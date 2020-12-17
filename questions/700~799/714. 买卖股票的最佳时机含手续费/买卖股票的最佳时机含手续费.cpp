/* 买卖股票的最佳时机含手续费.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

示例 1:

输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
输出: 8
解释: 能够达到的最大利润:
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
注意:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dpHolding = INT_MIN, dpSold = 0;

        for (int price : prices) {
            dpHolding = max(dpHolding, dpSold - price);  // 持有以前的股票，和以前是卖出状态，买入今天的股票，选利润大的
            dpSold = max(dpSold, dpHolding + price - fee);  // 已卖出状态，和以前是买入状态，卖出今天的股票，选利润大的
        }

        return dpSold;  // 最大利润肯定出现在卖出状态
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> prices = { 1,3,2,8,4,9 };
    check.checkInt(8, o.maxProfit(prices, 2));

    prices = { 1,3,7,5,10,3 };
    check.checkInt(6, o.maxProfit(prices, 3));

    prices = { 1,9,10 };
    check.checkInt(6, o.maxProfit(prices, 3));

    prices = { 1 };
    check.checkInt(0, o.maxProfit(prices, 3));
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
