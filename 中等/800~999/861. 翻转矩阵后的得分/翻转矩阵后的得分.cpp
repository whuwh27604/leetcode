/* 翻转矩阵后的得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个二维矩阵 A 其中每个元素的值为 0 或 1 。

移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。

在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。

返回尽可能高的分数。

 

示例：

输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
输出：39
解释：
转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 

提示：

1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] 是 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/score-after-flipping-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int i, j, row = A.size(), column = A[0].size();
        int score = 0, bit = 1;

        for (i = 0; i < row; ++i) {
            if (A[i][0] == 0) {
                for (j = 0; j < column; ++j) {
                    A[i][j] ^= 1;
                }
            }
        }

        for (j = column - 1; j > 0; --j) {
            int count = 0;

            for (i = 0; i < row; ++i) {
                if (A[i][j] == 1) {
                    count++;
                }
            }

            score += (bit * max(count, row - count));
            bit <<= 1;
        }

        score += (bit * row);

        return score;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> A = { {0,0,1,1},{1,0,1,0},{1,1,0,0} };
    check.checkInt(39, o.matrixScore(A));

    A = { {0} };
    check.checkInt(1, o.matrixScore(A));

    A = { {1} };
    check.checkInt(1, o.matrixScore(A));

    A = { {0,0},{0,0} };
    check.checkInt(6, o.matrixScore(A));
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
