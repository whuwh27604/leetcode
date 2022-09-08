/* 统计不同回文子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串 s，返回 s 中不同的非空「回文子序列」个数 。

通过从 s 中删除 0 个或多个字符来获得子序列。

如果一个字符序列与它反转后的字符序列一致，那么它是「回文字符序列」。

如果有某个 i , 满足 ai != bi ，则两个序列 a1, a2, ... 和 b1, b2, ... 不同。

注意：

结果可能很大，你需要对 109 + 7 取模 。
 

示例 1：

输入：s = 'bccb'
输出：6
解释：6 个不同的非空回文子字符序列分别为：'b', 'c', 'bb', 'cc', 'bcb', 'bccb'。
注意：'bcb' 虽然出现两次但仅计数一次。
示例 2：

输入：s = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
输出：104860361
解释：共有 3104860382 个不同的非空回文子序列，104860361 对 109 + 7 取模后的值。
 

提示：

1 <= s.length <= 1000
s[i] 仅包含 'a', 'b', 'c' 或 'd' 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-different-palindromic-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int size = s.size();
        vector<vector<int>> lefts(4, vector<int>(size)), rights(4, vector<int>(size));

        getLefts(s, lefts);
        getRights(s, rights);

        return count(s, lefts, rights);
    }

    void getLefts(string& s, vector<vector<int>>& lefts) {
        vector<int> prev(4, -1);

        for (int i = 0; i < (int)s.size(); ++i) {
            int idx = s[i] - 'a';
            lefts[idx][i] = prev[idx];
            prev[idx] = i;
        }
    }

    void getRights(string& s, vector<vector<int>>& rights) {
        int size = s.size();
        vector<int> next(4, size);

        for (int i = size - 1; i >= 0; --i) {
            int idx = s[i] - 'a';
            rights[idx][i] = next[idx];
            next[idx] = i;
        }
    }

    int count(string& s, vector<vector<int>>& lefts, vector<vector<int>>& rights) {
        int start, end, size = s.size(), mod = 1000000007;
        vector<vector<long long>> dp(size, vector<long long>(size, 0));

        for (start = 0; start < size; ++start) {  // 长度为1时回文串个数为1
            dp[start][start] = 1;
        }

        for (int len = 2; len <= size; ++len) {
            for (start = 0; start <= size - len; ++start) {
                end = start + len - 1;

                if (s[start] != s[end]) {  // 首尾字符不相等，统计前面、后面，再减去中间重复的
                    dp[start][end] = (dp[start + 1][end] + dp[start][end - 1] + mod - dp[start + 1][end - 1]) % mod;
                }
                else {  // 首尾字符相等，记为x
                    int idx = s[start] - 'a', low = rights[idx][start], high = lefts[idx][end];

                    if (low == end) {  // s(start, end)之间没有字符x，那么其中所有的回文串加上x...x都可以构成一个新的回文串，再加上x和xx两个
                        dp[start][end] = (2 * dp[start + 1][end - 1] + 2) % mod;
                    }
                    else if (low == high) {  // s(start, end)之间有一个字符x，那么x不再重复计算
                        dp[start][end] = (2 * dp[start + 1][end - 1] + 1) % mod;
                    }
                    else {  // s(start, end)之间有2个以上字符x，那么x、xx不再重复计算，并且s(low, high)之间的回文串被重复计算了
                        dp[start][end] = (2 * dp[start + 1][end - 1] + mod - dp[low + 1][high - 1]) % mod;
                    }
                }
            }
        }

        return (int)dp[0][size - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.countPalindromicSubsequences("d"));
    check.checkInt(2, o.countPalindromicSubsequences("ad"));
    check.checkInt(2, o.countPalindromicSubsequences("cc"));
    check.checkInt(3, o.countPalindromicSubsequences("abc"));
    check.checkInt(4, o.countPalindromicSubsequences("aba"));
    check.checkInt(6, o.countPalindromicSubsequences("bccb"));
    check.checkInt(117990582, o.countPalindromicSubsequences("bcbacbabdcbcbdcbddcaaccdcbbcdbcabbcdddadaadddbdbbbdacbabaabdddcaccccdccdbabcddbdcccabccbbcdbcdbdaada"));
    check.checkInt(104860361, o.countPalindromicSubsequences("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"));
    check.checkInt(700746431, o.countPalindromicSubsequences("bccbabcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcbabccbabcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcbabccbabcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcbabccbabcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcbabccbabcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcbabccbabcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"));
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
