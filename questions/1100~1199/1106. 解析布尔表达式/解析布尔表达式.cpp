/* 解析布尔表达式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个以字符串形式表述的 布尔表达式（boolean） expression，返回该式的运算结果。

有效的表达式需遵循以下约定：

"t"，运算结果为 True
"f"，运算结果为 False
"!(expr)"，运算过程为对内部表达式 expr 进行逻辑 非的运算（NOT）
"&(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 与的运算（AND）
"|(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 或的运算（OR）
 

示例 1：

输入：expression = "!(f)"
输出：true
示例 2：

输入：expression = "|(f,t)"
输出：true
示例 3：

输入：expression = "&(t,f)"
输出：false
示例 4：

输入：expression = "|(&(t,f,t),!(t))"
输出：false
 

提示：

1 <= expression.length <= 20000
expression[i] 由 {'(', ')', '&', '|', '!', 't', 'f', ','} 中的字符组成。
expression 是以上述形式给出的有效表达式，表示一个布尔值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/parsing-a-boolean-expression
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> exprs;
        int i;

        for (char c : expression) {
            if (c == ',') {
                continue;
            }
            else if (c == ')') {  // 碰到')'就计算这一组()内的value，并将value重新入栈
                vector<char> values;

                while (exprs.top() != '(') {  // 先把values都导出来
                    values.push_back(exprs.top());
                    exprs.pop();
                }

                exprs.pop();  // pop '('

                if (exprs.empty()) {  // 如果栈已经空了，那么只能有一个value
                    exprs.push(values[0]);
                }
                else {
                    char oper = exprs.top();  // pop逻辑运算符
                    exprs.pop();

                    if (oper == '!') {
                        exprs.push(values[0] == 't' ? 'f' : 't');
                    }
                    else if (oper == '&') {
                        for (i = 0; i < (int)values.size(); ++i) {
                            if (values[i] == 'f') {
                                break;
                            }
                        }

                        exprs.push(i == values.size() ? 't' : 'f');
                    }
                    else {
                        for (i = 0; i < (int)values.size(); ++i) {
                            if (values[i] == 't') {
                                break;
                            }
                        }

                        exprs.push(i == values.size() ? 'f' : 't');
                    }
                }
            }
            else {  // 其它统统入栈
                exprs.push(c);
            }
        }

        return exprs.top() == 't' ? true : false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.parseBoolExpr("!(f)"));
    check.checkBool(true, o.parseBoolExpr("|(f,t)"));
    check.checkBool(false, o.parseBoolExpr("&(t,f)"));
    check.checkBool(false, o.parseBoolExpr("|(&(t,f,t),!(t))"));
    check.checkBool(true, o.parseBoolExpr("t"));
    check.checkBool(false, o.parseBoolExpr("(f)"));
    check.checkBool(true, o.parseBoolExpr("!(&(!(t),&(f),|(f)))"));
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
