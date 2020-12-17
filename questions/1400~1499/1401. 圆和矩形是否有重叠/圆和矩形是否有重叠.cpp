/* 圆和矩形是否有重叠.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个以 (radius, x_center, y_center) 表示的圆和一个与坐标轴平行的矩形 (x1, y1, x2, y2)，其中 (x1, y1) 是矩形左下角的坐标，(x2, y2) 是右上角的坐标。

如果圆和矩形有重叠的部分，请你返回 True ，否则返回 False 。

换句话说，请你检测是否 存在 点 (xi, yi) ，它既在圆上也在矩形上（两者都包括点落在边界上的情况）。

 

示例 1：



输入：radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
输出：true
解释：圆和矩形有公共点 (1,0)
示例 2：



输入：radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
输出：true
示例 3：



输入：radius = 1, x_center = 1, y_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3
输出：true
示例 4：

输入：radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
输出：false
 

提示：

1 <= radius <= 2000
-10^4 <= x_center, y_center, x1, y1, x2, y2 <= 10^4
x1 < x2
y1 < y2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/circle-and-rectangle-overlapping
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if (x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2) {  // 圆在矩形内部
            return true;
        }
        else if (x_center >= x1 && x_center <= x2) {  // 圆在矩形垂直方向
            return (y_center + radius) >= y1 && (y_center - radius) <= y2;
        }
        else if (y_center >= y1 && y_center <= y2) {  // 圆在矩形水平方向
            return (x_center + radius) >= x1 && (x_center - radius) <= x2;
        }
        else {  // 圆在矩形对角线方向，那么矩形的顶点离圆最近
            radius *= radius;
            return distance(x_center, y_center, x1, y1) <= radius || distance(x_center, y_center, x2, y2) <= radius
                || distance(x_center, y_center, x1, y2) <= radius || distance(x_center, y_center, x2, y1) <= radius;
        }
    }

    int distance(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.checkOverlap(1, 0, 0, 1, -1, 3, 1));
    check.checkBool(true, o.checkOverlap(1, 0, 0, -1, 0, 0, 1));
    check.checkBool(true, o.checkOverlap(1, 1, 1, -3, -3, 3, 3));
    check.checkBool(false, o.checkOverlap(1, 1, 1, 1, -3, 2, -1));
    check.checkBool(false, o.checkOverlap(1, -1, 1, 0, -1, 1, 0));
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
