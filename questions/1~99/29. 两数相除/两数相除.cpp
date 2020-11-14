/* 两数相除.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

 

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
解释: 7/-3 = truncate(-2.33333..) = -2
 

提示：

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if ((dividend == INT_MIN) && (divisor == -1)) {
            return INT_MAX;
        }

        bool negative = (dividend < 0);
        negative = (divisor < 0) ? (!negative) : negative;

        long long lldividend = abs((long long)dividend);
        long long lldivisor = abs((long long)divisor);
        if (lldividend < lldivisor) {
            return 0;
        }

        pair<long long, long long> quotient = { 0, lldividend };
        long long ans = 0;
        do {
            quotient = mostGreat(quotient.second, lldivisor);
            ans += quotient.first;
        } while (quotient.second >= lldivisor);

        return negative ? (int)(0 - ans) : (int)ans;
    }

    pair<long long, long long> mostGreat(long long dividend, long long divisor) {
        long long quotient = 1;

        while ((divisor + divisor) < dividend) {
            divisor += divisor;
            quotient += quotient;
        }

        return { quotient, dividend - divisor };
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(3, o.divide(10, 3));
    check.checkInt(-2, o.divide(7, -3));
    check.checkInt(0, o.divide(1, 2));
    check.checkInt(INT_MAX, o.divide(INT_MAX, 1));
    check.checkInt(-INT_MAX, o.divide(INT_MAX, -1));
    check.checkInt(1073741823, o.divide(INT_MAX, 2));
    check.checkInt(-1073741823, o.divide(INT_MAX, -2));
    check.checkInt(INT_MIN, o.divide(INT_MIN, 1));
    check.checkInt(INT_MAX, o.divide(INT_MIN, -1));
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
