/* 零钱兑换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

 

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
 

说明:
你可以认为每种硬币的数量是无限的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0) {
            return -1;
        }

        int i, j, size = coins.size(), minimum = -1;
        // dp[i]表示组成金额i，需要的最少硬币数量，则dp[i]=min(dp[i-coins[0], i-coins[1], ... , i-coins[size-1]])+1;
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (i = 1; i <= amount; i++) {
            minimum = -1;
            for (j = 0; j < size; j++) {
                int prevAmount = i - coins[j];
                if ((prevAmount < 0) || (dp[prevAmount] == -1)) {
                    continue;
                }

                if (minimum == -1) {
                    minimum = dp[prevAmount];
                }
                else {
                    minimum = min(minimum, dp[prevAmount]);
                }
            }

            if (minimum != -1) {
                dp[i] = minimum + 1;
            }
        }

        return dp[amount];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> coins = {  };
    check.checkInt(-1, o.coinChange(coins, -11));
    check.checkInt(0, o.coinChange(coins, 0));
    check.checkInt(-1, o.coinChange(coins, 11));

    coins = { 1 };
    check.checkInt(10, o.coinChange(coins, 10));

    coins = { 2 };
    check.checkInt(-1, o.coinChange(coins, 1));
    check.checkInt(1, o.coinChange(coins, 2));
    check.checkInt(-1, o.coinChange(coins, 3));
    check.checkInt(2, o.coinChange(coins, 4));
    check.checkInt(-1, o.coinChange(coins, 5));

    coins = { 3,7 };
    check.checkInt(-1, o.coinChange(coins, 1));
    check.checkInt(-1, o.coinChange(coins, 2));
    check.checkInt(1, o.coinChange(coins, 3));
    check.checkInt(-1, o.coinChange(coins, 4));
    check.checkInt(-1, o.coinChange(coins, 5));
    check.checkInt(2, o.coinChange(coins, 6));
    check.checkInt(1, o.coinChange(coins, 7));
    check.checkInt(-1, o.coinChange(coins, 8));
    check.checkInt(3, o.coinChange(coins, 9));
    check.checkInt(2, o.coinChange(coins, 10));
    check.checkInt(-1, o.coinChange(coins, 11));
    check.checkInt(4, o.coinChange(coins, 12));
    check.checkInt(3, o.coinChange(coins, 13));
    check.checkInt(2, o.coinChange(coins, 14));
    check.checkInt(5, o.coinChange(coins, 15));

    coins = { 1,2,5 };
    check.checkInt(1, o.coinChange(coins, 1));
    check.checkInt(1, o.coinChange(coins, 2));
    check.checkInt(2, o.coinChange(coins, 3));
    check.checkInt(2, o.coinChange(coins, 4));
    check.checkInt(1, o.coinChange(coins, 5));
    check.checkInt(2, o.coinChange(coins, 6));
    check.checkInt(2, o.coinChange(coins, 7));
    check.checkInt(3, o.coinChange(coins, 8));
    check.checkInt(3, o.coinChange(coins, 9));
    check.checkInt(2, o.coinChange(coins, 10));
    check.checkInt(3, o.coinChange(coins, 11));
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
