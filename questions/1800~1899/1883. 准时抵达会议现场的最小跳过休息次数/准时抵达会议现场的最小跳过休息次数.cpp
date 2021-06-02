﻿/* 准时抵达会议现场的最小跳过休息次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 hoursBefore ，表示你要前往会议所剩下的可用小时数。要想成功抵达会议现场，你必须途经 n 条道路。道路的长度用一个长度为 n 的整数数组 dist 表示，其中 dist[i] 表示第 i 条道路的长度（单位：千米）。另给你一个整数 speed ，表示你在道路上前进的速度（单位：千米每小时）。

当你通过第 i 条路之后，就必须休息并等待，直到 下一个整数小时 才能开始继续通过下一条道路。注意：你不需要在通过最后一条道路后休息，因为那时你已经抵达会议现场。

例如，如果你通过一条道路用去 1.4 小时，那你必须停下来等待，到 2 小时才可以继续通过下一条道路。如果通过一条道路恰好用去 2 小时，就无需等待，可以直接继续。
然而，为了能准时到达，你可以选择 跳过 一些路的休息时间，这意味着你不必等待下一个整数小时。注意，这意味着与不跳过任何休息时间相比，你可能在不同时刻到达接下来的道路。

例如，假设通过第 1 条道路用去 1.4 小时，且通过第 2 条道路用去 0.6 小时。跳过第 1 条道路的休息时间意味着你将会在恰好 2 小时完成通过第 2 条道路，且你能够立即开始通过第 3 条道路。
返回准时抵达会议现场所需要的 最小跳过次数 ，如果 无法准时参会 ，返回 -1 。

 

示例 1：

输入：dist = [1,3,2], speed = 4, hoursBefore = 2
输出：1
解释：
不跳过任何休息时间，你将用 (1/4 + 3/4) + (3/4 + 1/4) + (2/4) = 2.5 小时才能抵达会议现场。
可以跳过第 1 次休息时间，共用 ((1/4 + 0) + (3/4 + 0)) + (2/4) = 1.5 小时抵达会议现场。
注意，第 2 次休息时间缩短为 0 ，由于跳过第 1 次休息时间，你是在整数小时处完成通过第 2 条道路。
示例 2：

输入：dist = [7,3,5,5], speed = 2, hoursBefore = 10
输出：2
解释：
不跳过任何休息时间，你将用 (7/2 + 1/2) + (3/2 + 1/2) + (5/2 + 1/2) + (5/2) = 11.5 小时才能抵达会议现场。
可以跳过第 1 次和第 3 次休息时间，共用 ((7/2 + 0) + (3/2 + 0)) + ((5/2 + 0) + (5/2)) = 10 小时抵达会议现场。
示例 3：

输入：dist = [7,3,5,5], speed = 1, hoursBefore = 10
输出：-1
解释：即使跳过所有的休息时间，也无法准时参加会议。
 

提示：

n == dist.length
1 <= n <= 1000
1 <= dist[i] <= 105
1 <= speed <= 106
1 <= hoursBefore <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-skips-to-arrive-at-meeting-on-time
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int roads, skips, size = dist.size();
        double EPS = 1e-8;
        vector<vector<double>> dp(size + 1, vector<double>(size + 1, 1e20));
        dp[0][0] = 0;

        for (roads = 1; roads <= size; ++roads) {
            dp[roads][0] = min(dp[roads][0], ceil(dp[roads - 1][0] + (double)dist[roads - 1] / speed - EPS));  // skips==0时，只有不跳过的选项

            for (skips = 1; skips < roads; ++skips) {
                dp[roads][skips] = min(dp[roads][skips], ceil(dp[roads - 1][skips] + (double)dist[roads - 1] / speed - EPS));  // 选择不跳过
                dp[roads][skips] = min(dp[roads][skips], dp[roads - 1][skips - 1] + (double)dist[roads - 1] / speed); // 选择跳过
            }

            dp[roads][roads] = min(dp[roads][roads], dp[roads - 1][roads - 1] + (double)dist[roads - 1] / speed);  // skips==roads时，只有跳过的选项
        }

        for (skips = 0; skips <= size; ++skips) {
            if (dp[size][skips] < hoursBefore + EPS) {
                return skips;
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> dist = { 1,3,2 };
    check.checkInt(1, o.minSkips(dist, 4, 2));

    dist = { 7,3,5,5 };
    check.checkInt(2, o.minSkips(dist, 2, 10));

    dist = { 7,3,5,5 };
    check.checkInt(-1, o.minSkips(dist, 1, 10));

    dist = { 2,1,5,4,4,3,2,9,2,10 };
    check.checkInt(7, o.minSkips(dist, 6, 7));

    dist = { 10 };
    check.checkInt(0, o.minSkips(dist, 5, 2));

    dist = { 10 };
    check.checkInt(-1, o.minSkips(dist, 5, 1));
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
