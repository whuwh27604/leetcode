/* 搜索二维矩阵 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int row = matrix.size(), column = matrix[0].size(), i = row - 1, j = 0;

        while ((i >= 0) && (j < column)) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                i--;
            }
            else if (matrix[i][j] < target) {
                j++;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> matrix = {};
    check.checkBool(false, o.searchMatrix(matrix, 0));

    matrix = { {} };
    check.checkBool(false, o.searchMatrix(matrix, 0));

    matrix = { {1} };
    check.checkBool(false, o.searchMatrix(matrix, 0));

    matrix = { {1} };
    check.checkBool(true, o.searchMatrix(matrix, 1));

    matrix = { {1},{2} };
    check.checkBool(false, o.searchMatrix(matrix, 3));

    matrix = { {1},{2} };
    check.checkBool(true, o.searchMatrix(matrix, 1));

    matrix = { {1,2} };
    check.checkBool(true, o.searchMatrix(matrix, 2));

    matrix = { {1,2} };
    check.checkBool(false, o.searchMatrix(matrix, 0));

    matrix = { {1,2} };
    check.checkBool(false, o.searchMatrix(matrix, 3));

    matrix = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
    check.checkBool(false, o.searchMatrix(matrix, 0));
    check.checkBool(false, o.searchMatrix(matrix, 20));
    check.checkBool(false, o.searchMatrix(matrix, 25));
    check.checkBool(false, o.searchMatrix(matrix, 28));
    check.checkBool(false, o.searchMatrix(matrix, 31));
    check.checkBool(true, o.searchMatrix(matrix, 1));
    check.checkBool(true, o.searchMatrix(matrix, 7));
    check.checkBool(true, o.searchMatrix(matrix, 15));
    check.checkBool(true, o.searchMatrix(matrix, 2));
    check.checkBool(true, o.searchMatrix(matrix, 5));
    check.checkBool(true, o.searchMatrix(matrix, 19));
    check.checkBool(true, o.searchMatrix(matrix, 3));
    check.checkBool(true, o.searchMatrix(matrix, 16));
    check.checkBool(true, o.searchMatrix(matrix, 22));
    check.checkBool(true, o.searchMatrix(matrix, 10));
    check.checkBool(true, o.searchMatrix(matrix, 14));
    check.checkBool(true, o.searchMatrix(matrix, 24));
    check.checkBool(true, o.searchMatrix(matrix, 18));
    check.checkBool(true, o.searchMatrix(matrix, 26));
    check.checkBool(true, o.searchMatrix(matrix, 30));
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
