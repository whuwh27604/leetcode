/* 最长回文子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int i, len = s.size(), left1, right1, left2, right2, left;
        int palindromeLen1, palindromeLen2, palindromeLen, maxPalindromeLen = 0;
        string maxPalindrome;

        if (len == 1) {
            return s;
        }

        for (i = 0; i < len - 1; i++) {
            left1 = i - 1;
            right1 = i + 1;
            while ((left1 >= 0) && (right1 < len) && (s[left1] == s[right1])) {
                left1--;
                right1++;
            }
            palindromeLen1 = right1 - left1 - 1;

            if (s[i] != s[i + 1]) {
                palindromeLen2 = 0;
            }
            else {
                left2 = i - 1;
                right2 = i + 2;
                while ((left2 >= 0) && (right2 < len) && (s[left2] == s[right2])) {
                    left2--;
                    right2++;
                }
                palindromeLen2 = right2 - left2 - 1;
            }

            if (palindromeLen1 > palindromeLen2) {
                palindromeLen = palindromeLen1;
                left = left1;
            }
            else {
                palindromeLen = palindromeLen2;
                left = left2;
            }

            if (palindromeLen > maxPalindromeLen) {
                maxPalindromeLen = palindromeLen;
                maxPalindrome.clear();
                maxPalindrome.append(s, left + 1, palindromeLen);
            }
        }

        return maxPalindrome;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("bab", o.longestPalindrome("babad"));
    check.checkString("bb", o.longestPalindrome("cbbd"));
    check.checkString("a", o.longestPalindrome("a"));
    check.checkString("aa", o.longestPalindrome("aa"));
    check.checkString("aaa", o.longestPalindrome("aaa"));
    check.checkString("aaa", o.longestPalindrome("baaa"));
    check.checkString("aaa", o.longestPalindrome("aaab"));
    check.checkString("abcba", o.longestPalindrome("dabcba"));
    check.checkString("abcba", o.longestPalindrome("abcbad"));
    check.checkString("abccba", o.longestPalindrome("dabccba"));
    check.checkString("abccba", o.longestPalindrome("abccbad"));

    string s1(999, 'a');
    string s2 = s1;
    s2 += 'b';
    check.checkString(s1, o.longestPalindrome(s2));
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
