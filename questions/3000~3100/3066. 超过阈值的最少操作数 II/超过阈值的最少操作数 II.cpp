/* 超过阈值的最少操作数 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

一次操作中，你将执行：

选择 nums 中最小的两个整数 x 和 y 。
将 x 和 y 从 nums 中删除。
将 min(x, y) * 2 + max(x, y) 添加到数组中的任意位置。
注意，只有当 nums 至少包含两个元素时，你才可以执行以上操作。

你需要使数组中的所有元素都大于或等于 k ，请你返回需要的 最少 操作次数。



示例 1：

输入：nums = [2,11,10,1,3], k = 10
输出：2
解释：第一次操作中，我们删除元素 1 和 2 ，然后添加 1 * 2 + 2 到 nums 中，nums 变为 [4, 11, 10, 3] 。
第二次操作中，我们删除元素 3 和 4 ，然后添加 3 * 2 + 4 到 nums 中，nums 变为 [10, 11, 10] 。
此时，数组中的所有元素都大于等于 10 ，所以我们停止操作。
使数组中所有元素都大于等于 10 需要的最少操作次数为 2 。
示例 2：

输入：nums = [1,1,2,4,9], k = 20
输出：4
解释：第一次操作后，nums 变为 [2, 4, 9, 3] 。
第二次操作后，nums 变为 [7, 4, 9] 。
第三次操作后，nums 变为 [15, 9] 。
第四次操作后，nums 变为 [33] 。
此时，数组中的所有元素都大于等于 20 ，所以我们停止操作。
使数组中所有元素都大于等于 20 需要的最少操作次数为 4 。


提示：

2 <= nums.length <= 2 * 105
1 <= nums[i] <= 109
1 <= k <= 109
输入保证答案一定存在，也就是说一定存在一个操作序列使数组中所有元素都大于等于 k 。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
		priority_queue<long long, vector<long long>, greater<long long>> nodes;
		int opers = 0;

		for (int num : nums) {
			nodes.push(num);
		}

		while (nodes.size() > 1) {
			long long x = nodes.top();
			if (x >= k) {
				break;
			}

			nodes.pop();
			long long y = nodes.top();
			nodes.pop();
			nodes.push(min(x, y) * 2 + max(x, y));
			++opers;
		}

		return opers;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 2,11,10,1,3 };
	check.checkInt(2, o.minOperations(nums, 10));

	nums = { 1,1,2,4,9 };
	check.checkInt(4, o.minOperations(nums, 20));
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
