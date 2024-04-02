/* 修改数组后最大化数组中的连续元素数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始只包含 正 整数的数组 nums 。

一开始，你可以将数组中 任意数量 元素增加 至多 1 。

修改后，你可以从最终数组中选择 一个或者更多 元素，并确保这些元素升序排序后是 连续 的。比方说，[3, 4, 5] 是连续的，但是 [3, 4, 6] 和 [1, 1, 2, 3] 不是连续的。

请你返回 最多 可以选出的元素数目。



示例 1：

输入：nums = [2,1,5,1,1]
输出：3
解释：我们将下标 0 和 3 处的元素增加 1 ，得到结果数组 nums = [3,1,5,2,1] 。
我们选择元素 [3,1,5,2,1] 并将它们排序得到 [1,2,3] ，是连续元素。
最多可以得到 3 个连续元素。
示例 2：

输入：nums = [1,4,7,10]
输出：1
解释：我们可以选择的最多元素数目是 1 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 106
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
		int maxElements = 1;
		vector<int> dp(1000002, 0);

		sort(nums.begin(), nums.end());

		for (int num : nums) {
			dp[num + 1] = 1 + dp[num];
			maxElements = max(maxElements, dp[num + 1]);
			dp[num] = 1 + dp[num - 1];
			maxElements = max(maxElements, dp[num]);
		}

		return maxElements;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 2,1,5,1,1 };
	check.checkInt(3, o.maxSelectedElements(nums));

	nums = { 1,4,7,10 };
	check.checkInt(1, o.maxSelectedElements(nums));
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
