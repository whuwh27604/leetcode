/* 矩阵区域和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m * n 的矩阵 mat 和一个整数 K ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素 mat[r][c] 的和： 

i - K <= r <= i + K, j - K <= c <= j + K 
(r, c) 在矩阵内。
 

示例 1：

输入：mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
输出：[[12,21,16],[27,45,33],[24,39,28]]
示例 2：

输入：mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
输出：[[45,45,45],[45,45,45],[45,45,45]]
 

提示：

m == mat.length
n == mat[i].length
1 <= m, n, K <= 100
1 <= mat[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/matrix-block-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int row = mat.size(), column = mat[0].size();

        vector<vector<int>> preSum(row + 1, vector<int>(column + 1, 0));
        getPreSum(mat, preSum);

        vector<vector<int>> blockSum(row, vector<int>(column));
        getBlockSum(preSum, K, blockSum);

        return blockSum;
    }

    void getPreSum(vector<vector<int>>& mat, vector<vector<int>>& preSum) {
        int i, j, row = mat.size(), column = mat[0].size();

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                preSum[i + 1][j + 1] = preSum[i + 1][j] + preSum[i][j + 1] - preSum[i][j] + mat[i][j];
            }
        }
    }

    void getBlockSum(vector<vector<int>>& preSum, int K, vector<vector<int>>& blockSum) {
        int i, j, row = blockSum.size(), column = blockSum[0].size();

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                int r0 = (i - K) >= 0 ? i - K : 0;
                int c0 = (j - K) >= 0 ? j - K : 0;
                int r1 = (i + K) < row ? i + K : row - 1;
                int c1 = (j + K) < column ? j + K : column - 1;

                blockSum[i][j] = preSum[r1 + 1][c1 + 1] - preSum[r1 + 1][c0] - preSum[r0][c1 + 1] + preSum[r0][c0];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = { {1,2,3},{4,5,6},{7,8,9} };
    vector<vector<int>> actual = o.matrixBlockSum(mat, 1);
    vector<vector<int>> expected = { {12,21,16},{27,45,33},{24,39,28} };
    check.checkIntVectorVector(expected, actual);

    mat = { {1,2,3},{4,5,6},{7,8,9} };
    actual = o.matrixBlockSum(mat, 2);
    expected = { {45,45,45},{45,45,45},{45,45,45} };
    check.checkIntVectorVector(expected, actual);

    mat = { {5} };
    actual = o.matrixBlockSum(mat, 1);
    expected = { {5} };
    check.checkIntVectorVector(expected, actual);
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
