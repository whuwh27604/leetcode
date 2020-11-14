/* 我能赢吗.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和达到 100 的玩家，即为胜者。

如果我们将游戏规则改为 “玩家不能重复使用整数” 呢？

例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。

给定一个整数 maxChoosableInteger （整数池中可选择的最大数）和另一个整数 desiredTotal（累计和），判断先出手的玩家是否能稳赢（假设两位玩家游戏时都表现最佳）？

你可以假设 maxChoosableInteger 不会大于 20， desiredTotal 不会大于 300。

示例：

输入：
maxChoosableInteger = 10
desiredTotal = 11

输出：
false

解释：
无论第一个玩家选择哪个整数，他都会失败。
第一个玩家可以选择从 1 到 10 的整数。
如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/can-i-win
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }

        int choosableNums = 0, mask = 1;
        for (int i = 0; i < maxChoosableInteger; ++i) {
            choosableNums |= mask;
            mask <<= 1;
        }

        char* memo = new char[2 << maxChoosableInteger];
        for (int i = 0; i < (2 << maxChoosableInteger); ++i) {
            memo[i] = -1;
        }

        bool canWin = canIWin(maxChoosableInteger, choosableNums, desiredTotal, memo);
        delete[] memo;

        return canWin;
    }

    bool canIWin(int maxChoosableInteger, int choosableNums, int desiredTotal, char* memo) {
        if (memo[choosableNums] != -1) {
            return (bool)memo[choosableNums];
        }

        int mask = (1 << (maxChoosableInteger - 1));
        bool canWin = false;

        for (int num = maxChoosableInteger; num > 0; --num, mask >>= 1) {
            if ((choosableNums & mask) == 0) {
                continue;
            }

            /* 1、如果当前可选的数大于等于desiredTotal，说明我赢了
               2、如果我选了num，对方怎么也赢不了，说明我能赢，因为唯一一种两边都赢不了的场景一开始就排除了 */
            if ((num >= desiredTotal) || (!canIWin(maxChoosableInteger, choosableNums & ~mask, desiredTotal - num, memo))) {
                canWin = true;
                break;
            }
        }

        memo[choosableNums] = canWin;
        return canWin;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(false, o.canIWin(10, 11));
    check.checkBool(false, o.canIWin(10, 40));
    check.checkBool(false, o.canIWin(5, 16));
    check.checkBool(true, o.canIWin(5, 15));
    check.checkBool(false, o.canIWin(6, 21));
    check.checkBool(true, o.canIWin(5, 12));
    check.checkBool(true, o.canIWin(10, 0));
    check.checkBool(false, o.canIWin(20, 209));
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
