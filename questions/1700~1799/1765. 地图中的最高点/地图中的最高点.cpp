/* 地图中的最高点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 m x n 的整数矩阵 isWater ，它代表了一个由 陆地 和 水域 单元格组成的地图。

如果 isWater[i][j] == 0 ，格子 (i, j) 是一个 陆地 格子。
如果 isWater[i][j] == 1 ，格子 (i, j) 是一个 水域 格子。
你需要按照如下规则给每个单元格安排高度：

每个格子的高度都必须是非负的。
如果一个格子是是 水域 ，那么它的高度必须为 0 。
任意相邻的格子高度差 至多 为 1 。当两个格子在正东、南、西、北方向上相互紧挨着，就称它们为相邻的格子。（也就是说它们有一条公共边）
找到一种安排高度的方案，使得矩阵中的最高高度值 最大 。

请你返回一个大小为 m x n 的整数矩阵 height ，其中 height[i][j] 是格子 (i, j) 的高度。如果有多种解法，请返回 任意一个 。

 

示例 1：



输入：isWater = [[0,1],[0,0]]
输出：[[1,0],[2,1]]
解释：上图展示了给各个格子安排的高度。
蓝色格子是水域格，绿色格子是陆地格。
示例 2：



输入：isWater = [[0,0,1],[1,0,0],[0,0,0]]
输出：[[1,1,0],[0,1,1],[1,2,2]]
解释：所有安排方案中，最高可行高度为 2 。
任意安排方案中，只要最高高度为 2 且符合上述规则的，都为可行方案。
 

提示：

m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j] 要么是 0 ，要么是 1 。
至少有 1 个水域格子。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/map-of-highest-peak
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r, c, row = isWater.size(), column = isWater[0].size(), height = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        vector<vector<int>> grid(row, vector<int>(column, -1));
        queue<pair<int, int>> bfs;

        init(isWater, bfs, grid);

        while (!bfs.empty()) {
            int size = bfs.size();
            ++height;

            for (int i = 0; i < size; ++i) {
                r = bfs.front().first, c = bfs.front().second;
                bfs.pop();

                for (int j = 0; j < 4; ++j) {
                    int nr = r + dr[j], nc = c + dc[j];

                    if (nr >= 0 && nr < row && nc >= 0 && nc < column && grid[nr][nc] == -1) {
                        grid[nr][nc] = height;
                        bfs.push({ nr, nc });
                    }
                }
            }
        }

        return grid;
    }

    void init(vector<vector<int>>& isWater, queue<pair<int, int>>& bfs, vector<vector<int>>& grid) {
        for (int r = 0; r < (int)isWater.size(); ++r) {
            for (int c = 0; c < (int)isWater[0].size(); ++c) {
                if (isWater[r][c] == 1) {
                    bfs.push({ r, c });
                    grid[r][c] = 0;
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> isWater = { {0,1},{0,0} };
    vector<vector<int>> actual = o.highestPeak(isWater);
    vector<vector<int>> expected = { {1,0},{2,1} };
    check.checkIntVectorVector(expected, actual);

    isWater = { {0,0,1},{1,0,0},{0,0,0} };
    actual = o.highestPeak(isWater);
    expected = { {1,1,0},{0,1,1},{1,2,2} };
    check.checkIntVectorVector(expected, actual);
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
