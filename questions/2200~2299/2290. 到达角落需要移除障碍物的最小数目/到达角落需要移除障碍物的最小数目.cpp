/* 到达角落需要移除障碍物的最小数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维整数数组 grid ，数组大小为 m x n 。每个单元格都是两个值之一：

0 表示一个 空 单元格，
1 表示一个可以移除的 障碍物 。
你可以向上、下、左、右移动，从一个空单元格移动到另一个空单元格。

现在你需要从左上角 (0, 0) 移动到右下角 (m - 1, n - 1) ，返回需要移除的障碍物的 最小 数目。

 

示例 1：



输入：grid = [[0,1,1],[1,1,0],[1,1,0]]
输出：2
解释：可以移除位于 (0, 1) 和 (0, 2) 的障碍物来创建从 (0, 0) 到 (2, 2) 的路径。
可以证明我们至少需要移除两个障碍物，所以返回 2 。
注意，可能存在其他方式来移除 2 个障碍物，创建出可行的路径。
示例 2：



输入：grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
输出：0
解释：不移除任何障碍物就能从 (0, 0) 到 (2, 4) ，所以返回 0 。
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 105
2 <= m * n <= 105
grid[i][j] 为 0 或 1
grid[0][0] == grid[m - 1][n - 1] == 0

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        vector<vector<int>> costs(row, vector<int>(column, -1));
        deque<pair<int, int>> nodes;
        nodes.push_back({ 0,0 });
        costs[0][0] = 0;

        while (!nodes.empty()) {
            int r = nodes.front().first, c = nodes.front().second, cost = costs[r][c];
            nodes.pop_front();

            if (r == row - 1 && c == column - 1) {  // 到达目的地
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < column && costs[nr][nc] == -1) {
                    if (grid[nr][nc] == 0) {
                        nodes.push_front({ nr,nc });  // 可以直达的地方放入队列头部，继续寻找下一个
                        costs[nr][nc] = cost;
                    }
                    else {
                        nodes.push_back({ nr,nc });  // 需要移除障碍物，放入队列尾部，cost加1
                        costs[nr][nc] = cost + 1;
                    }
                }
            }
        }

        return costs[row - 1][column - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {0,1,1},{1,1,0},{1,1,0} };
    check.checkInt(2, o.minimumObstacles(grid));

    grid = { {0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0} };
    check.checkInt(0, o.minimumObstacles(grid));
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
