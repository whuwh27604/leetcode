/* 最少翻转次数使二进制矩阵回文 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的二进制矩阵 grid 。

如果矩阵中一行或者一列从前往后与从后往前读是一样的，那么我们称这一行或者这一列是 回文 的。

你可以将 grid 中任意格子的值 翻转 ，也就是将格子里的值从 0 变成 1 ，或者从 1 变成 0 。

请你返回 最少 翻转次数，使得矩阵 要么 所有行是 回文的 ，要么所有列是 回文的 。



示例 1：

输入：grid = [[1,0,0],[0,0,0],[0,0,1]]

输出：2

解释：



将高亮的格子翻转，得到所有行都是回文的。

示例 2：

输入：grid = [[0,1],[0,1],[0,0]]

输出：1

解释：



将高亮的格子翻转，得到所有列都是回文的。

示例 3：

输入：grid = [[1],[0]]

输出：0

解释：

所有行已经是回文的。



提示：

m == grid.length
n == grid[i].length
1 <= m * n <= 2 * 105
0 <= grid[i][j] <= 1
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        return min(minRowFlips(grid), minColumnFlips(grid));
    }

    int minRowFlips(vector<vector<int>>& grid) {
        int row = (int)grid.size(), column = (int)grid[0].size(), flips = 0;

        for (int r = 0; r < row; ++r) {
            for (int c1 = 0, c2 = column - 1; c1 < c2; ++c1, --c2) {
                if (grid[r][c1] != grid[r][c2]) {
                    ++flips;
                }
            }
        }

        return flips;
    }

    int minColumnFlips(vector<vector<int>>& grid) {
        int row = (int)grid.size(), column = (int)grid[0].size(), flips = 0;

        for (int c = 0; c < column; ++c) {
            for (int r1 = 0, r2 = row - 1; r1 < r2; ++r1, --r2) {
                if (grid[r1][c] != grid[r2][c]) {
                    ++flips;
                }
            }
        }

        return flips;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {1,0,0},{0,0,0},{0,0,1} };
    check.checkInt(2, o.minFlips(grid));

    grid = { {0,1},{0,1},{0,0} };
    check.checkInt(1, o.minFlips(grid));

    grid = { {1},{0} };
    check.checkInt(0, o.minFlips(grid));
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
