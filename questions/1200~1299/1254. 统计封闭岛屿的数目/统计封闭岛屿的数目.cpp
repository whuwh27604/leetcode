/* 统计封闭岛屿的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个二维矩阵 grid ，每个位置要么是陆地（记号为 0 ）要么是水域（记号为 1 ）。

我们从一块陆地出发，每次可以往上下左右 4 个方向相邻区域走，能走到的所有陆地区域，我们将其称为一座「岛屿」。

如果一座岛屿 完全 由水域包围，即陆地边缘上下左右所有相邻区域都是水域，那么我们将其称为 「封闭岛屿」。

请返回封闭岛屿的数目。

 

示例 1：



输入：grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
输出：2
解释：
灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。
示例 2：



输入：grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
输出：1
示例 3：

输入：grid = [[1,1,1,1,1,1,1],
             [1,0,0,0,0,0,1],
             [1,0,1,1,1,0,1],
             [1,0,1,0,1,0,1],
             [1,0,1,1,1,0,1],
             [1,0,0,0,0,0,1],
             [1,1,1,1,1,1,1]]
输出：2
 

提示：

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-closed-islands
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
    int closedIsland(vector<vector<int>>& grid) {
        int i, j, row = grid.size(), column = grid[0].size(), size = row * column;
        DSU dsu(size + 1);

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (grid[i][j] == 1) {
                    dsu.merge(i * column + j, size);
                }
                else {
                    if (i == 0 || i == row - 1 || j == 0 || j == column - 1) {
                        dsu.merge(i * column + j, size);
                    }

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

    vector<vector<int>> grid = { {1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0} };
    check.checkInt(2, o.closedIsland(grid));

    grid = { {0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0} };
    check.checkInt(1, o.closedIsland(grid));

    grid = { {1,1,1,1,1,1,1} ,
             {1,0,0,0,0,0,1},
             {1,0,1,1,1,0,1},
             {1,0,1,0,1,0,1},
             {1,0,1,1,1,0,1},
             {1,0,0,0,0,0,1},
             {1,1,1,1,1,1,1} };
    check.checkInt(2, o.closedIsland(grid));

    grid = { {0} };
    check.checkInt(0, o.closedIsland(grid));

    grid = { {1} };
    check.checkInt(0, o.closedIsland(grid));

    grid = { {1,0,1,0,1},{0,1,0,1,0},{1,0,1,0,1},{0,1,0,1,0},{1,0,1,0,1} };
    check.checkInt(4, o.closedIsland(grid));

    grid = { {0,0,1,1,0,1,0,0,1,0},{1,1,0,1,1,0,1,1,1,0},{1,0,1,1,1,0,0,1,1,0},{0,1,1,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,1,1,0},{0,1,0,1,0,1,0,1,1,1},{1,0,1,0,1,1,0,0,0,1},{1,1,1,1,1,1,0,0,0,0},{1,1,1,0,0,1,0,1,0,1},{1,1,1,0,1,1,0,1,1,0} };
    check.checkInt(5, o.closedIsland(grid));
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
