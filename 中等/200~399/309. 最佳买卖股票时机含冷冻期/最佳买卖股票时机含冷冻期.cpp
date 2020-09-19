/* 最佳买卖股票时机含冷冻期.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* 令f[i]为到第i天的最大收益，f[i]有三种状态：0、持有一只股票；1、卖出一只股票，冷冻期；2、无股票，可以买入
           0、可以选择继续持有f[i-1][0]->f[i][0]，或者卖出进入冷冻期f[i-1][0]->f[i][1]
           1、只能进入状态2，f[i-1][1]->f[i][2]
           2、可以选择保持状态2，f[i-1][2]->f[i][2]，或者买入一只股票进入状态0，f[i-1][2]->f[i][0] */
        struct STATE {
            int state0;
            int state1;
            int state2;
        };

        int size = prices.size();
        if (size == 0) {
            return 0;
        }

        STATE* dp = new STATE[size + 1];
        dp[0] = { -prices[0],0,0 };

        for (int i = 1; i <= size; i++) {
            dp[i].state0 = max(dp[i - 1].state0, dp[i - 1].state2 - prices[i - 1]);
            dp[i].state1 = dp[i - 1].state0 + prices[i - 1];
            dp[i].state2 = max(dp[i - 1].state1, dp[i - 1].state2);
        }

        int maximumProfit = max(dp[size].state1, dp[size].state2);  // state0还持有股票，一定不是最大的。
        delete[] dp;

        return maximumProfit;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> prices = { 1,2,3,0,2 };
    check.checkInt(3, o.maxProfit(prices));

    prices = {  };
    check.checkInt(0, o.maxProfit(prices));

    prices = { 5 };
    check.checkInt(0, o.maxProfit(prices));

    prices = { 5,8 };
    check.checkInt(3, o.maxProfit(prices));

    prices = { 8,5 };
    check.checkInt(0, o.maxProfit(prices));

    prices = { 5,6,1,10 };
    check.checkInt(9, o.maxProfit(prices));

    prices = { 1,2,3,4,5,6 };
    check.checkInt(5, o.maxProfit(prices));

    prices = { 5,8,0,1,4 };
    check.checkInt(6, o.maxProfit(prices));

    prices = { 5,8,6,9,12 };
    check.checkInt(7, o.maxProfit(prices));

    prices = { 5,8,6,6,12 };
    check.checkInt(9, o.maxProfit(prices));
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
