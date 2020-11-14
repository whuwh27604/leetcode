/* 下降路径最小和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个方形整数数组 A，我们想要得到通过 A 的下降路径的最小和。

下降路径可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列。

 

示例：

输入：[[1,2,3],[4,5,6],[7,8,9]]
输出：12
解释：
可能的下降路径有：
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
和最小的下降路径是 [1,4,7]，所以答案是 12。

 

提示：

1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-falling-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int i, j, size = A.size(), minSum = INT_MAX;
        if (size == 1) {
            return A[0][0];
        }

        vector<vector<int>> dp(size, vector<int>(size, 0));
        dp[0] = A[0];

        for (i = 1; i < size; ++i) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + A[i][0];

            for (j = 1; j < size - 1; ++j) {
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + A[i][j];
            }

            dp[i][size - 1] = min(dp[i - 1][size - 2], dp[i - 1][size - 1]) + A[i][size - 1];
        }

        for (j = 0; j < size; ++j) {
            minSum = min(minSum, dp[size - 1][j]);
        }

        return minSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> A = { {1,2,3},{4,5,6},{7,8,9} };
    check.checkInt(12, o.minFallingPathSum(A));

    A = { {5} };
    check.checkInt(5, o.minFallingPathSum(A));

    A = { {10,9},{8,7} };
    check.checkInt(16, o.minFallingPathSum(A));
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
