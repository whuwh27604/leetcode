/* 反转表达式值的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 有效的 布尔表达式，用字符串 expression 表示。这个字符串包含字符 '1'，'0'，'&'（按位 与 运算），'|'（按位 或 运算），'(' 和 ')' 。

比方说，"()1|1" 和 "(1)&()" 不是有效 布尔表达式。而 "1"， "(((1))|(0))" 和 "1|(0&(1))" 是 有效 布尔表达式。
你的目标是将布尔表达式的 值 反转 （也就是将 0 变为 1 ，或者将 1 变为 0），请你返回达成目标需要的 最少操作 次数。

比方说，如果表达式 expression = "1|1|(0&0)&1" ，它的 值 为 1|1|(0&0)&1 = 1|1|0&1 = 1|0&1 = 1&1 = 1 。我们想要执行操作将 新的 表达式的值变成 0 。
可执行的 操作 如下：

将一个 '1' 变成一个 '0' 。
将一个 '0' 变成一个 '1' 。
将一个 '&' 变成一个 '|' 。
将一个 '|' 变成一个 '&' 。
注意：'&' 的 运算优先级 与 '|' 相同 。计算表达式时，括号优先级 最高 ，然后按照 从左到右 的顺序运算。

 

示例 1：

输入：expression = "1&(0|1)"
输出：1
解释：我们可以将 "1&(0|1)" 变成 "1&(0&1)" ，执行的操作为将一个 '|' 变成一个 '&' ，执行了 1 次操作。
新表达式的值为 0 。
示例 2：

输入：expression = "(0&0)&(0&0&0)"
输出：3
解释：我们可以将 "(0&0)&(0&0&0)" 变成 "(0|1)|(0&0&0)" ，执行了 3 次操作。
新表达式的值为 1 。
示例 3：

输入：expression = "(0|(1|0&1))"
输出：1
解释：我们可以将 "(0|(1|0&1))" 变成 "(0|(0|0&1))" ，执行了 1 次操作。
新表达式的值为 0 。
 

提示：

1 <= expression.length <= 105
expression 只包含 '1'，'0'，'&'，'|'，'(' 和 ')'
所有括号都有与之匹配的对应括号。
不会有空的括号（也就是说 "()" 不是 expression 的子字符串）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-to-change-the-final-value-of-expression
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperationsToFlip(string expression) {
        stack<pair<int, int>> minOpers;
        stack<char> opers;
        pair<int, int> operand1, operand2;
        char oper = 0;

        for (char c : expression) {
            if (c == '|' || c == '&') {  // 遇到操作符，更新oper
                oper = c;
            }
            else if (c == '0' || c == '1') {  // 遇到操作数
                int num = c - '0';
                if (oper == 0) {  // 第一个操作数
                    operand1 = { num, (num + 1) % 2 };
                }
                else {  // 第二个操作数，执行运算
                    operand2 = { num, (num + 1) % 2 };
                    operand1 = dp(operand1, operand2, oper);
                }
            }
            else if (c == '(') {  // 遇到左括号，操作符、操作数入栈
                minOpers.push(operand1);
                opers.push(oper);
                oper = 0;
            }
            else {  // 遇到右括号，从栈顶弹出操作符、操作数执行运算
                oper = opers.top();
                opers.pop();
                operand2 = minOpers.top();
                minOpers.pop();

                if (oper != 0) {
                    operand1 = dp(operand1, operand2, oper);
                }
            }
        }

        return operand1.first + operand1.second;  // 必然一个为0，对应表达式原本的值，另一个就是翻转需要的最小次数
    }

    pair<int, int> dp(pair<int, int>& operand1, pair<int, int>& operand2, char oper) {
        pair<int, int> result;

        if (oper == '|') {
            result.first = min(operand1.first + operand2.first, min(operand1.first, operand2.first) + 1);  // 要让结果是0，可以两个都是0，也可以任一个为0，然后将'|'改为'&'
            result.second = min(operand1.second, operand2.second);  // 要让结果是1，任一个是1就可以了
        }
        else {
            result.first = min(operand1.first, operand2.first);  // 要让结果是0，任一个是0就可以了
            result.second = min(operand1.second + operand2.second, min(operand1.second, operand2.second) + 1);  // 要让结果是1，可以两个都是1，也可以任一个为1，然后将'&'改为'|'
        }

        return result;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.minOperationsToFlip("1&(0|1)"));
    check.checkInt(3, o.minOperationsToFlip("(0&0)&(0&0&0)"));
    check.checkInt(1, o.minOperationsToFlip("(0|(1|0&1))"));
    check.checkInt(1, o.minOperationsToFlip("0"));
    check.checkInt(2, o.minOperationsToFlip("0&0"));
    check.checkInt(1, o.minOperationsToFlip("1|((0&0)&0|(0&0))"));
    check.checkInt(2, o.minOperationsToFlip("1&(((0&0))&0)&1&1&(((0&0)))&1|(0&0)|(1&1)|(0&0)|(1&(1&((0)&(0&0)&(0&0)|1|0&(1|((1&((0&0)&((0&0)|((0&0)|(0&0))|0&(0&0)|(0&0))|(0&0)&1))&1&1))|1|(1))|((0&0)&0|(0&0))&1|0)&(0&0))&(0&(0&0)|(0&0)|0|1)|(0&1&(0&0)&0&1)&1|(1&0|0&0|(0&0)&1|1|(((0|(0&0))))|(0&0))&1&(0&0)|1&(0&0)&(0&0)&(1)&0|(1|(0&0))&((0&0))&1&((((1|(0&0)|((0&1)|((0&0)&((0&0)|0)&0|(0&0))|(1|(0&0)&1)|0&(0|(0&0)&(0|((1&(0&0)|1|1)&(0&0)&(0&0)|(0&0)&0|(0&0))|1))&1&0&(0&0))&(0&0)|0&0|((0&0)))))&1|0&1)|1&(0)&1&0&(((0&0))&0&0&(1|(((0&0))&(0&0)|(1))))"));
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
