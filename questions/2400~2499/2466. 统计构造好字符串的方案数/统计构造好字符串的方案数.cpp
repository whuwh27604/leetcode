/* 统计构造好字符串的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你整数 zero ，one ，low 和 high ，我们从空字符串开始构造一个字符串，每一步执行下面操作中的一种：

将 '0' 在字符串末尾添加 zero  次。
将 '1' 在字符串末尾添加 one 次。
以上操作可以执行任意次。

如果通过以上过程得到一个 长度 在 low 和 high 之间（包含上下边界）的字符串，那么这个字符串我们称为 好 字符串。

请你返回满足以上要求的 不同 好字符串数目。由于答案可能很大，请将结果对 109 + 7 取余 后返回。



示例 1：

输入：low = 3, high = 3, zero = 1, one = 1
输出：8
解释：
一个可能的好字符串是 "011" 。
可以这样构造得到："" -> "0" -> "01" -> "011" 。
从 "000" 到 "111" 之间所有的二进制字符串都是好字符串。
示例 2：

输入：low = 2, high = 3, zero = 1, one = 2
输出：5
解释：好字符串为 "00" ，"11" ，"000" ，"110" 和 "011" 。


提示：

1 <= low <= high <= 105
1 <= zero, one <= low
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int goods = 0, mod = 1000000007;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= high; ++i) {
            if (i >= zero) {
                dp[i] = dp[i - zero];
            }

            if (i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % mod;
            }

            if (i >= low) {
                goods = (goods + dp[i]) % mod;
            }
        }

        return goods;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(8, o.countGoodStrings(3, 3, 1, 1));
    check.checkInt(5, o.countGoodStrings(2, 3, 1, 2));
    check.checkInt(2, o.countGoodStrings(56, 56, 56, 2));
    check.checkInt(764262396, o.countGoodStrings(200, 200, 10, 1));
    check.checkInt(665935775, o.countGoodStrings(100000, 100000, 2, 8));
    check.checkInt(215447031, o.countGoodStrings(1, 100000, 1, 1));
    check.checkInt(89, o.countGoodStrings(40, 40, 4, 8));
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
