/* 重构 2 行二进制矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 2 行 n 列的二进制数组：

矩阵是一个二进制矩阵，这意味着矩阵中的每个元素不是 0 就是 1。
第 0 行的元素之和为 upper。
第 1 行的元素之和为 lower。
第 i 列（从 0 开始编号）的元素之和为 colsum[i]，colsum 是一个长度为 n 的整数数组。
你需要利用 upper，lower 和 colsum 来重构这个矩阵，并以二维整数数组的形式返回它。

如果有多个不同的答案，那么任意一个都可以通过本题。

如果不存在符合要求的答案，就请返回一个空的二维数组。

 

示例 1：

输入：upper = 2, lower = 1, colsum = [1,1,1]
输出：[[1,1,0],[0,0,1]]
解释：[[1,0,1],[0,1,0]] 和 [[0,1,1],[1,0,0]] 也是正确答案。
示例 2：

输入：upper = 2, lower = 3, colsum = [2,2,1,1]
输出：[]
示例 3：

输入：upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
输出：[[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
 

提示：

1 <= colsum.length <= 10^5
0 <= upper, lower <= colsum.length
0 <= colsum[i] <= 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-a-2-row-binary-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int sumTwo = 0, sumOne = 0;
        countSums(colsum, sumTwo, sumOne);

        int upperOne = upper - sumTwo, lowerOne = lower - sumTwo;
        if ((sumTwo * 2 + sumOne != upper + lower) || (upperOne < 0) || (lowerOne < 0)) {
            return {};
        }

        int i, size = colsum.size();
        vector<vector<int>> matrix(2, vector<int>(size, 0));

        for (i = 0; i < size; ++i) {
            if (colsum[i] == 2) {
                matrix[0][i] = matrix[1][i] = 1;
            }
            else if (colsum[i] == 1) {
                if (upperOne != 0) {
                    matrix[0][i] = 1;
                    --upperOne;
                }
                else {
                    matrix[1][i] = 1;
                }
            }
        }

        return matrix;
    }

    void countSums(vector<int>& colsum, int& sumTwo, int& sumOne) {
        for (int sum : colsum) {
            if (sum == 2) {
                ++sumTwo;
            }
            else if (sum == 1) {
                ++sumOne;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> colsum = { 1,1,1 };
    vector<vector<int>> actual = o.reconstructMatrix(2, 1, colsum);
    vector<vector<int>> expected = { {1,1,0},{0,0,1} };
    check.checkIntVectorVector(expected, actual);

    colsum = { 2,2,1,1 };
    actual = o.reconstructMatrix(2, 3, colsum);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    colsum = { 2,2,1,1 };
    actual = o.reconstructMatrix(1, 5, colsum);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    colsum = { 2,2,1,1 };
    actual = o.reconstructMatrix(6, 0, colsum);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    colsum = { 2,1,2,0,1,0,1,2,0,1 };
    actual = o.reconstructMatrix(5, 5, colsum);
    expected = { {1,1,1,0,1,0,0,1,0,0},{1,0,1,0,0,0,1,1,0,1} };
    check.checkIntVectorVector(expected, actual);

    colsum = { 0,2 };
    actual = o.reconstructMatrix(2, 0, colsum);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    colsum = { 0 };
    actual = o.reconstructMatrix(0, 0, colsum);
    expected = { {0},{0} };
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
