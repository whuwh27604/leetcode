/* 出界的路径数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个 m × n 的网格和一个球。球的起始坐标为 (i,j) ，你可以将球移到相邻的单元格内，或者往上、下、左、右四个方向上移动使球穿过网格边界。但是，你最多可以移动 N 次。找出可以将球移出边界的路径数量。答案可能非常大，返回 结果 mod 109 + 7 的值。

 

示例 1：

输入: m = 2, n = 2, N = 2, i = 0, j = 0
输出: 6
解释:

示例 2：

输入: m = 1, n = 3, N = 3, i = 0, j = 1
输出: 12
解释:

 

说明:

球一旦出界，就不能再被移动回网格内。
网格的长度和高度在 [1,50] 的范围内。
N 在 [0,50] 的范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/out-of-boundary-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0 || i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        long long paths = 0;
        long long* dp = new long long[(N + 1) * m * n]();
        dp[i * n + j] = 1;
        int k, r, c, size = m * n, base = 0, mod = 1000000007;

        for (k = 0; k < N; ++k) {
            int newBase = base + size;

            for (r = 0; r < m; ++r) {
                for (c = 0; c < n; ++c) {  // 刷新到达每个位置的路径数
                    dp[newBase + r * n + c] = ((r == 0 ? 0 : dp[base + (r - 1) * n + c])
                        + (r == (long long)m - 1 ? 0 : dp[base + (r + 1) * n + c])
                        + (c == 0 ? 0 : dp[base + r * n + c - 1])
                        + (c == (long long)n - 1 ? 0 : dp[base + r * n + c + 1])) % mod;
                }
            }

            for (c = 0; c < n; ++c) {
                paths += dp[base + c];  // 从上面出去
                paths += dp[base + (m - 1) * n + c];  // 从下面出去
            }

            for (r = 0; r < m; ++r) {
                paths += dp[base + r * n];  // 从左边出去
                paths += dp[base + r * n + n - 1];  // 从右边出去
            }

            paths %= mod;
            base = newBase;
        }

        delete[] dp;
        return (int)paths;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.findPaths(2, 2, 2, 2, 2));
    check.checkInt(6, o.findPaths(2, 2, 2, 0, 0));
    check.checkInt(797922653, o.findPaths(2, 2, 50, 0, 1));
    check.checkInt(12, o.findPaths(1, 3, 3, 0, 1));
    check.checkInt(0, o.findPaths(1, 3, 0, 0, 1));
    check.checkInt(134217723, o.findPaths(1, 3, 49, 0, 2));
    check.checkInt(85315957, o.findPaths(10, 12, 50, 5, 6));
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
