/* 求出数字答案.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你三个 正 整数 num1 ，num2 和 num3 。

数字 num1 ，num2 和 num3 的数字答案 key 是一个四位数，定义如下：

一开始，如果有数字 少于 四位数，给它补 前导 0 。
答案 key 的第 i 个数位（1 <= i <= 4）为 num1 ，num2 和 num3 第 i 个数位中的 最小 值。
请你返回三个数字 没有 前导 0 的数字答案。



示例 1：

输入：num1 = 1, num2 = 10, num3 = 1000

输出：0

解释：

补前导 0 后，num1 变为 "0001" ，num2 变为 "0010" ，num3 保持不变，为 "1000" 。

数字答案 key 的第 1 个数位为 min(0, 0, 1) 。
数字答案 key 的第 2 个数位为 min(0, 0, 0) 。
数字答案 key 的第 3 个数位为 min(0, 1, 0) 。
数字答案 key 的第 4 个数位为 min(1, 0, 0) 。
所以数字答案为 "0000" ，也就是 0 。

示例 2：

输入： num1 = 987, num2 = 879, num3 = 798

输出：777

示例 3：

输入：num1 = 1, num2 = 2, num3 = 3

输出：1



提示：

1 <= num1, num2, num3 <= 9999
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int key = 0;

        for (int d = 1; d < 10000; d *= 10) {
            key += min({ num1 / d % 10,num2 / d % 10,num3 / d % 10 }) * d;
        }

        return key;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.generateKey(1, 10, 1000));
    check.checkInt(777, o.generateKey(987, 879, 798));
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
