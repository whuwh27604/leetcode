/* 找到字符串中合法的相邻数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个只包含数字的字符串 s 。如果 s 中两个 相邻 的数字满足以下条件，我们称它们是 合法的 ：

前面的数字 不等于 第二个数字。
两个数字在 s 中出现的次数 恰好 分别等于这个数字本身。
请你从左到右遍历字符串 s ，并返回最先找到的 合法 相邻数字。如果这样的相邻数字不存在，请你返回一个空字符串。



示例 1：

输入：s = "2523533"

输出："23"

解释：

数字 '2' 出现 2 次，数字 '3' 出现 3 次。"23" 中每个数字在 s 中出现的次数都恰好分别等于数字本身。所以输出 "23" 。

示例 2：

输入：s = "221"

输出："21"

解释：

数字 '2' 出现 2 次，数字 '1' 出现 1 次。所以输出 "21" 。

示例 3：

输入：s = "22"

输出：""

解释：

没有合法的相邻数字。



提示：

2 <= s.length <= 100
s 只包含 '1' 到 '9' 的数字。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string findValidPair(string s) {
        vector<int> cnt(10, 0);
        string ans;

        for (char c : s) {
            ++cnt[c - '0'];
        }

        for (int i = 1; i < (int)s.size(); ++i) {
            int d1 = s[i] - '0', d2 = s[i - 1] - '0';
            if (d1 != d2 && cnt[d1] == d1 && cnt[d2] == d2) {
                ans = string(s, i - 1, 2);
                break;
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("23", o.findValidPair("2523533"));
    check.checkString("21", o.findValidPair("221"));
    check.checkString("", o.findValidPair("22"));
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
