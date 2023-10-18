/* 构造乘积矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、大小为 n * m 的二维整数矩阵 grid ，定义一个下标从 0 开始、大小为 n * m 的的二维矩阵 p。如果满足以下条件，则称 p 为 grid 的 乘积矩阵 ：

对于每个元素 p[i][j] ，它的值等于除了 grid[i][j] 外所有元素的乘积。乘积对 12345 取余数。
返回 grid 的乘积矩阵。



示例 1：

输入：grid = [[1,2],[3,4]]
输出：[[24,12],[8,6]]
解释：p[0][0] = grid[0][1] * grid[1][0] * grid[1][1] = 2 * 3 * 4 = 24
p[0][1] = grid[0][0] * grid[1][0] * grid[1][1] = 1 * 3 * 4 = 12
p[1][0] = grid[0][0] * grid[0][1] * grid[1][1] = 1 * 2 * 4 = 8
p[1][1] = grid[0][0] * grid[0][1] * grid[1][0] = 1 * 2 * 3 = 6
所以答案是 [[24,12],[8,6]] 。
示例 2：

输入：grid = [[12345],[2],[1]]
输出：[[2],[0],[0]]
解释：p[0][0] = grid[0][1] * grid[0][2] = 2 * 1 = 2
p[0][1] = grid[0][0] * grid[0][2] = 12345 * 1 = 12345. 12345 % 12345 = 0 ，所以 p[0][1] = 0
p[0][2] = grid[0][0] * grid[0][1] = 12345 * 2 = 24690. 24690 % 12345 = 0 ，所以 p[0][2] = 0
所以答案是 [[2],[0],[0]] 。


提示：

1 <= n == grid.length <= 105
1 <= m == grid[i].length <= 105
2 <= n * m <= 105
1 <= grid[i][j] <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), mod = 12345;
        vector<long long> prefix(n * m + 1, 1), suffix(n * m + 1, 1);

        getPrefix(n, m, mod, grid, prefix);
        getSuffix(n, m, mod, grid, suffix);

        return constructMatrix(n, m, mod, prefix, suffix);
    }

    void getPrefix(int n, int m, int mod, vector<vector<int>>& grid, vector<long long>& prefix) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int idx = i * m + j + 1;
                prefix[idx] = prefix[idx - 1] * grid[i][j] % mod;
            }
        }
    }

    void getSuffix(int n, int m, int mod, vector<vector<int>>& grid, vector<long long>& suffix) {
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int idx = i * m + j;
                suffix[idx] = suffix[idx + 1] * grid[i][j] % mod;
            }
        }
    }

    vector<vector<int>> constructMatrix(int n, int m, int mod, vector<long long>& prefix, vector<long long>& suffix) {
        vector<vector<int>> matrix(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int idx = i * m + j;
                matrix[i][j] = (int)(prefix[idx] * suffix[idx + 1] % mod);
            }
        }

        return matrix;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,2},{3,4} };
    vector<vector<int>> actual = o.constructProductMatrix(grid);
    vector<vector<int>> expected = { {24,12},{8,6} };
    check.checkIntVectorVector(expected, actual);

    grid = { {12345},{2},{1} };
    actual = o.constructProductMatrix(grid);
    expected = { {2},{0},{0} };
    check.checkIntVectorVector(expected, actual);

    grid = { {68916659},{263909215} };
    actual = o.constructProductMatrix(grid);
    expected = { {10150},{6869} };
    check.checkIntVectorVector(expected, actual);
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
