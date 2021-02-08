/* 数字 1 的个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。

 

示例 1：

输入：n = 13
输出：6
示例 2：

输入：n = 0
输出：0
 

提示：

0 <= n <= 2 * 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-digit-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n == 0) {
            return 0;
        }

        vector<int> section = { 1,20,300,4000,50000,600000,7000000,80000000,900000000 };
        vector<int> digits;
        num2Vector(n, digits);

        return countDigit(n, digits, digits.size() - 1, section);
    }

    void num2Vector(int n, vector<int>& digits) {
        while (n != 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
    }

    int countDigit(int n, vector<int>& digits, int start, vector<int>& section) {
        int firstDigit = digits[start], base = (int)pow(10, start);

        if (start == 0) {
            return firstDigit == 0 ? 0 : 1;
        }

        if (firstDigit == 0) {
            return countDigit(n, digits, --start, section);
        }

        int count = section[start - 1];  // 前一段全部1的个数
        count += firstDigit == 1 ? (n - base + 1) : base;  // 本段最高位1的个数
        count += (firstDigit - 1) * section[start - 1];  // 本段除最高位1外完整区间1的个数
        count += countDigit(n - firstDigit * base, digits, --start, section);  // 本段除最高位1外最后不完整区间1的个数

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.countDigitOne(0));
    check.checkInt(1, o.countDigitOne(1));
    check.checkInt(1, o.countDigitOne(2));
    check.checkInt(2, o.countDigitOne(10));
    check.checkInt(6, o.countDigitOne(13));
    check.checkInt(154, o.countDigitOne(234));
    check.checkInt(300, o.countDigitOne(999));
    check.checkInt(4000, o.countDigitOne(9999));
    check.checkInt(21, o.countDigitOne(100));
    check.checkInt(23, o.countDigitOne(101));
    check.checkInt(36, o.countDigitOne(111));
    check.checkInt(260000000, o.countDigitOne(200000000));
    check.checkInt(900000001, o.countDigitOne(1000000000));
    check.checkInt(84252133, o.countDigitOne(102030105));
    check.checkInt(767944060, o.countDigitOne(824883294));
    check.checkInt(900000000, o.countDigitOne(999999999));
    check.checkInt(1737167499, o.countDigitOne(1410065408));
    check.checkInt(2147483646, o.countDigitOne(1633388154));
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
