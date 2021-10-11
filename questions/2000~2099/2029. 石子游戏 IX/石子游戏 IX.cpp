/* 石子游戏 IX.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 和 Bob 再次设计了一款新的石子游戏。现有一行 n 个石子，每个石子都有一个关联的数字表示它的价值。给你一个整数数组 stones ，其中 stones[i] 是第 i 个石子的价值。

Alice 和 Bob 轮流进行自己的回合，Alice 先手。每一回合，玩家需要从 stones 中移除任一石子。

如果玩家移除石子后，导致 所有已移除石子 的价值 总和 可以被 3 整除，那么该玩家就 输掉游戏 。
如果不满足上一条，且移除后没有任何剩余的石子，那么 Bob 将会直接获胜（即便是在 Alice 的回合）。
假设两位玩家均采用 最佳 决策。如果 Alice 获胜，返回 true ；如果 Bob 获胜，返回 false 。

 

示例 1：

输入：stones = [2,1]
输出：true
解释：游戏进行如下：
- 回合 1：Alice 可以移除任意一个石子。
- 回合 2：Bob 移除剩下的石子。
已移除的石子的值总和为 1 + 2 = 3 且可以被 3 整除。因此，Bob 输，Alice 获胜。
示例 2：

输入：stones = [2]
输出：false
解释：Alice 会移除唯一一个石子，已移除石子的值总和为 2 。
由于所有石子都已移除，且值总和无法被 3 整除，Bob 获胜。
示例 3：

输入：stones = [5,1,2,4,3]
输出：false
解释：Bob 总会获胜。其中一种可能的游戏进行方式如下：
- 回合 1：Alice 可以移除值为 1 的第 2 个石子。已移除石子值总和为 1 。
- 回合 2：Bob 可以移除值为 3 的第 5 个石子。已移除石子值总和为 = 1 + 3 = 4 。
- 回合 3：Alices 可以移除值为 4 的第 4 个石子。已移除石子值总和为 = 1 + 3 + 4 = 8 。
- 回合 4：Bob 可以移除值为 2 的第 3 个石子。已移除石子值总和为 = 1 + 3 + 4 + 2 = 10.
- 回合 5：Alice 可以移除值为 5 的第 1 个石子。已移除石子值总和为 = 1 + 3 + 4 + 2 + 5 = 15.
Alice 输掉游戏，因为已移除石子值总和（15）可以被 3 整除，Bob 获胜。
 

提示：

1 <= stones.length <= 105
1 <= stones[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stone-game-ix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        /* 1、显然0可以用来转换先后手，如果A发现先手要输，那么可以选0变为后手；B肯定选0让A再变为先手。所以偶数个0没有意义，奇数个0有一次转变先后手的机会。
           2、第一个必然选1或者2。如果是1，则只能是11212121...如果A发现没有2可以选，则输掉了。如果有一个0，则可以让B输掉。
           3、如果先选2，则只能是22121212...如果A发现没有1可以选，则输掉了。如果有一个0，则可以让B输掉。
           4、综上，可以推导出，c0是偶数，c1和c2都大于0，则A必胜；c1是奇数，c1 - c2 > 2 或者c2 - c1 > 2则A必胜 */
        vector<int> count(3, 0);

        for (int stone : stones) {
            ++count[stone % 3];
        }

        return ((count[0] & 1) == 0) ? (count[1] > 0 && count[2] > 0) : (count[1] - count[2] > 2 || count[2] - count[1] > 2);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> stones = { 2,1 };
    check.checkBool(true, o.stoneGameIX(stones));

    stones = { 2 };
    check.checkBool(false, o.stoneGameIX(stones));

    stones = { 5,1,2,4,3 };
    check.checkBool(false, o.stoneGameIX(stones));

    stones = { 15,20,10,13,14,15,5,2,3 };
    check.checkBool(false, o.stoneGameIX(stones));

    stones = { 19,2,17,20,7,17 };
    check.checkBool(true, o.stoneGameIX(stones));
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
