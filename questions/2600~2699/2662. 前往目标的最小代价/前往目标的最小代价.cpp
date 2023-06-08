/* 前往目标的最小代价.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 start ，其中 start = [startX, startY] 表示你的初始位置位于二维空间上的 (startX, startY) 。另给你一个数组 target ，其中 target = [targetX, targetY] 表示你的目标位置 (targetX, targetY) 。

从位置 (x1, y1) 到空间中任一其他位置 (x2, y2) 的代价是 |x2 - x1| + |y2 - y1| 。

给你一个二维数组 specialRoads ，表示空间中存在的一些特殊路径。其中 specialRoads[i] = [x1i, y1i, x2i, y2i, costi] 表示第 i 条特殊路径可以从 (x1i, y1i) 到 (x2i, y2i) ，但成本等于 costi 。你可以使用每条特殊路径任意次数。

返回从 (startX, startY) 到 (targetX, targetY) 所需的最小代价。



示例 1：

输入：start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
输出：5
解释：从 (1,1) 到 (4,5) 的最优路径如下：
- (1,1) -> (1,2) ，移动的代价是 |1 - 1| + |2 - 1| = 1 。
- (1,2) -> (3,3) ，移动使用第一条特殊路径，代价是 2 。
- (3,3) -> (3,4) ，移动的代价是 |3 - 3| + |4 - 3| = 1.
- (3,4) -> (4,5) ，移动使用第二条特殊路径，代价是 1 。
总代价是 1 + 2 + 1 + 1 = 5 。
可以证明无法以小于 5 的代价完成从 (1,1) 到 (4,5) 。
示例 2：

输入：start = [3,2], target = [5,7], specialRoads = [[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]
输出：7
解释：最优路径是不使用任何特殊路径，直接以 |5 - 3| + |7 - 2| = 7 的代价从初始位置到达目标位置。


提示：

start.length == target.length == 2
1 <= startX <= targetX <= 105
1 <= startY <= targetY <= 105
1 <= specialRoads.length <= 200
specialRoads[i].length == 5
startX <= x1i, x2i <= targetX
startY <= y1i, y2i <= targetY
1 <= costi <= 105
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

typedef long long LL;

class Point {
public:
    int x;
    int y;

    Point() : x(0), y(0) {}
    Point(int x_, int y_) : x(x_), y(y_) {}
};

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        if (start == target) {
            return 0;
        }

        vector<Point> points;
        unordered_map<LL, int> pointIndices;

        getPoints(start, target, specialRoads, points, pointIndices);
        int n = points.size();
        vector<vector<int>> graph(n, vector<int>(n, 0));
        createGraph(n, points, pointIndices, specialRoads, graph);

        return dijkstra(n, graph);
    }

    void getPoints(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads, vector<Point>& points, unordered_map<LL, int>& pointIndices) {
        pointIndices[((LL)start[0] << 32) | start[1]] = points.size();
        points.push_back(Point(start[0], start[1]));
        pointIndices[((LL)target[0] << 32) | target[1]] = points.size();
        points.push_back(Point(target[0], target[1]));

        for (auto& road : specialRoads) {
            Point p = { road[0],road[1] };
            LL key = ((LL)p.x << 32) | p.y;
            if (pointIndices.count(key) == 0) {
                pointIndices[key] = points.size();
                points.push_back(p);
            }

            p = { road[2],road[3] };
            key = ((LL)p.x << 32) | p.y;
            if (pointIndices.count(key) == 0) {
                pointIndices[key] = points.size();
                points.push_back(p);
            }
        }
    }

    void createGraph(int n, vector<Point>& points, unordered_map<LL, int>& pointIndices, vector<vector<int>>& specialRoads, vector<vector<int>>& graph) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dis = abs(points[i].x - points[j].x) + abs(points[i].y - points[j].y);
                graph[i][j] = dis;
                graph[j][i] = dis;
            }
        }

        for (auto& road : specialRoads) {
            int i = pointIndices[((LL)road[0] << 32) | road[1]], j = pointIndices[((LL)road[2] << 32) | road[3]], dis = road[4];
            graph[i][j] = min(graph[i][j], dis);
        }
    }

    int dijkstra(int n, vector<vector<int>>& graph) {
        vector<bool> visited(n, false);
        vector<int> distance(n, INT_MAX);
        distance[0] = 0;  // 起点的索引是0

        for (int i = 0; i < n; ++i) {
            int current = 0, dis = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && distance[j] < dis) {
                    dis = distance[j];
                    current = j;
                }
            }

            if (current == 1) {  // 终点的索引是1
                break;
            }

            visited[current] = true;

            for (int next = 0; next < n; ++next) {
                distance[next] = min(distance[next], dis + graph[current][next]);
            }
        }

        return distance[1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> start = { 1,1 };
    vector<int> target = { 4,5 };
    vector<vector<int>> specialRoads = { {1,2,3,3,2},{3,4,4,5,1} };
    check.checkInt(5, o.minimumCost(start, target, specialRoads));

    start = { 3,2 };
    target = { 5,7 };
    specialRoads = { {3,2,3,4,4},{3,3,5,5,5},{3,4,5,6,6} };
    check.checkInt(7, o.minimumCost(start, target, specialRoads));

    start = { 1,1 };
    target = { 10,8 };
    specialRoads = { {6,4,9,7,1},{5,2,2,1,3},{3,2,5,5,2} };
    check.checkInt(10, o.minimumCost(start, target, specialRoads));

    start = { 1,3 };
    target = { 4,4 };
    specialRoads = { {2,3,3,3,1},{4,4,1,4,4},{1,3,4,4,1},{1,3,4,4,2} };
    check.checkInt(1, o.minimumCost(start, target, specialRoads));

    start = { 2,1 };
    target = { 6,1 };
    specialRoads = { {3,1,5,1,6},{2,1,6,1,2},{2,1,6,1,3},{6,1,6,1,2},{5,1,6,1,7},{4,1,6,1,6},{4,1,4,1,6},{2,1,2,1,1} };
    check.checkInt(2, o.minimumCost(start, target, specialRoads));

    start = { 1,1 };
    target = { 8,10 };
    specialRoads = { {4,2,1,7,1},{2,10,4,10,1},{7,5,7,7,4},{6,6,3,2,2},{8,1,4,2,4} };
    check.checkInt(14, o.minimumCost(start, target, specialRoads));
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
