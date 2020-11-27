/* 数字转换为十六进制数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。

注意:

十六进制中所有字母(a-f)都必须是小写。
十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
给定的数确保在32位有符号整数范围内。
不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
示例 1：

输入:
26

输出:
"1a"
示例 2：

输入:
-1

输出:
"ffffffff"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string toHex(int num) {
        string hexString;
        if (num == 0) {
            hexString.push_back('0');
            return hexString;
        }

        char table[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
        unsigned int unsignedNum = (unsigned int)num;
        while (unsignedNum != 0) {
            unsigned int remainder = (unsignedNum % 16);
            hexString.insert(0, 1, table[remainder]);
            unsignedNum /= 16;
        }

        return hexString;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string expected = "0";
    check.checkString(expected, o.toHex(0));

    expected = "1";
    check.checkString(expected, o.toHex(1));

    expected = "f";
    check.checkString(expected, o.toHex(15));

    expected = "10";
    check.checkString(expected, o.toHex(16));

    expected = "1a";
    check.checkString(expected, o.toHex(26));

    expected = "7fffffff";
    check.checkString(expected, o.toHex(INT_MAX));

    expected = "ffffffff";
    check.checkString(expected, o.toHex(-1));

    expected = "fffffff1";
    check.checkString(expected, o.toHex(-15));

    expected = "fffffff0";
    check.checkString(expected, o.toHex(-16));

    expected = "ffffffef";
    check.checkString(expected, o.toHex(-17));

    expected = "80000000";
    check.checkString(expected, o.toHex(INT_MIN));
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
