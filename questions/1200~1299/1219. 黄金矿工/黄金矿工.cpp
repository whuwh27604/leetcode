/* 黄金矿工.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。

为了使收益最大化，矿工需要按以下规则来开采黄金：

每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。
 

示例 1：

输入：grid = [[0,6,0],[5,8,7],[0,9,0]]
输出：24
解释：
[[0,6,0],
 [5,8,7],
 [0,9,0]]
一种收集最多黄金的路线是：9 -> 8 -> 7。
示例 2：

输入：grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
输出：28
解释：
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
一种收集最多黄金的路线是：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7。
 

提示：

1 <= grid.length, grid[i].length <= 15
0 <= grid[i][j] <= 100
最多 25 个单元格中有黄金。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-with-maximum-gold
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int i, j, row = grid.size(), column = grid[0].size(), maxGold = 0;

        for (i = 0; i < row; ++i) {  // 考虑环路的存在，准确找到一条路径的端点比较繁琐，而且题目说最多25个黄金格，所以全部尝试一遍吧
            for (j = 0; j < column; ++j) {
                if (grid[i][j] > 0) {
                    maxGold = max(maxGold, DFS(grid, i, j));
                }
            }
        }

        return maxGold;
    }

    int DFS(vector<vector<int>>& grid, int rIndex, int cIndex) {
        grid[rIndex][cIndex] = -grid[rIndex][cIndex];  // 避免回头路

        int row = grid.size(), column = grid[0].size(), maxGold = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        for (int i = 0; i < 4; ++i) {
            int r = rIndex + dr[i], c = cIndex + dc[i];
            if (r >= 0 && r < row && c >= 0 && c < column && grid[r][c] > 0) {
                maxGold = max(maxGold, DFS(grid, r, c));
            }
        }

        grid[rIndex][cIndex] = -grid[rIndex][cIndex];  // 回溯，尝试其它路径
        return grid[rIndex][cIndex] + maxGold;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {0,6,0},{5,8,7},{0,9,0} };
    check.checkInt(24, o.getMaximumGold(grid));

    grid = { {1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20} };
    check.checkInt(28, o.getMaximumGold(grid));

    grid = { {34,0,1,0,0,0},{0,0,2,0,1,0},{5,4,3,7,4,2},{0,0,5,0,1,4},{0,0,5,0,2,3} };
    check.checkInt(36, o.getMaximumGold(grid));

    grid = { {0,1,6,20,0},{0,0,3,0,0},{16,9,16,8,0},{14,0,4,20,9} };
    check.checkInt(92, o.getMaximumGold(grid));

    grid = { {7} };
    check.checkInt(7, o.getMaximumGold(grid));

    grid = { {0} };
    check.checkInt(0, o.getMaximumGold(grid));
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
