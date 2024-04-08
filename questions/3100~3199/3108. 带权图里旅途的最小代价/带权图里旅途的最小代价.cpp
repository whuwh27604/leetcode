/* 带权图里旅途的最小代价.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个节点的带权无向图，节点编号为 0 到 n - 1 。

给你一个整数 n 和一个数组 edges ，其中 edges[i] = [ui, vi, wi] 表示节点 ui 和 vi 之间有一条权值为 wi 的无向边。

在图中，一趟旅途包含一系列节点和边。旅途开始和结束点都是图中的节点，且图中存在连接旅途中相邻节点的边。注意，一趟旅途可能访问同一条边或者同一个节点多次。

如果旅途开始于节点 u ，结束于节点 v ，我们定义这一趟旅途的 代价 是经过的边权按位与 AND 的结果。换句话说，如果经过的边对应的边权为 w0, w1, w2, ..., wk ，那么代价为w0 & w1 & w2 & ... & wk ，其中 & 表示按位与 AND 操作。

给你一个二维数组 query ，其中 query[i] = [si, ti] 。对于每一个查询，你需要找出从节点开始 si ，在节点 ti 处结束的旅途的最小代价。如果不存在这样的旅途，答案为 -1 。

返回数组 answer ，其中 answer[i] 表示对于查询 i 的 最小 旅途代价。



示例 1：

输入：n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]

输出：[1,-1]

解释：



第一个查询想要得到代价为 1 的旅途，我们依次访问：0->1（边权为 7 ）1->2 （边权为 1 ）2->1（边权为 1 ）1->3 （边权为 7 ）。

第二个查询中，无法从节点 3 到节点 4 ，所以答案为 -1 。

示例 2：

输入：n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]

输出：[0]

解释：



第一个查询想要得到代价为 0 的旅途，我们依次访问：1->2（边权为 1 ），2->1（边权 为 6 ），1->2（边权为 1 ）。



提示：

1 <= n <= 105
0 <= edges.length <= 105
edges[i].length == 3
0 <= ui, vi <= n - 1
ui != vi
0 <= wi <= 105
1 <= query.length <= 105
query[i].length == 2
0 <= si, ti <= n - 1
*/

#include <iostream>
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

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        vector<int> costs(n, 0x7fffffff);
        int size = query.size();
        vector<int> ans(size);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            dsu.merge(u, v);
        }

        for (auto& edge : edges) {
            int u = edge[0], w = edge[2];
            costs[dsu.find(u)] &= w;
        }

        for (int i = 0; i < size; ++i) {
            int s = query[i][0], t = query[i][1];
            if (s == t) {
                ans[i] = 0;
            }
            else {
                int set1 = dsu.find(s), set2 = dsu.find(t);
                if (set1 == set2) {
                    ans[i] = costs[set1];
                }
                else {
                    ans[i] = -1;
                }
            }
        }

        return ans;
    }
};

int main()
{
	Solution o;
	CheckResult check;

    vector<vector<int>> edges = { {0,1,7},{1,3,7},{1,2,1} };
    vector<vector<int>> query = { {0,3},{3,4} };
    vector<int> actual = o.minimumCost(5, edges, query);
    vector<int> expected = { 1,-1 };
    check.checkIntVector(expected, actual);

    edges = { {0,2,7},{0,1,15},{1,2,6},{1,2,1} };
    query = { {1,2} };
    actual = o.minimumCost(3, edges, query);
    expected = { 0 };
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
