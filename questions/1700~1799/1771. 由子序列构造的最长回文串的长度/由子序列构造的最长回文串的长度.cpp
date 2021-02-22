/* 由子序列构造的最长回文串的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 word1 和 word2 ，请你按下述方法构造一个字符串：

从 word1 中选出某个 非空 子序列 subsequence1 。
从 word2 中选出某个 非空 子序列 subsequence2 。
连接两个子序列 subsequence1 + subsequence2 ，得到字符串。
返回可按上述方法构造的最长 回文串 的 长度 。如果无法构造回文串，返回 0 。

字符串 s 的一个 子序列 是通过从 s 中删除一些（也可能不删除）字符而不更改其余字符的顺序生成的字符串。

回文串 是正着读和反着读结果一致的字符串。

 

示例 1：

输入：word1 = "cacb", word2 = "cbba"
输出：5
解释：从 word1 中选出 "ab" ，从 word2 中选出 "cba" ，得到回文串 "abcba" 。
示例 2：

输入：word1 = "ab", word2 = "ab"
输出：3
解释：从 word1 中选出 "ab" ，从 word2 中选出 "a" ，得到回文串 "aba" 。
示例 3：

输入：word1 = "aa", word2 = "bb"
输出：0
解释：无法按题面所述方法构造回文串，所以返回 0 。
 

提示：

1 <= word1.length, word2.length <= 1000
word1 和 word2 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximize-palindrome-length-from-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int i, size1 = word1.size(), size2 = word2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

        vector<vector<int>> dp1(size1, vector<int>(size1, 0));
        getLPOneWord(word1, dp1);
        for (i = 1; i <= size1; ++i) {
            dp[i][0] = dp1[size1 - i][size1 - 1];  // 注意这里word1是从后往前取字符
        }

        vector<vector<int>> dp2(size2, vector<int>(size2, 0));
        getLPOneWord(word2, dp2);
        for (i = 1; i <= size2; ++i) {
            dp[0][i] = dp2[0][i - 1];
        }

        getLPTwoWords(word1, word2, dp);
        return dp[size1][size2];
    }

    void getLPOneWord(string& word, vector<vector<int>>& dp) {
        int i, j, k, size = word.size();

        for (i = 0; i < size; ++i) {
            dp[i][i] = 1;  // 单字符的LP长度为1
        }

        for (k = 1; k < size; ++k) {
            for (i = 0, j = k; j < size; ++i, ++j) {
                if (word[i] == word[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];  // 首尾相等，贡献LP长度2，然后剩下的字符串继续找LP
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);  // 首尾不等，选择分别去掉首尾，剩下字符串LP大的一个
                }
            }
        }
    }

    void getLPTwoWords(string& word1, string& word2, vector<vector<int>>& dp) {
        int i, j, k, size1 = word1.size(), size2 = word2.size();

        for (k = 2; k <= size1 + size2; ++k) {
            for (i = min(size1, k - 1), j = k - i; i > 0 && j <= size2; --i, ++j) {
                if (word1[size1 - i] == word2[j - 1]) {
                    dp[i][j] = 2 + max({ dp[i - 1][j - 1], dp[0][j - 1], dp[i - 1][0] });  // 因为已经满足了不为空的要求，此时可以把一边为空的选项加进来选择最大的
                }
                else {  // 必须要满足都不为空的要求，所以当某一边长度为1时，必须选择它
                    if (i == 1 && j == 1) {
                        dp[i][j] = 0;
                    }
                    else if (i == 1) {
                        dp[i][j] = dp[i][j - 1];
                    }
                    else if (j == 1) {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else {
                        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                    }
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.longestPalindrome("cacb", "cbba"));
    check.checkInt(3, o.longestPalindrome("ab", "aa"));
    check.checkInt(3, o.longestPalindrome("ab", "ab"));
    check.checkInt(0, o.longestPalindrome("aa", "bb"));
    check.checkInt(2, o.longestPalindrome("a", "a"));
    check.checkInt(0, o.longestPalindrome("a", "b"));
    check.checkInt(45, o.longestPalindrome("akdsfhsdfhaflafhlahfahflakh", "ahdfhasfkhadlkfjhalkdhfalkhflakhdfahlafdkjha"));
    check.checkInt(44, o.longestPalindrome("ahdfhasfkhadlkfjhalkdhfalkhflakhdfahlafdkjha", "akdsfhsdfhaflafhlahfahflakh"));
    check.checkInt(7, o.longestPalindrome("eeeecd", "eabfbeeb"));
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
