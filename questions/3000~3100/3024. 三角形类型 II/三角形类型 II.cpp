/* 三角形类型 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始长度为 3 的整数数组 nums ，需要用它们来构造三角形。

如果一个三角形的所有边长度相等，那么这个三角形称为 equilateral 。
如果一个三角形恰好有两条边长度相等，那么这个三角形称为 isosceles 。
如果一个三角形三条边的长度互不相同，那么这个三角形称为 scalene 。
如果这个数组无法构成一个三角形，请你返回字符串 "none" ，否则返回一个字符串表示这个三角形的类型。



示例 1：

输入：nums = [3,3,3]
输出："equilateral"
解释：由于三条边长度相等，所以可以构成一个等边三角形，返回 "equilateral" 。
示例 2：

输入：nums = [3,4,5]
输出："scalene"
解释：
nums[0] + nums[1] = 3 + 4 = 7 ，大于 nums[2] = 5 。
nums[0] + nums[2] = 3 + 5 = 8 ，大于 nums[1] = 4 。
nums[1] + nums[2] = 4 + 5 = 9 ，大于 nums[0] = 3 。
由于任意两边纸盒都大于第三边，所以可以构成一个三角形。
因为三条边的长度互不相等，所以返回 "scalene" 。


提示：

nums.length == 3
1 <= nums[i] <= 100
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int a = nums[0], b = nums[1], c = nums[2];
		if (a + b <= c) {
			return "none";
		}

		if (a == c) {
			return "equilateral";
		}

		if (a == b || b == c) {
			return "isosceles";
		}

		return "scalene";
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 3,3,3 };
	check.checkString("equilateral", o.triangleType(nums));

	nums = { 3,4,5 };
	check.checkString("scalene", o.triangleType(nums));

	nums = { 3,3,5 };
	check.checkString("isosceles", o.triangleType(nums));

	nums = { 3,4,8 };
	check.checkString("none", o.triangleType(nums));
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
