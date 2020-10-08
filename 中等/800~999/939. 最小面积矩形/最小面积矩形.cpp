/* 最小面积矩形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定在 xy 平面上的一组点，确定由这些点组成的矩形的最小面积，其中矩形的边平行于 x 轴和 y 轴。

如果没有任何矩形，就返回 0。

 

示例 1：

输入：[[1,1],[1,3],[3,1],[3,3],[2,2]]
输出：4
示例 2：

输入：[[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
输出：2
 

提示：

1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
所有的点都是不同的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-area-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> pointsTable;
        hashPoints(points, pointsTable);

        int i, j, size = points.size(), minArea = INT_MAX;

        for (i = 0; i < size - 1; ++i) {  // 枚举所有的对角线顶点
            int x1 = points[i][0], y1 = points[i][1];

            for (j = i + 1; j < size; ++j) {
                int x2 = points[j][0], y2 = points[j][1];

                if ((x1 == x2) || (y1 == y2)) {  // 不构成一对顶点
                    continue;
                }

                if ((pointsTable[x1].count(y2) == 0) || (pointsTable[x2].count(y1) == 0)) {  // 另外一对顶点不存在
                    continue;
                }

                minArea = min(minArea, abs(x1 - x2) * abs(y1 - y2));
            }
        }

        return minArea == INT_MAX ? 0 : minArea;
    }

    void hashPoints(vector<vector<int>>& points, unordered_map<int, unordered_set<int>>& pointsTable) {
        for (vector<int>& point : points) {
            if (pointsTable.count(point[0]) == 0) {
                pointsTable[point[0]] = { point[1] };
            }
            else {
                pointsTable[point[0]].insert(point[1]);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> points = { {1,1},{1,3},{3,1},{3,3},{2,2} };
    check.checkInt(4, o.minAreaRect(points));

    points = { {1,1},{1,3},{3,1},{3,3},{4,1},{4,3} };
    check.checkInt(2, o.minAreaRect(points));

    points = { {1,1} };
    check.checkInt(0, o.minAreaRect(points));

    points = { {1,1},{2,2} };
    check.checkInt(0, o.minAreaRect(points));
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
