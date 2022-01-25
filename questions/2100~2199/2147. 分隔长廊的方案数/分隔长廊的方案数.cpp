/* 分隔长廊的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个图书馆的长廊里，有一些座位和装饰植物排成一列。给你一个下标从 0 开始，长度为 n 的字符串 corridor ，它包含字母 'S' 和 'P' ，其中每个 'S' 表示一个座位，每个 'P' 表示一株植物。

在下标 0 的左边和下标 n - 1 的右边 已经 分别各放了一个屏风。你还需要额外放置一些屏风。每一个位置 i - 1 和 i 之间（1 <= i <= n - 1），至多能放一个屏风。

请你将走廊用屏风划分为若干段，且每一段内都 恰好有两个座位 ，而每一段内植物的数目没有要求。可能有多种划分方案，如果两个方案中有任何一个屏风的位置不同，那么它们被视为 不同 方案。

请你返回划分走廊的方案数。由于答案可能很大，请你返回它对 109 + 7 取余 的结果。如果没有任何方案，请返回 0 。

 

示例 1：



输入：corridor = "SSPPSPS"
输出：3
解释：总共有 3 种不同分隔走廊的方案。
上图中黑色的竖线表示已经放置好的屏风。
上图每种方案中，每一段都恰好有 两个 座位。
示例 2：



输入：corridor = "PPSPSP"
输出：1
解释：只有 1 种分隔走廊的方案，就是不放置任何屏风。
放置任何的屏风都会导致有一段无法恰好有 2 个座位。
示例 3：



输入：corridor = "S"
输出：0
解释：没有任何方案，因为总是有一段无法恰好有 2 个座位。
 

提示：

n == corridor.length
1 <= n <= 105
corridor[i] 要么是 'S' ，要么是 'P' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-divide-a-long-corridor
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        int i, size = corridor.size(), seat = 0, plant = 1;
        long long ways = 1;

        for (i = 0; i < size; ++i) {
            if (corridor[i] == 'S') {
                if (seat == 1) {
                    seat = 2;
                    plant = 1;
                }
                else if (seat == 2) {
                    seat = 1;
                    ways = (ways * plant) % 1000000007;
                }
                else {
                    seat = 1;
                }
            }
            else {
                if (seat == 2) {
                    ++plant;
                }
            }
        }

        return seat == 2 ? (int)ways : 0;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.numberOfWays("SSPPSPS"));
    check.checkInt(1, o.numberOfWays("PPSPSP"));
    check.checkInt(0, o.numberOfWays("S"));
    check.checkInt(0, o.numberOfWays("P"));
    check.checkInt(1, o.numberOfWays("SS"));
    check.checkInt(129140163, o.numberOfWays("SSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPS"));
    check.checkInt(0, o.numberOfWays("SSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSSSPPSPSS"));
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
