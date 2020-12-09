/* 阈值距离内邻居最少的城市.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 个城市，按从 0 到 n-1 编号。给你一个边数组 edges，其中 edges[i] = [fromi, toi, weighti] 代表 fromi 和 toi 两个城市之间的双向加权边，距离阈值是一个整数 distanceThreshold。

返回能通过某些路径到达其他城市数目最少、且路径距离 最大 为 distanceThreshold 的城市。如果有多个这样的城市，则返回编号最大的城市。

注意，连接城市 i 和 j 的路径的距离等于沿该路径的所有边的权重之和。

 

示例 1：



输入：n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
输出：3
解释：城市分布图如上。
每个城市阈值距离 distanceThreshold = 4 内的邻居城市分别是：
城市 0 -> [城市 1, 城市 2] 
城市 1 -> [城市 0, 城市 2, 城市 3] 
城市 2 -> [城市 0, 城市 1, 城市 3] 
城市 3 -> [城市 1, 城市 2] 
城市 0 和 3 在阈值距离 4 以内都有 2 个邻居城市，但是我们必须返回城市 3，因为它的编号最大。
示例 2：



输入：n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
输出：0
解释：城市分布图如上。 
每个城市阈值距离 distanceThreshold = 2 内的邻居城市分别是：
城市 0 -> [城市 1] 
城市 1 -> [城市 0, 城市 4] 
城市 2 -> [城市 3, 城市 4] 
城市 3 -> [城市 2, 城市 4]
城市 4 -> [城市 1, 城市 2, 城市 3] 
城市 0 在阈值距离 4 以内只有 1 个邻居城市。
 

提示：

2 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti, distanceThreshold <= 10^4
所有 (fromi, toi) 都是不同的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        init(edges, dp);
        floyd(n, dp);

        return getSmallestNeighbourCity(n, distanceThreshold, dp);
    }

    void init(vector<vector<int>>& edges, vector<vector<int>>& dp) {
        for (vector<int>& edge : edges) {
            dp[edge[0]][edge[1]] = edge[2];
            dp[edge[1]][edge[0]] = edge[2];
        }
    }

    void floyd(int n, vector<vector<int>>& dp) {  // Floyd插点法，dp[i][j]表示i到j之间的最短距离
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i != j && dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
        }
    }

    int getSmallestNeighbourCity(int n, int distanceThreshold, vector<vector<int>>& dp) {
        int minNeighbours = INT_MAX, smallestNeighbourCity = n - 1;

        for (int i = 0; i < n; ++i) {
            int neighbours = 0;

            for (int j = 0; j < n; ++j) {
                if (i != j && dp[i][j] <= distanceThreshold) {
                    ++neighbours;
                }
            }

            if (neighbours <= minNeighbours) {
                minNeighbours = neighbours;
                smallestNeighbourCity = i;
            }
        }

        return smallestNeighbourCity;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1,3},{1,2,1},{1,3,4},{2,3,1} };
    check.checkInt(3, o.findTheCity(4, edges, 4));

    edges = { {0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1} };
    check.checkInt(0, o.findTheCity(5, edges, 2));

    edges = { {0,3,7},{2,4,1},{0,1,5},{2,3,10},{1,3,6},{1,2,1} };
    check.checkInt(5, o.findTheCity(6, edges, 417));
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
