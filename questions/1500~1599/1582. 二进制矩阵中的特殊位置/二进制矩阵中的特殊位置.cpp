/* 二进制矩阵中的特殊位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 rows x cols 的矩阵 mat，其中 mat[i][j] 是 0 或 1，请返回 矩阵 mat 中特殊位置的数目 。

特殊位置 定义：如果 mat[i][j] == 1 并且第 i 行和第 j 列中的所有其他元素均为 0（行和列的下标均 从 0 开始 ），则位置 (i, j) 被称为特殊位置。

 

示例 1：

输入：mat = [[1,0,0],
            [0,0,1],
            [1,0,0]]
输出：1
解释：(1,2) 是一个特殊位置，因为 mat[1][2] == 1 且所处的行和列上所有其他元素都是 0
示例 2：

输入：mat = [[1,0,0],
            [0,1,0],
            [0,0,1]]
输出：3
解释：(0,0), (1,1) 和 (2,2) 都是特殊位置
示例 3：

输入：mat = [[0,0,0,1],
            [1,0,0,0],
            [0,1,1,0],
            [0,0,0,0]]
输出：2
示例 4：

输入：mat = [[0,0,0,0,0],
            [1,0,0,0,0],
            [0,1,0,0,0],
            [0,0,1,0,0],
            [0,0,0,1,1]]
输出：3
 

提示：

rows == mat.length
cols == mat[i].length
1 <= rows, cols <= 100
mat[i][j] 是 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/special-positions-in-a-binary-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size(), column = mat[0].size();
        vector<int> rowSum(row, 0), columnSum(column, 0);

        getRowSum(mat, rowSum);
        getColumnSum(mat, columnSum);

        return getSpecials(mat, rowSum, columnSum);
    }

    void getRowSum(vector<vector<int>>& mat, vector<int>& rowSum) {
        for (int i = 0; i < (int)mat.size(); ++i) {
            for (int j = 0; j < (int)mat[0].size(); ++j) {
                rowSum[i] += mat[i][j];
            }
        }
    }

    void getColumnSum(vector<vector<int>>& mat, vector<int>& columnSum) {
        for (int j = 0; j < (int)mat[0].size(); ++j) {
            for (int i = 0; i < (int)mat.size(); ++i) {
                columnSum[j] += mat[i][j];
            }
        }
    }

    int getSpecials(vector<vector<int>>& mat, vector<int>& rowSum, vector<int>& columnSum) {
        int specials = 0;

        for (int i = 0; i < (int)mat.size(); ++i) {
            for (int j = 0; j < (int)mat[0].size(); ++j) {
                if (mat[i][j] == 1 && rowSum[i] == 1 && columnSum[j] == 1) {
                    ++specials;
                }
            }
        }

        return specials;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = { {1,0,0},{0,0,1},{1,0,0} };
    check.checkInt(1, o.numSpecial(mat));

    mat = { {1,0,0},{0,1,0},{0,0,1} };
    check.checkInt(3, o.numSpecial(mat));

    mat = { {0,0,0,1},{1,0,0,0},{0,1,1,0},{0,0,0,0} };
    check.checkInt(2, o.numSpecial(mat));

    mat = { {0,0,0,0,0},{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1} };
    check.checkInt(3, o.numSpecial(mat));
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
