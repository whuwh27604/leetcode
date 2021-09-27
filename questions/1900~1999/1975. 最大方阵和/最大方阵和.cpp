/* 最大方阵和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n x n 的整数方阵 matrix 。你可以执行以下操作 任意次 ：

选择 matrix 中 相邻 两个元素，并将它们都 乘以 -1 。
如果两个元素有 公共边 ，那么它们就是 相邻 的。

你的目的是 最大化 方阵元素的和。请你在执行以上操作之后，返回方阵的 最大 和。

 

示例 1：


输入：matrix = [[1,-1],[-1,1]]
输出：4
解释：我们可以执行以下操作使和等于 4 ：
- 将第一行的 2 个元素乘以 -1 。
- 将第一列的 2 个元素乘以 -1 。
示例 2：


输入：matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
输出：16
解释：我们可以执行以下操作使和等于 16 ：
- 将第二行的最后 2 个元素乘以 -1 。
 

提示：

n == matrix.length == matrix[i].length
2 <= n <= 250
-105 <= matrix[i][j] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-matrix-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        /* 1、如果有0，则可以全部变为正数。
           2、如果没有0，任意位置的两个负数，可以把它们交换为正数，而不改变其它任何数。
           3、所以如果是偶数个负数，则可以全部交换为正数；如果是奇数个负数，则选择绝对值最小的一个数为负数，其它都变为正数。 */
        long long sum = 0;
        int minAbs = INT_MAX, negatives = 0, zeros = 0;

        for (auto& row : matrix) {
            for (int num : row) {
                if (num < 0) {
                    ++negatives;
                    num = -num;
                }
                else if (num == 0) {
                    ++zeros;
                }

                sum += num;
                minAbs = min(minAbs, num);
            }
        }

        return (zeros != 0 || (negatives % 2) == 0) ? sum : (sum - minAbs - minAbs);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> matrix = { {1,-1},{-1,1} };
    check.checkLongLong(4, o.maxMatrixSum(matrix));

    matrix = { {1,2,3},{-1,-2,-3},{1,2,3} };
    check.checkLongLong(16, o.maxMatrixSum(matrix));

    matrix = { {-1,0,-1},{-2,1,3},{3,2,2} };
    check.checkLongLong(15, o.maxMatrixSum(matrix));

    matrix = { {1,2,3},{-5,5,5},{2,3,3} };
    check.checkLongLong(27, o.maxMatrixSum(matrix));
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
