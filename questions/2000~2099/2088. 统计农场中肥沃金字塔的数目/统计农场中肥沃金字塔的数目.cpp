/* 统计农场中肥沃金字塔的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个 矩形网格 状的农场，划分为 m 行 n 列的单元格。每个格子要么是 肥沃的 （用 1 表示），要么是 贫瘠 的（用 0 表示）。网格图以外的所有与格子都视为贫瘠的。

农场中的 金字塔 区域定义如下：

区域内格子数目 大于 1 且所有格子都是 肥沃的 。
金字塔 顶端 是这个金字塔 最上方 的格子。金字塔的高度是它所覆盖的行数。令 (r, c) 为金字塔的顶端且高度为 h ，那么金字塔区域内包含的任一格子 (i, j) 需满足 r <= i <= r + h - 1 且 c - (i - r) <= j <= c + (i - r) 。
一个 倒金字塔 类似定义如下：

区域内格子数目 大于 1 且所有格子都是 肥沃的 。
倒金字塔的 顶端 是这个倒金字塔 最下方 的格子。倒金字塔的高度是它所覆盖的行数。令 (r, c) 为金字塔的顶端且高度为 h ，那么金字塔区域内包含的任一格子 (i, j) 需满足 r - h + 1 <= i <= r 且 c - (r - i) <= j <= c + (r - i) 。
下图展示了部分符合定义和不符合定义的金字塔区域。黑色区域表示肥沃的格子。



给你一个下标从 0 开始且大小为 m x n 的二进制矩阵 grid ，它表示农场，请你返回 grid 中金字塔和倒金字塔的 总数目 。

 

示例 1：

  

输入：grid = [[0,1,1,0],[1,1,1,1]]
输出：2
解释：
2 个可能的金字塔区域分别如上图蓝色和红色区域所示。
这个网格图中没有倒金字塔区域。
所以金字塔区域总数为 2 + 0 = 2 。
示例 2：

  

输入：grid = [[1,1,1],[1,1,1]]
输出：2
解释：
金字塔区域如上图蓝色区域所示，倒金字塔如上图红色区域所示。
所以金字塔区域总数目为 1 + 1 = 2 。
示例 3：



输入：grid = [[1,0,1],[0,0,0],[1,0,1]]
输出：0
解释：
网格图中没有任何金字塔或倒金字塔区域。
示例 4：

   

输入：grid = [[1,1,1,1,0],[1,1,1,1,1],[1,1,1,1,1],[0,1,0,0,1]]
输出：13
解释：
有 7 个金字塔区域。上图第二和第三张图中展示了它们中的 3 个。
有 6 个倒金字塔区域。上图中最后一张图展示了它们中的 2 个。
所以金字塔区域总数目为 7 + 6 = 13.
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
grid[i][j] 要么是 0 ，要么是 1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-fertile-pyramids-in-a-land
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        vector<vector<int>> consectiveOnes(grid.size(), vector<int>(grid[0].size(), 0));

        getConsectiveOnes(grid, consectiveOnes);

        return countPyramids(grid, consectiveOnes) + countInversePyramids(grid, consectiveOnes);
    }

    void getConsectiveOnes(vector<vector<int>>& grid, vector<vector<int>>& consectiveOnes) {
        int i, j, m = grid.size(), n = grid[0].size();

        for (i = 0; i < m; ++i) {
            consectiveOnes[i][0] = grid[i][0];

            for (j = 1; j < n; ++j) {
                consectiveOnes[i][j] = (grid[i][j] == 0 ? 0 : consectiveOnes[i][j - 1] + 1);
            }
        }
    }

    int countPyramids(vector<vector<int>>& grid, vector<vector<int>>& consectiveOnes) {
        int i, j, m = grid.size(), n = grid[0].size(), pyramids = 0;
        vector<vector<int>> heights(m, vector<int>(n, 0));

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    heights[i][j] = grid[i][j];
                }
                else {
                    heights[i][j] = min(heights[i - 1][j - 1] + 1, (consectiveOnes[i][j] + 1) / 2);
                }

                if (heights[i][j] != 0) {
                    pyramids += (heights[i][j] - 1);
                }
            }
        }

        return pyramids;
    }

    int countInversePyramids(vector<vector<int>>& grid, vector<vector<int>>& consectiveOnes) {
        int i, j, m = grid.size(), n = grid[0].size(), pyramids = 0;
        vector<vector<int>> heights(m, vector<int>(n, 0));

        for (i = m - 1; i >= 0; --i) {
            for (j = 0; j < n; ++j) {
                if (i == m - 1 || j == 0) {
                    heights[i][j] = grid[i][j];
                }
                else {
                    heights[i][j] = min(heights[i + 1][j - 1] + 1, (consectiveOnes[i][j] + 1) / 2);
                }

                if (heights[i][j] != 0) {
                    pyramids += (heights[i][j] - 1);
                }
            }
        }

        return pyramids;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {0,1,1,0},{1,1,1,1} };
    check.checkInt(2, o.countPyramids(grid));

    grid = { {1,1,1},{1,1,1} };
    check.checkInt(2, o.countPyramids(grid));

    grid = { {1,0,1},{0,0,0},{1,0,1} };
    check.checkInt(0, o.countPyramids(grid));

    grid = { {1,1,1,1,0},{1,1,1,1,1},{1,1,1,1,1},{0,1,0,0,1} };
    check.checkInt(13, o.countPyramids(grid));
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
