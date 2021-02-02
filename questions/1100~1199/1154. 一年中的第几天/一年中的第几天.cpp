/* 一年中的第几天.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个按 YYYY-MM-DD 格式表示日期的字符串 date，请你计算并返回该日期是当年的第几天。

通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。

 

示例 1：

输入：date = "2019-01-09"
输出：9
示例 2：

输入：date = "2019-02-10"
输出：41
示例 3：

输入：date = "2003-03-01"
输出：60
示例 4：

输入：date = "2004-03-01"
输出：61
 

提示：

date.length == 10
date[4] == date[7] == '-'，其他的 date[i] 都是数字。
date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/day-of-the-year
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
        int month = (date[5] - '0') * 10 + (date[6] - '0');
        int day = (date[8] - '0') * 10 + (date[9] - '0');
        
        int leapDays[12] = { 0,31,60,91,121,152,182,213,244,274,305,335 };
        int noLeapDays[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };

        if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
            return leapDays[month - 1] + day;
        }
        return noLeapDays[month - 1] + day;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(9, o.dayOfYear("2019-01-09"));
    check.checkInt(41, o.dayOfYear("2019-02-10"));
    check.checkInt(1, o.dayOfYear("2003-01-01"));
    check.checkInt(32, o.dayOfYear("2003-02-01"));
    check.checkInt(60, o.dayOfYear("2003-03-01"));
    check.checkInt(91, o.dayOfYear("2003-04-01"));
    check.checkInt(121, o.dayOfYear("2003-05-01"));
    check.checkInt(152, o.dayOfYear("2003-06-01"));
    check.checkInt(182, o.dayOfYear("2003-07-01"));
    check.checkInt(213, o.dayOfYear("2003-08-01"));
    check.checkInt(244, o.dayOfYear("2003-09-01"));
    check.checkInt(274, o.dayOfYear("2003-10-01"));
    check.checkInt(305, o.dayOfYear("2003-11-01"));
    check.checkInt(335, o.dayOfYear("2003-12-01"));
    check.checkInt(365, o.dayOfYear("2003-12-31"));
    check.checkInt(1, o.dayOfYear("2004-01-01"));
    check.checkInt(32, o.dayOfYear("2004-02-01"));
    check.checkInt(61, o.dayOfYear("2004-03-01"));
    check.checkInt(92, o.dayOfYear("2004-04-01"));
    check.checkInt(122, o.dayOfYear("2004-05-01"));
    check.checkInt(153, o.dayOfYear("2004-06-01"));
    check.checkInt(183, o.dayOfYear("2004-07-01"));
    check.checkInt(214, o.dayOfYear("2004-08-01"));
    check.checkInt(245, o.dayOfYear("2004-09-01"));
    check.checkInt(275, o.dayOfYear("2004-10-01"));
    check.checkInt(306, o.dayOfYear("2004-11-01"));
    check.checkInt(336, o.dayOfYear("2004-12-01"));
    check.checkInt(366, o.dayOfYear("2004-12-31"));
    check.checkInt(1, o.dayOfYear("2004-01-01"));
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
