/* 最大平均值和的分组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们将给定的数组 A 分成 K 个相邻的非空子数组 ，我们的分数由每个子数组内的平均值的总和构成。计算我们所能得到的最大分数是多少。

注意我们必须使用 A 数组中的每一个数进行分组，并且分数不一定需要是整数。

示例:
输入:
A = [9,1,2,3,9]
K = 3
输出: 20
解释:
A 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
我们也可以把 A 分成[9, 1], [2], [3, 9].
这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
说明:

1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
答案误差在 10^-6 内被视为是正确的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-sum-of-averages
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int index, group, size = A.size();
        vector<vector<double>> dp(K + 1, vector<double>(size, 0));

        vector<int> preSum(size + 1, 0);
        getPreSum(A, preSum);

        for (index = size - 1; index >= 0; --index) {
            dp[1][index] = ((double)preSum[size] - preSum[index]) / ((double)size - index);

            for (group = 2; group <= K; ++group) {
                for (int i = index; i <= size - group; ++i) {
                    dp[group][index] = max(dp[group][index], ((double)preSum[i + 1] - preSum[index]) / ((double)i - index + 1) + dp[group - 1][i + 1]);
                }
            }
        }

        return dp[K][0];
    }

    void getPreSum(vector<int>& A, vector<int>& preSum) {
        preSum[0] = 0;

        for (unsigned int i = 0; i < A.size(); ++i) {
            preSum[i + 1] = preSum[i] + A[i];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 9,1,2,3,9 };
    check.checkDouble(20, o.largestSumOfAverages(A, 3));

    A = { 9,1,2,3,9 };
    check.checkDouble(4.8, o.largestSumOfAverages(A, 1));

    A = { 9 };
    check.checkDouble(9, o.largestSumOfAverages(A, 1));

    A = { 4,1,7,5,6,2,3 };
    check.checkDouble(18.166667, o.largestSumOfAverages(A, 4));
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
