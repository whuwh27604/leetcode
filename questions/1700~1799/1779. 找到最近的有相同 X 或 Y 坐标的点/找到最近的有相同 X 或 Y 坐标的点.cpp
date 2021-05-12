/* 找到最近的有相同 X 或 Y 坐标的点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 x 和 y ，表示你在一个笛卡尔坐标系下的 (x, y) 处。同时，在同一个坐标系下给你一个数组 points ，其中 points[i] = [ai, bi] 表示在 (ai, bi) 处有一个点。当一个点与你所在的位置有相同的 x 坐标或者相同的 y 坐标时，我们称这个点是 有效的 。

请返回距离你当前位置 曼哈顿距离 最近的 有效 点的下标（下标从 0 开始）。如果有多个最近的有效点，请返回下标 最小 的一个。如果没有有效点，请返回 -1 。

两个点 (x1, y1) 和 (x2, y2) 之间的 曼哈顿距离 为 abs(x1 - x2) + abs(y1 - y2) 。

 

示例 1：

输入：x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
输出：2
解释：所有点中，[3,1]，[2,4] 和 [4,4] 是有效点。有效点中，[2,4] 和 [4,4] 距离你当前位置的曼哈顿距离最小，都为 1 。[2,4] 的下标最小，所以返回 2 。
示例 2：

输入：x = 3, y = 4, points = [[3,4]]
输出：0
提示：答案可以与你当前所在位置坐标相同。
示例 3：

输入：x = 3, y = 4, points = [[2,3]]
输出：-1
解释：没有有效点。
 

提示：

1 <= points.length <= 104
points[i].length == 2
1 <= x, y, ai, bi <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int i, size = points.size(), index = -1, distance, minDistance = INT_MAX;

        for (i = 0; i < size; ++i) {
            if (points[i][0] == x) {
                distance = abs(points[i][1] - y);
            }
            else if (points[i][1] == y) {
                distance = abs(points[i][0] - x);
            }
            else {
                distance = INT_MAX;
            }

            if (distance < minDistance) {
                minDistance = distance;
                index = i;
            }
        }

        return index;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> points = { {1,2},{3,1},{2,4},{2,3},{4,4} };
    check.checkInt(2, o.nearestValidPoint(3, 4, points));

    points = { {3,4} };
    check.checkInt(0, o.nearestValidPoint(3, 4, points));

    points = { {2,3} };
    check.checkInt(-1, o.nearestValidPoint(3, 4, points));
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
