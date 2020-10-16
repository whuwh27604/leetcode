/* 不含 AAA 或 BBB 的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个整数 A 和 B，返回任意字符串 S，要求满足：

S 的长度为 A + B，且正好包含 A 个 'a' 字母与 B 个 'b' 字母；
子串 'aaa' 没有出现在 S 中；
子串 'bbb' 没有出现在 S 中。
 

示例 1：

输入：A = 1, B = 2
输出："abb"
解释："abb", "bab" 和 "bba" 都是正确答案。
示例 2：

输入：A = 4, B = 1
输出："aabaa"
 

提示：

0 <= A <= 100
0 <= B <= 100
对于给定的 A 和 B，保证存在满足要求的 S。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-without-aaa-or-bbb
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        // 很明显的贪心策略，哪个字母剩下多，就放2个，然后放另外一个字母；一样多的时候就交替放
        string ans;
        int bigger = max(A, B), less = min(A, B);
        char bc = (A > B) ? 'a' : 'b', lc = (A < B) ? 'a' : 'b';

        patternAAB(bigger, less, bc, lc, ans);
        patternAB(bigger, ans);

        return ans;
    }

    void patternAAB(int& bigger, int& less, char bc, char lc, string& ans) {
        while (bigger > less) {
            ans += bc;
            if (--bigger != 0) {
                ans += bc;
                --bigger;
            }
            if (less != 0) {
                ans += lc;
                --less;
            }
        }
    }

    void patternAB(int times, string& ans) {
        while (times != 0) {
            ans += "ab";
            --times;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("aabaa", o.strWithout3a3b(4, 1));
    check.checkString("", o.strWithout3a3b(0, 0));
    check.checkString("b", o.strWithout3a3b(0, 1));
    check.checkString("bb", o.strWithout3a3b(0, 2));
    check.checkString("a", o.strWithout3a3b(1, 0));
    check.checkString("ab", o.strWithout3a3b(1, 1));
    check.checkString("bba", o.strWithout3a3b(1, 2));
    check.checkString("bbab", o.strWithout3a3b(1, 3));
    check.checkString("bbabb", o.strWithout3a3b(1, 4));
    check.checkString("aa", o.strWithout3a3b(2, 0));
    check.checkString("aab", o.strWithout3a3b(2, 1));
    check.checkString("abab", o.strWithout3a3b(2, 2));
    check.checkString("bbaab", o.strWithout3a3b(2, 3));
    check.checkString("bbabba", o.strWithout3a3b(2, 4));
    check.checkString("bbabbab", o.strWithout3a3b(2, 5));
    check.checkString("bbabbabb", o.strWithout3a3b(2, 6));
    check.checkString("aaba", o.strWithout3a3b(3, 1));
    check.checkString("aabab", o.strWithout3a3b(3, 2));
    check.checkString("ababab", o.strWithout3a3b(3, 3));
    check.checkString("bbaabab", o.strWithout3a3b(3, 4));
    check.checkString("bbabbaab", o.strWithout3a3b(3, 5));
    check.checkString("bbabbabba", o.strWithout3a3b(3, 6));
    check.checkString("bbabbabbab", o.strWithout3a3b(3, 7));
    check.checkString("bbabbabbabb", o.strWithout3a3b(3, 8));
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
