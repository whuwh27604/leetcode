/* 找出最安全路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、大小为 n x n 的二维矩阵 grid ，其中 (r, c) 表示：

如果 grid[r][c] = 1 ，则表示一个存在小偷的单元格
如果 grid[r][c] = 0 ，则表示一个空单元格
你最开始位于单元格 (0, 0) 。在一步移动中，你可以移动到矩阵中的任一相邻单元格，包括存在小偷的单元格。

矩阵中路径的 安全系数 定义为：从路径中任一单元格到矩阵中任一小偷所在单元格的 最小 曼哈顿距离。

返回所有通向单元格 (n - 1, n - 1) 的路径中的 最大安全系数 。

单元格 (r, c) 的某个 相邻 单元格，是指在矩阵中存在的 (r, c + 1)、(r, c - 1)、(r + 1, c) 和 (r - 1, c) 之一。

两个单元格 (a, b) 和 (x, y) 之间的 曼哈顿距离 等于 | a - x | + | b - y | ，其中 |val| 表示 val 的绝对值。



示例 1：


输入：grid = [[1,0,0],[0,0,0],[0,0,1]]
输出：0
解释：从 (0, 0) 到 (n - 1, n - 1) 的每条路径都经过存在小偷的单元格 (0, 0) 和 (n - 1, n - 1) 。
示例 2：


输入：grid = [[0,0,1],[0,0,0],[0,0,0]]
输出：2
解释：
上图所示路径的安全系数为 2：
- 该路径上距离小偷所在单元格（0，2）最近的单元格是（0，0）。它们之间的曼哈顿距离为 | 0 - 0 | + | 0 - 2 | = 2 。
可以证明，不存在安全系数更高的其他路径。
示例 3：


输入：grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
输出：2
解释：
上图所示路径的安全系数为 2：
- 该路径上距离小偷所在单元格（0，3）最近的单元格是（1，2）。它们之间的曼哈顿距离为 | 0 - 1 | + | 3 - 2 | = 2 。
- 该路径上距离小偷所在单元格（3，0）最近的单元格是（3，2）。它们之间的曼哈顿距离为 | 3 - 3 | + | 0 - 2 | = 2 。
可以证明，不存在安全系数更高的其他路径。


提示：

1 <= grid.length == n <= 400
grid[i].length == n
grid[i][j] 为 0 或 1
grid 至少存在一个小偷
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), low = 0, high = 2 * n, ans = 0;
        vector<vector<int>> factors(n, vector<int>(n, INT_MAX));

        getFactors(n, grid, factors);

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(n, mid, grid, factors)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    void getFactors(int n, vector<vector<int>>& grid, vector<vector<int>>& factors) {
        queue<pair<int, int>> nodes;
        int fact = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    nodes.push({ r,c });
                    factors[r][c] = 0;
                }
            }
        }

        while (!nodes.empty()) {
            int size = nodes.size();
            ++fact;

            for (int i = 0; i < size; ++i) {
                int r = nodes.front().first, c = nodes.front().second;
                nodes.pop();

                for (int j = 0; j < 4; ++j) {
                    int nr = r + dr[j], nc = c + dc[j];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && factors[nr][nc] == INT_MAX) {
                        factors[nr][nc] = fact;
                        nodes.push({ nr,nc });
                    }
                }
            }
        }
    }

    bool check(int n, int safeFactor, vector<vector<int>>& grid, vector<vector<int>>& factors) {
        if (factors[0][0] < safeFactor) {
            return false;
        }

        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        queue<pair<int, int>> nodes;
        nodes.push({ 0,0 });

        while (!nodes.empty()) {
            int r = nodes.front().first, c = nodes.front().second;
            nodes.pop();

            for (int j = 0; j < 4; ++j) {
                int nr = r + dr[j], nc = c + dc[j];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && factors[nr][nc] >= safeFactor) {
                    if (nr == n - 1 && nc == n - 1) {
                        return true;
                    }

                    visited[nr][nc] = true;
                    nodes.push({ nr,nc });
                }
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,0,0},{0,0,0},{0,0,1} };
    check.checkInt(0, o.maximumSafenessFactor(grid));

    grid = { {0,0,1},{0,0,0},{0,0,0} };
    check.checkInt(2, o.maximumSafenessFactor(grid));

    grid = { {0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0} };
    check.checkInt(2, o.maximumSafenessFactor(grid));
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
