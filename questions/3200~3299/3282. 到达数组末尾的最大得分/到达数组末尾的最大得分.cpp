/* 到达数组末尾的最大得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums 。

你的目标是从下标 0 出发，到达下标 n - 1 处。每次你只能移动到 更大 的下标处。

从下标 i 跳到下标 j 的得分为 (j - i) * nums[i] 。

请你返回你到达最后一个下标处能得到的 最大总得分 。



示例 1：

输入：nums = [1,3,1,5]

输出：7

解释：

一开始跳到下标 1 处，然后跳到最后一个下标处。总得分为 1 * 1 + 2 * 3 = 7 。

示例 2：

输入：nums = [4,3,1,3,2]

输出：16

解释：

直接跳到最后一个下标处。总得分为 4 * 4 = 16 。



提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        /* ix < iy, x < y
        * score[ix -> target] = (target - ix) * x
        * score[ix -> iy -> target] = (iy - ix) * x + (target - iy) * y
        * score[ix -> iy -> target] > score[ix -> target]
        * 所以从左往右，碰到更大的数就应该跳，碰到较小的数不要跳 */
        int n = (int)nums.size(), score = 0;
        long long totalScore = 0;

        for (int i = 0; i < n - 1; ++i) {
            score = max(score, nums[i]);
            totalScore += score;
        }

        return totalScore;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,3,1,5 };
    check.checkLongLong(7, o.findMaximumScore(nums));

    nums = { 4,3,1,3,2 };
    check.checkLongLong(16, o.findMaximumScore(nums));

    nums = { 5 };
    check.checkLongLong(0, o.findMaximumScore(nums));
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
