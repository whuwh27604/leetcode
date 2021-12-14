/* 最佳运动员的比拼回合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
n 名运动员参与一场锦标赛，所有运动员站成一排，并根据 最开始的 站位从 1 到 n 编号（运动员 1 是这一排中的第一个运动员，运动员 2 是第二个运动员，依此类推）。

锦标赛由多个回合组成（从回合 1 开始）。每一回合中，这一排从前往后数的第 i 名运动员需要与从后往前数的第 i 名运动员比拼，获胜者将会进入下一回合。如果当前回合中运动员数目为奇数，那么中间那位运动员将轮空晋级下一回合。

例如，当前回合中，运动员 1, 2, 4, 6, 7 站成一排
运动员 1 需要和运动员 7 比拼
运动员 2 需要和运动员 6 比拼
运动员 4 轮空晋级下一回合
每回合结束后，获胜者将会基于最开始分配给他们的原始顺序（升序）重新排成一排。

编号为 firstPlayer 和 secondPlayer 的运动员是本场锦标赛中的最佳运动员。在他们开始比拼之前，完全可以战胜任何其他运动员。而任意两个其他运动员进行比拼时，其中任意一个都有获胜的可能，因此你可以 裁定 谁是这一回合的获胜者。

给你三个整数 n、firstPlayer 和 secondPlayer 。返回一个由两个值组成的整数数组，分别表示两位最佳运动员在本场锦标赛中比拼的 最早 回合数和 最晚 回合数。

 

示例 1：

输入：n = 11, firstPlayer = 2, secondPlayer = 4
输出：[3,4]
解释：
一种能够产生最早回合数的情景是：
回合 1：1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
回合 2：2, 3, 4, 5, 6, 11
回合 3：2, 3, 4
一种能够产生最晚回合数的情景是：
回合 1：1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
回合 2：1, 2, 3, 4, 5, 6
回合 3：1, 2, 4
回合 4：2, 4
示例 2：

输入：n = 5, firstPlayer = 1, secondPlayer = 5
输出：[1,1]
解释：两名最佳运动员 1 和 5 将会在回合 1 进行比拼。
不存在使他们在其他回合进行比拼的可能。
 

提示：

2 <= n <= 28
1 <= firstPlayer < secondPlayer <= n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-earliest-and-latest-rounds-where-players-compete
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> roundLens;
        vector<vector<vector<int>>> earliest(n + 1, vector<vector<int>>(n, vector<int>(n, n + 1))), latest(n + 1, vector<vector<int>>(n, vector<int>(n, 0)));

        getRoundLens(n, roundLens);

        for (int roundLen : roundLens) {
            getEarliestAndLatest(roundLen, earliest, latest);
        }

        --firstPlayer, --secondPlayer;

        if (firstPlayer > secondPlayer) {
            swap(firstPlayer, secondPlayer);
        }

        if (firstPlayer >= n / 2 || n - secondPlayer <= firstPlayer) {  // 求对称位置
            int tmpFirst = n - 1 - firstPlayer, tmpSecond = n - 1 - secondPlayer;
            firstPlayer = tmpSecond, secondPlayer = tmpFirst;
        }

        getEarliestAndLatest(n, firstPlayer, secondPlayer, earliest, latest);

        return { earliest[n][firstPlayer][secondPlayer], latest[n][firstPlayer][secondPlayer] };
    }

    void getRoundLens(int n, vector<int>& roundLens) {
        while (n > 2) {
            n = (n + 1) / 2;
            roundLens.push_back(n);
        }

        reverse(roundLens.begin(), roundLens.end());
    }

    void getEarliestAndLatest(int roundLen, vector<vector<vector<int>>>& earliest, vector<vector<vector<int>>>& latest) {
        for (int firstPlayer = 0; firstPlayer < roundLen - 1; ++firstPlayer) {
            for (int secondPlayer = firstPlayer + 1; secondPlayer < roundLen; ++secondPlayer) {
                getEarliestAndLatest(roundLen, firstPlayer, secondPlayer, earliest, latest);
            }
        }
    }

    void getEarliestAndLatest(int roundLen, int firstPlayer, int secondPlayer, vector<vector<vector<int>>>& earliest, vector<vector<vector<int>>>& latest) {
        if (firstPlayer + secondPlayer == roundLen - 1) {  // 在对称位置上，第一轮必然相遇
            earliest[roundLen][firstPlayer][secondPlayer] = latest[roundLen][firstPlayer][secondPlayer] = 1;
            return;
        }

        // 两个数都在右侧，或者第二个数比第一个数更靠近端点，将两个数交换到对称位置
        if (firstPlayer >= roundLen / 2 || roundLen - secondPlayer <= firstPlayer) {
            int tmpFirst = roundLen - 1 - firstPlayer, tmpSecond = roundLen - 1 - secondPlayer;
            earliest[roundLen][firstPlayer][secondPlayer] = earliest[roundLen][tmpSecond][tmpFirst];
            latest[roundLen][firstPlayer][secondPlayer] = latest[roundLen][tmpSecond][tmpFirst];
            return;
        }

        // 下一轮，第一个数可以在区间[0, firstPlayer]任意位置
        int minNextFirst = 0, maxNextFirst = firstPlayer, minNextSecond = 0, maxNextSecond = 0, halfLen = (roundLen + 1) / 2;

        if (secondPlayer < (roundLen + 1) / 2) {  // 第二个数在左侧，则下一轮第二个数可以在第一个数后面[1, secondPlayer - firstPlayer]任意位置
            minNextSecond = 1, maxNextSecond = secondPlayer - firstPlayer;
        }
        else {  // 第二个数在右侧，那么区间[mirrorSecondPlayer, secondPlayer]必然剩下一半，而区间(firstPlayer, mirrorSecondPlayer)可以剩下任意个数
            minNextSecond = secondPlayer - (roundLen / 2 - 1), maxNextSecond = minNextSecond + roundLen - 1 - secondPlayer - firstPlayer - 1;
        }

        for (int nextFirst = minNextFirst; nextFirst <= maxNextFirst; ++nextFirst) {
            for (int nextSecond = minNextSecond; nextSecond <= maxNextSecond; ++nextSecond) {
                earliest[roundLen][firstPlayer][secondPlayer] = min(earliest[roundLen][firstPlayer][secondPlayer], earliest[halfLen][nextFirst][nextFirst + nextSecond] + 1);
                latest[roundLen][firstPlayer][secondPlayer] = max(latest[roundLen][firstPlayer][secondPlayer], latest[halfLen][nextFirst][nextFirst + nextSecond] + 1);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.earliestAndLatest(5, 1, 5);
    vector<int> expected = { 1,1 };
    check.checkIntVector(expected, actual);

    actual = o.earliestAndLatest(11, 2, 4);
    expected = { 3,4 };
    check.checkIntVector(expected, actual);

    actual = o.earliestAndLatest(28, 1, 27);
    expected = { 2,2 };
    check.checkIntVector(expected, actual);

    actual = o.earliestAndLatest(28, 5, 16);
    expected = { 2,5 };
    check.checkIntVector(expected, actual);

    actual = o.earliestAndLatest(3, 2, 3);
    expected = { 2,2 };
    check.checkIntVector(expected, actual);

    actual = o.earliestAndLatest(5, 1, 4);
    expected = { 2,2 };
    check.checkIntVector(expected, actual);
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
