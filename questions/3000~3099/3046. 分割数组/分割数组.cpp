/* 分割数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 偶数 的整数数组 nums 。你需要将这个数组分割成 nums1 和 nums2 两部分，要求：

nums1.length == nums2.length == nums.length / 2 。
nums1 应包含 互不相同 的元素。
nums2也应包含 互不相同 的元素。
如果能够分割数组就返回 true ，否则返回 false 。



示例 1：

输入：nums = [1,1,2,2,3,4]
输出：true
解释：分割 nums 的可行方案之一是 nums1 = [1,2,3] 和 nums2 = [1,2,4] 。
示例 2：

输入：nums = [1,1,1,1]
输出：false
解释：分割 nums 的唯一可行方案是 nums1 = [1,1] 和 nums2 = [1,1] 。但 nums1 和 nums2 都不是由互不相同的元素构成。因此，返回 false 。


提示：

1 <= nums.length <= 100
nums.length % 2 == 0
1 <= nums[i] <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
		vector<int> count(101, 0);

		for (int num : nums) {
			if (++count[num] > 2) {
				return false;
			}
		}

		return true;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,1,2,2,3,4 };
	check.checkBool(true, o.isPossibleToSplit(nums));

	nums = { 1,1,1,1 };
	check.checkBool(false, o.isPossibleToSplit(nums));
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
