/* 统计共同度过的日子数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 和 Bob 计划分别去罗马开会。

给你四个字符串 arriveAlice ，leaveAlice ，arriveBob 和 leaveBob 。Alice 会在日期 arriveAlice 到 leaveAlice 之间在城市里（日期为闭区间），而 Bob 在日期 arriveBob 到 leaveBob 之间在城市里（日期为闭区间）。每个字符串都包含 5 个字符，格式为 "MM-DD" ，对应着一个日期的月和日。

请你返回 Alice和 Bob 同时在罗马的天数。

你可以假设所有日期都在 同一个 自然年，而且 不是 闰年。每个月份的天数分别为：[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] 。

 

示例 1：

输入：arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
输出：3
解释：Alice 从 8 月 15 号到 8 月 18 号在罗马。Bob 从 8 月 16 号到 8 月 19 号在罗马，他们同时在罗马的日期为 8 月 16、17 和 18 号。所以答案为 3 。
示例 2：

输入：arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
输出：0
解释：Alice 和 Bob 没有同时在罗马的日子，所以我们返回 0 。
 

提示：

所有日期的格式均为 "MM-DD" 。
Alice 和 Bob 的到达日期都 早于或等于 他们的离开日期。
题目测试用例所给出的日期均为 非闰年 的有效日期。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-days-spent-together
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrive = max(getDaysFromNewYear(arriveAlice), getDaysFromNewYear(arriveBob));
        int leave = min(getDaysFromNewYear(leaveAlice), getDaysFromNewYear(leaveBob));

        return max(0, leave - arrive + 1);
    }

    int getDaysFromNewYear(string& date) {
        int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        int daysFromNewYear = 0;
        int month = (date[0] - '0') * 10 + date[1] - '0';
        int day = (date[3] - '0') * 10 + date[4] - '0';

        for (int m = 1; m < month; ++m) {
            daysFromNewYear += days[m];
        }

        return daysFromNewYear + day;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.countDaysTogether("08-15", "08-18", "08-16", "08-19"));
    check.checkInt(0, o.countDaysTogether("10-01", "10-31", "11-01", "12-31"));
    check.checkInt(0, o.countDaysTogether("10-01", "10-31", "09-01", "09-30"));
    check.checkInt(1, o.countDaysTogether("08-15", "08-18", "08-14", "08-15"));
    check.checkInt(2, o.countDaysTogether("08-15", "08-18", "08-16", "08-17"));
    check.checkInt(4, o.countDaysTogether("08-15", "08-18", "08-10", "08-18"));
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
