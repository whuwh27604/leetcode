/* 预测赢家.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。

给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。

 

示例 1：

输入：[1, 5, 2]
输出：False
解释：一开始，玩家1可以从1和2中进行选择。
如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下 1（或者 2 ）可选。
所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。
因此，玩家 1 永远不会成为赢家，返回 False 。
示例 2：

输入：[1, 5, 233, 7]
输出：True
解释：玩家 1 一开始选择 1 。然后玩家 2 必须从 5 和 7 中进行选择。无论玩家 2 选择了哪个，玩家 1 都可以选择 233 。
     最终，玩家 1（234 分）比玩家 2（12 分）获得更多的分数，所以返回 True，表示玩家 1 可以成为赢家。
 

提示：

1 <= 给定的数组长度 <= 20.
数组里所有分数都为非负数且不会大于 10000000 。
如果最终两个玩家的分数相等，那么玩家 1 仍为赢家。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/predict-the-winner
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        if (size % 2 == 0) {
            /* size为偶数时，先手必胜。假设num编号为n,n+1,2n,2n+1,3n,3n+1...，先手方总是能够控制自己拿到所有的n,2n,3n...
               或者n+1,2n+1,3n+1...所以只需要选择和大的那一份拿就可以了 */
            return true;
        }

        /* 令dp[i][j]表示nums[i,j]先手能够赢多少分，则dp[i][j+1]=max(nums[i]-dp[i+1][j+1], num[j+1]-dp[i][j])
           对nums[i,j+1]来说，如果先手选nums[i]，那么剩下nums[i+1,j+1]，自己变为后手；
           如果先手选nums[j+1]，那么剩下nums[i,j]，自己变为后手*/
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++) {
            dp[i][i] = nums[i];
        }

        int i = 0, j = 1;
        while (j < size) {  // 从左上往右下动态规划
            dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            ++i;
            if (++j == size) {
                j = size - i + 1;
                i = 0;
            }
        }

        return dp[0][size - 1] >= 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 0 };
    check.checkBool(true, o.PredictTheWinner(nums));

    nums = { 1,5,2 };
    check.checkBool(false, o.PredictTheWinner(nums));

    nums = { 1,5,233,7 };
    check.checkBool(true, o.PredictTheWinner(nums));

    nums = { 3,9,1,2 };
    check.checkBool(true, o.PredictTheWinner(nums));

    nums = { 0,0,7,6,5,6,1 };
    check.checkBool(false, o.PredictTheWinner(nums));

    nums = { 2,4,55,6,8 };
    check.checkBool(false, o.PredictTheWinner(nums));
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
