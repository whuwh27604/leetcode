/* 求和游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 和 Bob 玩一个游戏，两人轮流行动，Alice 先手 。

给你一个 偶数长度 的字符串 num ，每一个字符为数字字符或者 '?' 。每一次操作中，如果 num 中至少有一个 '?' ，那么玩家可以执行以下操作：

选择一个下标 i 满足 num[i] == '?' 。
将 num[i] 用 '0' 到 '9' 之间的一个数字字符替代。
当 num 中没有 '?' 时，游戏结束。

Bob 获胜的条件是 num 中前一半数字的和 等于 后一半数字的和。Alice 获胜的条件是前一半的和与后一半的和 不相等 。

比方说，游戏结束时 num = "243801" ，那么 Bob 获胜，因为 2+4+3 = 8+0+1 。如果游戏结束时 num = "243803" ，那么 Alice 获胜，因为 2+4+3 != 8+0+3 。
在 Alice 和 Bob 都采取 最优 策略的前提下，如果 Alice 获胜，请返回 true ，如果 Bob 获胜，请返回 false 。

 

示例 1：

输入：num = "5023"
输出：false
解释：num 中没有 '?' ，没法进行任何操作。
前一半的和等于后一半的和：5 + 0 = 2 + 3 。
示例 2：

输入：num = "25??"
输出：true
解释：Alice 可以将两个 '?' 中的一个替换为 '9' ，Bob 无论如何都无法使前一半的和等于后一半的和。
示例 3：

输入：num = "?3295???"
输出：false
解释：Bob 总是能赢。一种可能的结果是：
- Alice 将第一个 '?' 用 '9' 替换。num = "93295???" 。
- Bob 将后面一半中的一个 '?' 替换为 '9' 。num = "932959??" 。
- Alice 将后面一半中的一个 '?' 替换为 '2' 。num = "9329592?" 。
- Bob 将后面一半中最后一个 '?' 替换为 '7' 。num = "93295927" 。
Bob 获胜，因为 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7 。
 

提示：

2 <= num.length <= 105
num.length 是 偶数 。
num 只包含数字字符和 '?' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        /* 如果？是奇数个，那么alice必胜，因为她最后一个？总可以选一个数让两边不等。
           2、如果？是偶数个，alice全力在左边放9，右边放0；bob全力在右边放9，左边放0。假设alice放了n个9在左边，那么：
           sum1 + n * 9 ! + (count1 - n) * 0 != ((count1 + count2) / 2 - n) * 0 + sum2 + (count2 - ((count1 + count2) / 2 - n)) * 9
           即：sum1 - sum2 != (count2 - count1) * 9 / 2 */
        int i, size = num.size(), sum1 = 0, count1 = 0, sum2 = 0, count2 = 0;

        for (i = 0; i < size / 2; ++i) {
            if (num[i] == '?') {
                ++count1;
            }
            else {
                sum1 += (num[i] - '0');
            }
        }

        for (; i < size; ++i) {
            if (num[i] == '?') {
                ++count2;
            }
            else {
                sum2 += (num[i] - '0');
            }
        }

        return ((count1 + count2) % 2 == 1) || (2 * (sum1 - sum2) != 9 * (count2 - count1));
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(false, o.sumGame("5023"));
    check.checkBool(true, o.sumGame("25??"));
    check.checkBool(false, o.sumGame("?3295???"));
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
