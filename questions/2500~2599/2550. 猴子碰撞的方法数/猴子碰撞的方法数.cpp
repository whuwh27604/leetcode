/* 猴子碰撞的方法数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现在有一个正凸多边形，其上共有 n 个顶点。顶点按顺时针方向从 0 到 n - 1 依次编号。每个顶点上 正好有一只猴子 。下图中是一个 6 个顶点的凸多边形。



每个猴子同时移动到相邻的顶点。顶点 i 的相邻顶点可以是：

顺时针方向的顶点 (i + 1) % n ，或
逆时针方向的顶点 (i - 1 + n) % n 。
如果移动后至少有两个猴子位于同一顶点，则会发生 碰撞 。

返回猴子至少发生 一次碰撞 的移动方法数。由于答案可能非常大，请返回对 109+7 取余后的结果。

注意，每只猴子只能移动一次。



示例 1：

输入：n = 3
输出：6
解释：共计 8 种移动方式。
下面列出两种会发生碰撞的方式：
- 猴子 1 顺时针移动；猴子 2 逆时针移动；猴子 3 顺时针移动。猴子 1 和猴子 2 碰撞。
- 猴子 1 逆时针移动；猴子 2 逆时针移动；猴子 3 顺时针移动。猴子 1 和猴子 3 碰撞。
可以证明，有 6 种让猴子碰撞的方法。
示例 2：

输入：n = 4
输出：14
解释：可以证明，有 14 种让猴子碰撞的方法。


提示：

3 <= n <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int monkeyMove(int n) {
        int mod = 1000000007;

        return (fastPower(2, n, mod) + mod - 2) % mod;
    }

    int fastPower(int x, int n, int mod) {
        long long ans = 1;

        while (n != 0) {
            if ((n & 1) == 1) {
                ans = ans * x % mod;
            }

            x = (long long)x * x % mod;
            n >>= 1;
        }

        return (int)ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(6, o.monkeyMove(3));
    check.checkInt(14, o.monkeyMove(4));
    check.checkInt(1000000006, o.monkeyMove(500000003));
    check.checkInt(570312502, o.monkeyMove(999999999));
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
