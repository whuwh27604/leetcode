/* 转置矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个矩阵 A， 返回 A 的转置矩阵。

矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

 

示例 1：

输入：[[1,2,3],[4,5,6],[7,8,9]]
输出：[[1,4,7],[2,5,8],[3,6,9]]
示例 2：

输入：[[1,2,3],[4,5,6]]
输出：[[1,4],[2,5],[3,6]]
 

提示：

1 <= A.length <= 1000
1 <= A[0].length <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/transpose-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int i, j, row = A.size(), column = A[0].size();
        vector<vector<int>> transposed(column, vector<int>(row));

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                transposed[j][i] = A[i][j];
            }
        }

        return transposed;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> A = { {1,2,3},{4,5,6},{7,8,9} };
    vector<vector<int>> actual = o.transpose(A);
    vector<vector<int>> expected = { {1,4,7},{2,5,8},{3,6,9} };
    check.checkIntDoubleVector(expected, actual);

    A = { {1,2,3},{4,5,6} };
    actual = o.transpose(A);
    expected = { {1,4},{2,5},{3,6} };
    check.checkIntDoubleVector(expected, actual);

    A = { {1} };
    actual = o.transpose(A);
    expected = { {1} };
    check.checkIntDoubleVector(expected, actual);

    A = { {1,2,3} };
    actual = o.transpose(A);
    expected = { {1},{2},{3} };
    check.checkIntDoubleVector(expected, actual);

    A = { {1},{2},{3} };
    actual = o.transpose(A);
    expected = { {1,2,3} };
    check.checkIntDoubleVector(expected, actual);
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
