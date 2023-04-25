/* 网格图中最少访问的格子数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的 m x n 整数矩阵 grid 。你一开始的位置在 左上角 格子 (0, 0) 。

当你在格子 (i, j) 的时候，你可以移动到以下格子之一：

满足 j < k <= grid[i][j] + j 的格子 (i, k) （向右移动），或者
满足 i < k <= grid[i][j] + i 的格子 (k, j) （向下移动）。
请你返回到达 右下角 格子 (m - 1, n - 1) 需要经过的最少移动格子数，如果无法到达右下角格子，请你返回 -1 。



示例 1：



输入：grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
输出：4
解释：上图展示了到达右下角格子经过的 4 个格子。
示例 2：



输入：grid = [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]
输出：3
解释：上图展示了到达右下角格子经过的 3 个格子。
示例 3：



输入：grid = [[2,1,0],[1,0,0]]
输出：-1
解释：无法到达右下角格子。


提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 105
1 <= m * n <= 105
0 <= grid[i][j] < m * n
grid[m - 1][n - 1] == 0
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(column, inf));
        vector<vector<pair<int, int>>> cDps(column);

        for (int r = row - 1; r >= 0; --r) {
            vector<pair<int, int>> rDps;

            for (int c = column - 1; c >= 0; --c) {
                if (r == row - 1 && c == column - 1) {
                    dp[r][c] = 1;
                    rDps.push_back({ 1,column - 1 });
                    cDps[column - 1].push_back({ 1,row - 1 });
                    continue;
                }

                int len = grid[r][c];
                if (len == 0) {
                    continue;
                }

                // 程序主流程dp算法，在位置[r,c]，横向可以走到[r, c + grid[r][c]]，我们选择这里面dp最小的位置[r',c']，先一步走到[r',c']，再走到终点。纵向类似处理。
                dp[r][c] = min(dp[r][c], getMinDp(rDps, c + len) + 1);
                dp[r][c] = min(dp[r][c], getMinDp(cDps[c], r + len) + 1);
                addDp(rDps, dp[r][c], c);
                addDp(cDps[c], dp[r][c], r);
            }
        }

        return dp[0][0] == inf ? -1 : dp[0][0];
    }

    void addDp(vector<pair<int, int>>& dps, int dp, int index) {  // 按照从后往前，从下往上的顺序遍历，dps单调递增保存dp值，并同时记录下该dp值对应的index
        while (!dps.empty() && dps.back().first >= dp) {
            dps.pop_back();
        }

        dps.push_back({ dp,index });
    }

    int getMinDp(vector<pair<int, int>>& dps, int index) {  // 二分查找小于等于index范围内的最小dp值
        if (dps.empty()) {
            return inf;
        }

        int dp = inf, low = 0, high = dps.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (dps[mid].second <= index) {
                dp = dps[mid].first;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return dp;
    }

    int inf = INT_MAX / 2;
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {3,4,2,1},{4,2,1,1},{2,1,1,0},{3,4,1,0} };
    check.checkInt(3, o.minimumVisitedCells(grid));

    grid = { {2,1,0},{1,0,0} };
    check.checkInt(-1, o.minimumVisitedCells(grid));

    grid = { {3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0} };
    check.checkInt(4, o.minimumVisitedCells(grid));

    grid = { {3,0,0,20,0,0,0},{1,0,0,0,0,0,0},{1,0,0,0,0,0,0},{1,0,0,0,0,0,0},{1,1,9,1,1,0,1},{0,0,0,0,0,0,0} };
    check.checkInt(7, o.minimumVisitedCells(grid));
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
