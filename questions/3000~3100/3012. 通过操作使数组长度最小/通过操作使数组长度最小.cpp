/* 通过操作使数组长度最小.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，它只包含 正 整数。

你的任务是通过进行以下操作 任意次 （可以是 0 次） 最小化 nums 的长度：

在 nums 中选择 两个不同 的下标 i 和 j ，满足 nums[i] > 0 且 nums[j] > 0 。
将结果 nums[i] % nums[j] 插入 nums 的结尾。
将 nums 中下标为 i 和 j 的元素删除。
请你返回一个整数，它表示进行任意次操作以后 nums 的 最小长度 。



示例 1：

输入：nums = [1,4,3,1]
输出：1
解释：使数组长度最小的一种方法是：
操作 1 ：选择下标 2 和 1 ，插入 nums[2] % nums[1] 到数组末尾，得到 [1,4,3,1,3] ，然后删除下标为 2 和 1 的元素。
nums 变为 [1,1,3] 。
操作 2 ：选择下标 1 和 2 ，插入 nums[1] % nums[2] 到数组末尾，得到 [1,1,3,1] ，然后删除下标为 1 和 2 的元素。
nums 变为 [1,1] 。
操作 3 ：选择下标 1 和 0 ，插入 nums[1] % nums[0] 到数组末尾，得到 [1,1,0] ，然后删除下标为 1 和 0 的元素。
nums 变为 [0] 。
nums 的长度无法进一步减小，所以答案为 1 。
1 是可以得到的最小长度。
示例 2：

输入：nums = [5,5,5,10,5]
输出：2
解释：使数组长度最小的一种方法是：
操作 1 ：选择下标 0 和 3 ，插入 nums[0] % nums[3] 到数组末尾，得到 [5,5,5,10,5,5] ，然后删除下标为 0 和 3 的元素。
nums 变为 [5,5,5,5] 。
操作 2 ：选择下标 2 和 3 ，插入 nums[2] % nums[3] 到数组末尾，得到 [5,5,5,5,0] ，然后删除下标为 2 和 3 的元素。
nums 变为 [5,5,0] 。
操作 3 ：选择下标 0 和 1 ，插入 nums[0] % nums[1] 到数组末尾，得到 [5,5,0,0] ，然后删除下标为 0 和 1 的元素。
nums 变为 [0,0] 。
nums 的长度无法进一步减小，所以答案为 2 。
2 是可以得到的最小长度。
示例 3：

输入：nums = [2,3,4]
输出：1
解释：使数组长度最小的一种方法是：
操作 1 ：选择下标 1 和 2 ，插入 nums[1] % nums[2] 到数组末尾，得到 [2,3,4,3] ，然后删除下标为 1 和 2 的元素。
nums 变为 [2,3] 。
操作 2 ：选择下标 1 和 0 ，插入 nums[1] % nums[0] 到数组末尾，得到 [2,3,1] ，然后删除下标为 1 和 0 的元素。
nums 变为 [1] 。
nums 的长度无法进一步减小，所以答案为 1 。
1 是可以得到的最小长度。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
		int minNum = *min_element(nums.begin(), nums.end());
		int count = 1;

		for (int num : nums) {
			if (num % minNum != 0) {
				return 1;  // minNum是原数组的最小值，取余k不为0的情况下，k将比minNum更小，用k可以消除所有数
			}

			if (num == minNum) {
				++count;  // 不能产生比minNum更小的数，那么所有的minNum将会剩下，两两操作后剩下一半
			}
		}

		return count / 2;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,4,3,1 };
	check.checkInt(1, o.minimumArrayLength(nums));

	nums = { 5,5,5,10,5 };
	check.checkInt(2, o.minimumArrayLength(nums));

	nums = { 2,3,4 };
	check.checkInt(1, o.minimumArrayLength(nums));

	nums = { 2,2,2,2,2 };
	check.checkInt(3, o.minimumArrayLength(nums));
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
