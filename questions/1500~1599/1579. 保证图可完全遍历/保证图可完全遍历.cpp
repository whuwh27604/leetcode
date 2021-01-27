/* 保证图可完全遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 和 Bob 共有一个无向图，其中包含 n 个节点和 3  种类型的边：

类型 1：只能由 Alice 遍历。
类型 2：只能由 Bob 遍历。
类型 3：Alice 和 Bob 都可以遍历。
给你一个数组 edges ，其中 edges[i] = [typei, ui, vi] 表示节点 ui 和 vi 之间存在类型为 typei 的双向边。请你在保证图仍能够被 Alice和 Bob 完全遍历的前提下，找出可以删除的最大边数。如果从任何节点开始，Alice 和 Bob 都可以到达所有其他节点，则认为图是可以完全遍历的。

返回可以删除的最大边数，如果 Alice 和 Bob 无法完全遍历图，则返回 -1 。

 

示例 1：



输入：n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
输出：2
解释：如果删除 [1,1,2] 和 [1,1,3] 这两条边，Alice 和 Bob 仍然可以完全遍历这个图。再删除任何其他的边都无法保证图可以完全遍历。所以可以删除的最大边数是 2 。
示例 2：



输入：n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
输出：0
解释：注意，删除任何一条边都会使 Alice 和 Bob 无法完全遍历这个图。
示例 3：



输入：n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
输出：-1
解释：在当前图中，Alice 无法从其他节点到达节点 4 。类似地，Bob 也不能达到节点 1 。因此，图无法完全遍历。
 

提示：

1 <= n <= 10^5
1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)
edges[i].length == 3
1 <= edges[i][0] <= 3
1 <= edges[i][1] < edges[i][2] <= n
所有元组 (typei, ui, vi) 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsu(n + 1);

        int commonEdges = mergeVertexes(edges, 3, dsu);
        DSU backDsu = dsu;

        int aliceEdges = mergeVertexes(edges, 1, dsu);
        if (commonEdges + aliceEdges != n - 1) {
            return -1;
        }

        int bobEdges = mergeVertexes(edges, 2, backDsu);
        return commonEdges + bobEdges == n - 1 ? (int)edges.size() - commonEdges - aliceEdges - bobEdges : -1;
    }

    int mergeVertexes(vector<vector<int>>& edges, int type, DSU& dsu) {
        int count = 0;

        for (auto& edge : edges) {
            if (edge[0] != type) {
                continue;
            }

            if (dsu.find(edge[1]) == dsu.find(edge[2])) {
                continue;
            }

            dsu.merge(edge[1], edge[2]);
            ++count;
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4} };
    check.checkInt(2, o.maxNumEdgesToRemove(4, edges));

    edges = { {3,1,2},{3,2,3},{1,1,4},{2,1,4} };
    check.checkInt(0, o.maxNumEdgesToRemove(4, edges));

    edges = { {3,2,3},{1,1,2},{2,3,4} };
    check.checkInt(-1, o.maxNumEdgesToRemove(4, edges));

    edges = { {1,1,2},{2,1,3},{3,2,4},{3,2,5},{1,2,6},{3,6,7},{3,7,8},{3,6,9},{3,4,10},{2,3,11},{1,5,12},{3,3,13},{2,1,10},{2,6,11},{3,5,13},{1,9,12},{1,6,8},{3,6,13},{2,1,4},{1,1,13},{2,9,10},{2,1,6},{2,10,13},{2,2,9},{3,4,12},{2,4,7},{1,1,10},{1,3,7},{1,7,11},{3,3,12},{2,4,8},{3,8,9},{1,9,13},{2,4,10},{1,6,9},{3,10,13},{1,7,10},{1,1,11},{2,4,9},{3,5,11},{3,2,6},{2,1,5},{2,5,11},{2,1,7},{2,3,8},{2,8,9},{3,4,13},{3,3,8},{3,3,11},{2,9,11},{3,1,8},{2,1,8},{3,8,13},{2,10,11},{3,1,5},{1,10,11},{1,7,12},{2,3,5},{3,1,13},{2,4,11},{2,3,9},{2,6,9},{2,1,13},{3,1,12},{2,7,8},{2,5,6},{3,1,9},{1,5,10},{3,2,13},{2,3,6},{2,2,10},{3,4,11},{1,4,13},{3,5,10},{1,4,10},{1,1,8},{3,3,4},{2,4,6},{2,7,11},{2,7,10},{2,3,12},{3,7,11},{3,9,10},{2,11,13},{1,1,12},{2,10,12},{1,7,13},{1,4,11},{2,4,5},{1,3,10},{2,12,13},{3,3,10},{1,6,12},{3,6,10},{1,3,4},{2,7,9},{1,3,11},{2,2,8},{1,2,8},{1,11,13},{1,2,13},{2,2,6},{1,4,6},{1,6,11},{3,1,2},{1,1,3},{2,11,12},{3,2,11},{1,9,10},{2,6,12},{3,1,7},{1,4,9},{1,10,12},{2,6,13},{2,2,12},{2,1,11},{2,5,9},{1,3,8},{1,7,8},{1,2,12},{1,5,11},{2,7,12},{3,1,11},{3,9,12},{3,2,9},{3,10,11} };
    check.checkInt(114, o.maxNumEdgesToRemove(13, edges));
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
