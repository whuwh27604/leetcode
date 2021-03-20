﻿/* 逆波兰表达式求值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
根据 逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

 

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 

示例 1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: 该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
示例 2：

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: 该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
示例 3：

输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释:
该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

逆波兰表达式：

逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
逆波兰表达式主要有以下两个优点：

去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <sstream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;

        for (string s : tokens) {
            if ((s[0] >= '0' && s[0] <= '9') || (s.size() != 1)) {
                numbers.push(stoi(s));
            }
            else {
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();

                if (s == "+") {
                    numbers.push(a + b);
                }
                else if (s == "-") {
                    numbers.push(a - b);
                }
                else if (s == "*") {
                    numbers.push(a * b);
                }
                else {
                    numbers.push(a / b);
                }
            }
        }

        return numbers.top();
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> tokens = { "1","2","+" };
    check.checkInt(3, o.evalRPN(tokens));

    tokens = { "5","3","-" };
    check.checkInt(2, o.evalRPN(tokens));

    tokens = { "2","3","*" };
    check.checkInt(6, o.evalRPN(tokens));

    tokens = { "12","3","/" };
    check.checkInt(4, o.evalRPN(tokens));

    tokens = { "2", "1", "+", "3", "*" };
    check.checkInt(9, o.evalRPN(tokens));

    tokens = { "4", "13", "5", "/", "+" };
    check.checkInt(6, o.evalRPN(tokens));

    tokens = { "6" };
    check.checkInt(6, o.evalRPN(tokens));

    tokens = { "-4" };
    check.checkInt(-4, o.evalRPN(tokens));

    tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
    check.checkInt(22, o.evalRPN(tokens));
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
