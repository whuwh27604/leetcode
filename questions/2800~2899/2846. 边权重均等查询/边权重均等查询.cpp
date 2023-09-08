/* 边权重均等查询.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现有一棵由 n 个节点组成的无向树，节点按从 0 到 n - 1 编号。给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ui, vi, wi] 表示树中存在一条位于节点 ui 和节点 vi 之间、权重为 wi 的边。

另给你一个长度为 m 的二维整数数组 queries ，其中 queries[i] = [ai, bi] 。对于每条查询，请你找出使从 ai 到 bi 路径上每条边的权重相等所需的 最小操作次数 。在一次操作中，你可以选择树上的任意一条边，并将其权重更改为任意值。

注意：

查询之间 相互独立 的，这意味着每条新的查询时，树都会回到 初始状态 。
从 ai 到 bi的路径是一个由 不同 节点组成的序列，从节点 ai 开始，到节点 bi 结束，且序列中相邻的两个节点在树中共享一条边。
返回一个长度为 m 的数组 answer ，其中 answer[i] 是第 i 条查询的答案。



示例 1：


输入：n = 7, edges = [[0,1,1],[1,2,1],[2,3,1],[3,4,2],[4,5,2],[5,6,2]], queries = [[0,3],[3,6],[2,6],[0,6]]
输出：[0,0,1,3]
解释：第 1 条查询，从节点 0 到节点 3 的路径中的所有边的权重都是 1 。因此，答案为 0 。
第 2 条查询，从节点 3 到节点 6 的路径中的所有边的权重都是 2 。因此，答案为 0 。
第 3 条查询，将边 [2,3] 的权重变更为 2 。在这次操作之后，从节点 2 到节点 6 的路径中的所有边的权重都是 2 。因此，答案为 1 。
第 4 条查询，将边 [0,1]、[1,2]、[2,3] 的权重变更为 2 。在这次操作之后，从节点 0 到节点 6 的路径中的所有边的权重都是 2 。因此，答案为 3 。
对于每条查询 queries[i] ，可以证明 answer[i] 是使从 ai 到 bi 的路径中的所有边的权重相等的最小操作次数。
示例 2：


输入：n = 8, edges = [[1,2,6],[1,3,4],[2,4,6],[2,5,3],[3,6,6],[3,0,8],[7,0,2]], queries = [[4,6],[0,4],[6,5],[7,4]]
输出：[1,2,2,3]
解释：第 1 条查询，将边 [1,3] 的权重变更为 6 。在这次操作之后，从节点 4 到节点 6 的路径中的所有边的权重都是 6 。因此，答案为 1 。
第 2 条查询，将边 [0,3]、[3,1] 的权重变更为 6 。在这次操作之后，从节点 0 到节点 4 的路径中的所有边的权重都是 6 。因此，答案为 2 。
第 3 条查询，将边 [1,3]、[5,2] 的权重变更为 6 。在这次操作之后，从节点 6 到节点 5 的路径中的所有边的权重都是 6 。因此，答案为 2 。
第 4 条查询，将边 [0,7]、[0,3]、[1,3] 的权重变更为 6 。在这次操作之后，从节点 7 到节点 4 的路径中的所有边的权重都是 6 。因此，答案为 3 。
对于每条查询 queries[i] ，可以证明 answer[i] 是使从 ai 到 bi 的路径中的所有边的权重相等的最小操作次数。


提示：

1 <= n <= 104
edges.length == n - 1
edges[i].length == 3
0 <= ui, vi < n
1 <= wi <= 26
生成的输入满足 edges 表示一棵有效的树
1 <= queries.length == m <= 2 * 104
queries[i].length == 2
0 <= ai, bi < n
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<int> log2(n + 1);
        calcLog(n, log2);
        int m = queries.size(), maxP = log2[n] + 1;
        vector<vector<pair<int, int>>> adjs(n);
        vector<int> depths(n, 0);
        vector<int> weight(26, 0);
        vector<vector<int>> weights(n, vector<int>(26, 0));
        vector<vector<int>> ancestors(maxP, vector<int>(n, -1));  // ancestors[i][j]表示节点j的第2 ^ i个祖先
        vector<int> ans(m);

        getAdjs(edges, adjs);
        DFS(0, -1, 0, adjs, depths, ancestors, weight, weights);
        getAncestors(n, maxP, ancestors);

        for (int i = 0; i < m; ++i) {
            int a = queries[i][0], b = queries[i][1];
            int lca = getLCA(a, b, log2, depths, ancestors);
            ans[i] = depths[a] + depths[b] - 2 * depths[lca] - getMaxWeight(weights[a], weights[b], weights[lca]);
        }

        return ans;
    }

    void calcLog(int n, vector<int>& log2) {
        log2[1] = 0;

        for (int i = 2; i <= n; ++i) {
            log2[i] = log2[i / 2] + 1;
        }
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<pair<int, int>>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back({ edge[1],edge[2] - 1 });
            adjs[edge[1]].push_back({ edge[0],edge[2] - 1 });
        }
    }

    void DFS(int node, int ancestor, int depth, vector<vector<pair<int, int>>>& adjs, vector<int>& depths, vector<vector<int>>& ancestors, vector<int>& weight, vector<vector<int>>& weights) {
        depths[node] = depth;
        weights[node] = weight;
        ancestors[0][node] = ancestor;

        for (auto& next : adjs[node]) {
            if (next.first != ancestor) {
                ++weight[next.second];
                DFS(next.first, node, depth + 1, adjs, depths, ancestors, weight, weights);
                --weight[next.second];
            }
        }
    }

    void getAncestors(int n, int maxP, vector<vector<int>>& ancestors) {
        for (int i = 1; i < maxP; ++i) {
            for (int j = 0; j < n; ++j) {
                int half = ancestors[i - 1][j];
                if (half != -1) {
                    ancestors[i][j] = ancestors[i - 1][half];
                }
            }
        }
    }

    int getLCA(int a, int b, vector<int>& log2, vector<int>& depths, vector<vector<int>>& ancestors) {
        int higher = a, lower = b;
        if (depths[a] > depths[b]) {
            swap(higher, lower);
        }

        while (depths[higher] != depths[lower]) {
            lower = ancestors[log2[depths[lower] - depths[higher]]][lower];  // 先让更低的节点往上跳，直到2个节点在同一高度
        }

        if (higher == lower) {
            return higher;
        }

        for (int p = log2[depths[higher]]; p >= 0; p--) {
            if (ancestors[p][higher] != ancestors[p][lower]) {  // 祖先不同时，一起往上跳
                higher = ancestors[p][higher];
                lower = ancestors[p][lower];
            }
        }

        return ancestors[0][higher];
    }

    int getMaxWeight(vector<int>& weightA, vector<int>& weightB, vector<int>& weightLCA) {
        vector<int> weight = weightA;
        int maxWeight = 0;

        for (int i = 0; i < 26; ++i) {
            weight[i] += weightB[i];
            weight[i] -= (2 * weightLCA[i]);
            maxWeight = max(maxWeight, weight[i]);
        }

        return maxWeight;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1,1},{1,2,1},{2,3,1},{3,4,2},{4,5,2},{5,6,2} };
    vector<vector<int>> queries = { {0,3},{3,6},{2,6},{0,6} };
    vector<int> actual = o.minOperationsQueries(7, edges, queries);
    vector<int> expected = { 0,0,1,3 };
    check.checkIntVector(expected, actual);

    edges = { {1,2,6},{1,3,4},{2,4,6},{2,5,3},{3,6,6},{3,0,8},{7,0,2} };
    queries = { {4,6},{0,4},{6,5},{7,4} };
    actual = o.minOperationsQueries(8, edges, queries);
    expected = { 1,2,2,3 };
    check.checkIntVector(expected, actual);

    edges = { {0,1,26} };
    queries = { {0,1},{0,0},{1,1} };
    actual = o.minOperationsQueries(2, edges, queries);
    expected = { 0,0,0 };
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
