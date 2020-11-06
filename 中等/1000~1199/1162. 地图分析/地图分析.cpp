/* 地图分析.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你现在手里有一份大小为 N x N 的 网格 grid，上面的每个 单元格 都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的。

我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - x1| + |y0 - y1| 。

如果网格上只有陆地或者海洋，请返回 -1。

 

示例 1：



输入：[[1,0,1],[0,0,0],[1,0,1]]
输出：2
解释：
海洋单元格 (1, 1) 和所有陆地单元格之间的距离都达到最大，最大距离为 2。
示例 2：



输入：[[1,0,0],[0,0,0],[0,0,0]]
输出：4
解释：
海洋单元格 (2, 2) 和所有陆地单元格之间的距离都达到最大，最大距离为 4。
 

提示：

1 <= grid.length == grid[0].length <= 100
grid[i][j] 不是 0 就是 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        int N = grid.size(), distance = -1;

        queue<pair<int, int>> bfs;
        getAllLands(grid, bfs);

        if (bfs.size() == 0 || bfs.size() == N * N) {
            return -1;
        }

        while (!bfs.empty()) {
            int i, size = bfs.size();
            ++distance;

            for (i = 0; i < size; ++i) {
                int row = bfs.front().first, column = bfs.front().second;
                bfs.pop();

                for (int j = 0; j < 4; ++j) {
                    int r = row + dr[j], c = column + dc[j];

                    if (r >= 0 && r < N && c >= 0 && c < N && grid[r][c] == 0) {
                        grid[r][c] = 1;
                        bfs.push({ r, c });
                    }
                }
            }
        }

        return distance;
    }

    void getAllLands(vector<vector<int>>& grid, queue<pair<int, int>>& bfs) {
        int i, j, N = grid.size();

        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    bfs.push({ i, j });
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,0,1},{0,0,0},{1,0,1} };
    check.checkInt(2, o.maxDistance(grid));

    grid = { {1,0,0},{0,0,0},{0,0,0} };
    check.checkInt(4, o.maxDistance(grid));

    grid = { {1,0,1},{0,0,0},{0,0,0} };
    check.checkInt(3, o.maxDistance(grid));

    grid = { {1} };
    check.checkInt(-1, o.maxDistance(grid));

    grid = { {0} };
    check.checkInt(-1, o.maxDistance(grid));

    grid = { {1,0},{0,1} };
    check.checkInt(1, o.maxDistance(grid));

    grid = { {1,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0} };
    check.checkInt(18, o.maxDistance(grid));
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
