/* 合并两棵树后的最小直径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两棵 无向 树，分别有 n 和 m 个节点，节点编号分别为 0 到 n - 1 和 0 到 m - 1 。给你两个二维整数数组 edges1 和 edges2 ，长度分别为 n - 1 和 m - 1 ，其中 edges1[i] = [ai, bi] 表示在第一棵树中节点 ai 和 bi 之间有一条边，edges2[i] = [ui, vi] 表示在第二棵树中节点 ui 和 vi 之间有一条边。

你必须在第一棵树和第二棵树中分别选一个节点，并用一条边连接它们。

请你返回添加边后得到的树中，最小直径 为多少。

一棵树的 直径 指的是树中任意两个节点之间的最长路径长度。



示例 1：

输入：edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]

输出：3

解释：

将第一棵树中的节点 0 与第二棵树中的任意节点连接，得到一棵直径为 3 得树。

示例 2：

输入：edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]

输出：5

解释：

将第一棵树中的节点 0 和第二棵树中的节点 0 连接，可以得到一棵直径为 5 的树。



提示：

1 <= n, m <= 105
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
输入保证 edges1 和 edges2 分别表示一棵合法的树。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int diameter1 = getDiameter(edges1);
        int diameter2 = getDiameter(edges2);

        return max({ diameter1, diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1 });
    }

    int getDiameter(vector<vector<int>>& edges) {
        int size = (int)edges.size() + 1;

        vector<vector<int>> adjs(size);
        getAdjs(edges, adjs);

        int peer = 0;  // 两次BFS找直径：任意节点a开始，找最远点b；从b开始找最远点c；则bc是树的直径
        (void)getDiameter(adjs, size, 0, peer);

        return getDiameter(adjs, size, peer, peer);
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    int getDiameter(vector<vector<int>>& adjs, int size, int node, int& peer) {
        int diameter = -1;
        queue<int> nodes;
        nodes.push(node);
        vector<bool> visited(size, false);
        visited[node] = true;

        while (!nodes.empty()) {
            int count = (int)nodes.size();
            ++diameter;

            for (int i = 0; i < count; ++i) {
                node = nodes.front();
                nodes.pop();
                peer = node;

                for (int next : adjs[node]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        nodes.push(next);
                    }
                }
            }
        }

        return diameter;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> edges1 = { {0,1},{0,2},{0,3} };
    vector<vector<int>> edges2 = { {0,1} };
    check.checkInt(3, o.minimumDiameterAfterMerge(edges1, edges2));

    edges1 = { {0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7} };
    edges2 = { {0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7} };
    check.checkInt(5, o.minimumDiameterAfterMerge(edges1, edges2));

    edges1 = { {0,1},{2,0},{3,2},{3,6},{8,7},{4,8},{5,4},{3,5},{3,9} };
    edges2 = { {0,1},{0,2},{0,3} };
    check.checkInt(7, o.minimumDiameterAfterMerge(edges1, edges2));
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
