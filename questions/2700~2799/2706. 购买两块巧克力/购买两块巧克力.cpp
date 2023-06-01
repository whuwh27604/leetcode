/* 购买两块巧克力.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 prices ，它表示一个商店里若干巧克力的价格。同时给你一个整数 money ，表示你一开始拥有的钱数。

你必须购买 恰好 两块巧克力，而且剩余的钱数必须是 非负数 。同时你想最小化购买两块巧克力的总花费。

请你返回在购买两块巧克力后，最多能剩下多少钱。如果购买任意两块巧克力都超过了你拥有的钱，请你返回 money 。注意剩余钱数必须是非负数。



示例 1：

输入：prices = [1,2,2], money = 3
输出：0
解释：分别购买价格为 1 和 2 的巧克力。你剩下 3 - 3 = 0 块钱。所以我们返回 0 。
示例 2：

输入：prices = [3,2,3], money = 3
输出：3
解释：购买任意 2 块巧克力都会超过你拥有的钱数，所以我们返回 3 。


提示：

2 <= prices.length <= 50
1 <= prices[i] <= 100
1 <= money <= 100
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minPrice = INT_MAX / 2, minSum = INT_MAX;

        for (int price : prices) {
            minSum = min(minSum, minPrice + price);
            minPrice = min(minPrice, price);
        }

        return minSum <= money ? money - minSum : money;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> prices = { 1,2,2 };
    check.checkInt(0, o.buyChoco(prices, 3));

    prices = { 3,2,3 };
    check.checkInt(3, o.buyChoco(prices, 3));

    prices = { 2,3 };
    check.checkInt(0, o.buyChoco(prices, 5));

    prices = { 5,4,3,2,1 };
    check.checkInt(7, o.buyChoco(prices, 10));
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
