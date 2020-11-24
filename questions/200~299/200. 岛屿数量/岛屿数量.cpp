/* 岛屿数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int _size) {
        size = _size;
        parents = new int[size];

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    ~DSU() {
        delete[] parents;
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        parents[find(x)] = find(y);
    }

    int count() {
        unordered_set<int> sets;

        for (int i = 0; i < size; ++i) {
            sets.insert(find(i));
        }

        return sets.size();
    }

private:
    int* parents;
    int size;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int i, j, row = grid.size(), column = grid[0].size(), size = row * column;
        DSU dsu(size + 1);

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (grid[i][j] == '0') {
                    dsu.merge(i * column + j, size);
                }
                else {
                    if (i > 0 && grid[i][j] == grid[i - 1][j]) {
                        dsu.merge(i * column + j, (i - 1) * column + j);
                    }

                    if (j > 0 && grid[i][j] == grid[i][j - 1]) {
                        dsu.merge(i * column + j, i * column + j - 1);
                    }
                }
            }
        }

        return dsu.count() - 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<char>> grid = { {'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'} };
    check.checkInt(1, o.numIslands(grid));

    grid = { {'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'} };
    check.checkInt(3, o.numIslands(grid));

    grid = { {'0'} };
    check.checkInt(0, o.numIslands(grid));

    grid = { {'1','1','1','1','1'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'1','1','1','1','1'} };
    check.checkInt(1, o.numIslands(grid));

    grid = { {'1','1','0','0'},{'1','1','0','0'},{'0','0','1','1'},{'0','0','1','1'} };
    check.checkInt(2, o.numIslands(grid));

    grid = { {'1','0','1','0','1'},{'0','1','0','1','0'},{'1','0','1','0','1'},{'0','1','0','1','0'},{'1','0','1','0','1'} };
    check.checkInt(13, o.numIslands(grid));
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
