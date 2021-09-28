/* 主题空间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「以扣会友」线下活动所在场地由若干主题空间与走廊组成，场地的地图记作由一维字符串型数组 grid，字符串中仅包含 "0"～"5" 这 6 个字符。地图上每一个字符代表面积为 1 的区域，其中 "0" 表示走廊，其他字符表示主题空间。相同且连续（连续指上、下、左、右四个方向连接）的字符组成同一个主题空间。

假如整个 grid 区域的外侧均为走廊。请问，不与走廊直接相邻的主题空间的最大面积是多少？如果不存在这样的空间请返回 0。

示例 1:

输入：grid = ["110","231","221"]

输出：1

解释：4 个主题空间中，只有 1 个不与走廊相邻，面积为 1。


示例 2:

输入：grid = ["11111100000","21243101111","21224101221","11111101111"]

输出：3

解释：8 个主题空间中，有 5 个不与走廊相邻，面积分别为 3、1、1、1、2，最大面积为 3。


提示：

1 <= grid.length <= 500
1 <= grid[i].length <= 500
grid[i][j] 仅可能是 "0"～"5"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/YesdPw
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestArea(vector<string>& grid) {
        int i, j, row = grid.size(), column = grid[0].size(), maxArea = 0;

        setCorridors(grid);

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (grid[i][j] != visited) {
                    maxArea = max(maxArea, DFS(grid, i, j, grid[i][j]));
                }
            }
        }

        return maxArea;
    }

    void setCorridors(vector<string>& grid) {
        int row = grid.size(), column = grid[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        queue<pair<int, char>> bfs;
        init(grid, bfs);

        while (!bfs.empty()) {
            int r = bfs.front().first >> 16, c = bfs.front().first & 0xffff;
            char theme = bfs.front().second;
            bfs.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < column && grid[nr][nc] != visited && (theme == '0' || theme == grid[nr][nc])) {
                    bfs.push({ (nr << 16) | nc, grid[nr][nc] });
                    grid[nr][nc] = visited;
                }
            }
        }
    }

    void init(vector<string>& grid, queue<pair<int, char>>& bfs) {
        int i, j, row = grid.size(), column = grid[0].size();

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (i == 0 || i == row - 1 || j == 0 || j == column - 1 || grid[i][j] == '0') {
                    bfs.push({ (i << 16) | j, grid[i][j] });
                    grid[i][j] = visited;
                }
            }
        }
    }

    int DFS(vector<string>& grid, int r, int c, char theme) {
        int row = grid.size(), column = grid[0].size(), area = 1;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        grid[r][c] = visited;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];

            if (nr >= 0 && nr < row && nc >= 0 && nc < column && grid[nr][nc] == theme) {
                area += DFS(grid, nr, nc, theme);
            }
        }

        return area;
    }

private:
    const char visited = '9';
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> grid = { "110","231","221" };
    check.checkInt(1, o.largestArea(grid));

    grid = { "11111100000","21243101111","21224101221","11111101111" };
    check.checkInt(3, o.largestArea(grid));

    grid = { "1" };
    check.checkInt(0, o.largestArea(grid));

    grid = { "1111","1101","1111" };
    check.checkInt(0, o.largestArea(grid));

    grid = { "111","222","333" };
    check.checkInt(0, o.largestArea(grid));

    grid = { "331223024","342452255","434132314","314112223","255231220","100115032","440233544","455221424" };
    check.checkInt(3, o.largestArea(grid));

    grid = { "111111","122221","122221","122221","122221","111111" };
    check.checkInt(16, o.largestArea(grid));
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
