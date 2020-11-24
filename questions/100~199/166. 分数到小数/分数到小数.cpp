/* 分数到小数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。

如果小数部分为循环小数，则将循环的部分括在括号内。

如果存在多个答案，只需返回 任意一个 。

对于所有给定的输入，保证 答案字符串的长度小于 104 。

 

示例 1：

输入：numerator = 1, denominator = 2
输出："0.5"
示例 2：

输入：numerator = 2, denominator = 1
输出："2"
示例 3：

输入：numerator = 2, denominator = 3
输出："0.(6)"
示例 4：

输入：numerator = 4, denominator = 333
输出："0.(012)"
示例 5：

输入：numerator = 1, denominator = 5
输出："0.2"
 

提示：

-231 <= numerator, denominator <= 231 - 1
denominator != 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fraction-to-recurring-decimal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        unordered_map<long long, int> remainders;
        long long lnumerator = numerator, ldenominator = denominator, remainder;  // 考虑-2147483648转换为long long型
        lnumerator = abs(lnumerator);
        ldenominator = abs(ldenominator);

        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)) {
            ans += '-';  // 正负数
        }

        ans += to_string(lnumerator / ldenominator);  // 整数部分
        remainder = lnumerator % ldenominator;
        if (remainder == 0) {
            return ans;
        }

        ans += '.';  // 小数点
        int index = ans.size();

        do {
            remainders[remainder] = index++;
            remainder *= 10;
            ans += '0' + (int)(remainder / ldenominator);  // 小数部分
            remainder %= ldenominator;
        } while (remainder != 0 && remainders.count(remainder) == 0);  // 余数为0表示除尽了，余数重复表示出现了循环节

        if (remainder != 0) {
            ans.insert(remainders[remainder], 1, '(');  // 在循环余数第一次出现的地方添加括号
            ans += ')';
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("2.(285714)", o.fractionToDecimal(16, 7));
    check.checkString("0.(1213)", o.fractionToDecimal(1213, 9999));
    check.checkString("0.1(6)", o.fractionToDecimal(1, 6));
    check.checkString("-6.25", o.fractionToDecimal(-50, 8));
    check.checkString("11", o.fractionToDecimal(-22, -2));
    check.checkString("-0.58(3)", o.fractionToDecimal(7, -12));
    check.checkString("0.0000000004656612873077392578125", o.fractionToDecimal(-1, -2147483648));
    check.checkString("3.(142857)", o.fractionToDecimal(22, 7));
    check.checkString("58040098.(567)", o.fractionToDecimal(2147483647, 37));
    check.checkString("-2147483648", o.fractionToDecimal(-2147483648, 1));
    check.checkString("0.5", o.fractionToDecimal(1, 2));
    check.checkString("2", o.fractionToDecimal(2, 1));
    check.checkString("0.5", o.fractionToDecimal(1, 2));
    check.checkString("0.(6)", o.fractionToDecimal(2, 3));
    check.checkString("0.00(6)", o.fractionToDecimal(2, 300));
    check.checkString("0.(012)", o.fractionToDecimal(4, 333));
    check.checkString("0.2", o.fractionToDecimal(1, 5));
    check.checkString("0", o.fractionToDecimal(0, -5));
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
