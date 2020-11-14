/* 边框着色.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个二维整数网格 grid，网格中的每个值表示该位置处的网格块的颜色。

只有当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一连通分量。

连通分量的边界是指连通分量中的所有与不在分量中的正方形相邻（四个方向上）的所有正方形，或者在网格的边界上（第一行/列或最后一行/列）的所有正方形。

给出位于 (r0, c0) 的网格块和颜色 color，使用指定颜色 color 为所给网格块的连通分量的边界进行着色，并返回最终的网格 grid 。

 

示例 1：

输入：grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
输出：[[3, 3], [3, 2]]
示例 2：

输入：grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
输出：[[1, 3, 3], [2, 3, 3]]
示例 3：

输入：grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
输出：[[2, 2, 2], [2, 1, 2], [2, 2, 2]]
 

提示：

1 <= grid.length <= 50
1 <= grid[0].length <= 50
1 <= grid[i][j] <= 1000
0 <= r0 < grid.length
0 <= c0 < grid[0].length
1 <= color <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coloring-a-border
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int origColor = grid[r0][c0];
        vector<vector<int>> ans = grid;

        DFS(ans, r0, c0, origColor);
        colorGrid(grid, ans, origColor, color);

        return ans;
    }

    void DFS(vector<vector<int>>& grid, int r0, int c0, int origColor) {
        int row = grid.size(), column = grid[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        
        grid[r0][c0] = -1;

        for (int i = 0; i < 4; ++i) {
            int r = r0 + dr[i], c = c0 + dc[i];

            if (r >= 0 && r < row && c >= 0 && c < column && grid[r][c] == origColor) {
                DFS(grid, r, c, origColor);
            }
        }
    }

    void colorGrid(vector<vector<int>>& grid, vector<vector<int>>& ans, int origColor, int setColor) {
        int i, j, k, row = grid.size(), column = grid[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (ans[i][j] != -1) {
                    continue;
                }

                for (k = 0; k < 4; ++k) {
                    int r = i + dr[k], c = j + dc[k];
                    if (r < 0 || r >= row || c < 0 || c >= column || grid[r][c] != origColor) {
                        ans[i][j] = setColor;
                        break;
                    }
                }

                if (k == 4) {
                    ans[i][j] = origColor;
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,1},{1,2} };
    vector<vector<int>> actual = o.colorBorder(grid, 0, 0, 3);
    vector<vector<int>> expected = { {3,3},{3,2} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1,2,2},{2,3,2} };
    actual = o.colorBorder(grid, 0, 1, 3);
    expected = { {1,3,3},{2,3,3} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1,2,2},{2,3,2} };
    actual = o.colorBorder(grid, 0, 1, 2);
    expected = { {1,2,2},{2,3,2} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1,1,1},{1,1,1},{1,1,1} };
    actual = o.colorBorder(grid, 1, 1, 2);
    expected = { {2,2,2},{2,1,2},{2,2,2} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1,0},{0,1} };
    actual = o.colorBorder(grid, 0, 0, 2);
    expected = { {2,0},{0,1} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1} };
    actual = o.colorBorder(grid, 0, 0, 1);
    expected = { {1} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1} };
    actual = o.colorBorder(grid, 0, 0, 2);
    expected = { {2} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1} };
    actual = o.colorBorder(grid, 0, 0, 2);
    expected = { {2,2,2,2,2},{2,1,1,1,2},{2,1,1,1,2},{2,1,1,1,2},{2,2,2,2,2} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1,1,1,1,1},{1,0,1,0,1},{1,1,1,1,1},{1,0,1,0,1},{1,1,1,1,1} };
    actual = o.colorBorder(grid, 0, 0, 2);
    expected = { {2,2,2,2,2},{2,0,2,0,2},{2,2,1,2,2},{2,0,2,0,2},{2,2,2,2,2} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1,2,1,2,1,2},{2,2,2,2,1,2},{1,2,2,2,1,2} };
    actual = o.colorBorder(grid, 1, 3, 1);
    expected = { {1,1,1,1,1,2},{1,2,1,1,1,2},{1,1,1,1,1,2} };
    check.checkIntVectorVector(expected, actual);
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
