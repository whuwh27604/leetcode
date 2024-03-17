/* 元素和小于等于 k 的子矩阵的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数矩阵 grid 和一个整数 k。

返回包含 grid 左上角元素、元素和小于或等于 k 的
子矩阵
的数目。



示例 1：


输入：grid = [[7,6,3],[6,6,1]], k = 18
输出：4
解释：如上图所示，只有 4 个子矩阵满足：包含 grid 的左上角元素，并且元素和小于或等于 18 。
示例 2：


输入：grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
输出：6
解释：如上图所示，只有 6 个子矩阵满足：包含 grid 的左上角元素，并且元素和小于或等于 20 。


提示：

m == grid.length
n == grid[i].length
1 <= n, m <= 1000
0 <= grid[i][j] <= 1000
1 <= k <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
		int m = grid.size(), n = grid[0].size(), count = 0;
		vector<vector<int>> sums(m, vector<int>(n, 0));

		for (int c = 0; c < n; ++c) {
			sums[0][c] = grid[0][c];

			for (int r = 1; r < m; ++r) {
				sums[r][c] = sums[r - 1][c] + grid[r][c];
			}
		}

		for (int r = 0; r < m; ++r) {
			int sum = 0;

			for (int c = 0; c < n; ++c) {
				sum += sums[r][c];
				if (sum <= k) {
					++count;
				}
			}
		}

		return count;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> grid = { {7,6,3},{6,6,1} };
	check.checkInt(4, o.countSubmatrices(grid, 18));

	grid = { {7,2,9},{1,5,0},{2,6,6} };
	check.checkInt(6, o.countSubmatrices(grid, 20));
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
