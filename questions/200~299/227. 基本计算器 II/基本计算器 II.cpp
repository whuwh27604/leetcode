/* 基本计算器 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

示例 1:

输入: "3+2*2"
输出: 7
示例 2:

输入: " 3/2 "
输出: 1
示例 3:

输入: " 3+5 / 2 "
输出: 5
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        queue<int> expression;
        int i, j, size = s.size(), numA = 1, numB, oper = 3;

        for (i = 0; i < size; ++i) {
            char c = s[i];
            if (c == ' ') {
                continue;
            }
            else if (c == '+') {
                expression.push(numA);
                expression.push(1);
                numA = 1;
                oper = 3;
            }
            else if (c == '-') {
                expression.push(numA);
                expression.push(2);
                numA = 1;
                oper = 3;
            }
            else if (c == '*') {
                oper = 3;
            }
            else if (c == '/') {
                oper = 4;
            }
            else {
                for (j = i + 1; j < size && s[j] >= '0' && s[j] <= '9'; ++j) {}

                numB = stoi(string(s, i, j - i));
                numA = oper == 3 ? numA * numB : numA / numB;
                i = j - 1;
            }
        }

        expression.push(numA);
        numA = expression.front();
        expression.pop();

        while (!expression.empty()) {
            oper = expression.front();
            expression.pop();
            numB = expression.front();
            expression.pop();
            numA = oper == 1 ? numA + numB : numA - numB;
        }

        return numA;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(5, o.calculate("5"));
    check.checkInt(3, o.calculate("1 + 2"));
    check.checkInt(-1, o.calculate(" 3 - 4 "));
    check.checkInt(0, o.calculate("0 * 4"));
    check.checkInt(4, o.calculate("12 / 3"));
    check.checkInt(7, o.calculate("3+2*2"));
    check.checkInt(1, o.calculate("3/2"));
    check.checkInt(5, o.calculate(" 3+5 / 2 "));
    check.checkInt(1, o.calculate(" 3-5 / 2 "));
    check.checkInt(2579, o.calculate("123+2456"));
    check.checkInt(1, o.calculate("1"));
    check.checkInt(1, o.calculate("1-1+1"));
    check.checkInt(8, o.calculate("14/3*2"));
    check.checkInt(1, o.calculate(" 3/2 "));
    check.checkInt(-7, o.calculate("3+5/2+3*2-54/3"));
    check.checkInt(145, o.calculate("3+5/2+3*2-54/3+19*8"));
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
