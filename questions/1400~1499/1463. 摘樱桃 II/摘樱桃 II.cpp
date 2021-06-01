/* 摘樱桃 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 rows x cols 的矩阵 grid 来表示一块樱桃地。 grid 中每个格子的数字表示你能获得的樱桃数目。

你有两个机器人帮你收集樱桃，机器人 1 从左上角格子 (0,0) 出发，机器人 2 从右上角格子 (0, cols-1) 出发。

请你按照如下规则，返回两个机器人能收集的最多樱桃数目：

从格子 (i,j) 出发，机器人可以移动到格子 (i+1, j-1)，(i+1, j) 或者 (i+1, j+1) 。
当一个机器人经过某个格子时，它会把该格子内所有的樱桃都摘走，然后这个位置会变成空格子，即没有樱桃的格子。
当两个机器人同时到达同一个格子时，它们中只有一个可以摘到樱桃。
两个机器人在任意时刻都不能移动到 grid 外面。
两个机器人最后都要到达 grid 最底下一行。
 

示例 1：



输入：grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
输出：24
解释：机器人 1 和机器人 2 的路径在上图中分别用绿色和蓝色表示。
机器人 1 摘的樱桃数目为 (3 + 2 + 5 + 2) = 12 。
机器人 2 摘的樱桃数目为 (1 + 5 + 5 + 1) = 12 。
樱桃总数为： 12 + 12 = 24 。
示例 2：



输入：grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
输出：28
解释：机器人 1 和机器人 2 的路径在上图中分别用绿色和蓝色表示。
机器人 1 摘的樱桃数目为 (1 + 9 + 5 + 2) = 17 。
机器人 2 摘的樱桃数目为 (1 + 3 + 4 + 3) = 11 。
樱桃总数为： 17 + 11 = 28 。
示例 3：

输入：grid = [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]
输出：22
示例 4：

输入：grid = [[1,1],[1,1]]
输出：4
 

提示：

rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cherry-pickup-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r, c1, c2, row = grid.size(), column = grid[0].size(), base = (column + 2) * (column + 2);
        vector<int> dp(row * base, -1);  // dp[r][c1][c2]
        dp[(column + 2) + column] = grid[0][0] + grid[0][column - 1];  // dp[0][1][column]

        for (r = 1; r < row; ++r) {
            for (c1 = 1; c1 <= column; ++c1) {
                for (c2 = 1; c2 <= column; ++c2) {
                    /* dp[r][c1][c2] = max({ dp[r - 1][c1 - 1][c2 - 1],dp[r - 1][c1 - 1][c2],dp[r - 1][c1 - 1][c2 + 1],dp[r - 1][c1][c2 - 1],
                        dp[r - 1][c1][c2],dp[r - 1][c1][c2 + 1],dp[r - 1][c1 + 1][c2 - 1],dp[r - 1][c1 + 1][c2],dp[r - 1][c1 + 1][c2 + 1] }); */
                    dp[r * base + c1 * (column + 2) + c2] = max({ dp[(r - 1) * base + (c1 - 1) * (column + 2) + c2 - 1],
                        dp[(r - 1) * base + (c1 - 1) * (column + 2) + c2],
                        dp[(r - 1) * base + (c1 - 1) * (column + 2) + c2 + 1],
                        dp[(r - 1) * base + c1 * (column + 2) + c2 - 1],
                        dp[(r - 1) * base + c1 * (column + 2) + c2],
                        dp[(r - 1) * base + c1 * (column + 2) + c2 + 1],
                        dp[(r - 1) * base + (c1 + 1) * (column + 2) + c2 - 1],
                        dp[(r - 1) * base + (c1 + 1) * (column + 2) + c2],
                        dp[(r - 1) * base + (c1 + 1) * (column + 2) + c2 + 1] });

                    if (dp[r * base + c1 * (column + 2) + c2] != -1) {
                        dp[r * base + c1 * (column + 2) + c2] += (grid[r][c1 - 1] + (c1 == c2 ? 0 : grid[r][c2 - 1]));
                    }
                }
            }
        }

        return getCherriesPickup(dp, row, column, base);
    }

    int getCherriesPickup(vector<int>& dp, int row, int column, int base) {
        int maxCherries = 0;

        for (int c1 = 1; c1 <= column; ++c1) {
            for (int c2 = 1; c2 <= column; ++c2) {
                maxCherries = max(maxCherries, dp[(row - 1) * base + c1 * (column + 2) + c2]);
            }
        }

        return maxCherries;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {3,1,1},{2,5,1},{1,5,5},{2,1,1} };
    check.checkInt(24, o.cherryPickup(grid));

    grid = { {1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6} };
    check.checkInt(28, o.cherryPickup(grid));

    grid = { {1,0,0,3},{0,0,0,3},{0,0,3,3},{9,0,3,3} };
    check.checkInt(22, o.cherryPickup(grid));

    grid = { {1,1},{1,1} };
    check.checkInt(4, o.cherryPickup(grid));
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
