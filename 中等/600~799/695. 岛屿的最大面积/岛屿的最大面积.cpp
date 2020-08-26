/* 岛屿的最大面积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

 

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

 

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int i, j, row = grid.size(), column = grid[0].size(), maxArea = 0;

        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    DFS(grid, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

    void DFS(vector<vector<int>>& grid, int pointR, int pointC, int& area) {
        int i, row = grid.size(), column = grid[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        area += 1;
        grid[pointR][pointC] = -1;

        for (i = 0; i < 4; i++) {
            int r = pointR + dr[i];
            int c = pointC + dc[i];

            if ((r >= 0) && (r < row) && (c >= 0) && (c < column) && (grid[r][c] == 1)) {
                DFS(grid, r, c, area);
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {0,0,0,0,0,0,0,0} };
    check.checkInt(0, o.maxAreaOfIsland(grid));

    grid = { {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0} };
    check.checkInt(6, o.maxAreaOfIsland(grid));

    grid = {  };
    check.checkInt(0, o.maxAreaOfIsland(grid));

    grid = { {} };
    check.checkInt(0, o.maxAreaOfIsland(grid));

    grid = { {0} };
    check.checkInt(0, o.maxAreaOfIsland(grid));

    grid = { {1} };
    check.checkInt(1, o.maxAreaOfIsland(grid));

    grid = { {1,1,1},{1,1,1},{1,1,1},{1,1,1} };
    check.checkInt(12, o.maxAreaOfIsland(grid));

    grid = { {1,1,1},{1,0,1},{1,0,1},{1,1,1} };
    check.checkInt(10, o.maxAreaOfIsland(grid));
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
