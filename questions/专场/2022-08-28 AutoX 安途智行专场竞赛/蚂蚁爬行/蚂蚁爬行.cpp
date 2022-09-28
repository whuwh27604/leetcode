/* 蚂蚁爬行.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一张稿纸上画了若干由线条构成的的线段和正圆形。geometry[i] 表示对于第 i 个线条有：

若 geometry[i].length 为 4 ，表示为一条线段，[x1, y1, x2, y2] 表示该线段的两个端点坐标分别为 (x1,y1) 和 (x2,y2)。
若 geometry[i].length 为 3 ，表示为一个正圆形，[x, y, r] 表示其圆心坐标和半径分别为 (x,y) 和 r
现有一群小蚂蚁在这些线条上爬行，path[i] = [start, end] 表示第 i 只蚂蚁从第 start 个线条前往第 end 个线条。在爬行过程中，对于任意两个线条，只要有接触（公共点），小蚂蚁就能从一个爬到另一个。请判断这些小蚂蚁能否到达各自的目的地。
示例 1：

输入：
geometry = [[2,5,7,3],[1,1,4,2],[4,3,2]]
path = [[0,1],[1,2],[0,2]]

输出：[true,true,true]

解释：如下图所示：
所有的几何对象都是可互通的，所有蚂蚁都可以到达目的地。
image.png

示例 2：

输入：
geometry = [[4,1,1],[3,2,1],[1,4,5,4]]
path = [[0,1],[2,0]]

输出：[true,false]

解释：如下图所示:
geometry[0] 和 geometry[1] 相接触，geometry[2] 不与任何几何对象接触，因此蚂蚁 1 无法到达，
image.png

提示：

2 <= geometry.length <= 1000
0 <= geometry[i][0],geometry[i][1] <= 10^5
对于线段，0 <= geometry[i][2],geometry[i][3] <= 10^5
对于正圆形，1 <= geometry[i][2] <= 10^5
1 <= path.length <= 1000
0 <= path[i][0], path[i][1] < geometry.length
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

typedef long long LL;

class DSU {
public:
    DSU(int size) {
        parents.resize(size);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        parents[find(x)] = find(y);
    }

private:
    vector<int> parents;
};

class Solution {
public:
    vector<bool> antPass(vector<vector<int>>& geometry, vector<vector<int>>& path) {
        DSU dsu(geometry.size());

        connect(geometry, dsu);

        return getAns(path, dsu);
    }

    void connect(vector<vector<int>>& geometry, DSU& dsu) {
        for (int i = 0; i < (int)geometry.size() - 1; ++i) {
            for (int j = i + 1; j < (int)geometry.size(); ++j) {
                auto& g1 = geometry[i], & g2 = geometry[j];
                int len1 = g1.size(), len2 = g2.size();

                if ((len1 == 3 && len2 == 3 && is2CirclesCross(g1[0], g1[1], g1[2], g2[0], g2[1], g2[2]))
                    || (len1 == 4 && len2 == 4 && is2SegmentsCross(g1[0], g1[1], g1[2], g1[3], g2[0], g2[1], g2[2], g2[3]))
                    || (len1 == 3 && len2 == 4 && isCircleSegmentCross(g1[0], g1[1], g1[2], g2[0], g2[1], g2[2], g2[3]))
                    || (len1 == 4 && len2 == 3 && isCircleSegmentCross(g2[0], g2[1], g2[2], g1[0], g1[1], g1[2], g1[3]))) {
                    dsu.merge(i, j);
                }
            }
        }
    }

    vector<bool> getAns(vector<vector<int>>& path, DSU& dsu) {
        int size = path.size();
        vector<bool> ans(size);

        for (int i = 0; i < size; ++i) {
            ans[i] = dsu.find(path[i][0]) == dsu.find(path[i][1]);
        }

        return ans;
    }

    bool is2CirclesCross(LL x1, LL y1, LL r1, LL x2, LL y2, LL r2) {  // 两圆相交，圆心的距离要大于等于半径之差，小于等于半径之和
        LL centerDist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        LL minDist = (r1 - r2) * (r1 - r2);
        LL maxDist = (r1 + r2) * (r1 + r2);

        return centerDist >= minDist && centerDist <= maxDist;
    }

    // 两线段相交，1、在x、y轴的投影都必须有交点；2、两线段都必须满足一条线段的两个端点在另外一条线段的两侧
    bool is2SegmentsCross(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3, LL x4, LL y4) {
        if (min(x1, x2) > max(x3, x4) || max(x1, x2) < min(x3, x4) || min(y1, y2) > max(y3, y4) || max(y1, y2) < min(y3, y4)) {
            return false;
        }

        return (crossProduct(x1, y1, x2, y2, x3, y3) * crossProduct(x1, y1, x2, y2, x4, y4) <= 0)
            && (crossProduct(x3, y3, x4, y4, x1, y1) * crossProduct(x3, y3, x4, y4, x2, y2) <= 0);
    }

    bool isCircleSegmentCross(LL x0, LL y0, LL r, LL x1, LL y1, LL x2, LL y2) {
        double dr = (double)r, dist1 = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)), dist2 = sqrt((x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0));

        if (dist1 < r && dist2 < r) {  // 两点都在圆内
            return false;
        }

        if ((doubleCompare(dist1, dr) <= 0 && doubleCompare(dist2, dr) >= 0) || (doubleCompare(dist1, dr) >= 0 && doubleCompare(dist2, dr) <= 0)) {  // 一点在圆内，一点在圆外
            return true;
        }

        // 两点都在圆外，求直线表达式ax + by + c = 0;
        LL a = 0, b = 0, c = 0;
        if (x1 == x2) {
            a = 1, b = 0, c = -x1;
        }
        else if (y1 == y2) {
            a = 0, b = 1, c = -y1;
        }
        else {  // 非平行于坐标轴的直线，(x - x1) / (x2 - x1) = (y - y1) / (y2 - y1) --> (y2 - y1)x + (x1 - x2)y + x2y1 - y2x1 = 0
            a = y2 - y1, b = x1 - x2, c = x2 * y1 - x1 * y2;
        }

        // 点到直线距离公式：dist = abs((ax0 + by0 + c) / sqrt(a * a + b * b))，x0、y0是圆心坐标
        if (fabs((a * x0 + b * y0 + c) / sqrt(a * a + b * b)) > dr) {  // 圆心到直线的距离大于半径，肯定不相交
            return false;
        }

        // cosA = dotProduct(b, c) / (module(b) * module(c))，大于0为锐角，小于0为钝角
        LL angle1 = dotProduct(x1, y1, x0, y0, x2, y2), angle2 = dotProduct(x2, y2, x0, y0, x1, y1);

        return angle1 >= 0 && angle2 >= 0;  // 点到直线的距离小于等于半径，并且两个角都是锐角（直角），则圆和线段有交点
    }

    // 求向量p0->p1、p0->p2的叉积，如果：叉积大于0，p0->p1在p0->p2的顺时针方向；叉积小于0，p0->p1在p0->p2的逆时针方向；叉积等于0，则p0->p1、p0->p2共线。
    LL crossProduct(LL x0, LL y0, LL x1, LL y1, LL x2, LL y2) {
        return (x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0);
    }

    // 求向量p0->p1、p0->p2的点积，如果：点积大于0，角p1p0p2是锐角；点积等于0，角p1p0p2是直角；点积小于0，角p1p0p2是钝角
    LL dotProduct(LL x0, LL y0, LL x1, LL y1, LL x2, LL y2) {
        return (x1 - x0) * (x2 - x0) + (y1 - y0) * (y2 - y0);
    }

    int doubleCompare(double x, double y) {
        if (fabs(x - y) < 1e-8) {
            return 0;
        }

        return x > y ? 1 : -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> geometry = { {2,5,7,3},{1,1,4,2},{4,3,2} };
    vector<vector<int>> path = { {0,1},{1,2},{0,2} };
    vector<bool> actual = o.antPass(geometry, path);
    vector<bool> expected = { true,true,true };
    check.checkBoolVector(expected, actual);

    geometry = { {4,1,1},{3,2,1},{1,4,5,4} };
    path = { {0,1},{2,0} };
    actual = o.antPass(geometry, path);
    expected = { true,false };
    check.checkBoolVector(expected, actual);

    geometry = getIntVectorVector("./testcase1_geometry.txt");
    path = getIntVectorVector("./testcase1_path.txt");;
    actual = o.antPass(geometry, path);
    expected = { true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,false,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,false,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,false,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,false,false,false,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true };
    check.checkBoolVector(expected, actual);
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
