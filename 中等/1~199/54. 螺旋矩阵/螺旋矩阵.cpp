/* 螺旋矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }

        int i, j, row = matrix.size(), column = matrix[0].size();
        int rowStart = 0, rowEnd = row - 1, columnStart = 0, columnEnd = column - 1;
        vector<int> spiralNums;

        while ((rowEnd > rowStart) && (columnEnd > columnStart)) {
            for (j = columnStart; j <= columnEnd; j++) {
                spiralNums.push_back(matrix[rowStart][j]);
            }

            for (i = rowStart + 1; i <= rowEnd; i++) {
                spiralNums.push_back(matrix[i][columnEnd]);
            }

            for (j = columnEnd - 1; j >= columnStart; j--) {
                spiralNums.push_back(matrix[rowEnd][j]);
            }

            for (i = rowEnd - 1; i > rowStart; i--) {
                spiralNums.push_back(matrix[i][columnStart]);
            }

            rowStart++;
            rowEnd--;
            columnStart++;
            columnEnd--;
        }

        if ((rowStart == rowEnd) && (columnStart <= columnEnd)) {
            for (j = columnStart; j <= columnEnd; j++) {
                spiralNums.push_back(matrix[rowStart][j]);
            }
        }

        if ((columnStart == columnEnd) && (rowStart < rowEnd)) {
            for (i = rowStart; i <= rowEnd; i++) {
                spiralNums.push_back(matrix[i][columnStart]);
            }
        }

        return spiralNums;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    vector<int> actual = o.spiralOrder(matrix);
    vector<int> expected = { 1,2,3,6,9,8,7,4,5 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,3,4,8,12,11,10,9,5,6,7 };
    check.checkIntVector(expected, actual);

    matrix = {  };
    actual = o.spiralOrder(matrix);
    expected = {  };
    check.checkIntVector(expected, actual);

    matrix = { {1} };
    actual = o.spiralOrder(matrix);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,3 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3,4} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,3,4 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3,4,5} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,3,4,5 };
    check.checkIntVector(expected, actual);

    matrix = { {1},{2} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    matrix = { {1},{2},{3} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,3 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2},{3,4} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,4,3 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2},{3,4},{5,6} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,4,6,5,3 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2},{3,4},{5,6},{7,8} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,4,6,8,7,5,3 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2},{3,4},{5,6},{7,8},{9,10} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,4,6,8,10,9,7,5,3 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3},{4,5,6} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,3,6,5,4 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3,4},{5,6,7,8} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,3,4,8,7,6,5 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3,4,5},{6,7,8,9,10} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,3,4,5,10,9,8,7,6 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,3,4,5,10,15,14,13,12,11,6,7,8,9 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3},{4,5,6},{7,8,9},{10,11,12} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,3,6,9,12,11,10,7,4,5,8 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15} };
    actual = o.spiralOrder(matrix);
    expected = { 1,2,3,6,9,12,15,14,13,10,7,4,5,8,11 };
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
