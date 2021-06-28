/* 公交路线.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 routes ，表示一系列公交线路，其中每个 routes[i] 表示一条公交线路，第 i 辆公交车将会在上面循环行驶。

例如，路线 routes[0] = [1, 5, 7] 表示第 0 辆公交车会一直按序列 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... 这样的车站路线行驶。
现在从 source 车站出发（初始时不在公交车上），要前往 target 车站。 期间仅可乘坐公交车。

求出 最少乘坐的公交车数量 。如果不可能到达终点车站，返回 -1 。

 

示例 1：

输入：routes = [[1,2,7],[3,6,7]], source = 1, target = 6
输出：2
解释：最优策略是先乘坐第一辆公交车到达车站 7 , 然后换乘第二辆公交车到车站 6 。
示例 2：

输入：routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
输出：-1
 

提示：

1 <= routes.length <= 500.
1 <= routes[i].length <= 105
routes[i] 中的所有值 互不相同
sum(routes[i].length) <= 105
0 <= routes[i][j] < 106
0 <= source, target < 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bus-routes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_set<int> sourceRoutes, targetRoutes;
        int maxStation = getMaxStation(routes, source, sourceRoutes, target, targetRoutes);

        vector<unordered_set<int>> routesAdjs(routes.size());
        buildRoutesAdjs(routes, maxStation, routesAdjs);

        int buses = 0;
        vector<bool> visited(routes.size(), false);
        queue<int> bfs;  // 直接bfs路线而不是站点
        
        for (int sourceRoute : sourceRoutes) {
            bfs.push(sourceRoute);
        }

        while (!bfs.empty()) {
            int i, size = bfs.size();
            ++buses;

            for (i = 0; i < size; ++i) {
                int route = bfs.front();
                bfs.pop();

                if (targetRoutes.count(route) != 0) {
                    return buses;
                }

                for (int adj : routesAdjs[route]) {
                    if (!visited[adj]) {
                        visited[adj] = true;
                        bfs.push(adj);
                    }
                }
            }
        }

        return -1;
    }

    int getMaxStation(vector<vector<int>>& routes, int source, unordered_set<int>& sourceRoutes, int target, unordered_set<int>& targetRoutes) {
        int maxStation = 0;

        for (int route = 0; route < (int)routes.size(); ++route) {
            for (int station : routes[route]) {
                maxStation = max(maxStation, station);

                if (station == source) {
                    sourceRoutes.insert(route);
                }

                if (station == target) {
                    targetRoutes.insert(route);
                }
            }
        }

        return maxStation;
    }

    void buildRoutesAdjs(vector<vector<int>>& routes, int maxStation, vector<unordered_set<int>>& routesAdjs) {
        int route, size = routes.size();
        vector<vector<int>> stationRoutes(maxStation + 1);

        for (route = 0; route < size; ++route) {
            for (int station : routes[route]) {
                stationRoutes[station].push_back(route);  // 站点station和路线route是连通的
            }
        }

        for (route = 0; route < size; ++route) {
            for (int station : routes[route]) {
                for (int adj : stationRoutes[station]) {
                    routesAdjs[route].insert(adj);
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> routes = { {1,2,7},{3,6,7} };
    check.checkInt(2, o.numBusesToDestination(routes, 1, 6));

    routes = { {7,12},{4,5,15},{6},{15,19},{9,12,13} };
    check.checkInt(-1, o.numBusesToDestination(routes, 15, 12));

    routes = { {1,9,12,20,23,24,35,38},{10,21,24,31,32,34,37,38,43},
            {10,19,28,37},{8},{14,19},{11,17,23,31,41,43,44},{21,26,29,33},{5,11,33,41},{4,5,8,9,24,44} };
    check.checkInt(1, o.numBusesToDestination(routes, 37, 28));

    routes = { {1,7},{3,5} };
    check.checkInt(0, o.numBusesToDestination(routes, 5, 5));
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
