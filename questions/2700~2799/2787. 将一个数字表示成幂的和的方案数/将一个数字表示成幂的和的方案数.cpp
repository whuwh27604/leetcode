/* 将一个数字表示成幂的和的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 正 整数 n 和 x 。

请你返回将 n 表示成一些 互不相同 正整数的 x 次幂之和的方案数。换句话说，你需要返回互不相同整数 [n1, n2, ..., nk] 的集合数目，满足 n = n1x + n2x + ... + nkx 。

由于答案可能非常大，请你将它对 109 + 7 取余后返回。

比方说，n = 160 且 x = 3 ，一个表示 n 的方法是 n = 23 + 33 + 53 。



示例 1：

输入：n = 10, x = 2
输出：1
解释：我们可以将 n 表示为：n = 32 + 12 = 10 。
这是唯一将 10 表达成不同整数 2 次方之和的方案。
示例 2：

输入：n = 4, x = 1
输出：2
解释：我们可以将 n 按以下方案表示：
- n = 41 = 4 。
- n = 31 + 11 = 4 。


提示：

1 <= n <= 300
1 <= x <= 5
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfWays(int n, int x) {
        int maxNum = getMaxNum(n, x);
        vector<int> nums(maxNum);
        vector<vector<int>> dp(maxNum + 1, vector<int>(n + 1, 0));
        dp[0][0] = dp[0][1] = 1;

        for (int i = 0; i < maxNum; ++i) {
            nums[i] = (int)pow(i + 1, x);
        }

        for (int i = 1; i < maxNum; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];

                if (j >= nums[i]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - nums[i]]) % 1000000007;
                }
            }
        }

        return dp[maxNum - 1][n];
    }

    int getMaxNum(int n, int x) {
        int num = 1;

        while ((int)pow(num, x) <= n) {
            ++num;
        }

        return num - 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.numberOfWays(10, 2));
    check.checkInt(2, o.numberOfWays(4, 1));
    check.checkInt(1, o.numberOfWays(36, 3));
    check.checkInt(872471266, o.numberOfWays(300, 1));
    check.checkInt(0, o.numberOfWays(300, 5));
    check.checkInt(1, o.numberOfWays(64, 3));
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
