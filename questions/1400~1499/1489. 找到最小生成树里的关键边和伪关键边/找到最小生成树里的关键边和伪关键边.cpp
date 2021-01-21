/* 找到最小生成树里的关键边和伪关键边.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个点的带权无向连通图，节点编号为 0 到 n-1 ，同时还有一个数组 edges ，其中 edges[i] = [fromi, toi, weighti] 表示在 fromi 和 toi 节点之间有一条带权无向边。最小生成树 (MST) 是给定图中边的一个子集，它连接了所有节点且没有环，而且这些边的权值和最小。

请你找到给定图中最小生成树的所有关键边和伪关键边。如果从图中删去某条边，会导致最小生成树的权值和增加，那么我们就说它是一条关键边。伪关键边则是可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。

请注意，你可以分别以任意顺序返回关键边的下标和伪关键边的下标。

 

示例 1：



输入：n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
输出：[[0,1],[2,3,4,5]]
解释：上图描述了给定图。
下图是所有的最小生成树。

注意到第 0 条边和第 1 条边出现在了所有最小生成树中，所以它们是关键边，我们将这两个下标作为输出的第一个列表。
边 2，3，4 和 5 是所有 MST 的剩余边，所以它们是伪关键边。我们将它们作为输出的第二个列表。
示例 2 ：



输入：n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
输出：[[],[0,1,2,3]]
解释：可以观察到 4 条边都有相同的权值，任选它们中的 3 条可以形成一棵 MST 。所以 4 条边都是伪关键边。
 

提示：

2 <= n <= 100
1 <= edges.length <= min(200, n * (n - 1) / 2)
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti <= 1000
所有 (fromi, toi) 数对都是互不相同的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        parents.resize(size);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        parents[find(x)] = find(y);
    }

private:
    vector<int> parents;
};

class Tarjan {
public:
    Tarjan(int n_, const vector<vector<int>>& edges_, const vector<vector<int>>& edgeIds_) : \
        n(n_), edges(edges_), edgeIds(edgeIds_), low(n_, -1), dfn(n_, -1), ts(-1) {}

    void getAllCuttingEdges(vector<int>& bridges) {
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                getCuttingEdges(i, -1, bridges);
            }
        }
    }

    void getCuttingEdges(int vertex, int parentEdgeId, vector<int>& bridges) {
        low[vertex] = dfn[vertex] = ++ts;

        for (unsigned int i = 0; i < edges[vertex].size(); ++i) {
            int peer = edges[vertex][i], id = edgeIds[vertex][i];

            if (dfn[peer] == -1) {
                getCuttingEdges(peer, id, bridges);
                low[vertex] = min(low[vertex], low[peer]);

                if (low[peer] > dfn[vertex]) {
                    bridges.push_back(id);
                }
            }
            else if (id != parentEdgeId) {
                low[vertex] = min(low[vertex], dfn[peer]);
            }
        }
    }

private:
    const vector<vector<int>>& edges;
    const vector<vector<int>>& edgeIds;
    vector<int> low;
    vector<int> dfn;
    int n;
    int ts;
};

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[2] < v2[2];
}

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int edgeSize = edges.size();
        indexEdges(edgeSize, edges);
        sort(edges.begin(), edges.end(), vectorCompare);  // 按weight排序edges

        int i = 0, j;
        DSU dsu(n);
        vector<int> edgeLabels(edgeSize);
        vector<vector<int>> ans(2);

        while (i < edgeSize) {
            int weight = edges[i][2];
            for (j = i; j < edgeSize && edges[j][2] == weight; ++j) {}  // 所有weight等于edges[i][2]的edges

            unordered_map<int, int> setIds;
            int id = 0;
            assignSetIds(edges, i, j, dsu, id, setIds, edgeLabels);  // 给每个连通分量分配一个编号

            vector<vector<int>> currentEdges(id), currentEdgeIds(id);
            getCurrentEdges(edges, i, j, dsu, setIds, currentEdges, currentEdgeIds);  // 生成当前图的边

            Tarjan tarjan(id, currentEdges, currentEdgeIds);
            vector<int> bridges;
            tarjan.getAllCuttingEdges(bridges);  // 利用tarjan算法求所有的桥边
            labelBridges(bridges, edgeLabels, ans);  // 桥边都是关键边

            connectVertexes(edges, i, j, dsu);  // 连通当前edges的vertexes
            i = j;  // 处理下一个weight的edges
        }

        getPseudoCriticalEdges(edgeSize, edgeLabels, ans);

        return ans;
    }

    void indexEdges(int edgeSize, vector<vector<int>>& edges) {
        for (int i = 0; i < edgeSize; ++i) {
            edges[i].push_back(i);
        }
    }

    void assignSetIds(vector<vector<int>>& edges, int start, int end, DSU& dsu, int& id, unordered_map<int, int>& setIds, vector<int>& edgeLabels) {
        for (int i = start; i < end; ++i) {
            int x = dsu.find(edges[i][0]), y = dsu.find(edges[i][1]);

            if (x == y) {  // 这是一个自环边
                edgeLabels[edges[i][3]] = -1;
            }
            else {
                if (setIds.count(x) == 0) {
                    setIds[x] = id++;
                }

                if (setIds.count(y) == 0) {
                    setIds[y] = id++;
                }
            }
        }
    }

    void getCurrentEdges(vector<vector<int>>& edges, int start, int end, DSU& dsu, unordered_map<int, int>& setIds,
        vector<vector<int>>& currentEdges, vector<vector<int>>& currentEdgeIds) {
        for (int i = start; i < end; ++i) {
            int x = dsu.find(edges[i][0]), y = dsu.find(edges[i][1]);

            if (x != y) {
                int idx = setIds[x], idy = setIds[y];
                currentEdges[idx].push_back(idy);
                currentEdgeIds[idx].push_back(edges[i][3]);
                currentEdges[idy].push_back(idx);
                currentEdgeIds[idy].push_back(edges[i][3]);
            }
        }
    }

    void labelBridges(vector<int>& bridges, vector<int>& edgeLabels, vector<vector<int>>& ans) {
        for (int bridge : bridges) {
            edgeLabels[bridge] = 1;  // 将桥边（关键边）标记为1
            ans[0].push_back(bridge);
        }
    }

    void connectVertexes(vector<vector<int>>& edges, int start, int end, DSU& dsu) {
        for (int i = start; i < end; ++i) {
            dsu.merge(edges[i][0], edges[i][1]);
        }
    }

    void getPseudoCriticalEdges(int edgeSize, vector<int>& edgeLabels, vector<vector<int>>& ans) {
        for (int i = 0; i < edgeSize; ++i) {
            if (edgeLabels[i] == 0) {  // 处理完以后，未标记的edges就是伪关键边
                ans[1].push_back(i);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6} };
    vector<vector<int>> actual = o.findCriticalAndPseudoCriticalEdges(5, edges);
    vector<vector<int>> expected = { {0,1},{2,3,4,5} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    edges = { {0,1,1},{1,2,1},{2,3,1},{0,3,1} };
    actual = o.findCriticalAndPseudoCriticalEdges(4, edges);
    expected = { {},{0,1,2,3} };
    check.checkIntVectorVectorRandomOrder(expected, actual);
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
