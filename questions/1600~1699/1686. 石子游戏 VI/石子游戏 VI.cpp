/* 石子游戏 VI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 和 Bob 轮流玩一个游戏，Alice 先手。

一堆石子里总共有 n 个石子，轮到某个玩家时，他可以 移出 一个石子并得到这个石子的价值。Alice 和 Bob 对石子价值有 不一样的的评判标准 。双方都知道对方的评判标准。

给你两个长度为 n 的整数数组 aliceValues 和 bobValues 。aliceValues[i] 和 bobValues[i] 分别表示 Alice 和 Bob 认为第 i 个石子的价值。

所有石子都被取完后，得分较高的人为胜者。如果两个玩家得分相同，那么为平局。两位玩家都会采用 最优策略 进行游戏。

请你推断游戏的结果，用如下的方式表示：

如果 Alice 赢，返回 1 。
如果 Bob 赢，返回 -1 。
如果游戏平局，返回 0 。
 

示例 1：

输入：aliceValues = [1,3], bobValues = [2,1]
输出：1
解释：
如果 Alice 拿石子 1 （下标从 0开始），那么 Alice 可以得到 3 分。
Bob 只能选择石子 0 ，得到 2 分。
Alice 获胜。
示例 2：

输入：aliceValues = [1,2], bobValues = [3,1]
输出：0
解释：
Alice 拿石子 0 ， Bob 拿石子 1 ，他们得分都为 1 分。
打平。
示例 3：

输入：aliceValues = [2,4,3], bobValues = [1,6,7]
输出：-1
解释：
不管 Alice 怎么操作，Bob 都可以得到比 Alice 更高的得分。
比方说，Alice 拿石子 1 ，Bob 拿石子 2 ， Alice 拿石子 0 ，Alice 会得到 6 分而 Bob 得分为 7 分。
Bob 会获胜。
 

提示：

n == aliceValues.length == bobValues.length
1 <= n <= 105
1 <= aliceValues[i], bobValues[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stone-game-vi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        // 合并两组价值后，每次取最大的
        int i, size = bobValues.size(), sumAlice = 0, sumBob = 0;
        vector<pair<int, int>> sums(size);

        for (i = 0; i < size; ++i) {
            sums[i] = { aliceValues[i] + bobValues[i], i };
        }

        sort(sums.begin(), sums.end());

        for (i = size - 1; i >= 0; i -= 2) {
            sumAlice += aliceValues[sums[i].second];
        }

        for (i = size - 2; i >= 0; i -= 2) {
            sumBob += bobValues[sums[i].second];
        }

        return sumAlice > sumBob ? 1 : (sumAlice == sumBob ? 0 : -1);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> aliceValues = { 1,3 };
    vector<int> bobValues = { 2,1 };
    check.checkInt(1, o.stoneGameVI(aliceValues, bobValues));

    aliceValues = { 1,2 };
    bobValues = { 3,1 };
    check.checkInt(0, o.stoneGameVI(aliceValues, bobValues));

    aliceValues = { 2,4,3 };
    bobValues = { 1,6,7 };
    check.checkInt(-1, o.stoneGameVI(aliceValues, bobValues));

    aliceValues = { 1 };
    bobValues = { 3 };
    check.checkInt(1, o.stoneGameVI(aliceValues, bobValues));

    aliceValues = { 2,9,1,1,1,3,5,8,8,6,8,6,2,4 };
    bobValues = { 1,9,7,8,3,4,2,7,8,10,1,7,10,4 };
    check.checkInt(-1, o.stoneGameVI(aliceValues, bobValues));
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
