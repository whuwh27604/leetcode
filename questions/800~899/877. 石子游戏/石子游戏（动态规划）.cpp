/* 石子游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。

游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。

亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。

假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。

 

示例：

输入：[5,3,4,5]
输出：true
解释：
亚历克斯先开始，只能拿前 5 颗或后 5 颗石子 。
假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
如果李拿走前 3 颗，那么剩下的是 [4,5]，亚历克斯拿走后 5 颗赢得 10 分。
如果李拿走后 5 颗，那么剩下的是 [3,4]，亚历克斯拿走后 4 颗赢得 9 分。
这表明，取前 5 颗石子对亚历克斯来说是一个胜利的举动，所以我们返回 true 。
 

提示：

2 <= piles.length <= 500
piles.length 是偶数。
1 <= piles[i] <= 500
sum(piles) 是奇数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stone-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        /* 令dp[i][j]表示piles[i,j]先手能赢多少分，则dp[i][j+1]=max(nums[i]-dp[i+1][j+1], nums[j+1]-dp[i][j])
           对nums[i,j+1]来说，如果先手选nums[i]，那么剩下nums[i+1,j+1]，自己变为后手；
           如果先手选nums[j+1]，那么剩下nums[i,j]，自己变为后手 */
        int i, j, size = piles.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        
        for (i = 0; i < size; ++i) {
            dp[i][i] = piles[i];
        }

        i = 0;
        j = 1;
        while (j < size) {
            dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            ++i;
            if (++j == size) {
                j = size - i + 1;
                i = 0;
            }
        }

        return dp[0][size - 1] > 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> piles = { 5,3,4,5 };
    check.checkBool(true, o.stoneGame(piles));

    piles = { 3,2,10,4 };
    check.checkBool(true, o.stoneGame(piles));
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
