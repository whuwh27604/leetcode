/* 将石头分散到网格图的最少移动次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 3 * 3 ，下标从 0 开始的二维整数矩阵 grid ，分别表示每一个格子里石头的数目。网格图中总共恰好有 9 个石头，一个格子里可能会有 多个 石头。

每一次操作中，你可以将一个石头从它当前所在格子移动到一个至少有一条公共边的相邻格子。

请你返回每个格子恰好有一个石头的 最少移动次数 。



示例 1：



输入：grid = [[1,1,0],[1,1,1],[1,2,1]]
输出：3
解释：让每个格子都有一个石头的一个操作序列为：
1 - 将一个石头从格子 (2,1) 移动到 (2,2) 。
2 - 将一个石头从格子 (2,2) 移动到 (1,2) 。
3 - 将一个石头从格子 (1,2) 移动到 (0,2) 。
总共需要 3 次操作让每个格子都有一个石头。
让每个格子都有一个石头的最少操作次数为 3 。
示例 2：



输入：grid = [[1,3,0],[1,0,0],[1,0,3]]
输出：4
解释：让每个格子都有一个石头的一个操作序列为：
1 - 将一个石头从格子 (0,1) 移动到 (0,2) 。
2 - 将一个石头从格子 (0,1) 移动到 (1,1) 。
3 - 将一个石头从格子 (2,2) 移动到 (1,2) 。
4 - 将一个石头从格子 (2,2) 移动到 (2,1) 。
总共需要 4 次操作让每个格子都有一个石头。
让每个格子都有一个石头的最少操作次数为 4 。


提示：

grid.length == grid[i].length == 3
0 <= grid[i][j] <= 9
grid 中元素之和为 9 。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        unordered_map<int, int> memo;
        memo[111111111] = 0;

        return DFS(grid, memo);
    }

    int DFS(vector<vector<int>>& grid, unordered_map<int, int>& memo) {
        int state = getState(grid);
        if (memo.count(state)) {
            return memo[state];
        }

        int r = 0, c = 0, moves = INT_MAX;
        getMore(grid, r, c);

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == 0) {
                    --grid[r][c];
                    grid[i][j] = 1;
                    moves = min(moves, abs(r - i) + abs(c - j) + DFS(grid, memo));
                    ++grid[r][c];
                    grid[i][j] = 0;
                }
            }
        }

        return memo[state] = moves;
    }

    int getState(vector<vector<int>>& grid) {
        int state = 0;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                state = state * 10 + grid[i][j];
            }
        }

        return state;
    }

    void getMore(vector<vector<int>>& grid, int& r, int& c) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] > 1) {
                    r = i, c = j;
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,1,0},{1,1,1},{1,2,1} };
    check.checkInt(3, o.minimumMoves(grid));

    grid = { {1,3,0},{1,0,0},{1,0,3} };
    check.checkInt(4, o.minimumMoves(grid));

    grid = { {1,2,2},{1,1,0},{0,1,1} };
    check.checkInt(4, o.minimumMoves(grid));
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
