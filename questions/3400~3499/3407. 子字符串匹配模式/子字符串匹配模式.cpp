/* 子字符串匹配模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个模式字符串 p ，其中 p 恰好 包含 一个 '*' 符号。

p 中的 '*' 符号可以被替换为零个或多个字符组成的任意字符序列。

如果 p 可以变成 s 的子字符串，那么返回 true ，否则返回 false 。

子字符串 指的是字符串中一段连续 非空 的字符序列。



示例 1：

输入：s = "leetcode", p = "ee*e"

输出：true

解释：

将 '*' 替换为 "tcod" ，子字符串 "eetcode" 匹配模式串。

示例 2：

输入：s = "car", p = "c*v"

输出：false

解释：

不存在匹配模式串的子字符串。

示例 3：

输入：s = "luck", p = "u*"

输出：true

解释：

子字符串 "u" ，"uc" 和 "uck" 都匹配模式串。



提示：

1 <= s.length <= 50
1 <= p.length <= 50
s 只包含小写英文字母。
p 只包含小写英文字母和一个 '*' 符号。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        size_t size = p.size();
        size_t len1 = p.find('*', 0);
        size_t pre = s.find(string(p, 0, len1), 0);
        if (pre == s.npos) {
            return false;
        }

        reverse(s.begin(), s.end());
        reverse(p.begin(), p.end());
        size_t len2 = size - 1 - len1;
        size_t suf = s.find(string(p, 0, len2), 0);
        if (suf == s.npos) {
            return false;
        }

        return pre + len1 + suf + len2 <= s.size();
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.hasMatch("leetcode", "ee*e"));
    check.checkBool(true, o.hasMatch("luck", "u*"));
    check.checkBool(true, o.hasMatch("luck", "u*c"));
    check.checkBool(false, o.hasMatch("car", "c*v"));
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
