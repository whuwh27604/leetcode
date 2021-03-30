/* 搜索二维矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), column = matrix[0].size(), low = 0, high = row * column - 1;

        while (low <= high) {
            int middle = (low + high) / 2, r = middle / column, c = middle % column;
            if (matrix[r][c] == target) {
                return true;
            }

            if (matrix[r][c] > target) {
                high = middle - 1;
            }
            else {
                low = middle + 1;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
    check.checkBool(true, o.searchMatrix(matrix, 3));

    matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
    check.checkBool(true, o.searchMatrix(matrix, 1));

    matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
    check.checkBool(true, o.searchMatrix(matrix, 10));

    matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
    check.checkBool(true, o.searchMatrix(matrix, 20));

    matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
    check.checkBool(true, o.searchMatrix(matrix, 50));

    matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
    check.checkBool(false, o.searchMatrix(matrix, 0));

    matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
    check.checkBool(false, o.searchMatrix(matrix, 51));

    matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
    check.checkBool(false, o.searchMatrix(matrix, 13));

    matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
    check.checkBool(false, o.searchMatrix(matrix, 8));

    matrix = { {1,3,5,7} };
    check.checkBool(true, o.searchMatrix(matrix, 1));

    matrix = { {1,3,5,7} };
    check.checkBool(true, o.searchMatrix(matrix, 3));

    matrix = { {1,3,5,7} };
    check.checkBool(true, o.searchMatrix(matrix, 7));

    matrix = { {1,3,5,7} };
    check.checkBool(false, o.searchMatrix(matrix, 0));

    matrix = { {1,3,5,7} };
    check.checkBool(false, o.searchMatrix(matrix, 2));

    matrix = { {1,3,5,7} };
    check.checkBool(false, o.searchMatrix(matrix, 8));

    matrix = { {1},{3},{5},{7} };
    check.checkBool(true, o.searchMatrix(matrix, 1));

    matrix = { {1},{3},{5},{7} };
    check.checkBool(true, o.searchMatrix(matrix, 3));

    matrix = { {1},{3},{5},{7} };
    check.checkBool(true, o.searchMatrix(matrix, 7));

    matrix = { {1},{3},{5},{7} };
    check.checkBool(false, o.searchMatrix(matrix, 0));

    matrix = { {1},{3},{5},{7} };
    check.checkBool(false, o.searchMatrix(matrix, 2));

    matrix = { {1},{3},{5},{7} };
    check.checkBool(false, o.searchMatrix(matrix, 8));
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
