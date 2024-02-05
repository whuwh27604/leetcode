/* 从第一个节点出发到最后一个节点的受限路径数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现有一个加权无向连通图。给你一个正整数 n ，表示图中有 n 个节点，并按从 1 到 n 给节点编号；另给你一个数组 edges ，其中每个 edges[i] = [ui, vi, weighti] 表示存在一条位于节点 ui 和 vi 之间的边，这条边的权重为 weighti 。

从节点 start 出发到节点 end 的路径是一个形如 [z0, z1, z2, ..., zk] 的节点序列，满足 z0 = start 、zk = end 且在所有符合 0 <= i <= k-1 的节点 zi 和 zi+1 之间存在一条边。

路径的距离定义为这条路径上所有边的权重总和。用 distanceToLastNode(x) 表示节点 n 和 x 之间路径的最短距离。受限路径 为满足 distanceToLastNode(zi) > distanceToLastNode(zi+1) 的一条路径，其中 0 <= i <= k-1 。

返回从节点 1 出发到节点 n 的 受限路径数 。由于数字可能很大，请返回对 109 + 7 取余 的结果。



示例 1：


输入：n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
输出：3
解释：每个圆包含黑色的节点编号和蓝色的 distanceToLastNode 值。三条受限路径分别是：
1) 1 --> 2 --> 5
2) 1 --> 2 --> 3 --> 5
3) 1 --> 3 --> 5
示例 2：


输入：n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
输出：1
解释：每个圆包含黑色的节点编号和蓝色的 distanceToLastNode 值。唯一一条受限路径是：1 --> 3 --> 7 。


提示：

1 <= n <= 2 * 104
n - 1 <= edges.length <= 4 * 104
edges[i].length == 3
1 <= ui, vi <= n
ui != vi
1 <= weighti <= 105
任意两个节点之间至多存在一条边
任意两个节点之间至少存在一条路径
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
	int countRestrictedPaths(int n, vector<vector<int>>& edges) {
		vector<vector<pair<int, int>>> adjs(n + 1);
		vector<int> minDist(n + 1, INT_MAX), memo(n + 1, -1);

		getAdjs(edges, adjs);
		dijkstra(n, adjs, minDist);

		return getPaths(1, n, adjs, minDist, memo);
	}

	void getAdjs(vector<vector<int>>& edges, vector<vector<pair<int, int>>>& adjs) {
		for (auto& edge : edges) {
			int x = edge[0], y = edge[1], weight = edge[2];
			adjs[x].push_back({ weight,y });
			adjs[y].push_back({ weight,x });
		}
	}

	void dijkstra(int n, vector<vector<pair<int, int>>>& adjs, vector<int>& minDist) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nodes;
		nodes.push({ 0,n });
		minDist[n] = 0;

		while (!nodes.empty()) {
			int weight = nodes.top().first, node = nodes.top().second;
			nodes.pop();

			for (auto& next : adjs[node]) {
				if (weight + next.first < minDist[next.second]) {
					minDist[next.second] = weight + next.first;
					nodes.push({ weight + next.first,next.second });
				}
			}
		}
	}

	int getPaths(int node, int n, vector<vector<pair<int, int>>>& adjs, vector<int>& minDist, vector<int>& memo) {
		if (node == n) {
			return 1;
		}

		if (memo[node] != -1) {
			return memo[node];
		}

		memo[node] = 0;

		for (auto& next : adjs[node]) {
			if (minDist[node] > minDist[next.second]) {
				memo[node] = (memo[node] + getPaths(next.second, n, adjs, minDist, memo)) % 1000000007;
			}
		}

		return memo[node];
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> edges = { {1,2,3},{1,3,3},{2,3,1},{1,4,2},{5,2,2},{3,5,1},{5,4,10} };
	check.checkInt(3, o.countRestrictedPaths(5, edges));

	edges = { {1,3,1},{4,1,2},{7,3,4},{2,5,3},{5,6,1},{6,7,2},{7,5,3},{2,6,4} };
	check.checkInt(1, o.countRestrictedPaths(7, edges));

	edges = getIntVectorVector("testcase1.txt");
	check.checkInt(926335851, o.countRestrictedPaths(312, edges));
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
