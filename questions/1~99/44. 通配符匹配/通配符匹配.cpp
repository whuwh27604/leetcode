/* 通配符匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。
示例 3:

输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
示例 4:

输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
示例 5:

输入:
s = "acdcb"
p = "a*c?b"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/wildcard-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        // 掐头去尾，使p变为*P1*P2*P3*...Pn*模式
        int sStart = 0, sEnd = (int)s.size() - 1, pStart = 0, pEnd = (int)p.size() - 1;
        while ((sStart <= sEnd) && (pStart <= pEnd) && (p[pStart] != '*')) {
            if ((p[pStart] != '?') && (s[sStart] != p[pStart])) {
                return false;
            }
            sStart++;
            pStart++;
        }
        if (pStart > pEnd) {
            return sStart > sEnd;
        }
        if (sStart > sEnd) {
            while (pStart <= pEnd) {
                if (p[pStart++] != '*') {
                    return false;
                }
            }
            return true;
        }

        while ((sEnd >= sStart) && (p[pEnd] != '*')) {
            if ((p[pEnd] != '?') && (s[sEnd] != p[pEnd])) {
                return false;
            }
            sEnd--;
            pEnd--;
        }
        if (sStart > sEnd) {
            while (pEnd > pStart) {
                if (p[pEnd--] != '*') {
                    return false;
                }
            }
            return true;
        }

        // 贪心搜索P1、P2...Pn，如果第一次出现的Px无法完成全部匹配，后面的Px更加没有可能
        while (pStart < pEnd) {
            if (p[pStart] == '*') {
                pStart++;
            }
            else {
                if (!findPx(s, p, sStart, sEnd, pStart)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool findPx(string& s, string& p, int& sStart, int sEnd, int& pStart) {
        while (sStart <= sEnd) {
            int sIndex = sStart++, pIndex = pStart;

            while ((s[sIndex] == p[pIndex]) || (p[pIndex] == '?')) {
                sIndex++;
                pIndex++;
                if (p[pIndex] == '*') {
                    sStart = sIndex;
                    pStart = pIndex;
                    return true;
                }
                if (sIndex > sEnd) {
                    return false;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.isMatch("", ""));
    check.checkBool(false, o.isMatch("a", ""));
    check.checkBool(true, o.isMatch("", "*"));
    check.checkBool(true, o.isMatch("", "***"));
    check.checkBool(false, o.isMatch("", "a"));
    check.checkBool(false, o.isMatch("", "*a*"));
    check.checkBool(false, o.isMatch("", "*?*"));
    check.checkBool(true, o.isMatch("abcde", "a*c*e"));
    check.checkBool(true, o.isMatch("abcde", "a*?*e"));
    check.checkBool(true, o.isMatch("abcdefghijklmnopq", "a*cd*fgh*kl*opq"));
    check.checkBool(true, o.isMatch("abcdefghijklmnopq", "a*?cd*fgh*kl*opq"));
    check.checkBool(true, o.isMatch("abcdefghijklmnopq", "a*cd?*fgh*kl*opq"));
    check.checkBool(false, o.isMatch("abcdefghijklmnopq", "a*c?d*fgh*kl*opq"));
    check.checkBool(false, o.isMatch("abcdefghijklmnop", "a*cd*fgh*kl*opq"));
    check.checkBool(false, o.isMatch("abcdefghijkmnopq", "a*cd*fgh*kl*opq"));
    check.checkBool(false, o.isMatch("abcdefghijko", "a*cd*fgh*kl*o"));
    check.checkBool(false, o.isMatch("aa", "a"));
    check.checkBool(true, o.isMatch("aa", "a?"));
    check.checkBool(true, o.isMatch("aa", "?a"));
    check.checkBool(false, o.isMatch("a", "aa"));
    check.checkBool(false, o.isMatch("a", "?aa"));
    check.checkBool(false, o.isMatch("ac", "ac?"));
    check.checkBool(true, o.isMatch("ac", "ac"));
    check.checkBool(true, o.isMatch("aaa", "aaa"));
    check.checkBool(true, o.isMatch("abc", "a*c"));
    check.checkBool(true, o.isMatch("abc", "a?c"));
    check.checkBool(true, o.isMatch("abc", "a*?c"));
    check.checkBool(true, o.isMatch("abc", "ab*c"));
    check.checkBool(true, o.isMatch("abc", "*c"));
    check.checkBool(true, o.isMatch("abc", "?*c"));
    check.checkBool(true, o.isMatch("abc", "*?c"));
    check.checkBool(true, o.isMatch("abc", "*abc"));
    check.checkBool(false, o.isMatch("abc", "*?abc"));
    check.checkBool(false, o.isMatch("abc", "a*abc"));
    check.checkBool(false, o.isMatch("abc", "abc*abc"));
    check.checkBool(false, o.isMatch("abc", "?*abc"));
    check.checkBool(true, o.isMatch("abc", "abc*"));
    check.checkBool(true, o.isMatch("abc", "a*"));
    check.checkBool(false, o.isMatch("abc", "abcd*"));
    check.checkBool(false, o.isMatch("abc", "ab*cd"));
    check.checkBool(false, o.isMatch("abc", "*dabc"));
    check.checkBool(true, o.isMatch("aa", "*"));
    check.checkBool(false, o.isMatch("cb", "?a"));
    check.checkBool(true, o.isMatch("adceb", "*a*b"));
    check.checkBool(false, o.isMatch("acdcb", "a*c?b"));
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
