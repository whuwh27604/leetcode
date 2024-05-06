/* 找出与数组相加的整数 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数数组 nums1 和 nums2。

从 nums1 中移除两个元素，并且所有其他元素都与变量 x 所表示的整数相加。如果 x 为负数，则表现为元素值的减少。

执行上述操作后，nums1 和 nums2 相等 。当两个数组中包含相同的整数，并且这些整数出现的频次相同时，两个数组 相等 。

返回能够实现数组相等的 最小 整数 x 。



示例 1:

输入：nums1 = [4,20,16,12,8], nums2 = [14,18,10]

输出：-2

解释：

移除 nums1 中下标为 [0,4] 的两个元素，并且每个元素与 -2 相加后，nums1 变为 [18,14,10] ，与 nums2 相等。

示例 2:

输入：nums1 = [3,5,5,3], nums2 = [7,7]

输出：2

解释：

移除 nums1 中下标为 [0,3] 的两个元素，并且每个元素与 2 相加后，nums1 变为 [7,7] ，与 nums2 相等。



提示：

3 <= nums1.length <= 200
nums2.length == nums1.length - 2
0 <= nums1[i], nums2[i] <= 1000
测试用例以这样的方式生成：存在一个整数 x，nums1 中的每个元素都与 x 相加后，再移除两个元素，nums1 可以与 nums2 相等。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
		int minAdd = INT_MAX;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		for (int i = 0; i < 3; ++i) {
			int diff = nums2[0] - nums1[i];
			if (isSubseq(nums1, nums2, diff)) {
				minAdd = min(minAdd, diff);
			}
		}

		return minAdd;
    }

	bool isSubseq(vector<int>& nums1, vector<int>& nums2, int diff) {
		int size = (int)nums1.size(), i = 0;

		for (int num : nums2) {
			while (i < size && num - nums1[i] != diff) {
				++i;
			}

			if (i == size) {
				return false;
			}

			++i;
		}

		return true;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums1 = { 4,20,16,12,8 };
	vector<int> nums2 = { 14,18,10 };
	check.checkInt(-2, o.minimumAddedInteger(nums1, nums2));

	nums1 = { 3,5,5,3 };
	nums2 = { 7,7 };
	check.checkInt(2, o.minimumAddedInteger(nums1, nums2));

	nums1 = { 3,5,10,9,9,4 };
	nums2 = { 1,6,6,0 };
	check.checkInt(-3, o.minimumAddedInteger(nums1, nums2));
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
