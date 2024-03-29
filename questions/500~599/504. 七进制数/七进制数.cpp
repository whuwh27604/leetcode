﻿/* 七进制数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数，将其转化为7进制，并以字符串形式输出。

示例 1:

输入: 100
输出: "202"
示例 2:

输入: -7
输出: "-10"
注意: 输入范围是 [-1e7, 1e7] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/base-7
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }

        string base7Num;

        if (num < 0) {
            num = -num;
            base7Num.push_back('-');
        }

        while (num != 0) {
            base7Num.push_back('0' + (num % 7));
            num /= 7;
        }

        auto iter = (base7Num[0] == '-' ? base7Num.begin() + 1 : base7Num.begin());
        reverse(iter, base7Num.end());

        return base7Num;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("202", o.convertToBase7(100));
    check.checkString("-10", o.convertToBase7(-7));
    check.checkString("0", o.convertToBase7(0));
    check.checkString("1", o.convertToBase7(1));
    check.checkString("6", o.convertToBase7(6));
    check.checkString("10", o.convertToBase7(7));
    check.checkString("16", o.convertToBase7(13));
    check.checkString("66", o.convertToBase7(48));
    check.checkString("100", o.convertToBase7(49));
    check.checkString("-1", o.convertToBase7(-1));
    check.checkString("-6", o.convertToBase7(-6));
    check.checkString("-10", o.convertToBase7(-7));
    check.checkString("-16", o.convertToBase7(-13));
    check.checkString("-66", o.convertToBase7(-48));
    check.checkString("-100", o.convertToBase7(-49));
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
