/* 最长回文子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。

 

示例 1:
输入:

"bbbab"
输出:

4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:

"cbbd"
输出:

2
一个可能的最长回文子序列为 "bb"。

 

提示：

1 <= s.length <= 1000
s 只包含小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int i, j, k, size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));  // dp[i][j]表示s[i,j]的LP长度，i必须小于等于j，否则为0

        for (i = 0; i < size; ++i) {
            dp[i][i] = 1;  // 单字符的LP长度为1
        }

        for (k = 1; k < size; ++k) {
            for (i = 0, j = k; j < size; ++i, ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];  // 首尾相等，贡献LP长度2，然后剩下的字符串继续找LP
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);  // 首尾不等，选择分别去掉首尾，剩下字符串LP大的一个
                }
            }
        }

        return dp[0][size - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.longestPalindromeSubseq("bbbab"));
    check.checkInt(2, o.longestPalindromeSubseq("cbbd"));
    check.checkInt(1, o.longestPalindromeSubseq("b"));
    check.checkInt(1, o.longestPalindromeSubseq("ab"));
    check.checkInt(2, o.longestPalindromeSubseq("bb"));
    check.checkInt(1, o.longestPalindromeSubseq("abc"));
    check.checkInt(2, o.longestPalindromeSubseq("abb"));
    check.checkInt(2, o.longestPalindromeSubseq("bba"));
    check.checkInt(3, o.longestPalindromeSubseq("bab"));
    check.checkInt(5, o.longestPalindromeSubseq("aabaa"));
    check.checkInt(7, o.longestPalindromeSubseq("abcabcabcabc"));
    check.checkInt(45, o.longestPalindromeSubseq("akdsfhsdfhaflafhlahfahflakhahdfhasfkhadlkfjhalkdhfalkhflakhdfahlafdkjha"));
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
