/* 将数组分割成最多数目的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个只包含 非负 整数的数组 nums 。

我们定义满足 l <= r 的子数组 nums[l..r] 的分数为 nums[l] AND nums[l + 1] AND ... AND nums[r] ，其中 AND 是按位与运算。

请你将数组分割成一个或者更多子数组，满足：

每个 元素都 只 属于一个子数组。
子数组分数之和尽可能 小 。
请你在满足以上要求的条件下，返回 最多 可以得到多少个子数组。

一个 子数组 是一个数组中一段连续的元素。



示例 1：

输入：nums = [1,0,2,0,1,2]
输出：3
解释：我们可以将数组分割成以下子数组：
- [1,0] 。子数组分数为 1 AND 0 = 0 。
- [2,0] 。子数组分数为 2 AND 0 = 0 。
- [1,2] 。子数组分数为 1 AND 2 = 0 。
分数之和为 0 + 0 + 0 = 0 ，是我们可以得到的最小分数之和。
在分数之和为 0 的前提下，最多可以将数组分割成 3 个子数组。所以返回 3 。
示例 2：

输入：nums = [5,7,1,3]
输出：1
解释：我们可以将数组分割成一个子数组：[5,7,1,3] ，分数为 1 ，这是可以得到的最小总分数。
在总分数为 1 的前提下，最多可以将数组分割成 1 个子数组。所以返回 1 。


提示：

1 <= nums.length <= 105
0 <= nums[i] <= 106
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int size = nums.size(), subarrays = 0, score = INT_MAX;

        /* 1、AND的结果只会越来越小，要使分数之和最小，显然应该整个数组作为1组操作
           2、如果整个数组的分数为0，那么可能分割为多个子数组，每个子数组的分数都为0。当操作到分数为0时，应该立即分割。
           3、如果整个数组的分数为x != 0，那么不能分割。假设分割为nums1和nums2，它们的分数 >= x，分数和 >= 2x，比不分割要差 */
        for (int i = 0; i < size; ++i) {
            score &= nums[i];

            if (score == 0) {
                ++subarrays;
                score = INT_MAX;
            }
        }

        return subarrays == 0 ? 1 : subarrays;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,0,2,0,1,2 };
    check.checkInt(3, o.maxSubarrays(nums));

    nums = { 5,7,1,3 };
    check.checkInt(1, o.maxSubarrays(nums));

    nums = { 5 };
    check.checkInt(1, o.maxSubarrays(nums));
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
