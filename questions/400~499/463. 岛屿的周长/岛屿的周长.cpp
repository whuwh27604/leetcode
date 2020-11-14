/* 岛屿的周长.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。

网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

 

示例 :

输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

输出: 16

解释: 它的周长是下面图片中的 16 个黄色的边：



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/island-perimeter
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int landr = 0, landc = 0, perimeter = 0;

        if (findFirstLand(grid, landr, landc) == -1) {
            return 0;
        }

        DFS(grid, landr, landc, perimeter);

        return perimeter;
    }

    int findFirstLand(vector<vector<int>>& grid, int& landr, int& landc) {
        int row = grid.size(), column = grid[0].size();

        for (landr = 0; landr < row; ++landr) {
            for (landc = 0; landc < column; ++landc) {
                if (grid[landr][landc] == 1) {
                    return 0;
                }
            }
        }

        return -1;
    }

    void DFS(vector<vector<int>>& grid, int landr, int landc, int& perimeter) {
        int row = grid.size(), column = grid[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        grid[landr][landc] = -1;

        for (int i = 0; i < 4; ++i) {
            int r = landr + dr[i], c = landc + dc[i];

            if (r < 0 || r >= row || c < 0 || c >= column) {
                ++perimeter;
            }
            else {
                if (grid[r][c] == 0) {
                    ++perimeter;
                }
                else if (grid[r][c] == 1) {
                    DFS(grid, r, c, perimeter);
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0} };
    check.checkInt(16, o.islandPerimeter(grid));

    grid = {  };
    check.checkInt(0, o.islandPerimeter(grid));

    grid = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
    check.checkInt(0, o.islandPerimeter(grid));

    grid = { {1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
    check.checkInt(4, o.islandPerimeter(grid));

    grid = { {0,0,0,0},{0,1,0,0},{0,0,0,0},{0,0,0,0} };
    check.checkInt(4, o.islandPerimeter(grid));

    grid = { {1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
    check.checkInt(10, o.islandPerimeter(grid));

    grid = { {0,0,0,1},{0,0,0,1},{0,0,0,1},{0,0,0,1} };
    check.checkInt(10, o.islandPerimeter(grid));

    grid = { {1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1} };
    check.checkInt(16, o.islandPerimeter(grid));

    grid = { {1,1,0,0},{0,1,1,0},{0,0,1,1},{0,0,0,1} };
    check.checkInt(16, o.islandPerimeter(grid));

    grid = { {0,1,0,0},{1,1,1,0},{0,1,0,0},{0,0,0,0} };
    check.checkInt(12, o.islandPerimeter(grid));

    grid = { {1,1,1,1},{0,0,0,1},{1,1,0,1},{1,1,1,1} };
    check.checkInt(24, o.islandPerimeter(grid));

    grid = { {1,1},{0,1} };
    check.checkInt(8, o.islandPerimeter(grid));
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
