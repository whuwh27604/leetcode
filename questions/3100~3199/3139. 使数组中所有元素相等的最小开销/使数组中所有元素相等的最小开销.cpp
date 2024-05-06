/* 使数组中所有元素相等的最小开销.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和两个整数 cost1 和 cost2 。你可以执行以下 任一 操作 任意 次：

从 nums 中选择下标 i 并且将 nums[i] 增加 1 ，开销为 cost1。
选择 nums 中两个 不同 下标 i 和 j ，并且将 nums[1] 和 nums[2] 都 增加 1 ，开销为 cost2 。
你的目标是使数组中所有元素都 相等 ，请你返回需要的 最小开销 之和。

由于答案可能会很大，请你将它对 109 + 7 取余 后返回。



示例 1：

输入：nums = [4,1], cost1 = 5, cost2 = 2

输出：15

解释：

执行以下操作可以使数组中所有元素相等：

将 nums[1] 增加 1 ，开销为 5 ，nums 变为 [4,2] 。
将 nums[1] 增加 1 ，开销为 5 ，nums 变为 [4,3] 。
将 nums[1] 增加 1 ，开销为 5 ，nums 变为 [4,4] 。
总开销为 15 。

示例 2：

输入：nums = [2,3,3,3,5], cost1 = 2, cost2 = 1

输出：6

解释：

执行以下操作可以使数组中所有元素相等：

将 nums[0] 和 nums[1] 同时增加 1 ，开销为 1 ，nums 变为 [3,4,3,3,5] 。
将 nums[0] 和 nums[2] 同时增加 1 ，开销为 1 ，nums 变为 [4,4,4,3,5] 。
将 nums[0] 和 nums[3] 同时增加 1 ，开销为 1 ，nums 变为 [5,4,4,4,5] 。
将 nums[1] 和 nums[2] 同时增加 1 ，开销为 1 ，nums 变为 [5,5,5,4,5] 。
将 nums[3] 增加 1 ，开销为 2 ，nums 变为 [5,5,5,5,5] 。
总开销为 6 。

示例 3：

输入：nums = [3,5,3], cost1 = 1, cost2 = 3

输出：4

解释：

执行以下操作可以使数组中所有元素相等：

将 nums[0] 增加 1 ，开销为 1 ，nums 变为 [4,5,3] 。
将 nums[0] 增加 1 ，开销为 1 ，nums 变为 [5,5,3] 。
将 nums[2] 增加 1 ，开销为 1 ，nums 变为 [5,5,4] 。
将 nums[2] 增加 1 ，开销为 1 ，nums 变为 [5,5,5] 。
总开销为 4 。



提示：

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= cost1 <= 106
1 <= cost2 <= 106
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
		int n = (int)nums.size(), mod = 1000000007;

		if (n == 1) {  // 一个数，不用任何操作
			return 0;
		}

		if (n == 2) {  // 两个数，把小的变为大的是最小开销
			return (long long)abs(nums[0] - nums[1]) * cost1 % mod;
		}

		int maxNum = 0, minNum = INT_MAX;
		long long sum = 0;

		for (int num : nums) {
			sum += num;
			minNum = min(minNum, num);
			maxNum = max(maxNum, num);
		}

		if (cost2 >= cost1 * 2) {  // 操作2没有意义，全部执行操作1
			return ((long long)maxNum * n - sum) * cost1 % mod;
		}

		long long minCost = LLONG_MAX;
		long long maxTarget = max((long long)maxNum, (sum - 2 * minNum) / (n - 2) + 1) + 1;  // 超过maxTarget以后，一定是全部执行操作2到最多剩一个数

		for (long long target = maxNum; target <= maxTarget; ++target) {
			long long totalDist = target * n - sum;
			long long maxDist = target - minNum;
			long long otherDist = totalDist - maxDist;

			if (otherDist >= maxDist) {  // 可以执行所有的操作2，最多执行一个操作1
				long long cost = totalDist / 2 * cost2;
				if ((totalDist & 1) == 1) {
					cost += cost1;
				}
				minCost = min(minCost, cost);
			}
			else {  // maxDist里面会剩下一部分只能执行操作1
				minCost = min(minCost, otherDist * cost2 + (maxDist - otherDist) * cost1);
			}
		}

		return minCost % mod;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 4,1 };
	check.checkInt(15, o.minCostToEqualizeArray(nums, 5, 2));

	nums = { 2,3,3,3,5 };
	check.checkInt(6, o.minCostToEqualizeArray(nums, 2, 1));

	nums = { 3,5,3 };
	check.checkInt(4, o.minCostToEqualizeArray(nums, 1, 3));

	nums = { 1,3,4,4 };
	check.checkInt(4, o.minCostToEqualizeArray(nums, 10, 1));

	nums = { 43,46,1,1 };
	check.checkInt(271, o.minCostToEqualizeArray(nums, 41, 5));

	nums = { 60,19,53,31,57 };
	check.checkInt(90, o.minCostToEqualizeArray(nums, 60, 2));

	nums = { 1,1000000 };
	check.checkInt(998993007, o.minCostToEqualizeArray(nums, 1000000, 1));
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
