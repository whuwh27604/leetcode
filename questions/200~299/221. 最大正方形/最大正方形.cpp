/* 最大正方形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

 

示例：

输入：
matrix = [["1","0","1","0","0"],
          ["1","0","1","1","1"],
          ["1","1","1","1","1"],
          ["1","0","0","1","0"]]

输出：4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int i, j, row = matrix.size(), column = matrix[0].size(), maxEdge = 0;
        vector<vector<int>> dp(row + 1, vector<int>(column + 1, 0));  // dp[i][j]表示以[i,j]为右下顶点的最大正方形边长

        for (i = 1; i <= row; ++i) {
            for (j = 1; j <= column; ++j) {
                if (matrix[i - 1][j - 1] == '0') {
                    dp[i][j] = 0;
                }
                else {  // 左边，上边，左上三个正方形重合的部分加上matrix[i][j]这个点，可以构成一个最大的正方形
                    dp[i][j] = min({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] }) + 1;
                }

                maxEdge = max(maxEdge, dp[i][j]);
            }
        }

        return maxEdge * maxEdge;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<char>> matrix = { {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} };
    check.checkInt(4, o.maximalSquare(matrix));

    matrix = { {'1','1','1','1','1'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'1','1','1','1','1'} };
    check.checkInt(16, o.maximalSquare(matrix));

    matrix = { {'1','1','1','1','1'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'1','1','1','1','1'} };
    check.checkInt(25, o.maximalSquare(matrix));

    matrix = { {'1','1'},{'1','1'} };
    check.checkInt(4, o.maximalSquare(matrix));

    matrix = {  };
    check.checkInt(0, o.maximalSquare(matrix));

    matrix = { {'1'} };
    check.checkInt(1, o.maximalSquare(matrix));

    matrix = { {'0'} };
    check.checkInt(0, o.maximalSquare(matrix));

    matrix = { {'0','1','1','1'},{'1','1','1','1'},{'0','1','1','1'} };
    check.checkInt(9, o.maximalSquare(matrix));

    matrix = { {'1','0','1'},{'1','1','0'},{'1','1','0'} };
    check.checkInt(4, o.maximalSquare(matrix));
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
