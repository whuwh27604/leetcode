/* 构造相同颜色的正方形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维 3 x 3 的矩阵 grid ，每个格子都是一个字符，要么是 'B' ，要么是 'W' 。字符 'W' 表示白色，字符 'B' 表示黑色。

你的任务是改变 至多一个 格子的颜色，使得矩阵中存在一个 2 x 2 颜色完全相同的正方形。

如果可以得到一个相同颜色的 2 x 2 正方形，那么返回 true ，否则返回 false 。



示例 1：










输入：grid = [["B","W","B"],["B","W","W"],["B","W","B"]]

输出：true

解释：

修改 grid[0][2] 的颜色，可以满足要求。

示例 2：










输入：grid = [["B","W","B"],["W","B","W"],["B","W","B"]]

输出：false

解释：

只改变一个格子颜色无法满足要求。

示例 3：










输入：grid = [["B","W","B"],["B","W","W"],["B","W","W"]]

输出：true

解释：

grid 已经包含一个 2 x 2 颜色相同的正方形了。



提示：

grid.length == 3
grid[i].length == 3
grid[i][j] 要么是 'W' ，要么是 'B' 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
		return count(grid, 0, 0) != 2 || count(grid, 0, 1) != 2 || count(grid, 1, 0) != 2 || count(grid, 1, 1) != 2;
    }

	int count(vector<vector<char>>& grid, int r, int c) {
		int cnt = 0;

		if (grid[r][c] == 'B') {
			++cnt;
		}
		if (grid[r][c + 1] == 'B') {
			++cnt;
		}
		if (grid[r + 1][c] == 'B') {
			++cnt;
		}
		if (grid[r + 1][c + 1] == 'B') {
			++cnt;
		}

		return cnt;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<char>> grid = { {'B','W','B'},{'B','W','W'},{'B','W','B'} };
	check.checkBool(true, o.canMakeSquare(grid));

	grid = { {'B','W','B'},{'W','B','W'},{'B','W','B'} };
	check.checkBool(false, o.canMakeSquare(grid));

	grid = { {'B','W','B'},{'B','W','W'},{'B','W','W'} };
	check.checkBool(true, o.canMakeSquare(grid));
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
