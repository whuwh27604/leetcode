/* 基本计算器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实现一个基本的计算器来计算一个简单的字符串表达式 s 的值。

 

示例 1：

输入：s = "1 + 1"
输出：2
示例 2：

输入：s = " 2-1 + 2 "
输出：3
示例 3：

输入：s = "(1+(4+5+2)-3)+(6+8)"
输出：23
 

提示：

1 <= s.length <= 3 * 105
s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
s 表示一个有效的表达式

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> expression;
        int numA = 0, numB, add = 1, i, j, size = s.size();

        for (i = 0; i < size; ++i) {
            char c = s[i];
            if (c == ' ') {
                continue;
            }
            else if (c == '+') {
                add = 1;
            }
            else if (c == '-') {
                add = 0;
            }
            else if (c == '(') {
                expression.push(numA);
                expression.push(add);
                numA = 0;
                add = 1;
            }
            else if (c == ')') {
                add = expression.top();
                expression.pop();
                numB = numA;
                numA = expression.top();
                expression.pop();
                numA = add == 1 ? numA + numB : numA - numB;
            }
            else {
                for (j = i + 1; j < size && s[j] >= '0' && s[j] <= '9'; ++j) {}

                numB = stoi(string(s, i, j - i));
                numA = add == 1 ? numA + numB : numA - numB;
                i = j - 1;
            }
        }

        return numA;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.calculate("1 + 1"));
    check.checkInt(3, o.calculate(" 2-1 + 2 "));
    check.checkInt(23, o.calculate("(1+(4+5+2)-3)+(6+8)"));
    check.checkInt(11, o.calculate("(7)-(0)+(4)"));
    check.checkInt(-1, o.calculate("-2+ 1"));
    check.checkInt(23, o.calculate("(3-(5-(8)-(2+(9-(0-(8-(2))))-(4))-(4)))"));
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
