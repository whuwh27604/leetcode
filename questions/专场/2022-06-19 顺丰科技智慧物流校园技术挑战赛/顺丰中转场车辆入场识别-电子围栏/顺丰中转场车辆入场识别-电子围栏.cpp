/* 顺丰中转场车辆入场识别-电子围栏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
【背景】
物流站点的王经理需要对进出站点的物流车辆进行管理，王经理需要通过车载定位知道某物流车辆是否在某个划定的区域内，如果物流车辆超出指定的区域，系统会自动发送提醒信息给王经理，王经理可以通过提醒信息来监管具体情况。

【问题】
几何计算简化如下：
点（x，y） 为车辆所在坐标点，coords[x1,y1,x2,y2,x3,y3,x4,x4,....,x1,y1]为连续封闭区域坐标点。

现给定连续封闭坐标点的一维数组coords[n]和车辆坐标(x,y)，
返回车辆是否在封闭区域coords内（用例不包含点在多边形边界线的情况）。

【示例】
image.png

输入：
x = 1, y = 3,
coords = [0,0,0,4,4,4,2,2,4,0,0,0]
输出：true
提示

0 < coords.length < 1000
0 < coords[i] < 10000.0
0 < x < 10000.0
0 < y < 10000.0
用例保证点不会出现在多边形边界线上
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Point {
public:
    double x;
    double y;

    Point() : x(0.0), y(0.0) {}
    Point(double _x, double _y) : x(_x), y(_y) {}

    Point operator-(const Point& p) {
        return Point(x - p.x, y - p.y);
    }

    double sqlrt() {
        return sqrt(x * x + y * y);
    }
};

class Solution {
public:
    bool isPointInPolygon(double x, double y, vector<double>& coords) {
        Point vehicle(x, y);
        vector<Point> points;

        for (int i = 0; i < (int)coords.size(); i += 2) {
            points.push_back(Point(coords[i], coords[i + 1]));
        }

        return check(vehicle, points);
    }

    int doubleCompare(double x) {
        if (abs(x) < 1e-8) {
            return 0;
        }

        return x > 0 ? 1 : -1;
    }

    double dotProduct(Point& p1, Point& p2, Point& p0) {
        Point p = p1 - p0;
        Point q = p2 - p0;

        return p.x * q.x + p.y * q.y;
    }

    double crossProduct(Point& p1, Point& p2, Point& p0) {
        Point p = p1 - p0;
        Point q = p2 - p0;

        return p.x * q.y - p.y * q.x;
    }

    bool pointInLine(Point& p1, Point& p2, Point& p0) {
        return doubleCompare(crossProduct(p1, p2, p0)) == 0 && doubleCompare(dotProduct(p1, p2, p0)) <= 0;
    }

    bool check(Point& vehicle, vector<Point>& points) {
        int count = 0;  // 从vehicle发出任一射线，如果vehicle在内部，会和所有边相交奇数次；如果vehicle在外边，会和所有边相交偶数次。

        for (int i = 0; i < (int)points.size() - 1; ++i) {
            if (pointInLine(points[i], points[i + 1], vehicle)) {
                return false;
            }

            int f0 = doubleCompare(crossProduct(points[i], points[i + 1], vehicle));
            int f1 = doubleCompare(points[i].y - vehicle.y);
            int f2 = doubleCompare(points[i + 1].y - vehicle.y);

            if (f0 > 0 && f1 <= 0 && f2 > 0) {
                ++count;
            }
            else if (f0 < 0 && f2 <= 0 && f1 > 0) {
                --count;
            }
        }

        return count != 0;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<double> coords = { 0,0,0,4,4,4,2,2,4,0,0,0 };
    check.checkBool(true, o.isPointInPolygon(1, 3, coords));
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
