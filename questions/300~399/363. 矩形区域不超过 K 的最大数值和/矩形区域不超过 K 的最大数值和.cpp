/* 矩形区域不超过 K 的最大数值和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空二维矩阵 matrix 和一个整数 k，找到这个矩阵内部不大于 k 的最大矩形和。

示例:

输入: matrix = [[1,0,1],[0,-2,3]], k = 2
输出: 2
解释: 矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
说明：

矩阵内的矩形区域面积必须大于 0。
如果行数远大于列数，你将如何解答呢？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), column = matrix[0].size(), maxSubmatrixSum = INT_MIN;

        for (int cStart = 0; cStart < column; ++cStart) {  // 因为row远大于column，所以列举所有可能的column
            vector<int> rowSums(row, 0);

            for (int cEnd = cStart; cEnd < column; ++cEnd) {
                set<int> submatrixSums;
                int submatrixSum = 0;

                for (int r = 0; r < row; ++r) {
                    rowSums[r] += matrix[r][cEnd];
                    submatrixSum += rowSums[r];

                    if (submatrixSum < k) {  // 可能是一个解
                        maxSubmatrixSum = max(maxSubmatrixSum, submatrixSum);
                    }
                    else if (submatrixSum == k) {  // 已经找到最优解
                        return k;
                    }

                    auto iter = submatrixSums.lower_bound(submatrixSum - k);  // 二分查找最接近k的子矩阵
                    if (iter != submatrixSums.end()) {
                        if (submatrixSum - *iter == k) {  // 已经找到最优解
                            return k;
                        }

                        maxSubmatrixSum = max(maxSubmatrixSum, submatrixSum - *iter);  // 可能是一个解
                    }

                    submatrixSums.insert(submatrixSum);
                }
            }
        }

        return maxSubmatrixSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> matrix = { {1,0,1},{0,-2,3} };
    check.checkInt(2, o.maxSumSubmatrix(matrix, 2));

    matrix = { {5,-4,-3,4},{-3,-4,4,5},{5,1,5,-4} };
    check.checkInt(-2, o.maxSumSubmatrix(matrix, -2));

    matrix = { {5} };
    check.checkInt(INT_MIN, o.maxSumSubmatrix(matrix, 2));

    matrix = { {5} };
    check.checkInt(5, o.maxSumSubmatrix(matrix, 5));
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
