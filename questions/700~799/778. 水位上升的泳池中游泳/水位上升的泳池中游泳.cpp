/* 水位上升的泳池中游泳.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个 N x N 的坐标方格 grid 中，每一个方格的值 grid[i][j] 表示在位置 (i,j) 的平台高度。

现在开始下雨了。当时间为 t 时，此时雨水导致水池中任意位置的水位为 t 。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。

你从坐标方格的左上平台 (0，0) 出发。最少耗时多久你才能到达坐标方格的右下平台 (N-1, N-1)？

 

示例 1:

输入: [[0,2],[1,3]]
输出: 3
解释:
时间为0时，你位于坐标方格的位置为 (0, 0)。
此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0 时的水位。

等时间到达 3 时，你才可以游向平台 (1, 1). 因为此时的水位是 3，坐标方格中的平台没有比水位 3 更高的，所以你可以游向坐标方格中的任意位置
示例2:

输入: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
输出: 16
解释:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

最终的路线用加粗进行了标记。
我们必须等到时间为 16，此时才能保证平台 (0, 0) 和 (4, 4) 是连通的
 

提示:

2 <= N <= 50.
grid[i][j] 是 [0, ..., N*N - 1] 的排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swim-in-rising-water
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
    int swimInWater(vector<vector<int>>& grid) {
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        int row = grid.size(), column = grid[0].size(), minTime = 0;
        vector<vector<int>> visited(row, vector<int>(column, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, pairCompare> dijkstra;
        dijkstra.push({ grid[0][0],{0,0} });

        while (!dijkstra.empty()) {
            minTime = dijkstra.top().first;
            int r = dijkstra.top().second.first, c = dijkstra.top().second.second;
            dijkstra.pop();
            visited[r][c] = 1;

            if (r == row - 1 && c == column - 1) {
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < column && visited[nr][nc] == 0) {
                    dijkstra.push({ max(minTime, grid[nr][nc]), {nr,nc} });
                }
            }
        }

        return minTime;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {3,2},{1,0} };
    check.checkInt(3, o.swimInWater(grid));

    grid = { {0,2},{1,3} };
    check.checkInt(3, o.swimInWater(grid));

    grid = { {0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6} };
    check.checkInt(16, o.swimInWater(grid));
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
