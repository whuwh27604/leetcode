/* 罗马数字转整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:

输入: "III"
输出: 3
示例 2:

输入: "IV"
输出: 4
示例 3:

输入: "IX"
输出: 9
示例 4:

输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
示例 5:

输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/roman-to-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include "../check/CheckResult.h"

using namespace std;

class romanChar {
public:
    char preChar;
    romanChar(char pre) {
        preChar = pre;
    }
    virtual int value() = 0;
};

class romanCharI : public romanChar {
public:
    romanCharI(char pre) : romanChar(pre) {};

    int value() {
        return 1;
    }
};

class romanCharV : public romanChar {
public:
    romanCharV(char pre) : romanChar(pre) {};

    int value() {
        if (preChar == 'I') {
            return 3;
        }
        return 5;
    }
};

class romanCharX : public romanChar {
public:
    romanCharX(char pre) : romanChar(pre) {};

    int value() {
        if (preChar == 'I') {
            return 8;
        }
        return 10;
    }
};

class romanCharL : public romanChar {
public:
    romanCharL(char pre) : romanChar(pre) {};

    int value() {
        if (preChar == 'X') {
            return 30;
        }
        return 50;
    }
};

class romanCharC : public romanChar {
public:
    romanCharC(char pre) : romanChar(pre) {};

    int value() {
        if (preChar == 'X') {
            return 80;
        }
        return 100;
    }
};

class romanCharD : public romanChar {
public:
    romanCharD(char pre) : romanChar(pre) {};

    int value() {
        if (preChar == 'C') {
            return 300;
        }
        return 500;
    }
};

class romanCharM : public romanChar {
public:
    romanCharM(char pre) : romanChar(pre) {};

    int value() {
        if (preChar == 'C') {
            return 800;
        }
        return 1000;
    }
};

class Solution {
public:
    int romanToInt(string s) {
        int number = 0;
        char preChar = 'A';
        romanChar* character = NULL;

        for (unsigned int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case 'I':
                    character = new romanCharI(preChar);
                    break;
                case 'V':
                    character = new romanCharV(preChar);
                    break;
                case 'X':
                    character = new romanCharX(preChar);
                    break;
                case 'L':
                    character = new romanCharL(preChar);
                    break;
                case 'C':
                    character = new romanCharC(preChar);
                    break;
                case 'D':
                    character = new romanCharD(preChar);
                    break;
                case 'M':
                    character = new romanCharM(preChar);
                    break;
                default:
                    delete character;
                    return 0;
            }

            preChar = s[i];
            number += character->value();
            delete character;
        }

        return number;
    }
};

int main()
{
    Solution o;
    CheckResult result;
    string s = "III";
    result.checkInt(3, o.romanToInt(s));
    s = "IV";
    result.checkInt(4, o.romanToInt(s));
    s = "IX";
    result.checkInt(9, o.romanToInt(s));
    s = "LVIII";
    result.checkInt(58, o.romanToInt(s));
    s = "MCMXCIV";
    result.checkInt(1994, o.romanToInt(s));
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
