/* 检查按位或是否存在尾随零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 正整数 数组 nums 。

你需要检查是否可以从数组中选出 两个或更多 元素，满足这些元素的按位或运算（ OR）结果的二进制表示中 至少 存在一个尾随零。

例如，数字 5 的二进制表示是 "101"，不存在尾随零，而数字 4 的二进制表示是 "100"，存在两个尾随零。

如果可以选择两个或更多元素，其按位或运算结果存在尾随零，返回 true；否则，返回 false 。



示例 1：

输入：nums = [1,2,3,4,5]
输出：true
解释：如果选择元素 2 和 4，按位或运算结果是 6，二进制表示为 "110" ，存在一个尾随零。
示例 2：

输入：nums = [2,4,8,16]
输出：true
解释：如果选择元素 2 和 4，按位或运算结果是 6，二进制表示为 "110"，存在一个尾随零。
其他按位或运算结果存在尾随零的可能选择方案包括：(2, 8), (2, 16), (4, 8), (4, 16), (8, 16), (2, 4, 8), (2, 4, 16), (2, 8, 16), (4, 8, 16), 以及 (2, 4, 8, 16) 。
示例 3：

输入：nums = [1,3,5,7,9]
输出：false
解释：不存在按位或运算结果存在尾随零的选择方案。


提示：

2 <= nums.length <= 100
1 <= nums[i] <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
		bool exist = false;

		for (int num : nums) {
			if ((num & 1) == 0) {
				if (exist) {
					return true;
				}

				exist = true;
			}
		}

		return false;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,3,4,5 };
	check.checkBool(true, o.hasTrailingZeros(nums));

	nums = { 2,4,8,16 };
	check.checkBool(true, o.hasTrailingZeros(nums));

	nums = { 1,3,5,7,9 };
	check.checkBool(false, o.hasTrailingZeros(nums));
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
