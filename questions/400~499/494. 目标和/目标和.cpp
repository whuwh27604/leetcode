/* 目标和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

 

示例：

输入：nums: [1, 1, 1, 1, 1], S: 3
输出：5
解释：

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
 

提示：

数组非空，且长度不会超过 20 。
初始的数组的和不会超过 1000 。
保证返回的最终结果能被 32 位整数存下。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // 令dp[i][j]表示i个数能够得到和j的方法数，则dp[i+1][j+nums[i+1]]和dp[i+1][j-nums[i+1]]都可以基于dp[i][j]演变而来
        int i, j, row = nums.size(), sum = 0;
        for (i = 0; i < row; i++) {
            sum += nums[i];
        }

        int column = 2 * sum + 1;
        vector<vector<int>> dp(row, vector<int>(column, 0));
        if (nums[0] == 0) {
            dp[0][sum] = 2;  // 如果nums[0]==0，则可以+，可以-，算两种方法
        }
        else {
            dp[0][sum + nums[0]] = dp[0][sum - nums[0]] = 1;
        }

        for (i = 1; i < row; i++) {
            int num = nums[i];
            for (j = 0; j < column; j++) {
                if (dp[i - 1][j] == 0) {
                    continue;
                }

                if (j >= num) {
                    dp[i][j - num] += dp[i - 1][j];
                }

                if (j < column - num) {
                    dp[i][j + num] += dp[i - 1][j];
                }
            }
        }

        return (S >= -sum && S <= sum) ? dp[row - 1][sum + S] : 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,1,1,1,1 };
    check.checkInt(0, o.findTargetSumWays(nums, -6));
    check.checkInt(1, o.findTargetSumWays(nums, -5));
    check.checkInt(0, o.findTargetSumWays(nums, -4));
    check.checkInt(5, o.findTargetSumWays(nums, -3));
    check.checkInt(0, o.findTargetSumWays(nums, -2));
    check.checkInt(10, o.findTargetSumWays(nums, -1));
    check.checkInt(0, o.findTargetSumWays(nums, 0));
    check.checkInt(10, o.findTargetSumWays(nums, 1));
    check.checkInt(0, o.findTargetSumWays(nums, 2));
    check.checkInt(5, o.findTargetSumWays(nums, 3));
    check.checkInt(0, o.findTargetSumWays(nums, 4));
    check.checkInt(1, o.findTargetSumWays(nums, 5));
    check.checkInt(0, o.findTargetSumWays(nums, 6));

    nums = { 5 };
    check.checkInt(1, o.findTargetSumWays(nums, 5));
    check.checkInt(1, o.findTargetSumWays(nums, -5));
    check.checkInt(0, o.findTargetSumWays(nums, 0));
    check.checkInt(0, o.findTargetSumWays(nums, 10));
    check.checkInt(0, o.findTargetSumWays(nums, -10));

    nums = { 5,8 };
    check.checkInt(1, o.findTargetSumWays(nums, 13));
    check.checkInt(1, o.findTargetSumWays(nums, 3));
    check.checkInt(1, o.findTargetSumWays(nums, -3));
    check.checkInt(1, o.findTargetSumWays(nums, -13));
    check.checkInt(0, o.findTargetSumWays(nums, -14));
    check.checkInt(0, o.findTargetSumWays(nums, -8));
    check.checkInt(0, o.findTargetSumWays(nums, 0));
    check.checkInt(0, o.findTargetSumWays(nums, 5));
    check.checkInt(0, o.findTargetSumWays(nums, 12));
    check.checkInt(0, o.findTargetSumWays(nums, 15));

    nums = { 1,0 };
    check.checkInt(2, o.findTargetSumWays(nums, 1));
    check.checkInt(2, o.findTargetSumWays(nums, -1));
    check.checkInt(0, o.findTargetSumWays(nums, 2));

    nums = { 1,0,0 };
    check.checkInt(4, o.findTargetSumWays(nums, 1));
    check.checkInt(4, o.findTargetSumWays(nums, -1));
    check.checkInt(0, o.findTargetSumWays(nums, -2));

    nums = { 0,0,0,0,0,1 };
    check.checkInt(32, o.findTargetSumWays(nums, 1));
    check.checkInt(32, o.findTargetSumWays(nums, -1));
    check.checkInt(0, o.findTargetSumWays(nums, -2));
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
