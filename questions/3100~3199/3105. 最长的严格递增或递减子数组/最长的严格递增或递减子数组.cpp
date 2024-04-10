/* 最长的严格递增或递减子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。

返回数组 nums 中 严格递增 或 严格递减 的最长非空子数组的长度。



示例 1：

输入：nums = [1,4,3,3,2]

输出：2

解释：

nums 中严格递增的子数组有[1]、[2]、[3]、[3]、[4] 以及 [1,4] 。

nums 中严格递减的子数组有[1]、[2]、[3]、[3]、[4]、[3,2] 以及 [4,3] 。

因此，返回 2 。

示例 2：

输入：nums = [3,3,3,3]

输出：1

解释：

nums 中严格递增的子数组有 [3]、[3]、[3] 以及 [3] 。

nums 中严格递减的子数组有 [3]、[3]、[3] 以及 [3] 。

因此，返回 1 。

示例 3：

输入：nums = [3,2,1]

输出：3

解释：

nums 中严格递增的子数组有 [3]、[2] 以及 [1] 。

nums 中严格递减的子数组有 [3]、[2]、[1]、[3,2]、[2,1] 以及 [3,2,1] 。

因此，返回 3 。



提示：

1 <= nums.length <= 50
1 <= nums[i] <= 50
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
		return max(getMaxIncreasingSub(nums), getMaxDecreasingSub(nums));
    }

	int getMaxIncreasingSub(vector<int>& nums) {
		int size = nums.size(), prev = 0, len = 0, maxLen = 0;

		for (int i = 0; i < size; ++i) {
			if (nums[i] > prev) {
				++len;
			}
			else {
				len = 1;
			}

			prev = nums[i];
			maxLen = max(maxLen, len);
		}

		return maxLen;
	}

	int getMaxDecreasingSub(vector<int>& nums) {
		int size = nums.size(), prev = 0, len = 0, maxLen = 0;

		for (int i = 0; i < size; ++i) {
			if (nums[i] < prev) {
				++len;
			}
			else {
				len = 1;
			}

			prev = nums[i];
			maxLen = max(maxLen, len);
		}

		return maxLen;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,4,3,3,2 };
	check.checkInt(2, o.longestMonotonicSubarray(nums));

	nums = { 3,3,3,3 };
	check.checkInt(1, o.longestMonotonicSubarray(nums));

	nums = { 3,2,1 };
	check.checkInt(3, o.longestMonotonicSubarray(nums));

	nums = { 3 };
	check.checkInt(1, o.longestMonotonicSubarray(nums));
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
