/* 在矩阵上写出字母 Y 所需的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、大小为 n x n 的矩阵 grid ，其中 n 为奇数，且 grid[r][c] 的值为 0 、1 或 2 。

如果一个单元格属于以下三条线中的任一一条，我们就认为它是字母 Y 的一部分：

从左上角单元格开始到矩阵中心单元格结束的对角线。
从右上角单元格开始到矩阵中心单元格结束的对角线。
从中心单元格开始到矩阵底部边界结束的垂直线。
当且仅当满足以下全部条件时，可以判定矩阵上写有字母 Y ：

属于 Y 的所有单元格的值相等。
不属于 Y 的所有单元格的值相等。
属于 Y 的单元格的值与不属于Y的单元格的值不同。
每次操作你可以将任意单元格的值改变为 0 、1 或 2 。返回在矩阵上写出字母 Y 所需的 最少 操作次数。



示例 1：


输入：grid = [[1,2,2],[1,1,0],[0,1,0]]
输出：3
解释：将在矩阵上写出字母 Y 需要执行的操作用蓝色高亮显示。操作后，所有属于 Y 的单元格（加粗显示）的值都为 1 ，而不属于 Y 的单元格的值都为 0 。
可以证明，写出 Y 至少需要进行 3 次操作。
示例 2：


输入：grid = [[0,1,0,1,0],[2,1,0,1,2],[2,2,2,0,1],[2,2,2,2,2],[2,1,2,2,2]]
输出：12
解释：将在矩阵上写出字母 Y 需要执行的操作用蓝色高亮显示。操作后，所有属于 Y 的单元格（加粗显示）的值都为 0 ，而不属于 Y 的单元格的值都为 2 。
可以证明，写出 Y 至少需要进行 12 次操作。


提示：

3 <= n <= 49
n == grid.length == grid[i].length
0 <= grid[i][j] <= 2
n 为奇数。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
		int n = grid.size();

		return min({ getOperations(grid, n, 0, 1),
			getOperations(grid, n, 0, 2),
			getOperations(grid, n, 1, 0),
			getOperations(grid, n, 1, 2),
			getOperations(grid, n, 2, 0),
			getOperations(grid, n, 2, 1), });
    }

	int getOperations(vector<vector<int>>& grid, int n, int y, int other) {
		int opers = 0;

		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < n; ++c) {
				bool isY = isYCell(n, r, c);
				if ((isY && grid[r][c] != y) || (!isY && grid[r][c] != other)) {
					++opers;
				}
			}
		}

		return opers;
	}

	bool isYCell(int n, int r, int c) {
		int half = n / 2;

		return (r == c && c <= half) || (r + c == n - 1 && c > half) || (c == half && r > half);
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> grid = { {1,2,2},{1,1,0},{0,1,0} };
	check.checkInt(3, o.minimumOperationsToWriteY(grid));

	grid = { {0,1,0,1,0},{2,1,0,1,2},{2,2,2,0,1},{2,2,2,2,2},{2,1,2,2,2} };;
	check.checkInt(12, o.minimumOperationsToWriteY(grid));
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
