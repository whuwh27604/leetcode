/* 破解锁的最少时间 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Bob 被困在了一个地窖里，他需要破解 n 个锁才能逃出地窖，每一个锁都需要一定的 能量 才能打开。每一个锁需要的能量存放在一个数组 strength 里，其中 strength[i] 表示打开第 i 个锁需要的能量。

Bob 有一把剑，它具备以下的特征：

一开始剑的能量为 0 。
剑的能量增加因子 X 一开始的值为 1 。
每分钟，剑的能量都会增加当前的 X 值。
打开第 i 把锁，剑的能量需要到达 至少 strength[i] 。
打开一把锁以后，剑的能量会变回 0 ，X 的值会增加一个给定的值 K 。
你的任务是打开所有 n 把锁并逃出地窖，请你求出需要的 最少 分钟数。

请你返回 Bob 打开所有 n 把锁需要的 最少 时间。



示例 1：

输入：strength = [3,4,1], K = 1

输出：4

解释：

时间	能量	X	操作	更新后的 X
0	0	1	什么也不做	1
1	1	1	打开第 3 把锁	2
2	2	2	什么也不做	2
3	4	2	打开第 2 把锁	3
4	3	3	打开第 1 把锁	3
无法用少于 4 分钟打开所有的锁，所以答案为 4 。

示例 2：

输入：strength = [2,5,4], K = 2

输出：5

解释：

时间	能量	X	操作	更新后的 X
0	0	1	什么也不做	1
1	1	1	什么也不做	1
2	2	1	打开第 1 把锁	3
3	3	3	什么也不做	3
4	6	3	打开第 2 把锁	5
5	5	5	打开第 3 把锁	7
无法用少于 5 分钟打开所有的锁，所以答案为 5 。



提示：

n == strength.length
1 <= n <= 8
1 <= K <= 10
1 <= strength[i] <= 106
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int n = (int)strength.size(), maxMask = (1 << n);
        vector<int> memo(maxMask, INT_MAX);

        return getMinTime(maxMask - 1, 1, n, K, strength, memo);
    }

    int getMinTime(int mask, int x, int n, int k, vector<int>& strength, vector<int>& memo) {
        if (mask == 0) {
            return 0;
        }

        if (memo[mask] != INT_MAX) {
            return memo[mask];
        }

        for (int i = 0, bit = 1; i < n; ++i, bit <<= 1) {
            if ((mask & bit) != 0) {
                memo[mask] = min(memo[mask], (strength[i] + x - 1) / x + getMinTime(mask ^ bit, x + k, n, k, strength, memo));
            }
        }

        return memo[mask];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> strength = { 3,4,1 };
    check.checkInt(4, o.findMinimumTime(strength, 1));

    strength = { 2,5,4 };
    check.checkInt(5, o.findMinimumTime(strength, 2));
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
