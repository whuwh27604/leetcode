/* 斐波那契数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
给定 N，计算 F(N)。

 

示例 1：

输入：2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
示例 2：

输入：3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
示例 3：

输入：4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
 

提示：

0 ≤ N ≤ 30

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fibonacci-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int fib(int N) {
        int* fibonacci = new int[N + 2];
        fibonacci[0] = 0;
        fibonacci[1] = 1;
        for (int i = 2; i <= N; i++) {
            fibonacci[i] = (fibonacci[i - 2] + fibonacci[i - 1]);
        }

        int fibonacciN = fibonacci[N];
        delete[] fibonacci;

        return fibonacciN;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.fib(0));
    check.checkInt(1, o.fib(1));
    check.checkInt(1, o.fib(2));
    check.checkInt(2, o.fib(3));
    check.checkInt(3, o.fib(4));
    check.checkInt(5, o.fib(5));
    check.checkInt(8, o.fib(6));
    check.checkInt(13, o.fib(7));
    check.checkInt(21, o.fib(8));
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
