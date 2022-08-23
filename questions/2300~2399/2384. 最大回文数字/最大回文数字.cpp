/* 最大回文数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个仅由数字（0 - 9）组成的字符串 num 。

请你找出能够使用 num 中数字形成的 最大回文 整数，并以字符串形式返回。该整数不含 前导零 。

注意：

你 无需 使用 num 中的所有数字，但你必须使用 至少 一个数字。
数字可以重新排序。
 

示例 1：

输入：num = "444947137"
输出："7449447"
解释：
从 "444947137" 中选用数字 "4449477"，可以形成回文整数 "7449447" 。
可以证明 "7449447" 是能够形成的最大回文整数。
示例 2：

输入：num = "00009"
输出："9"
解释：
可以证明 "9" 能够形成的最大回文整数。
注意返回的整数不应含前导零。
 

提示：

1 <= num.length <= 105
num 由数字（0 - 9）组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/largest-palindromic-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        int size = num.size();
        string half1, half2;
        vector<int> count('9' + 1, 0);

        for (char n : num) {
            ++count[n];
        }

        for (char digit = '9'; digit > '0'; --digit) {
            half1 += string(count[digit] / 2, digit);
        }

        if (!half1.empty()) {
            half1 += string(count['0'] / 2, '0');
        }

        half2 = half1;
        reverse(half2.begin(), half2.end());

        for (char digit = '9'; digit >= '0'; --digit) {
            if ((count[digit] % 2) != 0) {
                half1 += digit;
                break;
            }
        }

        string ans = half1 + half2;
        return ans.empty() ? "0" : ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("7449447", o.largestPalindromic("444947137"));
    check.checkString("9", o.largestPalindromic("00009"));
    check.checkString("0", o.largestPalindromic("0"));
    check.checkString("99", o.largestPalindromic("99"));
    check.checkString("999", o.largestPalindromic("999"));
    check.checkString("91019", o.largestPalindromic("91019"));
    check.checkString("9100019", o.largestPalindromic("9100019"));
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
