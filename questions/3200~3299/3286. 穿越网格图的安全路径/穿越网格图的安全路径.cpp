/* 穿越网格图的安全路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的二进制矩形 grid 和一个整数 health 表示你的健康值。

你开始于矩形的左上角 (0, 0) ，你的目标是矩形的右下角 (m - 1, n - 1) 。

你可以在矩形中往上下左右相邻格子移动，但前提是你的健康值始终是 正数 。

对于格子 (i, j) ，如果 grid[i][j] = 1 ，那么这个格子视为 不安全 的，会使你的健康值减少 1 。

如果你可以到达最终的格子，请你返回 true ，否则返回 false 。

注意 ，当你在最终格子的时候，你的健康值也必须为 正数 。



示例 1：

输入：grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1

输出：true

解释：

沿着下图中灰色格子走，可以安全到达最终的格子。


示例 2：

输入：grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3

输出：false

解释：

健康值最少为 4 才能安全到达最后的格子。


示例 3：

输入：grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5

输出：true

解释：

沿着下图中灰色格子走，可以安全到达最终的格子。



任何不经过格子 (1, 1) 的路径都是不安全的，因为你的健康值到达最终格子时，都会小于等于 0 。



提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 50
2 <= m * n
1 <= health <= m + n
grid[i][j] 要么是 0 ，要么是 1 。
*/

#include <iostream>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int r;
    int c;
    int health;

    Node() : r(0), c(0), health(0) {}
    Node(int r_, int c_, int h) : r(r_), c(c_), health(h) {}
};

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        int row = (int)grid.size(), column = (int)grid[0].size();
        vector<vector<int>> heals(row, vector<int>(column, 0));
        heals[0][0] = health - grid[0][0];
        deque<Node> nodes;
        nodes.push_back(Node(0, 0, heals[0][0]));

        while (!nodes.empty()) {
            int r = nodes.front().r, c = nodes.front().c, heal = nodes.front().health;
            nodes.pop_front();

            if (r == row - 1 && c == column - 1 && heal > 0) {
                return true;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr < 0 || nr >= row || nc < 0 || nc >= column) {
                    continue;
                }

                int nheal = heal - grid[nr][nc];
                if (nheal <= heals[nr][nc]) {  // 只有更优的路径才更新，避免重复计算
                    continue;
                }
                heals[nr][nc] = nheal;

                if (nheal == heal) {  // 优先计算health没有减少的节点
                    nodes.push_front(Node(nr, nc, nheal));
                }
                else {  // health减1了，放入队列尾部
                    nodes.push_back(Node(nr, nc, nheal));
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0} };
    check.checkBool(true, o.findSafeWalk(grid, 1));

    grid = { {0,1,1,0,0,0},{1,0,1,0,0,0},{0,1,1,1,0,1},{0,0,1,0,1,0} };
    check.checkBool(false, o.findSafeWalk(grid, 3));

    grid = { {1,1,1},{1,0,1},{1,1,1} };
    check.checkBool(true, o.findSafeWalk(grid, 5));
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
