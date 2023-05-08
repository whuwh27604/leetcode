/* 保龄球游戏的获胜者.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的整数数组 player1 和 player2 ，分别表示玩家 1 和玩家 2 击中的瓶数。

保龄球比赛由 n 轮组成，每轮的瓶数恰好为 10 。

假设玩家在第 i 轮中击中 xi 个瓶子。玩家第 i 轮的价值为：

如果玩家在该轮的前两轮的任何一轮中击中了 10 个瓶子，则为 2xi 。
否则，为 xi 。
玩家的得分是其 n 轮价值的总和。

返回

如果玩家 1 的得分高于玩家 2 的得分，则为 1 ；
如果玩家 2 的得分高于玩家 1 的得分，则为 2 ；
如果平局，则为 0 。


示例 1：

输入：player1 = [4,10,7,9], player2 = [6,5,2,3]
输出：1
解释：player1 的得分是 4 + 10 + 2*7 + 2*9 = 46 。
player2 的得分是 6 + 5 + 2 + 3 = 16 。
player1 的得分高于 player2 的得分，所以 play1 在比赛中获胜，答案为 1 。
示例 2：

输入：player1 = [3,5,7,6], player2 = [8,10,10,2]
输出：2
解释：player1 的得分是 3 + 5 + 7 + 6 = 21 。
player2 的得分是 8 + 10 + 2*10 + 2*2 = 42 。
player2 的得分高于 player1 的得分，所以 play2 在比赛中获胜，答案为 2 。
示例 3：

输入：player1 = [2,3], player2 = [4,1]
输出：0
解释：player1 的得分是 2 + 3 = 5 。
player2 的得分是 4 + 1 = 5 。
player1 的得分等于 player2 的得分，所以这一场比赛平局，答案为 0 。


提示：

n == player1.length == player2.length
1 <= n <= 1000
0 <= player1[i], player2[i] <= 10
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int size = player1.size(), score1 = player1[0], score2 = player2[0];

        if (size > 1) {
            score1 += (player1[0] == 10 ? player1[1] * 2 : player1[1]);
            score2 += (player2[0] == 10 ? player2[1] * 2 : player2[1]);
        }

        for (int i = 2; i < size; ++i) {
            score1 += ((player1[i - 1] == 10 || player1[i - 2] == 10) ? player1[i] * 2 : player1[i]);
            score2 += ((player2[i - 1] == 10 || player2[i - 2] == 10) ? player2[i] * 2 : player2[i]);
        }

        return score1 == score2 ? 0 : (score1 > score2 ? 1 : 2);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> player1 = { 4,10,7,9 };
    vector<int> player2 = { 6,5,2,3 };
    check.checkInt(1, o.isWinner(player1, player2));

    player1 = { 3,5,7,6 };
    player2 = { 8,10,10,2 };
    check.checkInt(2, o.isWinner(player1, player2));

    player1 = { 2,3 };
    player2 = { 4,1 };
    check.checkInt(0, o.isWinner(player1, player2));

    player1 = { 5,6,1,10 };
    player2 = { 5,1,10,5 };
    check.checkInt(2, o.isWinner(player1, player2));
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
