﻿/* 运动员和训练师的最大匹配数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 players ，其中 players[i] 表示第 i 名运动员的 能力 值，同时给你一个下标从 0 开始的整数数组 trainers ，其中 trainers[j] 表示第 j 名训练师的 训练能力值 。

如果第 i 名运动员的能力值 小于等于 第 j 名训练师的能力值，那么第 i 名运动员可以 匹配 第 j 名训练师。除此以外，每名运动员至多可以匹配一位训练师，每位训练师最多可以匹配一位运动员。

请你返回满足上述要求 players 和 trainers 的 最大 匹配数。

 

示例 1：

输入：players = [4,7,9], trainers = [8,2,5,8]
输出：2
解释：
得到两个匹配的一种方案是：
- players[0] 与 trainers[0] 匹配，因为 4 <= 8 。
- players[1] 与 trainers[3] 匹配，因为 7 <= 8 。
可以证明 2 是可以形成的最大匹配数。
示例 2：

输入：players = [1,1,1], trainers = [10]
输出：1
解释：
训练师可以匹配所有 3 个运动员
每个运动员至多只能匹配一个训练师，所以最大答案是 1 。
 

提示：

1 <= players.length, trainers.length <= 105
1 <= players[i], trainers[j] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-matching-of-players-with-trainers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i, j = -1, size1 = players.size(), size2 = trainers.size(), count = 0;

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        for (i = 0; i < size1 && j < size2; ++i) {
            for (j += 1; j < size2 && trainers[j] < players[i]; ++j) {}
            if (j < size2) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> players = { 4,7,9 };
    vector<int> trainers = { 8,2,5,8 };
    check.checkInt(2, o.matchPlayersAndTrainers(players, trainers));

    players = { 1,1,1 };
    trainers = { 10 };
    check.checkInt(1, o.matchPlayersAndTrainers(players, trainers));
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
