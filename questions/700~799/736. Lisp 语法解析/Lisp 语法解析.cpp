/* Lisp 语法解析.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个类似 Lisp 语句的字符串表达式 expression，求出其计算结果。

表达式语法如下所示:

表达式可以为整数，let 表达式，add 表达式，mult 表达式，或赋值的变量。表达式的结果总是一个整数。
(整数可以是正整数、负整数、0)
let 表达式采用 "(let v1 e1 v2 e2 ... vn en expr)" 的形式，其中 let 总是以字符串 "let"来表示，接下来会跟随一对或多对交替的变量和表达式，也就是说，第一个变量 v1被分配为表达式 e1 的值，第二个变量 v2 被分配为表达式 e2 的值，依次类推；最终 let 表达式的值为 expr表达式的值。
add 表达式表示为 "(add e1 e2)" ，其中 add 总是以字符串 "add" 来表示，该表达式总是包含两个表达式 e1、e2 ，最终结果是 e1 表达式的值与 e2 表达式的值之 和 。
mult 表达式表示为 "(mult e1 e2)" ，其中 mult 总是以字符串 "mult" 表示，该表达式总是包含两个表达式 e1、e2，最终结果是 e1 表达式的值与 e2 表达式的值之 积 。
在该题目中，变量名以小写字符开始，之后跟随 0 个或多个小写字符或数字。为了方便，"add" ，"let" ，"mult" 会被定义为 "关键字" ，不会用作变量名。
最后，要说一下作用域的概念。计算变量名所对应的表达式时，在计算上下文中，首先检查最内层作用域（按括号计），然后按顺序依次检查外部作用域。测试用例中每一个表达式都是合法的。有关作用域的更多详细信息，请参阅示例。
 
示例 1：

输入：expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))"
输出：14
解释：
计算表达式 (add x y), 在检查变量 x 值时，
在变量的上下文中由最内层作用域依次向外检查。
首先找到 x = 3, 所以此处的 x 值是 3 。
示例 2：

输入：expression = "(let x 3 x 2 x)"
输出：2
解释：let 语句中的赋值运算按顺序处理即可。
示例 3：

输入：expression = "(let x 1 y 2 x (add x y) (add x y))"
输出：5
解释：
第一个 (add x y) 计算结果是 3，并且将此值赋给了 x 。
第二个 (add x y) 计算结果是 3 + 2 = 5 。
 
提示：

1 <= expression.length <= 2000
exprssion 中不含前导和尾随空格
expressoin 中的不同部分（token）之间用单个空格进行分隔
答案和所有中间计算结果都符合 32-bit 整数范围
测试用例中的表达式均为合法的且最终结果为整数

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/parse-lisp-expression
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int evaluate(string expression) {
        int index = 0;
        unordered_map<string, vector<int>> globalVars;

        if (expression[index] == '-' || (expression[index] >= '0' && expression[index] <= '9')) {
            return getNumber(expression, index);
        }

        return parseParentheses(expression, index, globalVars);
    }

    int parseParentheses(string& expression, int& index, unordered_map<string, vector<int>>& globalVars) {
        ++index;

        if (expression[index] == 'l') {
            return let(expression, index, globalVars);
        }
        else if (expression[index] == 'a') {
            return add(expression, index, globalVars);
        }
        else {
            return mult(expression, index, globalVars);
        }
    }

    int let(string& expression, int& index, unordered_map<string, vector<int>>& globalVars) {
        int value = 0, num = 0, odd = 1, last = 0;
        string var;
        vector<string> localVars;
        index += 4;

        while (expression[index] != ')') {
            if (expression[index] == ' ') {
                ++index;
            }
            else {
                if (odd == 1) {
                    if (expression[index] >= 'a' && expression[index] <= 'z') {
                        var = getVarName(expression, index);
                        last = 1;
                    }
                    else if (expression[index] == '-' || (expression[index] >= '0' && expression[index] <= '9')) {
                        num = getNumber(expression, index);
                        last = 2;
                    }
                    else {
                        value = parseParentheses(expression, index, globalVars);
                        last = 3;
                    }
                }
                else {
                    globalVars[var].push_back(getVar(expression, index, globalVars));
                    localVars.push_back(var);
                }

                odd ^= 1;
            }
        }

        index += 1;
        value = (last == 1 ? globalVars[var].back() : last == 2 ? num : value);

        for (string& var : localVars) {
            globalVars[var].pop_back();
        }

        return value;
    }

    int add(string& expression, int& index, unordered_map<string, vector<int>>& globalVars) {
        index += 4;
        int var1 = getVar(expression, index, globalVars);
        index += 1;
        int var2 = getVar(expression, index, globalVars);
        index += 1;

        return var1 + var2;
    }

    int mult(string& expression, int& index, unordered_map<string, vector<int>>& globalVars) {
        index += 5;
        int var1 = getVar(expression, index, globalVars);
        index += 1;
        int var2 = getVar(expression, index, globalVars);
        index += 1;

        return var1 * var2;
    }

    int getVar(string& expression, int& index, unordered_map<string, vector<int>>& globalVars) {
        if (expression[index] >= 'a' && expression[index] <= 'z') {
            return globalVars[getVarName(expression, index)].back();
        }
        else if (expression[index] == '-' || (expression[index] >= '0' && expression[index] <= '9')) {
            return getNumber(expression, index);
        }

        return parseParentheses(expression, index, globalVars);
    }

    int getNumber(string& expression, int& index) {
        string num;

        while (index < (int)expression.size() && expression[index] != ' ' && expression[index] != ')') {
            num += expression[index++];
        }

        return stoi(num);
    }

    string getVarName(string& expression, int& index) {
        string name;

        while (expression[index] != ' ' && expression[index] != ')') {
            name += expression[index++];
        }

        return name;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(14, o.evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))"));
    check.checkInt(2, o.evaluate("(let x 3 x 2 x)"));
    check.checkInt(5, o.evaluate("(let x 1 y 2 x (add x y) (add x y))"));
    check.checkInt(2, o.evaluate("2"));
    check.checkInt(321, o.evaluate("(let xy 123 321)"));
    check.checkInt(-12, o.evaluate("(let x 7 -12)"));
    check.checkInt(-2, o.evaluate("(let x -2 y x y)"));
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
