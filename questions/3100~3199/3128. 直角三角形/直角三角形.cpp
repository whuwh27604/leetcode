/* 直角三角形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维 boolean 矩阵 grid 。

请你返回使用 grid 中的 3 个元素可以构建的 直角三角形 数目，且满足 3 个元素值 都 为 1 。

注意：

如果 grid 中 3 个元素满足：一个元素与另一个元素在 同一行，同时与第三个元素在 同一列 ，那么这 3 个元素称为一个 直角三角形 。这 3 个元素互相之间不需要相邻。


示例 1：

0	1	0
0	1	1
0	1	0
0	1	0
0	1	1
0	1	0
输入：grid = [[0,1,0],[0,1,1],[0,1,0]]

输出：2

解释：

有 2 个直角三角形。

示例 2：

1	0	0	0
0	1	0	1
1	0	0	0
输入：grid = [[1,0,0,0],[0,1,0,1],[1,0,0,0]]

输出：0

解释：

没有直角三角形。

示例 3：

1	0	1
1	0	0
1	0	0
1	0	1
1	0	0
1	0	0
输入：grid = [[1,0,1],[1,0,0],[1,0,0]]

输出：2

解释：

有两个直角三角形。



提示：

1 <= grid.length <= 1000
1 <= grid[i].length <= 1000
0 <= grid[i][j] <= 1
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
		int row = (int)grid.size(), column = (int)grid[0].size();
		vector<vector<int>> rowSum(row, vector<int>(column, 0)), columnSum(row, vector<int>(column, 0));

		getRowSum(row, column, grid, rowSum);
		getColumnSum(row, column, grid, columnSum);

		return getTriangles(row, column, grid, rowSum, columnSum);
    }

	void getRowSum(int row, int column, vector<vector<int>>& grid, vector<vector<int>>& rowSum) {
		for (int r = 0; r < row; ++r) {
			rowSum[r][0] = grid[r][0];

			for (int c = 1; c < column; ++c) {
				rowSum[r][c] = rowSum[r][c - 1] + grid[r][c];
			}
		}
	}

	void getColumnSum(int row, int column, vector<vector<int>>& grid, vector<vector<int>>& columnSum) {
		for (int c = 0; c < column; ++c) {
			columnSum[0][c] = grid[0][c];

			for (int r = 1; r < row; ++r) {
				columnSum[r][c] = columnSum[r - 1][c] + grid[r][c];
			}
		}
	}

	long long getTriangles(int row, int column, vector<vector<int>>& grid, vector<vector<int>>& rowSum, vector<vector<int>>& columnSum) {
		long long triangles = 0;

		for (int r = 0; r < row; ++r) {
			for (int c = 0; c < column; ++c) {
				if (grid[r][c] == 1) {
					triangles += ((long long)rowSum[r][c] - 1) * ((long long)columnSum[r][c] - 1);
					triangles += ((long long)rowSum[r][column - 1] - rowSum[r][c]) * ((long long)columnSum[r][c] - 1);
					triangles += ((long long)rowSum[r][c] - 1) * ((long long)columnSum[row - 1][c] - columnSum[r][c]);
					triangles += ((long long)rowSum[r][column - 1] - rowSum[r][c]) * ((long long)columnSum[row - 1][c] - columnSum[r][c]);
				}
			}
		}

		return triangles;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> grid = { {0,1,0},{0,1,1},{0,1,0} };
	check.checkLongLong(2, o.numberOfRightTriangles(grid));

	grid = { {1,0,0,0},{0,1,0,1},{1,0,0,0} };
	check.checkLongLong(0, o.numberOfRightTriangles(grid));

	grid = { {1,0,1},{1,0,0},{1,0,0} };
	check.checkLongLong(2, o.numberOfRightTriangles(grid));
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
