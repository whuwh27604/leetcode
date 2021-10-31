/* 重复 K 次的最长子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的字符串 s ，和一个整数 k 。请你找出字符串 s 中 重复 k 次的 最长子序列 。

子序列 是由其他字符串删除某些（或不删除）字符派生而来的一个字符串。

如果 seq * k 是 s 的一个子序列，其中 seq * k 表示一个由 seq 串联 k 次构造的字符串，那么就称 seq 是字符串 s 中一个 重复 k 次 的子序列。

举个例子，"bba" 是字符串 "bababcba" 中的一个重复 2 次的子序列，因为字符串 "bbabba" 是由 "bba" 串联 2 次构造的，而 "bbabba" 是字符串 "bababcba" 的一个子序列。
返回字符串 s 中 重复 k 次的最长子序列  。如果存在多个满足的子序列，则返回 字典序最大 的那个。如果不存在这样的子序列，返回一个 空 字符串。

 

示例 1：



输入：s = "letsleetcode", k = 2
输出："let"
解释：存在两个最长子序列重复 2 次：let" 和 "ete" 。
"let" 是其中字典序最大的一个。
示例 2：

输入：s = "bb", k = 2
输出："b"
解释：重复 2 次的最长子序列是 "b" 。
示例 3：

输入：s = "ab", k = 2
输出：""
解释：不存在重复 2 次的最长子序列。返回空字符串。
示例 4：

输入：s = "bbabbabbbbabaababab", k = 3
输出："bbbb"
解释：在 "bbabbabbbbabaababab" 中重复 3 次的最长子序列是 "bbbb" 。
 

提示：

n == s.length
2 <= k <= 2000
2 <= n < k * 8
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-subsequence-repeated-k-times
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string longestSubseq, possible = getPossible(s, k);
        int n, size = possible.size();
        unordered_set<string> visited;

        for (n = size; n > 0; --n) {
            if (DFS(s, possible, "", size, n, 0, k, visited, longestSubseq)) {
                return longestSubseq;
            }
        }

        return "";
    }

    string getPossible(string& s, int k) {
        vector<int> count('z' + 1, 0);
        string possible;

        for (char c : s) {
            ++count[c];
        }

        for (char c = 'z'; c >= 'a'; --c) {
            if (count[c] >= k) {
                possible += string(count[c] / k, c);
            }
        }

        return possible;
    }

    bool DFS(string& s, string& possible, string current, int size, int n, int index, int k, unordered_set<string>& visited, string& longestSubseq) {
        if (n == 0) {
            if (visited.count(current) == 0) {
                visited.insert(current);

                do {
                    if (isSubsequence(s, current, k)) {
                        longestSubseq = max(longestSubseq, current);
                        return true;
                    }
                } while (next_permutation(current.begin(), current.end(), greater<char>()));
            }

            return false;
        }

        bool find = false;

        for (int i = index; i <= size - n; ++i) {
            string next = current + possible[i];
            find |= DFS(s, possible, next, size, n - 1, i + 1, k, visited, longestSubseq);
        }

        return find;
    }

    bool isSubsequence(string& s, string& current, int k) {
        int i, j = 0, count = 0, size = current.size();

        for (i = 0; i < (int)s.size(); ++i) {
            if (s[i] == current[j]) {
                if (++j == size) {
                    if (++count == k) {
                        return true;
                    }

                    j = 0;
                }
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("let", o.longestSubsequenceRepeatedK("letsleetcode", 2));
    check.checkString("b", o.longestSubsequenceRepeatedK("bb", 2));
    check.checkString("", o.longestSubsequenceRepeatedK("ab", 2));
    check.checkString("bbbb", o.longestSubsequenceRepeatedK("bbabbabbbbabaababab", 3));
    check.checkString("y", o.longestSubsequenceRepeatedK("xxyy", 2));
    check.checkString("le", o.longestSubsequenceRepeatedK("lealecle", 2));
    check.checkString("zzzzzzz", o.longestSubsequenceRepeatedK("zzzzzzzzzzzzzzz", 2));
    check.checkString("babab", o.longestSubsequenceRepeatedK("babbbaabbabab", 2));
    check.checkString("fd", o.longestSubsequenceRepeatedK("effecdefddabcbbfeabbedfedefeddebf", 5));
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
