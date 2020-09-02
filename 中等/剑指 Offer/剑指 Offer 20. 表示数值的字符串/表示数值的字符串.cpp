/* 表示数值的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
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
    Solution o;
    CheckResult check;

    check.checkBool(true, o.isNumber("+100"));
    check.checkBool(true, o.isNumber("5e2"));
    check.checkBool(true, o.isNumber("-123"));
    check.checkBool(true, o.isNumber("3.1416"));
    check.checkBool(true, o.isNumber("3."));
    check.checkBool(true, o.isNumber("-1E-16"));
    check.checkBool(true, o.isNumber("0123"));
    check.checkBool(false, o.isNumber("1a3.14"));
    check.checkBool(false, o.isNumber("12e"));
    check.checkBool(false, o.isNumber("1.2.3"));
    check.checkBool(false, o.isNumber("+-5"));
    check.checkBool(false, o.isNumber("12e+5.4"));
    check.checkBool(false, o.isNumber(""));
    check.checkBool(false, o.isNumber(" "));
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
