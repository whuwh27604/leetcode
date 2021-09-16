/* 统计子岛屿.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 m x n 的二进制矩阵 grid1 和 grid2 ，它们只包含 0 （表示水域）和 1 （表示陆地）。一个 岛屿 是由 四个方向 （水平或者竖直）上相邻的 1 组成的区域。任何矩阵以外的区域都视为水域。

如果 grid2 的一个岛屿，被 grid1 的一个岛屿 完全 包含，也就是说 grid2 中该岛屿的每一个格子都被 grid1 中同一个岛屿完全包含，那么我们称 grid2 中的这个岛屿为 子岛屿 。

请你返回 grid2 中 子岛屿 的 数目 。

 

示例 1：


输入：grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
输出：3
解释：如上图所示，左边为 grid1 ，右边为 grid2 。
grid2 中标红的 1 区域是子岛屿，总共有 3 个子岛屿。
示例 2：


输入：grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
输出：2
解释：如上图所示，左边为 grid1 ，右边为 grid2 。
grid2 中标红的 1 区域是子岛屿，总共有 2 个子岛屿。
 

提示：

m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] 和 grid2[i][j] 都要么是 0 要么是 1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-sub-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int i, j, row = grid1.size(), column = grid1[0].size(), subIslands = 0;

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (grid2[i][j] == 1) {
                    if (DFS(grid1, grid2, i, j)) {
                        ++subIslands;
                    }
                }
            }
        }

        return subIslands;
    }

    bool DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c) {
        int i, row = grid1.size(), column = grid1[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        bool isSubIsland = (grid1[r][c] == 1);

        grid2[r][c] = -1;

        for (i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];

            if (nr >= 0 && nr < row && nc >= 0 && nc < column && grid2[nr][nc] == 1) {
                isSubIsland &= DFS(grid1, grid2, nr, nc);
            }
        }

        return isSubIsland;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid1 = { {1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1} };
    vector<vector<int>> grid2 = { {1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0} };
    check.checkInt(3, o.countSubIslands(grid1, grid2));

    grid1 = { {1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1} };
    grid2 = { {0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1} };
    check.checkInt(2, o.countSubIslands(grid1, grid2));

    grid1 = { {1} };
    grid2 = { {1} };
    check.checkInt(1, o.countSubIslands(grid1, grid2));

    grid1 = { {0} };
    grid2 = { {1} };
    check.checkInt(0, o.countSubIslands(grid1, grid2));
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
