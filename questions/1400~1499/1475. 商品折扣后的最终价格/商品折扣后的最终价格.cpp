/* 商品折扣后的最终价格.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 prices ，其中 prices[i] 是商店里第 i 件商品的价格。

商店里正在进行促销活动，如果你要买第 i 件商品，那么你可以得到与 prices[j] 相等的折扣，其中 j 是满足 j > i 且 prices[j] <= prices[i] 的 最小下标 ，如果没有满足条件的 j ，你将没有任何折扣。

请你返回一个数组，数组中第 i 个元素是折扣后你购买商品 i 最终需要支付的价格。

 

示例 1：

输入：prices = [8,4,6,2,3]
输出：[4,2,4,2,3]
解释：
商品 0 的价格为 price[0]=8 ，你将得到 prices[1]=4 的折扣，所以最终价格为 8 - 4 = 4 。
商品 1 的价格为 price[1]=4 ，你将得到 prices[3]=2 的折扣，所以最终价格为 4 - 2 = 2 。
商品 2 的价格为 price[2]=6 ，你将得到 prices[3]=2 的折扣，所以最终价格为 6 - 2 = 4 。
商品 3 和 4 都没有折扣。
示例 2：

输入：prices = [1,2,3,4,5]
输出：[1,2,3,4,5]
解释：在这个例子中，所有商品都没有折扣。
示例 3：

输入：prices = [10,1,1,6]
输出：[9,0,1,6]
 

提示：

1 <= prices.length <= 500
1 <= prices[i] <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/final-prices-with-a-special-discount-in-a-shop
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int i, size = prices.size();
        stack<pair<int, int>> increasePrices;
        vector<int> cutOffPrices(size, 0);

        for (i = 0; i < size; i++) {
            int currentPrice = prices[i];
            if (increasePrices.empty()) {
                increasePrices.push({ currentPrice, i });
                continue;
            }

            pair<int, int> topPriceIndex = increasePrices.top();
            if (currentPrice > topPriceIndex.first) {
                increasePrices.push({ currentPrice, i });
                continue;
            }

            while (currentPrice <= topPriceIndex.first) {
                cutOffPrices[topPriceIndex.second] = topPriceIndex.first - currentPrice;
                increasePrices.pop();
                if (increasePrices.empty()) {
                    break;
                }
                topPriceIndex = increasePrices.top();
            }

            increasePrices.push({ currentPrice, i });
        }

        while (!increasePrices.empty()) {
            pair<int, int> priceIndex = increasePrices.top();
            increasePrices.pop();
            cutOffPrices[priceIndex.second] = priceIndex.first;
        }

        return cutOffPrices;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> prices = {};
    vector<int> actual = o.finalPrices(prices);
    vector<int> expected = {};
    check.checkIntVector(expected, actual);

    prices = { 5 };
    actual = o.finalPrices(prices);
    expected = { 5 };
    check.checkIntVector(expected, actual);

    prices = { 5,3 };
    actual = o.finalPrices(prices);
    expected = { 2,3 };
    check.checkIntVector(expected, actual);

    prices = { 5,6 };
    actual = o.finalPrices(prices);
    expected = { 5,6 };
    check.checkIntVector(expected, actual);

    prices = { 5,5 };
    actual = o.finalPrices(prices);
    expected = { 0,5 };
    check.checkIntVector(expected, actual);

    prices = { 8,4,6,2,3 };
    actual = o.finalPrices(prices);
    expected = { 4,2,4,2,3 };
    check.checkIntVector(expected, actual);

    prices = { 1,2,3,4,5 };
    actual = o.finalPrices(prices);
    expected = { 1,2,3,4,5 };
    check.checkIntVector(expected, actual);

    prices = { 10,1,1,6 };
    actual = o.finalPrices(prices);
    expected = { 9,0,1,6 };
    check.checkIntVector(expected, actual);

    prices = { 8,4,9,11,5,2,6,7,9,1 };
    actual = o.finalPrices(prices);
    expected = { 4,2,4,6,3,1,5,6,8,1 };
    check.checkIntVector(expected, actual);
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
