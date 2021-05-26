/* 石子游戏 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 和 Bob 用几堆石子在做游戏。几堆石子排成一行，每堆石子都对应一个得分，由数组 stoneValue 给出。

Alice 和 Bob 轮流取石子，Alice 总是先开始。在每个玩家的回合中，该玩家可以拿走剩下石子中的的前 1、2 或 3 堆石子 。比赛一直持续到所有石头都被拿走。

每个玩家的最终得分为他所拿到的每堆石子的对应得分之和。每个玩家的初始分数都是 0 。比赛的目标是决出最高分，得分最高的选手将会赢得比赛，比赛也可能会出现平局。

假设 Alice 和 Bob 都采取 最优策略 。如果 Alice 赢了就返回 "Alice" ，Bob 赢了就返回 "Bob"，平局（分数相同）返回 "Tie" 。

 

示例 1：

输入：values = [1,2,3,7]
输出："Bob"
解释：Alice 总是会输，她的最佳选择是拿走前三堆，得分变成 6 。但是 Bob 的得分为 7，Bob 获胜。
示例 2：

输入：values = [1,2,3,-9]
输出："Alice"
解释：Alice 要想获胜就必须在第一个回合拿走前三堆石子，给 Bob 留下负分。
如果 Alice 只拿走第一堆，那么她的得分为 1，接下来 Bob 拿走第二、三堆，得分为 5 。之后 Alice 只能拿到分数 -9 的石子堆，输掉比赛。
如果 Alice 拿走前两堆，那么她的得分为 3，接下来 Bob 拿走第三堆，得分为 3 。之后 Alice 只能拿到分数 -9 的石子堆，同样会输掉比赛。
注意，他们都应该采取 最优策略 ，所以在这里 Alice 将选择能够使她获胜的方案。
示例 3：

输入：values = [1,2,3,6]
输出："Tie"
解释：Alice 无法赢得比赛。如果她决定选择前三堆，她可以以平局结束比赛，否则她就会输。
示例 4：

输入：values = [1,2,3,-1,-2,-3,7]
输出："Alice"
示例 5：

输入：values = [-1,-2,-3]
输出："Tie"
 

提示：

1 <= values.length <= 50000
-1000 <= values[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stone-game-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int i, size = stoneValue.size();
        vector<int> dp(size + 3, 0);  // dp[i]表示面对stone[i,size)时先手能够赢的分数
        stoneValue.insert(stoneValue.end(), 3, 0);

        for (i = size - 1; i >= 0; --i) {
            dp[i] = max({ stoneValue[i] - dp[i + 1], stoneValue[i] + stoneValue[i + 1] - dp[i + 2],
                stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3] });
        }

        return dp[0] == 0 ? "Tie" : dp[0] > 0 ? "Alice" : "Bob";
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> stoneValue = { 1,2,3,7 };
    check.checkString("Bob", o.stoneGameIII(stoneValue));

    stoneValue = { 1,2,3,-9 };
    check.checkString("Alice", o.stoneGameIII(stoneValue));

    stoneValue = { 1,2,3,6 };
    check.checkString("Tie", o.stoneGameIII(stoneValue));

    stoneValue = { 1,2,3,-1,-2,-3,7 };
    check.checkString("Alice", o.stoneGameIII(stoneValue));

    stoneValue = { -1,-2,-3 };
    check.checkString("Tie", o.stoneGameIII(stoneValue));

    stoneValue = { 1,2,3,4,5,6,7,8,9,0,-9,-8,-7,-6,-5,-4,-3,-2,-1 };
    check.checkString("Tie", o.stoneGameIII(stoneValue));

    stoneValue = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
    check.checkString("Alice", o.stoneGameIII(stoneValue));
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
