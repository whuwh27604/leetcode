/* 连接所有点的最小费用.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。

连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 val 的绝对值。

请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。

 

示例 1：



输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
输出：20
解释：

我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
注意到任意两个点之间只有唯一一条路径互相到达。
示例 2：

输入：points = [[3,12],[-2,5],[-4,1]]
输出：18
示例 3：

输入：points = [[0,0],[1,1],[1,0],[-1,1]]
输出：4
示例 4：

输入：points = [[-1000000,-1000000],[1000000,1000000]]
输出：4000000
示例 5：

输入：points = [[0,0]]
输出：0
 

提示：

1 <= points.length <= 1000
-106 <= xi, yi <= 106
所有点 (xi, yi) 两两不同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-cost-to-connect-all-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int i, j, size = points.size(), minCost = 0;
        int infinity = 1000000000;
        vector<bool> visited(size);
        vector<int> minDistances(size, infinity);
        minDistances[0] = 0;

        for (i = 0; i < size; ++i) {
            int point = -1, minDistance = infinity;

            for (j = 0; j < size; ++j) {
                if (!visited[j] && minDistances[j] < minDistance) {
                    minDistance = minDistances[j];
                    point = j;
                }
            }

            visited[point] = true;
            minCost += minDistance;

            for (j = 0; j < size; ++j) {
                if (!visited[j]) {
                    minDistances[j] = min(minDistances[j], abs(points[j][0] - points[point][0]) + abs(points[j][1] - points[point][1]));
                }
            }
        }

        return minCost;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> points = { {0,0},{2,2},{3,10},{5,2},{7,0} };
    check.checkInt(20, o.minCostConnectPoints(points));

    points = { {3,12},{-2,5},{-4,1} };
    check.checkInt(18, o.minCostConnectPoints(points));

    points = { {0,0},{1,1},{1,0},{-1,1} };
    check.checkInt(4, o.minCostConnectPoints(points));

    points = { {-1000000,-1000000},{1000000,1000000} };
    check.checkInt(4000000, o.minCostConnectPoints(points));

    points = { {0,0} };
    check.checkInt(0, o.minCostConnectPoints(points));
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
