/* 统计全为 1 的正方形子矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。

 

示例 1：

输入：matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
输出：15
解释：
边长为 1 的正方形有 10 个。
边长为 2 的正方形有 4 个。
边长为 3 的正方形有 1 个。
正方形的总数 = 10 + 4 + 1 = 15.
示例 2：

输入：matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
输出：7
解释：
边长为 1 的正方形有 6 个。
边长为 2 的正方形有 1 个。
正方形的总数 = 6 + 1 = 7.
 

提示：

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int i, j, row = matrix.size(), column = matrix[0].size(), totalSquares = 0;
        vector<vector<int>> dp(row + 1, vector<int>(column + 1, 0));  // dp[i][j]表示以[i,j]为右下顶点的最大正方形边长

        for (i = 1; i <= row; ++i) {
            for (j = 1; j <= column; ++j) {
                if (matrix[i - 1][j - 1] == 0) {
                    dp[i][j] = 0;
                }
                else {  // 左边，上边，左上三个正方形重合的部分加上matrix[i][j]这个点，可以构成一个最大的正方形
                    dp[i][j] = min({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] }) + 1;
                    totalSquares += dp[i][j];  // 最大边长为n的正方形可以构成n个以[i,j]为右下顶点的正方形
                }
            }
        }

        return totalSquares;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> matrix = { {1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0} };
    check.checkInt(15, o.countSquares(matrix));

    matrix = { {1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1} };
    check.checkInt(40, o.countSquares(matrix));

    matrix = { {1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1} };
    check.checkInt(55, o.countSquares(matrix));

    matrix = { {1,1},{1,1} };
    check.checkInt(5, o.countSquares(matrix));

    matrix = { {1} };
    check.checkInt(1, o.countSquares(matrix));

    matrix = { {0} };
    check.checkInt(0, o.countSquares(matrix));

    matrix = { {0,1,1,1},{1,1,1,1},{0,1,1,1} };
    check.checkInt(15, o.countSquares(matrix));

    matrix = { {1,0,1},{1,1,0},{1,1,0} };
    check.checkInt(7, o.countSquares(matrix));
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
