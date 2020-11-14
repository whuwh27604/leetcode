/* 最低票价.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。

火车票有三种不同的销售方式：

一张为期一天的通行证售价为 costs[0] 美元；
一张为期七天的通行证售价为 costs[1] 美元；
一张为期三十天的通行证售价为 costs[2] 美元。
通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张为期 7 天的通行证，那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。

返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费。

 

示例 1：

输入：days = [1,4,6,7,8,20], costs = [2,7,15]
输出：11
解释：
例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
在第 1 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 1 天生效。
在第 3 天，你花了 costs[1] = $7 买了一张为期 7 天的通行证，它将在第 3, 4, ..., 9 天生效。
在第 20 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 20 天生效。
你总共花了 $11，并完成了你计划的每一天旅行。
示例 2：

输入：days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
输出：17
解释：
例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
在第 1 天，你花了 costs[2] = $15 买了一张为期 30 天的通行证，它将在第 1, 2, ..., 30 天生效。
在第 31 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 31 天生效。
你总共花了 $17，并完成了你计划的每一天旅行。
 

提示：

1 <= days.length <= 365
1 <= days[i] <= 365
days 按顺序严格递增
costs.length == 3
1 <= costs[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-for-tickets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // 令dp[i]表示第i天到365天的最小cost，则dp[i]=min(costs[0]+dp[i+1],cost[1]+dp[i+7],cost[2]+dp[i+30])
        vector<int> dp(366 + 30, 0);
        vector<int> travelDays(366, 0);

        for (int day : days) {
            travelDays[day] = 1;
        }

        for (int i = 365; i > 0; --i) {
            if (travelDays[i] == 0) {
                dp[i] = dp[i + 1];
            }
            else {
                dp[i] = min(costs[0] + dp[i + 1], min(costs[1] + dp[i + 7], costs[2] + dp[i + 30]));
            }
        }

        return dp[1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> days = { 1,4,6,7,8,20 };
    vector<int> costs = { 2,7,15 };
    check.checkInt(11, o.mincostTickets(days, costs));

    days = { 1,2,3,4,5,6,7,8,9,10,30,31 };
    costs = { 2,7,15 };
    check.checkInt(17, o.mincostTickets(days, costs));

    days = { 1,4,6,7,8,20 };
    costs = { 7,2,15 };
    check.checkInt(6, o.mincostTickets(days, costs));

    days = { 1,4,6,9,10,11,12,13,14,15,16,17,18,20,21,22,23,27,28 };
    costs = { 3,13,45 };
    check.checkInt(44, o.mincostTickets(days, costs));
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
