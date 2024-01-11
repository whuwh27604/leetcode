/* 大于等于顺序前缀和的最小缺失整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。

如果一个前缀 nums[0..i] 满足对于 1 <= j <= i 的所有元素都有 nums[j] = nums[j - 1] + 1 ，那么我们称这个前缀是一个 顺序前缀 。特殊情况是，只包含 nums[0] 的前缀也是一个 顺序前缀 。

请你返回 nums 中没有出现过的 最小 整数 x ，满足 x 大于等于 最长 顺序前缀的和。



示例 1：

输入：nums = [1,2,3,2,5]
输出：6
解释：nums 的最长顺序前缀是 [1,2,3] ，和为 6 ，6 不在数组中，所以 6 是大于等于最长顺序前缀和的最小整数。
示例 2：

输入：nums = [3,4,5,1,12,14,13]
输出：15
解释：nums 的最长顺序前缀是 [3,4,5] ，和为 12 ，12、13 和 14 都在数组中，但 15 不在，所以 15 是大于等于最长顺序前缀和的最小整数。


提示：

1 <= nums.length <= 50
1 <= nums[i] <= 50
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
		vector<bool> exist(1300, false);
		int sum = 0, prev = nums[0] - 1;

		for (int num : nums) {
			exist[num] = true;

			if (num == prev + 1) {
				sum += num;
				prev = num;
			}
			else {
				prev = -1;
			}
		}

		while (exist[sum]) {
			++sum;
		}

		return sum;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,3,2,5 };
	check.checkInt(6, o.missingInteger(nums));

	nums = { 3,4,5,1,12,14,13 };
	check.checkInt(15, o.missingInteger(nums));
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
