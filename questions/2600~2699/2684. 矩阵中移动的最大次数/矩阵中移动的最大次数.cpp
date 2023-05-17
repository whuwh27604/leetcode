/* 矩阵中移动的最大次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、大小为 m x n 的矩阵 grid ，矩阵由若干 正 整数组成。

你可以从矩阵第一列中的 任一 单元格出发，按以下方式遍历 grid ：

从单元格 (row, col) 可以移动到 (row - 1, col + 1)、(row, col + 1) 和 (row + 1, col + 1) 三个单元格中任一满足值 严格 大于当前单元格的单元格。
返回你在矩阵中能够 移动 的 最大 次数。



示例 1：


输入：grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
输出：3
解释：可以从单元格 (0, 0) 开始并且按下面的路径移动：
- (0, 0) -> (0, 1).
- (0, 1) -> (1, 2).
- (1, 2) -> (2, 3).
可以证明这是能够移动的最大次数。
示例 2：


输入：grid = [[3,2,4],[2,1,9],[1,1,7]]
输出：0
解释：从第一列的任一单元格开始都无法移动。


提示：

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
1 <= grid[i][j] <= 106
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size(), moves = 0;

        for (int r = 0; r < row; ++r) {
            grid[r][0] = -grid[r][0];
        }

        for (int c = 0; c < column - 1; ++c) {
            bool find = false;

            for (int r = 0; r < row; ++r) {
                if (grid[r][c] > 0) {
                    continue;
                }

                grid[r][c] = -grid[r][c];
                if (r != 0 && grid[r][c] < grid[r - 1][c + 1]) {
                    grid[r - 1][c + 1] = -grid[r - 1][c + 1];
                    find = true;
                }
                if (grid[r][c] < grid[r][c + 1]) {
                    grid[r][c + 1] = -grid[r][c + 1];
                    find = true;
                }
                if (r < row - 1 && grid[r][c] < grid[r + 1][c + 1]) {
                    grid[r + 1][c + 1] = -grid[r + 1][c + 1];
                    find = true;
                }
            }

            if (find) {
                ++moves;
            }
            else {
                break;
            }
        }

        return moves;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15} };
    check.checkInt(3, o.maxMoves(grid));

    grid = { {3,2,4},{2,1,9},{1,1,7} };
    check.checkInt(0, o.maxMoves(grid));
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
