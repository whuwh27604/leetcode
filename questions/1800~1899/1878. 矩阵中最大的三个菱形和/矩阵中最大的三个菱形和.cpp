/* 矩阵中最大的三个菱形和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的整数矩阵 grid 。

菱形和 指的是 grid 中一个正菱形 边界 上的元素之和。本题中的菱形必须为正方形旋转45度，且四个角都在一个格子当中。下图是四个可行的菱形，每个菱形和应该包含的格子都用了相应颜色标注在图中。


 

注意，菱形可以是一个面积为 0 的区域，如上图中右下角的紫色菱形所示。

请你按照 降序 返回 grid 中三个最大的 互不相同的菱形和 。如果不同的和少于三个，则将它们全部返回。

 

示例 1：


输入：grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
输出：[228,216,211]
解释：最大的三个菱形和如上图所示。
- 蓝色：20 + 3 + 200 + 5 = 228
- 红色：200 + 2 + 10 + 4 = 216
- 绿色：5 + 200 + 4 + 2 = 211
示例 2：


输入：grid = [[1,2,3],[4,5,6],[7,8,9]]
输出：[20,9,8]
解释：最大的三个菱形和如上图所示。
- 蓝色：4 + 2 + 6 + 8 = 20
- 红色：9 （右下角红色的面积为 0 的菱形）
- 绿色：8 （下方中央面积为 0 的菱形）
示例 3：

输入：grid = [[7,7,7]]
输出：[7]
解释：所有三个可能的菱形和都相同，所以返回 [7] 。
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 100
1 <= grid[i][j] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/get-biggest-three-rhombus-sums-in-a-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int i, j, k, row = grid.size(), column = grid[0].size();
        int first = 0, second = 0, third = 0;

        vector<vector<int>> diagonalPresum(row, vector<int>(column));
        getDiagonalPresum(grid, diagonalPresum);

        vector<vector<int>> backDiagonalPresum(row, vector<int>(column));
        getBackDiagonalPresum(grid, backDiagonalPresum);

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {  // 枚举菱形的中心点
                int sum = grid[i][j];

                for (k = 0; i - k >= 0 && i + k < row && j - k >= 0 && j + k < column; ++k) {  // 枚举菱形的半径
                    if (k != 0) {
                        int up = i - k, down = i + k, left = j - k, right = j + k;
                        sum = diagonalPresum[i][right] - diagonalPresum[up][j]
                            + backDiagonalPresum[down][j] - backDiagonalPresum[i][right]
                            + diagonalPresum[down][j] - diagonalPresum[i][left] - grid[down][j]
                            + backDiagonalPresum[i][left] - backDiagonalPresum[up][j] + grid[up][j];
                    }

                    if (sum > first) {
                        third = second;
                        second = first;
                        first = sum;
                    }
                    else if (sum == first) {
                        continue;
                    }
                    else if (sum > second) {
                        third = second;
                        second = sum;
                    }
                    else if (sum == second) {
                        continue;
                    }
                    else if (sum > third) {
                        third = sum;
                    }
                }
            }
        }

        vector<int> biggestThree = { first };

        if (second != 0) {
            biggestThree.push_back(second);
        }
        if (third != 0) {
            biggestThree.push_back(third);
        }

        return biggestThree;
    }

    void getDiagonalPresum(vector<vector<int>>& grid, vector<vector<int>>& diagonalPresum) {
        int i, j, r, c, row = grid.size(), column = grid[0].size(), sum;

        for (j = 0; j < column; ++j) {
            sum = 0, r = 0, c = j;

            while (r < row && c < column) {
                sum += grid[r][c];
                diagonalPresum[r++][c++] = sum;
            }
        }

        for (i = 1; i < row; ++i) {
            sum = 0, r = i, c = 0;

            while (r < row && c < column) {
                sum += grid[r][c];
                diagonalPresum[r++][c++] = sum;
            }
        }
    }

    void getBackDiagonalPresum(vector<vector<int>>& grid, vector<vector<int>>& backDiagonalPresum) {
        int i, j, r, c, row = grid.size(), column = grid[0].size(), sum;

        for (j = 0; j < column; ++j) {
            sum = 0, r = 0, c = j;

            while (r < row && c >= 0) {
                sum += grid[r][c];
                backDiagonalPresum[r++][c--] = sum;
            }
        }

        for (i = 1; i < row; ++i) {
            sum = 0, r = i, c = column - 1;

            while (r < row && c >= 0) {
                sum += grid[r][c];
                backDiagonalPresum[r++][c--] = sum;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5} };
    vector<int> actual = o.getBiggestThree(grid);
    vector<int> expected = { 228,216,211 };
    check.checkIntVector(expected, actual);

    grid = { {1,2,3},{4,5,6},{7,8,9} };
    actual = o.getBiggestThree(grid);
    expected = { 20,9,8 };
    check.checkIntVector(expected, actual);

    grid = { {7,7,7} };
    actual = o.getBiggestThree(grid);
    expected = { 7 };
    check.checkIntVector(expected, actual);
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
