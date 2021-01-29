/* 找出第 K 大的异或坐标值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维矩阵 matrix 和一个整数 k ，矩阵大小为 m x n 由非负整数组成。

矩阵中坐标 (a, b) 的 值 可由对所有满足 0 <= i <= a < m 且 0 <= j <= b < n 的元素 matrix[i][j]（下标从 0 开始计数）执行异或运算得到。

请你找出 matrix 的所有坐标中第 k 大的值（k 的值从 1 开始计数）。

 

示例 1：

输入：matrix = [[5,2],[1,6]], k = 1
输出：7
解释：坐标 (0,1) 的值是 5 XOR 2 = 7 ，为最大的值。
示例 2：

输入：matrix = [[5,2],[1,6]], k = 2
输出：5
解释：坐标 (0,0) 的值是 5 = 5 ，为第 2 大的值。
示例 3：

输入：matrix = [[5,2],[1,6]], k = 3
输出：4
解释：坐标 (1,0) 的值是 5 XOR 1 = 4 ，为第 3 大的值。
示例 4：

输入：matrix = [[5,2],[1,6]], k = 4
输出：0
解释：坐标 (1,1) 的值是 5 XOR 2 XOR 1 XOR 6 = 0 ，为第 4 大的值。
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
0 <= matrix[i][j] <= 106
1 <= k <= m * n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> kLargest;
        int i, j, row = matrix.size(), column = matrix[0].size();
        vector<vector<int>> xors(row + 1, vector<int>(column + 1, 0));

        for (i = 0; i < row; ++i) {
            int xorValue = 0;

            for (j = 0; j < column; ++j) {
                xorValue ^= matrix[i][j];
                xors[i + 1][j + 1] = xors[i][j + 1] ^ xorValue;
                kLargest.push(xors[i + 1][j + 1]);
                if ((int)kLargest.size() > k) {
                    kLargest.pop();
                }
            }
        }

        return kLargest.top();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> matrix = { {5,2},{1,6} };
    check.checkInt(7, o.kthLargestValue(matrix, 1));

    matrix = { {5,2},{1,6} };
    check.checkInt(5, o.kthLargestValue(matrix, 2));

    matrix = { {5,2},{1,6} };
    check.checkInt(4, o.kthLargestValue(matrix, 3));

    matrix = { {5,2},{1,6} };
    check.checkInt(0, o.kthLargestValue(matrix, 4));

    matrix = { {10,9,5},{2,0,4},{1,0,9},{3,4,8} };
    check.checkInt(1, o.kthLargestValue(matrix, 10));
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
