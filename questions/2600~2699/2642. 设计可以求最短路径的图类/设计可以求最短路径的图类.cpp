/* 设计可以求最短路径的图类.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个有 n 个节点的 有向带权 图，节点编号为 0 到 n - 1 。图中的初始边用数组 edges 表示，其中 edges[i] = [fromi, toi, edgeCosti] 表示从 fromi 到 toi 有一条代价为 edgeCosti 的边。

请你实现一个 Graph 类：

Graph(int n, int[][] edges) 初始化图有 n 个节点，并输入初始边。
addEdge(int[] edge) 向边集中添加一条边，其中 edge = [from, to, edgeCost] 。数据保证添加这条边之前对应的两个节点之间没有有向边。
int shortestPath(int node1, int node2) 返回从节点 node1 到 node2 的路径 最小 代价。如果路径不存在，返回 -1 。一条路径的代价是路径中所有边代价之和。


示例 1：



输入：
["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
[[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
输出：
[null, 6, -1, null, 6]

解释：
Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
g.shortestPath(3, 2); // 返回 6 。从 3 到 2 的最短路径如第一幅图所示：3 -> 0 -> 1 -> 2 ，总代价为 3 + 2 + 1 = 6 。
g.shortestPath(0, 3); // 返回 -1 。没有从 0 到 3 的路径。
g.addEdge([1, 3, 4]); // 添加一条节点 1 到节点 3 的边，得到第二幅图。
g.shortestPath(0, 3); // 返回 6 。从 0 到 3 的最短路径为 0 -> 1 -> 3 ，总代价为 2 + 4 = 6 。


提示：

1 <= n <= 100
0 <= edges.length <= n * (n - 1)
edges[i].length == edge.length == 3
0 <= fromi, toi, from, to, node1, node2 <= n - 1
1 <= edgeCosti, edgeCost <= 106
图中任何时候都不会有重边和自环。
调用 addEdge 至多 100 次。
调用 shortestPath 至多 100 次。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        size = n;
        inf = INT_MAX / 2;
        adjs.resize(n);
        costs.resize(n, vector<int>(n, inf));

        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            costs[edge[0]][edge[1]] = edge[2];
        }
    }

    void addEdge(vector<int> edge) {
        adjs[edge[0]].push_back(edge[1]);
        costs[edge[0]][edge[1]] = edge[2];
    }

    int shortestPath(int node1, int node2) {
        priority_queue<int, vector<int>, greater<int>> nodes;
        nodes.push(node1);
        vector<int> distance(size, inf);
        distance[node1] = 0;

        while (!nodes.empty()) {
            int node = nodes.top();
            nodes.pop();

            for (int next : adjs[node]) {
                int dis = distance[node] + costs[node][next];
                if (dis < distance[next]) {
                    distance[next] = dis;
                    nodes.push(next);
                }
            }
        }

        return distance[node2] == inf ? -1 : distance[node2];
    }

private:
    vector<vector<int>> adjs;
    vector<vector<int>> costs;
    int size;
    int inf;
};

int main()
{
    CheckResult check;

    vector<vector<int>> edges = { {0,2,5},{0,1,2},{1,2,1},{3,0,3} };
    Graph o1(4, edges);
    check.checkInt(6, o1.shortestPath(3, 2));
    check.checkInt(-1, o1.shortestPath(0, 3));
    o1.addEdge({ 1,3,4 });
    check.checkInt(6, o1.shortestPath(0, 3));
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
