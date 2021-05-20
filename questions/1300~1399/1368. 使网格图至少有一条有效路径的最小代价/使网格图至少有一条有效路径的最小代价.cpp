/* 使网格图至少有一条有效路径的最小代价.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的网格图 grid 。 grid 中每个格子都有一个数字，对应着从该格子出发下一步走的方向。 grid[i][j] 中的数字可能为以下几种情况：

1 ，下一步往右走，也就是你会从 grid[i][j] 走到 grid[i][j + 1]
2 ，下一步往左走，也就是你会从 grid[i][j] 走到 grid[i][j - 1]
3 ，下一步往下走，也就是你会从 grid[i][j] 走到 grid[i + 1][j]
4 ，下一步往上走，也就是你会从 grid[i][j] 走到 grid[i - 1][j]
注意网格图中可能会有 无效数字 ，因为它们可能指向 grid 以外的区域。

一开始，你会从最左上角的格子 (0,0) 出发。我们定义一条 有效路径 为从格子 (0,0) 出发，每一步都顺着数字对应方向走，最终在最右下角的格子 (m - 1, n - 1) 结束的路径。有效路径 不需要是最短路径 。

你可以花费 cost = 1 的代价修改一个格子中的数字，但每个格子中的数字 只能修改一次 。

请你返回让网格图至少有一条有效路径的最小代价。

 

示例 1：



输入：grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
输出：3
解释：你将从点 (0, 0) 出发。
到达 (3, 3) 的路径为： (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) 花费代价 cost = 1 使方向向下 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) 花费代价 cost = 1 使方向向下 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) 花费代价 cost = 1 使方向向下 --> (3, 3)
总花费为 cost = 3.
示例 2：



输入：grid = [[1,1,3],[3,2,2],[1,1,4]]
输出：0
解释：不修改任何数字你就可以从 (0, 0) 到达 (2, 2) 。
示例 3：



输入：grid = [[1,2],[4,3]]
输出：1
示例 4：

输入：grid = [[2,2,2],[2,2,2]]
输出：3
示例 5：

输入：grid = [[4]]
输出：0
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size(), r, c, cost = 0;
        int dr[5] = { 0,0,0,1,-1 }, dc[5] = { 0,1,-1,0,0 };
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        deque<int> nodes;
        nodes.push_back(encode(0, 0, 0));

        while (!nodes.empty()) {
            decode(nodes.front(), r, c, cost);
            nodes.pop_front();

            if (r == row - 1 && c == column - 1) {  // 到达目的地
                break;
            }

            if (visited[r][c]) {
                continue;
            }
            visited[r][c] = true;

            int arrow = grid[r][c], nr = r + dr[arrow], nc = c + dc[arrow];
            if (nr >= 0 && nr < row && nc >= 0 && nc < column && !visited[nr][nc]) {
                nodes.push_front(encode(nr, nc, cost));  // 可以直达的地方放入队列头部，继续寻找下一个
            }

            for (int i = 1; i < 5; ++i) {
                if (i == arrow) {
                    continue;
                }

                nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < row && nc >= 0 && nc < column && !visited[nr][nc]) {
                    nodes.push_back(encode(nr, nc, cost + 1));  // 需要改变方向的放入队列尾部，cost加1
                }
            }
        }

        return cost;
    }

    int encode(int r, int c, int cost) {
        return (r << 16) | (c << 8) | cost;
    }

    void decode(int node, int& r, int& c, int& cost) {
        r = node >> 16;
        c = (node >> 8) & 0xff;
        cost = node & 0xff;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2} };
    check.checkInt(3, o.minCost(grid));

    grid = { {1,1,3},{3,2,2},{1,1,4} };
    check.checkInt(0, o.minCost(grid));

    grid = { {1,2},{4,3} };
    check.checkInt(1, o.minCost(grid));

    grid = { {2,2,2},{2,2,2} };
    check.checkInt(3, o.minCost(grid));

    grid = { {4} };
    check.checkInt(0, o.minCost(grid));

    grid = { {1,2,3,4,4,3,2,1,1,1},
        {1,2,3,4,4,3,2,1,2,2},
        {1,2,3,4,4,3,2,1,3,3},
        {1,2,3,4,4,3,2,1,4,4},
        {1,2,3,4,4,3,2,1,1,1},
        {1,2,3,4,4,3,2,1,2,2},
        {1,2,3,4,4,3,2,1,3,3},
        {1,2,3,4,4,3,2,1,4,4},
        {1,2,3,4,4,3,2,1,1,2},
        {1,2,3,4,4,3,2,1,3,4}, };
    check.checkInt(7, o.minCost(grid));
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
