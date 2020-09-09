/* 所有可能的路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给一个有 n 个结点的有向无环图，找到所有从 0 到 n-1 的路径并输出（不要求按顺序）

二维数组的第 i 个数组中的单元都表示有向图中 i 号结点所能到达的下一些结点（译者注：有向图是有方向的，即规定了a→b你就不能从b→a）空就是没有下一个结点了。

示例:
输入: [[1,2], [3], [3], []]
输出: [[0,1,3],[0,2,3]]
解释: 图是这样的:
0--->1
|    |
v    v
2--->3
这有两条路: 0 -> 1 -> 3 和 0 -> 2 -> 3.
提示:

结点的数量会在范围 [2, 15] 内。
你可以把路径以任意顺序输出，但在路径内的结点的顺序必须保证。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-paths-from-source-to-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        DFS(graph, 0, graph.size() - 1, {}, allPaths);

        return allPaths;
    }

    void DFS(vector<vector<int>>& graph, int source, int target, vector<int> path, vector<vector<int>>& allPaths) {
        path.push_back(source);

        if (source == target) {
            allPaths.push_back(path);
            return;
        }

        for (int next : graph[source]) {
            DFS(graph, next, target, path, allPaths);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> graph = { {1,2},{3},{3},{} };
    vector<vector<int>> actual = o.allPathsSourceTarget(graph);
    vector<vector<int>> expected = { {0,1,3},{0,2,3} };
    check.checkIntVectorVector(expected, actual);

    graph = { {3,1},{4,6,7,2,5},{4,6,3},{6,4},{7,6,5},{6},{7},{} };
    actual = o.allPathsSourceTarget(graph);
    expected = { {0,3,6,7},{0,3,4,7},{0,3,4,6,7},{0,3,4,5,6,7},{0,1,4,7},{0,1,4,6,7},{0,1,4,5,6,7},{0,1,6,7},{0,1,7},{0,1,2,4,7},
        {0,1,2,4,6,7},{0,1,2,4,5,6,7},{0,1,2,6,7},{0,1,2,3,6,7},{0,1,2,3,4,7},{0,1,2,3,4,6,7},{0,1,2,3,4,5,6,7},{0,1,5,6,7} };
    check.checkIntVectorVector(expected, actual);

    graph = { {1},{} };
    actual = o.allPathsSourceTarget(graph);
    expected = { {0,1} };
    check.checkIntVectorVector(expected, actual);

    graph = { {},{} };
    actual = o.allPathsSourceTarget(graph);
    expected = {  };
    check.checkIntVectorVector(expected, actual);
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
