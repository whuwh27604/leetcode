/* 得到目标值的最少行动次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你正在玩一个整数游戏。从整数 1 开始，期望得到整数 target 。

在一次行动中，你可以做下述两种操作之一：

递增，将当前整数的值加 1（即， x = x + 1）。
加倍，使当前整数的值翻倍（即，x = 2 * x）。
在整个游戏过程中，你可以使用 递增 操作 任意 次数。但是只能使用 加倍 操作 至多 maxDoubles 次。

给你两个整数 target 和 maxDoubles ，返回从 1 开始得到 target 需要的最少行动次数。

 

示例 1：

输入：target = 5, maxDoubles = 0
输出：4
解释：一直递增 1 直到得到 target 。
示例 2：

输入：target = 19, maxDoubles = 2
输出：7
解释：最初，x = 1 。
递增 3 次，x = 4 。
加倍 1 次，x = 8 。
递增 1 次，x = 9 。
加倍 1 次，x = 18 。
递增 1 次，x = 19 。
示例 3：

输入：target = 10, maxDoubles = 4
输出：4
解释：
最初，x = 1 。
递增 1 次，x = 2 。
加倍 1 次，x = 4 。
递增 1 次，x = 5 。
加倍 1 次，x = 10 。
 

提示：

1 <= target <= 109
0 <= maxDoubles <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-moves-to-reach-target-score
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int current = target, moves = 0;

        while (current != 1) {
            if ((current & 1) == 1) {
                current -= 1;
                ++moves;
            }
            else {
                if (maxDoubles > 0) {
                    current /= 2;
                    --maxDoubles;
                    ++moves;
                }
                else {
                    break;
                }
            }
        }

        return moves + current - 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.minMoves(5, 0));
    check.checkInt(7, o.minMoves(19, 2));
    check.checkInt(4, o.minMoves(10, 4));
    check.checkInt(0, o.minMoves(1, 0));
    check.checkInt(1, o.minMoves(2, 0));
    check.checkInt(2, o.minMoves(3, 0));
    check.checkInt(2, o.minMoves(3, 1));
    check.checkInt(3, o.minMoves(4, 0));
    check.checkInt(2, o.minMoves(4, 4));
    check.checkInt(999999999, o.minMoves(1000000000, 0));
    check.checkInt(31250004, o.minMoves(1000000000, 5));
    check.checkInt(41, o.minMoves(1000000000, 50));
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
