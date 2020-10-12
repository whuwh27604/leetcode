/* 验证IP地址.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址。

IPv4 地址由十进制数和点来表示，每个地址包含4个十进制数，其范围为 0 - 255， 用(".")分割。比如，172.16.254.1；

同时，IPv4 地址内的数不会以 0 开头。比如，地址 172.16.254.01 是不合法的。

IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过 (":")分割。比如,  2001:0db8:85a3:0000:0000:8a2e:0370:7334 是一个有效的地址。而且，我们可以加入一些以 0 开头的数字，字母可以使用大写，也可以是小写。所以， 2001:db8:85a3:0:0:8A2E:0370:7334 也是一个有效的 IPv6 address地址 (即，忽略 0 开头，忽略大小写)。

然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现 (::) 的情况。 比如， 2001:0db8:85a3::8A2E:0370:7334 是无效的 IPv6 地址。

同时，在 IPv6 地址中，多余的 0 也是不被允许的。比如， 02001:0db8:85a3:0000:0000:8a2e:0370:7334 是无效的。

说明: 你可以认为给定的字符串里没有空格或者其他特殊字符。

示例 1:

输入: "172.16.254.1"

输出: "IPv4"

解释: 这是一个有效的 IPv4 地址, 所以返回 "IPv4"。
示例 2:

输入: "2001:0db8:85a3:0:0:8A2E:0370:7334"

输出: "IPv6"

解释: 这是一个有效的 IPv6 地址, 所以返回 "IPv6"。
示例 3:

输入: "256.256.256.256"

输出: "Neither"

解释: 这个地址既不是 IPv4 也不是 IPv6 地址。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-ip-address
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        if ((IP.find('.') != IP.npos) && isValidIPv4Address(IP)) {
            return "IPv4";
        }

        if ((IP.find(':') != IP.npos) && isValidIPv6Address(IP)) {
            return "IPv6";
        }

        return "Neither";
    }

    bool isValidIPv4Address(string& IP) {
        int start = 0, end, size = IP.size(), num;

        for (int i = 0; i < 4; i++) {
            num = getV4Number(IP, start, end);
            if ((num < 0) || (num > 255)) {
                return false;
            }

            start = end + 1;
        }

        return end == size;
    }

    int getV4Number(string& IP, int start, int& end) {
        int num = 0, size = IP.size();
        if (start >= size) {
            return -1;
        }

        end = start;
        while ((IP[end] >= '0') && (IP[end] <= '9')) {
            if (end - start >= 3) {
                return -1;
            }

            num = num * 10 + IP[end++] - '0';

            if (end >= size) {
                break;
            }
        }

        if (start == end) {
            return -1;
        }

        if ((num != 0) && (IP[start] == '0')) {
            return -1;
        }

        if ((num == 0) && (end - start != 1)) {
            return -1;
        }

        if ((end != size) && (IP[end] != '.')) {
            return -1;
        }

        return num;
    }

    bool isValidIPv6Address(string& IP) {
        int start = 0, end, size = IP.size();

        for (int i = 0; i < 8; i++) {
            if (!isNumber(IP, start, end)) {
                return false;
            }

            start = end + 1;
        }

        return end == size;
    }

    bool isNumber(string& IP, int start, int& end) {
        int size = IP.size();
        if (start >= size) {
            return false;
        }

        end = start;
        while (((IP[end] >= '0') && (IP[end] <= '9')) || ((IP[end] >= 'a') && (IP[end] <= 'f')) || ((IP[end] >= 'A') && (IP[end] <= 'F'))) {
            if (end - start >= 4) {
                return false;
            }

            end++;
            if (end >= size) {
                break;
            }
        }

        if (start == end) {
            return false;
        }

        if ((end != size) && (IP[end] != ':')) {
            return false;
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("IPv4", o.validIPAddress("0.98.123.255"));
    check.checkString("IPv4", o.validIPAddress("0.0.0.0"));
    check.checkString("IPv4", o.validIPAddress("255.255.255.255"));
    check.checkString("Neither", o.validIPAddress(""));
    check.checkString("Neither", o.validIPAddress("1.1.1"));
    check.checkString("Neither", o.validIPAddress("1.1.1."));
    check.checkString("Neither", o.validIPAddress(".1.1.1"));
    check.checkString("Neither", o.validIPAddress("1.1.1.1234"));
    check.checkString("Neither", o.validIPAddress("1.-1.1.1"));
    check.checkString("Neither", o.validIPAddress("0.0.0.-0"));
    check.checkString("Neither", o.validIPAddress("1.256.1.1"));
    check.checkString("Neither", o.validIPAddress("1.1.1.1."));
    check.checkString("Neither", o.validIPAddress("1.1.1.1.1"));
    check.checkString("Neither", o.validIPAddress("0.00.000.0000"));
    check.checkString("Neither", o.validIPAddress("172.16.254.01"));
    check.checkString("Neither", o.validIPAddress("1.1..1.1"));
    check.checkString("Neither", o.validIPAddress("1.1:1.1"));
    check.checkString("IPv6", o.validIPAddress("2001:0db8:85a3:0000:0:8A2E:0370:733a"));
    check.checkString("Neither", o.validIPAddress("02001:0db8:85a3:0000:0:8A2E:0370:733a"));
    check.checkString("Neither", o.validIPAddress("2001:0db8:85a3::8A2E:0370:7334"));
    check.checkString("Neither", o.validIPAddress("1:1.1:1:1:1:1:1"));
    check.checkString("Neither", o.validIPAddress("1:1:1:1:1:1:1:1:"));
    check.checkString("Neither", o.validIPAddress("1:1:1:1:1:1:1:1:1"));
    check.checkString("Neither", o.validIPAddress("1:1:1:1:1:1:1"));
    check.checkString("Neither", o.validIPAddress("20EE:FGb8:85a3:0:0:8A2E:0370:7334"));
    check.checkString("Neither", o.validIPAddress("1081:db8:85a3:01:-0:8A2E:0370:7334"));
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
