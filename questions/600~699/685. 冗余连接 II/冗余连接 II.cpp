/* 冗余连接 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在本问题中，有根树指满足以下条件的有向图。该树只有一个根节点，所有其他节点都是该根节点的后继。每一个节点只有一个父节点，除了根节点没有父节点。

输入一个有向图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。 每一个边 的元素是一对 [u, v]，用以表示有向图中连接顶点 u 和顶点 v 的边，其中 u 是 v 的一个父节点。

返回一条能删除的边，使得剩下的图是有N个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。

示例 1:

输入: [[1,2], [1,3], [2,3]]
输出: [2,3]
解释: 给定的有向图如下:
  1
 / \
v   v
2-->3
示例 2:

输入: [[1,2], [2,3], [3,4], [4,1], [1,5]]
输出: [4,1]
解释: 给定的有向图如下:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
注意:

二维数组大小的在3到1000范围内。
二维数组中的每个整数在1到N之间，其中 N 是二维数组的大小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/redundant-connection-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size() + 1, 0);
        init(parents);

        vector<vector<int>> ingree2Edges;
        if (existIngree2(edges, ingree2Edges)) {  // 先找有没有入度是2的节点
            if (isLoop(edges, parents, ingree2Edges[1])) {  // 删除后出现的edge，看看是否成环
                return ingree2Edges[0];
            }
            else {
                return ingree2Edges[1];
            }
        }

        vector<int> redundantEdge;
        findRedundantConnection(edges, parents, redundantEdge);  // 没有入度为2的节点，找成环的最后一个edge

        return redundantEdge;
    }

    void init(vector<int>& parents) {
        for (int i = 0; i < (int)parents.size(); i++) {
            parents[i] = i;
        }
    }

    bool existIngree2(vector<vector<int>>& edges, vector<vector<int>>& ingree2Edges) {
        vector<int> parents(edges.size() + 1, 0);

        for (vector<int>& edge : edges) {
            if (parents[edge[1]] != 0) {
                ingree2Edges.push_back({ parents[edge[1]],edge[1] });  // 先出现的edge
                ingree2Edges.push_back(edge);  // 后出现的edge
                return true;
            }

            parents[edge[1]] = edge[0];
        }

        return false;
    }

    bool isLoop(vector<vector<int>>& edges, vector<int>& parents, vector<int>& deletedEdge) {
        for (vector<int>& edge : edges) {
            if (edge == deletedEdge) {
                continue;
            }

            if (!unionSet(edge, parents)) {
                return true;
            }
        }

        return false;
    }

    void findRedundantConnection(vector<vector<int>>& edges, vector<int>& parents, vector<int>& redundantEdge) {
        for (vector<int>& edge : edges) {
            if (!unionSet(edge, parents)) {
                redundantEdge = edge;
                break;
            }
        }
    }

    int findParent(int x, vector<int>& parents) {
        if (x != parents[x]) {
            parents[x] = findParent(parents[x], parents);  // 找到最新的parent之后注意要更新之
        }

        return parents[x];
    }

    bool unionSet(vector<int>& edge, vector<int>& parents) {
        int x = edge[0], y = edge[1];
        int parentX = findParent(x, parents), parentY = findParent(y, parents);  // 更新节点parent到当前最新
        if (parentX == parentY) {
            return false;  // parent相同说明已经连通了，此次edge再加进来就会形成环路
        }

        parents[parentY] = parentX;  // 两个不同的集合，合并它们
        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> edges = { {1,2},{1,3},{2,3} };
    vector<int> actual = o.findRedundantDirectedConnection(edges);
    vector<int> expected = { 2,3 };
    check.checkIntVector(expected, actual);
    
    edges = { {1,2},{2,3},{3,4},{1,4},{1,5} };
    actual = o.findRedundantDirectedConnection(edges);
    expected = { 1,4 };
    check.checkIntVector(expected, actual);

    edges = { {1,2},{2,4},{4,1},{3,2} };
    actual = o.findRedundantDirectedConnection(edges);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    edges = { {2,4},{4,1},{3,2},{1,2} };
    actual = o.findRedundantDirectedConnection(edges);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    edges = { {1,2},{2,3},{1,3},{1,4},{2,5} };
    actual = o.findRedundantDirectedConnection(edges);
    expected = { 1,3 };
    check.checkIntVector(expected, actual);

    edges = { {1,2},{1,3},{2,3},{1,4},{2,5} };
    actual = o.findRedundantDirectedConnection(edges);
    expected = { 2,3 };
    check.checkIntVector(expected, actual);

    edges = { {1,2},{2,3},{3,1},{1,4} };
    actual = o.findRedundantDirectedConnection(edges);
    expected = { 3,1 };
    check.checkIntVector(expected, actual);

    edges = { {2,1},{3,1},{4,2},{1,4} };
    actual = o.findRedundantDirectedConnection(edges);
    expected = { 2,1 };
    check.checkIntVector(expected, actual);

    edges = { {4,2},{1,5},{5,2},{4,3},{4,1} };
    actual = o.findRedundantDirectedConnection(edges);
    expected = { 5,2 };
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
