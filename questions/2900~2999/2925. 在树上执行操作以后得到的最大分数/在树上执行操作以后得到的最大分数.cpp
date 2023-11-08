/* 在树上执行操作以后得到的最大分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一棵 n 个节点的无向树，节点编号为 0 到 n - 1 ，根节点编号为 0 。给你一个长度为 n - 1 的二维整数数组 edges 表示这棵树，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 有一条边。

同时给你一个长度为 n 下标从 0 开始的整数数组 values ，其中 values[i] 表示第 i 个节点的值。

一开始你的分数为 0 ，每次操作中，你将执行：

选择节点 i 。
将 values[i] 加入你的分数。
将 values[i] 变为 0 。
如果从根节点出发，到任意叶子节点经过的路径上的节点值之和都不等于 0 ，那么我们称这棵树是 健康的 。

你可以对这棵树执行任意次操作，但要求执行完所有操作以后树是 健康的 ，请你返回你可以获得的 最大分数 。



示例 1：



输入：edges = [[0,1],[0,2],[0,3],[2,4],[4,5]], values = [5,2,5,2,1,1]
输出：11
解释：我们可以选择节点 1 ，2 ，3 ，4 和 5 。根节点的值是非 0 的。所以从根出发到任意叶子节点路径上节点值之和都不为 0 。所以树是健康的。你的得分之和为 values[1] + values[2] + values[3] + values[4] + values[5] = 11 。
11 是你对树执行任意次操作以后可以获得的最大得分之和。
示例 2：



输入：edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [20,10,9,7,4,3,5]
输出：40
解释：我们选择节点 0 ，2 ，3 和 4 。
- 从 0 到 4 的节点值之和为 10 。
- 从 0 到 3 的节点值之和为 10 。
- 从 0 到 5 的节点值之和为 3 。
- 从 0 到 6 的节点值之和为 5 。
所以树是健康的。你的得分之和为 values[0] + values[2] + values[3] + values[4] = 40 。
40 是你对树执行任意次操作以后可以获得的最大得分之和。


提示：

2 <= n <= 2 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
values.length == n
1 <= values[i] <= 109
输入保证 edges 构成一棵合法的树。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adjs(n);

        getAdjs(edges, adjs);
        pair<long long, long long> score = DFS(0, -1, adjs, values);

        return max(score.first, score.second);
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    pair<long long, long long> DFS(int node, int parent, vector<vector<int>>& adjs, vector<int>& values) {
        if (node != 0 && adjs[node].size() == 1) {
            return { 0,0 };  // 叶子节点只能保留
        }

        long long score1 = values[node], score2 = 0;  // 拿走node节点，可以获得积分

        for (int next : adjs[node]) {
            if (next != parent) {
                pair<long long, long long> score = DFS(next, node, adjs, values);
                score1 += max(score.first, score.second);  // 拿走node后，子树必须自己满足条件
                score2 += score.second + values[next];  // 不拿走node，那么所有子树可以全部拿走
            }
        }

        return { score1,score2 };  // 函数返回以node为根节点，{ 拿走、不拿走 }node可以获得的最大得分
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1},{0,2},{0,3},{2,4},{4,5} };
    vector<int> values = { 5,2,5,2,1,1 };
    check.checkLongLong(11, o.maximumScoreAfterOperations(edges, values));

    edges = { {0,1},{0,2},{1,3},{1,4},{2,5},{2,6} };
    values = { 20,10,9,7,4,3,5 };
    check.checkLongLong(40, o.maximumScoreAfterOperations(edges, values));
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
