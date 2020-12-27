/* 验证回文字符串 Ⅱ.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True
示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。
注意:

字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        unsigned int len = s.size();
        for (unsigned int i = 0; i < (len / 2); i++) {
            if (s[i] == s[len - 1 - i]) {
                continue;
            }

            if (isPalindrome(s, (i + 1), (len - 1 - i))) {
                return true;
            }

            return (isPalindrome(s, i, (len - 1 - i - 1)));
        }

        return true;
    }

    bool isPalindrome(string& s, int indexHead, int indexTail) {
        while (indexHead < indexTail) {
            if (s[indexHead] != s[indexTail]) {
                return false;
            }

            indexHead++;
            indexTail--;
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.validPalindrome("aba"));
    check.checkBool(true, o.validPalindrome("abca"));
    check.checkBool(true, o.validPalindrome("a"));
    check.checkBool(true, o.validPalindrome("ab"));
    check.checkBool(false, o.validPalindrome("abc"));
    check.checkBool(true, o.validPalindrome("aabcdcba"));
    check.checkBool(true, o.validPalindrome("abcdcbaa"));
    check.checkBool(true, o.validPalindrome("abcxdcba"));
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
