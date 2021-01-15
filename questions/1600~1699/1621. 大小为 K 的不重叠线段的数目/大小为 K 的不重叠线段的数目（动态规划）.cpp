/* 大小为 K 的不重叠线段的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一维空间的 n 个点，其中第 i 个点（编号从 0 到 n-1）位于 x = i 处，请你找到 恰好 k 个不重叠 线段且每个线段至少覆盖两个点的方案数。线段的两个端点必须都是 整数坐标 。这 k 个线段不需要全部覆盖全部 n 个点，且它们的端点 可以 重合。

请你返回 k 个不重叠线段的方案数。由于答案可能很大，请将结果对 109 + 7 取余 后返回。

 

示例 1：


输入：n = 4, k = 2
输出：5
解释：
如图所示，两个线段分别用红色和蓝色标出。
上图展示了 5 种不同的方案 {(0,2),(2,3)}，{(0,1),(1,3)}，{(0,1),(2,3)}，{(1,2),(2,3)}，{(0,1),(1,2)} 。
示例 2：

输入：n = 3, k = 1
输出：3
解释：总共有 3 种不同的方案 {(0,1)}, {(0,2)}, {(1,2)} 。
示例 3：

输入：n = 30, k = 7
输出：796297179
解释：画 7 条线段的总方案数为 3796297200 种。将这个数对 109 + 7 取余得到 796297179 。
示例 4：

输入：n = 5, k = 3
输出：7
示例 5：

输入：n = 3, k = 2
输出：1
 

提示：

2 <= n <= 1000
1 <= k <= n-1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-sets-of-k-non-overlapping-line-segments
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        /* 假设已经知道n-1个点取k个线段的所有情况，那么加入第n个点时：
           1、不使用第n个点，直接n-1个点取k个线段，即dp[n-1][k]
           2、使用第n个点，并且2个点组成一个线段，剩下的点要取k-1个线段，即dp[n-1][k-1]
           3、使用第n个点，并且3个点组成一个线段，剩下的点要取k-1个线段，即dp[n-2][k-1]
              ......
           4、综上，dp[n][k]=dp[n-1][k]+dp[n-1][k-1]+dp[n-2][k-1]+...+dp[k][k-1](=1) */
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1));
        int mod = 1000000007;

        for (int j = 1; j <= k; ++j) {
            int sum = 1;

            for (int i = j + 2; i <= n; ++i) {
                sum = (sum + dp[i - 1][j - 1]) % mod;
                dp[i][j] = (dp[i - 1][j] + sum) % mod;
            }
        }

        return dp[n][k];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.numberOfSets(2, 1));
    check.checkInt(3, o.numberOfSets(3, 1));
    check.checkInt(1, o.numberOfSets(3, 2));
    check.checkInt(6, o.numberOfSets(4, 1));
    check.checkInt(5, o.numberOfSets(4, 2));
    check.checkInt(1, o.numberOfSets(4, 3));
    check.checkInt(10, o.numberOfSets(5, 1));
    check.checkInt(15, o.numberOfSets(5, 2));
    check.checkInt(7, o.numberOfSets(5, 3));
    check.checkInt(1, o.numberOfSets(5, 4));
    check.checkInt(796297179, o.numberOfSets(30, 7));
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
