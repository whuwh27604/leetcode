/* 将日期转换为二进制表示.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 date，它的格式为 yyyy-mm-dd，表示一个公历日期。

date 可以重写为二进制表示，只需要将年、月、日分别转换为对应的二进制表示（不带前导零）并遵循 year-month-day 的格式。

返回 date 的 二进制 表示。



示例 1：

输入： date = "2080-02-29"

输出： "100000100000-10-11101"

解释：

100000100000, 10 和 11101 分别是 2080, 02 和 29 的二进制表示。

示例 2：

输入： date = "1900-01-01"

输出： "11101101100-1-1"

解释：

11101101100, 1 和 1 分别是 1900, 1 和 1 的二进制表示。



提示：

date.length == 10
date[4] == date[7] == '-'，其余的 date[i] 都是数字。
输入保证 date 代表一个有效的公历日期，日期范围从 1900 年 1 月 1 日到 2100 年 12 月 31 日（包括这两天）。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string convertDateToBinary(string date) {
        int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
        int month = (date[5] - '0') * 10 + (date[6] - '0');
        int day = (date[8] - '0') * 10 + (date[9] - '0');

        return toString(year) + "-" + toString(month) + "-" + toString(day);
    }

    string toString(int n) {
        string s;

        while (n != 0) {
            s += ('0' + (n & 1));
            n >>= 1;
        }

        reverse(s.begin(), s.end());

        return s;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("100000100000-10-11101", o.convertDateToBinary("2080-02-29"));
    check.checkString("11101101100-1-1", o.convertDateToBinary("1900-01-01"));
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
