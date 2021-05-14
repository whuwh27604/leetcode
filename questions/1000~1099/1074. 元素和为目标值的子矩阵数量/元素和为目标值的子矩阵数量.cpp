/* 元素和为目标值的子矩阵数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。

子矩阵 x1, y1, x2, y2 是满足 x1 <= x <= x2 且 y1 <= y <= y2 的所有单元 matrix[x][y] 的集合。

如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 != x1'），那么这两个子矩阵也不同。

 

示例 1：

输入：matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
输出：4
解释：四个只含 0 的 1x1 子矩阵。
示例 2：

输入：matrix = [[1,-1],[-1,1]], target = 0
输出：5
解释：两个 1x2 子矩阵，加上两个 2x1 子矩阵，再加上一个 2x2 子矩阵。
 

提示：

1 <= matrix.length <= 300
1 <= matrix[0].length <= 300
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-submatrices-that-sum-to-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int i, j, k, row = matrix.size(), column = matrix[0].size(), count = 0;
        if (row > column) {
            vector<vector<int>> transposed(column, vector<int>(row));
            transpose(matrix, transposed);
            return numSubmatrixSumTarget(transposed, target);
        }

        vector<vector<int>> submatrixSums(row, vector<int>(column, 0));
        getSubmatrixSums(matrix, submatrixSums);

        for (i = 0; i < row; ++i) {
            for (k = i; k < row; ++k) {
                unordered_map<int, int> sumsCount = { {0,1} };  // 预置一个sum为0的，这样算出sum为target时可以直接得到一个结果

                for (j = 0; j < column; ++j) {
                    int sum = submatrixSums[k][j] - (i == 0 ? 0 : submatrixSums[i - 1][j]);
                    if (sumsCount.count(sum - target) != 0) {
                        count += sumsCount[sum - target];
                    }

                    ++sumsCount[sum];
                }
            }
        }

        return count;
    }

    void getSubmatrixSums(vector<vector<int>>& matrix, vector<vector<int>>& submatrixSums) {
        int i, j, row = matrix.size(), column = matrix[0].size();
        submatrixSums[0][0] = matrix[0][0];

        for (j = 1; j < column; ++j) {
            submatrixSums[0][j] = submatrixSums[0][j - 1] + matrix[0][j];
        }

        for (i = 1; i < row; ++i) {
            submatrixSums[i][0] = submatrixSums[i - 1][0] + matrix[i][0];
        }

        for (i = 1; i < row; ++i) {
            for (j = 1; j < column; ++j) {
                submatrixSums[i][j] = matrix[i][j] + submatrixSums[i - 1][j] + submatrixSums[i][j - 1] - submatrixSums[i - 1][j - 1];
            }
        }
    }

    void transpose(vector<vector<int>>& matrix, vector<vector<int>>& transposed) {
        for (int i = 0; i < (int)matrix.size(); ++i) {
            for (int j = 0; j < (int)matrix[0].size(); ++j) {
                transposed[j][i] = matrix[i][j];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> matrix = { {0,1,0},{1,1,1},{0,1,0} };
    check.checkInt(4, o.numSubmatrixSumTarget(matrix, 0));

    matrix = { {1,-1},{-1,1} };
    check.checkInt(5, o.numSubmatrixSumTarget(matrix, 0));

    matrix = { {1,-1},{-1,1},{1,-1} };
    check.checkInt(10, o.numSubmatrixSumTarget(matrix, 0));
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
