/* 使数组中位数等于 K 的最少操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个 非负 整数 k 。

一次操作中，你可以选择任一下标 i ，然后将 nums[i] 加 1 或者减 1 。

请你返回将 nums 中位数 变为 k 所需要的 最少 操作次数。

一个数组的 中位数 指的是数组按 非递减 顺序排序后最中间的元素。如果数组长度为偶数，我们选择中间两个数的较大值为中位数。



示例 1：

输入：nums = [2,5,6,8,5], k = 4

输出：2

解释：我们将 nums[1] 和 nums[4] 减 1 得到 [2, 4, 6, 8, 4] 。现在数组的中位数等于 k 。所以答案为 2 。

示例 2：

输入：nums = [2,5,6,8,5], k = 7

输出：3

解释：我们将 nums[1] 增加 1 两次，并且将 nums[2] 增加 1 一次，得到 [2, 7, 7, 8, 5] 。结果数组的中位数等于 k 。所以答案为 3 。

示例 3：

输入：nums = [1,2,3,4,5,6], k = 4

输出：0

解释：数组中位数已经等于 k 了，所以不需要进行任何操作。



提示：

1 <= nums.length <= 2 * 105
1 <= nums[i] <= 109
1 <= k <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());

		int size = nums.size(), half = size / 2;
		long long opers = abs(nums[half] - k);

		for (int i = half - 1; i >= 0 && nums[i] > k; --i) {
			opers += (nums[i] - k);
		}

		for (int i = half + 1; i < size && nums[i] < k; ++i) {
			opers += (k - nums[i]);
		}

		return opers;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 2,5,6,8,5 };
	check.checkLongLong(2, o.minOperationsToMakeMedianK(nums, 4));

	nums = { 2,5,6,8,5 };
	check.checkLongLong(3, o.minOperationsToMakeMedianK(nums, 7));

	nums = { 1,2,3,4,5,6 };
	check.checkLongLong(0, o.minOperationsToMakeMedianK(nums, 4));
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
