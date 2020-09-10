/* 多米诺和托米诺平铺.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有两种形状的瓷砖：一种是 2x1 的多米诺形，另一种是形如 "L" 的托米诺形。两种形状都可以旋转。

XX  <- 多米诺

XX  <- "L" 托米诺
X
给定 N 的值，有多少种方法可以平铺 2 x N 的面板？返回值 mod 10^9 + 7。

（平铺指的是每个正方形都必须有瓷砖覆盖。两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，使得恰好有一个平铺有一个瓷砖占据两个正方形。）

示例:
输入: 3
输出: 5
解释:
下面列出了五种不同的方法，不同字母代表不同瓷砖：
XYZ XXZ XYY XXY XYY
XYZ YYZ XZZ XYY XXY
提示：

N  的范围是 [1, 1000]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/domino-and-tromino-tiling
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numTilings(int N) {
        /* 令dp[i]表示i列平铺方法数，ways[i]表示纵向不能拆分开的方法数。此题关键是要能总结出ways[i]永远等于2(i>=3)
           dp[i]=dp[i-1]*ways[1]+dp[i-2]*ways[2]+dp[i-3]*ways[3]+...dp[1]*ways[i-1]+2
                =dp[i-1]+dp[i-2]+2dp[i-3]+2dp[i-4]+...+2dp[1]+2
                =dp[i-1]+dp[i-2]+dp[i-3]+2dp[i-4]+...+2dp[1]+2+dp[i-3]
                =dp[i-1]+dp[i-1]+dp[i-3]
                =2dp[i-1]+dp[i-3] */
        vector<int> dp(N > 2 ? N + 1 : 4, 1);
        dp[2] = 2;
        dp[3] = 5;
        int mod = 1000000007;

        for (int i = 4; i <= N; i++) {
            dp[i] = ((2 * dp[i - 1]) % mod + dp[i - 3]) % mod;
        }

        return dp[N];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.numTilings(1));
    check.checkInt(2, o.numTilings(2));
    check.checkInt(5, o.numTilings(3));
    check.checkInt(11, o.numTilings(4));
    check.checkInt(24, o.numTilings(5));
    check.checkInt(53, o.numTilings(6));
    check.checkInt(326038248, o.numTilings(999));
    check.checkInt(979232805, o.numTilings(1000));
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
