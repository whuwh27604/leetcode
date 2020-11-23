/* 分割回文串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Manacher {
public:
    Manacher(string& s) {
        preprocess(s);
        radii.resize(ms.size());
    }

    void preprocess(string& s) {
        ms += "@#";  // 首尾添加字符@、$，可以简化后面算法的边界处理

        for (char c : s) {
            ms += c;
            ms += '#';  // 每个字符前后插入#，可以使奇偶回文都变为奇回文，简化算法的处理
        }

        ms += '$';
    }

    void calculate() {
        /*   symmetryMaxRight   symmetryI     center          i            maxRight
        ------------|---------------|------------|------------|---------------|-------- */
        int i, size = ms.size();
        int center, maxRight = 0;

        for (i = 1; i < size - 1; i++) {
            if (i < maxRight) {
                /* （2 * center - i）是symmetryI，分三种情况可证明下面这句话成立：
                   1、radii[symmetryI]大于(symmetryI-symmetryMaxRight)，则radii[i]=(symmetryI-symmetryMaxRight)=(maxRight-i)，不能再大
                   2、radii[symmetryI]小于(symmetryI-symmetryMaxRight)，则radii[i]=radii[symmetryI]，不能再大
                   3、radii[symmetryI]等于(symmetryI-symmetryMaxRight)，则radii[i]=radii[symmetryI]=(maxRight-i)，然后执行下面的while语句继续拓展 */
                radii[i] = min(radii[2 * center - i], maxRight - i);
            }
            else {
                radii[i] = 1;
            }

            // 中心拓展找最大的半径，预处理在首尾添加的不同字符保证不会越界
            while (ms[i - radii[i]] == ms[i + radii[i]]) {
                radii[i]++;
            }

            // 每走一步i，都要维护maxRight。我们希望maxRight尽可能往右，这样才能更有机会执行if (i < maxRight)提高效率
            if (maxRight < i + radii[i]) {
                center = i;
                maxRight = i + radii[i];
            }
        }
    }

    bool isPalindrome(int start, int end) {
        return radii[(start + 1) + (end + 1)] / 2 >= (end - start + 2) / 2;
    }

private:
    string ms;
    vector<int> radii;
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        Manacher manacher(s);
        manacher.calculate();

        vector<string> substrs;
        vector<vector<string>> allSubstrs;
        DFS(s, 0, manacher, substrs, allSubstrs);

        return allSubstrs;
    }

    void DFS(string& s, int start, Manacher& manacher, vector<string>& substrs, vector<vector<string>>& allSubstrs) {
        int size = s.size();
        if (start == size) {
            allSubstrs.push_back(substrs);
            return;
        }

        for (int i = start; i < size; ++i) {
            if (manacher.isPalindrome(start, i)) {
                string substr(s, start, i - start + 1);
                substrs.push_back(substr);
                DFS(s, i + 1, manacher, substrs, allSubstrs);
                substrs.pop_back();
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<string>> actual = o.partition("aab");
    vector<vector<string>> expected = { {"aa","b"},{"a","a","b"} };
    check.checkStringVectorRandomVectorRandomOrder(expected, actual);

    actual = o.partition("a");
    expected = { {"a"} };
    check.checkStringVectorRandomVectorRandomOrder(expected, actual);

    actual = o.partition("abcde");
    expected = { {"a","b","c","d","e"} };
    check.checkStringVectorRandomVectorRandomOrder(expected, actual);

    actual = o.partition("cbbbcc");
    expected = { {"c","b","b","b","c","c"},{"c","b","b","b","cc"},{"c","b","bb","c","c"},{"c","b","bb","cc"},{"c","bb","b","c","c"},{"c","bb","b","cc"},{"c","bbb","c","c"},{"c","bbb","cc"},{"cbbbc","c"} };
    check.checkStringVectorRandomVectorRandomOrder(expected, actual);

    actual = o.partition("aaaaa");
    expected = { {"a","a","a","a","a"},{"a","a","a","aa"},{"a","a","aa","a"},{"a","a","aaa"},{"a","aa","a","a"},{"a","aa","aa"},{"a","aaa","a"},{"a","aaaa"},{"aa","a","a","a"},{"aa","a","aa"},{"aa","aa","a"},{"aa","aaa"},{"aaa","a","a"},{"aaa","aa"},{"aaaa","a"},{"aaaaa"} };
    check.checkStringVectorRandomVectorRandomOrder(expected, actual);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
