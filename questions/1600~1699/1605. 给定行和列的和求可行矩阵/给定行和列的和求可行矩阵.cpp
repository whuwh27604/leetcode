/* 给定行和列的和求可行矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个非负整数数组 rowSum 和 colSum ，其中 rowSum[i] 是二维矩阵中第 i 行元素的和， colSum[j] 是第 j 列元素的和。换言之你不知道矩阵里的每个元素，但是你知道每一行和每一列的和。

请找到大小为 rowSum.length x colSum.length 的任意 非负整数 矩阵，且该矩阵满足 rowSum 和 colSum 的要求。

请你返回任意一个满足题目要求的二维矩阵，题目保证存在 至少一个 可行矩阵。

 

示例 1：

输入：rowSum = [3,8], colSum = [4,7]
输出：[[3,0],
      [1,7]]
解释：
第 0 行：3 + 0 = 3 == rowSum[0]
第 1 行：1 + 7 = 8 == rowSum[1]
第 0 列：3 + 1 = 4 == colSum[0]
第 1 列：0 + 7 = 7 == colSum[1]
行和列的和都满足题目要求，且所有矩阵元素都是非负的。
另一个可行的矩阵为：[[1,2],
                  [3,5]]
示例 2：

输入：rowSum = [5,7,10], colSum = [8,6,8]
输出：[[0,5,0],
      [6,1,0],
      [2,0,8]]
示例 3：

输入：rowSum = [14,9], colSum = [6,9,8]
输出：[[0,9,5],
      [6,0,3]]
示例 4：

输入：rowSum = [1,0], colSum = [1]
输出：[[1],
      [0]]
示例 5：

输入：rowSum = [0], colSum = [0]
输出：[[0]]
 

提示：

1 <= rowSum.length, colSum.length <= 500
0 <= rowSum[i], colSum[i] <= 108
sum(rows) == sum(columns)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-valid-matrix-given-row-and-column-sums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int i, j, row = rowSum.size(), column = colSum.size(), totalSum = 0;
        vector<vector<int>> matrix(row, vector<int>(column));

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                int num = min(rowSum[i], colSum[j]);
                matrix[i][j] = num;
                rowSum[i] -= num;
                colSum[j] -= num;
            }
        }

        return matrix;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> rowSum = { 3,8 };
    vector<int> colSum = { 4,7 };
    vector<vector<int>> actual = o.restoreMatrix(rowSum, colSum);
    vector<vector<int>> expected = { {3,0},{1,7} };
    check.checkIntVectorVector(expected, actual);

    rowSum = { 5,7,10 };
    colSum = { 8,6,8 };
    actual = o.restoreMatrix(rowSum, colSum);
    expected = { {5,0,0},{3,4,0},{0,2,8} };
    check.checkIntVectorVector(expected, actual);

    rowSum = { 14,9 };
    colSum = { 6,9,8 };
    actual = o.restoreMatrix(rowSum, colSum);
    expected = { {6,8,0},{0,1,8} };
    check.checkIntVectorVector(expected, actual);

    rowSum = { 1,0 };
    colSum = { 1 };
    actual = o.restoreMatrix(rowSum, colSum);
    expected = { {1},{0} };
    check.checkIntVectorVector(expected, actual);

    rowSum = { 0 };
    colSum = { 0 };
    actual = o.restoreMatrix(rowSum, colSum);
    expected = { {0} };
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
