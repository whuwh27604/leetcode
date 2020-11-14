/* 石子游戏 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
亚历克斯和李继续他们的石子游戏。许多堆石子 排成一行，每堆都有正整数颗石子 piles[i]。游戏以谁手中的石子最多来决出胜负。

亚历克斯和李轮流进行，亚历克斯先开始。最初，M = 1。

在每个玩家的回合中，该玩家可以拿走剩下的 前 X 堆的所有石子，其中 1 <= X <= 2M。然后，令 M = max(M, X)。

游戏一直持续到所有石子都被拿走。

假设亚历克斯和李都发挥出最佳水平，返回亚历克斯可以得到的最大数量的石头。

 

示例：

输入：piles = [2,7,9,4,4]
输出：10
解释：
如果亚历克斯在开始时拿走一堆石子，李拿走两堆，接着亚历克斯也拿走两堆。在这种情况下，亚历克斯可以拿到 2 + 4 + 4 = 10 颗石子。
如果亚历克斯在开始时拿走两堆石子，那么李就可以拿走剩下全部三堆石子。在这种情况下，亚历克斯可以拿到 2 + 7 = 9 颗石子。
所以我们返回更大的 10。
 

提示：

1 <= piles.length <= 100
1 <= piles[i] <= 10 ^ 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stone-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int start, M, size = piles.size(), maxM = (size + 1) / 2;
        vector<vector<int>> dp(size + 1, vector<int>(maxM + 1, 0));  // dp[start][M]表示从piles[start]位置开始，可以取[1,2M]，最多可以取到的石头
        vector<int> preSum(size + 1, 0);

        getPreSum(piles, preSum);

        for (start = size - 1; start >= 0; --start) {
            for (M = 1; M <= maxM; ++M) {
                if (start + 2 * M >= size) {  // 已经可以把剩下的stone全收掉
                    dp[start][M] = preSum[size] - preSum[start];
                    continue;
                }

                for (int i = start; i < (start + 2 * M) && i < size; ++i) {  // 从1到2M依次尝试
                    int stones = preSum[i + 1] - preSum[start];  // 取[start,i]的stone
                    int newM = min(maxM, max(M, i - start + 1));  // 超过maxM没有意义，都是可以一把全收
                    // 自己取[start,i]以后，还剩preSum[size] - preSum[i+1]，对手最多取dp[i + 1][newM]，剩下的是自己的
                    stones += (preSum[size] - preSum[i + 1] - dp[i + 1][newM]);
                    dp[start][M] = max(dp[start][M], stones);
                }
            }
        }

        return dp[0][1];
    }

    void getPreSum(vector<int>& piles, vector<int>& preSum) {
        for (unsigned int i = 0; i < piles.size(); ++i) {
            preSum[i + 1] = preSum[i] + piles[i];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> piles = { 2,7,9,4,4 };
    check.checkInt(10, o.stoneGameII(piles));

    piles = { 1,5,7,9,9 };
    check.checkInt(17, o.stoneGameII(piles));

    piles = { 1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(26, o.stoneGameII(piles));

    piles = { 1,2,3,4,5,6,7,8,9,10,10,9,8,7,6,5,4,3,2,1 };
    check.checkInt(55, o.stoneGameII(piles));

    piles = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50 };
    check.checkInt(638, o.stoneGameII(piles));

    piles = { 9 };
    check.checkInt(9, o.stoneGameII(piles));

    piles = { 9,8 };
    check.checkInt(17, o.stoneGameII(piles));
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
