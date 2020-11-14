/* 有效的括号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        for (char parenthese : s) {
            if (parenthese == '(') {
                parentheses.push(')');
            }
            else if (parenthese == '[') {
                parentheses.push(']');
            }
            else if (parenthese == '{') {
                parentheses.push('}');
            }
            else {
                if (parentheses.empty()) {
                    return false;
                }

                if (parentheses.top() != parenthese) {
                    return false;
                }
                parentheses.pop();
            }
        }

        return parentheses.empty();
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.isValid("()"));
    check.checkBool(true, o.isValid("()[]{}"));
    check.checkBool(false, o.isValid("(]"));
    check.checkBool(false, o.isValid("([)]"));
    check.checkBool(true, o.isValid("{[]}"));
    check.checkBool(true, o.isValid(""));
    check.checkBool(false, o.isValid("]"));
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
