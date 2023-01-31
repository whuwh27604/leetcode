﻿/* 最大价值和与最小价值和的差值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个节点的无向无根图，节点编号为 0 到 n - 1 。给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间有一条边。

每个节点都有一个价值。给你一个整数数组 price ，其中 price[i] 是第 i 个节点的价值。

一条路径的 价值和 是这条路径上所有节点的价值之和。

你可以选择树中任意一个节点作为根节点 root 。选择 root 为根的 开销 是以 root 为起点的所有路径中，价值和 最大的一条路径与最小的一条路径的差值。

请你返回所有节点作为根节点的选择中，最大 的 开销 为多少。



示例 1：



输入：n = 6, edges = [[0,1],[1,2],[1,3],[3,4],[3,5]], price = [9,8,7,6,10,5]
输出：24
解释：上图展示了以节点 2 为根的树。左图（红色的节点）是最大价值和路径，右图（蓝色的节点）是最小价值和路径。
- 第一条路径节点为 [2,1,3,4]：价值为 [7,8,6,10] ，价值和为 31 。
- 第二条路径节点为 [2] ，价值为 [7] 。
最大路径和与最小路径和的差值为 24 。24 是所有方案中的最大开销。
示例 2：



输入：n = 3, edges = [[0,1],[1,2]], price = [1,1,1]
输出：2
解释：上图展示了以节点 0 为根的树。左图（红色的节点）是最大价值和路径，右图（蓝色的节点）是最小价值和路径。
- 第一条路径包含节点 [0,1,2]：价值为 [1,1,1] ，价值和为 3 。
- 第二条路径节点为 [0] ，价值为 [1] 。
最大路径和与最小路径和的差值为 2 。2 是所有方案中的最大开销。


提示：

1 <= n <= 105
edges.length == n - 1
0 <= ai, bi <= n - 1
edges 表示一棵符合题面要求的树。
price.length == n
1 <= price[i] <= 105
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        if (n == 1) {
            return 0;
        }

        long long maxCost = 0;
        vector<vector<int>> adjs(n);

        getAdjs(edges, adjs);
        (void)DFS(0, -1, adjs, price, maxCost);

        return maxCost;
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    pair<long long, long long> DFS(int node, int parent, vector<vector<int>>& adjs, vector<int>& price, long long& maxCost) {
        vector<long long> leafCosts, nonLeafCosts;  // 最大开销由两部分组成：1、node到1个叶子节点；2、node到另一个叶子节点的前一跳，即非叶子节点

        for (int next : adjs[node]) {
            if (next != parent) {
                pair<long long, long long> cost = DFS(next, node, adjs, price, maxCost);
                leafCosts.push_back(cost.first);
                nonLeafCosts.push_back(cost.second);
            }
        }

        if (adjs[node].size() == 1) {
            maxCost = max(maxCost, price[node] + (nonLeafCosts.empty() ? 0 : *max_element(nonLeafCosts.begin(), nonLeafCosts.end())));
            return { price[node],0 };
        }
        else {
            maxCost = max(maxCost, price[node] + getMaxCost(leafCosts, nonLeafCosts));
            return { price[node] + *max_element(leafCosts.begin(), leafCosts.end()), price[node] + *max_element(nonLeafCosts.begin(), nonLeafCosts.end()) };
        }
    }

    long long getMaxCost(vector<long long>& leafCosts, vector<long long>& nonLeafCosts) {
        long long max1 = 0, max2 = 0, maxCost = 0;
        int size = leafCosts.size();

        for (long long cost : nonLeafCosts) {
            if (cost > max1) {
                max2 = max1;
                max1 = cost;
            }
            else if (cost > max2) {
                max2 = cost;
            }
        }

        for (int i = 0; i < size; ++i) {
            maxCost = max(maxCost, leafCosts[i] + (nonLeafCosts[i] == max1 ? max2 : max1));
        }

        return maxCost;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1},{1,2},{1,3},{3,4},{3,5} };
    vector<int> price = { 9,8,7,6,10,5 };
    check.checkLongLong(24, o.maxOutput(6, edges, price));

    edges = { {0,1},{1,2} };
    price = { 1,1,1 };
    check.checkLongLong(2, o.maxOutput(3, edges, price));

    edges = {  };
    price = { 5 };
    check.checkLongLong(0, o.maxOutput(1, edges, price));

    edges = { {0,3},{2,1},{1,3} };
    price = { 6,8,2,14 };
    check.checkLongLong(28, o.maxOutput(4, edges, price));
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
