/* 二维区域和检索 - 矩阵不可变.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。


上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。

示例:

给定 matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
说明:

你可以假设矩阵不可变。
会多次调用 sumRegion 方法。
你可以假设 row1 ≤ row2 且 col1 ≤ col2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-2d-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }

        int i, j, row = matrix.size(), column = matrix[0].size();

        vector<long long> oneRow(column + 1, 0);
        sumMatrix.push_back(oneRow);

        for (i = 0; i < row; ++i) {
            sumMatrix.push_back(oneRow);
            long long oneRowSum = 0;

            for (j = 0; j < column; ++j) {
                oneRowSum += matrix[i][j];
                sumMatrix[i + 1][j + 1] = sumMatrix[i][j + 1] + oneRowSum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return (int)(sumMatrix[row2 + 1][col2 + 1] + sumMatrix[row1][col1] - sumMatrix[row1][col2 + 1] - sumMatrix[row2 + 1][col1]);
    }

    vector<vector<long long>> sumMatrix;
};

int main()
{
    CheckResult check;

    vector<vector<int>> matrix = {};
    NumMatrix o(matrix);

    matrix = { {} };
    NumMatrix o1(matrix);

    matrix = { {3, 0, 1, 4, 2},{5, 6, 3, 2, 1},{1, 2, 0, 1, 5},{4, 1, 0, 1, 7},{1, 0, 3, 0, 5} };
    NumMatrix o2(matrix);
    check.checkInt(8, o2.sumRegion(2, 1, 4, 3));
    check.checkInt(11, o2.sumRegion(1, 1, 2, 2));
    check.checkInt(12, o2.sumRegion(1, 2, 2, 4));
    check.checkInt(3, o2.sumRegion(0, 0, 0, 0));
    check.checkInt(6, o2.sumRegion(1, 1, 1, 1));
    check.checkInt(14, o2.sumRegion(0, 0, 1, 1));
    check.checkInt(21, o2.sumRegion(0, 0, 2, 2));
    check.checkInt(34, o2.sumRegion(0, 0, 3, 3));
    check.checkInt(58, o2.sumRegion(0, 0, 4, 4));
    check.checkInt(3, o2.sumRegion(0, 0, 0, 1));
    check.checkInt(1, o2.sumRegion(0, 1, 0, 2));
    check.checkInt(5, o2.sumRegion(0, 2, 0, 3));
    check.checkInt(6, o2.sumRegion(0, 3, 0, 4));
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
