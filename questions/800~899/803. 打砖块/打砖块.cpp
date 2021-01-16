/* 打砖块.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个 m x n 的二元网格，其中 1 表示砖块，0 表示空白。砖块 稳定（不会掉落）的前提是：

一块砖直接连接到网格的顶部，或者
至少有一块相邻（4 个方向之一）砖块 稳定 不会掉落时
给你一个数组 hits ，这是需要依次消除砖块的位置。每当消除 hits[i] = (rowi, coli) 位置上的砖块时，对应位置的砖块（若存在）会消失，然后其他的砖块可能因为这一消除操作而掉落。一旦砖块掉落，它会立即从网格中消失（即，它不会落在其他稳定的砖块上）。

返回一个数组 result ，其中 result[i] 表示第 i 次消除操作对应掉落的砖块数目。

注意，消除可能指向是没有砖块的空白位置，如果发生这种情况，则没有砖块掉落。

 

示例 1：

输入：grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
输出：[2]
解释：
网格开始为：
[[1,0,0,0]，
 [1,1,1,0]]
消除 (1,0) 处加粗的砖块，得到网格：
[[1,0,0,0]
 [0,1,1,0]]
两个加粗的砖不再稳定，因为它们不再与顶部相连，也不再与另一个稳定的砖相邻，因此它们将掉落。得到网格：
[[1,0,0,0],
 [0,0,0,0]]
因此，结果为 [2] 。
示例 2：

输入：grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
输出：[0,0]
解释：
网格开始为：
[[1,0,0,0],
 [1,1,0,0]]
消除 (1,1) 处加粗的砖块，得到网格：
[[1,0,0,0],
 [1,0,0,0]]
剩下的砖都很稳定，所以不会掉落。网格保持不变：
[[1,0,0,0],
 [1,0,0,0]]
接下来消除 (1,0) 处加粗的砖块，得到网格：
[[1,0,0,0],
 [0,0,0,0]]
剩下的砖块仍然是稳定的，所以不会有砖块掉落。
因此，结果为 [0,0] 。
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 200
grid[i][j] 为 0 或 1
1 <= hits.length <= 4 * 104
hits[i].length == 2
0 <= xi <= m - 1
0 <= yi <= n - 1
所有 (xi, yi) 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bricks-falling-when-hit
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        parents.resize(size);
        setSizes.resize(size);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
            setSizes[i] = 1;  // 初始时每个集合只有自己一个
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        int parentX = find(x), parentY = find(y);

        if (parentX != parentY) {
            parents[parentX] = parentY;
            setSizes[parentY] += setSizes[parentX];  // 合并集合的同时，维护集合的大小
        }
    }

    int getSetSize(int x) {
        parents[x] = find(x);  // 需要先更新parent
        return setSizes[parents[x]];
    }

private:
    vector<int> parents;
    vector<int> setSizes;  // 用来记录集合的大小，这是此题的关键，否则每次find所有节点来查找哪些节点在顶部集合肯定超时
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        DSU dsu(grid.size() * grid[0].size() + 1);  // 虚拟一个row*column位置用来表示顶部
        vector<vector<int>> clearedGrid = grid;
        vector<int> fallbricks(hits.size());

        clearAllHitBricks(clearedGrid, hits);
        init(clearedGrid, dsu);
        reversePutBackBricks(grid, clearedGrid, hits, dsu, fallbricks);

        return fallbricks;
    }

    void clearAllHitBricks(vector<vector<int>>& clearedGrid, vector<vector<int>>& hits) {
        for (auto& hit : hits) {
            clearedGrid[hit[0]][hit[1]] = 0;
        }
    }

    void init(vector<vector<int>>& clearedGrid, DSU& dsu) {
        int i, j, row = clearedGrid.size(), column = clearedGrid[0].size();

        for (j = 0; j < column; ++j) {
            if (clearedGrid[0][j] == 1) {
                dsu.merge(j, row * column);  // 顶部brick全部连通到集合row*column
            }
        }

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (clearedGrid[i][j] == 0) {
                    continue;
                }

                if (j < column - 1 && clearedGrid[i][j + 1] != 0) {
                    dsu.merge(i * column + j, i * column + j + 1);  // 和右边连通
                }

                if (i < row - 1 && clearedGrid[i + 1][j] != 0) {
                    dsu.merge(i * column + j, (i + 1) * column + j);  // 和下面连通
                }
            }
        }
    }

    void reversePutBackBricks(vector<vector<int>>& grid, vector<vector<int>>& clearedGrid, vector<vector<int>>& hits, DSU& dsu, vector<int>& fallbricks) {
        int i, size = hits.size(), row = grid.size(), column = grid[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        for (i = size - 1; i >= 0; --i) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) {  // hit的地方并没有砖块，什么都不会发生
                continue;
            }

            int topBricks = dsu.getSetSize(row * column);  // 保存当前顶部集合有多少个砖块
            clearedGrid[r][c] = 1;  // 放回这块砖
            if (r == 0) {
                dsu.merge(c, row * column);  // 如果这块砖在顶部，连通到集合row*column
            }

            for (int j = 0; j < 4; ++j) {  // 检查4个方向
                int nr = r + dr[j], nc = c + dc[j];

                if (nr >= 0 && nr < row && nc >= 0 && nc < column && clearedGrid[nr][nc] == 1) {  // 如果有砖块就连通它们
                    dsu.merge(r * column + c, nr * column + nc);
                }
            }

            int newTopBricks = dsu.getSetSize(row * column);  // 连通完毕后再看顶部集合有多少个砖块
            fallbricks[i] = newTopBricks > topBricks ? newTopBricks - topBricks - 1 : 0;  // 新增的砖块就是会掉落的，注意要减去hit的这一块。另外还有可能没有新增。
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,0,0,0},{1,1,1,0} };
    vector<vector<int>> hits = { {1,0} };
    vector<int> actual = o.hitBricks(grid, hits);
    vector<int> expected = { 2 };
    check.checkIntVector(expected, actual);

    grid = { {1,0,0,0},{1,1,0,0} };
    hits = { {1,1},{1,0} };
    actual = o.hitBricks(grid, hits);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    grid = { {1},{1},{1},{1},{1} };
    hits = { {3,0},{4,0},{1,0},{2,0},{0,0} };
    actual = o.hitBricks(grid, hits);
    expected = { 1,0,1,0,0 };
    check.checkIntVector(expected, actual);

    grid = { {1,1,0,1,0},{1,1,0,1,1},{0,0,0,1,1},{0,0,0,1,0},{0,0,0,0,0},{0,0,0,0,0} };
    hits = { {5,1},{1,3} };
    actual = o.hitBricks(grid, hits);
    expected = { 0,4 };
    check.checkIntVector(expected, actual);

    grid = { {0,1,1,1,1},{1,1,1,1,0},{1,1,1,1,0},{0,0,1,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0} };
    hits = { {6,0},{1,0},{4,3},{1,2},{7,1},{6,3},{5,2},{5,1},{2,4},{4,4},{7,3} };
    actual = o.hitBricks(grid, hits);
    expected = { 0,0,0,0,0,0,0,0,0,0,0 };
    check.checkIntVector(expected, actual);

    grid = { {1,1,1},{0,1,0},{0,0,0} };
    hits = { {0,2},{2,0},{0,1},{1,2} };
    actual = o.hitBricks(grid, hits);
    expected = { 0,0,1,0 };
    check.checkIntVector(expected, actual);
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
