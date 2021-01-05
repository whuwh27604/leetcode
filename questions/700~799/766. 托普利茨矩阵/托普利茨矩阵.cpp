/* 托普利茨矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一个矩阵的每一方向由左上到右下的对角线上具有相同元素，那么这个矩阵是托普利茨矩阵。

给定一个 M x N 的矩阵，当且仅当它是托普利茨矩阵时返回 True。

示例 1:

输入:
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
输出: True
解释:
在上述矩阵中, 其对角线为:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。
各条对角线上的所有元素均相同, 因此答案是True。
示例 2:

输入:
matrix = [
  [1,2],
  [2,2]
]
输出: False
解释:
对角线"[1, 2]"上的元素不同。
说明:

 matrix 是一个包含整数的二维数组。
matrix 的行数和列数均在 [1, 20]范围内。
matrix[i][j] 包含的整数在 [0, 99]范围内。
进阶:

如果矩阵存储在磁盘上，并且磁盘内存是有限的，因此一次最多只能将一行矩阵加载到内存中，该怎么办？
如果矩阵太大以至于只能一次将部分行加载到内存中，该怎么办？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/toeplitz-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unsigned int i, j, r, c, row = matrix.size(), column = matrix[0].size();

        for (j = 0; j < (column - 1); j++) {
            r = 1;
            c = (j + 1);
            while ((r < row) && (c < column)) {
                if (matrix[r][c] != matrix[0][j]) {
                    return false;
                }
                r++;
                c++;
            }
        }

        for (i = 1; i < (row - 1); i++) {
            r = (i + 1);
            c = 1;
            while ((r < row) && (c < column)) {
                if (matrix[r][c] != matrix[i][0]) {
                    return false;
                }
                r++;
                c++;
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> matrix = { {1,2,3,4},{5,1,2,3},{9,5,1,2} };
    check.checkBool(true, o.isToeplitzMatrix(matrix));

    matrix = { {1,2},{2,2} };
    check.checkBool(false, o.isToeplitzMatrix(matrix));

    matrix = { {1} };
    check.checkBool(true, o.isToeplitzMatrix(matrix));

    matrix = { {1,2} };
    check.checkBool(true, o.isToeplitzMatrix(matrix));

    matrix = { {1},{2} };
    check.checkBool(true, o.isToeplitzMatrix(matrix));
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
