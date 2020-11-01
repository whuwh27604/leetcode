/* 矩阵中的幸运数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。

幸运数是指矩阵中满足同时下列两个条件的元素：

在同一行的所有元素中最小
在同一列的所有元素中最大
 

示例 1：

输入：matrix = [[3,7,8],[9,11,13],[15,16,17]]
输出：[15]
解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
示例 2：

输入：matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
输出：[12]
解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
示例 3：

输入：matrix = [[7,8],[1,2]]
输出：[7]
 

提示：

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5
矩阵中的所有元素都是不同的

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> allMinNums;
        int i, j, row = matrix.size(), column = matrix[0].size();

        for (i = 0; i < row; i++) {
            int minimun = minNumInOneRow(matrix[i]);
            allMinNums.push_back(minimun);
        }

        vector<int> ans;
        for (j = 0; j < column; j++) {
            int rowIndex, maximum = INT_MIN;

            for (i = 0; i < row; i++) {
                if (matrix[i][j] > maximum) {
                    maximum = matrix[i][j];
                    rowIndex = i;
                }
            }

            if (allMinNums[rowIndex] == maximum) {
                ans.push_back(maximum);
            }
        }

        return ans;
    }

    int minNumInOneRow(vector<int>& row) {
        int i, len = row.size(), minimum = INT_MAX;

        for (i = 0; i < len; i++) {
            minimum = min(minimum, row[i]);
        }

        return minimum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> matrix = { {3,7,8},{9,11,13},{15,16,17} };
    vector<int> actual = o.luckyNumbers(matrix);
    vector<int> expected = { 15 };
    check.checkIntVector(expected, actual);

    matrix = { {1,10,4,2},{9,3,8,7},{15,16,17,12} };
    actual = o.luckyNumbers(matrix);
    expected = { 12 };
    check.checkIntVector(expected, actual);

    matrix = { {7,8},{1,2} };
    actual = o.luckyNumbers(matrix);
    expected = { 7 };
    check.checkIntVector(expected, actual);

    matrix = { {8} };
    actual = o.luckyNumbers(matrix);
    expected = { 8 };
    check.checkIntVector(expected, actual);

    matrix = { {1,2,3} };
    actual = o.luckyNumbers(matrix);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    matrix = { {1},{2},{3} };
    actual = o.luckyNumbers(matrix);
    expected = { 3 };
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
