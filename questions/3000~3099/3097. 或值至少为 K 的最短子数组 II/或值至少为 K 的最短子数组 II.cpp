/* 或值至少为 K 的最短子数组 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 非负 整数数组 nums 和一个整数 k 。

如果一个数组中所有元素的按位或运算 OR 的值 至少 为 k ，那么我们称这个数组是 特别的 。

请你返回 nums 中 最短特别非空
子数组
的长度，如果特别子数组不存在，那么返回 -1 。



示例 1：

输入：nums = [1,2,3], k = 2

输出：1

解释：

子数组 [3] 的按位 OR 值为 3 ，所以我们返回 1 。

示例 2：

输入：nums = [2,1,8], k = 10

输出：3

解释：

子数组 [2,1,8] 的按位 OR 值为 11 ，所以我们返回 3 。

示例 3：

输入：nums = [1,2], k = 0

输出：1

解释：

子数组 [1] 的按位 OR 值为 1 ，所以我们返回 1 。



提示：

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 109
0 <= k <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
		if (k == 0) {
			return 1;
		}

		int size = nums.size(), right = 0, minLen = INT_MAX;
		bool valid = false;
		vector<int> count(32, 0), target(32, 0);

		getTarget(k, target);

		for (int left = 0; left < size; ++left) {
			while (!valid && right < size) {
				slide(count, nums[right++], 1);
				valid = check(count, target);
			}

			if (valid) {
				minLen = min(minLen, right - left);
			}

			slide(count, nums[left], -1);
			valid = check(count, target);
		}

		return minLen == INT_MAX ? -1 : minLen;
    }

	void getTarget(int k, vector<int>& target) {
		int index = 0;

		while (k != 0) {
			if ((k & 1) != 0) {
				target[index] = 1;
			}

			k >>= 1;
			++index;
		}
	}

	bool check(vector<int>& count, vector<int>& target) {
		for (int i = 31; i >= 0; --i) {
			if (count[i] == 0 && target[i] != 0) {
				return false;
			}

			if (count[i] != 0 && target[i] == 0) {
				return true;
			}
		}

		return true;
	}

	void slide(vector<int>& count, int num, int change) {
		int index = 0;

		while (num != 0) {
			if ((num & 1) != 0) {
				count[index] += change;
			}

			num >>= 1;
			++index;
		}
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,3 };
	check.checkInt(1, o.minimumSubarrayLength(nums, 2));

	nums = { 2,1,8 };
	check.checkInt(3, o.minimumSubarrayLength(nums, 10));

	nums = { 1,2 };
	check.checkInt(1, o.minimumSubarrayLength(nums, 0));

	nums = { 1 };
	check.checkInt(-1, o.minimumSubarrayLength(nums, 2));

	nums = { 41 };
	check.checkInt(1, o.minimumSubarrayLength(nums, 3));
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
