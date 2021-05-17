// 恰有 K 根木棍可以看到的排列数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        /* 令dp[i][j]表示i根棍棍能看到j根的方法数，考虑最后一根棍棍是否能够看到：
           1、如果能看到，那么它必然是i，则剩下i-1根棍棍要看到j-1根；
           2、如果不能看到，那么它可能是[1,i-1]中，任何一根。那么还剩下i-1根棍棍要看到j根。
           综上，dp[i][j] = dp[i-1][j-1] + (i-1) * dp[i-1][j] */
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        dp[1][1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i && j <= k; ++j) {
                dp[i][j] = (dp[i - 1][j - 1] + ((long long)i - 1) * dp[i - 1][j]) % 1000000007;
            }
        }

        return (int)dp[n][k];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.rearrangeSticks(1, 1));
    check.checkInt(1, o.rearrangeSticks(2, 1));
    check.checkInt(1, o.rearrangeSticks(2, 2));
    check.checkInt(2, o.rearrangeSticks(3, 1));
    check.checkInt(3, o.rearrangeSticks(3, 2));
    check.checkInt(1, o.rearrangeSticks(3, 3));
    check.checkInt(6, o.rearrangeSticks(4, 1));
    check.checkInt(11, o.rearrangeSticks(4, 2));
    check.checkInt(6, o.rearrangeSticks(4, 3));
    check.checkInt(1, o.rearrangeSticks(4, 4));
    check.checkInt(24, o.rearrangeSticks(5, 1));
    check.checkInt(50, o.rearrangeSticks(5, 2));
    check.checkInt(35, o.rearrangeSticks(5, 3));
    check.checkInt(10, o.rearrangeSticks(5, 4));
    check.checkInt(1, o.rearrangeSticks(5, 5));
    check.checkInt(647427950, o.rearrangeSticks(20, 11));
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
