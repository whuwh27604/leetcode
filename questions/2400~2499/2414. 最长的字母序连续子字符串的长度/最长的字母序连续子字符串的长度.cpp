/* 最长的字母序连续子字符串的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
字母序连续字符串 是由字母表中连续字母组成的字符串。换句话说，字符串 "abcdefghijklmnopqrstuvwxyz" 的任意子字符串都是 字母序连续字符串 。

例如，"abc" 是一个字母序连续字符串，而 "acb" 和 "za" 不是。
给你一个仅由小写英文字母组成的字符串 s ，返回其 最长 的 字母序连续子字符串 的长度。

 

示例 1：

输入：s = "abacaba"
输出：2
解释：共有 4 个不同的字母序连续子字符串 "a"、"b"、"c" 和 "ab" 。
"ab" 是最长的字母序连续子字符串。
示例 2：

输入：s = "abcde"
输出：5
解释："abcde" 是最长的字母序连续子字符串。
 

提示：

1 <= s.length <= 105
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int len = 0, maxLen = 0;
        char prev = 0;

        for (char c : s) {
            if (c == prev + 1) {
                ++len;
            }
            else {
                maxLen = max(maxLen, len);
                len = 1;
            }

            prev = c;
        }

        return max(maxLen, len);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.longestContinuousSubstring("abacaba"));
    check.checkInt(5, o.longestContinuousSubstring("abcde"));
    check.checkInt(1, o.longestContinuousSubstring("z"));
    check.checkInt(1, o.longestContinuousSubstring("za"));
    check.checkInt(26, o.longestContinuousSubstring("abcdefghijklmnopqrstuvwxyz"));
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
