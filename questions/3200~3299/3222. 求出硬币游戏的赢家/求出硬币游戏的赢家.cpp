/* 求出硬币游戏的赢家.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 正 整数 x 和 y ，分别表示价值为 75 和 10 的硬币的数目。

Alice 和 Bob 正在玩一个游戏。每一轮中，Alice 先进行操作，Bob 后操作。每次操作中，玩家需要拿出价值 总和 为 115 的硬币。如果一名玩家无法执行此操作，那么这名玩家 输掉 游戏。

两名玩家都采取 最优 策略，请你返回游戏的赢家。



示例 1：

输入：x = 2, y = 7

输出："Alice"

解释：

游戏一次操作后结束：

Alice 拿走 1 枚价值为 75 的硬币和 4 枚价值为 10 的硬币。
示例 2：

输入：x = 4, y = 11

输出："Bob"

解释：

游戏 2 次操作后结束：

Alice 拿走 1 枚价值为 75 的硬币和 4 枚价值为 10 的硬币。
Bob 拿走 1 枚价值为 75 的硬币和 4 枚价值为 10 的硬币。


提示：

1 <= x, y <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string losingPlayer(int x, int y) {
        int n = min(x, y / 4);  // the only way to get 115 = 75 + 10 * 4

        return (n & 1) == 1 ? "Alice" : "Bob";
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("Alice", o.losingPlayer(2, 7));
    check.checkString("Bob", o.losingPlayer(4, 11));
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
