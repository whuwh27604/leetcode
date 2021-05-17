/* 恰有 K 根木棍可以看到的排列数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 根长度互不相同的木棍，长度为从 1 到 n 的整数。请你将这些木棍排成一排，并满足从左侧 可以看到 恰好 k 根木棍。从左侧 可以看到 木棍的前提是这个木棍的 左侧 不存在比它 更长的 木棍。

例如，如果木棍排列为 [1,3,2,5,4] ，那么从左侧可以看到的就是长度分别为 1、3 、5 的木棍。
给你 n 和 k ，返回符合题目要求的排列 数目 。由于答案可能很大，请返回对 109 + 7 取余 的结果。

 

示例 1：

输入：n = 3, k = 2
输出：3
解释：[1,3,2], [2,3,1] 和 [2,1,3] 是仅有的能满足恰好 2 根木棍可以看到的排列。
可以看到的木棍已经用粗体+斜体标识。
示例 2：

输入：n = 5, k = 5
输出：1
解释：[1,2,3,4,5] 是唯一一种能满足全部 5 根木棍可以看到的排列。
可以看到的木棍已经用粗体+斜体标识。
示例 3：

输入：n = 20, k = 11
输出：647427950
解释：总共有 647427950 (mod 109 + 7) 种能满足恰好有 11 根木棍可以看到的排列。
 

提示：

1 <= n <= 1000
1 <= k <= n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

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
