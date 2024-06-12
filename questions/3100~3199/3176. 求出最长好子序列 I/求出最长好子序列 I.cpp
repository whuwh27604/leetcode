/* 求出最长好子序列 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个 非负 整数 k 。如果一个整数序列 seq 满足在范围下标范围 [0, seq.length - 2] 中存在 不超过 k 个下标 i 满足 seq[i] != seq[i + 1] ，那么我们称这个整数序列为 好 序列。

请你返回 nums 中 好
子序列
 的最长长度



示例 1：

输入：nums = [1,2,1,1,3], k = 2

输出：4

解释：

最长好子序列为 [1,2,1,1,3] 。

示例 2：

输入：nums = [1,2,3,4,5,1], k = 0

输出：2

解释：

最长好子序列为 [1,2,3,4,5,1] 。



提示：

1 <= nums.length <= 500
1 <= nums[i] <= 109
0 <= k <= min(nums.length, 25)
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int size = (int)nums.size(), ans = 1;
        vector<vector<int>> dp(size, vector<int>(k + 1, -1));
        dp[0][0] = 1;

        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] == nums[j]) {
                    dp[i][0] = max(dp[i][0], dp[j][0] + 1);
                }
                else {
                    dp[i][0] = max(dp[i][0], 1);
                }
                ans = max(ans, dp[i][0]);

                for (int c = 1; c <= k; ++c) {
                    if (nums[i] == nums[j]) {
                        if (dp[j][c] != -1) {
                            dp[i][c] = max(dp[i][c], dp[j][c] + 1);
                            ans = max(ans, dp[i][c]);
                        }
                    }
                    else {
                        if (dp[j][c - 1] != -1) {
                            dp[i][c] = max(dp[i][c], dp[j][c - 1] + 1);
                            ans = max(ans, dp[i][c]);
                        }
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,1,1,3 };
    check.checkInt(4, o.maximumLength(nums, 2));

    nums = { 1,2,3,4,5,1 };
    check.checkInt(2, o.maximumLength(nums, 0));

    nums = { 2 };
    check.checkInt(1, o.maximumLength(nums, 0));

    nums = { 29,30,30 };
    check.checkInt(2, o.maximumLength(nums, 0));
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
