/* 一个图中连通三元组的最小度数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个无向图，整数 n 表示图中节点的数目，edges 数组表示图中的边，其中 edges[i] = [ui, vi] ，表示 ui 和 vi 之间有一条无向边。

一个 连通三元组 指的是 三个 节点组成的集合且这三个点之间 两两 有边。

连通三元组的度数 是所有满足此条件的边的数目：一个顶点在这个三元组内，而另一个顶点不在这个三元组内。

请你返回所有连通三元组中度数的 最小值 ，如果图中没有连通三元组，那么返回 -1 。

 

示例 1：


输入：n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
输出：3
解释：只有一个三元组 [1,2,3] 。构成度数的边在上图中已被加粗。
示例 2：


输入：n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
输出：0
解释：有 3 个三元组：
1) [1,4,3]，度数为 0 。
2) [2,5,6]，度数为 2 。
3) [5,6,7]，度数为 2 。
 

提示：

2 <= n <= 400
edges[i].length == 2
1 <= edges.length <= n * (n-1) / 2
1 <= ui, vi <= n
ui != vi
图中没有重复的边。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-degree-of-a-connected-trio-in-a-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../tools/TestData.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> adjMatrix(n + 1, vector<bool>(n + 1, false));
        vector<int> degrees(n + 1);

        for (auto& edge : edges) {
            int node0 = edge[0], node1 = edge[1];
            adjMatrix[node0][node1] = true;
            adjMatrix[node1][node0] = true;
            ++degrees[node0];
            ++degrees[node1];
        }

        return getMinDegree(n, adjMatrix, degrees);
    }

    int getMinDegree(int n, vector<vector<bool>>& adjMatrix, vector<int>& degrees) {
        int minDegree = INT_MAX;

        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k <= n; ++k) {
                    if (adjMatrix[i][j] && adjMatrix[i][k] && adjMatrix[j][k]) {
                        minDegree = min(minDegree, degrees[i] + degrees[j] + degrees[k] - 6);
                    }
                }
            }
        }

        return minDegree == INT_MAX ? -1 : minDegree;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {1,2},{1,3},{3,2},{4,1},{5,2},{3,6} };
    check.checkInt(3, o.minTrioDegree(6, edges));

    edges = { {1,3},{4,1},{4,3},{2,5},{5,6},{6,7},{7,5},{2,6} };
    check.checkInt(0, o.minTrioDegree(7, edges));

    edges = { {1,2},{4,1},{4,2} };
    check.checkInt(0, o.minTrioDegree(4, edges));

    edges = { {3,2},{2,1} };
    check.checkInt(-1, o.minTrioDegree(3, edges));

    edges = getIntVectorVector("./testcase1.txt");
    check.checkInt(1191, o.minTrioDegree(400, edges));
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
