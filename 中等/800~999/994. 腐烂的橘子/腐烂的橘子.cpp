/* 腐烂的橘子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在给定的网格中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

 

示例 1：



输入：[[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：

输入：[[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
示例 3：

输入：[[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 

提示：

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] 仅为 0、1 或 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotting-oranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> bfs;
        int freshOranges = 0, minutes = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        int i, j, row = grid.size(), column = grid[0].size();

        init(grid, bfs, freshOranges);

        while (!bfs.empty()) {
            int size = bfs.size();
            ++minutes;

            for (i = 0; i < size; ++i) {
                int curRow = bfs.front().first, curColumn = bfs.front().second;
                bfs.pop();

                for (j = 0; j < 4; ++j) {
                    int r = curRow + dr[j], c = curColumn + dc[j];
                    if ((r >= 0) && (r < row) && (c >= 0) && (c < column) && (grid[r][c] == 1)) {
                        grid[r][c] = 2;
                        if (--freshOranges == 0) {
                            return minutes;
                        }
                        bfs.push({ r,c });
                    }
                }
            }
        }

        return (freshOranges == 0) ? 0 : -1;
    }

    void init(vector<vector<int>>& grid, queue<pair<int, int>>& bfs, int& freshOranges) {
        int i, j, row = grid.size(), column = grid[0].size();

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (grid[i][j] == 1) {
                    ++freshOranges;
                }
                else if (grid[i][j] == 2) {
                    bfs.push({ i,j });
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {2,1,1},{1,1,0},{0,1,1} };
    check.checkInt(4, o.orangesRotting(grid));

    grid = { {2,1,1},{0,1,1},{1,0,1} };
    check.checkInt(-1, o.orangesRotting(grid));

    grid = { {0,2} };
    check.checkInt(0, o.orangesRotting(grid));

    grid = { {2,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1} };
    check.checkInt(18, o.orangesRotting(grid));
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
