/* 最高乘法得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 4 的整数数组 a 和一个大小 至少为 4 的整数数组 b。

你需要从数组 b 中选择四个下标 i0, i1, i2, 和 i3，并满足 i0 < i1 < i2 < i3。你的得分将是 a[0] * b[i0] + a[1] * b[i1] + a[2] * b[i2] + a[3] * b[i3] 的值。

返回你能够获得的 最大 得分。



示例 1：

输入： a = [3,2,5,6], b = [2,-6,4,-5,-3,2,-7]

输出： 26

解释：
选择下标 0, 1, 2 和 5。得分为 3 * 2 + 2 * (-6) + 5 * 4 + 6 * 2 = 26。

示例 2：

输入： a = [-1,4,5,-2], b = [-5,-1,-3,-2,-4]

输出： -1

解释：
选择下标 0, 1, 3 和 4。得分为 (-1) * (-5) + 4 * (-1) + 5 * (-2) + (-2) * (-4) = -1。



提示：

a.length == 4
4 <= b.length <= 105
-105 <= a[i], b[i] <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = 4, m = (int)b.size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));  // dp[i][j]表示从b[0, j]选择i个数，匹配到a[i]的最大值
        dp[0][0] = (long long)a[0] * b[0];

        for (int j = 1; j < m; ++j) {
            dp[0][j] = max(dp[0][j - 1], (long long)a[0] * b[j]);
        }

        for (int i = 1; i < n; ++i) {
            for (int k = 0; k <= i; ++k) {
                dp[i][i] += (long long)a[k] * b[k];
            }
            for (int j = i + 1; j < m; ++j) {
                dp[i][j] = max(dp[i][j - 1], (long long)a[i] * b[j] + dp[i - 1][j - 1]);
            }
        }

        return dp[n - 1][m - 1];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> a = { 3,2,5,6 };
    vector<int> b = { 2,-6,4,-5,-3,2,-7 };
    check.checkLongLong(26, o.maxScore(a, b));

    a = { -1,4,5,-2 };
    b = { -5,-1,-3,-2,-4 };
    check.checkLongLong(-1, o.maxScore(a, b));
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
