/* 访问消失节点的最少时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维数组 edges 表示一个 n 个点的无向图，其中 edges[i] = [ui, vi, lengthi] 表示节点 ui 和节点 vi 之间有一条需要 lengthi 单位时间通过的无向边。

同时给你一个数组 disappear ，其中 disappear[i] 表示节点 i 从图中消失的时间点，在那一刻及以后，你无法再访问这个节点。

注意，图有可能一开始是不连通的，两个节点之间也可能有多条边。

请你返回数组 answer ，answer[i] 表示从节点 0 到节点 i 需要的 最少 单位时间。如果从节点 0 出发 无法 到达节点 i ，那么 answer[i] 为 -1 。



示例 1：



输入：n = 3, edges = [[0,1,2],[1,2,1],[0,2,4]], disappear = [1,1,5]

输出：[0,-1,4]

解释：

我们从节点 0 出发，目的是用最少的时间在其他节点消失之前到达它们。

对于节点 0 ，我们不需要任何时间，因为它就是我们的起点。
对于节点 1 ，我们需要至少 2 单位时间，通过 edges[0] 到达。但当我们到达的时候，它已经消失了，所以我们无法到达它。
对于节点 2 ，我们需要至少 4 单位时间，通过 edges[2] 到达。
示例 2：



输入：n = 3, edges = [[0,1,2],[1,2,1],[0,2,4]], disappear = [1,3,5]

输出：[0,2,3]

解释：

我们从节点 0 出发，目的是用最少的时间在其他节点消失之前到达它们。

对于节点 0 ，我们不需要任何时间，因为它就是我们的起点。
对于节点 1 ，我们需要至少 2 单位时间，通过 edges[0] 到达。
对于节点 2 ，我们需要至少 3 单位时间，通过 edges[0] 和 edges[1] 到达。
示例 3：

输入：n = 2, edges = [[0,1,1]], disappear = [1,1]

输出：[0,-1]

解释：

当我们到达节点 1 的时候，它恰好消失，所以我们无法到达节点 1 。



提示：

1 <= n <= 5 * 104
0 <= edges.length <= 105
edges[i] == [ui, vi, lengthi]
0 <= ui, vi <= n - 1
1 <= lengthi <= 105
disappear.length == n
1 <= disappear[i] <= 105
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
		vector<vector<pair<int, int>>> adjs(n);
		priority_queue<long long, vector<long long>, greater<long long>> nodes;
		nodes.push(0);
		vector<int> times(n, INT_MAX);
		times[0] = 0;

		for (auto& edge : edges) {
			int u = edge[0], v = edge[1], len = edge[2];
			adjs[u].push_back({ v,len });
			adjs[v].push_back({ u,len });
		}

		while (!nodes.empty()) {
			int time = (int)(nodes.top() >> 32), node = (int)nodes.top();
			nodes.pop();

			if (time > times[node]) {
				continue;
			}

			for (auto& adj : adjs[node]) {
				int next = adj.first, nextTime = adj.second + time;
				if (nextTime < times[next] && nextTime < disappear[next]) {
					times[next] = nextTime;
					nodes.push((((long long)nextTime) << 32) | next);
				}
			}
		}

		for (auto& time : times) {
			if (time == INT_MAX) {
				time = -1;
			}
		}

		return times;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> edges = { {0,1,2},{1,2,1},{0,2,4} };
	vector<int> disappear = { 1,1,5 };
	vector<int> actual = o.minimumTime(3, edges, disappear);
	vector<int> expected = { 0,-1,4 };
	check.checkIntVector(expected, actual);

	edges = { {0,1,2},{1,2,1},{0,2,4} };
	disappear = { 1,3,5 };
	actual = o.minimumTime(3, edges, disappear);
	expected = { 0,2,3 };
	check.checkIntVector(expected, actual);

	edges = getIntVectorVector("./testcase1_edges.txt");
	disappear = getIntVector("./testcase1_disappear.txt");
	actual = o.minimumTime(50000, edges, disappear);
	expected = getIntVector("./testcase1_expected.txt");
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
