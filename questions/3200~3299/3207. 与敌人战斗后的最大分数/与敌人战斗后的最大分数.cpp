/* 与敌人战斗后的最大分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 enemyEnergies ，它表示一个下标从 0 开始的敌人能量数组。

同时给你一个整数 currentEnergy ，它表示你一开始拥有的能量值总量。

你一开始的分数为 0 ，且一开始所有的敌人都未标记。

你可以通过以下操作 之一 任意次（也可以 0 次）来得分：

选择一个 未标记 且满足 currentEnergy >= enemyEnergies[i] 的敌人 i 。在这个操作中：
你会获得 1 分。
你的能量值减少 enemyEnergies[i] ，也就是说 currentEnergy = currentEnergy - enemyEnergies[i] 。
如果你目前 至少 有 1 分，你可以选择一个 未标记 的敌人 i 。在这个操作中：
你的能量值增加 enemyEnergies[i] ，也就是说 currentEnergy = currentEnergy + enemyEnergies[i] 。
敌人 i 被标记 。
请你返回通过以上操作，最多 可以获得多少分。



示例 1：

输入：enemyEnergies = [3,2,2], currentEnergy = 2

输出：3

解释：

通过以下操作可以得到最大得分 3 分：

对敌人 1 使用第一种操作：points 增加 1 ，currentEnergy 减少 2 。所以 points = 1 且 currentEnergy = 0 。
对敌人 0 使用第二种操作：currentEnergy 增加 3 ，敌人 0 被标记。所以 points = 1 ，currentEnergy = 3 ，被标记的敌人包括 [0] 。
对敌人 2 使用第一种操作：points 增加 1 ，currentEnergy 减少 2 。所以 points = 2 且 currentEnergy = 1 ，被标记的敌人包括[0] 。
对敌人 2 使用第二种操作：currentEnergy 增加 2 ，敌人 2 被标记。所以 points = 2 ，currentEnergy = 3 且被标记的敌人包括 [0, 2] 。
对敌人 1 使用第一种操作：points 增加 1 ，currentEnergy 减少 2 。所以 points = 3 ，currentEnergy = 1 ，被标记的敌人包括 [0, 2] 。
示例 2：

输入：enemyEnergies = [2], currentEnergy = 10

输出：5

解释：

通过对敌人 0 进行第一种操作 5 次，得到最大得分。



提示：

1 <= enemyEnergies.length <= 105
1 <= enemyEnergies[i] <= 109
0 <= currentEnergy <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int minEnergy = INT_MAX;
        long long sum = currentEnergy;

        for (int energy : enemyEnergies) {
            sum += energy;
            if (energy < minEnergy) {
                minEnergy = energy;
            }
        }

        return currentEnergy < minEnergy ? 0 : (sum - minEnergy) / minEnergy;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> enemyEnergies = { 3,2,2 };
    check.checkLongLong(3, o.maximumPoints(enemyEnergies, 2));

    enemyEnergies = { 2 };
    check.checkLongLong(5, o.maximumPoints(enemyEnergies, 10));

    enemyEnergies = { 2,3,4 };
    check.checkLongLong(0, o.maximumPoints(enemyEnergies, 1));
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
