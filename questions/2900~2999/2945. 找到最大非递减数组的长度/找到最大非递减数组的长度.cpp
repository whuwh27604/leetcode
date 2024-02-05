/* 找到最大非递减数组的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。

你可以执行任意次操作。每次操作中，你需要选择一个 子数组 ，并将这个子数组用它所包含元素的 和 替换。比方说，给定数组是 [1,3,5,6] ，你可以选择子数组 [3,5] ，用子数组的和 8 替换掉子数组，然后数组会变为 [1,8,6] 。

请你返回执行任意次操作以后，可以得到的 最长非递减 数组的长度。

子数组 指的是一个数组中一段连续 非空 的元素序列。



示例 1：

输入：nums = [5,2,2]
输出：1
解释：这个长度为 3 的数组不是非递减的。
我们有 2 种方案使数组长度为 2 。
第一种，选择子数组 [2,2] ，对数组执行操作后得到 [5,4] 。
第二种，选择子数组 [5,2] ，对数组执行操作后得到 [7,2] 。
这两种方案中，数组最后都不是 非递减 的，所以不是可行的答案。
如果我们选择子数组 [5,2,2] ，并将它替换为 [9] ，数组变成非递减的。
所以答案为 1 。
示例 2：

输入：nums = [1,2,3,4]
输出：4
解释：数组已经是非递减的。所以答案为 4 。
示例 3：

输入：nums = [4,3,2,6]
输出：3
解释：将 [3,2] 替换为 [5] ，得到数组 [4,5,6] ，它是非递减的。
最大可能的答案为 3 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105
*/

#include <iostream>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
		int size = nums.size();
		vector<int> dp(size + 1, 0);  // dp[i]表示nums[1, i]的最大非递减数组长度，数组下标从1开始
		vector<long long> last(size + 1, 0);  // last[i]表示dp[i]取到最大值时，数组最后一个元素的最小值
		vector<long long> sum(size + 1, 0);  // nums数组的前缀和
		deque<int> indices;  // 索引i递增、sums[i] + last[i]单调递增队列

		/* 对每个dp[i]，需要往前找位置 j ，如果sum[j + 1, ... , i] > last[j]，那么可以把该子数组合并为一个数，从位置 j 转移到位置 i
		*  即sum[i] - sum[j] >= last[j]时，dp[i] = dp[j] + 1，即sum[i] >= sum[j] + last[j]
		*  假设有两个位置 j1/j2 都可以转移，j1 < j2，显然last[i]_j1 > last[i]_j2，所以应该选择j2，也就是往前找的第一个满足要求的位置就应该转移
		*/

		for (int i = 1; i <= size; ++i) {
			sum[i] = sum[i - 1] + nums[i - 1];
			int index = 0;

			// 因为要找 <= sum[i]的第一个sum[j] + last[j]，后续sum[i]越来越大，更小的sum[j] + last[j]已经没有必要保留
			while (!indices.empty() && sum[indices.front()] + last[indices.front()] <= sum[i]) {
				index = indices.front();
				indices.pop_front();
			}
			if (index != 0 && (indices.empty() || sum[indices.front()] + last[indices.front()] > sum[i])) {
				indices.push_front(index);  // 但是要注意第一个 j 要保留下来，会影响后续的计算
			}

			dp[i] = dp[index] + 1;  // 此时index是满足条件的可以转移的位置，更新dp和last
			last[i] = sum[i] - sum[index];

			// 保持sum[i] + last[i]的单调递增性，更小的 i 有更大的sum[i] + last[i]，不需要再保留了，后续只可能优先找到当前位置 i
			while (!indices.empty() && sum[indices.back()] + last[indices.back()] >= sum[i] + last[i]) {
				indices.pop_back();
			}
			indices.push_back(i);
		}

		return dp[size];
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,1,3,3 };
	check.checkInt(4, o.findMaximumLength(nums));

	nums = { 5,2,2 };
	check.checkInt(1, o.findMaximumLength(nums));

	nums = { 1,2,3,4 };
	check.checkInt(4, o.findMaximumLength(nums));

	nums = { 4,3,2,6 };
	check.checkInt(3, o.findMaximumLength(nums));

	nums = { 418,421,309,442,80,305,166,884,791,353 };
	check.checkInt(5, o.findMaximumLength(nums));

	nums = { 272,482,115,925,983 };
	check.checkInt(4, o.findMaximumLength(nums));

	nums = { 38,986,134,156 };
	check.checkInt(2, o.findMaximumLength(nums));
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
