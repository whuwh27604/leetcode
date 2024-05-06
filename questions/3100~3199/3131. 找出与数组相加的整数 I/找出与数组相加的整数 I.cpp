/* 找出与数组相加的整数 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度相等的数组 nums1 和 nums2。

数组 nums1 中的每个元素都与变量 x 所表示的整数相加。如果 x 为负数，则表现为元素值的减少。

在与 x 相加后，nums1 和 nums2 相等 。当两个数组中包含相同的整数，并且这些整数出现的频次相同时，两个数组 相等 。

返回整数 x 。



示例 1:

输入：nums1 = [2,6,4], nums2 = [9,7,5]

输出：3

解释：

与 3 相加后，nums1 和 nums2 相等。

示例 2:

输入：nums1 = [10], nums2 = [5]

输出：-5

解释：

与 -5 相加后，nums1 和 nums2 相等。

示例 3:

输入：nums1 = [1,1,1,1], nums2 = [1,1,1,1]

输出：0

解释：

与 0 相加后，nums1 和 nums2 相等。



提示：

1 <= nums1.length == nums2.length <= 100
0 <= nums1[i], nums2[i] <= 1000
测试用例以这样的方式生成：存在一个整数 x，使得 nums1 中的每个元素都与 x 相加后，nums1 与 nums2 相等。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
		return *min_element(nums2.begin(), nums2.end()) - *min_element(nums1.begin(), nums1.end());
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums1 = { 2,6,4 };
	vector<int> nums2 = { 9,7,5 };
	check.checkInt(3, o.addedInteger(nums1, nums2));

	nums1 = { 10 };
	nums2 = { 5 };
	check.checkInt(-5, o.addedInteger(nums1, nums2));

	nums1 = { 1,1,1,1 };
	nums2 = { 1,1,1,1 };
	check.checkInt(0, o.addedInteger(nums1, nums2));
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
