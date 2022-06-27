/* 统计无向图中无法互相到达点对数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n ，表示一张 无向图 中有 n 个节点，编号为 0 到 n - 1 。同时给你一个二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条 无向 边。

请你返回 无法互相到达 的不同 点对数目 。

 

示例 1：



输入：n = 3, edges = [[0,1],[0,2],[1,2]]
输出：0
解释：所有点都能互相到达，意味着没有点对无法互相到达，所以我们返回 0 。
示例 2：



输入：n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
输出：14
解释：总共有 14 个点对互相无法到达：
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]]
所以我们返回 14 。
 

提示：

1 <= n <= 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ai, bi < n
ai != bi
不会有重复边。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjs(n);
        vector<bool> visited(n, false);
        vector<int> counts;

        getAdjs(edges, adjs);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                counts.push_back(DFS(i, adjs, visited));
            }
        }

        return getPairs(n, counts);
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    int DFS(int root, vector<vector<int>>& adjs, vector<bool>& visited) {
        visited[root] = true;
        int count = 0;

        for (int next : adjs[root]) {
            if (!visited[next]) {
                count += DFS(next, adjs, visited);
            }
        }

        return count + 1;
    }

    long long getPairs(int n, vector<int>& counts) {
        long long pairs = ((long long)n - 1) * n / 2;

        for (int count : counts) {
            pairs -= ((long long)count - 1) * count / 2;
        }

        return pairs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1},{0,2},{1,2} };
    check.checkLongLong(0, o.countPairs(3, edges));

    edges = { {0,2},{0,5},{2,4},{1,6},{5,4} };
    check.checkLongLong(14, o.countPairs(7, edges));
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
