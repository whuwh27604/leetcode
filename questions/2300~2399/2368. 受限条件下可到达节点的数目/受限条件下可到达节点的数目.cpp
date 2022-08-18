/* 受限条件下可到达节点的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现有一棵由 n 个节点组成的无向树，节点编号从 0 到 n - 1 ，共有 n - 1 条边。

给你一个二维整数数组 edges ，长度为 n - 1 ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条边。另给你一个整数数组 restricted 表示 受限 节点。

在不访问受限节点的前提下，返回你可以从节点 0 到达的 最多 节点数目。

注意，节点 0 不 会标记为受限节点。

 

示例 1：


输入：n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
输出：4
解释：上图所示正是这棵树。
在不访问受限节点的前提下，只有节点 [0,1,2,3] 可以从节点 0 到达。
示例 2：


输入：n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
输出：3
解释：上图所示正是这棵树。
在不访问受限节点的前提下，只有节点 [0,5,6] 可以从节点 0 到达。
 

提示：

2 <= n <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges 表示一棵有效的树
1 <= restricted.length < n
1 <= restricted[i] < n
restricted 中的所有值 互不相同

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reachable-nodes-with-restrictions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool> valid(n, true), visited(n, false);
        vector<vector<int>> adjs(n);

        setValid(restricted, valid);
        getAdjs(edges, adjs);

        return DFS(0, adjs, valid, visited);
    }

    void setValid(vector<int>& restricted, vector<bool>& valid) {
        for (int node : restricted) {
            valid[node] = false;
        }
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    int DFS(int node, vector<vector<int>>& adjs, vector<bool>& valid, vector<bool>& visited) {
        int count = 1;
        visited[node] = true;

        for (int next : adjs[node]) {
            if (valid[next] && !visited[next]) {
                count += DFS(next, adjs, valid, visited);
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1},{1,2},{3,1},{4,0},{0,5},{5,6} };
    vector<int> restricted = { 4,5 };
    check.checkInt(4, o.reachableNodes(7, edges, restricted));

    edges = { {0,1},{0,2},{0,5},{0,4},{3,2},{6,5} };
    restricted = { 4,2,1 };
    check.checkInt(3, o.reachableNodes(7, edges, restricted));
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
