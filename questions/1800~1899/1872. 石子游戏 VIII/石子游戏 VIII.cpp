/* 石子游戏 VIII.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 和 Bob 玩一个游戏，两人轮流操作， Alice 先手 。

总共有 n 个石子排成一行。轮到某个玩家的回合时，如果石子的数目 大于 1 ，他将执行以下操作：

选择一个整数 x > 1 ，并且 移除 最左边的 x 个石子。
将 移除 的石子价值之 和 累加到该玩家的分数中。
将一个 新的石子 放在最左边，且新石子的值为被移除石子值之和。
当只剩下 一个 石子时，游戏结束。

Alice 和 Bob 的 分数之差 为 (Alice 的分数 - Bob 的分数) 。 Alice 的目标是 最大化 分数差，Bob 的目标是 最小化 分数差。

给你一个长度为 n 的整数数组 stones ，其中 stones[i] 是 从左边起 第 i 个石子的价值。请你返回在双方都采用 最优 策略的情况下，Alice 和 Bob 的 分数之差 。

 

示例 1：

输入：stones = [-1,2,-3,4,-5]
输出：5
解释：
- Alice 移除最左边的 4 个石子，得分增加 (-1) + 2 + (-3) + 4 = 2 ，并且将一个价值为 2 的石子放在最左边。stones = [2,-5] 。
- Bob 移除最左边的 2 个石子，得分增加 2 + (-5) = -3 ，并且将一个价值为 -3 的石子放在最左边。stones = [-3] 。
两者分数之差为 2 - (-3) = 5 。
示例 2：

输入：stones = [7,-6,5,10,5,-2,-6]
输出：13
解释：
- Alice 移除所有石子，得分增加 7 + (-6) + 5 + 10 + 5 + (-2) + (-6) = 13 ，并且将一个价值为 13 的石子放在最左边。stones = [13] 。
两者分数之差为 13 - 0 = 13 。
示例 3：

输入：stones = [-10,-12]
输出：-22
解释：
- Alice 只有一种操作，就是移除所有石子。得分增加 (-10) + (-12) = -22 ，并且将一个价值为 -22 的石子放在最左边。stones = [-22] 。
两者分数之差为 (-22) - 0 = -22 。
 

提示：

n == stones.length
2 <= n <= 105
-104 <= stones[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stone-game-viii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int i, size = stones.size();
        vector<int> presums(size);
        presums[0] = stones[0];

        for (i = 1; i < size; ++i) {
            presums[i] = presums[i - 1] + stones[i];
        }

        int dp = presums.back();  // dp[i]表示alice面对stones[i,size)时（不包括新加入的最左边的石头），可以获得的最大差值

        /* alice可以选择[i,i],[i,i+1]...[i,size-1]，可以获得presums[i],presums[i+1]...presums[size-1]的分数；
           对应的bob可以获得dp[i+1],dp[i+2]...0最大分差，选择presums[i]-dp[i+1],presums[i+1]-dp[i+2]...presums[size-1]分差最大的一个 */
        for (i = size - 2; i > 0; --i) {
            dp = max(presums[i] - dp, dp);
        }

        return dp;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> stones = { -1,2,-3,4,-5 };
    check.checkInt(5, o.stoneGameVIII(stones));

    stones = { 7,-6,5,10,5,-2,-6 };
    check.checkInt(13, o.stoneGameVIII(stones));

    stones = { -10,-12 };
    check.checkInt(-22, o.stoneGameVIII(stones));

    stones = { 3,-1,-1,-1,-1 };
    check.checkInt(1, o.stoneGameVIII(stones));
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
