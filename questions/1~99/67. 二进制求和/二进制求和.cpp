/* 二进制求和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

 

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
 

提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = a.size() - 1;
        int lenB = b.size() - 1;
        bool addOne = false;
        char sum;
        string reverseSum;

        do {
            sum = addChar(a[lenA], b[lenB], addOne);
            reverseSum.push_back(sum);

            lenA--;
            lenB--;
        }while ((lenA >= 0) && (lenB >= 0));

        while (lenA >= 0) {
            sum = addChar(a[lenA], '0', addOne);
            reverseSum.push_back(sum);

            lenA--;
        }

        while (lenB >= 0) {
            sum = addChar('0', b[lenB], addOne);
            reverseSum.push_back(sum);

            lenB--;
        }

        if (addOne) {
            reverseSum.push_back('1');
        }

        reverse(reverseSum.begin(), reverseSum.end());
        return reverseSum;
    }

    char addChar(char a, char b, bool& addOne) {
        if (!addOne) {
            if (a == '1') {
                if (b == '1') {
                    addOne = true;
                    return '0';
                }
                return '1';
            }
            return b;
        }

        if (a == '0') {
            if (b == '0') {
                addOne = false;
                return '1';
            }
            return '0';
        }
        return b;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string a = "11";
    string b = "1";
    string actual = o.addBinary(a, b);
    string expected = "100";
    check.checkString(expected, actual);

    a = "1010";
    b = "1011";
    actual = o.addBinary(a, b);
    expected = "10101";
    check.checkString(expected, actual);

    a = "0";
    b = "1011";
    actual = o.addBinary(a, b);
    expected = "1011";
    check.checkString(expected, actual);

    a = "1111";
    b = "11111";
    actual = o.addBinary(a, b);
    expected = "101110";
    check.checkString(expected, actual);

    a = "0";
    b = "0";
    actual = o.addBinary(a, b);
    expected = "0";
    check.checkString(expected, actual);

    a = "1";
    b = "0";
    actual = o.addBinary(a, b);
    expected = "1";
    check.checkString(expected, actual);
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
