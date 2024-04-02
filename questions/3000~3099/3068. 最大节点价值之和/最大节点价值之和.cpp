/* 最大节点价值之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 n 个节点的 无向 树，节点从 0 到 n - 1 编号。树以长度为 n - 1 下标从 0 开始的二维整数数组 edges 的形式给你，其中 edges[i] = [ui, vi] 表示树中节点 ui 和 vi 之间有一条边。同时给你一个 正 整数 k 和一个长度为 n 下标从 0 开始的 非负 整数数组 nums ，其中 nums[i] 表示节点 i 的 价值 。

Alice 想 最大化 树中所有节点价值之和。为了实现这一目标，Alice 可以执行以下操作 任意 次（包括 0 次）：

选择连接节点 u 和 v 的边 [u, v] ，并将它们的值更新为：
nums[u] = nums[u] XOR k
nums[v] = nums[v] XOR k
请你返回 Alice 通过执行以上操作 任意次 后，可以得到所有节点 价值之和 的 最大值 。



示例 1：



输入：nums = [1,2,1], k = 3, edges = [[0,1],[0,2]]
输出：6
解释：Alice 可以通过一次操作得到最大价值和 6 ：
- 选择边 [0,2] 。nums[0] 和 nums[2] 都变为：1 XOR 3 = 2 ，数组 nums 变为：[1,2,1] -> [2,2,2] 。
所有节点价值之和为 2 + 2 + 2 = 6 。
6 是可以得到最大的价值之和。
示例 2：



输入：nums = [2,3], k = 7, edges = [[0,1]]
输出：9
解释：Alice 可以通过一次操作得到最大和 9 ：
- 选择边 [0,1] 。nums[0] 变为：2 XOR 7 = 5 ，nums[1] 变为：3 XOR 7 = 4 ，数组 nums 变为：[2,3] -> [5,4] 。
所有节点价值之和为 5 + 4 = 9 。
9 是可以得到最大的价值之和。
示例 3：



输入：nums = [7,7,7,7,7,7], k = 3, edges = [[0,1],[0,2],[0,3],[0,4],[0,5]]
输出：42
解释：Alice 不需要执行任何操作，就可以得到最大价值之和 42 。


提示：

2 <= n == nums.length <= 2 * 104
1 <= k <= 109
0 <= nums[i] <= 109
edges.length == n - 1
edges[i].length == 2
0 <= edges[i][0], edges[i][1] <= n - 1
输入保证 edges 构成一棵合法的树。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
		/* 对任意2点x、y，假设路径是x,p1,p2...pn,y，那么依次操作路径上的每一条边，最终x变为x^k，y变为y^k
		   而p1,p2...pn都不变，因为p^k^k = p。所以我们可以操作任意点对，题目变为了从nums中选偶数个操作得到最大值 */
		int n = nums.size();
		long long even = nums[0], odd = (nums[0] ^ k);

		for (int i = 1; i < n; ++i) {
			int num = nums[i];
			long long evenTmp = max(even + num, odd + (num ^ k));
			long long oddTmp = max(even + (num ^ k), odd + num);
			even = evenTmp;
			odd = oddTmp;
		}

		return even;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,1 };
	vector<vector<int>> edges = { {0,1},{0,2} };
	check.checkLongLong(6, o.maximumValueSum(nums, 3, edges));

	nums = { 2,3 };
	edges = { {0,1} };
	check.checkLongLong(9, o.maximumValueSum(nums, 7, edges));

	nums = { 7,7,7,7,7,7 };
	edges = { {0,1},{0,2},{0,3},{0,4},{0,5} };
	check.checkLongLong(42, o.maximumValueSum(nums, 3, edges));
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
