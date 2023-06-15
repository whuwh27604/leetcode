/* 找到最长的半重复子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 s ，这个字符串只包含 0 到 9 的数字字符。

如果一个字符串 t 中至多有一对相邻字符是相等的，那么称这个字符串是 半重复的 。

请你返回 s 中最长 半重复 子字符串的长度。

一个 子字符串 是一个字符串中一段连续 非空 的字符。



示例 1：

输入：s = "52233"
输出：4
解释：最长半重复子字符串是 "5223" ，子字符串从 i = 0 开始，在 j = 3 处结束。
示例 2：

输入：s = "5494"
输出：4
解释：s 就是一个半重复字符串，所以答案为 4 。
示例 3：

输入：s = "1111111"
输出：2
解释：最长半重复子字符串是 "11" ，子字符串从 i = 0 开始，在 j = 1 处结束。


提示：

1 <= s.length <= 50
'0' <= s[i] <= '9'
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        s += s.back();
        int size = s.size(), same1 = -1, same2 = -1, maxLen = 0;

        for (int i = 1; i < size; ++i) {
            if (s[i] == s[i - 1]) {
                if (same2 == -1) {
                    maxLen = max(maxLen, i);
                    same2 = i;
                }
                else {
                    if (same1 == -1) {
                        maxLen = max(maxLen, i);
                        same1 = same2;
                        same2 = i;
                    }
                    else {
                        maxLen = max(maxLen, i - same1);
                        same1 = same2;
                        same2 = i;
                    }
                }
            }
        }

        return maxLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.longestSemiRepetitiveSubstring("52233"));
    check.checkInt(4, o.longestSemiRepetitiveSubstring("5494"));
    check.checkInt(2, o.longestSemiRepetitiveSubstring("1111111"));
    check.checkInt(1, o.longestSemiRepetitiveSubstring("1"));
    check.checkInt(2, o.longestSemiRepetitiveSubstring("12"));
    check.checkInt(3, o.longestSemiRepetitiveSubstring("123"));
    check.checkInt(4, o.longestSemiRepetitiveSubstring("1233"));
    check.checkInt(4, o.longestSemiRepetitiveSubstring("11223344"));
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
