/* 相等的有理数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个字符串 S 和 T，每个字符串代表一个非负有理数，只有当它们表示相同的数字时才返回 true；否则，返回 false。字符串中可以使用括号来表示有理数的重复部分。

通常，有理数最多可以用三个部分来表示：整数部分 <IntegerPart>、小数非重复部分 <NonRepeatingPart> 和小数重复部分 <(><RepeatingPart><)>。数字可以用以下三种方法之一来表示：

<IntegerPart>（例：0，12，123）
<IntegerPart><.><NonRepeatingPart> （例：0.5，2.12，2.0001）
<IntegerPart><.><NonRepeatingPart><(><RepeatingPart><)>（例：0.1(6)，0.9(9)，0.00(1212)）
十进制展开的重复部分通常在一对圆括号内表示。例如：

1 / 6 = 0.16666666... = 0.1(6) = 0.1666(6) = 0.166(66)

0.1(6) 或 0.1666(6) 或 0.166(66) 都是 1 / 6 的正确表示形式。

 

示例 1：

输入：S = "0.(52)", T = "0.5(25)"
输出：true
解释：因为 "0.(52)" 代表 0.52525252...，而 "0.5(25)" 代表 0.52525252525.....，则这两个字符串表示相同的数字。
示例 2：

输入：S = "0.1666(6)", T = "0.166(66)"
输出：true
示例 3：

输入：S = "0.9(9)", T = "1."
输出：true
解释：
"0.9(9)" 代表 0.999999999... 永远重复，等于 1 。[有关说明，请参阅此链接]
"1." 表示数字 1，其格式正确：(IntegerPart) = "1" 且 (NonRepeatingPart) = "" 。
 

提示：

每个部分仅由数字组成。
整数部分 <IntegerPart> 不会以 2 个或更多的零开头。（对每个部分的数字没有其他限制）。
1 <= <IntegerPart>.length <= 4
0 <= <NonRepeatingPart>.length <= 4
1 <= <RepeatingPart>.length <= 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/equal-rational-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isRationalEqual(string s, string t) {
        return getNumber(s) == getNumber(t);
    }

    string getNumber(string& s) {
        string num, nonRepeating, repeating;
        int i, size = s.size();

        for (i = 0; i < size && s[i] != '.'; ++i) {
            num += s[i];
        }

        for (i += 1; i < size && s[i] != '('; ++i) {
            nonRepeating += s[i];
        }

        for (i += 1; i < size && s[i] != ')'; ++i) {
            repeating += s[i];
        }

        if (repeating.empty()) {
            repeating = '0';
        }

        if (repeating == string(repeating.size(), '9')) {
            repeating = '0';

            while (!nonRepeating.empty() && nonRepeating.back() == '9') {
                nonRepeating.pop_back();
            }

            if (nonRepeating.empty()) {
                num = to_string(stoi(num) + 1);
            }
            else {
                nonRepeating.back() += 1;
            }
        }
        
        num += ('.' + nonRepeating);

        while (num.size() < 20) {
            num += repeating;
        }

        return num.size() >= 20 ? string(num, 0, 20) : num;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isRationalEqual("0.(52)", "0.5(25)"));
    check.checkBool(true, o.isRationalEqual("0.1666(6)", "0.166(66)"));
    check.checkBool(true, o.isRationalEqual("0.9(9)", "1."));
    check.checkBool(true, o.isRationalEqual("1.(9)", "2"));
    check.checkBool(true, o.isRationalEqual("1.(9)", "2.0"));
    check.checkBool(false, o.isRationalEqual("1.9999", "2.0"));
    check.checkBool(true, o.isRationalEqual("9999.9999(9999)", "10000"));
    check.checkBool(true, o.isRationalEqual("0.(00)", "0.0"));
    check.checkBool(true, o.isRationalEqual("2.00", "2.0"));
    check.checkBool(true, o.isRationalEqual("2.10", "2.1(0)"));
    check.checkBool(true, o.isRationalEqual("2.0(9)", "2.1"));
    check.checkBool(true, o.isRationalEqual("2.199(9)", "2.2"));
    check.checkBool(true, o.isRationalEqual("2.01099(9)", "2.011"));
    check.checkBool(false, o.isRationalEqual("99", "9.9"));
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
