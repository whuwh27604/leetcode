/* 圆形靶内的最大飞镖数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
墙壁上挂着一个圆形的飞镖靶。现在请你蒙着眼睛向靶上投掷飞镖。

投掷到墙上的飞镖用二维平面上的点坐标数组表示。飞镖靶的半径为 r 。

请返回能够落在 任意 半径为 r 的圆形靶内或靶上的最大飞镖数。

 

示例 1：



输入：points = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
输出：4
解释：如果圆形的飞镖靶的圆心为 (0,0) ，半径为 2 ，所有的飞镖都落在靶上，此时落在靶上的飞镖数最大，值为 4 。
示例 2：



输入：points = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
输出：5
解释：如果圆形的飞镖靶的圆心为 (0,4) ，半径为 5 ，则除了 (7,8) 之外的飞镖都落在靶上，此时落在靶上的飞镖数最大，值为 5 。
示例 3：

输入：points = [[-2,0],[2,0],[0,2],[0,-2]], r = 1
输出：1
示例 4：

输入：points = [[1,2],[3,5],[1,-1],[2,3],[4,1],[1,3]], r = 2
输出：4
 

提示：

1 <= points.length <= 100
points[i].length == 2
-10^4 <= points[i][0], points[i][1] <= 10^4
1 <= r <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Point {
public:
    double x;
    double y;

    Point(double x_, double y_) : x(x_), y(y_) {}
};

class Solution {
public:
    int numPoints(vector<vector<int>>& darts, int r) {
        int i, j, size = darts.size(), maxPoints = 1;
        double diam = 2.0 * r;
        vector<Point> points;

        for (auto& dart : darts) {
            points.push_back(Point(dart[0], dart[1]));
        }

        for (i = 0; i < size; ++i) {
            for (j = 0; j < size; ++j) {
                if (i != j && doubleLessEqual(getDistance(points[i], points[j]), diam)) {  // 两点距离小于等于直径才可能在一个圆内
                    Point center = getCenter(points[i], points[j], r);
                    maxPoints = max(maxPoints, countPoints(points, center, r));
                }
            }
        }

        return maxPoints;
    }

    int countPoints(vector<Point>& points, Point& center, double r) {
        int count = 0;

        for (Point& point : points) {
            if (doubleLessEqual(getDistance(center, point), r)) {
                ++count;
            }
        }

        return count;
    }

    double getDistance(Point& p1, Point& p2) {
        double len1 = p1.x - p2.x, len2 = p1.y - p2.y;

        return sqrt(len1 * len1 + len2 * len2);
    }

    Point getCenter(Point& p1, Point& p2, double r) {
        Point dir{ p1.y - p2.y, p2.x - p1.x };
        Point middle{ (p1.x + p2.x) / 2, (p1.y + p2.y) / 2 };
        double distance = getDistance(p1, middle);
        double d = sqrt(r * r - distance * distance);
        double root = sqrt(dir.x * dir.x + dir.y * dir.y);
        double detX = d * dir.x / root;
        double detY = d * dir.y / root;

        return { middle.x + detX, middle.y + detY };
    }

    bool doubleLessEqual(double x, double y) {
        if (fabs(x - y) < 1e-8) {
            return true;
        }

        return x < y;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> darts = { {-2,0},{2,0},{0,2},{0,-2} };
    check.checkInt(4, o.numPoints(darts, 2));

    darts = { {-3,0},{3,0},{2,6},{5,4},{0,9},{7,8} };
    check.checkInt(5, o.numPoints(darts, 5));

    darts = { {-2,0},{2,0},{0,2},{0,-2} };
    check.checkInt(1, o.numPoints(darts, 1));

    darts = { {1,2},{3,5},{1,-1},{2,3},{4,1},{1,3} };
    check.checkInt(4, o.numPoints(darts, 2));

    darts = { {-23,0},{23,22},{15,1},{-15,2},{30,-25},{2,19},{18,12},{9,21},{17,11},{20,-22},{-21,26},{25,0},{-18,15},{16,-18},{-5,-6},{10,4},{18,-20},{-19,-8},{-14,-28},{-5,3},{-16,-10},{-7,1} };
    check.checkInt(15, o.numPoints(darts, 23));

    darts = {{-9,-2},{11,-2},{2,-14},{12,13},{-18,19},{1,-16},{-19,15},{10,-7},{-20,-8},{4,13},{2,5},{-9,0},{-3,13},{11,14},{8,7},{-4,-6},{-15,-16},{-15,14},{15,-6}};
    check.checkInt(13, o.numPoints(darts, 15));
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
