/* 交替子数组计数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个
二进制数组
nums 。

如果一个
子数组
中 不存在 两个 相邻 元素的值 相同 的情况，我们称这样的子数组为 交替子数组 。

返回数组 nums 中交替子数组的数量。



示例 1：

输入： nums = [0,1,1,1]

输出： 5

解释：

以下子数组是交替子数组：[0] 、[1] 、[1] 、[1] 以及 [0,1] 。

示例 2：

输入： nums = [1,0,1,0]

输出： 10

解释：

数组的每个子数组都是交替子数组。可以统计在内的子数组共有 10 个。



提示：

1 <= nums.length <= 105
nums[i] 不是 0 就是 1 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
		long long subs = 0;
		int i = 0, size = nums.size();

		while (i < size) {
			int j = i + 1;

			while (j < size && nums[j] != nums[j - 1]) {
				++j;
			}

			int len = j - i;
			subs += ((long long)len + 1) * len / 2;
			i = j;
		}

		return subs;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 0,1,1,1 };
	check.checkLongLong(5, o.countAlternatingSubarrays(nums));

	nums = { 1,0,1,0 };
	check.checkLongLong(10, o.countAlternatingSubarrays(nums));
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
