/* 字符串转换整数 (atoi).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：

如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0 。

提示：

本题中的空白字符只包括空格字符 ' ' 。
假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。
 

示例 1:

输入: "42"
输出: 42
示例 2:

输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
示例 3:

输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
示例 4:

输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
示例 5:

输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
     因此返回 INT_MIN (−231) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-to-integer-atoi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i, len = str.size();

        for (i = 0; i < len; i++) {
            if (str[i] != ' ') {
                break;
            }
        }

        if (i >= len) {
            return 0;
        }

        bool negative = false;
        if (str[i] == '+') {
            i++;
        }
        else if ((str[i] == '-')) {
            i++;
            negative = true;
        }

        long long num = 0;
        while (str[i] >= '0' && str[i] <= '9') {
            if (negative) {
                num = num * 10 - (str[i] - '0');
                if (num < INT_MIN) {
                    return INT_MIN;
                }
            }
            else {
                num = num * 10 + str[i] - '0';
                if (num > INT_MAX) {
                    return INT_MAX;
                }
            }

            i++;
        }

        return (int)num;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(42, o.myAtoi("42"));
    check.checkInt(42, o.myAtoi(" 42"));
    check.checkInt(42, o.myAtoi("   42"));
    check.checkInt(42, o.myAtoi(" +42"));
    check.checkInt(-42, o.myAtoi("  -42"));
    check.checkInt(4193, o.myAtoi("4193 with words"));
    check.checkInt(0, o.myAtoi("words and 987"));
    check.checkInt(0, o.myAtoi(" words and 987"));
    check.checkInt(0, o.myAtoi(""));
    check.checkInt(0, o.myAtoi(" "));
    check.checkInt(0, o.myAtoi("+a987"));
    check.checkInt(0, o.myAtoi("-a987"));
    check.checkInt(987, o.myAtoi("987 1"));
    check.checkInt(0, o.myAtoi("0"));
    check.checkInt(1, o.myAtoi("1"));
    check.checkInt(-1, o.myAtoi("-1"));
    check.checkInt(INT_MAX, o.myAtoi("2147483647"));
    check.checkInt(INT_MAX, o.myAtoi("2147483648"));
    check.checkInt(INT_MIN, o.myAtoi("-2147483648"));
    check.checkInt(INT_MIN, o.myAtoi("-2147483649"));
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
