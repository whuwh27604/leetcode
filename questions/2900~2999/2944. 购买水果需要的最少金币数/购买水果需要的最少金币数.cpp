/* 购买水果需要的最少金币数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你在一个水果超市里，货架上摆满了玲琅满目的奇珍异果。

给你一个下标从 1 开始的数组 prices ，其中 prices[i] 表示你购买第 i 个水果需要花费的金币数目。

水果超市有如下促销活动：

如果你花费 price[i] 购买了水果 i ，那么接下来的 i 个水果你都可以免费获得。
注意 ，即使你 可以 免费获得水果 j ，你仍然可以花费 prices[j] 个金币去购买它以便能免费获得接下来的 j 个水果。

请你返回获得所有水果所需要的 最少 金币数。



示例 1：

输入：prices = [3,1,2]
输出：4
解释：你可以按如下方法获得所有水果：
- 花 3 个金币购买水果 1 ，然后免费获得水果 2 。
- 花 1 个金币购买水果 2 ，然后免费获得水果 3 。
- 免费获得水果 3 。
注意，虽然你可以免费获得水果 2 ，但你还是花 1 个金币去购买它，因为这样的总花费最少。
购买所有水果需要最少花费 4 个金币。
示例 2：

输入：prices = [1,10,1,1]
输出：2
解释：你可以按如下方法获得所有水果：
- 花 1 个金币购买水果 1 ，然后免费获得水果 2 。
- 免费获得水果 2 。
- 花 1 个金币购买水果 3 ，然后免费获得水果 4 。
- 免费获得水果 4 。
购买所有水果需要最少花费 2 个金币。


提示：

1 <= prices.length <= 1000
1 <= prices[i] <= 105
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int size = prices.size();
        vector<int> dp(2 * size + 1, 0);
        dp[size] = prices[size - 1];

        for (int i = size - 1; i > 0; --i) {
            int minCost = INT_MAX;

            for (int j = 1; j <= i + 1; ++j) {
                minCost = min(minCost, dp[i + j]);
            }

            dp[i] = prices[i - 1] + minCost;
        }

        return dp[1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> prices = { 3,1,2 };
    check.checkInt(4, o.minimumCoins(prices));

    prices = { 1,10,1,1 };
    check.checkInt(2, o.minimumCoins(prices));
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
