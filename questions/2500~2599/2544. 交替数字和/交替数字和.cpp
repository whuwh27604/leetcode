/* 交替数字和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n 。n 中的每一位数字都会按下述规则分配一个符号：

最高有效位 上的数字分配到 正 号。
剩余每位上数字的符号都与其相邻数字相反。
返回所有数字及其对应符号的和。



示例 1：

输入：n = 521
输出：4
解释：(+5) + (-2) + (+1) = 4
示例 2：

输入：n = 111
输出：1
解释：(+1) + (-1) + (+1) = 1
示例 3：

输入：n = 886996
输出：0
解释：(+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0


提示：

1 <= n <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0;
        bool negative = false;

        while (n != 0) {
            int digit = n % 10;
            n /= 10;
            sum += negative ? -digit : digit;
            negative = !negative;
        }

        return negative ? sum : -sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.alternateDigitSum(521));
    check.checkInt(1, o.alternateDigitSum(111));
    check.checkInt(0, o.alternateDigitSum(886996));
    check.checkInt(1, o.alternateDigitSum(1));
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
