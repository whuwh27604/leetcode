/* 二进制矩阵中的最短路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个 N × N 的方形网格中，每个单元格有两种状态：空（0）或者阻塞（1）。

一条从左上角到右下角、长度为 k 的畅通路径，由满足下述条件的单元格 C_1, C_2, ..., C_k 组成：

相邻单元格 C_i 和 C_{i+1} 在八个方向之一上连通（此时，C_i 和 C_{i+1} 不同且共享边或角）
C_1 位于 (0, 0)（即，值为 grid[0][0]）
C_k 位于 (N-1, N-1)（即，值为 grid[N-1][N-1]）
如果 C_i 位于 (r, c)，则 grid[r][c] 为空（即，grid[r][c] == 0）
返回这条从左上角到右下角的最短畅通路径的长度。如果不存在这样的路径，返回 -1 。

 

示例 1：

输入：[[0,1],[1,0]]

输出：2

示例 2：

输入：[[0,0,0],[1,1,0],[1,1,0]]

输出：4

 

提示：

1 <= grid.length == grid[0].length <= 100
grid[i][j] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-path-in-binary-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid.back().back() == 1) {
            return -1;
        }

        queue<pair<int, int>> bfs;
        bfs.push({ 0,0 });
        grid[0][0] = -1;

        int dr[8] = { 0,1,1,1,0,-1,-1,-1 }, dc[8] = { 1,1,0,-1,-1,-1,0,1 };
        int N = grid.size(), path = 0;

        while (!bfs.empty()) {
            int i, size = bfs.size();
            ++path;

            for (i = 0; i < size; ++i) {
                int row = bfs.front().first, column = bfs.front().second;
                bfs.pop();

                if (row == N - 1 && column == N - 1) {
                    return path;
                }

                for (int i = 0; i < 8; ++i) {
                    int r = row + dr[i], c = column + dc[i];
                    if (r >= 0 && r < N && c >= 0 && c < N && grid[r][c] == 0) {
                        bfs.push({ r,c });
                        grid[r][c] = -1;
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

    vector<vector<int>> grid = { {0,1},{1,0} };
    check.checkInt(2, o.shortestPathBinaryMatrix(grid));

    grid = { {0,0,0},{1,1,0},{1,1,0} };
    check.checkInt(4, o.shortestPathBinaryMatrix(grid));

    grid = { {0,1,0,0,1,1,0},{1,0,0,0,0,0,0},{1,0,0,1,1,1,1},{0,1,0,0,0,0,0},{1,0,0,0,0,0,1},{1,0,0,1,0,0,0},{1,0,1,0,0,1,0} };
    check.checkInt(7, o.shortestPathBinaryMatrix(grid));

    grid = { {1,0,0},{1,1,0},{1,1,0} };
    check.checkInt(-1, o.shortestPathBinaryMatrix(grid));

    grid = { {0,0,0},{1,1,0},{1,1,1} };
    check.checkInt(-1, o.shortestPathBinaryMatrix(grid));

    grid = { {0} };
    check.checkInt(1, o.shortestPathBinaryMatrix(grid));
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
