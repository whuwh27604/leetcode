/* 最大人工岛.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在二维地图上， 0代表海洋， 1代表陆地，我们最多只能将一格 0 海洋变成 1变成陆地。

进行填海之后，地图上最大的岛屿面积是多少？（上、下、左、右四个方向相连的 1 可形成岛屿）

示例 1:

输入: [[1, 0], [0, 1]]
输出: 3
解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
示例 2:

输入: [[1, 1], [1, 0]]
输出: 4
解释: 将一格0变成1，岛屿的面积扩大为 4。
示例 3:

输入: [[1, 1], [1, 1]]
输出: 4
解释: 没有0可以让我们变成1，面积依然为 4。
说明:

1 <= grid.length = grid[0].length <= 50
0 <= grid[i][j] <= 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/making-a-large-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<int> islandAreas = { 0,0 };
        getAllIslandAreas(grid, islandAreas);

        int allArea = grid.size() * grid.size();
        if (islandAreas.back() == allArea) {  // 整个grid全部是一个island
            return allArea;
        }

        return getMaxIslandArea(grid, islandAreas);
    }

    void getAllIslandAreas(vector<vector<int>>& grid, vector<int>& islandAreas) {
        int i, j, index = 2, size = grid.size();

        for (i = 0; i < size; ++i) {
            for (j = 0; j < size; ++j) {
                if (grid[i][j] == 1) {
                    islandAreas.push_back(getIslandArea(grid, i, j, index++));
                }
            }
        }
    }

    int getIslandArea(vector<vector<int>>& grid, int r, int c, int index) {
        int area = 1, i, size = grid.size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        grid[r][c] = index;

        for (i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < size && nc >= 0 && nc < size && grid[nr][nc] == 1) {
                area += getIslandArea(grid, nr, nc, index);
            }
        }

        return area;
    }

    int getMaxIslandArea(vector<vector<int>>& grid, vector<int>& islandAreas) {
        int r, c, i, size = grid.size(), maxIslandArea = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        for (r = 0; r < size; ++r) {
            for (c = 0; c < size; ++c) {
                if (grid[r][c] != 0) {
                    continue;
                }

                vector<int> islandIndices(4, 0);  // 缓存4个方向上的island index
                int area = 1;

                for (i = 0; i < 4; ++i) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr >= 0 && nr < size && nc >= 0 && nc < size  // 连到了一个不同的island
                        && grid[nr][nc] != islandIndices[0] && grid[nr][nc] != islandIndices[1] && grid[nr][nc] != islandIndices[2]) {
                        islandIndices[i] = grid[nr][nc];  // 记录这个island index
                        area += islandAreas[grid[nr][nc]];  // 把面积相加
                    }
                }

                maxIslandArea = max(maxIslandArea, area);
            }
        }

        return maxIslandArea;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,0},{0,1} };
    check.checkInt(3, o.largestIsland(grid));

    grid = { {1,1},{1,0} };
    check.checkInt(4, o.largestIsland(grid));

    grid = { {1,1},{1,1} };
    check.checkInt(4, o.largestIsland(grid));

    grid = { {0} };
    check.checkInt(1, o.largestIsland(grid));

    grid = { {1} };
    check.checkInt(1, o.largestIsland(grid));

    grid = { {0,1,0},{1,0,1},{0,1,0} };
    check.checkInt(5, o.largestIsland(grid));

    grid = { {1,0,0,1,0,1,0,0},
        {0,0,0,0,0,1,0,1},
        {0,1,0,0,0,1,0,1},
        {0,0,1,1,0,1,0,1},
        {0,0,1,0,0,1,0,1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0} };
    check.checkInt(10, o.largestIsland(grid));
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
