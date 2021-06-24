/* 穿过迷宫的最少移动次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你还记得那条风靡全球的贪吃蛇吗？

我们在一个 n*n 的网格上构建了新的迷宫地图，蛇的长度为 2，也就是说它会占去两个单元格。蛇会从左上角（(0, 0) 和 (0, 1)）开始移动。我们用 0 表示空单元格，用 1 表示障碍物。蛇需要移动到迷宫的右下角（(n-1, n-2) 和 (n-1, n-1)）。

每次移动，蛇可以这样走：

如果没有障碍，则向右移动一个单元格。并仍然保持身体的水平／竖直状态。
如果没有障碍，则向下移动一个单元格。并仍然保持身体的水平／竖直状态。
如果它处于水平状态并且其下面的两个单元都是空的，就顺时针旋转 90 度。蛇从（(r, c)、(r, c+1)）移动到 （(r, c)、(r+1, c)）。

如果它处于竖直状态并且其右面的两个单元都是空的，就逆时针旋转 90 度。蛇从（(r, c)、(r+1, c)）移动到（(r, c)、(r, c+1)）。

返回蛇抵达目的地所需的最少移动次数。

如果无法到达目的地，请返回 -1。

 

示例 1：



输入：grid = [[0,0,0,0,0,1],
               [1,1,0,0,1,0],
               [0,0,0,0,1,1],
               [0,0,1,0,1,0],
               [0,1,1,0,0,0],
               [0,1,1,0,0,0]]
输出：11
解释：
一种可能的解决方案是 [右, 右, 顺时针旋转, 右, 下, 下, 下, 下, 逆时针旋转, 右, 下]。
示例 2：

输入：grid = [[0,0,1,1,1,1],
               [0,0,0,0,1,1],
               [1,1,0,0,0,1],
               [1,1,1,0,0,1],
               [1,1,1,0,0,1],
               [1,1,1,0,0,0]]
输出：9
 

提示：

2 <= n <= 100
0 <= grid[i][j] <= 1
蛇保证从空单元格开始出发。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-moves-to-reach-target-with-rotations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Snake {
public:
    int r1;
    int c1;
    int r2;
    int c2;
    int dir;  // 0 : invalid, 1 : horizontal, 2 : vertical
    vector<vector<int>>* grid;

    Snake() : r1(0), c1(0), r2(0), c2(0), dir(0), grid(0) {}
    Snake(int _r1, int _c1, int _r2, int _c2, int _dir, vector<vector<int>>* _grid) : r1(_r1), c1(_c1), r2(_r2), c2(_c2), dir(_dir), grid(_grid) {}

    bool operator==(const Snake& snake) const {
        return r1 == snake.r1 && c1 == snake.c1 && r2 == snake.r2 && c2 == snake.c2;
    }

    Snake moveRight() {
        if (dir == 1) {
            if ((*grid)[r2][c2 + 1] == 0) {
                return Snake(r2, c2, r2, c2 + 1, dir, grid);
            }
        }
        else {
            if ((*grid)[r1][c1 + 1] == 0 && (*grid)[r2][c2 + 1] == 0) {
                return Snake(r1, c1 + 1, r2, c2 + 1, dir, grid);
            }
        }

        return Snake();
    }

    Snake moveDown() {
        if (dir == 1) {
            if ((*grid)[r1 + 1][c1] == 0 && (*grid)[r2 + 1][c2] == 0) {
                return Snake(r1 + 1, c1, r2 + 1, c2, dir, grid);
            }
        }
        else {
            if ((*grid)[r2 + 1][c2] == 0) {
                return Snake(r2, c2, r2 + 1, c2, dir, grid);
            }
        }

        return Snake();
    }

    Snake rotateClockwise() {
        if (dir == 1 && (*grid)[r1 + 1][c1] == 0 && (*grid)[r2 + 1][c2] == 0) {
            return Snake(r1, c1, r1 + 1, c1, 2, grid);
        }

        return Snake();
    }

    Snake rotateCounterclockwise() {
        if (dir == 2 && (*grid)[r1][c1 + 1] == 0 && (*grid)[r2][c2 + 1] == 0) {
            return Snake(r1, c1, r1, c1 + 1, 1, grid);
        }

        return Snake();
    }
};

struct SnakeHasher {
    size_t operator()(const Snake& s) const {
        return std::hash<unsigned int>{}((((unsigned int)s.r1) << 24) + (((unsigned int)s.c1) << 16) + (((unsigned int)s.r2) << 8) + (unsigned int)s.c2);
    }
};

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size(), moves = 0;
        if (grid[n - 1][n - 2] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        vector<vector<int>> newGrid(n + 2, vector<int>(n + 2, 1));
        copyGrid(grid, newGrid);

        Snake start(1, 1, 1, 2, 1, &newGrid), target(n, n - 1, n, n, 0, 0);
        queue<Snake> bfs;
        bfs.push(start);
        unordered_set<Snake, SnakeHasher> visited;
        visited.insert(start);

        while (!bfs.empty()) {
            int i, size = bfs.size();

            for (i = 0; i < size; ++i) {
                Snake snake = bfs.front();
                bfs.pop();

                if (snake == target) {
                    return moves;
                }

                Snake next = snake.moveRight();
                if (next.dir != 0 && visited.count(next) == 0) {
                    visited.insert(next);
                    bfs.push(next);
                }

                next = snake.moveDown();
                if (next.dir != 0 && visited.count(next) == 0) {
                    visited.insert(next);
                    bfs.push(next);
                }

                next = snake.rotateClockwise();
                if (next.dir != 0 && visited.count(next) == 0) {
                    visited.insert(next);
                    bfs.push(next);
                }

                next = snake.rotateCounterclockwise();
                if (next.dir != 0 && visited.count(next) == 0) {
                    visited.insert(next);
                    bfs.push(next);
                }
            }

            ++moves;
        }

        return -1;
    }

    void copyGrid(vector<vector<int>>& grid, vector<vector<int>>& newGrid) {
        for (unsigned int i = 0; i < grid.size(); ++i) {
            for (unsigned int j = 0; j < grid.size(); ++j) {
                newGrid[i + 1][j + 1] = grid[i][j];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {0,0,0,0,0,1},
        {1,1,0,0,1,0},
        {0,0,0,0,1,1},
        {0,0,1,0,1,0},
        {0,1,1,0,0,0},
        {0,1,1,0,0,0} };
    check.checkInt(11, o.minimumMoves(grid));

    grid = { {0,0,1,1,1,1},
        {0,0,0,0,1,1},
        {1,1,0,0,0,1},
        {1,1,1,0,0,1},
        {1,1,1,0,0,1},
        {1,1,1,0,0,0} };
    check.checkInt(9, o.minimumMoves(grid));

    grid = { {0,0},{0,0} };
    check.checkInt(1, o.minimumMoves(grid));

    grid = { {0,0},{0,1} };
    check.checkInt(-1, o.minimumMoves(grid));

    grid = { {0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{0,1,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,1,0,0,1,0,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,1,0},{0,0,1,0,0,0,0,0,1,0,0,0,1,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},{0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},{0,1,0,1,0,1,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,1,1,1,0,0,1,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,1,1,0},{0,0,1,0,1,0,0,1,0,1,1,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0} };
    check.checkInt(-1, o.minimumMoves(grid));

    grid = { {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,0,1,1,0,0,1,0,0,0,0,1,0,0},{0,1,0,0,0,0,1,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,1,0,0,1,0,0,0,1,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},{1,0,0,0,0,0,1,0,0,0,1,0,0,0,1},{0,0,1,0,1,0,0,0,0,0,0,0,0,0,0} };
    check.checkInt(-1, o.minimumMoves(grid));
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
