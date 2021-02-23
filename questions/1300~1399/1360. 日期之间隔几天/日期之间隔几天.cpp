/* 日期之间隔几天.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你编写一个程序来计算两个日期之间隔了多少天。

日期以字符串形式给出，格式为 YYYY-MM-DD，如示例所示。

 

示例 1：

输入：date1 = "2019-06-29", date2 = "2019-06-30"
输出：1
示例 2：

输入：date1 = "2020-01-15", date2 = "2019-12-31"
输出：15
 

提示：

给定的日期是 1971 年到 2100 年之间的有效日期。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-days-between-two-dates
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        int year1, month1, day1, year2, month2, day2, days1, days2;
        days1 = dayOfYear(date1, year1, month1, day1);
        days2 = dayOfYear(date2, year2, month2, day2);

        if (year1 == year2) {
            return abs(days1 - days2);
        }

        int daysBetweenTwoDates, totalDaysThisYear;
        if (year1 > year2) {
            totalDaysThisYear = isLeapYear(year2) ? 366 : 365;
            daysBetweenTwoDates = totalDaysThisYear - days2;
            for (int i = year2 + 1; i < year1; i++) {
                totalDaysThisYear = isLeapYear(i) ? 366 : 365;
                daysBetweenTwoDates += totalDaysThisYear;
            }
            daysBetweenTwoDates += days1;
        }
        else {
            totalDaysThisYear = isLeapYear(year1) ? 366 : 365;
            daysBetweenTwoDates = totalDaysThisYear - days1;
            for (int i = year1 + 1; i < year2; i++) {
                totalDaysThisYear = isLeapYear(i) ? 366 : 365;
                daysBetweenTwoDates += totalDaysThisYear;
            }
            daysBetweenTwoDates += days2;
        }

        return daysBetweenTwoDates;
    }

    bool isLeapYear(int year) {
        return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
    }

    int dayOfYear(string date, int& year, int& month, int& day) {
        year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
        month = (date[5] - '0') * 10 + (date[6] - '0');
        day = (date[8] - '0') * 10 + (date[9] - '0');

        int leapDays[12]{ 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
        int noLeapDays[12]{ 0,31,59,90,120,151,181,212,243,273,304,334 };

        if (isLeapYear(year)) {
            return leapDays[month - 1] + day;
        }
        return noLeapDays[month - 1] + day;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.daysBetweenDates("2019-06-29", "2019-06-30"));
    check.checkInt(1, o.daysBetweenDates("2019-06-30", "2019-06-29"));
    check.checkInt(62, o.daysBetweenDates("2019-06-28", "2019-08-29"));
    check.checkInt(15, o.daysBetweenDates("2020-01-15", "2019-12-31"));
    check.checkInt(366, o.daysBetweenDates("2020-01-01", "2021-01-01"));
    check.checkInt(0, o.daysBetweenDates("2020-01-01", "2020-01-01"));
    check.checkInt(824, o.daysBetweenDates("2019-11-02", "2022-02-03"));
    check.checkInt(824, o.daysBetweenDates("2022-02-03", "2019-11-02"));
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
