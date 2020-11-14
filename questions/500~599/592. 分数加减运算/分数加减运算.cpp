/* 分数加减运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个表示分数加减运算表达式的字符串，你需要返回一个字符串形式的计算结果。 这个结果应该是不可约分的分数，即最简分数。 如果最终结果是一个整数，例如 2，你需要将它转换成分数形式，其分母为 1。所以在上述例子中, 2 应该被转换为 2/1。

示例 1:

输入:"-1/2+1/2"
输出: "0/1"
 示例 2:

输入:"-1/2+1/2+1/3"
输出: "1/3"
示例 3:

输入:"1/3-1/2"
输出: "-1/6"
示例 4:

输入:"5/3+1/3"
输出: "2/1"
说明:

输入和输出字符串只包含 '0' 到 '9' 的数字，以及 '/', '+' 和 '-'。 
输入和输出分数格式均为 ±分子/分母。如果输入的第一个分数或者输出的分数是正数，则 '+' 会被省略掉。
输入只包含合法的最简分数，每个分数的分子与分母的范围是  [1,10]。 如果分母是1，意味着这个分数实际上是一个整数。
输入的分数个数范围是 [1,10]。
最终结果的分子与分母保证是 32 位整数范围内的有效整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fraction-addition-and-subtraction
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        vector<long long> numerators, denominators;
        analysis(expression, numerators, denominators);

        int i, size = numerators.size();
        long long numerator = 0, denominator = 1;
        for (i = 0; i < size; i++) {
            denominator *= denominators[i];
        }

        for (i = 0; i < size; i++) {
            numerator += (numerators[i] * denominator / denominators[i]);
        }

        bool negative = false;
        if (numerator < 0) {
            negative = true;
            numerator = -numerator;
        }

        long long maxDivisor = gcd(numerator, denominator);
        numerator /= maxDivisor;
        denominator /= maxDivisor;

        string result;
        if (negative) {
            result += "-";
        }

        return result + to_string(numerator) + "/" + to_string(denominator);
    }

    void analysis(string& expression, vector<long long>& numerators, vector<long long>& denominators) {
        int i, size = expression.size(), num;
        bool isDenominator = true;

        for (i = size - 1; i >= 0; i--) {
            char c = expression[i];
            if ((c >= '0') && (c <= '9')) {
                if (c == '0') {
                    num = 10;
                    i--;
                }
                else {
                    num = c - '0';
                }

                if (isDenominator) {
                    denominators.push_back(num);
                }
                else {
                    numerators.push_back(num);
                }
                isDenominator = !isDenominator;
            }
            else if (c == '-') {
                numerators.back() = -numerators.back();
            }
        }
    }

    long long gcd(long long x, long long y) {
        return (y == 0) ? x : gcd(y, x % y);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("0/1", o.fractionAddition("-1/2+1/2"));
    check.checkString("1/3", o.fractionAddition("-1/2+1/2+1/3"));
    check.checkString("-1/6", o.fractionAddition("1/3-1/2"));
    check.checkString("2/1", o.fractionAddition("5/3+1/3"));
    check.checkString("-1/1", o.fractionAddition("-1/10-9/10"));
    check.checkString("9/1", o.fractionAddition("9/10+9/10+9/10+9/10+9/10+9/10+9/10+9/10+9/10+9/10"));
    check.checkString("-2/5", o.fractionAddition("-2/5"));
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
