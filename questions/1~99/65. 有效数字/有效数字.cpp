/* 有效数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有效数字（按顺序）可以分成以下几个部分：

一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分有效数字列举如下：

["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
部分无效数字列举如下：

["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。

 

示例 1：

输入：s = "0"
输出：true
示例 2：

输入：s = "e"
输出：false
示例 3：

输入：s = "."
输出：false
示例 4：

输入：s = ".1"
输出：true
 

提示：

1 <= s.length <= 20
s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，或者点 '.' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Solution() {
        transfer[State::STATE_INITIAL] = { {CharType::CHAR_SPACE, State::STATE_INITIAL},
                                           {CharType::CHAR_NUMBER, State::STATE_INTEGER},
                                           {CharType::CHAR_POINT, State::STATE_POINT_WITHOUT_INT},
                                           {CharType::CHAR_SIGN, State::STATE_INT_SIGN} };

        transfer[State::STATE_INT_SIGN] = { {CharType::CHAR_NUMBER, State::STATE_INTEGER},
                                            {CharType::CHAR_POINT, State::STATE_POINT_WITHOUT_INT} };

        transfer[State::STATE_INTEGER] = { {CharType::CHAR_NUMBER, State::STATE_INTEGER},
                                           {CharType::CHAR_EXP, State::STATE_EXP},
                                           {CharType::CHAR_POINT, State::STATE_POINT},
                                           {CharType::CHAR_SPACE, State::STATE_END} };

        transfer[State::STATE_POINT] = { {CharType::CHAR_NUMBER, State::STATE_FRACTION},
                                         {CharType::CHAR_EXP, State::STATE_EXP},
                                         {CharType::CHAR_SPACE, State::STATE_END} };

        transfer[State::STATE_POINT_WITHOUT_INT] = { {CharType::CHAR_NUMBER, State::STATE_FRACTION} };

        transfer[State::STATE_FRACTION] = { {CharType::CHAR_NUMBER, State::STATE_FRACTION},
                                            {CharType::CHAR_EXP, State::STATE_EXP},
                                            {CharType::CHAR_SPACE, State::STATE_END} };

        transfer[State::STATE_EXP] = { {CharType::CHAR_NUMBER, State::STATE_EXP_NUMBER},
                                       {CharType::CHAR_SIGN, State::STATE_EXP_SIGN} };

        transfer[State::STATE_EXP_SIGN] = { {CharType::CHAR_NUMBER, State::STATE_EXP_NUMBER} };

        transfer[State::STATE_EXP_NUMBER] = { {CharType::CHAR_NUMBER, State::STATE_EXP_NUMBER},
                                              {CharType::CHAR_SPACE, State::STATE_END} };

        transfer[State::STATE_END] = { {CharType::CHAR_SPACE, State::STATE_END} };
    }

    bool isNumber(string s) {
        State state = State::STATE_INITIAL;

        for (char c : s) {
            CharType ct = toCharType(c);
            auto iter = transfer[state].find(ct);
            if (iter == transfer[state].end()) {
                return false;
            }

            state = iter->second;
        }

        return ((state == State::STATE_INTEGER)
            || (state == State::STATE_POINT)
            || (state == State::STATE_FRACTION)
            || (state == State::STATE_EXP_NUMBER)
            || (state == State::STATE_END));
    }

private:
    enum class State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END
    };

    enum class CharType {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL
    };

    unordered_map<State, unordered_map<CharType, State>> transfer;

    CharType toCharType(char ch) {
        if (ch >= '0' && ch <= '9') {
            return CharType::CHAR_NUMBER;
        }
        else if (ch == 'e' || ch == 'E') {
            return CharType::CHAR_EXP;
        }
        else if (ch == '.') {
            return CharType::CHAR_POINT;
        }
        else if (ch == '+' || ch == '-') {
            return CharType::CHAR_SIGN;
        }
        else if (ch == ' ') {
            return CharType::CHAR_SPACE;
        }
        else {
            return CharType::CHAR_ILLEGAL;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isNumber("2"));
    check.checkBool(true, o.isNumber("0089"));
    check.checkBool(true, o.isNumber("-0.1"));
    check.checkBool(true, o.isNumber("+3.14"));
    check.checkBool(true, o.isNumber("4."));
    check.checkBool(true, o.isNumber("-.9"));
    check.checkBool(true, o.isNumber("2e10"));
    check.checkBool(true, o.isNumber("-90E3"));
    check.checkBool(true, o.isNumber("3e+7"));
    check.checkBool(true, o.isNumber("+6e-1"));
    check.checkBool(true, o.isNumber("53.5e93"));
    check.checkBool(true, o.isNumber("-123.456e789"));
    check.checkBool(true, o.isNumber("0"));
    check.checkBool(true, o.isNumber(".1"));
    check.checkBool(false, o.isNumber("abc"));
    check.checkBool(false, o.isNumber("1a"));
    check.checkBool(false, o.isNumber("1e"));
    check.checkBool(false, o.isNumber("e3"));
    check.checkBool(false, o.isNumber("99e2.5"));
    check.checkBool(false, o.isNumber("--6"));
    check.checkBool(false, o.isNumber("-+3"));
    check.checkBool(false, o.isNumber("95a54e53"));
    check.checkBool(false, o.isNumber("e"));
    check.checkBool(false, o.isNumber("."));
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
