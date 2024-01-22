/* 将数组分成最小总代价的子数组 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums 。

一个数组的 代价 是它的 第一个 元素。比方说，[1,2,3] 的代价是 1 ，[3,4,1] 的代价是 3 。

你需要将 nums 分成 3 个 连续且没有交集 的子数组。

请你返回这些子数组的 最小 代价 总和 。



示例 1：

输入：nums = [1,2,3,12]
输出：6
解释：最佳分割成 3 个子数组的方案是：[1] ，[2] 和 [3,12] ，总代价为 1 + 2 + 3 = 6 。
其他得到 3 个子数组的方案是：
- [1] ，[2,3] 和 [12] ，总代价是 1 + 2 + 12 = 15 。
- [1,2] ，[3] 和 [12] ，总代价是 1 + 3 + 12 = 16 。
示例 2：

输入：nums = [5,4,3]
输出：12
解释：最佳分割成 3 个子数组的方案是：[5] ，[4] 和 [3] ，总代价为 5 + 4 + 3 = 12 。
12 是所有分割方案里的最小总代价。
示例 3：

输入：nums = [10,3,1,1]
输出：12
解释：最佳分割成 3 个子数组的方案是：[10,3] ，[1] 和 [1] ，总代价为 10 + 1 + 1 = 12 。
12 是所有分割方案里的最小总代价。


提示：

3 <= n <= 50
1 <= nums[i] <= 50
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
		int n = nums.size(), minCost = INT_MAX;

		for (int i = 1; i < n - 1; ++i) {
			for (int j = i + 1; j < n; ++j) {
				minCost = min(minCost, nums[0] + nums[i] + nums[j]);
			}
		}

		return minCost;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,3,12 };
	check.checkInt(6, o.minimumCost(nums));

	nums = { 5,4,3 };
	check.checkInt(12, o.minimumCost(nums));

	nums = { 10,3,1,1 };
	check.checkInt(12, o.minimumCost(nums));
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
