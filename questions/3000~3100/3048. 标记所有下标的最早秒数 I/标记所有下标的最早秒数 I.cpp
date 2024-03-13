/* 标记所有下标的最早秒数 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 1 开始的整数数组 nums 和 changeIndices ，数组的长度分别为 n 和 m 。

一开始，nums 中所有下标都是未标记的，你的任务是标记 nums 中 所有 下标。

从第 1 秒到第 m 秒（包括 第 m 秒），对于每一秒 s ，你可以执行以下操作 之一 ：

选择范围 [1, n] 中的一个下标 i ，并且将 nums[i] 减少 1 。
如果 nums[changeIndices[s]] 等于 0 ，标记 下标 changeIndices[s] 。
什么也不做。
请你返回范围 [1, m] 中的一个整数，表示最优操作下，标记 nums 中 所有 下标的 最早秒数 ，如果无法标记所有下标，返回 -1 。



示例 1：

输入：nums = [2,2,0], changeIndices = [2,2,2,2,3,2,2,1]
输出：8
解释：这个例子中，我们总共有 8 秒。按照以下操作标记所有下标：
第 1 秒：选择下标 1 ，将 nums[1] 减少 1 。nums 变为 [1,2,0] 。
第 2 秒：选择下标 1 ，将 nums[1] 减少 1 。nums 变为 [0,2,0] 。
第 3 秒：选择下标 2 ，将 nums[2] 减少 1 。nums 变为 [0,1,0] 。
第 4 秒：选择下标 2 ，将 nums[2] 减少 1 。nums 变为 [0,0,0] 。
第 5 秒，标​​​​​记 changeIndices[5] ，也就是标记下标 3 ，因为 nums[3] 等于 0 。
第 6 秒，标​​​​​记 changeIndices[6] ，也就是标记下标 2 ，因为 nums[2] 等于 0 。
第 7 秒，什么也不做。
第 8 秒，标记 changeIndices[8] ，也就是标记下标 1 ，因为 nums[1] 等于 0 。
现在所有下标已被标记。
最早可以在第 8 秒标记所有下标。
所以答案是 8 。
示例 2：

输入：nums = [1,3], changeIndices = [1,1,1,2,1,1,1]
输出：6
解释：这个例子中，我们总共有 7 秒。按照以下操作标记所有下标：
第 1 秒：选择下标 2 ，将 nums[2] 减少 1 。nums 变为 [1,2] 。
第 2 秒：选择下标 2 ，将 nums[2] 减少 1 。nums 变为 [1,1] 。
第 3 秒：选择下标 2 ，将 nums[2] 减少 1 。nums 变为 [1,0] 。
第 4 秒：标​​​​​记 changeIndices[4] ，也就是标记下标 2 ，因为 nums[2] 等于 0 。
第 5 秒：选择下标 1 ，将 nums[1] 减少 1 。nums 变为 [0,0] 。
第 6 秒：标​​​​​记 changeIndices[6] ，也就是标记下标 1 ，因为 nums[1] 等于 0 。
现在所有下标已被标记。
最早可以在第 6 秒标记所有下标。
所以答案是 6 。
示例 3：

Input: nums = [0,1], changeIndices = [2,2,2]
Output: -1
Explanation: 这个例子中，无法标记所有下标，因为下标 1 不在 changeIndices 中。
所以答案是 -1 。


提示：

1 <= n == nums.length <= 2000
0 <= nums[i] <= 109
1 <= m == changeIndices.length <= 2000
1 <= changeIndices[i] <= n
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
		int n = nums.size(), m = changeIndices.size(), low = 1, high = m, second = -1;

		while (low <= high) {
			int mid = (low + high) / 2;
			if (check(nums, changeIndices, mid)) {
				second = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}

		return second;
    }

	bool check(vector<int>& nums, vector<int>& changeIndices, int second) {
		int n = nums.size(), minus = 0;
		vector<int> lastIndex(n + 1, -1);
		vector<bool> marked(n + 1, false);

		for (int i = 1; i <= second; ++i) {
			lastIndex[changeIndices[i - 1]] = i;
		}

		for (int i = 1; i <= second; ++i) {
			int idx = changeIndices[i - 1];
			if (lastIndex[idx] == i) {  // 贪心策略，idx最后一次出现时再标记它
				if (minus >= nums[idx - 1]) {  // 保证前面积攒的minus操作可以将nums[idx - 1]清零
					minus -= nums[idx - 1];
					marked[idx] = true;
				}
				else {
					return false;
				}
			}
			else {  // 暂时还不需要标记，这一秒的机会可以将某个num减1
				++minus;
			}
		}

		for (int i = 1; i <= n; ++i) {
			if (!marked[i]) {
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

	vector<int> nums = { 2,2,0 };
	vector<int> changeIndices = { 2,2,2,2,3,2,2,1 };
	check.checkInt(8, o.earliestSecondToMarkIndices(nums, changeIndices));

	nums = { 1,3 };
	changeIndices = { 1,1,1,2,1,1,1 };
	check.checkInt(6, o.earliestSecondToMarkIndices(nums, changeIndices));

	nums = { 0,1 };
	changeIndices = { 2,2,2 };
	check.checkInt(-1, o.earliestSecondToMarkIndices(nums, changeIndices));
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
