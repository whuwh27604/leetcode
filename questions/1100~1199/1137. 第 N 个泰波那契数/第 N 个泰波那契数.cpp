﻿/* 第 N 个泰波那契数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
泰波那契序列 Tn 定义如下： 

T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数 n，请返回第 n 个泰波那契数 Tn 的值。

 

示例 1：

输入：n = 4
输出：4
解释：
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
示例 2：

输入：n = 25
输出：1389537
 

提示：

0 <= n <= 37
答案保证是一个 32 位整数，即 answer <= 2^31 - 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-th-tribonacci-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int tribonaccis[38] = { 0,1,1 };

        for (int i = 0; i <= 34; i++) {
            tribonaccis[i + 3] = tribonaccis[i] + tribonaccis[i + 1] + tribonaccis[i + 2];
        }

        return tribonaccis[n];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.tribonacci(0));
    check.checkInt(1, o.tribonacci(1));
    check.checkInt(1, o.tribonacci(2));
    check.checkInt(2, o.tribonacci(3));
    check.checkInt(4, o.tribonacci(4));
    check.checkInt(7, o.tribonacci(5));
    check.checkInt(1389537, o.tribonacci(25));
    check.checkInt(2082876103, o.tribonacci(37));
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
