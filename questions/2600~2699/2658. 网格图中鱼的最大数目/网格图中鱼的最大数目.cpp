/* 网格图中鱼的最大数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始大小为 m x n 的二维整数数组 grid ，其中下标在 (r, c) 处的整数表示：

如果 grid[r][c] = 0 ，那么它是一块 陆地 。
如果 grid[r][c] > 0 ，那么它是一块 水域 ，且包含 grid[r][c] 条鱼。
一位渔夫可以从任意 水域 格子 (r, c) 出发，然后执行以下操作任意次：

捕捞格子 (r, c) 处所有的鱼，或者
移动到相邻的 水域 格子。
请你返回渔夫最优策略下， 最多 可以捕捞多少条鱼。如果没有水域格子，请你返回 0 。

格子 (r, c) 相邻 的格子为 (r, c + 1) ，(r, c - 1) ，(r + 1, c) 和 (r - 1, c) ，前提是相邻格子在网格图内。



示例 1：



输入：grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
输出：7
解释：渔夫可以从格子 (1,3) 出发，捕捞 3 条鱼，然后移动到格子 (2,3) ，捕捞 4 条鱼。
示例 2：



输入：grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
输出：1
解释：渔夫可以从格子 (0,0) 或者 (3,3) ，捕捞 1 条鱼。


提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 10
0 <= grid[i][j] <= 10
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int r;
    int c;
    int value;

    Node() : r(0), c(0), value(0) {}
    Node(int r_, int c_, int v_) : r(r_), c(c_), value(v_) {}
};

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size(), maxFish = 0;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                if (grid[r][c] != 0) {
                    maxFish = max(maxFish, getFish(grid, Node(r, c, grid[r][c])));
                }
            }
        }

        return maxFish;
    }

    int getFish(vector<vector<int>>& grid, Node node) {
        int row = grid.size(), column = grid[0].size(), fish = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        queue<Node> nodes;
        nodes.push(node);
        grid[node.r][node.c] = 0;

        while (!nodes.empty()) {
            Node current = nodes.front();
            nodes.pop();
            fish += current.value;

            for (int i = 0; i < 4; ++i) {
                int nr = current.r + dr[i], nc = current.c + dc[i];
                if (nr >= 0 && nr < row && nc >= 0 && nc < column && grid[nr][nc] != 0) {
                    nodes.push(Node(nr, nc, grid[nr][nc]));
                    grid[nr][nc] = 0;
                }
            }
        }

        return fish;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0} };
    check.checkInt(7, o.findMaxFish(grid));

    grid = { {1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1} };
    check.checkInt(1, o.findMaxFish(grid));
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
