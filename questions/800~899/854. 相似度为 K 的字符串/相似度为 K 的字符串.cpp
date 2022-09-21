/* 相似度为 K 的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
对于某些非负整数 k ，如果交换 s1 中两个字母的位置恰好 k 次，能够使结果字符串等于 s2 ，则认为字符串 s1 和 s2 的 相似度为 k 。

给你两个字母异位词 s1 和 s2 ，返回 s1 和 s2 的相似度 k 的最小值。

 

示例 1：

输入：s1 = "ab", s2 = "ba"
输出：1
示例 2：

输入：s1 = "abc", s2 = "bca"
输出：2
 

提示：

1 <= s1.length <= 20
s2.length == s1.length
s1 和 s2  只包含集合 {'a', 'b', 'c', 'd', 'e', 'f'} 中的小写字母
s2 是 s1 的一个字母异位词

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/k-similar-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int kSimilarity(string s1, string s2) {
        unordered_map<string, int> memo;

        return DFS(s1, s2, memo);
    }

    int DFS(string s1, string s2, unordered_map<string, int>& memo) {
        if (s1.empty()) {
            return 0;
        }

        string key = s1 + s2;
        if (memo.count(key) != 0) {
            return memo[key];
        }

        int size = s1.size();
        int& ans = memo[key];
        ans = size;

        if (s1[0] == s2[0]) {
            return ans = DFS(string(s1, 1, size - 1), string(s2, 1, size - 1), memo);
        }

        for (int i = 1; i < size; ++i) {
            if (s1[i] == s2[0]) {
                ans = min(ans, DFS(string(s1, 1, i - 1) + s1[0] + string(s1, i + 1, size - 1 - i), string(s2, 1, size - 1), memo) + 1);
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.kSimilarity("ab", "ba"));
    check.checkInt(2, o.kSimilarity("abc", "bca"));
    check.checkInt(6, o.kSimilarity("aabbccddee", "cdacbeebad"));
    check.checkInt(1, o.kSimilarity("abbbbbbbbbbbbbbbbbbb", "bbbbbbbbbbbbbbbbbbba"));
    check.checkInt(1, o.kSimilarity("bbbbbbbbbbbbbbbbbbba", "abbbbbbbbbbbbbbbbbbb"));
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
