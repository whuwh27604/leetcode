/* 移除无效的括号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 '('、')' 和小写字母组成的字符串 s。

你需要从字符串中删除最少数目的 '(' 或者 ')' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。

请返回任意一个合法字符串。

有效「括号字符串」应当符合以下 任意一条 要求：

空字符串或只包含小写字母的字符串
可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
可以被写作 (A) 的字符串，其中 A 是一个有效的「括号字符串」
 

示例 1：

输入：s = "lee(t(c)o)de)"
输出："lee(t(c)o)de"
解释："lee(t(co)de)" , "lee(t(c)ode)" 也是一个可行答案。
示例 2：

输入：s = "a)b(c)d"
输出："ab(c)d"
示例 3：

输入：s = "))(("
输出：""
解释：空字符串也是有效的
示例 4：

输入：s = "(a(b(c)d)"
输出："a(b(c)d)"
 

提示：

1 <= s.length <= 10^5
s[i] 可能是 '('、')' 或英文小写字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        flagInvalidParentheses(s);

        string validStr;

        for (char c : s) {
            if (c != '#') {
                validStr += c;
            }
        }

        return validStr;
    }

    void flagInvalidParentheses(string& s) {
        stack<unsigned int> indices;

        for (unsigned int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                indices.push(i);
            }
            else if (s[i] == ')') {
                if (indices.empty()) {
                    s[i] = '#';
                }
                else {
                    indices.pop();
                }
            }
        }

        while (!indices.empty()) {
            s[indices.top()] = '#';
            indices.pop();
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("lee(t(c)o)de", o.minRemoveToMakeValid("lee(t(c)o)de)"));
    check.checkString("ab(c)d", o.minRemoveToMakeValid("a)b(c)d"));
    check.checkString("", o.minRemoveToMakeValid("))(("));
    check.checkString("a(b(c)d)", o.minRemoveToMakeValid("(a(b(c)d)"));
    check.checkString("", o.minRemoveToMakeValid("("));
    check.checkString("a", o.minRemoveToMakeValid("a"));
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
