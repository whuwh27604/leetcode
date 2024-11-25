/* 移除石头游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 和 Bob 在玩一个游戏，他们俩轮流从一堆石头中移除石头，Alice 先进行操作。

Alice 在第一次操作中移除 恰好 10 个石头。
接下来的每次操作中，每位玩家移除的石头数 恰好 为另一位玩家上一次操作的石头数减 1 。
第一位没法进行操作的玩家输掉这个游戏。

给你一个正整数 n 表示一开始石头的数目，如果 Alice 赢下这个游戏，请你返回 true ，否则返回 false 。



示例 1：

输入：n = 12

输出：true

解释：

Alice 第一次操作中移除 10 个石头，剩下 2 个石头给 Bob 。
Bob 无法移除 9 个石头，所以 Alice 赢下游戏。
示例 2：

输入：n = 1

输出：false

解释：

Alice 无法移除 10 个石头，所以 Alice 输掉游戏。


提示：

1 <= n <= 50
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        int stone = 10, who = 1;

        while (n >= stone) {
            n -= stone--;
            who ^= 1;
        }

        return who == 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.canAliceWin(12));
    check.checkBool(false, o.canAliceWin(1));
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
