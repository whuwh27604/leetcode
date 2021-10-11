/* 整数转换英文表示.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
将非负整数 num 转换为其对应的英文表示。

 

示例 1：

输入：num = 123
输出："One Hundred Twenty Three"
示例 2：

输入：num = 12345
输出："Twelve Thousand Three Hundred Forty Five"
示例 3：

输入：num = 1234567
输出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
示例 4：

输入：num = 1234567891
输出："One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
 

提示：

0 <= num <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-to-english-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        string number;

        if (num == 0) {
            return "Zero";
        }

        int billion = num / 1000000000;
        if (billion != 0) {
            number += words[billion];
            number += "Billion ";
        }

        num %= 1000000000;
        int million = num / 1000000;
        if (million != 0) {
            addNum(number, million);
            number += "Million ";
        }

        num %= 1000000;
        int thousand = num / 1000;
        if (thousand != 0) {
            addNum(number, thousand);
            number += "Thousand ";
        }

        num %= 1000;
        if (num != 0) {
            addNum(number, num);
        }

        number.pop_back();
        return number;
    }

    void addNum(string& number, int num) {
        int hundred = num / 100;
        if (hundred != 0) {
            number += words[hundred];
            number += "Hundred ";
        }

        num %= 100;
        int ty = num / 10;
        if (ty == 1) {
            number += words[num];
        }
        else {
            if (ty > 1) {
                number += words[ty * 10];
            }

            num %= 10;
            if (num != 0) {
                number += words[num];
            }
        }
    }

private:
    unordered_map<int, string> words = { {1,"One "},{2,"Two "},{3,"Three "},{4,"Four "},{5,"Five "},
            {6,"Six "},{7,"Seven "},{8,"Eight "},{9,"Nine "},{10,"Ten "},{11,"Eleven "},{12,"Twelve "},{13,"Thirteen "},{14,"Fourteen "},
            {15,"Fifteen "},{16,"Sixteen "},{17,"Seventeen "},{18,"Eighteen "},{19,"Nineteen "},{20,"Twenty "},{30,"Thirty "},{40,"Forty "},
            {50,"Fifty "},{60,"Sixty "},{70,"Seventy "},{80,"Eighty "},{90,"Ninety "} };
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("One Hundred Twenty Three", o.numberToWords(123));
    check.checkString("Twelve Thousand Three Hundred Forty Five", o.numberToWords(12345));
    check.checkString("One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven", o.numberToWords(1234567));
    check.checkString("One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One", o.numberToWords(1234567891));
    check.checkString("Zero", o.numberToWords(0));
    check.checkString("One Hundred Eight", o.numberToWords(108));
    check.checkString("One Hundred Eighteen", o.numberToWords(118));
    check.checkString("One Billion One Hundred One Thousand", o.numberToWords(1000101000));
    check.checkString("One Hundred Twenty Three", o.numberToWords(123));
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
