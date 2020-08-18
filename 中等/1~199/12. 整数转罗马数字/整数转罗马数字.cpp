/* 整数转罗马数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

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
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:

输入: 3
输出: "III"
示例 2:

输入: 4
输出: "IV"
示例 3:

输入: 9
输出: "IX"
示例 4:

输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:

输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-to-roman
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        int n[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
        string c[13] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

        for (int i = 0; i < 13; i++) {
            while (num >= n[i]) {
                num -= n[i];
                roman += c[i];
            }
        }

        return roman;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("", o.intToRoman(0));
    check.checkString("I", o.intToRoman(1));
    check.checkString("II", o.intToRoman(2));
    check.checkString("III", o.intToRoman(3));
    check.checkString("IV", o.intToRoman(4));
    check.checkString("V", o.intToRoman(5));
    check.checkString("VI", o.intToRoman(6));
    check.checkString("IX", o.intToRoman(9));
    check.checkString("X", o.intToRoman(10));
    check.checkString("XI", o.intToRoman(11));
    check.checkString("XIV", o.intToRoman(14));
    check.checkString("XV", o.intToRoman(15));
    check.checkString("XVI", o.intToRoman(16));
    check.checkString("XLIX", o.intToRoman(49));
    check.checkString("L", o.intToRoman(50));
    check.checkString("LI", o.intToRoman(51));
    check.checkString("XCIX", o.intToRoman(99));
    check.checkString("C", o.intToRoman(100));
    check.checkString("CI", o.intToRoman(101));
    check.checkString("CDXCIX", o.intToRoman(499));
    check.checkString("D", o.intToRoman(500));
    check.checkString("DI", o.intToRoman(501));
    check.checkString("CMXCIX", o.intToRoman(999));
    check.checkString("M", o.intToRoman(1000));
    check.checkString("MI", o.intToRoman(1001));
    check.checkString("LVIII", o.intToRoman(58));
    check.checkString("MCMXCIV", o.intToRoman(1994));
    check.checkString("MMMCMXCIX", o.intToRoman(3999));
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
