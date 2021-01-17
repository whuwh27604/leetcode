/* 三维形体投影面积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在 N * N 的网格中，我们放置了一些与 x，y，z 三轴对齐的 1 * 1 * 1 立方体。

每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格 (i, j) 上。

现在，我们查看这些立方体在 xy、yz 和 zx 平面上的投影。

投影就像影子，将三维形体映射到一个二维平面上。

在这里，从顶部、前面和侧面看立方体时，我们会看到“影子”。

返回所有三个投影的总面积。

 

示例 1：

输入：[[2]]
输出：5
示例 2：

输入：[[1,2],[3,4]]
输出：17
解释：
这里有该形体在三个轴对齐平面上的三个投影(“阴影部分”)。

示例 3：

输入：[[1,0],[0,2]]
输出：8
示例 4：

输入：[[1,1,1],[1,0,1],[1,1,1]]
输出：14
示例 5：

输入：[[2,2,2],[2,1,2],[2,2,2]]
输出：21
 

提示：

1 <= grid.length = grid[0].length <= 50
0 <= grid[i][j] <= 50

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/projection-area-of-3d-shapes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        unsigned int i, j;
        int maxNumber, totalArea = 0;

        for (i = 0; i < grid.size(); i++) {
            maxNumber = 0;
            for (j = 0; j < grid[0].size(); j++) {
                maxNumber = max(maxNumber, grid[i][j]);
                if (grid[i][j] != 0) {
                    totalArea++;
                }
            }
            totalArea += maxNumber;
        }

        for (i = 0; i < grid[0].size(); i++) {
            maxNumber = 0;
            for (j = 0; j < grid.size(); j++) {
                maxNumber = max(maxNumber, grid[j][i]);
            }
            totalArea += maxNumber;
        }

        return totalArea;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {2} };
    check.checkInt(5, o.projectionArea(grid));

    grid = { {0} };
    check.checkInt(0, o.projectionArea(grid));

    grid = { {1,2},{3,4} };
    check.checkInt(17, o.projectionArea(grid));

    grid = { {1,0},{0,2} };
    check.checkInt(8, o.projectionArea(grid));

    grid = { {1,1,1},{1,0,1},{1,1,1} };
    check.checkInt(14, o.projectionArea(grid));

    grid = { {2,2,2},{2,1,2},{2,2,2} };
    check.checkInt(21, o.projectionArea(grid));
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
