/* 用点构造面积最大的矩形 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 points，其中 points[i] = [xi, yi] 表示无限平面上一点的坐标。

你的任务是找出满足以下条件的矩形可能的 最大 面积：

矩形的四个顶点必须是数组中的 四个 点。
矩形的内部或边界上 不能 包含任何其他点。
矩形的边与坐标轴 平行 。
返回可以获得的 最大面积 ，如果无法形成这样的矩形，则返回 -1。



示例 1：

输入： points = [[1,1],[1,3],[3,1],[3,3]]

输出：4

解释：

示例 1 图示

我们可以用这 4 个点作为顶点构成一个矩形，并且矩形内部或边界上没有其他点。因此，最大面积为 4 。

示例 2：

输入： points = [[1,1],[1,3],[3,1],[3,3],[2,2]]

输出：-1

解释：

示例 2 图示

唯一一组可能构成矩形的点为 [1,1], [1,3], [3,1] 和 [3,3]，但点 [2,2] 总是位于矩形内部。因此，返回 -1 。

示例 3：

输入： points = [[1,1],[1,3],[3,1],[3,3],[1,2],[3,2]]

输出：2

解释：

示例 3 图示

点 [1,3], [1,2], [3,2], [3,3] 可以构成面积最大的矩形，面积为 2。此外，点 [1,1], [1,2], [3,1], [3,2] 也可以构成一个符合题目要求的矩形，面积相同。



提示：

1 <= points.length <= 10
points[i].length == 2
0 <= xi, yi <= 100
给定的所有点都是 唯一 的。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Point {
public:
    int x;
    int y;

    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}

    bool operator<(const Point& p) {
        return x == p.x ? y < p.y : x < p.x;
    }
};

class Rectangle {
public:
    Point p1, p2, p3, p4;

    Rectangle(Point& a, Point& b, Point& c, Point& d) : p1(a), p2(b), p3(c), p4(d) {}

    bool isRectangle() {
        return p1.x == p2.x && p3.x == p4.x && p1.y == p3.y && p2.y == p4.y;
    }

    bool inRectangle(Point& p) {
        return p.x >= p1.x && p.x <= p3.x && p.y >= p1.y && p.y <= p2.y;
    }

    int getArea() {
        return (p3.x - p1.x) * (p2.y - p1.y);
    }
};

class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int maxArea = -1;
        int size = (int)points.size();
        vector<Point> ps(size);

        for (int i = 0; i < size; ++i) {
            ps[i] = Point(points[i][0], points[i][1]);
        }

        sort(ps.begin(), ps.end());

        for (int i = 0; i < size - 3; ++i) {
            for (int j = i + 1; j < size - 2; ++j) {
                for (int p = j + 1; p < size - 1; ++p) {
                    for (int q = p + 1; q < size; ++q) {
                        Rectangle r(ps[i], ps[j], ps[p], ps[q]);
                        if (!r.isRectangle()) {
                            continue;
                        }

                        bool inRectangle = false;

                        for (int k = 0; k < size; ++k) {
                            if (k == i || k == j || k == p || k == q) {
                                continue;
                            }

                            if (r.inRectangle(ps[k])) {
                                inRectangle = true;
                                break;
                            }
                        }

                        if (!inRectangle) {
                            maxArea = max(maxArea, r.getArea());
                        }
                    }
                }
            }
        }

        return maxArea;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> points = { {1,1},{1,3},{3,1},{3,3} };
    check.checkInt(4, o.maxRectangleArea(points));

    points = { {1,1},{1,3},{3,1},{3,3},{2,2} };
    check.checkInt(-1, o.maxRectangleArea(points));

    points = { {1,1},{1,3},{3,1},{3,3},{1,2},{3,2} };
    check.checkInt(2, o.maxRectangleArea(points));
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
