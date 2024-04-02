/* 移除后集合的最多元素数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，它们的长度都是偶数 n 。

你必须从 nums1 中移除 n / 2 个元素，同时从 nums2 中也移除 n / 2 个元素。移除之后，你将 nums1 和 nums2 中剩下的元素插入到集合 s 中。

返回集合 s可能的 最多 包含多少元素。



示例 1：

输入：nums1 = [1,2,1,2], nums2 = [1,1,1,1]
输出：2
解释：从 nums1 和 nums2 中移除两个 1 。移除后，数组变为 nums1 = [2,2] 和 nums2 = [1,1] 。因此，s = {1,2} 。
可以证明，在移除之后，集合 s 最多可以包含 2 个元素。
示例 2：

输入：nums1 = [1,2,3,4,5,6], nums2 = [2,3,2,3,2,3]
输出：5
解释：从 nums1 中移除 2、3 和 6 ，同时从 nums2 中移除两个 3 和一个 2 。移除后，数组变为 nums1 = [1,4,5] 和 nums2 = [2,3,2] 。因此，s = {1,2,3,4,5} 。
可以证明，在移除之后，集合 s 最多可以包含 5 个元素。
示例 3：

输入：nums1 = [1,1,2,2,3,3], nums2 = [4,4,5,5,6,6]
输出：6
解释：从 nums1 中移除 1、2 和 3 ，同时从 nums2 中移除 4、5 和 6 。移除后，数组变为 nums1 = [1,2,3] 和 nums2 = [4,5,6] 。因此，s = {1,2,3,4,5,6} 。
可以证明，在移除之后，集合 s 最多可以包含 6 个元素。


提示：

n == nums1.length == nums2.length
1 <= n <= 2 * 104
n是偶数。
1 <= nums1[i], nums2[i] <= 109
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> n1, n2, common;  // 将所有数划分为n1独有、n2独有、两数组共有的

		for (int num : nums1) {
			n1.insert(num);
		}

		for (int num : nums2) {
			if (common.count(num) == 0) {
				if (n1.count(num) == 0) {
					n2.insert(num);
				}
				else {
					n1.erase(num);
					common.insert(num);
				}
			}
		}

		int size1 = n1.size(), size2 = n2.size(), size3 = common.size();
		int n = nums1.size(), half = n / 2;
		int size = min(size1, half) + min(size2, half);  // 从n1里面最多取half个，n2里面最多取half个

		return min(size + size3, n);  // 如果还不够，从common里面取数填充，最多n个
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums1 = { 1,2,1,2 };
	vector<int> nums2 = { 1,1,1,1 };
	check.checkInt(2, o.maximumSetSize(nums1, nums2));

	nums1 = { 1,2,3,4,5,6 };
	nums2 = { 2,3,2,3,2,3 };
	check.checkInt(5, o.maximumSetSize(nums1, nums2));

	nums1 = { 1,1,2,2,3,3 };
	nums2 = { 4,4,5,5,6,6 };
	check.checkInt(6, o.maximumSetSize(nums1, nums2));
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
