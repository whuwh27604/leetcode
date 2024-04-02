/* 将数组分成最小总代价的子数组 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始长度为 n 的整数数组 nums 和两个 正 整数 k 和 dist 。

一个数组的 代价 是数组中的 第一个 元素。比方说，[1,2,3] 的代价为 1 ，[3,4,1] 的代价为 3 。

你需要将 nums 分割成 k 个 连续且互不相交 的子数组，满足 第二 个子数组与第 k 个子数组中第一个元素的下标距离 不超过 dist 。换句话说，如果你将 nums 分割成子数组 nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)] ，那么它需要满足 ik-1 - i1 <= dist 。

请你返回这些子数组的 最小 总代价。



示例 1：

输入：nums = [1,3,2,6,4,2], k = 3, dist = 3
输出：5
解释：将数组分割成 3 个子数组的最优方案是：[1,3] ，[2,6,4] 和 [2] 。这是一个合法分割，因为 ik-1 - i1 等于 5 - 2 = 3 ，等于 dist 。总代价为 nums[0] + nums[2] + nums[5] ，也就是 1 + 2 + 2 = 5 。
5 是分割成 3 个子数组的最小总代价。
示例 2：

输入：nums = [10,1,2,2,2,1], k = 4, dist = 3
输出：15
解释：将数组分割成 4 个子数组的最优方案是：[10] ，[1] ，[2] 和 [2,2,1] 。这是一个合法分割，因为 ik-1 - i1 等于 3 - 1 = 2 ，小于 dist 。总代价为 nums[0] + nums[1] + nums[2] + nums[3] ，也就是 10 + 1 + 2 + 2 = 15 。
分割 [10] ，[1] ，[2,2,2] 和 [1] 不是一个合法分割，因为 ik-1 和 i1 的差为 5 - 1 = 4 ，大于 dist 。
15 是分割成 4 个子数组的最小总代价。
示例 3：

输入：nums = [10,8,18,9], k = 3, dist = 1
输出：36
解释：将数组分割成 4 个子数组的最优方案是：[10] ，[8] 和 [18,9] 。这是一个合法分割，因为 ik-1 - i1 等于 2 - 1 = 1 ，等于 dist 。总代价为 nums[0] + nums[1] + nums[2] ，也就是 10 + 8 + 18 = 36 。
分割 [10] ，[8,18] 和 [9] 不是一个合法分割，因为 ik-1 和 i1 的差为 3 - 1 = 2 ，大于 dist 。
36 是分割成 3 个子数组的最小总代价。


提示：

3 <= n <= 105
1 <= nums[i] <= 109
3 <= k <= n
k - 2 <= dist <= n - 2
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
		map<int, int> windows, minKs;  // 本质上是从window[i, i + dist]中选择 k - 1 个最小的数
		int n = nums.size(), count = --k;
		long long cost = nums[0];

		for (int i = 1; i <= k; ++i) {  // 先取k个数放入minKs
			int num = nums[i];
			++minKs[num];
			cost += num;
		}

		for (int i = k + 1; i <= dist + 1; ++i) {  // 将窗口扩展到 dist + 1
			int num = nums[i];
			add(minKs, num, count, cost);  // 新来的数加入minKs
			num = minKs.rbegin()->first;  // 最大的数从minKs移入windows
			del(minKs, num, count, cost);
			++windows[num];
		}

		long long minCost = cost;

		for (int i = dist + 2; i < n; ++i) {  // 滑动窗口[i, i + dist]
			int num = nums[i - dist - 1];
			if (windows.count(num) != 0) {  // 删除窗口左端的num
				del(windows, num);
			}
			else {
				del(minKs, num, count, cost);
			}

			num = nums[i];
			++windows[num];  // 将新的num移入windows

			if (count < k || minKs.rbegin()->first > windows.begin()->first) {  // minKs删了一个数，或者比新来的数大，把windows的最小值移过来
				num = windows.begin()->first;
				add(minKs, num, count, cost);
				del(windows, num);
			}

			if (count > k) {  // minKs超大了，把最大的一个数移入windows
				num = minKs.rbegin()->first;
				++windows[num];
				del(minKs, num, count, cost);
			}

			minCost = min(minCost, cost);
		}

		return minCost;
    }

	void del(map<int, int>& mp, int num) {
		if (--mp[num] == 0) {
			mp.erase(num);
		}
	}

	void del(map<int, int>& mp, int num, int& count, long long& cost) {
		cost -= num;
		--count;
		del(mp, num);
	}

	void add(map<int, int>& mp, int num, int& count, long long& cost) {
		cost += num;
		++count;
		++mp[num];
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,3,2,6,4,2 };
	check.checkLongLong(5, o.minimumCost(nums, 3, 3));

	nums = { 10,1,2,2,2,1 };
	check.checkLongLong(15, o.minimumCost(nums, 4, 3));

	nums = { 10,8,18,9 };
	check.checkLongLong(36, o.minimumCost(nums, 3, 1));
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
