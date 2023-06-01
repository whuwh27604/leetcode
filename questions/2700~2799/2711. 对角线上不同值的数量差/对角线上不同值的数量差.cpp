/* 对角线上不同值的数量差.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、大小为 m x n 的二维矩阵 grid ，请你求解大小同样为 m x n 的答案矩阵 answer 。

矩阵 answer 中每个单元格 (r, c) 的值可以按下述方式进行计算：

令 topLeft[r][c] 为矩阵 grid 中单元格 (r, c) 左上角对角线上 不同值 的数量。
令 bottomRight[r][c] 为矩阵 grid 中单元格 (r, c) 右下角对角线上 不同值 的数量。
然后 answer[r][c] = |topLeft[r][c] - bottomRight[r][c]| 。

返回矩阵 answer 。

矩阵对角线 是从最顶行或最左列的某个单元格开始，向右下方向走到矩阵末尾的对角线。

如果单元格 (r1, c1) 和单元格 (r, c) 属于同一条对角线且 r1 < r ，则单元格 (r1, c1) 属于单元格 (r, c) 的左上对角线。类似地，可以定义右下对角线。



示例 1：


输入：grid = [[1,2,3],[3,1,5],[3,2,1]]
输出：[[1,1,0],[1,0,1],[0,1,1]]
解释：第 1 个图表示最初的矩阵 grid 。
第 2 个图表示对单元格 (0,0) 计算，其中蓝色单元格是位于右下对角线的单元格。
第 3 个图表示对单元格 (1,2) 计算，其中红色单元格是位于左上对角线的单元格。
第 4 个图表示对单元格 (1,1) 计算，其中蓝色单元格是位于右下对角线的单元格，红色单元格是位于左上对角线的单元格。
- 单元格 (0,0) 的右下对角线包含 [1,1] ，而左上对角线包含 [] 。对应答案是 |1 - 0| = 1 。
- 单元格 (1,2) 的右下对角线包含 [] ，而左上对角线包含 [2] 。对应答案是 |0 - 1| = 1 。
- 单元格 (1,1) 的右下对角线包含 [1] ，而左上对角线包含 [1] 。对应答案是 |1 - 1| = 0 。
其他单元格的对应答案也可以按照这样的流程进行计算。
示例 2：

输入：grid = [[1]]
输出：[[0]]
解释：- 单元格 (0,0) 的右下对角线包含 [] ，左上对角线包含 [] 。对应答案是 |0 - 0| = 0 。


提示：

m == grid.length
n == grid[i].length
1 <= m, n, grid[i][j] <= 50
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        vector<vector<int>> ans(row, vector<int>(column));

        for (int r = row - 1; r >= 0; --r) {
            int i = r, j = 0;
            unordered_set<int> nums;
            for (; i < row && j < column; ++i, ++j) {
                ans[i][j] = nums.size();
                nums.insert(grid[i][j]);
            }

            nums.clear();
            for (--i, --j; i >= r && j >= 0; --i, --j) {
                ans[i][j] = abs(ans[i][j] - (int)nums.size());
                nums.insert(grid[i][j]);
            }
        }

        for (int c = 1; c < column; ++c) {
            int i = 0, j = c;
            unordered_set<int> nums;
            for (; i < row && j < column; ++i, ++j) {
                ans[i][j] = nums.size();
                nums.insert(grid[i][j]);
            }

            nums.clear();
            for (--i, --j; i >= 0 && j >= c; --i, --j) {
                ans[i][j] = abs(ans[i][j] - (int)nums.size());
                nums.insert(grid[i][j]);
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,2,3},{3,1,5},{3,2,1} };
    vector<vector<int>> actual = o.differenceOfDistinctValues(grid);
    vector<vector<int>> expected = { {1,1,0},{1,0,1},{0,1,1} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1} };
    actual = o.differenceOfDistinctValues(grid);
    expected = { {0} };
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
