/* 二进制矩阵中翻转最多一次使路径不连通.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的 m x n 二进制 矩阵 grid 。你可以从一个格子 (row, col) 移动到格子 (row + 1, col) 或者 (row, col + 1) ，前提是前往的格子值为 1 。如果从 (0, 0) 到 (m - 1, n - 1) 没有任何路径，我们称该矩阵是 不连通 的。

你可以翻转 最多一个 格子的值（也可以不翻转）。你 不能翻转 格子 (0, 0) 和 (m - 1, n - 1) 。

如果可以使矩阵不连通，请你返回 true ，否则返回 false 。

注意 ，翻转一个格子的值，可以使它的值从 0 变 1 ，或从 1 变 0 。



示例 1：



输入：grid = [[1,1,1],[1,0,0],[1,1,1]]
输出：true
解释：按照上图所示我们翻转蓝色格子里的值，翻转后从 (0, 0) 到 (2, 2) 没有路径。
示例 2：



输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
输出：false
解释：无法翻转至多一个格子，使 (0, 0) 到 (2, 2) 没有路径。


提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
grid[0][0] == grid[m - 1][n - 1] == 1
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        // 第一次DFS失败，说明本身就不联通，直接返回成功。第一次修改了已经访问过的点不可达，第二次DFS失败，说明第一次修改的点中存在割点
        return !DFS(grid, 0, 0) || !DFS(grid, 0, 0);
    }

    bool DFS(vector<vector<int>>& grid, int r, int c) {
        int row = grid.size(), column = grid[0].size();
        if (r == row - 1 && c == column - 1) {
            return true;
        }

        grid[r][c] = 0;

        return (r < row - 1 && grid[r + 1][c] == 1 && DFS(grid, r + 1, c)) || (c < column - 1 && grid[r][c + 1] == 1 && DFS(grid, r, c + 1));
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,1,1},{1,0,0},{1,1,1} };
    check.checkBool(true, o.isPossibleToCutPath(grid));

    grid = { {1,1,0,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,0,1,1} };
    check.checkBool(true, o.isPossibleToCutPath(grid));

    grid = { {1,1,0,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,0,1,1},{1,1,1,1,1,0,1,1},{1,1,1,1,1,0,1,1} };
    check.checkBool(true, o.isPossibleToCutPath(grid));

    grid = { {1,1,1} };
    check.checkBool(true, o.isPossibleToCutPath(grid));

    grid = { {1,0,1} };
    check.checkBool(true, o.isPossibleToCutPath(grid));

    grid = { {1,1,0,1,1,1},{1,1,1,1,0,1},{1,1,1,1,1,1} };
    check.checkBool(true, o.isPossibleToCutPath(grid));

    grid = { {1,1,1},{1,0,1},{1,1,1} };
    check.checkBool(false, o.isPossibleToCutPath(grid));

    grid = { {1,1,1,1},{1,1,1,1},{1,0,1,1},{0,0,1,1} };
    check.checkBool(false, o.isPossibleToCutPath(grid));

    grid = { {1} };
    check.checkBool(false, o.isPossibleToCutPath(grid));

    grid = { {1,1} };
    check.checkBool(false, o.isPossibleToCutPath(grid));
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
