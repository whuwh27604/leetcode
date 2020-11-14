/* 对角线遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

 

示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]

解释:

 

说明:

给定矩阵中的元素总数不会超过 100000 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diagonal-traverse
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        bool rightUp = true;
        int i = 0, j = 0, row = matrix.size(), column = matrix[0].size();
        vector<int> diagonalOrder;

        while (true) {
            diagonalOrder.push_back(matrix[i][j]);
            if ((i == row - 1) && (j == column - 1)) {
                break;
            }

            if (rightUp) {
                if (j == column - 1) {
                    rightUp = false;
                    i++;
                }
                else if (i == 0) {
                    rightUp = false;
                    j++;
                }
                else {
                    i--;
                    j++;
                }
            }
            else {
                if (i == row - 1) {
                    rightUp = true;
                    j++;
                }
                else if (j == 0) {
                    rightUp = true;
                    i++;
                }
                else {
                    i++;
                    j--;
                }
            }
        }

        return diagonalOrder;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> matrix = {};
    vector<int> actual = o.findDiagonalOrder(matrix);
    vector<int> expected = {};
    check.checkIntVector(expected, actual);

    matrix = { {} };
    actual = o.findDiagonalOrder(matrix);
    expected = {};
    check.checkIntVector(expected, actual);

    matrix = { {1} };
    actual = o.findDiagonalOrder(matrix);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2} };
    actual = o.findDiagonalOrder(matrix);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3,4,5} };
    actual = o.findDiagonalOrder(matrix);
    expected = { 1,2,3,4,5 };
    check.checkIntVector(expected, actual);

    matrix = { {1},{2} };
    actual = o.findDiagonalOrder(matrix);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2},{3,4} };
    actual = o.findDiagonalOrder(matrix);
    expected = { 1,2,3,4 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3} };
    actual = o.findDiagonalOrder(matrix);
    expected = { 1,2,3 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3},{4,5,6} };
    actual = o.findDiagonalOrder(matrix);
    expected = { 1,2,4,5,3,6 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2},{3,4},{5,6} };
    actual = o.findDiagonalOrder(matrix);
    expected = { 1,2,3,5,4,6 };
    check.checkIntVector(expected, actual);

    matrix = { {1},{2},{3},{4},{5} };
    actual = o.findDiagonalOrder(matrix);
    expected = { 1,2,3,4,5 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3},{4,5,6},{7,8,9} };
    actual = o.findDiagonalOrder(matrix);
    expected = { 1,2,4,7,5,3,6,8,9 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
    actual = o.findDiagonalOrder(matrix);
    expected = { 1,2,6,11,7,3,4,8,12,16,21,17,13,9,5,10,14,18,22,23,19,15,20,24,25 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    actual = o.findDiagonalOrder(matrix);
    expected = { 1,2,5,9,6,3,4,7,10,11,8,12 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3},{4,5,6},{7,8,9},{10,11,12} };
    actual = o.findDiagonalOrder(matrix);
    expected = { 1,2,4,7,5,3,6,8,10,11,9,12 };
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
