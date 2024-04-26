/* 追逐游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
秋游中的小力和小扣设计了一个追逐游戏。他们选了秋日市集景区中的 N 个景点，景点编号为 1~N。此外，他们还选择了 N 条小路，满足任意两个景点之间都可以通过小路互相到达，且不存在两条连接景点相同的小路。整个游戏场景可视作一个无向连通图，记作二维数组 edges，数组中以 [a,b] 形式表示景点 a 与景点 b 之间有一条小路连通。

小力和小扣只能沿景点间的小路移动。小力的目标是在最快时间内追到小扣，小扣的目标是尽可能延后被小力追到的时间。游戏开始前，两人分别站在两个不同的景点 startA 和 startB。每一回合，小力先行动，小扣观察到小力的行动后再行动。小力和小扣在每回合可选择以下行动之一：

移动至相邻景点
留在原地
如果小力追到小扣（即两人于某一时刻出现在同一位置），则游戏结束。若小力可以追到小扣，请返回最少需要多少回合；若小力无法追到小扣，请返回 -1。

注意：小力和小扣一定会采取最优移动策略。

示例 1：

输入：edges = [[1,2],[2,3],[3,4],[4,1],[2,5],[5,6]], startA = 3, startB = 5

输出：3

解释：image.png

第一回合，小力移动至 2 号点，小扣观察到小力的行动后移动至 6 号点； 第二回合，小力移动至 5 号点，小扣无法移动，留在原地； 第三回合，小力移动至 6 号点，小力追到小扣。返回 3。

示例 2：

输入：edges = [[1,2],[2,3],[3,4],[4,1]], startA = 1, startB = 3

输出：-1

解释：image.png

小力如果不动，则小扣也不动；否则小扣移动到小力的对角线位置。这样小力无法追到小扣。

提示：

edges 的长度等于图中节点个数
3 <= edges.length <= 10^5
1 <= edges[i][0], edges[i][1] <= edges.length 且 edges[i][0] != edges[i][1]
1 <= startA, startB <= edges.length 且 startA != startB
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
	int chaseGame(vector<vector<int>>& edges, int startA, int startB) {
		int n = (int)edges.size();

		vector<vector<int>> adjs(n + 1);
		if (getAdjs(edges, startA, startB, adjs)) {
			return 1;  // AB相邻，一回合即可
		}

		vector<int> times(n + 1, 0);
		int circleLen = 0, nodeX = 0;
		(void)DFS(startB, -1, 1, times, adjs, circleLen, nodeX);

		vector<int> distanceA(n + 1, -1), distanceB(n + 1, -1);
		getDistance(startA, adjs, distanceA);
		getDistance(startB, adjs, distanceB);
		if (circleLen > 3 && distanceA[nodeX] > distanceB[nodeX] + 1) {
			return -1;  // 环的长度大于3并且B能早一步到达环上，无法追上
		}

		int ans = 0;  // 一定有解，B往尽可能远的地方跑
		for (int node = 1; node <= n; ++node) {
			if (distanceA[node] > distanceB[node] + 1) {  // B可安全达到的点
				ans = max(ans, distanceA[node]);
			}
		}

		return ans;
	}

	bool getAdjs(vector<vector<int>>& edges, int startA, int startB, vector<vector<int>>& adjs) {
		for (auto& edge : edges) {
			int a = edge[0], b = edge[1];

			if ((a == startA && b == startB) || (a == startB && b == startA)) {
				return true;
			}

			adjs[a].push_back(b);
			adjs[b].push_back(a);
		}

		return false;
	}

	bool DFS(int node, int parent, int time, vector<int>& times, vector<vector<int>>& adjs, int& circleLen, int& nodeX) {
		if (times[node] != 0) {
			circleLen = time - times[node];
			nodeX = node;
			return true;
		}

		times[node] = time;

		for (int next : adjs[node]) {
			if (next != parent) {
				if (DFS(next, node, time + 1, times, adjs, circleLen, nodeX)) {
					return true;
				}
			}
		}

		return false;
	}

	void getDistance(int start, vector<vector<int>>& adjs, vector<int>& distance) {
		queue<int> nodes;
		nodes.push(start);
		distance[start] = 0;
		int dist = 0;

		while (!nodes.empty()) {
			int size = (int)nodes.size();
			dist += 1;

			for (int i = 0; i < size; ++i) {
				int node = nodes.front();
				nodes.pop();

				for (int next : adjs[node]) {
					if (distance[next] == -1) {
						distance[next] = dist;
						nodes.push(next);
					}
				}
			}
		}
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> edges = { {1,2},{2,3},{3,4},{4,1},{2,5},{5,6} };
	check.checkInt(3, o.chaseGame(edges, 3, 5));

	edges = { {1,2},{2,3},{3,4},{4,1} };
	check.checkInt(-1, o.chaseGame(edges, 1, 3));
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
