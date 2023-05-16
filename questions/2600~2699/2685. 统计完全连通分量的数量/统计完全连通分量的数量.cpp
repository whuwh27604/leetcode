/* 统计完全连通分量的数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 。现有一个包含 n 个顶点的 无向 图，顶点按从 0 到 n - 1 编号。给你一个二维整数数组 edges 其中 edges[i] = [ai, bi] 表示顶点 ai 和 bi 之间存在一条 无向 边。

返回图中 完全连通分量 的数量。

如果在子图中任意两个顶点之间都存在路径，并且子图中没有任何一个顶点与子图外部的顶点共享边，则称其为 连通分量 。

如果连通分量中每对节点之间都存在一条边，则称其为 完全连通分量 。



示例 1：



输入：n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
输出：3
解释：如上图所示，可以看到此图所有分量都是完全连通分量。
示例 2：



输入：n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
输出：1
解释：包含节点 0、1 和 2 的分量是完全连通分量，因为每对节点之间都存在一条边。
包含节点 3 、4 和 5 的分量不是完全连通分量，因为节点 4 和 5 之间不存在边。
因此，在图中完全连接分量的数量是 1 。


提示：

1 <= n <= 50
0 <= edges.length <= n * (n - 1) / 2
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
不存在重复的边
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjs(n);
        vector<int> visited(n, 0);
        int count = 0;

        getAdjs(edges, adjs);

        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                int size = getComponent(i, adjs, visited);
                if (check(i, size, adjs, visited)) {
                    ++count;
                }
            }
        }

        return count;
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    int getComponent(int node, vector<vector<int>>& adjs, vector<int>& visited) {
        int size = 1;
        visited[node] = 1;

        for (int next : adjs[node]) {
            if (visited[next] == 0) {
                size += getComponent(next, adjs, visited);
            }
        }

        return size;
    }

    bool check(int node, int size, vector<vector<int>>& adjs, vector<int>& visited) {
        if (adjs[node].size() + 1 != size) {
            return false;
        }

        visited[node] = 2;

        for (int next : adjs[node]) {
            if (visited[next] != 2) {
                if (!check(next, size, adjs, visited)) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1},{0,2},{1,2},{3,4} };
    check.checkInt(3, o.countCompleteComponents(6, edges));

    edges = { {0,1},{0,2},{1,2},{3,4},{3,5} };
    check.checkInt(1, o.countCompleteComponents(6, edges));
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
