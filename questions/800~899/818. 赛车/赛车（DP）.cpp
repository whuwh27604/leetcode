/* 赛车.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你的赛车起始停留在位置 0，速度为 +1，正行驶在一个无限长的数轴上。（车也可以向负数方向行驶。）

你的车会根据一系列由 A（加速）和 R（倒车）组成的指令进行自动驾驶 。

当车得到指令 "A" 时, 将会做出以下操作： position += speed, speed *= 2。

当车得到指令 "R" 时, 将会做出以下操作：如果当前速度是正数，则将车速调整为 speed = -1 ；否则将车速调整为 speed = 1。  (当前所处位置不变。)

例如，当得到一系列指令 "AAR" 后, 你的车将会走过位置 0->1->3->3，并且速度变化为 1->2->4->-1。

现在给定一个目标位置，请给出能够到达目标位置的最短指令列表的长度。

示例 1:
输入:
target = 3
输出: 2
解释:
最短指令列表为 "AA"
位置变化为 0->1->3
示例 2:
输入:
target = 6
输出: 5
解释:
最短指令列表为 "AAARA"
位置变化为 0->1->3->7->7->6
说明:

1 <= target（目标位置） <= 10000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/race-car
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 3, INT_MAX);
        dp[0] = 0, dp[1] = 1, dp[2] = 4;

        for (int t = 3; t <= target; ++t) {
            int k = getFirstGreaterOne(t);

            if (t == ((1 << k) - 1)) {  // 全力加速可达的位置
                dp[t] = k;
                continue;
            }

            for (int j = 0; j < k - 1; ++j) {
                dp[t] = min(dp[t], dp[t - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2);  // 尝试所有的可能的折返位置
            }

            if ((1 << k) - 1 - t < t) {  // 已越过t再折返的位置
                dp[t] = min(dp[t], dp[(1 << k) - 1 - t] + k + 1);
            }
        }

        return dp[target];
    }

    int getFirstGreaterOne(int target) {
        int bit = 1, num = 0;

        while (bit <= target) {
            bit <<= 1;
            ++num;
        }

        return num;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.racecar(1));
    check.checkInt(4, o.racecar(2));
    check.checkInt(2, o.racecar(3));
    check.checkInt(5, o.racecar(4));
    check.checkInt(7, o.racecar(5));
    check.checkInt(5, o.racecar(6));
    check.checkInt(3, o.racecar(7));
    check.checkInt(6, o.racecar(8));
    check.checkInt(8, o.racecar(9));
    check.checkInt(7, o.racecar(10));
    check.checkInt(16, o.racecar(99));
    check.checkInt(19, o.racecar(100));
    check.checkInt(20, o.racecar(999));
    check.checkInt(23, o.racecar(1000));
    check.checkInt(43, o.racecar(9999));
    check.checkInt(45, o.racecar(10000));
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
