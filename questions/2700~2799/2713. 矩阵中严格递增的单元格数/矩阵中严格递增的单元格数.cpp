/* 矩阵中严格递增的单元格数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 1 开始、大小为 m x n 的整数矩阵 mat，你可以选择任一单元格作为 起始单元格 。

从起始单元格出发，你可以移动到 同一行或同一列 中的任何其他单元格，但前提是目标单元格的值 严格大于 当前单元格的值。

你可以多次重复这一过程，从一个单元格移动到另一个单元格，直到无法再进行任何移动。

请你找出从某个单元开始访问矩阵所能访问的 单元格的最大数量 。

返回一个表示可访问单元格最大数量的整数。



示例 1：



输入：mat = [[3,1],[3,4]]
输出：2
解释：上图展示了从第 1 行、第 2 列的单元格开始，可以访问 2 个单元格。可以证明，无论从哪个单元格开始，最多只能访问 2 个单元格，因此答案是 2 。
示例 2：



输入：mat = [[1,1],[1,1]]
输出：1
解释：由于目标单元格必须严格大于当前单元格，在本示例中只能访问 1 个单元格。
示例 3：



输入：mat = [[3,1,6],[-9,5,7]]
输出：4
解释：上图展示了从第 2 行、第 1 列的单元格开始，可以访问 4 个单元格。可以证明，无论从哪个单元格开始，最多只能访问 4 个单元格，因此答案是 4 。


提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 105
1 <= m * n <= 105
-105 <= mat[i][j] <= 105
*/

#include <iostream>
#include <algorithm>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int row = mat.size(), column = mat[0].size(), maxCells = 0;
        map<int, vector<pair<int, int>>> numIndices;
        // 从小到大枚举mat[r][c]，dp[r][c]表示到mat[r][c]为止，最多可以访问的cells。用rowMaxDp[r]记录r行最大的dp，用columnMaxDp[c]记录c列最大的dp
        vector<int> rowMaxDp(row, 0), columnMaxDp(column, 0);

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                numIndices[mat[r][c]].push_back({ r,c });  // 把相等的数分在同一组。因为相等的数之间不可达，所以要一次计算完所有相等的数。
            }
        }

        for (auto& numIndex : numIndices) {
            int num = numIndex.first;
            int size = numIndex.second.size();
            vector<int> dps(size, INT_MIN);  // 计算这一组数的dp

            for (int i = 0; i < size; ++i) {
                int r = numIndex.second[i].first, c = numIndex.second[i].second;
                dps[i] = max(rowMaxDp[r], columnMaxDp[c]) + 1;  // 从比它小的数都可以到达mat[r][c]，所以选最大的一个，然后加上mat[r][c]自己
                maxCells = max(maxCells, dps[i]);  // 最终答案是所有dp中最大的一个
            }

            for (int i = 0; i < size; ++i) {  // 这一组计算完成后，才能更新rowMaxDp、columnMaxDp的值。因为相等的数不可达，中途更新将导致错误的结果。
                int r = numIndex.second[i].first, c = numIndex.second[i].second;
                rowMaxDp[r] = max(rowMaxDp[r], dps[i]);
                columnMaxDp[c] = max(columnMaxDp[c], dps[i]);
            }
        }

        return maxCells;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = { {3,1},{3,4} };
    check.checkInt(2, o.maxIncreasingCells(mat));

    mat = { {1,1},{1,1} };
    check.checkInt(1, o.maxIncreasingCells(mat));

    mat = { {3,1,6},{-9,5,7} };
    check.checkInt(4, o.maxIncreasingCells(mat));
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
