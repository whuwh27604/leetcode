/* 网格中的最短路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m * n 的网格，其中每个单元格不是 0（空）就是 1（障碍物）。每一步，您都可以在空白单元格中上、下、左、右移动。

如果您 最多 可以消除 k 个障碍物，请找出从左上角 (0, 0) 到右下角 (m-1, n-1) 的最短路径，并返回通过该路径所需的步数。如果找不到这样的路径，则返回 -1 。

 

示例 1：



输入： grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
输出：6
解释：
不消除任何障碍的最短路径是 10。
消除位置 (3,2) 处的障碍后，最短路径是 6 。该路径是 (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
示例 2：



输入：grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
输出：-1
解释：我们至少需要消除两个障碍才能找到这样的路径。
 

提示：

grid.length == m
grid[0].length == n
1 <= m, n <= 40
1 <= k <= m*n
grid[i][j] 是 0 或 1
grid[0][0] == grid[m-1][n-1] == 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-path-in-a-grid-with-obstacles-elimination
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int r;
    int c;
    int obstacles;

    Node() : r(0), c(0), obstacles(0) {}
    Node(int r_, int c_, int ob) : r(r_), c(c_), obstacles(ob) {}
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row = grid.size(), column = grid[0].size(), steps = 0;

        if (k >= row + column - 3) {  // 从上到下，从左到右最多m + n - 3个障碍，k超过这个数选这条最短路径就可以了
            return row + column - 2;
        }

        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        vector<vector<bool>> visited(row * column, vector<bool>(k + 1, false));
        visited[0][0] = true;
        queue<Node> nodes;
        nodes.push(Node(0, 0, 0));

        while (!nodes.empty()) {
            int i, size = nodes.size();
            ++steps;

            for (i = 0; i < size; ++i) {
                Node node = nodes.front();
                nodes.pop();

                for (int j = 0; j < 4; ++j) {
                    int nr = node.r + dr[j], nc = node.c + dc[j];

                    if (nr < 0 || nr >= row || nc < 0 || nc >= column) {
                        continue;
                    }

                    if (nr == row - 1 && nc == column - 1) {
                        return steps;
                    }

                    int pos = nr * column + nc;

                    if (grid[nr][nc] == 0) {
                        if (!visited[pos][node.obstacles]) {
                            visited[pos][node.obstacles] = true;
                            nodes.push(Node(nr, nc, node.obstacles));
                        }
                    }
                    else {
                        if (node.obstacles < k && !visited[pos][node.obstacles + 1]) {
                            visited[pos][node.obstacles + 1] = true;
                            nodes.push(Node(nr, nc, node.obstacles + 1));
                        }
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

    vector<vector<int>> grid = { {0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0} };
    check.checkInt(6, o.shortestPath(grid, 1));

    grid = { {0,1,1},{1,1,1},{1,0,0} };
    check.checkInt(-1, o.shortestPath(grid, 1));

    grid = { {0,1,1,0} };
    check.checkInt(-1, o.shortestPath(grid, 1));

    grid = { {0,1,1,0} };
    check.checkInt(3, o.shortestPath(grid, 5));
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
