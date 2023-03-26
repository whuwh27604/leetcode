/* 检查骑士巡视方案.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
骑士在一张 n x n 的棋盘上巡视。在有效的巡视方案中，骑士会从棋盘的 左上角 出发，并且访问棋盘上的每个格子 恰好一次 。

给你一个 n x n 的整数矩阵 grid ，由范围 [0, n * n - 1] 内的不同整数组成，其中 grid[row][col] 表示单元格 (row, col) 是骑士访问的第 grid[row][col] 个单元格。骑士的行动是从下标 0 开始的。

如果 grid 表示了骑士的有效巡视方案，返回 true；否则返回 false。

注意，骑士行动时可以垂直移动两个格子且水平移动一个格子，或水平移动两个格子且垂直移动一个格子。下图展示了骑士从某个格子出发可能的八种行动路线。




示例 1：


输入：grid = [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]
输出：true
解释：grid 如上图所示，可以证明这是一个有效的巡视方案。
示例 2：


输入：grid = [[0,3,6],[5,8,1],[2,7,4]]
输出：false
解释：grid 如上图所示，考虑到骑士第 7 次行动后的位置，第 8 次行动是无效的。


提示：

n == grid.length == grid[i].length
3 <= n <= 7
0 <= grid[row][col] < n * n
grid 中的所有整数 互不相同
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return false;
        }

        int size = grid.size(), r = 0, c = 0;
        int dr[8] = { -2,-1,1,2,2,1,-1,-2 }, dc[8] = { 1,2,2,1,-1,-2,-2,-1 };

        for (int step = 1; step < size * size; ++step) {
            bool find = false;

            for (int i = 0; i < 8; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < size && nc >= 0 && nc < size && grid[nr][nc] == step) {
                    r = nr, c = nc;
                    find = true;
                    break;
                }
            }

            if (!find) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22} };
    check.checkBool(true, o.checkValidGrid(grid));

    grid = { {0,3,6},{5,8,1},{2,7,4} };
    check.checkBool(false, o.checkValidGrid(grid));

    grid = { {24,11,22,17,4},{21,16,5,12,9},{6,23,10,3,18},{15,20,1,8,13},{0,7,14,19,2} };
    check.checkBool(false, o.checkValidGrid(grid));

    grid = { {8,3,6},{5,0,1},{2,7,4} };
    check.checkBool(false, o.checkValidGrid(grid));
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
