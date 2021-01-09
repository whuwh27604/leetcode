/* 买卖股票的最佳时机 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1:

输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
示例 2：

输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。  
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。  
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3：

输入：prices = [7,6,4,3,1]
输出：0
解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
示例 4：

输入：prices = [1]
输出：0
 

提示：

1 <= prices.length <= 105
0 <= prices[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, size = prices.size(), holding1 = -prices[0], sold1 = -100000000, holding2 = -100000000, sold2 = -100000000;

        for (i = 1; i < size; ++i) {
            sold2 = max(sold2, holding2 + prices[i]);
            holding2 = max(holding2, sold1 - prices[i]);
            sold1 = max(sold1, holding1 + prices[i]);
            holding1 = max(holding1, -prices[i]);
        }

        return max({ 0, sold1, sold2 });
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> prices = { 3,3,5,0,0,3,1,4 };
    check.checkInt(6, o.maxProfit(prices));
    
    prices = { 1,2,3,4,5 };
    check.checkInt(4, o.maxProfit(prices));

    prices = { 7,6,4,3,1 };
    check.checkInt(0, o.maxProfit(prices));

    prices = { 1 };
    check.checkInt(0, o.maxProfit(prices));

    prices = { 1,2,4,2,5,7,2,4,9,0 };
    check.checkInt(13, o.maxProfit(prices));
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
