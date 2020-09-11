/* 保持城市天际线.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在二维数组grid中，grid[i][j]代表位于某处的建筑物的高度。 我们被允许增加任何数量（不同建筑物的数量可能不同）的建筑物的高度。 高度 0 也被认为是建筑物。

最后，从新数组的所有四个方向（即顶部，底部，左侧和右侧）观看的“天际线”必须与原始数组的天际线相同。 城市的天际线是从远处观看时，由所有建筑物形成的矩形的外部轮廓。 请看下面的例子。

建筑物高度可以增加的最大总和是多少？

例子：
输入： grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
输出： 35
解释：
The grid is:
[ [3, 0, 8, 4],
  [2, 4, 5, 7],
  [9, 2, 6, 3],
  [0, 3, 1, 0] ]

从数组竖直方向（即顶部，底部）看“天际线”是：[9, 4, 8, 7]
从水平水平方向（即左侧，右侧）看“天际线”是：[8, 7, 9, 3]

在不影响天际线的情况下对建筑物进行增高后，新数组如下：

gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]
说明:

1 < grid.length = grid[0].length <= 50。
 grid[i][j] 的高度范围是： [0, 100]。
一座建筑物占据一个grid[i][j]：换言之，它们是 1 x 1 x grid[i][j] 的长方体。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-increase-to-keep-city-skyline
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> maxEachRow, maxEachColumn;

        getMaxEachRow(grid, maxEachRow);
        getMaxEachColumn(grid, maxEachColumn);

        return increaseGrid(grid, maxEachRow, maxEachColumn);
    }

    void getMaxEachRow(vector<vector<int>>& grid, vector<int>& maxEachRow) {
        int i, j, size = grid.size();

        for (i = 0; i < size; i++) {
            int maxHeight = 0;

            for (j = 0; j < size; j++) {
                maxHeight = max(maxHeight, grid[i][j]);
            }

            maxEachRow.push_back(maxHeight);
        }
    }

    void getMaxEachColumn(vector<vector<int>>& grid, vector<int>& maxEachColumn) {
        int i, j, size = grid.size();

        for (j = 0; j < size; j++) {
            int maxHeight = 0;

            for (i = 0; i < size; i++) {
                maxHeight = max(maxHeight, grid[i][j]);
            }

            maxEachColumn.push_back(maxHeight);
        }
    }

    int increaseGrid(vector<vector<int>>& grid, vector<int>& maxEachRow, vector<int>& maxEachColumn) {
        int i, j, size = grid.size(), increaseHeight = 0;

        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                increaseHeight += (min(maxEachRow[i], maxEachColumn[j]) - grid[i][j]);
            }
        }

        return increaseHeight;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0} };
    check.checkInt(35, o.maxIncreaseKeepingSkyline(grid));

    grid = { {3} };
    check.checkInt(0, o.maxIncreaseKeepingSkyline(grid));

    grid = { {5,5},{5,5} };
    check.checkInt(0, o.maxIncreaseKeepingSkyline(grid));

    grid = { {5,0},{0,0} };
    check.checkInt(0, o.maxIncreaseKeepingSkyline(grid));

    grid = { {5,5},{5,0} };
    check.checkInt(5, o.maxIncreaseKeepingSkyline(grid));

    grid = { {5,0},{0,5} };
    check.checkInt(10, o.maxIncreaseKeepingSkyline(grid));
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
