/* 矩阵置零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

输入:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2:

输入:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
进阶:

一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-matrix-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }

        int i, j, row = matrix.size(), column = matrix[0].size();
        bool firstRowSet0 = false, firstColumnSet0 = false;

        for (i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                firstColumnSet0 = true;
                break;
            }
        }

        for (j = 0; j < column; j++) {
            if (matrix[0][j] == 0) {
                firstRowSet0 = true;
                break;
            }
        }

        for (i = 1; i < row; i++) {
            for (j = 1; j < column; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;  // 第一次遍历，利用第一行、第一列做标记，先不实际改动矩阵
                }
            }
        }

        for (i = 1; i < row; i++) {
            if (matrix[i][0] == 0) {
                for (j = 1; j < column; j++) {
                    matrix[i][j] = 0;  // 根据标记，置对应行、列为0
                }
            }
        }

        for (j = 1; j < column; j++) {
            if (matrix[0][j] == 0) {
                for (i = 1; i < row; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRowSet0) {
            for (j = 0; j < column; j++) {
                matrix[0][j] = 0;  // 最后判断第一行、第一列是否置0
            }
        }

        if (firstColumnSet0) {
            for (i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
    o.setZeroes(matrix);
    vector<vector<int>> expected = { {1,0,1},{0,0,0},{1,0,1} };
    check.checkIntVectorVector(expected, matrix);

    matrix = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };
    o.setZeroes(matrix);
    expected = { {0,0,0,0},{0,4,5,0},{0,3,1,0} };
    check.checkIntVectorVector(expected, matrix);

    matrix = {  };
    o.setZeroes(matrix);
    expected = {  };
    check.checkIntVectorVector(expected, matrix);

    matrix = { {1} };
    o.setZeroes(matrix);
    expected = { {1} };
    check.checkIntVectorVector(expected, matrix);

    matrix = { {1,1,0} };
    o.setZeroes(matrix);
    expected = { {0,0,0} };
    check.checkIntVectorVector(expected, matrix);

    matrix = { {0},{1},{1} };
    o.setZeroes(matrix);
    expected = { {0},{0},{0} };
    check.checkIntVectorVector(expected, matrix);

    matrix = { {1,1,1},{0,1,2} };
    o.setZeroes(matrix);
    expected = { {0,1,1},{0,0,0} };
    check.checkIntVectorVector(expected, matrix);
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
