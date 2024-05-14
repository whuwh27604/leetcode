/* 矩阵中的最大得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 正整数 组成、大小为 m x n 的矩阵 grid。你可以从矩阵中的任一单元格移动到另一个位于正下方或正右侧的任意单元格（不必相邻）。从值为 c1 的单元格移动到值为 c2 的单元格的得分为 c2 - c1 。

你可以从 任一 单元格开始，并且必须至少移动一次。

返回你能得到的 最大 总得分。



示例 1：


输入：grid = [[9,5,7,3],[8,9,6,1],[6,7,14,3],[2,5,3,1]]

输出：9

解释：从单元格 (0, 1) 开始，并执行以下移动：
- 从单元格 (0, 1) 移动到 (2, 1)，得分为 7 - 5 = 2 。
- 从单元格 (2, 1) 移动到 (2, 2)，得分为 14 - 7 = 7 。
总得分为 2 + 7 = 9 。

示例 2：



输入：grid = [[4,3,2],[3,2,1]]

输出：-1

解释：从单元格 (0, 0) 开始，执行一次移动：从 (0, 0) 到 (0, 1) 。得分为 3 - 4 = -1 。



提示：

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
1 <= grid[i][j] <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
		int row = (int)grid.size(), column = (int)grid[0].size();
		int num = grid[row - 1][column - 1];
		vector<vector<int>> dp(row, vector<int>(column));
		dp[row - 1][column - 1] = num;
		int maxRowDp = num;
		vector<int> maxColumnDp(column);
		maxColumnDp[column - 1] = num;
		int ans = INT_MIN;

		for (int c = column - 2; c >= 0; --c) {
			dp[row - 1][c] = maxRowDp - grid[row - 1][c];
			ans = max(ans, dp[row - 1][c]);
			int sum = grid[row - 1][c];
			if (dp[row - 1][c] > 0) {
				sum += dp[row - 1][c];
			}
			maxRowDp = max(maxRowDp, sum);
			maxColumnDp[c] = sum;
		}

		for (int r = row - 2; r >= 0; --r) {
			int c = column - 1;
			dp[r][c] = maxColumnDp[c] - grid[r][c];
			ans = max(ans, dp[r][c]);
			int sum = grid[r][c];
			if (dp[r][c] > 0) {
				sum += dp[r][c];
			}
			maxRowDp = sum;
			maxColumnDp[c] = max(maxColumnDp[c], sum);

			for (--c; c >= 0; --c) {
				dp[r][c] = maxColumnDp[c] - grid[r][c];
				dp[r][c] = max(dp[r][c], maxRowDp - grid[r][c]);
				ans = max(ans, dp[r][c]);
				sum = grid[r][c];
				if (dp[r][c] > 0) {
					sum += dp[r][c];
				}
				maxRowDp = max(maxRowDp, sum);
				maxColumnDp[c] = max(maxColumnDp[c], sum);
			}
		}

		return ans;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> grid = { {9,5,7,3},{8,9,6,1},{6,7,14,3},{2,5,3,1} };
	check.checkInt(9, o.maxScore(grid));

	grid = { {4,3,2},{3,2,1} };
	check.checkInt(-1, o.maxScore(grid));
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
