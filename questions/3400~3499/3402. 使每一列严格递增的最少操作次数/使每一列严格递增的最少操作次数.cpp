/* 使每一列严格递增的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 非负 整数组成的 m x n 矩阵 grid。

在一次操作中，你可以将任意元素 grid[i][j] 的值增加 1。

返回使 grid 的所有列 严格递增 所需的 最少 操作次数。



示例 1：

输入: grid = [[3,2],[1,3],[3,4],[0,1]]

输出: 15

解释:

为了让第 0 列严格递增，可以对 grid[1][0] 执行 3 次操作，对 grid[2][0] 执行 2 次操作，对 grid[3][0] 执行 6 次操作。
为了让第 1 列严格递增，可以对 grid[3][1] 执行 4 次操作。

示例 2：

输入: grid = [[3,2,1],[2,1,0],[1,2,3]]

输出: 12

解释:

为了让第 0 列严格递增，可以对 grid[1][0] 执行 2 次操作，对 grid[2][0] 执行 4 次操作。
为了让第 1 列严格递增，可以对 grid[1][1] 执行 2 次操作，对 grid[2][1] 执行 2 次操作。
为了让第 2 列严格递增，可以对 grid[1][2] 执行 2 次操作。



提示:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
0 <= grid[i][j] < 2500
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int row = (int)grid.size(), column = (int)grid[0].size(), opers = 0;

        for (int c = 0; c < column; ++c) {
            int wanted = 0;

            for (int r = 0; r < row; ++r) {
                if (grid[r][c] >= wanted) {
                    wanted = grid[r][c] + 1;
                }
                else {
                    opers += (wanted - grid[r][c]);
                    ++wanted;
                }
            }
        }

        return opers;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {3,2},{1,3},{3,4},{0,1} };
    check.checkInt(15, o.minimumOperations(grid));

    grid = { {3,2,1},{2,1,0},{1,2,3} };
    check.checkInt(12, o.minimumOperations(grid));
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
