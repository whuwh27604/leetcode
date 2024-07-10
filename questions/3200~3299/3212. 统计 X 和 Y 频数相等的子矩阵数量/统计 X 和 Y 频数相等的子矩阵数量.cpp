/* 统计 X 和 Y 频数相等的子矩阵数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维字符矩阵 grid，其中 grid[i][j] 可能是 'X'、'Y' 或 '.'，返回满足以下条件的
子矩阵
数量：

包含 grid[0][0]
'X' 和 'Y' 的频数相等。
至少包含一个 'X'。


示例 1：

输入： grid = [["X","Y","."],["Y",".","."]]

输出： 3

解释：



示例 2：

输入： grid = [["X","X"],["X","Y"]]

输出： 0

解释：

不存在满足 'X' 和 'Y' 频数相等的子矩阵。

示例 3：

输入： grid = [[".","."],[".","."]]

输出： 0

解释：

不存在满足至少包含一个 'X' 的子矩阵。



提示：

1 <= grid.length, grid[i].length <= 1000
grid[i][j] 可能是 'X'、'Y' 或 '.'.
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int row = (int)grid.size(), column = (int)grid[0].size(), subs = 0;
        vector<vector<int>> countX(row, vector<int>(column, 0)), countY(row, vector<int>(column, 0));
        countX[0][0] = grid[0][0] == 'X' ? 1 : 0;
        countY[0][0] = grid[0][0] == 'Y' ? 1 : 0;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                if (r != 0 || c != 0) {
                    calc(grid, r, c, 'X', countX);
                    calc(grid, r, c, 'Y', countY);

                    if (countX[r][c] == countY[r][c] && countY[r][c] != 0) {
                        ++subs;
                    }
                }
            }
        }

        return subs;
    }

    void calc(vector<vector<char>>& grid, int r, int c, char want, vector<vector<int>>& count) {
        count[r][c] = grid[r][c] == want ? 1 : 0;
        if (r != 0) {
            count[r][c] += count[r - 1][c];
        }
        if (c != 0) {
            count[r][c] += count[r][c - 1];
        }
        if (r != 0 && c != 0) {
            count[r][c] -= count[r - 1][c - 1];
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<char>> grid = { {'X','Y','.'},{'Y','.','.'} };
    check.checkInt(3, o.numberOfSubmatrices(grid));

    grid = { {'X','X'},{'X','Y'} };
    check.checkInt(0, o.numberOfSubmatrices(grid));

    grid = { {'.','.'},{'.','.'} };
    check.checkInt(0, o.numberOfSubmatrices(grid));
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
