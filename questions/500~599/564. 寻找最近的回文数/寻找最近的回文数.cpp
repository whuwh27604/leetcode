/* 寻找最近的回文数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数 n ，你需要找到与它最近的回文数（不包括自身）。

“最近的”定义为两个整数差的绝对值最小。

示例 1:

输入: "123"
输出: "121"
注意:

n 是由字符串表示的正整数，其长度不超过18。
如果有多个结果，返回最小的那个。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-closest-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        string nearest;
        long long diff = LLONG_MAX, num = stoll(n);

        // 在直接回文串、回文串中间数加1、回文串中间数减1中，必定有一个是答案。
        palindrome(n);
        long long number = stoll(n);
        if (number != num) {
            diff = abs(number - num);
            nearest = n;
        }

        string s = decrease(n);
        number = stoll(s);
        if (num - number <= diff) {
            diff = num - number;
            nearest = s;
        }

        s = increase(n);
        number = stoll(s);
        if (number - num < diff) {
            nearest = s;
        }

        return nearest;
    }

    void palindrome(string& n) {
        for (int i = 0, j = n.size() - 1; i < j; ++i, --j) {
            n[j] = n[i];
        }
    }

    string increase(string& n) {
        string s = n;
        int i, j, size = s.size(), mid = (size - 1) / 2, carrier = 1;

        for (i = mid, j = (size & 1) == 1 ? mid : mid + 1; carrier == 1 && j < size; --i, ++j) {
            if (s[i] == '9') {
                s[i] = '0';
                carrier = 1;
            }
            else {
                s[i] += 1;
                carrier = 0;
            }

            s[j] = s[i];
        }

        if (carrier == 1) {
            s[0] = '1';
            s += '1';
        }

        return s;
    }

    string decrease(string& n) {
        string s = n;
        int i, j, size = s.size(), mid = (size - 1) / 2, carrier = 1;

        for (i = mid, j = (size & 1) == 1 ? mid : mid + 1; carrier == 1 && j < size; --i, ++j) {
            if (s[i] == '0') {
                s[i] = '9';
                carrier = 1;
            }
            else {
                s[i] -= 1;
                carrier = 0;
            }

            s[j] = s[i];
        }

        if (size != 1 && s[0] == '0') {
            s[0] = '9';
            s.pop_back();
        }

        return s;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("121", o.nearestPalindromic("123"));
    check.checkString("0", o.nearestPalindromic("1"));
    check.checkString("4", o.nearestPalindromic("5"));
    check.checkString("8", o.nearestPalindromic("9"));
    check.checkString("9", o.nearestPalindromic("10"));
    check.checkString("9", o.nearestPalindromic("11"));
    check.checkString("101", o.nearestPalindromic("99"));
    check.checkString("99", o.nearestPalindromic("100"));
    check.checkString("99", o.nearestPalindromic("101"));
    check.checkString("1001", o.nearestPalindromic("999"));
    check.checkString("999", o.nearestPalindromic("1000"));
    check.checkString("999", o.nearestPalindromic("1001"));
    check.checkString("123456788887654321", o.nearestPalindromic("123456789123456789"));
    check.checkString("807045053350540708", o.nearestPalindromic("807045053224792883"));
    check.checkString("77", o.nearestPalindromic("88"));
    check.checkString("11111", o.nearestPalindromic("11011"));
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
