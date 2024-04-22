/* 使矩阵满足条件的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 m x n 的二维矩形 grid 。每次 操作 中，你可以将 任一 格子的值修改为 任意 非负整数。完成所有操作后，你需要确保每个格子 grid[i][j] 的值满足：

如果下面相邻格子存在的话，它们的值相等，也就是 grid[i][j] == grid[i + 1][j]（如果存在）。
如果右边相邻格子存在的话，它们的值不相等，也就是 grid[i][j] != grid[i][j + 1]（如果存在）。
请你返回需要的 最少 操作数目。



示例 1：

输入：grid = [[1,0,2],[1,0,2]]

输出：0

解释：



矩阵中所有格子已经满足要求。

示例 2：

输入：grid = [[1,1,1],[0,0,0]]

输出：3

解释：



将矩阵变成 [[1,0,1],[1,0,1]] ，它满足所有要求，需要 3 次操作：

将 grid[1][0] 变为 1 。
将 grid[0][1] 变为 0 。
将 grid[1][2] 变为 1 。
示例 3：

输入：grid = [[1],[2],[3]]

输出：2

解释：



这个矩阵只有一列，我们可以通过 2 次操作将所有格子里的值变为 1 。



提示：

1 <= n, m <= 1000
0 <= grid[i][j] <= 9
*/

#include <iostream>

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
		int row = (int)grid.size(), column = (int)grid[0].size(), type = 10;
		vector<vector<int>> minOpers(column, vector<int>(10, 0));  // minOpers[c][i] ：把第c列变为i的操作次数

		for (int c = 0; c < column; ++c) {
			vector<int> count(type, 0);

			for (int r = 0; r < row; ++r) {
				++count[grid[r][c]];
			}

			for (int i = 0; i < type; ++i) {
				minOpers[c][i] = row - count[i];
			}
		}

		vector<int> minOperations = minOpers[0];  // minOperations[c][i] ：把grid[0, c]列，最后一列变为i的最小操作次数

		for (int c = 1; c < column; ++c) {
			vector<int> tmp(type, INT_MAX);

			for (int i = 0; i < type; ++i) {
				for (int j = 0; j < type; ++j) {
					if (j != i) {
						tmp[i] = min(tmp[i], minOpers[c][i] + minOperations[j]);
					}
				}
			}

			minOperations = tmp;
		}

		return *min_element(minOperations.begin(), minOperations.end());
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> grid = { {1,0,2},{1,0,2} };
	check.checkInt(0, o.minimumOperations(grid));

	grid = { {1,1,1},{0,0,0} };
	check.checkInt(3, o.minimumOperations(grid));

	grid = { {1},{2},{3} };
	check.checkInt(2, o.minimumOperations(grid));
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
