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
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ms;
        preprocess(s, ms);

        vector<int> radii(ms.size(), 0);
        int maxCenter, maxRadius = 0;
        manacher(ms, radii, maxCenter, maxRadius);

        string longestSubstr;
        for (int i = maxCenter - maxRadius + 2; i < maxCenter + maxRadius - 1; i += 2) {
            longestSubstr += ms[i];
        }

        return longestSubstr;
    }

    void preprocess(string& s, string& manacher) {
        manacher += "@#";  // 首尾添加字符@、$，可以简化后面算法的边界处理

        for (char c : s) {
            manacher += c;
            manacher += '#';  // 每个字符前后插入#，可以使奇偶回文都变为奇回文，简化算法的处理
        }

        manacher += '$';
    }

    void manacher(string& ms, vector<int>& radii, int& maxCenter, int& maxRadius) {
        /*   symmetryMaxRight   symmetryI     center          i            maxRight
        ------------|---------------|------------|------------|---------------|-------- */
        int i, size = ms.size();
        int center, maxRight = 0;

        for (i = 1; i < size - 1; i++) {
            if (i < maxRight) {
                /* （2 * center - i）是symmetryI，分三种情况可证明下面这句话成立：
                   1、radii[symmetryI]大于(symmetryI-symmetryMaxRight)，则radii[i]=(symmetryI-symmetryMaxRight)=(maxRight-i)，不能再大
                   2、radii[symmetryI]小于(symmetryI-symmetryMaxRight)，则radii[i]=radii[symmetryI]，不能再大
                   3、radii[symmetryI]等于(symmetryI-symmetryMaxRight)，则radii[i]=radii[symmetryI]=(maxRight-i)，然后执行下面的while语句继续拓展 */
                radii[i] = min(radii[2 * center - i], maxRight - i);
            }
            else {
                radii[i] = 1;
            }

            // 中心拓展找最大的半径，预处理在首尾添加的不同字符保证不会越界
            while (ms[i - radii[i]] == ms[i + radii[i]]) {
                radii[i]++;
            }

            // 每走一步i，都要维护maxRight。我们希望maxRight尽可能往右，这样才能更有机会执行if (i < maxRight)提高效率
            if (maxRight < i + radii[i]) {
                center = i;
                maxRight = i + radii[i];
            }

            if (radii[i] > maxRadius) {
                maxRadius = radii[i];
                maxCenter = i;
            }
        }
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
