/* 复数乘法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个表示复数的字符串。

返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。

示例 1:

输入: "1+1i", "1+1i"
输出: "0+2i"
解释: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
示例 2:

输入: "1+-1i", "1+-1i"
输出: "0+-2i"
解释: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。
注意:

输入字符串不包含额外的空格。
输入字符串将以 a+bi 的形式给出，其中整数 a 和 b 的范围均在 [-100, 100] 之间。输出也应当符合这种形式。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/complex-number-multiplication
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <sstream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int positon = a.find('+');
        string a1String(a, 0, positon);
        int a1 = getNumber(a1String);
        string b1String(a, positon + 1, a.size() - positon - 2);
        int b1 = getNumber(b1String);
        positon = b.find('+');
        string a2String(b, 0, positon);
        int a2 = getNumber(a2String);
        string b2String(b, positon + 1, b.size() - positon - 2);
        int b2 = getNumber(b2String);

        return to_string(a1 * a2 - b1 * b2) + "+" + to_string(a1 * b2 + a2 * b1) + "i";
    }

    int getNumber(string& s) {
        stringstream ss;
        ss << s;
        int number;
        ss >> number;
        return number;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("0+2i", o.complexNumberMultiply("1+1i", "1+1i"));
    check.checkString("0+-2i", o.complexNumberMultiply("1+-1i", "1+-1i"));
    check.checkString("3324+-968i", o.complexNumberMultiply("12+-34i", "56+78i"));
    check.checkString("-5+10i", o.complexNumberMultiply("1+2i", "3+4i"));
    check.checkString("3+6i", o.complexNumberMultiply("1+2i", "3+-0i"));
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
