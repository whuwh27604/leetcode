/* 石子游戏 VII.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
石子游戏中，爱丽丝和鲍勃轮流进行自己的回合，爱丽丝先开始 。

有 n 块石子排成一排。每个玩家的回合中，可以从行中 移除 最左边的石头或最右边的石头，并获得与该行中剩余石头值之 和 相等的得分。当没有石头可移除时，得分较高者获胜。

鲍勃发现他总是输掉游戏（可怜的鲍勃，他总是输），所以他决定尽力 减小得分的差值 。爱丽丝的目标是最大限度地 扩大得分的差值 。

给你一个整数数组 stones ，其中 stones[i] 表示 从左边开始 的第 i 个石头的值，如果爱丽丝和鲍勃都 发挥出最佳水平 ，请返回他们 得分的差值 。

 

示例 1：

输入：stones = [5,3,1,4,2]
输出：6
解释：
- 爱丽丝移除 2 ，得分 5 + 3 + 1 + 4 = 13 。游戏情况：爱丽丝 = 13 ，鲍勃 = 0 ，石子 = [5,3,1,4] 。
- 鲍勃移除 5 ，得分 3 + 1 + 4 = 8 。游戏情况：爱丽丝 = 13 ，鲍勃 = 8 ，石子 = [3,1,4] 。
- 爱丽丝移除 3 ，得分 1 + 4 = 5 。游戏情况：爱丽丝 = 18 ，鲍勃 = 8 ，石子 = [1,4] 。
- 鲍勃移除 1 ，得分 4 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [4] 。
- 爱丽丝移除 4 ，得分 0 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [] 。
得分的差值 18 - 12 = 6 。
示例 2：

输入：stones = [7,90,5,1,100,10,10,2]
输出：122
 

提示：

n == stones.length
2 <= n <= 1000
1 <= stones[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stone-game-vii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int i = 0, j = 1, size = stones.size();
        vector<int> presum(size + 1);
        getPresum(stones, presum);
        vector<vector<int>> dp(size, vector<int>(size, 0));  // dp[i][j]表示先手面对stones[i,j]时能够得到的最大分差

        while (j < size) {
            /* 当先手面对stones[i,j]时，有两个选择：
               1、选stones[i]，那么可以获得分数stones[i+1,j]=presum[j + 1]-presum[i + 1]，接下来是对手的先手面对stones[i+1,j]，对手可以获得的最大分差是dp[i+1][j]，
                  所以选择stones[i]最终可以获得的最大分差是presum[j + 1]-presum[i + 1]-dp[i+1][j]
               2、选stones[j]，那么可以获得分数stones[i,j-1]=presum[j]-presum[i]，接下来是对手的先手面对stones[i,j-1]，对手可以获得的最大分差是dp[i][j-1]，
                  所以选择stones[j]最终可以获得的最大分差是presum[j]-presum[i]-dp[i][j-1] */
            dp[i][j] = max(presum[j + 1] - presum[i + 1] - dp[i + 1][j], presum[j] - presum[i] - dp[i][j - 1]);

            ++i, ++j;
            if (j == size) {
                j = size - i + 1;
                i = 0;
            }
        }

        return dp[0][size - 1];
    }

    void getPresum(vector<int>& stones, vector<int>& presum) {
        presum[0] = 0;

        for (unsigned int i = 0; i < stones.size(); ++i) {
            presum[i + 1] = presum[i] + stones[i];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> stones = { 5,3,1,4,2 };
    check.checkInt(6, o.stoneGameVII(stones));

    stones = { 7,90,5,1,100,10,10,2 };
    check.checkInt(122, o.stoneGameVII(stones));

    stones = { 5,8 };
    check.checkInt(8, o.stoneGameVII(stones));
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
