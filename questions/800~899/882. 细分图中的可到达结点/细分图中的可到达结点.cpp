/* 细分图中的可到达结点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个无向图（原始图），图中有 n 个节点，编号从 0 到 n - 1 。你决定将图中的每条边细分为一条节点链，每条边之间的新节点数各不相同。

图用由边组成的二维数组 edges 表示，其中 edges[i] = [ui, vi, cnti] 表示原始图中节点 ui 和 vi 之间存在一条边，cnti 是将边细分后的新节点总数。注意，cnti == 0 表示边不可细分。

要细分边 [ui, vi] ，需要将其替换为 (cnti + 1) 条新边，和 cnti 个新节点。新节点为 x1, x2, ..., xcnti ，新边为 [ui, x1], [x1, x2], [x2, x3], ..., [xcnti+1, xcnti], [xcnti, vi] 。

现在得到一个新的 细分图 ，请你计算从节点 0 出发，可以到达多少个节点？节点 是否可以到达的判断条件 为：如果节点间距离是 maxMoves 或更少，则视为可以到达；否则，不可到达。

给你原始图和 maxMoves ，返回新的细分图中从节点 0 出发 可到达的节点数 。

 

示例 1：


输入：edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
输出：13
解释：边的细分情况如上图所示。
可以到达的节点已经用黄色标注出来。
示例 2：

输入：edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
输出：23
示例 3：

输入：edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
输出：1
解释：节点 0 与图的其余部分没有连通，所以只有节点 0 可以到达。
 

提示：

0 <= edges.length <= min(n * (n - 1) / 2, 104)
edges[i].length == 3
0 <= ui < vi < n
图中 不存在平行边
0 <= cnti <= 104
0 <= maxMoves <= 109
1 <= n <= 3000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reachable-nodes-in-subdivided-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

struct pairCompare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int, pair<int, bool>> allEdges;  // newNodes, visited
        vector<vector<pair<int, int>>> fromTos(n);  // distance, next node
        getFromTos(edges, fromTos, allEdges);

        vector<int> distances(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, pairCompare> dijkstra;  // distance, node
        dijkstra.push({ 0,0 });

        while (!dijkstra.empty()) {  // 每一次，从距离最短的点探索下一个
            int distance = dijkstra.top().first, node = dijkstra.top().second;
            dijkstra.pop();

            if (distance >= distances[node]) {  // 从另一条更远的距离到达该节点，跳过
                continue;
            }
            distances[node] = distance;

            for (auto& next : fromTos[node]) {
                if (distance + next.first <= maxMoves) {
                    dijkstra.push({ distance + next.first, next.second });  // 将下一跳加入队列，并不意味着马上会访问它，这需要根据优先队列的顺序
                    allEdges[hashKey(node, next.second)].second = true;  // 无论何时访问，该边所有节点确实都可达
                }
            }
        }

        return getReachableNodes(allEdges, distances, maxMoves);
    }

    int hashKey(int from, int to) {
        return (min(from, to) << 16) | max(from, to);
    }

    void getFromTos(vector<vector<int>>& edges, vector<vector<pair<int, int>>>& fromTos, unordered_map<int, pair<int, bool>>& allEdges) {
        for (auto& edge : edges) {
            fromTos[edge[0]].push_back({ edge[2] + 1, edge[1] });
            fromTos[edge[1]].push_back({ edge[2] + 1, edge[0] });
            int edgekey = hashKey(edge[0], edge[1]);
            allEdges[edgekey].first = edge[2];
            allEdges[edgekey].second = false;
        }
    }

    int getReachableNodes(unordered_map<int, pair<int, bool>>& allEdges, vector<int>& distances, int maxMoves) {
        int reachableNodes = 0;

        for (int distance : distances) {
            if (distance <= maxMoves) {  // 原始节点可达
                ++reachableNodes;
            }
        }

        for (auto& edge : allEdges) {
            int node1 = edge.first >> 16, node2 = edge.first & 0xffff, newNodes = edge.second.first;

            if (edge.second.second) {  // 这条边已经访问过，那么所有中间节点都可以加上
                reachableNodes += newNodes;
            }
            else {  // 这条边没有访问过，说明从一个端点到不了另外一个，只能访问中间部分节点
                int reachableNodes1 = distances[node1] <= maxMoves ? maxMoves - distances[node1] : 0;
                int reachableNodes2 = distances[node2] <= maxMoves ? maxMoves - distances[node2] : 0;
                reachableNodes += min(newNodes, reachableNodes1 + reachableNodes2);
            }
        }

        return reachableNodes;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1,10},{0,2,1},{1,2,2} };
    check.checkInt(13, o.reachableNodes(edges, 6, 3));

    edges = { {0,1,4},{1,2,6},{0,2,8},{1,3,1} };
    check.checkInt(23, o.reachableNodes(edges, 10, 4));

    edges = { {1,2,4},{1,4,5},{1,3,1},{2,3,4},{3,4,5} };
    check.checkInt(1, o.reachableNodes(edges, 17, 5));

    edges = {  };
    check.checkInt(1, o.reachableNodes(edges, 1, 3));
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
