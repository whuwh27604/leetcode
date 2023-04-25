/* 按字典序排在最后的子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，找出它的所有子串并按字典序排列，返回排在最后的那个子串。



示例 1：

输入：s = "abab"
输出："bab"
解释：我们可以找出 7 个子串 ["a", "ab", "aba", "abab", "b", "ba", "bab"]。按字典序排在最后的子串是 "bab"。
示例 2：

输入：s = "leetcode"
输出："tcode"


提示：

1 <= s.length <= 4 * 105
s 仅含有小写英文字符。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        int size = s.size(), left = 0, right = 1, step = 0;

        while (right + step < size) {
            if (s[left + step] == s[right + step]) {  // 先找从left、right开始的最长公共前缀
                ++step;
            }
            else {
                if (s[left + step] < s[right + step]) {  // s[left,size)不可能是最大后缀，又因为s[left, left + step) == s[right, right + step)，所以s[left, left + step]都不可能是最大后缀的起始位置
                    left += (step + 1);
                }
                else {  // s[left, left + step]一定大于s[right, right + step]，所以s[right, right + step]都不可能是最大后缀的起始位置
                    right += (step + 1);
                }

                step = 0;
                right = max(right, left + 1);
            }
        }

        return string(s, left, size - left);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("bab", o.lastSubstring("abab"));
    check.checkString("tcode", o.lastSubstring("leetcode"));
    check.checkString("x", o.lastSubstring("x"));
    check.checkString("b", o.lastSubstring("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"));
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
