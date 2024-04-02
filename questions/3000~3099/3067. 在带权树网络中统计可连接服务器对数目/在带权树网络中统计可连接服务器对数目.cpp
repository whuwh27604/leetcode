/* 在带权树网络中统计可连接服务器对数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵无根带权树，树中总共有 n 个节点，分别表示 n 个服务器，服务器从 0 到 n - 1 编号。同时给你一个数组 edges ，其中 edges[i] = [ai, bi, weighti] 表示节点 ai 和 bi 之间有一条双向边，边的权值为 weighti 。再给你一个整数 signalSpeed 。

如果两个服务器 a ，b 和 c 满足以下条件，那么我们称服务器 a 和 b 是通过服务器 c 可连接的 ：

a < b ，a != c 且 b != c 。
从 c 到 a 的距离是可以被 signalSpeed 整除的。
从 c 到 b 的距离是可以被 signalSpeed 整除的。
从 c 到 b 的路径与从 c 到 a 的路径没有任何公共边。
请你返回一个长度为 n 的整数数组 count ，其中 count[i] 表示通过服务器 i 可连接 的服务器对的 数目 。



示例 1：



输入：edges = [[0,1,1],[1,2,5],[2,3,13],[3,4,9],[4,5,2]], signalSpeed = 1
输出：[0,4,6,6,4,0]
解释：由于 signalSpeed 等于 1 ，count[c] 等于所有从 c 开始且没有公共边的路径对数目。
在输入图中，count[c] 等于服务器 c 左边服务器数目乘以右边服务器数目。
示例 2：



输入：edges = [[0,6,3],[6,5,3],[0,3,1],[3,2,7],[3,1,6],[3,4,2]], signalSpeed = 3
输出：[2,0,0,0,0,0,2]
解释：通过服务器 0 ，有 2 个可连接服务器对(4, 5) 和 (4, 6) 。
通过服务器 6 ，有 2 个可连接服务器对 (4, 5) 和 (0, 5) 。
所有服务器对都必须通过服务器 0 或 6 才可连接，所以其他服务器对应的可连接服务器对数目都为 0 。


提示：

2 <= n <= 1000
edges.length == n - 1
edges[i].length == 3
0 <= ai, bi < n
edges[i] = [ai, bi, weighti]
1 <= weighti <= 106
1 <= signalSpeed <= 106
输入保证 edges 构成一棵合法的树。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
		int n = edges.size() + 1;
		vector<vector<pair<int, int>>> adjs(n);
		vector<int> pairs(n, 0);

		getAdjs(edges, adjs);

		for (int i = 0; i < n; ++i) {
			int sum = 0;

			for (auto& next : adjs[i]) {
				int nodes = DFS(next.first, i, next.second, signalSpeed, adjs);
				pairs[i] += (sum * nodes);
				sum += nodes;
			}
		}

		return pairs;
    }

	void getAdjs(vector<vector<int>>& edges, vector<vector<pair<int, int>>>& adjs) {
		for (auto& edge : edges) {
			int a = edge[0], b = edge[1], weight = edge[2];
			adjs[a].push_back({ b,weight });
			adjs[b].push_back({ a,weight });
		}
	}

	int DFS(int node, int parent, int dist, int signalSpeed, vector<vector<pair<int, int>>>& adjs) {
		int count = (dist % signalSpeed == 0 ? 1 : 0);

		for (auto& next : adjs[node]) {
			if (next.first != parent) {
				count += DFS(next.first, node, dist + next.second, signalSpeed, adjs);
			}
		}

		return count;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> edges = { {0,1,1},{1,2,5},{2,3,13},{3,4,9},{4,5,2} };
	vector<int> actual = o.countPairsOfConnectableServers(edges, 1);
	vector<int> expected = { 0,4,6,6,4,0 };
	check.checkIntVector(expected, actual);

	edges = { {0,6,3},{6,5,3},{0,3,1},{3,2,7},{3,1,6},{3,4,2} };
	actual = o.countPairsOfConnectableServers(edges, 3);
	expected = { 2,0,0,0,0,0,2 };
	check.checkIntVector(expected, actual);

	edges = { {1,0,2},{2,1,4},{3,2,4},{4,0,3},{5,1,4},{6,2,2},{7,6,4},{8,1,2},{9,8,3} };
	actual = o.countPairsOfConnectableServers(edges, 1);
	expected = { 8,28,20,0,0,0,8,0,8,0 };
	check.checkIntVector(expected, actual);
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
