/* 超过阈值的最少操作数 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

一次操作中，你可以删除 nums 中的最小元素。

你需要使数组中的所有元素都大于或等于 k ，请你返回需要的 最少 操作次数。



示例 1：

输入：nums = [2,11,10,1,3], k = 10
输出：3
解释：第一次操作后，nums 变为 [2, 11, 10, 3] 。
第二次操作后，nums 变为 [11, 10, 3] 。
第三次操作后，nums 变为 [11, 10] 。
此时，数组中的所有元素都大于等于 10 ，所以我们停止操作。
使数组中所有元素都大于等于 10 需要的最少操作次数为 3 。
示例 2：

输入：nums = [1,1,2,4,9], k = 1
输出：0
解释：数组中的所有元素都大于等于 1 ，所以不需要对 nums 做任何操作。
示例 3：

输入：nums = [1,1,2,4,9], k = 9
输出：4
解释：nums 中只有一个元素大于等于 9 ，所以需要执行 4 次操作。


提示：

1 <= nums.length <= 50
1 <= nums[i] <= 109
1 <= k <= 109
输入保证至少有一个满足 nums[i] >= k 的下标 i 存在。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
		int opers = 0;

		for (int num : nums) {
			if (num < k) {
				++opers;
			}
		}

		return opers;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 2,11,10,1,3 };
	check.checkInt(3, o.minOperations(nums, 10));

	nums = { 1,1,2,4,9 };
	check.checkInt(0, o.minOperations(nums, 1));

	nums = { 1,1,2,4,9 };
	check.checkInt(4, o.minOperations(nums, 9));
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
