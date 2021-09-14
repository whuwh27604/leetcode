/* 最大的幻方.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个 k x k 的 幻方 指的是一个 k x k 填满整数的方格阵，且每一行、每一列以及两条对角线的和 全部相等 。幻方中的整数 不需要互不相同 。显然，每个 1 x 1 的方格都是一个幻方。

给你一个 m x n 的整数矩阵 grid ，请你返回矩阵中 最大幻方 的 尺寸 （即边长 k）。

 

示例 1：


输入：grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
输出：3
解释：最大幻方尺寸为 3 。
每一行，每一列以及两条对角线的和都等于 12 。
- 每一行的和：5+1+6 = 5+4+3 = 2+7+3 = 12
- 每一列的和：5+5+2 = 1+4+7 = 6+3+3 = 12
- 对角线的和：5+4+3 = 6+4+2 = 12
示例 2：


输入：grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
输出：2
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-magic-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int i, j, row = grid.size(), column = grid[0].size(), maxSide = 1;

        vector<vector<int>> rowPresum(row, vector<int>(column));
        getRowPresum(grid, rowPresum);

        vector<vector<int>> columnPresum(row, vector<int>(column));
        getColumnPresum(grid, columnPresum);

        vector<vector<int>> diagonalPresum(row, vector<int>(column));
        getDiagonalPresum(grid, diagonalPresum);

        vector<vector<int>> backDiagonalPresum(row, vector<int>(column));
        getBackDiagonalPresum(grid, backDiagonalPresum);

        for (i = 0; i < row - 1; ++i) {
            for (j = 0; j < column - 1; ++j) {  // 枚举square的左上顶点
                int side = 2;

                while (i + side - 1 < row && j + side - 1 < column) {  // 枚举square的边长
                    if (isMagicSquare(grid, rowPresum, columnPresum, diagonalPresum, backDiagonalPresum, i, j, side)) {
                        maxSide = max(maxSide, side);
                    }

                    ++side;
                }
            }
        }

        return maxSide;
    }

    void getRowPresum(vector<vector<int>>& grid, vector<vector<int>>& rowPresum) {
        for (int i = 0; i < (int)grid.size(); ++i) {
            int sum = 0;

            for (int j = 0; j < (int)grid[0].size(); ++j) {
                sum += grid[i][j];
                rowPresum[i][j] = sum;
            }
        }
    }

    void getColumnPresum(vector<vector<int>>& grid, vector<vector<int>>& columnPresum) {
        for (int j = 0; j < (int)grid[0].size(); ++j) {
            int sum = 0;

            for (int i = 0; i < (int)grid.size(); ++i) {
                sum += grid[i][j];
                columnPresum[i][j] = sum;
            }
        }
    }

    void getDiagonalPresum(vector<vector<int>>& grid, vector<vector<int>>& diagonalPresum) {
        int i, j, row = grid.size(), column = grid[0].size();

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (i == 0 || j == 0) {
                    diagonalPresum[i][j] = grid[i][j];
                }
                else {
                    diagonalPresum[i][j] = grid[i][j] + diagonalPresum[i - 1][j - 1];
                }
            }
        }
    }

    void getBackDiagonalPresum(vector<vector<int>>& grid, vector<vector<int>>& backDiagonalPresum) {
        int i, j, row = grid.size(), column = grid[0].size();

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (i == 0 || j == column - 1) {
                    backDiagonalPresum[i][j] = grid[i][j];
                }
                else {
                    backDiagonalPresum[i][j] = grid[i][j] + backDiagonalPresum[i - 1][j + 1];
                }
            }
        }
    }

    bool isMagicSquare(vector<vector<int>>& grid, vector<vector<int>>& rowPresum, vector<vector<int>>& columnPresum,
        vector<vector<int>>& diagonalPresum, vector<vector<int>>& backDiagonalPresum, int r, int c, int side) {
        int sum1 = diagonalPresum[r + side - 1][c + side - 1] - diagonalPresum[r][c] + grid[r][c];
        int sum2 = backDiagonalPresum[r + side - 1][c] - backDiagonalPresum[r][c + side - 1] + grid[r][c + side - 1];
        if (sum1 != sum2) {
            return false;
        }

        for (int ds = 0; ds < side; ++ds) {
            sum2 = rowPresum[r + ds][c + side - 1] - rowPresum[r + ds][c] + grid[r + ds][c];
            if (sum1 != sum2) {
                return false;
            }
        }

        for (int ds = 0; ds < side; ++ds) {
            sum2 = columnPresum[r + side - 1][c + ds] - columnPresum[r][c + ds] + grid[r][c + ds];
            if (sum1 != sum2) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4} };
    check.checkInt(3, o.largestMagicSquare(grid));

    grid = { {5,1,3,1},{9,3,3,1},{1,3,3,8} };
    check.checkInt(2, o.largestMagicSquare(grid));

    grid = { {5} };
    check.checkInt(1, o.largestMagicSquare(grid));
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
