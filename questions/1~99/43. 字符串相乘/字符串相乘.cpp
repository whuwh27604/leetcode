/* 字符串相乘.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if ((num1 == "0") || (num2 == "0")) {
            return "0";
        }

        vector<int> a, b;
        string2Vector(num1, a);
        string2Vector(num2, b);

        vector<int> ab;
        multiply(a, b, ab);

        string product;
        vector2String(ab, product);

        return product;
    }

    void string2Vector(string& num, vector<int>& number) {
        for (char c : num) {
            number.push_back(c - '0');
        }
    }

    void vector2String(vector<int>& num, string& s) {
        for (int i = (num[0] == 0 ? 1 : 0); i < (int)num.size(); i++) {
            s.push_back('0' + num[i]);
        }
    }

    void multiply(vector<int>& a, vector<int>& b, vector<int>& ab) {
        int i, j, size1 = a.size(), size2 = b.size();
        ab.insert(ab.begin(), size1 + size2, 0);
        int start = size1 + size2 - 1, index, carrier;

        for (j = size2 - 1; j >= 0; j--) {
            index = start--;
            carrier = 0;
            for (i = size1 - 1; i >= 0; i--) {
                ab[index] += (a[i] * b[j] + carrier);
                carrier = ab[index] / 10;
                ab[index--] %= 10;
            }

            ab[index] = carrier;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("0", o.multiply("1", "0"));
    check.checkString("6", o.multiply("2", "3"));
    check.checkString("56088", o.multiply("123", "456"));
    check.checkString("96", o.multiply("8", "12"));
    check.checkString("104", o.multiply("8", "13"));
    check.checkString("9999", o.multiply("1", "9999"));
    check.checkString("23999895", o.multiply("243", "98765"));
    check.checkString("315587694", o.multiply("468231", "674"));
    check.checkString("121932631112635269", o.multiply("123456789", "987654321"));
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
