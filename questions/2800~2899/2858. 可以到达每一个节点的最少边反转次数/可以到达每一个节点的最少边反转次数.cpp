/* 可以到达每一个节点的最少边反转次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个点的 简单有向图 （没有重复边的有向图），节点编号为 0 到 n - 1 。如果这些边是双向边，那么这个图形成一棵 树 。

给你一个整数 n 和一个 二维 整数数组 edges ，其中 edges[i] = [ui, vi] 表示从节点 ui 到节点 vi 有一条 有向边 。

边反转 指的是将一条边的方向反转，也就是说一条从节点 ui 到节点 vi 的边会变为一条从节点 vi 到节点 ui 的边。

对于范围 [0, n - 1] 中的每一个节点 i ，你的任务是分别 独立 计算 最少 需要多少次 边反转 ，从节点 i 出发经过 一系列有向边 ，可以到达所有的节点。

请你返回一个长度为 n 的整数数组 answer ，其中 answer[i]表示从节点 i 出发，可以到达所有节点的 最少边反转 次数。



示例 1：



输入：n = 4, edges = [[2,0],[2,1],[1,3]]
输出：[1,1,0,2]
解释：上图表示了与输入对应的简单有向图。
对于节点 0 ：反转 [2,0] ，从节点 0 出发可以到达所有节点。
所以 answer[0] = 1 。
对于节点 1 ：反转 [2,1] ，从节点 1 出发可以到达所有节点。
所以 answer[1] = 1 。
对于节点 2 ：不需要反转就可以从节点 2 出发到达所有节点。
所以 answer[2] = 0 。
对于节点 3 ：反转 [1,3] 和 [2,1] ，从节点 3 出发可以到达所有节点。
所以 answer[3] = 2 。
示例 2：



输入：n = 3, edges = [[1,2],[2,0]]
输出：[2,0,1]
解释：上图表示了与输入对应的简单有向图。
对于节点 0 ：反转 [2,0] 和 [1,2] ，从节点 0 出发可以到达所有节点。
所以 answer[0] = 2 。
对于节点 1 ：不需要反转就可以从节点 2 出发到达所有节点。
所以 answer[1] = 0 。
对于节点 2 ：反转 [1,2] ，从节点 2 出发可以到达所有节点。
所以 answer[2] = 1 。


提示：

2 <= n <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ui == edges[i][0] < n
0 <= vi == edges[i][1] < n
ui != vi
输入保证如果边是双向边，可以得到一棵树。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int> ans(n);
        vector<vector<pair<int, bool>>> adjs(n);

        getAdjs(edges, adjs);
        ans[0] = getReversals(0, -1, adjs);
        getAllReversals(0, -1, false, adjs, ans);

        return ans;
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<pair<int, bool>>>& adjs) {
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1];
            adjs[from].push_back({ to,true });
            adjs[to].push_back({ from,false });
        }
    }

    int getReversals(int node, int parent, vector<vector<pair<int, bool>>>& adjs) {
        int reversals = 0;

        for (auto& p : adjs[node]) {
            if (p.first != parent) {
                if (!p.second) {
                    ++reversals;
                }
                reversals += getReversals(p.first, node, adjs);
            }
        }

        return reversals;
    }

    void getAllReversals(int node, int parent, bool reachable, vector<vector<pair<int, bool>>>& adjs, vector<int>& ans) {
        if (parent != -1) {
            ans[node] = reachable ? ans[parent] + 1 : ans[parent] - 1;
        }

        for (auto& p : adjs[node]) {
            if (p.first != parent) {
                getAllReversals(p.first, node, p.second, adjs, ans);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {2,0},{2,1},{1,3} };
    vector<int> actual = o.minEdgeReversals(4, edges);
    vector<int> expected = { 1,1,0,2 };
    check.checkIntVector(expected, actual);

    edges = { {1,2},{2,0} };
    actual = o.minEdgeReversals(3, edges);
    expected = { 2,0,1 };
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
