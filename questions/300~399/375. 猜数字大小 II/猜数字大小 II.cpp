/* 猜数字大小 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们正在玩一个猜数游戏，游戏规则如下：

我从 1 到 n 之间选择一个数字，你来猜我选了哪个数字。

每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。

然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。

示例:

n = 10, 我选择了8.

第一轮: 你猜我选择的数字是5，我会告诉你，我的数字更大一些，然后你需要支付5块。
第二轮: 你猜是7，我告诉你，我的数字更大一些，你支付7块。
第三轮: 你猜是9，我告诉你，我的数字更小一些，你支付9块。

游戏结束。8 就是我选的数字。

你最终要支付 5 + 7 + 9 = 21 块钱。
给定 n ≥ 1，计算你至少需要拥有多少现金才能确保你能赢得这个游戏。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

/* 此题二分法不是最优解，比如n=5，二分法先选3，不对再选4，需要3+4=7。实际上应该先选4，不对再选2，4+2=6就可以猜出所有5个数了。
   令dp[i][j]表示从i到j的区间需要的最小金额，从左上往右下动态规划。
   对任意dp[i][j]，轮循所有i<=guess<=j，amount=max(dp[i][guess-1],dp[guess+1][j])+guess，dp[i][j]取最小的一个amount。
   直观上，第一次猜的数一定要在右半区间，否则最后的和不可能最小。所以每次从区间[i,j]中间开始遍历就可以了 */
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int i = 1, j = 2;

        while (j <= n) {
            int minAmount = INT_MAX;

            for (int guess = (i + j) / 2; guess <= j; guess++) {
                int left = (guess == i) ? 0 : dp[i][guess - 1];
                int right = (guess == j) ? 0 : dp[guess + 1][j];
                int amount = max(left, right) + guess;
                minAmount = min(amount, minAmount);
            }

            dp[i++][j++] = minAmount;
            if (j > n) {
                j = j - i + 2;
                i = 1;
            }
        }

        return dp[1][n];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.getMoneyAmount(1));
    check.checkInt(1, o.getMoneyAmount(2));
    check.checkInt(6, o.getMoneyAmount(5));
    check.checkInt(16, o.getMoneyAmount(10));
    check.checkInt(21, o.getMoneyAmount(12));
    check.checkInt(24, o.getMoneyAmount(13));
    check.checkInt(27, o.getMoneyAmount(14));
    check.checkInt(30, o.getMoneyAmount(15));
    check.checkInt(34, o.getMoneyAmount(16));
    check.checkInt(38, o.getMoneyAmount(17));
    check.checkInt(42, o.getMoneyAmount(18));
    check.checkInt(49, o.getMoneyAmount(20));
    check.checkInt(400, o.getMoneyAmount(100));
    check.checkInt(952, o.getMoneyAmount(200));
    check.checkInt(2280, o.getMoneyAmount(400));
    check.checkInt(2933, o.getMoneyAmount(500));
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
