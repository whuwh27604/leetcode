/* 出行的最少购票费用.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
航空公司向经常乘坐飞机的乘客们提供了一些商务套票，tickets[i] = [duration_i, price_i]，表示第 i 种套票的有效天数和价格。

例如：乘客购买了有效天数为 n 的套票，则该套票在第 date ~ date+n-1 天期间都可以使用。

现有一名乘客将在未来的几天中出行，days[i] 表示他第 i 次出行的时间，如果他选择购买商务套票，请返回他将花费的最少金额。

注意：

输入不存在多个有效天数相同的套票。
示例 1：

输入：
days = [1,2,3,4]
tickets = [[1,3],[2,5],[3,7]]

输出: 10

解释：可以买一张一天有效期的票和一张三天有效期的票；或买两张两天有效期的票；总票价均为10

示例 2：

输入：
days = [1,4,5]
tickets = [[1,4],[5,6],[2,5]]

输出: 6

解释：买一张 5 天有效期的票；总票价为6

提示：

1 <= days.length <= 10^5
1 <= days[i] < days[i+1] <= 10^9
1 <= tickets.length <= 20
1 <= tickets[i][0] <= 10^5
1 <= tickets[i][1] <= 10^9
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minCostToTravelOnDays(vector<int>& days, vector<vector<int>>& tickets) {
        int sizeDays = days.size(), sizeTickets = tickets.size();
        vector<long long> minCosts(sizeDays, LLONG_MAX);

        for (int i = 0; i < sizeDays; ++i) {
            for (int j = 0; j < sizeTickets; ++j) {
                int index = distance(days.begin(), upper_bound(days.begin(), days.end(), days[i] - tickets[j][0]));
                minCosts[i] = min(minCosts[i], (index == 0 ? 0 : minCosts[index - 1]) + tickets[j][1]);
            }
        }

        return minCosts.back();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> days = { 1,2,3,4 };
    vector<vector<int>> tickets = { {1,3},{2,5},{3,7} };
    check.checkLongLong(10, o.minCostToTravelOnDays(days, tickets));

    days = { 1,4,5 };
    tickets = { {1,4},{5,6},{2,5} };
    check.checkLongLong(6, o.minCostToTravelOnDays(days, tickets));

    days = { 1,4,5 };
    tickets = { {1,4},{5,10},{2,5} };
    check.checkLongLong(9, o.minCostToTravelOnDays(days, tickets));

    days = { 1,4,5 };
    tickets = { {1,2},{5,10},{2,5} };
    check.checkLongLong(6, o.minCostToTravelOnDays(days, tickets));

    days = { 1,2,4,5 };
    tickets = { {1,3},{2,5} };
    check.checkLongLong(10, o.minCostToTravelOnDays(days, tickets));

    days = { 5 };
    tickets = { {8,1} };
    check.checkLongLong(1, o.minCostToTravelOnDays(days, tickets));
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
