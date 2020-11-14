/* 交错字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
示例 2:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/interleaving-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.size(), size2 = s2.size(), size3 = s3.size(), i, j;
        if (size1 + size2 != size3) {
            return false;
        }

        // dp[i][j]表示s1的前i个字符和s2的前j个字符能否构成s3的前i+j个字符
        vector<vector<bool>> dp(size1 + 1, vector<bool>(size2 + 1, true));
        for (i = 1; i <= size1; i++) {
            dp[i][0] = (dp[i - 1][0] && (s1[i - 1] == s3[i - 1]));
        }

        for (j = 1; j <= size2; j++) {
            dp[0][j] = (dp[0][j - 1] && (s2[j - 1] == s3[j - 1]));
        }

        for (i = 1; i <= size1; i++) {
            for (j = 1; j <= size2; j++) {
                // s1的前i-1个字符和s2的前j个字符可以匹配s3的前i+j-1个字符，并且s1的第i个字符等于s3的第i+j个字符
                // 或者s1的前i个字符和s2的前j-1个字符可以匹配s3的前i+j-1个字符，并且s2的第j个字符等于s3的第i+j个字符
                dp[i][j] = ((dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1])));
            }
        }

        return dp[size1][size2];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.isInterleave("", "", ""));
    check.checkBool(true, o.isInterleave("abc", "", "abc"));
    check.checkBool(false, o.isInterleave("abc", "", "abd"));
    check.checkBool(true, o.isInterleave("", "abc", "abc"));
    check.checkBool(false, o.isInterleave("", "abc", "abd"));
    check.checkBool(false, o.isInterleave("a", "b", "a"));
    check.checkBool(true, o.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    check.checkBool(false, o.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    check.checkBool(true, o.isInterleave("a", "b", "ab"));
    check.checkBool(true, o.isInterleave("a", "b", "ba"));
    check.checkBool(false, o.isInterleave("a", "b", "ad"));
    check.checkBool(true, o.isInterleave("aaaab", "bbbbc", "ababababcb"));
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
