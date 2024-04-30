/* 找出唯一性数组的中位数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。数组 nums 的 唯一性数组 是一个按元素从小到大排序的数组，包含了 nums 的所有
非空子数组中
不同元素的个数。

换句话说，这是由所有 0 <= i <= j < nums.length 的 distinct(nums[i..j]) 组成的递增数组。

其中，distinct(nums[i..j]) 表示从下标 i 到下标 j 的子数组中不同元素的数量。

返回 nums 唯一性数组 的 中位数 。

注意，数组的 中位数 定义为有序数组的中间元素。如果有两个中间元素，则取值较小的那个。



示例 1：

输入：nums = [1,2,3]

输出：1

解释：

nums 的唯一性数组为 [distinct(nums[0..0]), distinct(nums[1..1]), distinct(nums[2..2]), distinct(nums[0..1]), distinct(nums[1..2]), distinct(nums[0..2])]，即 [1, 1, 1, 2, 2, 3] 。唯一性数组的中位数为 1 ，因此答案是 1 。

示例 2：

输入：nums = [3,4,3,4,5]

输出：2

解释：

nums 的唯一性数组为 [1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3] 。唯一性数组的中位数为 2 ，因此答案是 2 。

示例 3：

输入：nums = [4,3,5,4]

输出：2

解释：

nums 的唯一性数组为 [1, 1, 1, 1, 2, 2, 2, 3, 3, 3] 。唯一性数组的中位数为 2 ，因此答案是 2 。



提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
		int size = (int)nums.size(), low = 1, high = size, ans = 0;
		long long total = ((long long)size + 1) * size / 2, half = (total + 1) / 2;

		while (low <= high) {
			int mid = (low + high) / 2;
			if (check(nums, size, mid, half)) {
				ans = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}

		return ans;
    }

	bool check(vector<int>& nums, int size, int most, long long target) {
		int left = 0;
		long long subs = 0;
		unordered_map<int, int> numsCount;

		for (int right = 0; right < size; ++right) {
			int num = nums[right];
			++numsCount[num];

			while (numsCount.size() > most) {
				num = nums[left++];
				if (--numsCount[num] == 0) {
					numsCount.erase(num);
				}
			}

			subs += ((long long)right - left + 1);
			if (subs >= target) {
				return true;
			}
		}

		return false;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,3 };
	check.checkInt(1, o.medianOfUniquenessArray(nums));

	nums = { 3,4,3,4,5 };
	check.checkInt(2, o.medianOfUniquenessArray(nums));

	nums = { 4,3,5,4 };
	check.checkInt(2, o.medianOfUniquenessArray(nums));
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
