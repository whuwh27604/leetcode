/* 统计异或值为给定值的路径数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 m x n 的二维整数数组 grid 和一个整数 k 。

你的任务是统计满足以下 条件 且从左上格子 (0, 0) 出发到达右下格子 (m - 1, n - 1) 的路径数目：

每一步你可以向右或者向下走，也就是如果格子存在的话，可以从格子 (i, j) 走到格子 (i, j + 1) 或者格子 (i + 1, j) 。
路径上经过的所有数字 XOR 异或值必须 等于 k 。
请你返回满足上述条件的路径总数。

由于答案可能很大，请你将答案对 109 + 7 取余 后返回。



示例 1：

输入：grid = [[2, 1, 5], [7, 10, 0], [12, 6, 4]], k = 11

输出：3

解释：

3 条路径分别为：

(0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2)
(0, 0) → (1, 0) → (1, 1) → (1, 2) → (2, 2)
(0, 0) → (0, 1) → (1, 1) → (2, 1) → (2, 2)
示例 2：

输入：grid = [[1, 3, 3, 3], [0, 3, 3, 2], [3, 0, 1, 1]], k = 2

输出：5

解释：

5 条路径分别为：

(0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2) → (2, 3)
(0, 0) → (1, 0) → (1, 1) → (2, 1) → (2, 2) → (2, 3)
(0, 0) → (1, 0) → (1, 1) → (1, 2) → (1, 3) → (2, 3)
(0, 0) → (0, 1) → (1, 1) → (1, 2) → (2, 2) → (2, 3)
(0, 0) → (0, 1) → (0, 2) → (1, 2) → (2, 2) → (2, 3)
示例 3：

输入：grid = [[1, 1, 1, 2], [3, 0, 3, 2], [3, 0, 2, 2]], k = 10

输出：0



提示：

1 <= m == grid.length <= 300
1 <= n == grid[r].length <= 300
0 <= grid[r][c] < 16
0 <= k < 16
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int row = (int)grid.size(), column = (int)grid[0].size(), maxXor = 16, mod = 1000000007;
        vector<vector<vector<int>>> paths(row, vector<vector<int>>(column, vector<int>(maxXor, 0)));
        paths[0][0][grid[0][0]] = 1;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                for (int prevXor = 0; prevXor < maxXor; ++prevXor) {
                    int curXor = prevXor ^ grid[r][c];

                    if (r != 0) {
                        paths[r][c][curXor] = paths[r - 1][c][prevXor];
                    }
                    if (c != 0) {
                        paths[r][c][curXor] += paths[r][c - 1][prevXor];
                        paths[r][c][curXor] %= mod;
                    }
                }
            }
        }

        return paths[row - 1][column - 1][k];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {2,1,5},{7,10,0},{12,6,4} };
    check.checkInt(3, o.countPathsWithXorValue(grid, 11));

    grid = { {1,3,3,3},{0,3,3,2},{3,0,1,1} };
    check.checkInt(5, o.countPathsWithXorValue(grid, 2));

    grid = { {1,1,1,2},{3,0,3,2},{3,0,2,2} };
    check.checkInt(0, o.countPathsWithXorValue(grid, 10));
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
