/* 最长公共子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

 

示例 1:

输入：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共子序列是 "ace"，它的长度为 3。
示例 2:

输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。
示例 3:

输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0。
 

提示:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
输入的字符串只含有小写英文字符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /* 令dp[i][j]表示s1[i~size)和s2[j~size)可以得到的最长公共子序列，则dp[i-1][j-1]：
           1、如果s1[i-1]==s2[j-1]，则贪心想法，s1[i-1]和s2[j-1]肯定应该要作为lcs的第一个字符，所以dp[i-1][j-1]=dp[i][j]+1
           2、如果s1[i-1]!=s2[j-1]，那么s1[i-1]和s2[j-1]不可能同时是lcs的第一个字符，所以s1和s2分别新增一个字符，取lcs更长的，
              即dp[i-1][j-1]=max(dp[i][j-1],dp[i-1][j]) */
        int i, j, size1 = text1.size(), size2 = text2.size();
        vector<vector<int>> dp(size1, vector<int>(size2, 0));
        dp[size1 - 1][size2 - 1] = (text1[size1 - 1] == text2[size2 - 1]) ? 1 : 0;

        for (i = size1 - 2; i >= 0; --i) {
            dp[i][size2 - 1] = (dp[i + 1][size2 - 1] == 1 || text1[i] == text2[size2 - 1] ? 1 : 0);
        }

        for (j = size2 - 2; j >= 0; --j) {
            dp[size1 - 1][j] = (dp[size1 - 1][j + 1] == 1 || text1[size1 - 1] == text2[j] ? 1 : 0);
        }

        for (i = size1 - 2; i >= 0; --i) {
            for (j = size2 - 2; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.longestCommonSubsequence("abcde", "ace"));
    check.checkInt(3, o.longestCommonSubsequence("abc", "abc"));
    check.checkInt(0, o.longestCommonSubsequence("abc", "def"));
    check.checkInt(2, o.longestCommonSubsequence("ezupkr", "ubmrapg"));
    check.checkInt(4, o.longestCommonSubsequence("pmjghexybyrgzczy", "hafcdqbgncrcbihkd"));
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
