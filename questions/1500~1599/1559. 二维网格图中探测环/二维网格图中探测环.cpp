/* 二维网格图中探测环.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维字符网格数组 grid ，大小为 m x n ，你需要检查 grid 中是否存在 相同值 形成的环。

一个环是一条开始和结束于同一个格子的长度 大于等于 4 的路径。对于一个给定的格子，你可以移动到它上、下、左、右四个方向相邻的格子之一，可以移动的前提是这两个格子有 相同的值 。

同时，你也不能回到上一次移动时所在的格子。比方说，环  (1, 1) -> (1, 2) -> (1, 1) 是不合法的，因为从 (1, 2) 移动到 (1, 1) 回到了上一次移动时的格子。

如果 grid 中有相同值形成的环，请你返回 true ，否则返回 false 。



示例 1：



输入：grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
输出：true
解释：如下图所示，有 2 个用不同颜色标出来的环：

示例 2：



输入：grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
输出：true
解释：如下图所示，只有高亮所示的一个合法环：

示例 3：



输入：grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
输出：false


提示：

m == grid.length
n == grid[i].length
1 <= m <= 500
1 <= n <= 500
grid 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
	bool containsCycle(vector<vector<char>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));

		for (int r = 0; r < m; ++r) {
			for (int c = 0; c < n; ++c) {
				if (!visited[r][c]) {
					if (DFS(grid, visited, grid[r][c], m, n, r, c, -1, -1)) {
						return true;
					}
				}
			}
		}

		return false;
	}

	bool DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, char target, int m, int n, int r, int c, int pr, int pc) {
		int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
		visited[r][c] = true;

		for (int i = 0; i < 4; ++i) {
			int nr = r + dr[i], nc = c + dc[i];
			if (nr >= 0 && nr < m && nc >= 0 && nc < n && (!(nr == pr && nc == pc)) && grid[nr][nc] == target) {
				if (visited[nr][nc] || DFS(grid, visited, target, m, n, nr, nc, r, c)) {
					return true;
				}
			}
		}

		return false;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<char>> grid = { {'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'} };
	check.checkBool(true, o.containsCycle(grid));

	grid = { {'c','c','c','a'},{'c','d','c','c'},{'c','c','e','c'},{'f','c','c','c'} };
	check.checkBool(true, o.containsCycle(grid));

	grid = { {'a','b','b'},{'b','z','b'},{'b','b','a'} };
	check.checkBool(false, o.containsCycle(grid));
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
