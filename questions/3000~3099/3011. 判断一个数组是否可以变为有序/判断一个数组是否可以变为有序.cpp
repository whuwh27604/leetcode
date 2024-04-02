/* 判断一个数组是否可以变为有序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始且全是 正 整数的数组 nums 。

一次 操作 中，如果两个 相邻 元素在二进制下数位为 1 的数目 相同 ，那么你可以将这两个元素交换。你可以执行这个操作 任意次 （也可以 0 次）。

如果你可以使数组变有序，请你返回 true ，否则返回 false 。



示例 1：

输入：nums = [8,4,2,30,15]
输出：true
解释：我们先观察每个元素的二进制表示。 2 ，4 和 8 分别都只有一个数位为 1 ，分别为 "10" ，"100" 和 "1000" 。15 和 30 分别有 4 个数位为 1 ："1111" 和 "11110" 。
我们可以通过 4 个操作使数组有序：
- 交换 nums[0] 和 nums[1] 。8 和 4 分别只有 1 个数位为 1 。数组变为 [4,8,2,30,15] 。
- 交换 nums[1] 和 nums[2] 。8 和 2 分别只有 1 个数位为 1 。数组变为 [4,2,8,30,15] 。
- 交换 nums[0] 和 nums[1] 。4 和 2 分别只有 1 个数位为 1 。数组变为 [2,4,8,30,15] 。
- 交换 nums[3] 和 nums[4] 。30 和 15 分别有 4 个数位为 1 ，数组变为 [2,4,8,15,30] 。
数组变成有序的，所以我们返回 true 。
注意我们还可以通过其他的操作序列使数组变得有序。
示例 2：

输入：nums = [1,2,3,4,5]
输出：true
解释：数组已经是有序的，所以我们返回 true 。
示例 3：

输入：nums = [3,16,8,4,2]
输出：false
解释：无法通过操作使数组变为有序。


提示：

1 <= nums.length <= 100
1 <= nums[i] <= 28
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
		int prevOnes = 0, prevNum = 0, curOnes = 0, curNum = 0;

		for (int num : nums) {
			int ones = popcount(num);
			if (ones == curOnes) {
				curNum = max(curNum, num);
			}
			else {
				prevOnes = curOnes;
				prevNum = curNum;
				curOnes = ones;
				curNum = num;
			}

			if (num < prevNum) {
				return false;
			}
		}

		return true;
    }

	int popcount(int num) {
		int count = 0;

		while (num != 0) {
			num &= (num - 1);
			++count;
		}

		return count;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 8,4,2,30,15 };
	check.checkBool(true, o.canSortArray(nums));

	nums = { 1,2,3,4,5 };
	check.checkBool(true, o.canSortArray(nums));

	nums = { 3,16,8,4,2 };
	check.checkBool(false, o.canSortArray(nums));

	nums = { 20,16 };
	check.checkBool(false, o.canSortArray(nums));
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
