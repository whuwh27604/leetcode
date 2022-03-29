/* 从栈中取出 K 个硬币的最大面值和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一张桌子上总共有 n 个硬币 栈 。每个栈有 正整数 个带面值的硬币。

每一次操作中，你可以从任意一个栈的 顶部 取出 1 个硬币，从栈中移除它，并放入你的钱包里。

给你一个列表 piles ，其中 piles[i] 是一个整数数组，分别表示第 i 个栈里 从顶到底 的硬币面值。同时给你一个正整数 k ，请你返回在 恰好 进行 k 次操作的前提下，你钱包里硬币面值之和 最大为多少 。

 

示例 1：



输入：piles = [[1,100,3],[7,8,9]], k = 2
输出：101
解释：
上图展示了几种选择 k 个硬币的不同方法。
我们可以得到的最大面值为 101 。
示例 2：

输入：piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
输出：706
解释：
如果我们所有硬币都从最后一个栈中取，可以得到最大面值和。
 

提示：

n == piles.length
1 <= n <= 1000
1 <= piles[i][j] <= 105
1 <= k <= sum(piles[i].length) <= 2000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-value-of-k-coins-from-piles
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int coins, curCoins = piles[0].size(), totalCoins = curCoins;
        vector<int> dp(k + 1, 0);  // dp[i][coins]表示从piles[0, i]中一共取coins个硬币，可以得到的最大面值和

        for (coins = 1; coins <= min(k, curCoins); ++coins) {  // 计算dp[0]
            dp[coins] = dp[coins - 1] + piles[0][coins - 1];
        }

        for (int i = 1; i < (int)piles.size(); ++i) {
            curCoins = piles[i].size();
            totalCoins += curCoins;
            vector<int> presums(curCoins + 1, 0);

            for (coins = 1; coins <= curCoins; ++coins) {
                presums[coins] = presums[coins - 1] + piles[i][coins - 1];
            }

            for (coins = min(k, totalCoins); coins > 0; --coins) {  // 从后往前dp，这样可以复用dp数组
                for (int lastCoins = 0; lastCoins <= min(coins, curCoins); ++lastCoins) {  // 枚举最后一组取的硬币个数
                    dp[coins] = max(dp[coins], presums[lastCoins] + dp[coins - lastCoins]);  // 最后一组得分加上前面取剩余硬币个数的得分
                }
            }
        }

        return dp[k];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> piles = { {1,100,3},{7,8,9} };
    check.checkInt(101, o.maxValueOfCoins(piles, 2));

    piles = { {100},{100},{100},{100},{100},{100},{1,1,1,1,1,1,700} };
    check.checkInt(706, o.maxValueOfCoins(piles, 7));

    piles = { {80,62,78,78,40,59,98,35},{79,19,100,15},{79,2,27,73,12,13,11,37,27,55,54,55,87,10,97,26,78,20,75,23,46,94,56,32,14,70,70,37,60,46,1,53} };
    check.checkInt(693, o.maxValueOfCoins(piles, 10));
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
