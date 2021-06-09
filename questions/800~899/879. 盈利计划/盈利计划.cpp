/* 盈利计划.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
集团里有 n 名员工，他们可以完成各种各样的工作创造利润。

第 i 种工作会产生 profit[i] 的利润，它要求 group[i] 名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。

工作的任何至少产生 minProfit 利润的子集称为 盈利计划 。并且工作的成员总数最多为 n 。

有多少种计划可以选择？因为答案很大，所以 返回结果模 10^9 + 7 的值。

 

示例 1：

输入：n = 5, minProfit = 3, group = [2,2], profit = [2,3]
输出：2
解释：至少产生 3 的利润，该集团可以完成工作 0 和工作 1 ，或仅完成工作 1 。
总的来说，有两种计划。
示例 2：

输入：n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
输出：7
解释：至少产生 5 的利润，只要完成其中一种工作就行，所以该集团可以完成任何工作。
有 7 种可能的计划：(0)，(1)，(2)，(0,1)，(0,2)，(1,2)，以及 (0,1,2) 。
 

提示：

1 <= n <= 100
0 <= minProfit <= 100
1 <= group.length <= 100
1 <= group[i] <= 100
profit.length == group.length
0 <= profit[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/profitable-schemes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int size = group.size(), schemes = 0, mod = 1000000007;
        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
        dp[0][0][0] = 1;

        for (int index = 1; index <= size; ++index) {
            int members = group[index - 1], earn = profit[index - 1];

            for (int members = 0; members <= n; ++members) {
                for (int prof = 0; prof <= minProfit; ++prof) {
                    dp[index][members][prof] = dp[index - 1][members][prof];

                    if (members >= group[index - 1]) {
                        dp[index][members][prof] = (dp[index][members][prof] +
                            dp[index - 1][members - group[index - 1]][prof > profit[index - 1] ? prof - profit[index - 1] : 0]) % mod;
                    }
                }
            }
        }

        for (int members = 0; members <= n; ++members) {
            schemes = (schemes + dp[size][members][minProfit]) % mod;
        }

        return schemes;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> group = { 2,2 };
    vector<int> profit = { 2,3 };
    check.checkInt(2, o.profitableSchemes(5, 3, group, profit));

    group = { 2,3,5 };
    profit = { 6,7,8 };
    check.checkInt(7, o.profitableSchemes(10, 5, group, profit));

    group = { 80,40 };
    profit = { 88,88 };
    check.checkInt(2, o.profitableSchemes(64, 0, group, profit));
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
