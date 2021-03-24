/* 不同路径 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在二维网格 grid 上，有 4 种类型的方格：

1 表示起始方格。且只有一个起始方格。
2 表示结束方格，且只有一个结束方格。
0 表示我们可以走过的空方格。
-1 表示我们无法跨越的障碍。
返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。

每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。

 

示例 1：

输入：[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
输出：2
解释：我们有以下两条路径：
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
示例 2：

输入：[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
输出：4
解释：我们有以下四条路径：
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
示例 3：

输入：[[0,1],[2,0]]
输出：0
解释：
没有一条路能完全穿过每一个空的方格一次。
请注意，起始和结束方格可以位于网格中的任意位置。
 

提示：

1 <= grid.length * grid[0].length <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int state = 0, start = -1, end = -1, size = grid.size() * grid[0].size();

        initState(grid, state, start, end);
        if (start == -1 || end == -1) {
            return 0;
        }

        vector<vector<int>> memo(size, vector<int>(1 << size, -1));
        return DFS(grid, state, start, end, memo);
    }

    void initState(vector<vector<int>>& grid, int& state, int& start, int& end) {
        int i, j, row = grid.size(), column = grid[0].size();

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                int index = i * column + j;
                if (grid[i][j] == 1) {
                    start = index;
                }
                else if (grid[i][j] == 2) {
                    end = index;
                    state |= (1 << index);
                }
                else if (grid[i][j] == 0) {
                    state |= (1 << index);
                }
            }
        }
    }

    int DFS(vector<vector<int>>& grid, int state, int start, int end, vector<vector<int>>& memo) {
        if (memo[start][state] != -1) {
            return memo[start][state];  // 如果这个状态已经访问过，直接返回结果
        }

        if (start == end) {
            return state == 0 ? 1 : 0;  // 已经到达终点，如果所有点都已经访问过了，说明找到一条路径
        }

        int row = grid.size(), column = grid[0].size(), r = start / column, c = start % column, paths = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i], next = nr * column + nc;

            if (nr >= 0 && nr < row && nc >= 0 && nc < column && (state & (1 << next)) != 0) {
                paths += DFS(grid, state ^ (1 << next), next, end, memo);
            }
        }

        memo[start][state] = paths;  // 记录下这个状态的答案
        return paths;
    }
};

/*class Solution {
public:
    int ans;
    vector<vector<int>> grid;
    int R, C;
    int tr, tc, target;
    int dr[4] = { 0, -1, 0, 1 };
    int dc[4] = { 1, 0, -1, 0 };

    int uniquePathsIII(vector<vector<int>>& grid) {
        this->grid = grid;
        R = grid.size();
        C = grid[0].size();
        target = 0;

        int sr = 0, sc = 0;
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] % 2 == 0)
                    target |= code(r, c);

                if (grid[r][c] == 1) {
                    sr = r;
                    sc = c;
                }
                else if (grid[r][c] == 2) {
                    tr = r;
                    tc = c;
                }
            }

        vector<vector<vector<int>>> memo(R, vector<vector<int>>(C, vector<int>(1 << R * C, -1)));
        return dp(sr, sc, target, memo);
    }

    int code(int r, int c) {
        return 1 << (r * C + c);
    }

    int dp(int r, int c, int todo, vector<vector<vector<int>>>& memo) {
        if (memo[r][c][todo] != -1)
            return memo[r][c][todo];

        if (r == tr && c == tc) {
            return todo == 0 ? 1 : 0;
        }

        int ans = 0;
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (0 <= nr && nr < R && 0 <= nc && nc < C) {
                if ((todo & code(nr, nc)) != 0)
                    ans += dp(nr, nc, todo ^ code(nr, nc), memo);
            }
        }
        memo[r][c][todo] = ans;
        return ans;
    }
};*/

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,0,0,0},{0,0,0,0},{0,0,2,-1} };
    check.checkInt(2, o.uniquePathsIII(grid));

    grid = { {1,0,0},{0,0,2} };
    check.checkInt(1, o.uniquePathsIII(grid));

    grid = { {1,0,0,0},{0,0,0,0},{0,0,0,2} };
    check.checkInt(4, o.uniquePathsIII(grid));

    grid = { {0,1},{2,0} };
    check.checkInt(0, o.uniquePathsIII(grid));

    grid = { {1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,2} };
    check.checkInt(20, o.uniquePathsIII(grid));

    grid = { {1} };
    check.checkInt(0, o.uniquePathsIII(grid));

    grid = { {2} };
    check.checkInt(0, o.uniquePathsIII(grid));

    grid = { {1,-1,2} };
    check.checkInt(0, o.uniquePathsIII(grid));

    grid = { {0,0,0,0},{0,0,-1,0},{0,0,0,0},{1,0,2,0},{0,0,-1,0} };
    check.checkInt(0, o.uniquePathsIII(grid));
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
