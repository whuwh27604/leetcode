/* 最大好子数组和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的数组 nums 和一个 正 整数 k 。

如果 nums 的一个子数组中，第一个元素和最后一个元素 差的绝对值恰好 为 k ，我们称这个子数组为 好 的。换句话说，如果子数组 nums[i..j] 满足 |nums[i] - nums[j]| == k ，那么它是一个好子数组。

请你返回 nums 中 好 子数组的 最大 和，如果没有好子数组，返回 0 。



示例 1：

输入：nums = [1,2,3,4,5,6], k = 1
输出：11
解释：好子数组中第一个元素和最后一个元素的差的绝对值必须为 1 。好子数组有 [1,2] ，[2,3] ，[3,4] ，[4,5] 和 [5,6] 。最大子数组和为 11 ，对应的子数组为 [5,6] 。
示例 2：

输入：nums = [-1,3,2,4,5], k = 3
输出：11
解释：好子数组中第一个元素和最后一个元素的差的绝对值必须为 3 。好子数组有 [-1,3,2] 和 [2,4,5] 。最大子数组和为 11 ，对应的子数组为 [2,4,5] 。
示例 3：

输入：nums = [-1,-2,-3,-4], k = 2
输出：-6
解释：好子数组中第一个元素和最后一个元素的差的绝对值必须为 2 。好子数组有 [-1,-2,-3] 和 [-2,-3,-4] 。最大子数组和为 -6 ，对应的子数组为 [-1,-2,-3] 。


提示：

2 <= nums.length <= 105
-109 <= nums[i] <= 109
1 <= k <= 109
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
		long long maxSubSum = LLONG_MIN;
		int size = nums.size();
		vector<long long> presums(size + 1, 0);
		unordered_map<int, pair<int, long long>> maxSums;

		for (int i = 0; i < size; ++i) {
			presums[i + 1] = presums[i] + nums[i];
		}

		for (int i = size - 1; i >= 0; --i) {
			int n = nums[i], a = n + k, b = n - k;

			if (maxSums.count(a) != 0) {
				maxSubSum = max(maxSubSum, presums[maxSums[a].first] - presums[i] + maxSums[a].second);
			}

			if (maxSums.count(b) != 0) {
				maxSubSum = max(maxSubSum, presums[maxSums[b].first] - presums[i] + maxSums[b].second);
			}

			if (maxSums.count(n) == 0) {
				maxSums[n] = { i,n };
			}
			else {
				maxSums[n] = { i,max((long long)n, presums[maxSums[n].first] - presums[i] + maxSums[n].second)};
			}
		}

		return maxSubSum == LLONG_MIN ? 0 : maxSubSum;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,3,4,5,6 };
	check.checkLongLong(11, o.maximumSubarraySum(nums, 1));

	nums = { -1,3,2,4,5 };
	check.checkLongLong(11, o.maximumSubarraySum(nums, 3));

	nums = { -1,-2,-3,-4 };
	check.checkLongLong(-6, o.maximumSubarraySum(nums, 2));
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
