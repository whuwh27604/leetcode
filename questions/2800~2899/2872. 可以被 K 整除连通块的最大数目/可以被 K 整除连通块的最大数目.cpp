/* 可以被 K 整除连通块的最大数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 n 个节点的无向树，节点编号为 0 到 n - 1 。给你整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 有一条边。

同时给你一个下标从 0 开始长度为 n 的整数数组 values ，其中 values[i] 是第 i 个节点的 值 。再给你一个整数 k 。

你可以从树中删除一些边，也可以一条边也不删，得到若干连通块。一个 连通块的值 定义为连通块中所有节点值之和。如果所有连通块的值都可以被 k 整除，那么我们说这是一个 合法分割 。

请你返回所有合法分割中，连通块数目的最大值 。



示例 1：



输入：n = 5, edges = [[0,2],[1,2],[1,3],[2,4]], values = [1,8,1,4,4], k = 6
输出：2
解释：我们删除节点 1 和 2 之间的边。这是一个合法分割，因为：
- 节点 1 和 3 所在连通块的值为 values[1] + values[3] = 12 。
- 节点 0 ，2 和 4 所在连通块的值为 values[0] + values[2] + values[4] = 6 。
最多可以得到 2 个连通块的合法分割。
示例 2：



输入：n = 7, edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [3,0,6,1,5,2,1], k = 3
输出：3
解释：我们删除节点 0 和 2 ，以及节点 0 和 1 之间的边。这是一个合法分割，因为：
- 节点 0 的连通块的值为 values[0] = 3 。
- 节点 2 ，5 和 6 所在连通块的值为 values[2] + values[5] + values[6] = 9 。
- 节点 1 ，3 和 4 的连通块的值为 values[1] + values[3] + values[4] = 6 。
最多可以得到 3 个连通块的合法分割。


提示：

1 <= n <= 3 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
values.length == n
0 <= values[i] <= 109
1 <= k <= 109
values 之和可以被 k 整除。
输入保证 edges 是一棵无向树。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
		int components = 0;
		vector<vector<int>> adjs(n);

		getAdjs(edges, adjs);
		(void)DFS(0, -1, k, adjs, values, components);

		return components;
    }

	void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
		for (auto& edge : edges) {
			int a = edge[0], b = edge[1];
			adjs[a].push_back(b);
			adjs[b].push_back(a);
		}
	}

	long long DFS(int node, int parent, int k, vector<vector<int>>& adjs, vector<int>& values, int& components) {
		long long sum = values[node];

		for (int next : adjs[node]) {
			if (next != parent) {
				sum += DFS(next, node, k, adjs, values, components);
			}
		}

		if (sum % k == 0) {
			++components;
		}

		return sum;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> edges = { {0,2},{1,2},{1,3},{2,4} };
	vector<int> values = { 1,8,1,4,4 };
	check.checkInt(2, o.maxKDivisibleComponents(5, edges, values, 6));

	edges = { {0,1},{0,2},{1,3},{1,4},{2,5},{2,6} };
	values = { 3,0,6,1,5,2,1 };
	check.checkInt(3, o.maxKDivisibleComponents(7, edges, values, 3));

	edges = {  };
	values = { 10000 };
	check.checkInt(1, o.maxKDivisibleComponents(1, edges, values, 100));
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
