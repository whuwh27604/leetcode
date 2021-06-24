/* 统计子树中城市之间最大距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你 n 个城市，编号为从 1 到 n 。同时给你一个大小为 n-1 的数组 edges ，其中 edges[i] = [ui, vi] 表示城市 ui 和 vi 之间有一条双向边。题目保证任意城市之间只有唯一的一条路径。换句话说，所有城市形成了一棵 树 。

一棵 子树 是城市的一个子集，且子集中任意城市之间可以通过子集中的其他城市和边到达。两个子树被认为不一样的条件是至少有一个城市在其中一棵子树中存在，但在另一棵子树中不存在。

对于 d 从 1 到 n-1 ，请你找到城市间 最大距离 恰好为 d 的所有子树数目。

请你返回一个大小为 n-1 的数组，其中第 d 个元素（下标从 1 开始）是城市间 最大距离 恰好等于 d 的子树数目。

请注意，两个城市间距离定义为它们之间需要经过的边的数目。

 

示例 1：



输入：n = 4, edges = [[1,2],[2,3],[2,4]]
输出：[3,4,0]
解释：
子树 {1,2}, {2,3} 和 {2,4} 最大距离都是 1 。
子树 {1,2,3}, {1,2,4}, {2,3,4} 和 {1,2,3,4} 最大距离都为 2 。
不存在城市间最大距离为 3 的子树。
示例 2：

输入：n = 2, edges = [[1,2]]
输出：[1]
示例 3：

输入：n = 3, edges = [[1,2],[2,3]]
输出：[2,1]
 

提示：

2 <= n <= 15
edges.length == n-1
edges[i].length == 2
1 <= ui, vi <= n
题目保证 (ui, vi) 所表示的边互不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-subtrees-with-max-distance-between-cities
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dist(n, vector<int>(n, 100000));
        vector<int> ans(n - 1, 0);

        init(edges, dist);
        floyd(n, dist);

        for (int state = 2; state < (1 << n); ++state) {  // 枚举所有子集
            int maxDistance = 0, edge = 0;

            for (int x = 0; x < n - 1; ++x) {
                for (int y = x + 1; y < n; ++y) {
                    if ((state & (1 << x)) != 0 && (state & (1 << y)) != 0) {  // 这两个点被选中了
                        maxDistance = max(maxDistance, dist[x][y]);

                        if (dist[x][y] == 1) {
                            edge += 1;
                        }
                    }
                }
            }

            if (edge != 0 && edge == getPoints(state) - 1) {  // 边的数量等于点的数量减1，该子集构成一个树
                ans[maxDistance - 1] += 1;
            }
        }

        return ans;
    }

    void init(vector<vector<int>>& edges, vector<vector<int>>& dist) {
        for (auto& edge : edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            dist[x][y] = 1;
            dist[y][x] = 1;
        }
    }

    void floyd(int n, vector<vector<int>>& dist) {
        for (int k = 0; k < n; ++k) {
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) {
                    dist[x][y] = min(dist[x][y], (dist[x][k] + dist[k][y]));
                }
            }
        }
    }

    int getPoints(int state) {
        int points = 0;

        while (state != 0) {
            state &= (state - 1);
            points += 1;
        }

        return points;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {1,2},{2,3},{2,4} };
    vector<int> actual = o.countSubgraphsForEachDiameter(4, edges);
    vector<int> expected = { 3,4,0 };
    check.checkIntVector(expected, actual);

    edges = { {1,2} };
    actual = o.countSubgraphsForEachDiameter(2, edges);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    edges = { {1,2},{2,3} };
    actual = o.countSubgraphsForEachDiameter(3, edges);
    expected = { 2,1 };
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
