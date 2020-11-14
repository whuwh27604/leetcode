/* 分汤.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 A 和 B 两种类型的汤。一开始每种类型的汤有 N 毫升。有四种分配操作：

提供 100ml 的汤A 和 0ml 的汤B。
提供 75ml 的汤A 和 25ml 的汤B。
提供 50ml 的汤A 和 50ml 的汤B。
提供 25ml 的汤A 和 75ml 的汤B。
当我们把汤分配给某人之后，汤就没有了。每个回合，我们将从四种概率同为0.25的操作中进行分配选择。如果汤的剩余量不足以完成某次操作，我们将尽可能分配。当两种类型的汤都分配完时，停止操作。

注意不存在先分配100 ml汤B的操作。

需要返回的值： 汤A先分配完的概率 + 汤A和汤B同时分配完的概率 / 2。

示例:
输入: N = 50
输出: 0.625
解释:
如果我们选择前两个操作，A将首先变为空。对于第三个操作，A和B会同时变为空。对于第四个操作，B将首先变为空。
所以A变为空的总概率加上A和B同时变为空的概率的一半是 0.25 *(1 + 1 + 0.5 + 0)= 0.625。
注释:

0 <= N <= 10^9。
返回值在 10^-6 的范围将被认为是正确的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/soup-servings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double soupServings(int N) {
        if (N >= 5600) {
            return 1;
        }
        N = N / 25 + (N % 25 == 0 ? 0 : 1);

        /* dp[i][j]表示A有i份，B有j份时，A先分完或同时分完的概率，则：dp[i][j]=(dp[i-4][j]+dp[i-3][j-1]+dp[i-2][j-2]+dp[i-1][j-3])/4 */
        vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0));
        dp[0][0] = 0.5;  // 为啥是0.5？为啥不是0或者0.75或者1？感觉很难解释清楚
        for (int i = 1; i <= N; ++i) {
            dp[0][i] = 1;  // A先分完，B还有，所以概率为1
            dp[i][0] = 0;  // A还有，B已经分完了，所以概率为0
        }

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = (dp[i > 4 ? i - 4 : 0][j] + dp[i > 3 ? i - 3 : 0][j > 1 ? j - 1 : 0]
                    + dp[i > 2 ? i - 2 : 0][j > 2 ? j - 2 : 0] + dp[i > 1 ? i - 1 : 0][j > 3 ? j - 3 : 0]) / 4;
            }
        }

        return dp[N][N];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkDouble(0.625, o.soupServings(50));
    check.checkDouble(0.5, o.soupServings(0));
    check.checkDouble(0.625, o.soupServings(1));
    check.checkDouble(0.71875, o.soupServings(100));
    check.checkDouble(0.916344, o.soupServings(500));
    check.checkDouble(0.976565, o.soupServings(1000));
    check.checkDouble(1, o.soupServings(5600));
    check.checkDouble(1, o.soupServings(10000));
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
