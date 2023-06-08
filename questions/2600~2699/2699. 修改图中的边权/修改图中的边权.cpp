/* 修改图中的边权.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个节点的 无向带权连通 图，节点编号为 0 到 n - 1 ，再给你一个整数数组 edges ，其中 edges[i] = [ai, bi, wi] 表示节点 ai 和 bi 之间有一条边权为 wi 的边。

部分边的边权为 -1（wi = -1），其他边的边权都为 正 数（wi > 0）。

你需要将所有边权为 -1 的边都修改为范围 [1, 2 * 109] 中的 正整数 ，使得从节点 source 到节点 destination 的 最短距离 为整数 target 。如果有 多种 修改方案可以使 source 和 destination 之间的最短距离等于 target ，你可以返回任意一种方案。

如果存在使 source 到 destination 最短距离为 target 的方案，请你按任意顺序返回包含所有边的数组（包括未修改边权的边）。如果不存在这样的方案，请你返回一个 空数组 。

注意：你不能修改一开始边权为正数的边。



示例 1：



输入：n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
输出：[[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
解释：上图展示了一个满足题意的修改方案，从 0 到 1 的最短距离为 5 。
示例 2：



输入：n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
输出：[]
解释：上图是一开始的图。没有办法通过修改边权为 -1 的边，使得 0 到 2 的最短距离等于 6 ，所以返回一个空数组。
示例 3：



输入：n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
输出：[[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
解释：上图展示了一个满足题意的修改方案，从 0 到 2 的最短距离为 6 。


提示：

1 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= ai, bi < n
wi = -1 或者 1 <= wi <= 107
ai != bi
0 <= source, destination < n
source != destination
1 <= target <= 109
输入的图是连通图，且没有自环和重边。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<int> distance1(n, INT_MAX / 2), distance2(n, INT_MAX / 2);

        createGraph(edges, graph);
        dijkstra1(n, graph, source, destination, distance1);

        int delta = target - distance1[destination];
        if (delta < 0) {  // -1都修改为1，最短路仍然大于target，无解
            return {};
        }

        dijkstra2(n, graph, source, destination, delta, distance1, distance2);
        if (distance2[destination] < target) {  // 最短路无法再变大，无解
            return {};
        }

        modifyEdges(edges, graph);

        return edges;
    }

    void createGraph(vector<vector<int>>& edges, vector<vector<int>>& graph) {
        for (auto& edge : edges) {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
    }

    void dijkstra1(int n, vector<vector<int>>& graph, int source, int destination, vector<int>& distance1) {
        vector<bool> visited(n, false);
        distance1[source] = 0;

        for (int i = 0; i < n; ++i) {
            int current = 0, minDist = INT_MAX;
            for (int j = 0; j < n; ++j) {  // 找到还未确定距离的点中，距离最小的一个
                if (!visited[j] && distance1[j] < minDist) {
                    minDist = distance1[j];
                    current = j;
                }
            }

            if (current == destination) {
                break;
            }

            visited[current] = true;

            for (int next = 0; next < n; ++next) {
                int dis = graph[current][next];
                if (dis != 0) {
                    dis = max(dis, 1);  // 第一次dijkstra，碰到-1就修改为1，计算最短路径
                    distance1[next] = min(distance1[next], distance1[current] + dis);
                }
            }
        }
    }

    void dijkstra2(int n, vector<vector<int>>& graph, int source, int destination, int delta, vector<int>& distance1, vector<int>& distance2) {
        vector<bool> visited(n, false);
        distance2[source] = 0;

        for (int i = 0; i < n; ++i) {
            int current = 0, minDist = INT_MAX;
            for (int j = 0; j < n; ++j) {  // 找到还未确定距离的点中，距离最小的一个
                if (!visited[j] && distance2[j] < minDist) {
                    minDist = distance2[j];
                    current = j;
                }
            }

            if (current == destination) {
                break;
            }

            visited[current] = true;

            for (int next = 0; next < n; ++next) {
                int& dis = graph[current][next];
                if (dis != 0) {
                    if (dis == -1) {
                        dis = 1;
                        int wanted = delta + distance1[next] - distance2[current];
                        if (wanted > dis) {
                            dis = wanted;
                            graph[next][current] = wanted;
                        }
                    }

                    distance2[next] = min(distance2[next], distance2[current] + dis);
                }
            }
        }
    }

    void modifyEdges(vector<vector<int>>& edges, vector<vector<int>>& graph) {
        for (auto& edge : edges) {
            if (edge[2] == -1) {
                edge[2] = graph[edge[0]][edge[1]] == -1 ? 1 : graph[edge[0]][edge[1]];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {4,1,-1},{2,0,-1},{0,3,-1},{4,3,-1} };
    vector<vector<int>> actual = o.modifiedGraphEdges(5, edges, 0, 1, 5);
    vector<vector<int>> expected = { {4,1,1},{2,0,3},{0,3,3},{4,3,1} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    edges = { {0,1,-1},{0,2,5} };
    actual = o.modifiedGraphEdges(3, edges, 0, 2, 6);
    expected = {};
    check.checkIntVectorRandomOrderVector(expected, actual);

    edges = { {1,0,4},{1,2,3},{2,3,5},{0,3,-1} };
    actual = o.modifiedGraphEdges(4, edges, 0, 2, 6);
    expected = { {1,0,4},{1,2,3},{2,3,5},{0,3,1} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    edges = { {0,1,-1},{1,2,-1},{3,1,-1},{3,0,2},{0,2,5} };
    actual = o.modifiedGraphEdges(4, edges, 2, 3, 8);
    expected = {};
    check.checkIntVectorRandomOrderVector(expected, actual);

    edges = { {0,3,2},{0,4,3},{0,2,3},{3,4,-1},{2,1,5},{1,4,3} };
    actual = o.modifiedGraphEdges(5, edges, 0, 1, 7);
    expected = {};
    check.checkIntVectorRandomOrderVector(expected, actual);

    edges = { {0,3,-1},{0,4,4},{0,2,3},{3,4,2},{2,1,5},{1,4,-1} };
    actual = o.modifiedGraphEdges(5, edges, 0, 1, 6);
    expected = { {0,3,3},{0,4,4},{0,2,3},{3,4,2},{2,1,5},{1,4,2} };
    check.checkIntVectorRandomOrderVector(expected, actual);
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
