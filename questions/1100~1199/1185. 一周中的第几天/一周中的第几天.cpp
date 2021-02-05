/* 一周中的第几天.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。

输入为三个整数：day、month 和 year，分别表示日、月、年。

您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}。

 

示例 1：

输入：day = 31, month = 8, year = 2019
输出："Saturday"
示例 2：

输入：day = 18, month = 7, year = 1999
输出："Sunday"
示例 3：

输入：day = 15, month = 8, year = 1993
输出："Sunday"
 

提示：

给出的日期一定是在 1971 到 2100 年之间的有效日期。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/day-of-the-week
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int sumDays = 0;
        for (int i = 1971; i < year; i++) {
            if (isLeapYear(i)) {
                sumDays += 366;
            }
            else {
                sumDays += 365;
            }
        }

        int leapDays[12] = { 0,31,60,91,121,152,182,213,244,274,305,335 };
        int noLeapDays[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
        if (isLeapYear(year)) {
            sumDays += (leapDays[month - 1] + day);
        }
        else {
            sumDays += (noLeapDays[month - 1] + day);
        }
        sumDays %= 7;

        string whichDay[7] = { "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday" };  // 1971.1.1 星期五
        return whichDay[sumDays];
    }

    bool isLeapYear(int year) {
        return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("Saturday", o.dayOfTheWeek(31, 8, 2019));
    check.checkString("Sunday", o.dayOfTheWeek(18, 7, 1999));
    check.checkString("Sunday", o.dayOfTheWeek(15, 8, 1993));
    check.checkString("Friday", o.dayOfTheWeek(1, 1, 1971));
    check.checkString("Friday", o.dayOfTheWeek(31, 12, 2100));
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
