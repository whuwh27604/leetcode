/* 给墙壁刷油漆.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度为 n 下标从 0 开始的整数数组 cost 和 time ，分别表示给 n 堵不同的墙刷油漆需要的开销和时间。你有两名油漆匠：

一位需要 付费 的油漆匠，刷第 i 堵墙需要花费 time[i] 单位的时间，开销为 cost[i] 单位的钱。
一位 免费 的油漆匠，刷 任意 一堵墙的时间为 1 单位，开销为 0 。但是必须在付费油漆匠 工作 时，免费油漆匠才会工作。
请你返回刷完 n 堵墙最少开销为多少。



示例 1：

输入：cost = [1,2,3,2], time = [1,2,3,2]
输出：3
解释：下标为 0 和 1 的墙由付费油漆匠来刷，需要 3 单位时间。同时，免费油漆匠刷下标为 2 和 3 的墙，需要 2 单位时间，开销为 0 。总开销为 1 + 2 = 3 。
示例 2：

输入：cost = [2,3,4,2], time = [1,1,1,1]
输出：4
解释：下标为 0 和 3 的墙由付费油漆匠来刷，需要 2 单位时间。同时，免费油漆匠刷下标为 1 和 2 的墙，需要 2 单位时间，开销为 0 。总开销为 2 + 2 = 4 。


提示：

1 <= cost.length <= 500
cost.length == time.length
1 <= cost[i] <= 106
1 <= time[i] <= 500
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        /* paidWalls + freeWalls = n
           paidTime >= freeTime = freeWalls
           paidTime >= n - paidWalls
           paidTime + paidWalls >= n
           sum(paidTime + 1) >= n
           问题转换为0-1背包：选择x个walls，满足sum(paidTime + 1) >= n，求最小的sum(cost) */
        int n = cost.size();
        vector<int> dp(n + 1, INT_MAX / 2);  // dp[i][paidTime]表示前i个walls，sum(paidTime + 1)至少为paidTime的情况下的最小sum(cost)。采用滚动数组优化掉一维

        for (int& t : time) {
            t += 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int paidTime = n; paidTime > 0; --paidTime) {
                if (paidTime > time[i]) {  // 1、不选第i个wall，那么dp[i][paidTime] = dp[i - 1][paidTime]；2、选择第i个wall，那么dp[i][paidTime] = dp[i - 1][paidTime - time[i]] + cost[i]
                    dp[paidTime] = min(dp[paidTime], dp[paidTime - time[i]] + cost[i]);
                }
                else {  // paidTime <= time[i]时，选择第i个wall，花费可以小到cost[i]
                    dp[paidTime] = min(dp[paidTime], cost[i]);
                }
            }
        }

        return dp[n];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> cost = { 1,2,3,2 };
    vector<int> time = { 1,2,3,2 };
    check.checkInt(3, o.paintWalls(cost, time));

    cost = { 2,3,4,2 };
    time = { 1,1,1,1 };
    check.checkInt(4, o.paintWalls(cost, time));
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
