/* 不同的子序列 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串 S，计算 S 的不同非空子序列的个数。

因为结果可能很大，所以返回答案模 10^9 + 7.

 

示例 1：

输入："abc"
输出：7
解释：7 个不同的子序列分别是 "a", "b", "c", "ab", "ac", "bc", 以及 "abc"。
示例 2：

输入："aba"
输出：6
解释：6 个不同的子序列分别是 "a", "b", "ab", "ba", "aa" 以及 "aba"。
示例 3：

输入："aaa"
输出：3
解释：3 个不同的子序列分别是 "a", "aa" 以及 "aaa"。
 

 

提示：

S 只包含小写字母。
1 <= S.length <= 2000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distinct-subsequences-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int distinctSubseqII(string S) {
        int i, size = S.size(), mod = 1000000007;
        vector<int> lastIndices('z' + 1, -1);  // 字符最后一次出现的索引
        vector<int> dp(size + 1);  // dp[i + 1]表示s[0,i]的子序列个数
        dp[0] = 1;  // 空序列

        for (i = 0; i < size; ++i) {
            dp[i + 1] = (dp[i] * 2) % mod;  // 这个字符还没有出现过，那么子序列翻倍

            if (lastIndices[S[i]] != -1) {
                dp[i + 1] = (dp[i + 1] + mod - dp[lastIndices[S[i]]]) % mod;  // 这个字符上一次出现之前所有的子序列会被重复计算
            }

            lastIndices[S[i]] = i;
        }

        return (dp[size] + mod - 1) % mod;  // 最后的结果减去空序列
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.distinctSubseqII("z"));
    check.checkInt(15, o.distinctSubseqII("abcx"));
    check.checkInt(11, o.distinctSubseqII("abab"));
    check.checkInt(7, o.distinctSubseqII("abc"));
    check.checkInt(6, o.distinctSubseqII("aba"));
    check.checkInt(3, o.distinctSubseqII("aaa"));
    check.checkInt(9, o.distinctSubseqII("bebb"));
    check.checkInt(992025290, o.distinctSubseqII("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"));
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
