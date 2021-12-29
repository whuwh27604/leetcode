﻿/* 判断一个括号字符串是否有效.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个括号字符串是只由 '(' 和 ')' 组成的 非空 字符串。如果一个字符串满足下面 任意 一个条件，那么它就是有效的：

字符串为 ().
它可以表示为 AB（A 与 B 连接），其中A 和 B 都是有效括号字符串。
它可以表示为 (A) ，其中 A 是一个有效括号字符串。
给你一个括号字符串 s 和一个字符串 locked ，两者长度都为 n 。locked 是一个二进制字符串，只包含 '0' 和 '1' 。对于 locked 中 每一个 下标 i ：

如果 locked[i] 是 '1' ，你 不能 改变 s[i] 。
如果 locked[i] 是 '0' ，你 可以 将 s[i] 变为 '(' 或者 ')' 。
如果你可以将 s 变为有效括号字符串，请你返回 true ，否则返回 false 。

 

示例 1：



输入：s = "))()))", locked = "010100"
输出：true
解释：locked[1] == '1' 和 locked[3] == '1' ，所以我们无法改变 s[1] 或者 s[3] 。
我们可以将 s[0] 和 s[4] 变为 '(' ，不改变 s[2] 和 s[5] ，使 s 变为有效字符串。
示例 2：

输入：s = "()()", locked = "0000"
输出：true
解释：我们不需要做任何改变，因为 s 已经是有效字符串了。
示例 3：

输入：s = ")", locked = "0"
输出：false
解释：locked 允许改变 s[0] 。
但无论将 s[0] 变为 '(' 或者 ')' 都无法使 s 变为有效字符串。
 

提示：

n == s.length == locked.length
1 <= n <= 105
s[i] 要么是 '(' 要么是 ')' 。
locked[i] 要么是 '0' 要么是 '1' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-a-parentheses-string-can-be-valid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int i, size = s.size(), count = 0;

        if ((size & 1) == 1) {  // 奇数肯定失败
            return false;
        }

        for (i = 0; i < size; ++i) {  // 正向检查多余的右括号是否可以变为左括号
            if (s[i] == '(' || locked[i] == '0') {  // 如果是左括号、或者是右括号但可以将它变为左括号则改变它
                ++count;
            }
            else {
                if (count > 0) {  // 必须匹配的右括号，计数减1
                    --count;
                }
                else {  // 右括号过多，已无法平衡
                    return false;
                }
            }
        }

        count = 0;

        for (i = size - 1; i >= 0; --i) {  // 反向检查多余的左括号是否可以变为右括号
            if (s[i] == ')' || locked[i] == '0') {  // 如果是右括号、或者是左括号但可以将它变为右括号则改变它
                ++count;
            }
            else {
                if (count > 0) {  // 必须匹配的左括号，计数减1
                    --count;
                }
                else {  // 左括号过多，已无法平衡
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.canBeValid("))()))", "010100"));
    check.checkBool(true, o.canBeValid("()()", "0000"));
    check.checkBool(false, o.canBeValid(")", "0"));
    check.checkBool(true, o.canBeValid("(()(((", "111100"));
    check.checkBool(true, o.canBeValid(")(", "00"));
    check.checkBool(false, o.canBeValid("(()))()))(()((()()(((()))()()()()()())))()()(()())()(()((()()((()((((((()(()()(()()())(((((())((()))))()(((((((()()())()))())((((((()(())())()((())()()((())((((())(((())(())()()))(((()()())())))((()))))()()()((()))())(())(((()()((())(())(())())()((()))())(())()(()())((((()(((())((()()())(((()(((((()))()))))))(()((())())(())))))(())(((())()()(()))())())))(((())))()()))()())))))())()(()()))(())(()())))())()))((((())(()))()(((())())(()(()))()))((()(())()()))))())(()(((((()", "110001111001011100000100011110101000100110010010011001110010111111100111000100000000101111101001111111011101001110011001001100100001100000000010100010101101100000100001000110111000111110110010111011010010100011111101110011100010010001111001010001001000111101101111111011001000100111100110101000100011011001001100110011111111111100101000100111111100000100101101000101111101000011110001001011111010011010000100100000000011101011001110000110011000100001110101100101111111110100"));
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
