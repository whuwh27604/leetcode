/* 标记所有下标的最早秒数 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 1 开始的整数数组 nums 和 changeIndices ，数组的长度分别为 n 和 m 。

一开始，nums 中所有下标都是未标记的，你的任务是标记 nums 中 所有 下标。

从第 1 秒到第 m 秒（包括 第 m 秒），对于每一秒 s ，你可以执行以下操作 之一 ：

选择范围 [1, n] 中的一个下标 i ，并且将 nums[i] 减少 1 。
将 nums[changeIndices[s]] 设置成任意的 非负 整数。
选择范围 [1, n] 中的一个下标 i ， 满足 nums[i] 等于 0, 并 标记 下标 i 。
什么也不做。
请你返回范围 [1, m] 中的一个整数，表示最优操作下，标记 nums 中 所有 下标的 最早秒数 ，如果无法标记所有下标，返回 -1 。



示例 1：

输入：nums = [3,2,3], changeIndices = [1,3,2,2,2,2,3]
输出：6
解释：这个例子中，我们总共有 7 秒。按照以下操作标记所有下标：
第 1 秒：将 nums[changeIndices[1]] 变为 0 。nums 变为 [0,2,3] 。
第 2 秒：将 nums[changeIndices[2]] 变为 0 。nums 变为 [0,2,0] 。
第 3 秒：将 nums[changeIndices[3]] 变为 0 。nums 变为 [0,0,0] 。
第 4 秒：标记下标 1 ，因为 nums[1] 等于 0 。
第 5 秒：标记下标 2 ，因为 nums[2] 等于 0 。
第 6 秒：标记下标 3 ，因为 nums[3] 等于 0 。
现在所有下标已被标记。
最早可以在第 6 秒标记所有下标。
所以答案是 6 。
示例 2：

输入：nums = [0,0,1,2], changeIndices = [1,2,1,2,1,2,1,2]
输出：7
解释：这个例子中，我们总共有 8 秒。按照以下操作标记所有下标：
第 1 秒：标记下标 1 ，因为 nums[1] 等于 0 。
第 2 秒：标记下标 2 ，因为 nums[2] 等于 0 。
第 3 秒：将 nums[4] 减少 1 。nums 变为 [0,0,1,1] 。
第 4 秒：将 nums[4] 减少 1 。nums 变为 [0,0,1,0] 。
第 5 秒：将 nums[3] 减少 1 。nums 变为 [0,0,0,0] 。
第 6 秒：标记下标 3 ，因为 nums[3] 等于 0 。
第 7 秒：标记下标 4 ，因为 nums[4] 等于 0 。
现在所有下标已被标记。
最早可以在第 7 秒标记所有下标。
所以答案是 7 。
示例 3：

输入：nums = [1,2,3], changeIndices = [1,2,3]
输出：-1
解释：这个例子中，无法标记所有下标，因为我们没有足够的秒数。
所以答案是 -1 。


提示：

1 <= n == nums.length <= 5000
0 <= nums[i] <= 109
1 <= m == changeIndices.length <= 5000
1 <= changeIndices[i] <= n
*/

#include <iostream>
#include <numeric>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
		int n = (int)nums.size(), m = (int)changeIndices.size();
		long long total = accumulate(nums.begin(), nums.end(), (long long)0) + n;

		vector<int> changeTimes(n, -1);
		getChangeTime(m, changeIndices, changeTimes);

		int low = n, high = m, ans = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (check(nums, changeIndices, changeTimes, total, mid)) {
				ans = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}

		return ans;
    }

	void getChangeTime(int m, vector<int>& changeIndices, vector<int>& changeTimes) {
		for (int t = m - 1; t >= 0; --t) {
			changeTimes[changeIndices[t] - 1] = t;
		}
	}

	bool check(vector<int>& nums, vector<int>& changeIndices, vector<int>& changeTimes, long long total, int last) {
		priority_queue<int, vector<int>, greater<int>> seconds;
		int cnt = 0;  // 记录可用秒数

		for (int t = last - 1; t >= 0; --t) {
			int idx = changeIndices[t] - 1;
			int second = nums[idx];

			if (second <= 1 || t != changeTimes[idx]) {
				++cnt;  // 不选择执行快速设置操作，可用秒加1
				continue;
			}

			if (cnt == 0) {
				if (seconds.empty() || second <= seconds.top()) {
					++cnt;  // 不操作，可用秒加1
					continue;
				}

				total += seconds.top() + 1;
				seconds.pop();
				cnt += 2;  // 反悔一个快速设置 + mark操作
			}

			total -= (second + 1);  // 快速设置 + mark
			--cnt;  // mark
			seconds.push(second);  // 缓存，有可能被反悔
		}

		return cnt >= total;  // 最终可用秒要大于总共需要的秒数
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 3,2,3 };
	vector<int> changeIndices = { 1,3,2,2,2,2,3 };
	check.checkInt(6, o.earliestSecondToMarkIndices(nums, changeIndices));

	nums = { 0,0,1,2 };
	changeIndices = { 1,2,1,2,1,2,1,2 };
	check.checkInt(7, o.earliestSecondToMarkIndices(nums, changeIndices));

	nums = { 1,2,3 };
	changeIndices = { 1,2,3 };
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
