/* 最小可整除数位乘积 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 n 和 t 。请你返回大于等于 n 的 最小 整数，且该整数的 各数位之积 能被 t 整除。



示例 1：

输入：n = 10, t = 2

输出：10

解释：

10 的数位乘积为 0 ，可以被 2 整除，所以它是大于等于 10 且满足题目要求的最小整数。

示例 2：

输入：n = 15, t = 3

输出：16

解释：

16 的数位乘积为 6 ，可以被 3 整除，所以它是大于等于 15 且满足题目要求的最小整数。



提示：

1 <= n <= 100
1 <= t <= 10
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        while (!check(n, t)) {
            ++n;
        }

        return n;
    }

    bool check(int n, int t) {
        int mul = 1;

        while (n != 0) {
            mul *= (n % 10);
            n /= 10;
        }

        return (mul % t) == 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(10, o.smallestNumber(10, 2));
    check.checkInt(16, o.smallestNumber(15, 3));
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
