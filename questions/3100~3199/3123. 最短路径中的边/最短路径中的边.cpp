/* 最短路径中的边.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个节点的无向带权图，节点编号为 0 到 n - 1 。图中总共有 m 条边，用二维数组 edges 表示，其中 edges[i] = [ai, bi, wi] 表示节点 ai 和 bi 之间有一条边权为 wi 的边。

对于节点 0 为出发点，节点 n - 1 为结束点的所有最短路，你需要返回一个长度为 m 的 boolean 数组 answer ，如果 edges[i] 至少 在其中一条最短路上，那么 answer[i] 为 true ，否则 answer[i] 为 false 。

请你返回数组 answer 。

注意，图可能不连通。



示例 1：



输入：n = 6, edges = [[0,1,4],[0,2,1],[1,3,2],[1,4,3],[1,5,1],[2,3,1],[3,5,3],[4,5,2]]

输出：[true,true,true,false,true,true,true,false]

解释：

以下为节点 0 出发到达节点 5 的 所有 最短路：

路径 0 -> 1 -> 5 ：边权和为 4 + 1 = 5 。
路径 0 -> 2 -> 3 -> 5 ：边权和为 1 + 1 + 3 = 5 。
路径 0 -> 2 -> 3 -> 1 -> 5 ：边权和为 1 + 1 + 2 + 1 = 5 。
示例 2：



输入：n = 4, edges = [[2,0,1],[0,1,1],[0,3,4],[3,2,2]]

输出：[true,false,false,true]

解释：

只有一条从节点 0 出发到达节点 3 的最短路 0 -> 2 -> 3 ，边权和为 1 + 2 = 3 。



提示：

2 <= n <= 5 * 104
m == edges.length
1 <= m <= min(5 * 104, n * (n - 1) / 2)
0 <= ai, bi < n
ai != bi
1 <= wi <= 105
图中没有重边。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
	int peer;
	long long weight;
	int index;

	Node() : peer(0), weight(0), index(0) {};
	Node(int p, long long w, int i) : peer(p), weight(w), index(i) {};
};

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
		int m = (int)edges.size();
		vector<vector<Node>> adjs(n);
		vector<long long> distance(n, inf);
		vector<bool> ans(m, false);

		getAdjs(m, edges, adjs);
		dijkstra(adjs, distance);
		DFS(n - 1, distance[n - 1], 0, adjs, distance, ans);

		return ans;
    }

	void getAdjs(int m, vector<vector<int>>& edges, vector<vector<Node>>& adjs) {
		for (int i = 0; i < m; ++i) {
			int a = edges[i][0], b = edges[i][1], weight = edges[i][2];
			adjs[a].push_back(Node(b, weight, i));
			adjs[b].push_back(Node(a, weight, i));
		}
	}

	void dijkstra(vector<vector<Node>>& adjs, vector<long long>& distance) {
		priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<>> nodes;
		nodes.push({ 0,0 });
		distance[0] = 0;

		while (!nodes.empty()) {
			int node = nodes.top().first;
			long long weight = nodes.top().second;
			nodes.pop();

			if (weight > distance[node]) {
				continue;
			}

			for (Node& next : adjs[node]) {
				long long nweight = weight + next.weight;
				if (nweight < distance[next.peer]) {
					distance[next.peer] = nweight;
					nodes.push({ next.peer,nweight });
				}
			}
		}
	}

	void DFS(int node, long long total, long long dist, vector<vector<Node>>& adjs, vector<long long>& distance, vector<bool>& ans) {
		for (Node& adj : adjs[node]) {
			if (!ans[adj.index] && dist + adj.weight + distance[adj.peer] == total) {
				ans[adj.index] = true;
				DFS(adj.peer, total, dist + adj.weight, adjs, distance, ans);
			}
		}
	}

	long long inf = LLONG_MAX / 2;
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> edges = { {0,1,4},{0,2,1},{1,3,2},{1,4,3},{1,5,1},{2,3,1},{3,5,3},{4,5,2} };
	vector<bool> actual = o.findAnswer(6, edges);
	vector<bool> expected = { true,true,true,false,true,true,true,false };
	check.checkBoolVector(expected, actual);

	edges = { {2,0,1},{0,1,1},{0,3,4},{3,2,2} };
	actual = o.findAnswer(4, edges);
	expected = { true,false,false,true };
	check.checkBoolVector(expected, actual);
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
