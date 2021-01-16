/* 最小体力消耗路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。

请你返回从左上角走到右下角的最小 体力消耗值 。

 

示例 1：



输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
输出：2
解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
示例 2：



输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
输出：1
解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
示例 3：


输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
输出：0
解释：上图所示路径不需要消耗任何体力。
 

提示：

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-with-minimum-effort
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

struct pairCompare {
    bool operator()(const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2) const {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        int row = heights.size(), column = heights[0].size(), minEffort = 0;
        vector<vector<int>> efforts(row, vector<int>(column, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, pairCompare> dijkstra;
        dijkstra.push({ 0, {0,0} });

        while (!efforts.empty()) {
            int effort = dijkstra.top().first, r = dijkstra.top().second.first, c = dijkstra.top().second.second;
            dijkstra.pop();

            if (r == row - 1 && c == column - 1) {
                minEffort = effort;
                break;
            }

            if (effort >= efforts[r][c]) {
                continue;
            }

            efforts[r][c] = effort;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < column) {
                    dijkstra.push({ max(effort, abs(heights[r][c] - heights[nr][nc])), {nr, nc} });
                }
            }
        }

        return minEffort;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> heights = { {1,2,2},{3,8,2},{5,3,5} };
    check.checkInt(2, o.minimumEffortPath(heights));

    heights = { {1,2,3},{3,8,4},{5,3,5} };
    check.checkInt(1, o.minimumEffortPath(heights));

    heights = { {1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1} };
    check.checkInt(0, o.minimumEffortPath(heights));

    heights = { {5} };
    check.checkInt(0, o.minimumEffortPath(heights));

    heights = { {2,3,6,3,6,6,1,2},{4,5,6,5,5,10,1,2},{9,1,4,10,4,7,7,3} };
    check.checkInt(4, o.minimumEffortPath(heights));

    heights = { {1,10,6,7,9,10,4,9} };
    check.checkInt(9, o.minimumEffortPath(heights));
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
