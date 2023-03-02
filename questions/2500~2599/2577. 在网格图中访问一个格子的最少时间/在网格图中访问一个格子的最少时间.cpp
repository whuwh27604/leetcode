/* 在网格图中访问一个格子的最少时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的矩阵 grid ，每个元素都为 非负 整数，其中 grid[row][col] 表示可以访问格子 (row, col) 的 最早 时间。也就是说当你访问格子 (row, col) 时，最少已经经过的时间为 grid[row][col] 。

你从 最左上角 出发，出发时刻为 0 ，你必须一直移动到上下左右相邻四个格子中的 任意 一个格子（即不能停留在格子上）。每次移动都需要花费 1 单位时间。

请你返回 最早 到达右下角格子的时间，如果你无法到达右下角的格子，请你返回 -1 。



示例 1：



输入：grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
输出：7
解释：一条可行的路径为：
- 时刻 t = 0 ，我们在格子 (0,0) 。
- 时刻 t = 1 ，我们移动到格子 (0,1) ，可以移动的原因是 grid[0][1] <= 1 。
- 时刻 t = 2 ，我们移动到格子 (1,1) ，可以移动的原因是 grid[1][1] <= 2 。
- 时刻 t = 3 ，我们移动到格子 (1,2) ，可以移动的原因是 grid[1][2] <= 3 。
- 时刻 t = 4 ，我们移动到格子 (1,1) ，可以移动的原因是 grid[1][1] <= 4 。
- 时刻 t = 5 ，我们移动到格子 (1,2) ，可以移动的原因是 grid[1][2] <= 5 。
- 时刻 t = 6 ，我们移动到格子 (1,3) ，可以移动的原因是 grid[1][3] <= 6 。
- 时刻 t = 7 ，我们移动到格子 (2,3) ，可以移动的原因是 grid[2][3] <= 7 。
最终到达时刻为 7 。这是最早可以到达的时间。
示例 2：



输入：grid = [[0,2,4],[3,2,1],[1,0,4]]
输出：-1
解释：没法从左上角按题目规定走到右下角。


提示：

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
0 <= grid[i][j] <= 105
grid[0][0] == 0
*/

#include <iostream>
#include <queue>
#include "../tools/TestData.h"
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int r;
    int c;
    int time;

    Node() : r(0), c(0), time(0) {}
    Node(int x, int y, int t) : r(x), c(y), time(t) {}

    bool operator<(const Node& o) const {
        return time > o.time;
    }
};

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int row = grid.size(), column = grid[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        vector<vector<int>> times(row, vector<int>(column, INT_MAX));
        times[0][0] = 0;
        priority_queue<Node> nodes;
        nodes.push(Node(0, 0, 0));

        while (!nodes.empty()) {
            Node node = nodes.top();
            nodes.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = node.r + dr[i], nc = node.c + dc[i], time = node.time + 1;
                if (nr >= 0 && nr < row && nc >= 0 && nc < column) {
                    if (time < grid[nr][nc]) {
                        time = (((grid[nr][nc] - time) & 1) == 1) ? grid[nr][nc] + 1 : grid[nr][nc];
                    }
                    if (time < times[nr][nc]) {
                        times[nr][nc] = time;
                        nodes.push(Node(nr, nc, time));
                    }
                }
            }
        }

        return times[row - 1][column - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {0,1,3,2},{5,1,2,5},{4,3,8,6} };
    check.checkInt(7, o.minimumTime(grid));

    grid = { {0,2,4},{3,2,1},{1,0,4} };
    check.checkInt(-1, o.minimumTime(grid));

    grid = getIntVectorVector("./testcase1.txt");
    check.checkInt(68145, o.minimumTime(grid));
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
