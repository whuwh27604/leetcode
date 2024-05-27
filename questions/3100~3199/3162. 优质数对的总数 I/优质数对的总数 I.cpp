/* 优质数对的总数 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数数组 nums1 和 nums2，长度分别为 n 和 m。同时给你一个正整数 k。

如果 nums1[i] 可以被 nums2[j] * k 整除，则称数对 (i, j) 为 优质数对（0 <= i <= n - 1, 0 <= j <= m - 1）。

返回 优质数对 的总数。



示例 1：

输入：nums1 = [1,3,4], nums2 = [1,3,4], k = 1

输出：5

解释：

5个优质数对分别是 (0, 0), (1, 0), (1, 1), (2, 0), 和 (2, 2)。

示例 2：

输入：nums1 = [1,2,4,12], nums2 = [2,4], k = 3

输出：2

解释：

2个优质数对分别是 (3, 0) 和 (3, 1)。



提示：

1 <= n, m <= 50
1 <= nums1[i], nums2[j] <= 50
1 <= k <= 50
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		int pairs = 0;

		for (int n2 : nums2) {
			n2 *= k;

			for (int n1 : nums1) {
				if (n1 % n2 == 0) {
					++pairs;
				}
			}
		}

		return pairs;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums1 = { 1,3,4 };
	vector<int> nums2 = { 1,3,4 };
	check.checkInt(5, o.numberOfPairs(nums1, nums2, 1));

	nums1 = { 1,2,4,12 };
	nums2 = { 2,4 };
	check.checkInt(2, o.numberOfPairs(nums1, nums2, 3));
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
