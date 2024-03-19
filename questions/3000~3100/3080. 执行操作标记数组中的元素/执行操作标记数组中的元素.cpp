/* 执行操作标记数组中的元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 下标从 0 开始的正整数数组 nums 。

同时给你一个长度为 m 的二维操作数组 queries ，其中 queries[i] = [indexi, ki] 。

一开始，数组中的所有元素都 未标记 。

你需要依次对数组执行 m 次操作，第 i 次操作中，你需要执行：

如果下标 indexi 对应的元素还没标记，那么标记这个元素。
然后标记 ki 个数组中还没有标记的 最小 元素。如果有元素的值相等，那么优先标记它们中下标较小的。如果少于 ki 个未标记元素存在，那么将它们全部标记。
请你返回一个长度为 m 的数组 answer ，其中 answer[i]是第 i 次操作后数组中还没标记元素的 和 。



示例 1：

输入：nums = [1,2,2,1,2,3,1], queries = [[1,2],[3,3],[4,2]]

输出：[8,3,0]

解释：

我们依次对数组做以下操作：

标记下标为 1 的元素，同时标记 2 个未标记的最小元素。标记完后数组为 nums = [1,2,2,1,2,3,1] 。未标记元素的和为 2 + 2 + 3 + 1 = 8 。
标记下标为 3 的元素，由于它已经被标记过了，所以我们忽略这次标记，同时标记最靠前的 3 个未标记的最小元素。标记完后数组为 nums = [1,2,2,1,2,3,1] 。未标记元素的和为 3 。
标记下标为 4 的元素，由于它已经被标记过了，所以我们忽略这次标记，同时标记最靠前的 2 个未标记的最小元素。标记完后数组为 nums = [1,2,2,1,2,3,1] 。未标记元素的和为 0 。
示例 2：

输入：nums = [1,4,2,3], queries = [[0,1]]

输出：[7]

解释：我们执行一次操作，将下标为 0 处的元素标记，并且标记最靠前的 1 个未标记的最小元素。标记完后数组为 nums = [1,4,2,3] 。未标记元素的和为 4 + 3 = 7 。



提示：

n == nums.length
m == queries.length
1 <= m <= n <= 105
1 <= nums[i] <= 105
queries[i].length == 2
0 <= indexi, ki <= n - 1
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
		int n = nums.size(), m = queries.size();
		long long sum = 0;
		set<long long> nodes;
		vector<long long> ans(m);

		for (int i = 0; i < n; ++i) {
			sum += nums[i];
			nodes.insert(((long long)nums[i] << 32) | i);
		}

		for (int i = 0; i < m; ++i) {
			int index = queries[i][0], k = queries[i][1], num = nums[index];
			long long key = (((long long)num << 32) | index);

			if (nodes.count(key) != 0) {
				sum -= num;
				nodes.erase(key);
			}

			for (int j = 0; j < k && !nodes.empty(); ++j) {
				sum -= (*nodes.begin() >> 32);
				nodes.erase(nodes.begin());
			}

			ans[i] = sum;
		}

		return ans;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,2,1,2,3,1 };
	vector<vector<int>> queries = { {1,2},{3,3},{4,2} };
	vector<long long> actual = o.unmarkedSumArray(nums, queries);
	vector<long long> expected = { 8,3,0 };
	check.checkLongLongVector(expected, actual);

	nums = { 1,4,2,3 };
	queries = { {0,1} };
	actual = o.unmarkedSumArray(nums, queries);
	expected = { 7 };
	check.checkLongLongVector(expected, actual);
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
