/* 图中的最短环.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现有一个含 n 个顶点的 双向 图，每个顶点按从 0 到 n - 1 标记。图中的边由二维整数数组 edges 表示，其中 edges[i] = [ui, vi] 表示顶点 ui 和 vi 之间存在一条边。每对顶点最多通过一条边连接，并且不存在与自身相连的顶点。

返回图中 最短 环的长度。如果不存在环，则返回 -1 。

环 是指以同一节点开始和结束，并且路径中的每条边仅使用一次。



示例 1：


输入：n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
输出：3
解释：长度最小的循环是：0 -> 1 -> 2 -> 0
示例 2：


输入：n = 4, edges = [[0,1],[0,2]]
输出：-1
解释：图中不存在循环


提示：

2 <= n <= 1000
1 <= edges.length <= 1000
edges[i].length == 2
0 <= ui, vi < n
ui != vi
不存在重复的边
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int minCycle = INT_MAX;
        vector<vector<int>> adjs(n);

        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }

        for (auto& edge : edges) {
            minCycle = min(minCycle, BFS(n, edge[0], edge[1], adjs));
        }

        return minCycle == INT_MAX ? -1 : minCycle;
    }

    int BFS(int n, int root, int peer, vector<vector<int>>& adjs) {
        int cycle = 1;
        queue<int> nodes;
        nodes.push(root);
        vector<bool> visited(n, false);
        visited[root] = true;

        while (!nodes.empty()) {
            int size = nodes.size();
            ++cycle;

            for (int i = 0; i < size; ++i) {
                int node = nodes.front();
                nodes.pop();

                for (int next : adjs[node]) {
                    if (node == root && next == peer) {
                        continue;
                    }

                    if (next == peer) {
                        return cycle;
                    }

                    if (!visited[next]) {
                        visited[next] = true;
                        nodes.push(next);
                    }
                }
            }
        }

        return INT_MAX;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1},{1,2},{2,0},{3,4},{4,5},{5,6},{6,3} };
    check.checkInt(3, o.findShortestCycle(7, edges));

    edges = { {0,1},{0,2} };
    check.checkInt(-1, o.findShortestCycle(7, edges));

    edges = { {4,2},{5,1},{5,0},{0,3},{5,2},{1,4},{1,3},{3,4} };
    check.checkInt(3, o.findShortestCycle(6, edges));

    edges = { {0,1},{0,2},{2,1},{0,3},{3,4},{4,1} };
    check.checkInt(3, o.findShortestCycle(5, edges));

    edges = { {0,3},{0,5},{3,4},{4,5},{1,9},{1,11},{9,10},{11,10},{2,6},{2,8},{6,7},{8,7},{0,1},{0,2},{1,2} };
    check.checkInt(3, o.findShortestCycle(12, edges));

    edges = { {0,1},{1,2},{2,0},{0,3},{3,4},{4,5},{6,7},{7,8},{8,9},{9,10},{10,11},{11,12},{12,0},{2,7},{2,4},{1,8},{1,11} };
    check.checkInt(3, o.findShortestCycle(13, edges));

    edges = { {0,1} };
    check.checkInt(-1, o.findShortestCycle(2, edges));
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
