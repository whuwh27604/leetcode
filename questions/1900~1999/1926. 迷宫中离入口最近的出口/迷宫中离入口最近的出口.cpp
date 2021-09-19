/* 迷宫中离入口最近的出口.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的迷宫矩阵 maze （下标从 0 开始），矩阵中有空格子（用 '.' 表示）和墙（用 '+' 表示）。同时给你迷宫的入口 entrance ，用 entrance = [entrancerow, entrancecol] 表示你一开始所在格子的行和列。

每一步操作，你可以往 上，下，左 或者 右 移动一个格子。你不能进入墙所在的格子，你也不能离开迷宫。你的目标是找到离 entrance 最近 的出口。出口 的含义是 maze 边界 上的 空格子。entrance 格子 不算 出口。

请你返回从 entrance 到最近出口的最短路径的 步数 ，如果不存在这样的路径，请你返回 -1 。

 

示例 1：


输入：maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
输出：1
解释：总共有 3 个出口，分别位于 (1,0)，(0,2) 和 (2,3) 。
一开始，你在入口格子 (1,2) 处。
- 你可以往左移动 2 步到达 (1,0) 。
- 你可以往上移动 1 步到达 (0,2) 。
从入口处没法到达 (2,3) 。
所以，最近的出口是 (0,2) ，距离为 1 步。
示例 2：


输入：maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
输出：2
解释：迷宫中只有 1 个出口，在 (1,2) 处。
(1,0) 不算出口，因为它是入口格子。
初始时，你在入口与格子 (1,0) 处。
- 你可以往右移动 2 步到达 (1,2) 处。
所以，最近的出口为 (1,2) ，距离为 2 步。
示例 3：


输入：maze = [[".","+"]], entrance = [0,0]
输出：-1
解释：这个迷宫中没有出口。
 

提示：

maze.length == m
maze[i].length == n
1 <= m, n <= 100
maze[i][j] 要么是 '.' ，要么是 '+' 。
entrance.length == 2
0 <= entrancerow < m
0 <= entrancecol < n
entrance 一定是空格子。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/nearest-exit-from-entrance-in-maze
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../tools/TestData.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size(), column = maze[0].size(), steps = -1;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        queue<int> bfs;
        bfs.push({ (entrance[0] << 8) | entrance[1] });
        maze[entrance[0]][entrance[1]] = '+';

        while (!bfs.empty()) {
            int i, size = bfs.size();
            ++steps;

            for (i = 0; i < size; ++i) {
                int r = bfs.front() >> 8, c = bfs.front() & 0xff;
                bfs.pop();

                if (steps != 0 && (r == 0 || r == row - 1 || c == 0 || c == column - 1)) {
                    return steps;
                }

                for (int j = 0; j < 4; ++j) {
                    int nr = r + dr[j], nc = c + dc[j];

                    if (nr >= 0 && nr < row && nc >= 0 && nc < column && maze[nr][nc] == '.') {
                        bfs.push({ (nr << 8) | nc });
                        maze[nr][nc] = '+';
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<char>> maze = { {'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'} };
    vector<int> entrance = { 1,2 };
    check.checkInt(1, o.nearestExit(maze, entrance));

    maze = { {'+','+','+'},{'.','.','.'},{'+','+','+'} };
    entrance = { 1,0 };
    check.checkInt(2, o.nearestExit(maze, entrance));

    maze = { {'.','+'} };
    entrance = { 0,0 };
    check.checkInt(-1, o.nearestExit(maze, entrance));

    maze = getCharVectorVector("./testcase1.txt");
    entrance = { 42,4 };
    check.checkInt(-1, o.nearestExit(maze, entrance));
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
