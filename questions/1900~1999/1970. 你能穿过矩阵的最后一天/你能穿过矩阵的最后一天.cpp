/* 你能穿过矩阵的最后一天.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 1 开始的二进制矩阵，其中 0 表示陆地，1 表示水域。同时给你 row 和 col 分别表示矩阵中行和列的数目。

一开始在第 0 天，整个 矩阵都是 陆地 。但每一天都会有一块新陆地被 水 淹没变成水域。给你一个下标从 1 开始的二维数组 cells ，其中 cells[i] = [ri, ci] 表示在第 i 天，第 ri 行 ci 列（下标都是从 1 开始）的陆地会变成 水域 （也就是 0 变成 1 ）。

你想知道从矩阵最 上面 一行走到最 下面 一行，且只经过陆地格子的 最后一天 是哪一天。你可以从最上面一行的 任意 格子出发，到达最下面一行的 任意 格子。你只能沿着 四个 基本方向移动（也就是上下左右）。

请返回只经过陆地格子能从最 上面 一行走到最 下面 一行的 最后一天 。

 

示例 1：


输入：row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
输出：2
解释：上图描述了矩阵从第 0 天开始是如何变化的。
可以从最上面一行到最下面一行的最后一天是第 2 天。
示例 2：


输入：row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
输出：1
解释：上图描述了矩阵从第 0 天开始是如何变化的。
可以从最上面一行到最下面一行的最后一天是第 1 天。
示例 3：


输入：row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
输出：3
解释：上图描述了矩阵从第 0 天开始是如何变化的。
可以从最上面一行到最下面一行的最后一天是第 3 天。
 

提示：

2 <= row, col <= 2 * 104
4 <= row * col <= 2 * 104
cells.length == row * col
1 <= ri <= row
1 <= ci <= col
cells 中的所有格子坐标都是 唯一 的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/last-day-where-you-can-still-cross
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        parents.resize(size);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        parents[find(x)] = find(y);
    }

private:
    vector<int> parents;
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        col += 2;
        vector<vector<int>> grid(row, vector<int>(col, 0));
        DSU dsu(row * col);
        int day = 0, size = cells.size(), left = 0, right = col - 1;
        int dr[8] = { 0,1,1,1,0,-1,-1,-1 }, dc[8] = { 1,1,0,-1,-1,-1,0,1 };

        for (int i = 0; i < row; ++i) {
            grid[i][0] = grid[i][col - 1] = 1;
            dsu.merge(left, i * col);
            dsu.merge(right, i * col + col - 1);
        }

        for (day = 0; day < size; ++day) {
            int r = cells[day][0] - 1, c = cells[day][1];
            grid[r][c] = 1;

            for (int i = 0; i < 8; ++i) {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col + 2 && grid[nr][nc] == 1) {
                    dsu.merge(nr * col + nc, r * col + c);
                }
            }

            if (dsu.find(left) == dsu.find(right)) {
                break;
            }
        }

        return day;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> cells = { {1,1},{2,1},{1,2},{2,2} };
    check.checkInt(2, o.latestDayToCross(2, 2, cells));

    cells = { {1,1},{1,2},{2,1},{2,2} };
    check.checkInt(1, o.latestDayToCross(2, 2, cells));

    cells = { {1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1} };
    check.checkInt(3, o.latestDayToCross(3, 3, cells));

    cells = { {4,2},{6,2},{2,1},{4,1},{6,1},{3,1},{2,2},{3,2},{1,1},{5,1},{5,2},{1,2} };
    check.checkInt(3, o.latestDayToCross(6, 2, cells));
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
