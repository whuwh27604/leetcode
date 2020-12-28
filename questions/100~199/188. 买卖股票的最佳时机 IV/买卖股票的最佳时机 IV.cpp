/* 买卖股票的最佳时机 IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1：

输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2：

输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
 

提示：

0 <= k <= 109
0 <= prices.length <= 1000
0 <= prices[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int i, j, size = prices.size(), sizeK = min(k, size / 2) + 1;  // 完成一次完整的交易至少需要两天，过大的k是没有意义的
        vector<vector<int>> dpHolding(size, vector<int>(sizeK)), dpSold(size, vector<int>(sizeK));  // dp[i][j]表示在第i天完成j次交易，处于holding态和sold态的最大收益

        dpHolding[0][0] = -prices[0];  // 第0天，要处于holding态，只能买入股票。买入时不计算交易次数，卖出时计算交易次数
        dpSold[0][0] = 0;  // 第0天，要处于sold态，啥也不要干

        for (j = 1; j < sizeK; ++j) {
            dpHolding[0][j] = dpSold[0][j] = INT_MIN / 2;  // 第0天的其它交易次数初始化为一个较大的负值，表示非法的状态
        }

        for (i = 1; i < size; ++i) {
            dpHolding[i][0] = max(dpHolding[i - 1][0], -prices[i]);  // 仅买入当天股票的最大收益，就是股价中最低的
            dpSold[i][0] = 0;  // 不做任何操作，保持0收益

            for (j = 1; j < sizeK; ++j) {
                dpHolding[i][j] = max(dpHolding[i - 1][j], dpSold[i - 1][j] - prices[i]);  // 从前一天已经持有股票并完成j次交易和前一天卖出股票今天买入中选择收益大的
                dpSold[i][j] = max(dpSold[i - 1][j], dpHolding[i - 1][j - 1] + prices[i]);  // 从前一天卖出股票并完成j次交易和前一天持有股票完成j-1次交易今天卖出股票中选择收益大的
            }
        }

        return *max_element(dpSold[size - 1].begin(), dpSold[size - 1].end());  // 选择n天结束时，卖出状态中收益最大的
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> prices = { 2,4,1 };
    check.checkInt(2, o.maxProfit(2, prices));

    prices = { 3,2,6,5,0,3 };
    check.checkInt(7, o.maxProfit(2, prices));

    prices = { 5,4,3,2,1 };
    check.checkInt(0, o.maxProfit(5, prices));

    prices = {  };
    check.checkInt(0, o.maxProfit(2, prices));

    prices = { 3,3,5,0,0,3,1,4 };
    check.checkInt(6, o.maxProfit(2, prices));
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
