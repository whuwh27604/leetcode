/* 边界上的蚂蚁.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
边界上有一只蚂蚁，它有时向 左 走，有时向 右 走。

给你一个 非零 整数数组 nums 。蚂蚁会按顺序读取 nums 中的元素，从第一个元素开始直到结束。每一步，蚂蚁会根据当前元素的值移动：

如果 nums[i] < 0 ，向 左 移动 -nums[i]单位。
如果 nums[i] > 0 ，向 右 移动 nums[i]单位。
返回蚂蚁 返回 到边界上的次数。

注意：

边界两侧有无限的空间。
只有在蚂蚁移动了 |nums[i]| 单位后才检查它是否位于边界上。换句话说，如果蚂蚁只是在移动过程中穿过了边界，则不会计算在内。


示例 1：

输入：nums = [2,3,-5]
输出：1
解释：第 1 步后，蚂蚁距边界右侧 2 单位远。
第 2 步后，蚂蚁距边界右侧 5 单位远。
第 3 步后，蚂蚁位于边界上。
所以答案是 1 。
示例 2：

输入：nums = [3,2,-3,-4]
输出：0
解释：第 1 步后，蚂蚁距边界右侧 3 单位远。
第 2 步后，蚂蚁距边界右侧 5 单位远。
第 3 步后，蚂蚁距边界右侧 2 单位远。
第 4 步后，蚂蚁距边界左侧 2 单位远。
蚂蚁从未返回到边界上，所以答案是 0 。


提示：

1 <= nums.length <= 100
-10 <= nums[i] <= 10
nums[i] != 0
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
		int sum = 0, count = 0;

		for (int num : nums) {
			sum += num;

			if (sum == 0) {
				++count;
			}
		}

		return count;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 2,3,-5 };
	check.checkInt(1, o.returnToBoundaryCount(nums));

	nums = { 3,2,-3,-4 };
	check.checkInt(0, o.returnToBoundaryCount(nums));
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
