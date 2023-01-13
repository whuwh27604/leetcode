/* 将节点分成尽可能多的组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n ，表示一个 无向 图中的节点数目，节点编号从 1 到 n 。

同时给你一个二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条 双向 边。注意给定的图可能是不连通的。

请你将图划分为 m 个组（编号从 1 开始），满足以下要求：

图中每个节点都只属于一个组。
图中每条边连接的两个点 [ai, bi] ，如果 ai 属于编号为 x 的组，bi 属于编号为 y 的组，那么 |y - x| = 1 。
请你返回最多可以将节点分为多少个组（也就是最大的 m ）。如果没办法在给定条件下分组，请你返回 -1 。



示例 1：



输入：n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
输出：4
解释：如上图所示，
- 节点 5 在第一个组。
- 节点 1 在第二个组。
- 节点 2 和节点 4 在第三个组。
- 节点 3 和节点 6 在第四个组。
所有边都满足题目要求。
如果我们创建第五个组，将第三个组或者第四个组中任何一个节点放到第五个组，至少有一条边连接的两个节点所属的组编号不符合题目要求。
示例 2：

输入：n = 3, edges = [[1,2],[2,3],[3,1]]
输出：-1
解释：如果我们将节点 1 放入第一个组，节点 2 放入第二个组，节点 3 放入第三个组，前两条边满足题目要求，但第三条边不满足题目要求。
没有任何符合题目要求的分组方式。


提示：

1 <= n <= 500
1 <= edges.length <= 104
edges[i].length == 2
1 <= ai, bi <= n
ai != bi
两个点之间至多只有一条边。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> flags(n + 1, 0);
        vector<vector<int>> adjs(n + 1);
        int groups = 0;

        getAdjs(edges, adjs);

        for (int i = 1; i <= n; ++i) {
            if (flags[i] == 0) {
                vector<int> nodes;
                if (!isBipartite(i, 1, adjs, flags, nodes)) {
                    return -1;
                }

                groups += getMaxGroup(nodes, adjs);
            }
        }

        return groups;
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    bool isBipartite(int node, int flag, vector<vector<int>>& adjs, vector<int>& flags, vector<int>& nodes) {
        flags[node] = flag;
        nodes.push_back(node);

        for (int next : adjs[node]) {
            if (flags[next] == flag) {
                return false;
            }

            if (flags[next] == 0) {
                if (!isBipartite(next, flag == 1 ? 2 : 1, adjs, flags, nodes)) {
                    return false;
                }
            }
        }

        return true;
    }

    int getMaxGroup(vector<int>& nodes, vector<vector<int>>& adjs) {
        int maxGroup = 0;

        for (int node : nodes) {
            maxGroup = max(maxGroup, getMaxGroup(node, adjs));
        }

        return maxGroup;
    }

    int getMaxGroup(int root, vector<vector<int>>& adjs) {
        int group = 0;
        queue<int> nodes;
        nodes.push(root);
        vector<bool> visited(adjs.size(), false);
        visited[root] = true;

        while (!nodes.empty()) {
            int size = nodes.size();
            ++group;

            for (int i = 0; i < size; ++i) {
                int node = nodes.front();
                nodes.pop();

                for (int next : adjs[node]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        nodes.push(next);
                    }
                }
            }
        }

        return group;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {1,2},{1,4},{1,5},{2,6},{2,3},{4,6} };
    check.checkInt(4, o.magnificentSets(6, edges));

    edges = { {1,2},{2,3},{3,1} };
    check.checkInt(-1, o.magnificentSets(3, edges));

    edges = { {1,2},{1,3},{2,4},{3,5},{2,5} };
    check.checkInt(4, o.magnificentSets(5, edges));
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
