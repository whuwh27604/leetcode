/* 判断矩阵是否满足条件.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 m x n 的二维矩阵 grid 。你需要判断每一个格子 grid[i][j] 是否满足：

如果它下面的格子存在，那么它需要等于它下面的格子，也就是 grid[i][j] == grid[i + 1][j] 。
如果它右边的格子存在，那么它需要不等于它右边的格子，也就是 grid[i][j] != grid[i][j + 1] 。
如果 所有 格子都满足以上条件，那么返回 true ，否则返回 false 。



示例 1：

输入：grid = [[1,0,2],[1,0,2]]

输出：true

解释：



网格图中所有格子都符合条件。

示例 2：

输入：grid = [[1,1,1],[0,0,0]]

输出：false

解释：



同一行中的格子值都相等。

示例 3：

输入：grid = [[1],[2],[3]]

输出：false

解释：



同一列中的格子值不相等。



提示：

1 <= n, m <= 10
0 <= grid[i][j] <= 9
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
		int row = (int)grid.size(), column = (int)grid[0].size();

		for (int c = 0; c < column; ++c) {
			for (int r = 0; r < row - 1; ++r) {
				if (grid[r][c] != grid[r + 1][c]) {
					return false;
				}
			}
		}

		for (int c = 0; c < column - 1; ++c) {
			if (grid[0][c] == grid[0][c + 1]) {
				return false;
			}
		}

		return true;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> grid = { {1,0,2},{1,0,2} };
	check.checkBool(true, o.satisfiesConditions(grid));

	grid = { {1,1,1},{0,0,0} };
	check.checkBool(false, o.satisfiesConditions(grid));

	grid = { {1},{2},{3} };
	check.checkBool(false, o.satisfiesConditions(grid));
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
