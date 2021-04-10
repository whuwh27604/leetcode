/* 零钱兑换 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

 

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2:

输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。
示例 3:

输入: amount = 10, coins = [10]
输出: 1
 

注意:

你可以假设：

0 <= amount (总金额) <= 5000
1 <= coin (硬币面额) <= 5000
硬币种类不超过 500 种
结果符合 32 位符号整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change-2
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /* 令dp[i][j]表示选择前i种硬币凑成j的方法数，那么加入第i+1种硬币后：
           1、选择使用这种硬币，那么这意味着第i+1种硬币至少有一枚，还需要使用i+1种硬币凑成j-coins[i+1]，即dp[i+1][j-coins[i+1]]
           2、选择不使用这种硬币，那么仍然有dp[i][j]种方法可以凑成j。总的dp[i+1][j]是以上两种方法的和 */
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int n = coin; n <= amount; ++n) {
                dp[n] += dp[n - coin];
            }
        }

        return dp[amount];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> coins = { 1,2,5 };
    check.checkInt(1, o.change(0, coins));

    coins = { 1,2,5 };
    check.checkInt(4, o.change(5, coins));

    coins = { 2 };
    check.checkInt(0, o.change(3, coins));

    coins = { 10 };
    check.checkInt(1, o.change(10, coins));

    coins = {  };
    check.checkInt(1, o.change(0, coins));

    coins = { 1,2,3,4 };
    check.checkInt(23, o.change(10, coins));

    coins = { 1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(1204, o.change(24, coins));
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
