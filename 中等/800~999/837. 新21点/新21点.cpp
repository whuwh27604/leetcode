/* 新21点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
爱丽丝参与一个大致基于纸牌游戏 “21点” 规则的游戏，描述如下：

爱丽丝以 0 分开始，并在她的得分少于 K 分时抽取数字。 抽取时，她从 [1, W] 的范围中随机获得一个整数作为分数进行累计，其中 W 是整数。 每次抽取都是独立的，其结果具有相同的概率。

当爱丽丝获得不少于 K 分时，她就停止抽取数字。 爱丽丝的分数不超过 N 的概率是多少？

 

示例 1：

输入：N = 10, K = 1, W = 10
输出：1.00000
说明：爱丽丝得到一张卡，然后停止。
示例 2：

输入：N = 6, K = 1, W = 10
输出：0.60000
说明：爱丽丝得到一张卡，然后停止。
在 W = 10 的 6 种可能下，她的得分不超过 N = 6 分。
示例 3：

输入：N = 21, K = 17, W = 10
输出：0.73278
 

提示：

0 <= K <= N <= 10000
1 <= W <= 10000
如果答案与正确答案的误差不超过 10^-5，则该答案将被视为正确答案通过。
此问题的判断限制时间已经减少。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/new-21-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
        /* 令dp[x]表示当前分数为x时，获胜的概率，考虑最后一手牌，假设当前x为k-1，抽到了w，这是所有情况中x最远能够到达的地方k-1+w。所以：
           1、x>min(n, k-1+w)时，dp[x]=0;
           2、k<=x<=min(n, k-1+w)时，dp[x]=1;
           3、x<k时，dp[x]=(dp[x+1]+dp[x+2]+...+dp[x+w])/w */
        if (K == 0) {
            return 1;
        }

        int x, size = K + W;
        vector<double> dp(size, 0);

        for (x = K; x <= min(N, K - 1 + W); ++x) {
            dp[x] = 1;
        }

        dp[K - 1] = ((double)min(N, K - 1 + W) - K + 1) / W;

        for (x = K - 2; x >= 0; --x) {
            dp[x] = dp[x + 1] - (dp[x + W + 1] - dp[x + 1]) / W;
        }

        return dp[0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkDouble(1.0, o.new21Game(10, 1, 10));
    check.checkDouble(0.6, o.new21Game(6, 1, 10));
    check.checkDouble(0.732778, o.new21Game(21, 17, 10));
    check.checkDouble(0.99, o.new21Game(10, 2, 10));
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
