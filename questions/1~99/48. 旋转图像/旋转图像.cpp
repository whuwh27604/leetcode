/* 旋转图像.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-image
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, len = matrix.size(), start = 0, end = len - 1;

        while ((end - start) >= 1) {
            for (i = 0; i < end - start; i++) {
                int tmp = matrix[start][start + i];
                matrix[start][start + i] = matrix[end - i][start];
                matrix[end - i][start] = matrix[end][end - i];
                matrix[end][end - i] = matrix[start + i][end];
                matrix[start + i][end] = tmp;
            }

            start++;
            end--;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> matrix = {};
    vector<vector<int>> expected = {};
    o.rotate(matrix);
    check.checkIntDoubleVector(expected, matrix);

    matrix = { {1} };
    expected = { {1} };
    o.rotate(matrix);
    check.checkIntDoubleVector(expected, matrix);

    matrix = { {1,2},{3,4} };
    expected = { {3,1},{4,2} };
    o.rotate(matrix);
    check.checkIntDoubleVector(expected, matrix);

    matrix = { {1,2,3},{4,5,6},{7,8,9} };
    expected = { {7,4,1},{8,5,2},{9,6,3} };
    o.rotate(matrix);
    check.checkIntDoubleVector(expected, matrix);

    matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
    expected = { {13,9,5,1},{14,10,6,2},{15,11,7,3},{16,12,8,4} };
    o.rotate(matrix);
    check.checkIntDoubleVector(expected, matrix);

    matrix = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
    expected = { {21,16,11,6,1},{22,17,12,7,2},{23,18,13,8,3},{24,19,14,9,4},{25,20,15,10,5} };
    o.rotate(matrix);
    check.checkIntDoubleVector(expected, matrix);
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
