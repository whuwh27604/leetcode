/* 设置时间的最少代价.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
常见的微波炉可以设置加热时间，且加热时间满足以下条件：

至少为 1 秒钟。
至多为 99 分 99 秒。
你可以 最多 输入 4 个数字 来设置加热时间。如果你输入的位数不足 4 位，微波炉会自动加 前缀 0 来补足 4 位。微波炉会将设置好的四位数中，前 两位当作分钟数，后 两位当作秒数。它们所表示的总时间就是加热时间。比方说：

你输入 9 5 4 （三个数字），被自动补足为 0954 ，并表示 9 分 54 秒。
你输入 0 0 0 8 （四个数字），表示 0 分 8 秒。
你输入 8 0 9 0 ，表示 80 分 90 秒。
你输入 8 1 3 0 ，表示 81 分 30 秒。
给你整数 startAt ，moveCost ，pushCost 和 targetSeconds 。一开始，你的手指在数字 startAt 处。将手指移到 任何其他数字 ，需要花费 moveCost 的单位代价。每 输入你手指所在位置的数字一次，需要花费 pushCost 的单位代价。

要设置 targetSeconds 秒的加热时间，可能会有多种设置方法。你想要知道这些方法中，总代价最小为多少。

请你能返回设置 targetSeconds 秒钟加热时间需要花费的最少代价。

请记住，虽然微波炉的秒数最多可以设置到 99 秒，但一分钟等于 60 秒。

 

示例 1：



输入：startAt = 1, moveCost = 2, pushCost = 1, targetSeconds = 600
输出：6
解释：以下为设置加热时间的所有方法。
- 1 0 0 0 ，表示 10 分 0 秒。
  手指一开始就在数字 1 处，输入 1 （代价为 1），移到 0 处（代价为 2），输入 0（代价为 1），输入 0（代价为 1），输入 0（代价为 1）。
  总代价为：1 + 2 + 1 + 1 + 1 = 6 。这是所有方案中的最小代价。
- 0 9 6 0，表示 9 分 60 秒。它也表示 600 秒。
  手指移到 0 处（代价为 2），输入 0 （代价为 1），移到 9 处（代价为 2），输入 9（代价为 1），移到 6 处（代价为 2），输入 6（代价为 1），移到 0 处（代价为 2），输入 0（代价为 1）。
  总代价为：2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 = 12 。
- 9 6 0，微波炉自动补全为 0960 ，表示 9 分 60 秒。
  手指移到 9 处（代价为 2），输入 9 （代价为 1），移到 6 处（代价为 2），输入 6（代价为 1），移到 0 处（代价为 2），输入 0（代价为 1）。
  总代价为：2 + 1 + 2 + 1 + 2 + 1 = 9 。
示例 2：



输入：startAt = 0, moveCost = 1, pushCost = 2, targetSeconds = 76
输出：6
解释：最优方案为输入两个数字 7 6，表示 76 秒。
手指移到 7 处（代价为 1），输入 7 （代价为 2），移到 6 处（代价为 1），输入 6（代价为 2）。总代价为：1 + 2 + 1 + 2 = 6
其他可行方案为 0076 ，076 ，0116 和 116 ，但是它们的代价都比 6 大。
 

提示：

0 <= startAt <= 9
1 <= moveCost, pushCost <= 105
1 <= targetSeconds <= 6039

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-to-set-cooking-time
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int targetMinutes = targetSeconds / 60;
        targetSeconds %= 60;

        return min(getCost(startAt, moveCost, pushCost, targetMinutes, targetSeconds),
            getCost(startAt, moveCost, pushCost, targetMinutes - 1, targetSeconds + 60));
    }

    int getCost(int startAt, int moveCost, int pushCost, int targetMinutes, int targetSeconds) {
        if (targetMinutes < 0 || targetMinutes > 99 || targetSeconds > 99) {
            return INT_MAX;
        }

        int cost = 0, current = startAt;
        int minute1 = targetMinutes / 10, minute2 = targetMinutes % 10;
        int second1 = targetSeconds / 10, second2 = targetSeconds % 10;

        if (minute1 != 0) {
            cost += (current == minute1 ? 0 : moveCost);
            cost += pushCost;
            current = minute1;
        }

        if (minute1 != 0 || minute2 != 0) {
            cost += (current == minute2 ? 0 : moveCost);
            cost += pushCost;
            current = minute2;
        }

        if (minute1 != 0 || minute2 != 0 || second1 != 0) {
            cost += (current == second1 ? 0 : moveCost);
            cost += pushCost;
            current = second1;
        }

        cost += (current == second2 ? 0 : moveCost);
        cost += pushCost;

        return cost;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(6, o.minCostSetTime(1, 2, 1, 600));
    check.checkInt(6, o.minCostSetTime(0, 1, 2, 76));
    check.checkInt(2576, o.minCostSetTime(7, 220, 479, 6000));
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
