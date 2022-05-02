/* 统计网格图中没有被保卫的格子数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 m 和 n 表示一个下标从 0 开始的 m x n 网格图。同时给你两个二维整数数组 guards 和 walls ，其中 guards[i] = [rowi, coli] 且 walls[j] = [rowj, colj] ，分别表示第 i 个警卫和第 j 座墙所在的位置。

一个警卫能看到 4 个坐标轴方向（即东、南、西、北）的 所有 格子，除非他们被一座墙或者另外一个警卫 挡住 了视线。如果一个格子能被 至少 一个警卫看到，那么我们说这个格子被 保卫 了。

请你返回空格子中，有多少个格子是 没被保卫 的。

 

示例 1：



输入：m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
输出：7
解释：上图中，被保卫和没有被保卫的格子分别用红色和绿色表示。
总共有 7 个没有被保卫的格子，所以我们返回 7 。
示例 2：



输入：m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
输出：4
解释：上图中，没有被保卫的格子用绿色表示。
总共有 4 个没有被保卫的格子，所以我们返回 4 。
 

提示：

1 <= m, n <= 105
2 <= m * n <= 105
1 <= guards.length, walls.length <= 5 * 104
2 <= guards.length + walls.length <= m * n
guards[i].length == walls[j].length == 2
0 <= rowi, rowj < m
0 <= coli, colj < n
guards 和 walls 中所有位置 互不相同 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-unguarded-cells-in-the-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        setWall(grid, walls);
        setGuard(grid, guards);
        guard(grid, guards, m, n);

        return getUnguarded(grid);
    }

    void setWall(vector<vector<int>>& grid, vector<vector<int>>& walls) {
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 4;
        }
    }

    void setGuard(vector<vector<int>>& grid, vector<vector<int>>& guards) {
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 3;
        }
    }

    void guard(vector<vector<int>>& grid, vector<vector<int>>& guards, int m, int n) {
        for (auto& guard : guards) {
            int row = guard[0], column = guard[1], r, c;

            for (r = row - 1; r >= 0 && grid[r][column] != 4 && (grid[r][column] & 1) == 0; --r) {
                grid[r][column] |= 1;
            }

            for (r = row + 1; r < m && grid[r][column] != 4 && (grid[r][column] & 1) == 0; ++r) {
                grid[r][column] |= 1;
            }

            for (c = column - 1; c >= 0 && grid[row][c] != 4 && (grid[row][c] & 2) == 0; --c) {
                grid[row][c] |= 2;
            }

            for (c = column + 1; c < n && grid[row][c] != 4 && (grid[row][c] & 2) == 0; ++c) {
                grid[row][c] |= 2;
            }
        }
    }

    int getUnguarded(vector<vector<int>>& grid) {
        int count = 0;

        for (auto& row : grid) {
            for (int column : row) {
                if (column == 0) {
                    ++count;
                }
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> guards = { {0,0},{1,1},{2,3} };
    vector<vector<int>> walls = { {0,1},{2,2},{1,4} };
    check.checkInt(7, o.countUnguarded(4, 6, guards, walls));

    guards = { {1,1} };
    walls = { {0,1},{1,0},{2,1},{1,2} };
    check.checkInt(4, o.countUnguarded(3, 3, guards, walls));
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
