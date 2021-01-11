/* 矩阵的最大非负积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 rows x cols 的矩阵 grid 。最初，你位于左上角 (0, 0) ，每一步，你可以在矩阵中 向右 或 向下 移动。

在从左上角 (0, 0) 开始到右下角 (rows - 1, cols - 1) 结束的所有路径中，找出具有 最大非负积 的路径。路径的积是沿路径访问的单元格中所有整数的乘积。

返回 最大非负积 对 109 + 7 取余 的结果。如果最大积为负数，则返回 -1 。

注意，取余是在得到最大积之后执行的。

 

示例 1：

输入：grid = [[-1,-2,-3],
             [-2,-3,-3],
             [-3,-3,-2]]
输出：-1
解释：从 (0, 0) 到 (2, 2) 的路径中无法得到非负积，所以返回 -1
示例 2：

输入：grid = [[1,-2,1],
             [1,-2,1],
             [3,-4,1]]
输出：8
解释：最大非负积对应的路径已经用粗体标出 (1 * 1 * -2 * -4 * 1 = 8)
示例 3：

输入：grid = [[1, 3],
             [0,-4]]
输出：0
解释：最大非负积对应的路径已经用粗体标出 (1 * 0 * -4 = 0)
示例 4：

输入：grid = [[ 1, 4,4,0],
             [-2, 0,0,1],
             [ 1,-1,1,1]]
输出：2
解释：最大非负积对应的路径已经用粗体标出 (1 * -2 * 1 * -1 * 1 * 1 = 2)
 

提示：

1 <= rows, cols <= 15
-4 <= grid[i][j] <= 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-non-negative-product-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int i, j, row = grid.size(), column = grid[0].size();
        vector<vector<long long>> maxProduct(row, vector<long long>(column)), minProduct(row, vector<long long>(column));

        maxProduct[0][0] = minProduct[0][0] = grid[0][0];

        for (i = 1; i < row; ++i) {
            maxProduct[i][0] = minProduct[i][0] = maxProduct[i - 1][0] * grid[i][0];
        }

        for (j = 1; j < column; ++j) {
            maxProduct[0][j] = minProduct[0][j] = maxProduct[0][j - 1] * grid[0][j];
        }

        for (i = 1; i < row; ++i) {
            for (j = 1; j < column; ++j) {
                if (grid[i][j] < 0) {
                    maxProduct[i][j] = min(minProduct[i - 1][j], minProduct[i][j - 1]) * grid[i][j];
                    minProduct[i][j] = max(maxProduct[i - 1][j], maxProduct[i][j - 1]) * grid[i][j];
                }
                else {
                    maxProduct[i][j] = max(maxProduct[i - 1][j], maxProduct[i][j - 1]) * grid[i][j];
                    minProduct[i][j] = min(minProduct[i - 1][j], minProduct[i][j - 1]) * grid[i][j];
                }
            }
        }

        return maxProduct[row - 1][column - 1] < 0 ? -1 : (int)(maxProduct[row - 1][column - 1] % 1000000007);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {-1,-2,-3},{-2,-3,-3},{-3,-3,-2} };
    check.checkInt(-1, o.maxProductPath(grid));

    grid = { {1,-2,1},{1,-2,1},{3,-4,1} };
    check.checkInt(8, o.maxProductPath(grid));

    grid = { {1,3},{0,-4} };
    check.checkInt(0, o.maxProductPath(grid));

    grid = { { 1,4,4,0},{-2,0,0,1},{1,-1,1,1} };
    check.checkInt(2, o.maxProductPath(grid));
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
