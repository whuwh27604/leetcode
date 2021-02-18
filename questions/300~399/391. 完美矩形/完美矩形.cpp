/* 完美矩形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们有 N 个与坐标轴对齐的矩形, 其中 N > 0, 判断它们是否能精确地覆盖一个矩形区域。

每个矩形用左下角的点和右上角的点的坐标来表示。例如， 一个单位正方形可以表示为 [1,1,2,2]。 ( 左下角的点的坐标为 (1, 1) 以及右上角的点的坐标为 (2, 2) )。



示例 1:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

返回 true。5个矩形一起可以精确地覆盖一个矩形区域。
 



示例 2:

rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

返回 false。两个矩形之间有间隔，无法覆盖成一个矩形。
 



示例 3:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

返回 false。图形顶端留有间隔，无法覆盖成一个矩形。
 



示例 4:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

返回 false。因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        /* 1、总面积要相等
           2、不能有重叠，不能有空缺，这就意味着除大矩形的4个顶点外，其它所有顶点都要成对出现 */
        int maxX = INT_MIN, maxY = INT_MIN, minX = INT_MAX, minY = INT_MAX;
        long long totalArea = 0;
        unordered_set<unsigned long long> vertexes;

        for (auto& rectangle : rectangles) {
            int x1 = rectangle[0], y1 = rectangle[1], x2 = rectangle[2], y2 = rectangle[3];
            totalArea += ((long long)x2 - x1) * ((long long)y2 - y1);
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            unsigned long long vertex = (((unsigned long long)(unsigned int)x1 << 32) | (unsigned long long)(unsigned int)y1);
            vertexes.count(vertex) == 0 ? (void)vertexes.insert(vertex) : (void)vertexes.erase(vertex);
            vertex = (((unsigned long long)(unsigned int)x2 << 32) | (unsigned long long)(unsigned int)y2);
            vertexes.count(vertex) == 0 ? (void)vertexes.insert(vertex) : (void)vertexes.erase(vertex);
            vertex = (((unsigned long long)(unsigned int)x1 << 32) | (unsigned long long)(unsigned int)y2);
            vertexes.count(vertex) == 0 ? (void)vertexes.insert(vertex) : (void)vertexes.erase(vertex);
            vertex = (((unsigned long long)(unsigned int)x2 << 32) | (unsigned long long)(unsigned int)y1);
            vertexes.count(vertex) == 0 ? (void)vertexes.insert(vertex) : (void)vertexes.erase(vertex);
        }

        return ((long long)maxX - minX) * ((long long)maxY - minY) == totalArea
            && vertexes.size() == 4
            && vertexes.count(((unsigned long long)(unsigned int)minX << 32) | (unsigned long long)(unsigned int)minY) == 1
            && vertexes.count(((unsigned long long)(unsigned int)maxX << 32) | (unsigned long long)(unsigned int)maxY) == 1
            && vertexes.count(((unsigned long long)(unsigned int)minX << 32) | (unsigned long long)(unsigned int)maxY) == 1
            && vertexes.count(((unsigned long long)(unsigned int)maxX << 32) | (unsigned long long)(unsigned int)minY) == 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> rectangles = { {1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4} };
    check.checkBool(true, o.isRectangleCover(rectangles));

    rectangles = { {1,1,2,3},{1,3,2,4},{3,1,4,2},{3,2,4,4} };
    check.checkBool(false, o.isRectangleCover(rectangles));

    rectangles = { {1,1,3,3},{3,1,4,2},{1,3,2,4},{3,2,4,4} };
    check.checkBool(false, o.isRectangleCover(rectangles));

    rectangles = { {1,1,3,3},{3,1,4,2},{1,3,2,4},{2,2,4,4} };
    check.checkBool(false, o.isRectangleCover(rectangles));

    rectangles = { {0,0,1,1},{0,1,1,2},{0,2,1,3},{0,3,1,4} };
    check.checkBool(true, o.isRectangleCover(rectangles));

    rectangles = { {0,0,1,1} };
    check.checkBool(true, o.isRectangleCover(rectangles));

    rectangles = { {0,0,1,1},{1,0,2,1} };
    check.checkBool(true, o.isRectangleCover(rectangles));

    rectangles = { {0,0,4,1},{7,0,8,2},{5,1,6,3},{6,0,7,2},{4,0,5,1},{4,2,5,3},{2,1,4,3},{-1,2,2,3},{0,1,2,2},{6,2,8,3},{5,0,6,1},{4,1,5,2} };
    check.checkBool(false, o.isRectangleCover(rectangles));

    rectangles = { {0,-1,1,0},{0,0,1,1} };
    check.checkBool(true, o.isRectangleCover(rectangles));

    rectangles = getIntVectorVector("./testcase1.txt");
    check.checkBool(true, o.isRectangleCover(rectangles));
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
