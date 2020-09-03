﻿/* 最长有效括号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int i, size = s.size();
        int leftCount = 0, rightCount = 0, maxLength = 0;

        for (i = 0; i < size; i++) {
            if (s[i] == '(') {
                leftCount++;
            }
            else {
                rightCount++;
            }

            if (rightCount == leftCount) {
                maxLength = max(maxLength, leftCount * 2);
            }
            else if (rightCount > leftCount) {
                leftCount = 0;
                rightCount = 0;
            }
        }

        leftCount = 0;
        rightCount = 0;
        for (i = size - 1; i >= 0; i--) {
            if (s[i] == ')') {
                rightCount++;
            }
            else {
                leftCount++;
            }

            if (leftCount == rightCount) {
                maxLength = max(maxLength, rightCount * 2);
            }
            else if (leftCount > rightCount) {
                leftCount = 0;
                rightCount = 0;
            }
        }

        return maxLength;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.longestValidParentheses(""));
    check.checkInt(0, o.longestValidParentheses("("));
    check.checkInt(0, o.longestValidParentheses(")"));
    check.checkInt(2, o.longestValidParentheses("()"));
    check.checkInt(0, o.longestValidParentheses(")("));
    check.checkInt(2, o.longestValidParentheses("(()"));
    check.checkInt(4, o.longestValidParentheses(")()())"));
    check.checkInt(4, o.longestValidParentheses("((())"));
    check.checkInt(4, o.longestValidParentheses("((()()"));
    check.checkInt(4, o.longestValidParentheses("(()(()()"));
    check.checkInt(4, o.longestValidParentheses("((())(()"));
    check.checkInt(6, o.longestValidParentheses("()()()"));
    check.checkInt(6, o.longestValidParentheses("((()))"));
    check.checkInt(6, o.longestValidParentheses("()())(()()()"));
    check.checkInt(6, o.longestValidParentheses("()())()()()"));
    check.checkInt(6, o.longestValidParentheses("()()())(()()"));
    check.checkInt(10, o.longestValidParentheses(")()(((())))("));
    check.checkInt(2644, o.longestValidParentheses("((())))()())))(((()()(())))((()(())()((()))())())())()())))))))(((()(())(()))(()()(()()((()))()(())(()(())))))()(())(()()(((()(()()))))((()()))))))()((()())()()))((())()((((()))()()()((()())))())((())))))))(()()((((((()))(((((((()()))((())()(()())()()()(()())(()())(())))()()))))()(((())(())(()())()))()(()))(())((()))))(())))()))((()((()(())(()()()()()))(())())()))))()(()(((())))()()()(((()((()))(()((((((())((()))(()(())(()))(())())))()()))))())(()((()()())()))((((()(()))()()))(()())))((()))(()((((()(())(())()((()))(()))())))(((()(())))((())()(()(((())))())())()()()())((()()))))))(()))(())()(((()))()()((()))(()))(((()))))))))(()(())())(()((())(()()))((())))(()())((((())))(()(()))())(((()(()((()(())((())())(()))(())))()()(())((()()))((()()((()()())())()))())()))())()))())(()(()))(()))()(())))((((())()())()()())((()())(()())(()()))()(())(())))))()()()((()(())(((()(())()()))(()()((()(((()))))))))(((()((()()((()(((((())((()((()((((((((())()))())((())((()((()(()((())(((()(()))())))))))))))))()((()(())())))()(()))(((()))())()(((()))))((()(())(()())(((()(((()((((())()))))(())((()(((((()((()(()()()()((()((((((((((((())()(()))()()(()())()(()(((()((()(()()()())))((())()))())()()))())(((()(())))))()()()(((())))((()(()(((())(())(()((((()(((()(())(((((())()))())())()()(()())((((()(())))((()())))))))))()(()(())))))))()))()())))((())(()()()()()()()(())(()())))))())((()()))))()))))((())((()(((()))))(((()()))()(()((()()())()))(((()(()((())(()(()(()()))()((()(())))()((())))))(())()(())()))((())(((((()))()())(())))((((()((())())(())))(())))))((())())())((((()((())))()()((()()()))()())())(()())(((()))()()))))(()(())(()))()())(()())(()))(((((((()(()))())()())()())((()(((((()())(((())))()())))(()(()(())()((())()))(())))())()))((((()))())((()))(())))))(()))))))(()))))(())))())()()())()()(())()()(((((()))(((()()))()(()((((()(()(()(())))())))())(()()())()(()))())(()()))(()()((()()))))))(())((()()))(())))())())(())((((()))))()))()))()()()))))((((()((())(()))(()()))(())()())(()())))(()(()(())((()())()((())(()))()))()))))((())))(())(()))()()()()()))((())(((()(())))(((((((()(()))(()))())()((()))(()(())((()((()((())))()()((())))))((((())()())(()()(((()()((()))()()((())))(((()())((((()(())())))())()()()(())()))))))()()((()))())(()(((()()))((())))())())())((((()(((()(())())()())((()((()(()((())()(()))()((())))()(()))))(((()))())())(()((()))))()()(((((()))())))(()(()(())((((())())))((()()())(((((((()(()(()))(())))))()))(()(((((())()))((()()()()((()))()(()()()()))(()))))())())()))()(()()(((())((()))(()())))((()()(((())())))))))(())))((()(()(((())((((()))))(()()()))))(((((((())(()(()))(()(())((())(()(()(()(()())(())()(())(()()(()(()))())(())()()(((()())(())(()(((()()(())()((((()()))())(((()(((((()())()(())))()))))(()(()()(()(()()(((()))()))((()())))()(()(())))))))())((((()()))(()))))()((()))(()))())()))()))))(()(())()()()))(((((()))()())())(()())())))()())))))()()()())))))(())(((()))((())((()()))))()((((()(()(()))))(()(())(((())(()()(((()(())()())(()()(()(()())))()())))(((()()((()())()()((()))()))(((()((((()(((()(((()(()())((()))))()(()())(())()(()(((())((()))(())()(())()(()(())()))())()))()())(()))))()))))((()()()((()(()()(())))())(())()(()()))))))))()((()))((((())))())))((()()()(()(()((((()((()))()()((())((())(()))))(())())(((()()(()))))))(()()))()))((()(()(())()))(((())()))(())(()((((()((()()()))()()))(()()(())())((((((())(())((()())()(()())))()))())(()()(()(()()()(()()()()))(()(()()())())((()()()(((()((()())()()((()()(()((()())()())()((()))(()((()())))))))(())((((())(((((())(((())(()))(((()((()()())()((()(()))()()()(()((((())))(())())))((())))(()(((((()()()((())((((((((()()((((())))())())())))))))(((()())(((()))())))()))((())())())))))))))(()()(((())))))(())()()))((())()))(()(()))((()(()((((()(()(((()))))()))(()(()))())())()()(((())())(((()))))(((()())))()(()())()())()))())())(()()(((()()))(())(((()((())((((())))))((()))))(()((()(())))()(())((()(())((()(()())())))()))))(())())(()())()()()((())))((()()))()()()((((()())))))()))))()))())()((()(())()()(())(((()((()))(()(()()))(()))()))))))))))))(()()))(((())((()(((()()()(()())((((()(()()()))())))())(()())))(()((((()))((()()())(((()))()())(()(()((()(()))))(())()()((()())((()(()(()))((()((()())(((()(((((()()()))(()()(()(((()(()())()()()))((()(()())))())(()(()))(())()())))()()()))()())(()(((((()))()()((((()()()()))()()(()((()))(()))))))))))()))()(()((((((())(()))()((())))(((((())))))(()))))()()(()()()(((((()))()())()((((()()))()(())())))(((()((())))))))))(()()()((()))(()())((())))()()((()())))()()(()))))))))()(((()(()))()())((((((())))(((()(()())())))(())())())()()((((()(()(((())(()()(((((()))(()(())()))))))()))()())))()()(()))(((()))()())))((())(((()()))((((((())))(((())()()(()((()))())(()((()()(((())())()))()()())())(()()((((((((())))()(((())(()))))()()())()(())))(((((()())(((())()()))))()((())())(())()(()(()()((()))()(()(((()))))()()())(())()()()(((()((()()()(()())())(())()(((((()())(())()((((()()()))()((())()((()(()(((()(()))()())())()())()(()()(()(((()))()(())(()())(())((())()((()()())(()))))()(()()))))((())()()((()((()()(()((()()())(())))))())))()))))(((((()(()())(()))((()))()(()())())())))()(()()(()((())))))()()))((())((((()))))())((()))())((())((()(()((()))()()()))()((((((())((((((()((((((((()))(()(((()(((((((((())(())())()())))))))())())))()))(()))))()(()))(())))()()()((()()))(())(()))(()()(()())))()(()()()()())))(())((((()))(((((())(()(((((())((()((((()))(((((()))(()())()))))())()))()(()()))((((()))()())(())))()((())))(((((()()((()()((()))))()((())())()))(((((((((()((())((((())()())))(())())()))())))())()))()(()()(()))(()()()((())((()))())))()(()())()(((((((()))))(()()()((()(())))())()))((())())(()(()(())()()())))))(()()()))())()))()())(((())(())))()(())())))()((()(()(())()()()((()))()))((())((((()((((((()()()))()))())())))))()(())(()())))()(((()())(((())))((())()()))((())())()()(()()())()))())(((()((()(((()())(()(())(((())))()))))))())()((((((()))))))()(()))()))())))())((((())(())()(())()))()))((((((((()()(())())((((())))((((()(())()()(())()))())()))(((()((()))()(((((()()()))))(()(()())))(((()(((()(())())((((())(()((()((()(()()(()()))()))()()))()))))))())()(())())))(((())))((()))((()(())())((())))((()))()))(((()))))(()())()())())()())))())))(())))(())())()((()())()()))((()()())(((((()())))())))()()()((((((())())()((())()))(()))()(()())()())(())()())((()((())(())()()()()((())(()())()()((())))()(((()(()(((((()(())))()(()))()(()))()))())()))()())()(()))))()()())(((())((()((())(()(()))()((()))))))(())(()(())())()()((())((())((((())))))(()()())(()()())(())())(((()()(())(())))()()))(())))))())(())()(((())())))((()(((())))(()((())()))()))((()()())()(((((())((((())))(())()()((()()(()()))(()((()))((())())))))))()())))())())((()(()()()()()))))()))((())(((((()())(()))((())))((()(())))))))))(((())(()(())(()(())((()((()))()((())())()())()((()(())())()(((()()((()(()())))))())((())(((()())(((()(()((())((()(((())(()()((((((()))())))())(()(()(()()())())((()))((())(())(())())))()(()())()))())(())((((())()((())))))(()()((())(((((()))()()))()()())(()(((()))())()()()))(((()()))(()(()((())(())))()()((((()()))()(())()())()()()()()(()()))(((())(((()()()((((((((((()()()(((()))))))())))()(((((((()((((((((()))()(((())())())())((((((()()))(()))()))))(())()())))())(()))(((())()()()((()()((())(()))((()(()())))()(()((()((())()()()()(())()()((())())())()()))()()))))((()()((())(((())(())())))((())())())(()))))())))))()((()(()(()))))()))((((())((())())(()))))()((()))(())((()()))()()((())(())())))(())))))()()(()())((()(())(((()((())))()())))()))()))))(())()(()))((()()()()))(())))(()()(())(((()(((()()))()((()))())()))(()(()))())))))))()((()(()))(((())())(())(()))(())(()((()))))))(()())(()()()(((()(((((()))((()))))(()))(())())(((()(()())(()()()()))())(()((()(()))()))())))(((()(()))))()))(()()((())())(()()())((()))(())))()()))(())))())))(()((())((()))((()))))())()()()((((((())((())()))(()))(())(())())))()())()((())))((()()())(()))(((()))())())))(())(())())()())()))((((()()()()))(())))((((())))(())(()((((()))())()))))))()()()))())))()((())))))((())())))()()(()()(()(()()()())((((())))(())(((())(()(()((((())(()()()(()(()((())(())(()())((((()((()((((((()((((())(((()())()((((()((())()(()(()(()((()()()(()(()())(((()(())(()(())(())(()))()((((((((()()(())))(()()(((())()(()(((((()())((()(())()())(((()(()(())()((((((((())()((()()((((())(((()(()((()((((()((((()(()(())())()(((()()))))))(()(((())()(((()())))((()))))(()()))))(()))))))((())())((())))()()()(()((()))()))()))()()()()()))(((((((()((()))((())()(()(()))()((((((((((((()(())))))(()())))()(()()(()(()()))))(((((()()((())()))())()()()))(())())()())()()((()()(()(()()(()))))))()()))(()()((()))))()((()()()())))(((()(((()()(())(())(()(((())(()((()(()))(()()((())()(()()())()))))))(()()((())((()())))(())(()))()(()))(()))()))()(())()(()())))(()))(()()(((()))))())))))((())())))))()()()))(()))((()())())()()))(((())((()((())()(()))()((()))()(())))))))()()())())))(()()(())(()))(())))))()(()))(()()))))))))((((()()()()()))(()))((()((())))(()())(((()()()(())))))()))()())())(()()()))))))((()())))((())))(())()((()))()(()())())))))(((()()(()(())()())(((((()))((()(())(())))))))()()))))))((()((((()()))()))(()()))(()()(())))))(((()()))(()())))(())()((()((()(((()()()()((()())())(()(((((((()((((())(()((((()()(())))))(()())))))(()())))())(())))((()(()))(()())(((())))((((())))))((()))()(((((((())())())((())))))))(()))))))))()((()()())((())))(())))((()(((()(())(())))()()()()))(())(()(())()())(())))()())((()((()((()()((())())))(()((())()()))()))((()()(()))(((((((()))((())((())((())()()((((((((()())()()()))(()()(((()(())()))()))()))()()(()(((((()))))((())(((()))()((((((((()()()()(()))()(()))()(())))))))()((((()()((()(())()((()))((()()(()()))))))))))(())(()))()()((((())))()((())(()((()((()(())()))()()((((()))))()))())))))())(((()()))()))()(()))(()))()((()((((((())())))()))()((())(()(())))))))()))(()()()())())()))((()))(()((()((()())))))((((())()()())(())())()((()((()())()())()(()))))((()())))()))()()))))()((())))())(()))()))(()((())(()))))()()))(()()((((()()))(((()()())(()(()(((()))())))((((()())()()()(())()()()((()))))((()()(()()))()())))(((((()(())())))))(()))))())))(())())()))))((()))))))(((())(((())()(((())))(()))()())(((()(()(((()))))()(()()(())())))))())())()()((())))()(())((()))((())(()())(()()()(()()())((())())))))((()(()())()()))))(()()(()()()(()()))((((((()))(()())(())(())())((())(()(()))((()()(()))))()))()(())))())))())(()((())))((())(()()()(()))((()((((((()())()()))))()))((()((())()))()((((()()()(((())())))()()()())())())(()())()))()(())(())()))())((()(((((()))(())(((((()))(()())(()(()(())()((()(()(()))()(()))))()(((())(()((((((()))(()(((()()())()())((()())))((()((()())()((((((())()))(()))))(()()()()))())())((((((((())((((()()()))(())()()))(()(()()(()(()))))(()))(()()()(())()()(())(()))())((()()((()(()))()))))())((()())())(((((()(()()))((()()()))()()(()(()(((()())(((((((((()))()())(()(()(())(((((()()))))(()())(()())())(())))))((()))())(((()((((()))()))(()(()(((()()(()(((()()))(())))((((()(()()))))((((()()())()))())()))))((())((((((())()()))()))()(((()((())(()((((()())())((((((((((()(((((()())()()(()))))))()((((())())(((()()((((()()())()(((((())))()))(())())(((()(((())()))()()()()(())))(()(((()(()))())))()(((()()()()()(()(((()(((()))()(())(())()()))()((()))))))()(((((()(()()((())(())((())))()(()())(())))())((())(()(()()(((())((()()(()()((()))))())))()(()))()))))))())())))((((((()())))(())(()))()()))()(())))))))((()))(()()()()))()())()()()()))()()())))))))((())(())))(()))(())((()())))(()(((()))((((())())))(())((())())))))(((()())(())()(())))((()()()((()(()))()))(())))((()(()()((()()()))((()))((()))()))(()())()()(((((((((()(()))()())()((())((((((((()(())()(((()((())()((((((((()))())))(()((()((())())())((()()())))(()(()((((((()))))((((())))((()()(())()())()()())(())(((()(()()(())(((())((((())()()(()()(((())()(())((()(()(((()(()())))()))((()()())(())))))(()(()))()))()(()))))(()((()))()())(())(())(()))((()())()))())()())((((()))))())())(((()))(((()()((()((())(())()()))))(((()((((()(((((((((())()()()(())((()(()()(()()(()()(())()())(((((()))))()(())(((()((((()())(()(((()))))()))())((((()()((()(()))))((())(())(()(()))()()(((()))(((((((((()())))((())()(()(((((((()))))))()()(())(((()(()())()()))((()()))((((()(())())))((()())))))()))))))))()()(((())())((()))())((())((()()))())((((((((())((()((())())))))()()))))))()()(())))))()))()()(((()))))(())((((()()()()))((()((((()()(())(((((()())()))))))())())()((((((((((()))()))((()))(())())(()(()(())((()()(()((())(())((((())(()()(()((()((()(((((()(()()((((())(())())(()()())()())((()(())()(())()))))"));
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
