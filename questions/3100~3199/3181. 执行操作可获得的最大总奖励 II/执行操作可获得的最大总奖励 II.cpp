/* 执行操作可获得的最大总奖励 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 rewardValues，长度为 n，代表奖励的值。

最初，你的总奖励 x 为 0，所有下标都是 未标记 的。你可以执行以下操作 任意次 ：

从区间 [0, n - 1] 中选择一个 未标记 的下标 i。
如果 rewardValues[i] 大于 你当前的总奖励 x，则将 rewardValues[i] 加到 x 上（即 x = x + rewardValues[i]），并 标记 下标 i。
以整数形式返回执行最优操作能够获得的 最大 总奖励。



示例 1：

输入：rewardValues = [1,1,3,3]

输出：4

解释：

依次标记下标 0 和 2，总奖励为 4，这是可获得的最大值。

示例 2：

输入：rewardValues = [1,6,4,3,2]

输出：11

解释：

依次标记下标 0、2 和 1。总奖励为 11，这是可获得的最大值。



提示：

1 <= rewardValues.length <= 5 * 104
1 <= rewardValues[i] <= 5 * 104
*/

#include <iostream>
#include <algorithm>
#include <bitset>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());

        /* dp[i][x]表示rewardValues[0, i]是否可以构成x
           对于rewardValues[i] = v，如果不选它，那么dp[i][x] = dp[i - 1][x]
           如果选它，那么dp[i][x] = dp[i - 1][x - v]，前提条件是v <= x < 2v，因为前i-1个数构成x' >= v时，rewardValues[i]不能被取到
           dp[i][x]只和dp[i - 1][x']相关，可以滚动数组的思路优化掉第一维，并用bitset加速计算 */

        const int size = 100000;
        bitset<size> dp;
        dp[0] = 1;

        for (int v : rewardValues) {
            int shift = size - v;
            dp |= ((dp << shift) >> (shift - v));  // 将dp左移shift再右移shift，保留[0,v)位，再左移v位，最后或上原来的dp，这样用dp[0,v)刷新dp[v,2v)
        }

        int maxReward = 0;
        for (int x = rewardValues.back() * 2 - 1; x >= 0; --x) {  // 最大只能取到2v - 1，因为最后一个数最大只能是v，而前面的和要小于最后一个数
            if (dp.test(x)) {
                maxReward = x;
                break;
            }
        }

        return maxReward;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> rewardValues = { 1,1,3,3 };
    check.checkInt(4, o.maxTotalReward(rewardValues));

    rewardValues = { 1,6,4,3,2 };
    check.checkInt(11, o.maxTotalReward(rewardValues));
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
