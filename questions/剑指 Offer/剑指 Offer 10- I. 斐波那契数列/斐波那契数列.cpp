/* 斐波那契数列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 

示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5
 

提示：

0 <= n <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int fib(int n) {
        int i, prevTwo = 0, prev = 1, fn = n == 0 ? 0 : 1, mod = 1000000007;

        for (i = 2; i <= n; ++i) {
            fn = prevTwo + prev;
            if (fn >= mod) {
                fn -= mod;
            }

            prevTwo = prev;
            prev = fn;
        }

        return fn;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.fib(0));
    check.checkInt(1, o.fib(1));
    check.checkInt(1, o.fib(2));
    check.checkInt(5, o.fib(5));
    check.checkInt(55, o.fib(10));
    check.checkInt(687995182, o.fib(100));
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
