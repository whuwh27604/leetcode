/* 打家劫舍 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2:

输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        if (size == 1) {
            return nums[0];
        }

        if (size == 2) {
            return max(nums[0], nums[1]);
        }

        int dpN1 = dpN(nums, 0, size - 1);  // 选第一个，不选最后一个
        int dpN2 = dpN(nums, 1, size);  // 不选第一个，选最后一个
        return max(dpN1, dpN2);
    }

    int dpN(vector<int>& nums, int start, int N) {
        int prevTwo = nums[start];
        int prev = max(nums[start], nums[start + 1]);
        int dp = prev;
        for (int i = start + 2; i < N; i++) {
            dp = max(prevTwo + nums[i], prev);  // dp[n] = max(dp[n-1], dp[n-2]+nums[n])
            prevTwo = prev;
            prev = dp;
        }

        return dp;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = {};
    check.checkInt(0, o.rob(nums));

    nums = { 5 };
    check.checkInt(5, o.rob(nums));

    nums = { 5,6 };
    check.checkInt(6, o.rob(nums));

    nums = { 6,5 };
    check.checkInt(6, o.rob(nums));

    nums = { 2,3,2 };
    check.checkInt(3, o.rob(nums));

    nums = { 1,2,3,1 };
    check.checkInt(4, o.rob(nums));

    nums = { 2,4,3 };
    check.checkInt(4, o.rob(nums));

    nums = { 2,7,9,3,1 };
    check.checkInt(11, o.rob(nums));

    nums = { 2,7,9,3,1,3 };
    check.checkInt(13, o.rob(nums));
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
