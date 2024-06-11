/* 清除数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 。

你的任务是重复以下操作删除 所有 数字字符：

删除 第一个数字字符 以及它左边 最近 的 非数字 字符。
请你返回删除所有数字字符以后剩下的字符串。



示例 1：

输入：s = "abc"

输出："abc"

解释：

字符串中没有数字。

示例 2：

输入：s = "cb34"

输出：""

解释：

一开始，我们对 s[2] 执行操作，s 变为 "c4" 。

然后对 s[1] 执行操作，s 变为 "" 。



提示：

1 <= s.length <= 100
s 只包含小写英文字母和数字字符。
输入保证所有数字都可以按以上操作被删除。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        string ans;

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                ans.pop_back();
            }
            else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("abc", o.clearDigits("abc"));
    check.checkString("", o.clearDigits("cb34"));
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
