/* 统计趣味子数组的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，以及整数 modulo 和整数 k 。

请你找出并统计数组中 趣味子数组 的数目。

如果 子数组 nums[l..r] 满足下述条件，则称其为 趣味子数组 ：

在范围 [l, r] 内，设 cnt 为满足 nums[i] % modulo == k 的索引 i 的数量。并且 cnt % modulo == k 。
以整数形式表示并返回趣味子数组的数目。

注意：子数组是数组中的一个连续非空的元素序列。



示例 1：

输入：nums = [3,2,4], modulo = 2, k = 1
输出：3
解释：在这个示例中，趣味子数组分别是：
子数组 nums[0..0] ，也就是 [3] 。
- 在范围 [0, 0] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
- 因此 cnt = 1 ，且 cnt % modulo == k 。
子数组 nums[0..1] ，也就是 [3,2] 。
- 在范围 [0, 1] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
- 因此 cnt = 1 ，且 cnt % modulo == k 。
子数组 nums[0..2] ，也就是 [3,2,4] 。
- 在范围 [0, 2] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
- 因此 cnt = 1 ，且 cnt % modulo == k 。
可以证明不存在其他趣味子数组。因此，答案为 3 。
示例 2：

输入：nums = [3,1,9,6], modulo = 3, k = 0
输出：2
解释：在这个示例中，趣味子数组分别是：
子数组 nums[0..3] ，也就是 [3,1,9,6] 。
- 在范围 [0, 3] 内，只存在 3 个下标 i = 0, 2, 3 满足 nums[i] % modulo == k 。
- 因此 cnt = 3 ，且 cnt % modulo == k 。
子数组 nums[1..1] ，也就是 [1] 。
- 在范围 [1, 1] 内，不存在下标满足 nums[i] % modulo == k 。
- 因此 cnt = 0 ，且 cnt % modulo == k 。
可以证明不存在其他趣味子数组，因此答案为 2 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= modulo <= 109
0 <= k < modulo
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0;
        int sum = 0;  // 如果num % modulo == k则计数1，sum是计数的前缀和
        unordered_map<int, int> sumRemainderCount;  // sum对modulo取余的结果计数
        sumRemainderCount[0] = 1;  // 初始加入一个sum为0的计数

        for (int num : nums) {
            sum += (num % modulo == k ? 1 : 0);
            int remainder = sum % modulo;  // nums[0, i]子数组的计数余数为remainder，那么只需要知道计数余数为other的子数组nums[0, j]的个数，nums[j + 1, i]都是满足计数余数为k的子数组
            int other = (remainder + modulo - k) % modulo;  // remainder - k可能为负数
            if (sumRemainderCount.count(other) != 0) {
                ans += sumRemainderCount[other];
            }
            ++sumRemainderCount[remainder];  // 计算完满足要求的子数组个数后更新sum对modulo取余的结果计数
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,2,4 };
    check.checkLongLong(3, o.countInterestingSubarrays(nums, 2, 1));

    nums = { 3,1,9,6 };
    check.checkLongLong(2, o.countInterestingSubarrays(nums, 3, 0));

    nums = { 3 };
    check.checkLongLong(0, o.countInterestingSubarrays(nums, 3, 0));

    nums = { 3 };
    check.checkLongLong(1, o.countInterestingSubarrays(nums, 2, 1));
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
