/* 相同分数的最大操作数目 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，如果 nums 至少 包含 2 个元素，你可以执行以下操作：

选择 nums 中的前两个元素并将它们删除。
一次操作的 分数 是被删除元素的和。

在确保 所有操作分数相同 的前提下，请你求出 最多 能进行多少次操作。

请你返回按照上述要求 最多 可以进行的操作次数。



示例 1：

输入：nums = [3,2,1,4,5]
输出：2
解释：我们执行以下操作：
- 删除前两个元素，分数为 3 + 2 = 5 ，nums = [1,4,5] 。
- 删除前两个元素，分数为 1 + 4 = 5 ，nums = [5] 。
由于只剩下 1 个元素，我们无法继续进行任何操作。
示例 2：

输入：nums = [3,2,6,1,4]
输出：1
解释：我们执行以下操作：
- 删除前两个元素，分数为 3 + 2 = 5 ，nums = [6,1,4] 。
由于下一次操作的分数与前一次不相等，我们无法继续进行任何操作。


提示：

2 <= nums.length <= 100
1 <= nums[i] <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
		int size = nums.size(), target = nums[0] + nums[1], opers = 1;

		for (int i = 3; i < size && nums[i - 1] + nums[i] == target; i += 2) {
			++opers;
		}

		return opers;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 3,2,1,4,5 };
	check.checkInt(2, o.maxOperations(nums));

	nums = { 3,2,6,1,4 };
	check.checkInt(1, o.maxOperations(nums));

	nums = { 3,2 };
	check.checkInt(1, o.maxOperations(nums));

	nums = { 3,2,4,1,4,1 };
	check.checkInt(3, o.maxOperations(nums));
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
