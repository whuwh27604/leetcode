/* 零矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

 

示例 1：

输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2：

输入：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/zero-matrix-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size();
        vector<bool> rZeros(row, false), cZeros(column, false);

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                if (matrix[r][c] == 0) {
                    rZeros[r] = true;
                    cZeros[c] = true;
                }
            }
        }

        for (int r = 0; r < row; ++r) {
            if (rZeros[r]) {
                for (int c = 0; c < column; ++c) {
                    matrix[r][c] = 0;
                }
            }
        }

        for (int c = 0; c < column; ++c) {
            if (cZeros[c]) {
                for (int r = 0; r < row; ++r) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
    o.setZeroes(matrix);
    vector<vector<int>> expected = { {1,0,1},{0,0,0},{1,0,1} };
    check.checkIntVectorVector(expected, matrix);

    matrix = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };
    o.setZeroes(matrix);
    expected = { {0,0,0,0},{0,4,5,0},{0,3,1,0} };
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
