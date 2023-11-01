/* 使数组变美的最小增量运算数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、长度为 n 的整数数组 nums ，和一个整数 k 。

你可以执行下述 递增 运算 任意 次（可以是 0 次）：

从范围 [0, n - 1] 中选择一个下标 i ，并将 nums[i] 的值加 1 。
如果数组中任何长度 大于或等于 3 的子数组，其 最大 元素都大于或等于 k ，则认为数组是一个 美丽数组 。

以整数形式返回使数组变为 美丽数组 需要执行的 最小 递增运算数。

子数组是数组中的一个连续 非空 元素序列。



示例 1：

输入：nums = [2,3,0,0,2], k = 4
输出：3
解释：可以执行下述递增运算，使 nums 变为美丽数组：
选择下标 i = 1 ，并且将 nums[1] 的值加 1 -> [2,4,0,0,2] 。
选择下标 i = 4 ，并且将 nums[4] 的值加 1 -> [2,4,0,0,3] 。
选择下标 i = 4 ，并且将 nums[4] 的值加 1 -> [2,4,0,0,4] 。
长度大于或等于 3 的子数组为 [2,4,0], [4,0,0], [0,0,4], [2,4,0,0], [4,0,0,4], [2,4,0,0,4] 。
在所有子数组中，最大元素都等于 k = 4 ，所以 nums 现在是美丽数组。
可以证明无法用少于 3 次递增运算使 nums 变为美丽数组。
因此，答案为 3 。
示例 2：

输入：nums = [0,1,3,3], k = 5
输出：2
解释：可以执行下述递增运算，使 nums 变为美丽数组：
选择下标 i = 2 ，并且将 nums[2] 的值加 1 -> [0,1,4,3] 。
选择下标 i = 2 ，并且将 nums[2] 的值加 1 -> [0,1,5,3] 。
长度大于或等于 3 的子数组为 [0,1,5]、[1,5,3]、[0,1,5,3] 。
在所有子数组中，最大元素都等于 k = 5 ，所以 nums 现在是美丽数组。
可以证明无法用少于 2 次递增运算使 nums 变为美丽数组。
因此，答案为 2 。
示例 3：

输入：nums = [1,1,2], k = 1
输出：0
解释：在这个示例中，只有一个长度大于或等于 3 的子数组 [1,1,2] 。
其最大元素 2 已经大于 k = 1 ，所以无需执行任何增量运算。
因此，答案为 0 。


提示：

3 <= n == nums.length <= 105
0 <= nums[i] <= 109
0 <= k <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int size = nums.size();
        long long dp0 = nums[0] < k ? k - nums[0] : 0;  // dp[i]表示修改nums[i]，使nums[0, i]变美的最小操作次数
        long long dp1 = nums[1] < k ? k - nums[1] : 0;
        long long dp2 = nums[2] < k ? k - nums[2] : 0;

        for (int i = 3; i < size; ++i) {
            long long dp = min({ dp0, dp1, dp2 }) + (nums[i] < k ? k - nums[i] : 0);
            dp0 = dp1;
            dp1 = dp2;
            dp2 = dp;
        }

        return min({ dp0,dp1,dp2 });
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,0,0,2 };
    check.checkLongLong(3, o.minIncrementOperations(nums, 4));

    nums = { 0,1,3,3 };
    check.checkLongLong(2, o.minIncrementOperations(nums, 5));

    nums = { 1,1,2 };
    check.checkLongLong(0, o.minIncrementOperations(nums, 1));
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
