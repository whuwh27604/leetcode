/* 和为目标值的最长子序列的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个整数 target 。

返回和为 target 的 nums 子序列中，子序列 长度的最大值 。如果不存在和为 target 的子序列，返回 -1 。

子序列 指的是从原数组中删除一些或者不删除任何元素后，剩余元素保持原来的顺序构成的数组。



示例 1：

输入：nums = [1,2,3,4,5], target = 9
输出：3
解释：总共有 3 个子序列的和为 9 ：[4,5] ，[1,3,5] 和 [2,3,4] 。最长的子序列是 [1,3,5] 和 [2,3,4] 。所以答案为 3 。
示例 2：

输入：nums = [4,1,3,2,1,5], target = 7
输出：4
解释：总共有 5 个子序列的和为 7 ：[4,3] ，[4,1,2] ，[4,2,1] ，[1,1,5] 和 [1,3,2,1] 。最长子序列为 [1,3,2,1] 。所以答案为 4 。
示例 3：

输入：nums = [1,1,5,4,5], target = 3
输出：-1
解释：无法得到和为 3 的子序列。


提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 1000
1 <= target <= 1000
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> dp(size + 1, vector<int>(target + 1, -1));
        dp[0][0] = 0;

        for (int i = 1; i <= size; ++i) {
            dp[i][0] = 0;
            int num = nums[i - 1];

            for (int t = 1; t <= target; ++t) {
                dp[i][t] = dp[i - 1][t];
                if (t >= num && dp[i - 1][t - num] != -1) {
                    dp[i][t] = max(dp[i][t], dp[i - 1][t - num] + 1);
                }
            }
        }

        return dp[size][target];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4,5 };
    check.checkInt(3, o.lengthOfLongestSubsequence(nums, 9));

    nums = { 4,1,3,2,1,5 };
    check.checkInt(4, o.lengthOfLongestSubsequence(nums, 7));

    nums = { 1,1,5,4,5 };
    check.checkInt(-1, o.lengthOfLongestSubsequence(nums, 3));

    nums = { 1000 };
    check.checkInt(-1, o.lengthOfLongestSubsequence(nums, 12));

    nums = { 1,3,3,8 };
    check.checkInt(3, o.lengthOfLongestSubsequence(nums, 7));
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
