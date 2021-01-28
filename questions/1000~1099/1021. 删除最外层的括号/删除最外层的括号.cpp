/* 删除最外层的括号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有效括号字符串为空 ("")、"(" + A + ")" 或 A + B，其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。

如果有效字符串 S 非空，且不存在将其拆分为 S = A+B 的方法，我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。

给出一个非空有效字符串 S，考虑将其进行原语化分解，使得：S = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。

对 S 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 S 。

 

示例 1：

输入："(()())(())"
输出："()()()"
解释：
输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
示例 2：

输入："(()())(())(()(()))"
输出："()()()()(())"
解释：
输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
删除每个部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
示例 3：

输入："()()"
输出：""
解释：
输入字符串为 "()()"，原语化分解得到 "()" + "()"，
删除每个部分中的最外层括号后得到 "" + "" = ""。
 

提示：

S.length <= 10000
S[i] 为 "(" 或 ")"
S 是一个有效括号字符串

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-outermost-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        string outerRemoved;
        int leftCount = 0;

        for (char c : S) {
            if (c == '(') {
                if (++leftCount != 1) {
                    outerRemoved += c;
                }
            }
            else {
                if (--leftCount != 0) {
                    outerRemoved += c;
                }
            }
        }

        return outerRemoved;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string S = "(()())(())";
    string expected = "()()()";
    check.checkString(expected, o.removeOuterParentheses(S));

    S = "(()())(())(()(()))";
    expected = "()()()()(())";
    check.checkString(expected, o.removeOuterParentheses(S));

    S = "()()";
    expected = "";
    check.checkString(expected, o.removeOuterParentheses(S));

    S = "";
    expected = "";
    check.checkString(expected, o.removeOuterParentheses(S));

    S = "((()))";
    expected = "(())";
    check.checkString(expected, o.removeOuterParentheses(S));

    S = "(())((())((())))((((())))((((()))))(((((()))))))";
    expected = "()(())((()))(((())))((((()))))(((((())))))";
    check.checkString(expected, o.removeOuterParentheses(S));
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
