/* 逃离火灾.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始大小为 m x n 的二维整数数组 grid ，它表示一个网格图。每个格子为下面 3 个值之一：

0 表示草地。
1 表示着火的格子。
2 表示一座墙，你跟火都不能通过这个格子。
一开始你在最左上角的格子 (0, 0) ，你想要到达最右下角的安全屋格子 (m - 1, n - 1) 。每一分钟，你可以移动到 相邻 的草地格子。每次你移动 之后 ，着火的格子会扩散到所有不是墙的 相邻 格子。

请你返回你在初始位置可以停留的 最多 分钟数，且停留完这段时间后你还能安全到达安全屋。如果无法实现，请你返回 -1 。如果不管你在初始位置停留多久，你 总是 能到达安全屋，请你返回 109 。

注意，如果你到达安全屋后，火马上到了安全屋，这视为你能够安全到达安全屋。

如果两个格子有共同边，那么它们为 相邻 格子。

 

示例 1：



输入：grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
输出：3
解释：上图展示了你在初始位置停留 3 分钟后的情形。
你仍然可以安全到达安全屋。
停留超过 3 分钟会让你无法安全到达安全屋。
示例 2：



输入：grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
输出：-1
解释：上图展示了你马上开始朝安全屋移动的情形。
火会蔓延到你可以移动的所有格子，所以无法安全到达安全屋。
所以返回 -1 。
示例 3：



输入：grid = [[0,0,0],[2,2,0],[1,2,0]]
输出：1000000000
解释：上图展示了初始网格图。
注意，由于火被墙围了起来，所以无论如何你都能安全到达安全屋。
所以返回 109 。
 

提示：

m == grid.length
n == grid[i].length
2 <= m, n <= 300
4 <= m * n <= 2 * 104
grid[i][j] 是 0 ，1 或者 2 。
grid[0][0] == grid[m - 1][n - 1] == 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/escape-the-spreading-fire
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), inf = 1000000000;

        vector<vector<int>> burningMinutes(m, vector<int>(n, inf));
        getBurningMinutes(grid, burningMinutes);

        int low = 0, high = min(m * n, burningMinutes[0][0] - 1), maxStayingMinutes = -1;

        while (low <= high) {
            int middle = (low + high) / 2;

            if (canFinish(grid, burningMinutes, middle)) {
                maxStayingMinutes = middle;
                low = middle + 1;
            }
            else {
                high = middle - 1;
            }
        }

        return maxStayingMinutes == m * n ? inf : maxStayingMinutes;  // 等待m * n都可以到达的话，那么可以永久等待
    }

    void getBurningMinutes(vector<vector<int>>& grid, vector<vector<int>>& burningMinutes) {
        int m = grid.size(), n = grid[0].size(), r, c, inf = 1000000000, minutes = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        queue<pair<int, int>> bfs;

        for (r = 0; r < m; ++r) {
            for (c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    bfs.push({ r, c });
                }
            }
        }

        while (!bfs.empty()) {
            int size = bfs.size();
            ++minutes;

            for (int i = 0; i < size; ++i) {
                r = bfs.front().first, c = bfs.front().second;
                bfs.pop();

                for (int j = 0; j < 4; ++j) {
                    int nr = r + dr[j], nc = c + dc[j];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0 && burningMinutes[nr][nc] == inf) {
                        burningMinutes[nr][nc] = minutes;
                        bfs.push({ nr,nc });
                    }
                }
            }
        }
    }

    bool canFinish(vector<vector<int>>& grid, vector<vector<int>>& burningMinutes, int stayingMinutes) {
        int m = grid.size(), n = grid[0].size(), minutes = stayingMinutes;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        queue<pair<int, int>> bfs;
        bfs.push({ 0,0 });

        while (!bfs.empty()) {
            int size = bfs.size();
            ++minutes;

            for (int i = 0; i < size; ++i) {
                int r = bfs.front().first, c = bfs.front().second;
                bfs.pop();

                for (int j = 0; j < 4; ++j) {
                    int nr = r + dr[j], nc = c + dc[j];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0 && !visited[nr][nc]) {
                        visited[nr][nc] = true;

                        if (nr == m - 1 && nc == n - 1) {  // 如果是终点，可以取相等
                            if (burningMinutes[nr][nc] >= minutes) {
                                return true;
                            }
                            else {
                                return false;
                            }
                        }

                        if (burningMinutes[nr][nc] > minutes) {  // 不是终点，只能取大于
                            bfs.push({ nr,nc });
                        }
                    }
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

    vector<vector<int>> grid = { {0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0} };
    check.checkInt(3, o.maximumMinutes(grid));

    grid = { {0,0,0,0},{0,1,2,0},{0,2,0,0} };
    check.checkInt(-1, o.maximumMinutes(grid));

    grid = { {0,0,0},{2,2,0},{1,2,0} };
    check.checkInt(1000000000, o.maximumMinutes(grid));

    grid = { {0,2,0,0,1},{0,2,0,2,2},{0,2,0,0,0},{0,0,2,2,0},{0,0,0,0,0} };
    check.checkInt(0, o.maximumMinutes(grid));
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
