/* 至多 K 次操作后的最长回文子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个整数 k。

在一次操作中，你可以将任意位置的字符替换为字母表中相邻的字符（字母表是循环的，因此 'z' 的下一个字母是 'a'）。例如，将 'a' 替换为下一个字母结果是 'b'，将 'a' 替换为上一个字母结果是 'z'；同样，将 'z' 替换为下一个字母结果是 'a'，替换为上一个字母结果是 'y'。

返回在进行 最多 k 次操作后，s 的 最长回文子序列 的长度。

子序列 是一个 非空 字符串，可以通过删除原字符串中的某些字符（或不删除任何字符）并保持剩余字符的相对顺序得到。

回文 是正着读和反着读都相同的字符串。



示例 1：

输入: s = "abced", k = 2

输出: 3

解释:

将 s[1] 替换为下一个字母，得到 "acced"。
将 s[4] 替换为上一个字母，得到 "accec"。
子序列 "ccc" 形成一个长度为 3 的回文，这是最长的回文子序列。

示例 2：

输入: s = "aaazzz", k = 4

输出: 6

解释:

将 s[0] 替换为上一个字母，得到 "zaazzz"。
将 s[4] 替换为下一个字母，得到 "zaazaz"。
将 s[3] 替换为下一个字母，得到 "zaaaaz"。
整个字符串形成一个长度为 6 的回文。



提示:

1 <= s.length <= 200
1 <= k <= 200
s 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int size = (int)s.size(), maxLen = 1;
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(size, vector<int>(k + 1, 0)));  // dp[i + 1][j - 1][op]表示s[0, i]、s[j, size - 1]、op次转换可以匹配的最大长度

        for (int i = 0; i < size - 1; ++i) {  // s[i] <--> dp[i + 1], s[j] <--> dp[][j - 1]
            for (int j = size - 1; j > i; --j) {
                char a = min(s[i], s[j]), b = max(s[i], s[j]);
                int opers = min(b - a, 'z' - b + a - 'a' + 1);

                for (int op = 0; op <= k; ++op) {
                    dp[i + 1][j - 1][op] = dp[i][j - 1][op];  // 放弃左端点
                    dp[i + 1][j - 1][op] = max(dp[i + 1][j - 1][op], dp[i + 1][j][op]);  // 放弃右端点
                    if (op >= opers) {  // 当前端点可转换，长度加2，消耗opers次转换机会
                        dp[i + 1][j - 1][op] = max(dp[i + 1][j - 1][op], 2 + dp[i][j][op - opers]);
                    }
                }
            }

            maxLen = max(maxLen, dp[i + 1][i][k]);  // 当i、j相邻时，计算长度。长度为偶数的回文串
            maxLen = max(maxLen, 1 + dp[i][i][k]);  // i为中间位置，长度为奇数的回文串
            maxLen = max(maxLen, 1 + dp[i + 1][i + 1][k]);  // j为中间位置，长度为奇数的回文串
        }

        return maxLen;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(3, o.longestPalindromicSubsequence("abced", 2));
    check.checkInt(6, o.longestPalindromicSubsequence("aaazzz", 4));
    check.checkInt(2, o.longestPalindromicSubsequence("bt", 8));
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
