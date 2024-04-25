/* 游乐园的游览计划.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
又到了一年一度的春游时间，小吴计划去游乐场游玩 1 天，游乐场总共有 N 个游乐项目，编号从 0 到 N-1。小吴给每个游乐项目定义了一个非负整数值 value[i] 表示自己的喜爱值。两个游乐项目之间会有双向路径相连，整个游乐场总共有 M 条双向路径，保存在二维数组 edges中。 小吴计划选择一个游乐项目 A 作为这一天游玩的重点项目。上午小吴准备游玩重点项目 A 以及与项目 A 相邻的两个项目 B、C （项目A、B与C要求是不同的项目，且项目B与项目C要求相邻），并返回 A ，即存在一条 A-B-C-A 的路径。 下午，小吴决定再游玩重点项目 A以及与A相邻的两个项目 B'、C'，（项目A、B'与C'要求是不同的项目，且项目B'与项目C'要求相邻），并返回 A ，即存在一条 A-B'-C'-A 的路径。下午游玩项目 B'、C' 可与上午游玩项目B、C存在重复项目。 小吴希望提前安排好游玩路径，使得喜爱值之和最大。请你返回满足游玩路径选取条件的最大喜爱值之和，如果没有这样的路径，返回 0。 注意：一天中重复游玩同一个项目并不能重复增加喜爱值了。例如：上下午游玩路径分别是 A-B-C-A与A-C-D-A 那么只能获得 value[A] + value[B] + value[C] + value[D] 的总和。

示例 1：

输入：edges = [[0,1],[1,2],[0,2]], value = [1,2,3]

输出：6

解释：喜爱值之和最高的方案之一是 0->1->2->0 与 0->2->1->0 。重复游玩同一点不重复计入喜爱值，返回1+2+3=6

示例 2：

输入：edges = [[0,2],[2,1]], value = [1,2,5]

输出：0

解释：无满足要求的游玩路径，返回 0

示例 3：

输入：edges = [[0,1],[0,2],[0,3],[0,4],[0,5],[1,3],[2,4],[2,5],[3,4],[3,5],[4,5]], value = [7,8,6,8,9,7]

输出：39

解释：喜爱值之和最高的方案之一是 3->0->1->3 与 3->4->5->3 。喜爱值最高为 7+8+8+9+7=39

限制：

3 <= value.length <= 10000
1 <= edges.length <= 10000
0 <= edges[i][0],edges[i][1] < value.length
0 <= value[i] <= 10000
edges中没有重复的边
edges[i][0] != edges[i][1]
*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
	int maxWeight(vector<vector<int>>& edges, vector<int>& value) {
		int n = (int)value.size(), m = (int)edges.size();

		vector<int> degrees(n, 0);
		getDegrees(edges, degrees);

		vector<unordered_set<int>> adjs(n);
		createGraph(m, edges, degrees, adjs);  // 构建有向图将复杂度降低到 m * sqrt(m)

		int ans = 0;
		unordered_map<int, pair<int, int>> edgeTop2s;
		vector<vector<pair<int, int>>> pointPairs(n);
		getRectangles(edges, adjs, value, edgeTop2s, pointPairs, ans);

		ans = max(ans, getMaxWeight(n, pointPairs, value));

		return ans;
	}

	void getDegrees(vector<vector<int>>& edges, vector<int>& degrees) {
		for (auto& edge : edges) {
			++degrees[edge[0]];
			++degrees[edge[1]];
		}
	}

	void createGraph(int m, vector<vector<int>>& edges, vector<int>& degrees, vector<unordered_set<int>>& adjs) {
		for (int i = 0; i < m; ++i) {
			int a = edges[i][0], b = edges[i][1];
			if ((degrees[a] < degrees[b]) || (degrees[a] == degrees[b] && a < b)) {
				adjs[a].insert(b);
			}
			else {
				adjs[b].insert(a);
			}
		}
	}

	void getRectangles(vector<vector<int>>& edges, vector<unordered_set<int>>& adjs, vector<int>& value,
		unordered_map<int, pair<int, int>>& edgeTop2s, vector<vector<pair<int, int>>>& pointPairs, int& maxWeight) {
		for (auto& edge : edges) {
			int a = edge[0], b = edge[1];

			for (int c : adjs[a]) {
				if (adjs[b].count(c) != 0) {
					saveRectangle(a, b, c, value, edgeTop2s, pointPairs, maxWeight);
					maxWeight = max(maxWeight, value[a] + value[b] + value[c]);  // 最大值出现在 abc
				}
			}
		}
	}

	void saveRectangle(int a, int b, int c, vector<int>& value,
		unordered_map<int, pair<int, int>>& edgeTop2s, vector<vector<pair<int, int>>>& pointPairs, int& maxWeight) {
		saveEdge(a, b, c, value, edgeTop2s, maxWeight);
		saveEdge(a, c, b, value, edgeTop2s, maxWeight);
		saveEdge(b, c, a, value, edgeTop2s, maxWeight);
		pointPairs[a].push_back({ b,c });
		pointPairs[b].push_back({ a,c });
		pointPairs[c].push_back({ a,b });
	}

	void saveEdge(int a, int b, int c, vector<int>& value, unordered_map<int, pair<int, int>>& edgeTop2s, int& maxWeight) {
		int edge = (a << 16) | b;
		if (edgeTop2s.count(edge) == 0) {
			edgeTop2s[edge] = { -1,-1 };
		}

		int& top1 = edgeTop2s[edge].first;
		int& top2 = edgeTop2s[edge].second;
		int val = value[c];
		if (val > top1) {
			top2 = top1;
			top1 = val;
		}
		else if (val > top2) {
			top2 = val;
		}

		if (top2 != -1) {
			maxWeight = max(maxWeight, value[a] + value[b] + top1 + top2);  // 最大值出现在 abc + abd
		}
	}

	int getMaxWeight(int n, vector<vector<pair<int, int>>>& pointPairs, vector<int>& value) {
		int maxWeight = 0;

		for (int a = 0; a < n; ++a) {
			maxWeight = max(maxWeight, getMaxWeight(a, pointPairs[a], value));
		}

		return maxWeight;
	}

	int getMaxWeight(int a, vector<pair<int, int>>& pointPairs, vector<int>& value) {
		int top1 = -1, top1b = 0, top1c = 0;  // 对于2个三角形的情况，top3至少有一个要出现在答案中
		int top2 = -1, top2b = 0, top2c = 0;
		int top3 = -1, top3b = 0, top3c = 0;

		for (auto& pp : pointPairs) {
			int b = pp.first, c = pp.second, val = value[b] + value[c];
			if (val > top1) {
				top3 = top2, top3b = top2b, top3c = top2c;
				top2 = top1, top2b = top1b, top2c = top1c;
				top1 = val, top1b = b, top1c = c;
			}
			else if (val > top2) {
				top3 = top2, top3b = top2b, top3c = top2c;
				top2 = val, top2b = b, top2c = c;
			}
			else if (val > top3) {
				top3 = val, top3b = b, top3c = c;
			}
		}

		int maxWeight = getMaxWeight(a, top1b, top1c, pointPairs, value);

		if (top2 != -1) {
			maxWeight = max(maxWeight, getMaxWeight(a, top2b, top2c, pointPairs, value));
		}

		if (top3 != -1) {
			maxWeight = max(maxWeight, getMaxWeight(a, top3b, top3c, pointPairs, value));
		}

		return maxWeight;
	}

	int getMaxWeight(int a, int b, int c, vector<pair<int, int>>& pointPairs, vector<int>& value) {
		int maxWeight = 0, weight = value[a] + value[b] + value[c];

		for (auto& pp : pointPairs) {
			int d = pp.first, e = pp.second;
			if (d != b && d != c && e != b && e != c) {
				maxWeight = max(maxWeight, weight + value[d] + value[e]);
			}
		}

		return maxWeight;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> edges = { {0,1},{1,2},{0,2} };
	vector<int> value = { 1,2,3 };
	check.checkInt(6, o.maxWeight(edges, value));

	edges = { {0,2},{2,1} };
	value = { 1,2,5 };
	check.checkInt(0, o.maxWeight(edges, value));

	edges = { {0,1},{0,2},{0,3},{0,4},{0,5},{1,3},{2,4},{2,5},{3,4},{3,5},{4,5} };
	value = { 7,8,6,8,9,7 };
	check.checkInt(39, o.maxWeight(edges, value));

	edges = { {0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{1,8},{1,9},{2,3},{2,4},{2,5},{2,6},{2,7},{2,8},{2,9},{3,4},{3,5},{3,6},{3,7},{3,8},{3,9},{4,5},{4,6},{4,7},{4,8},{4,9},{5,6},{5,7},{5,8},{5,9},{6,7},{6,8},{6,9},{7,8},{7,9},{8,9} };
	value = { 6808,5250,74,3659,8931,1273,7545,879,7924,7710 };
	check.checkInt(38918, o.maxWeight(edges, value));

	edges = { {0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9},{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9},{1,9} };
	value = { 4304,3170,7710,7158,9561,934,3100,279,1817,5336 };
	check.checkInt(31903, o.maxWeight(edges, value));

	edges = { {0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9},{0,10},{0,11},{0,12},{0,13},{0,14},{0,15},{0,16},{0,17},{0,18},{0,19},{0,20},{0,21},{0,22},{0,23},{0,24},{0,25},{0,26},{0,27},{0,28},{0,29},{0,30},{0,31},{0,32},{0,33},{0,34},{0,35},{0,36},{0,37},{0,38},{0,39},{0,40},{0,41},{0,42},{0,43},{0,44},{0,45},{0,46},{0,47},{0,48},{0,49},{0,50},{0,51},{0,52},{0,53},{0,54},{0,55},{0,56},{0,57},{0,58},{0,59},{0,60},{0,61},{0,62},{0,63},{0,64},{0,65},{0,66},{0,67},{0,68},{0,69},{0,70},{0,71},{0,72},{0,73},{0,74},{0,75},{0,76},{0,77},{0,78},{0,79},{0,80},{0,81},{0,82},{0,83},{0,84},{0,85},{0,86},{0,87},{0,88},{0,89},{0,90},{0,91},{0,92},{0,93},{0,94},{0,95},{0,96},{0,97},{0,98},{0,99},{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9},{9,10},{10,11},{11,12},{12,13},{13,14},{14,15},{15,16},{16,17},{17,18},{18,19},{19,20},{20,21},{21,22},{22,23},{23,24},{24,25},{25,26},{26,27},{27,28},{28,29},{29,30},{30,31},{31,32},{32,33},{33,34},{34,35},{35,36},{36,37},{37,38},{38,39},{39,40},{40,41},{41,42},{42,43},{43,44},{44,45},{45,46},{46,47},{47,48},{48,49},{49,50},{50,51},{51,52},{52,53},{53,54},{54,55},{55,56},{56,57},{57,58},{58,59},{59,60},{60,61},{61,62},{62,63},{63,64},{64,65},{65,66},{66,67},{67,68},{68,69},{69,70},{70,71},{71,72},{72,73},{73,74},{74,75},{75,76},{76,77},{77,78},{78,79},{79,80},{80,81},{81,82},{82,83},{83,84},{84,85},{85,86},{86,87},{87,88},{88,89},{89,90},{90,91},{91,92},{92,93},{93,94},{94,95},{95,96},{96,97},{97,98},{98,99},{1,99} };
	value = { 8873,561,95,8985,3756,9790,1408,8016,194,2770,5681,3456,6856,7507,964,3503,6677,3109,3250,2332,7845,7639,809,9998,8652,4850,5204,5732,6532,8015,5420,6776,2010,181,7930,5224,4055,8261,6738,1546,7318,7526,4201,4257,1565,598,6649,7705,5551,5151,1977,1413,8555,2798,2505,8382,4749,7066,9379,7700,8210,5130,8554,5484,448,4608,774,5323,4306,5177,54,7225,4631,367,5401,445,5371,286,3017,3899,8156,1134,5558,6577,3179,8267,7358,1712,7879,615,4820,5738,3134,592,3721,8763,6634,6198,6032,8589 };
	check.checkInt(44602, o.maxWeight(edges, value));

	edges = { {0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3} };
	value = { 0,6,4,2,1 };
	check.checkInt(13, o.maxWeight(edges, value));
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
