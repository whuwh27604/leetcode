﻿/* 安装栅栏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个二维的花园中，有一些用 (x, y) 坐标表示的树。由于安装费用十分昂贵，你的任务是先用最短的绳子围起所有的树。只有当所有的树都被绳子包围时，花园才能围好栅栏。你需要找到正好位于栅栏边界上的树的坐标。

 

示例 1:

输入: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
输出: [[1,1],[2,0],[4,2],[3,3],[2,4]]
解释:

示例 2:

输入: [[1,2],[2,2],[4,2]]
输出: [[1,2],[2,2],[4,2]]
解释:

即使树都在一条直线上，你也需要先用绳子包围它们。
 

注意:

所有的树应当被围在一起。你不能剪断绳子来包围树或者把树分成一组以上。
输入的整数在 0 到 100 之间。
花园至少有一棵树。
所有树的坐标都是不同的。
输入的点没有顺序。输出顺序也没有要求。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/erect-the-fence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Point {
public:
    int x;
    int y;

    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }

    bool operator!=(const Point& p) const {
        return x != p.x || y != p.y;
    }

    bool operator<(const Point& p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
};

struct PointHasher {
    size_t operator()(const Point& p) const {
        return std::hash<unsigned long long>{}(((unsigned long long)((unsigned int)p.x) << 32) + (unsigned long long)((unsigned int)p.y));
    }
};

class Jarvis {
public:
    vector<vector<int>> getExtremePoints(vector<vector<int>>& points) {
        if (points.size() < 4) {
            return points;  // 少于4个点，肯定都是极点
        }

        vector<vector<int>> extremePoints;
        unordered_set<Point, PointHasher> pointsLeft;
        Point LTLPoint = getLowestLeftMost(points, pointsLeft);
        Point p = LTLPoint;

        do {
            auto iter = pointsLeft.begin();
            Point q = (*iter == p ? *(++iter) : *iter);

            for (++iter; iter != pointsLeft.end(); ++iter) {
                if (orientation(p, *iter, q) < 0) {
                    q = *iter;  // 寻找最靠右的连线端点
                }
            }

            extremePoints.push_back({ q.x, q.y });
            pointsLeft.erase(q);

            iter = pointsLeft.begin();
            while (iter != pointsLeft.end()) {
                if (*iter == p || orientation(p, *iter, q) != 0) {
                    ++iter;
                }
                else {  // 和pq同一条直线上的点
                    extremePoints.push_back({ iter->x, iter->y });
                    if (isBetween(p, q, *iter)) {
                        q = *iter;  // q要保持最远端的点
                    }

                    iter = pointsLeft.erase(iter);
                }
            }

            p = q;  // 以q为新的原点再找下一条最靠右的连线
        } while (p != LTLPoint);

        return extremePoints;
    }

    Point getLowestLeftMost(vector<vector<int>>& points, unordered_set<Point, PointHasher>& pointsLeft) {
        Point LTLPoint = { INT_MAX, INT_MAX };

        for (auto& point : points) {
            Point p({ point[0], point[1] });
            pointsLeft.insert(p);
            if (p < LTLPoint) {
                LTLPoint = p;
            }
        }

        return LTLPoint;
    }

    int orientation(const Point& p, const Point& q, const Point& r) {
        return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y- q.y);  // pq在pr右边时，返回负数；同一条直线返回0
    }

    bool isBetween(const Point& p, const Point& q, const Point& r) {  // 判断q是否在p、r之间
        return ((q.x >= p.x && q.x <= r.x) || (q.x <= p.x && q.x >= r.x))
            && ((q.y >= p.y && q.y <= r.y) || (q.y <= p.y && q.y >= r.y));
    }
};

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        Jarvis jarvis;
        return jarvis.getExtremePoints(points);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> points = { {1,1},{2,2},{2,0},{2,4},{3,3},{4,2} };
    vector<vector<int>> actual = o.outerTrees(points);
    vector<vector<int>> expected = { {1,1},{2,0},{4,2},{3,3},{2,4} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    points = { {1,2},{2,2},{4,2} };
    actual = o.outerTrees(points);
    expected = { {1,2},{2,2},{4,2} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    points = { {3,0},{4,0},{5,0},{6,1},{7,2},{7,3},{7,4},{6,5},{5,5},{4,5},{3,5},{2,5},{1,4},{1,3},{1,2},{2,1},{4,2} };
    actual = o.outerTrees(points);
    expected = { {7,2},{6,1},{7,3},{4,0},{1,4},{6,5},{2,1},{5,5},{1,3},{2,5},{1,2},{4,5},{3,5},{3,0},{7,4},{5,0} };
    check.checkIntVectorRandomOrderVector(expected, actual);
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
