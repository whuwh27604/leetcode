/* 边界元素是最大值的子数组数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 正 整数数组 nums 。

请你求出 nums 中有多少个子数组，满足子数组中 第一个 和 最后一个 元素都是这个子数组中的 最大 值。



示例 1：

输入：nums = [1,4,3,3,2]

输出：6

解释：

总共有 6 个子数组满足第一个元素和最后一个元素都是子数组中的最大值：

子数组 [1,4,3,3,2] ，最大元素为 1 ，第一个和最后一个元素都是 1 。
子数组 [1,4,3,3,2] ，最大元素为 4 ，第一个和最后一个元素都是 4 。
子数组 [1,4,3,3,2] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
子数组 [1,4,3,3,2] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
子数组 [1,4,3,3,2] ，最大元素为 2 ，第一个和最后一个元素都是 2 。
子数组 [1,4,3,3,2] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
所以我们返回 6 。

示例 2：

输入：nums = [3,3,3]

输出：6

解释：

总共有 6 个子数组满足第一个元素和最后一个元素都是子数组中的最大值：

子数组 [3,3,3] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
子数组 [3,3,3] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
子数组 [3,3,3] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
子数组 [3,3,3] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
子数组 [3,3,3] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
子数组 [3,3,3] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
所以我们返回 6 。

示例 3：

输入：nums = [1]

输出：1

解释：

nums 中只有一个子数组 [1] ，最大元素为 1 ，第一个和最后一个元素都是 1 。

所以我们返回 1 。



提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
		int size = (int)nums.size();
		stack<pair<int, int>> decreasing;  // { num, count of num in range [first greater than num, num] }
		long long subs = 0;

		for (int i = 0; i < size; ++i) {
			int num = nums[i];
			int leftEqual = 1;

			while (!decreasing.empty() && decreasing.top().first <= num) {
				if (decreasing.top().first == num) {
					leftEqual += decreasing.top().second;
				}

				decreasing.pop();
			}

			decreasing.push({ nums[i],leftEqual });
			subs += leftEqual;
		}

		return subs;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,4,3,3,2 };
	check.checkLongLong(6, o.numberOfSubarrays(nums));

	nums = { 3,3,3 };
	check.checkLongLong(6, o.numberOfSubarrays(nums));

	nums = { 1 };
	check.checkLongLong(1, o.numberOfSubarrays(nums));

	nums = { 3,2,1,3,3,3,1,4,3,3,2 };
	check.checkLongLong(18, o.numberOfSubarrays(nums));

	nums = { 1,3,3,3,1,4,3,3,2,1,3,3,3,1,4,3,3,2,1,3,3,3,1,4,3,3,2,1,3,3,3,1,4,3,3,2,1,3,3,3,1,4,3,3,2,1,3,3,3,1,4,3,3,2 };
	check.checkLongLong(123, o.numberOfSubarrays(nums));
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
