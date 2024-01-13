/* 最长相邻不相等子序列 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 和一个下标从 0 开始的字符串数组 words ，和一个下标从 0 开始的数组 groups ，两个数组长度都是 n 。

两个长度相等字符串的 汉明距离 定义为对应位置字符 不同 的数目。

你需要从下标 [0, 1, ..., n - 1] 中选出一个 最长子序列 ，将这个子序列记作长度为 k 的 [i0, i1, ..., ik - 1] ，它需要满足以下条件：

相邻 下标对应的 groups 值 不同。即，对于所有满足 0 < j + 1 < k 的 j 都有 groups[ij] != groups[ij + 1] 。
对于所有 0 < j + 1 < k 的下标 j ，都满足 words[ij] 和 words[ij + 1] 的长度 相等 ，且两个字符串之间的 汉明距离 为 1 。
请你返回一个字符串数组，它是下标子序列 依次 对应 words 数组中的字符串连接形成的字符串数组。如果有多个答案，返回任意一个。

子序列 指的是从原数组中删掉一些（也可能一个也不删掉）元素，剩余元素不改变相对位置得到的新的数组。

注意：words 中的字符串长度可能 不相等 。



示例 1：

输入：n = 3, words = ["bab","dab","cab"], groups = [1,2,2]
输出：["bab","cab"]
解释：一个可行的子序列是 [0,2] 。
- groups[0] != groups[2]
- words[0].length == words[2].length 且它们之间的汉明距离为 1 。
所以一个可行的答案是 [words[0],words[2]] = ["bab","cab"] 。
另一个可行的子序列是 [0,1] 。
- groups[0] != groups[1]
- words[0].length = words[1].length 且它们之间的汉明距离为 1 。
所以另一个可行的答案是 [words[0],words[1]] = ["bab","dab"] 。
符合题意的最长子序列的长度为 2 。
示例 2：

输入：n = 4, words = ["a","b","c","d"], groups = [1,2,3,4]
输出：["a","b","c","d"]
解释：我们选择子序列 [0,1,2,3] 。
它同时满足两个条件。
所以答案为 [words[0],words[1],words[2],words[3]] = ["a","b","c","d"] 。
它是所有下标子序列里最长且满足所有条件的。
所以它是唯一的答案。


提示：

1 <= n == words.length == groups.length <= 1000
1 <= words[i].length <= 10
1 <= groups[i] <= n
words 中的字符串 互不相同 。
words[i] 只包含小写英文字母。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> dp(n, 1);  // dp[i]表示以索引i为结尾的最长subseq长度
        vector<int> prevs(n, -1);  // 记录dp转移时的前一跳索引

        getMaxSubSeq(n, words, groups, dp, prevs);
        int index = getMaxSubSeqIndex(n, dp);

        return restoreWords(index, prevs, words);
    }

    void getMaxSubSeq(int n, vector<string>& words, vector<int>& groups, vector<int>& dp, vector<int>& prevs) {
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (isMatch(i, j, words, groups)) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prevs[i] = j;
                    }
                }
            }
        }
    }

    int getMaxSubSeqIndex(int n, vector<int>& dp) {
        int maxLen = 0, index = 0;

        for (int i = 0; i < n; ++i) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                index = i;
            }
        }

        return index;
    }

    vector<string> restoreWords(int index, vector<int>& prevs, vector<string>& words) {
        vector<string> ans;

        while (index != -1) {
            ans.push_back(words[index]);
            index = prevs[index];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    bool isMatch(int idx1, int idx2, vector<string>& words, vector<int>& groups) {
        if (groups[idx1] == groups[idx2]) {
            return false;
        }

        int size1 = words[idx1].size(), size2 = words[idx2].size(), count = 0;
        if (size1 != size2) {
            return false;
        }

        for (int i = 0; i < size1; ++i) {
            if (words[idx1][i] != words[idx2][i]) {
                if (++count > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "bab","dab","cab" };
    vector<int> groups = { 1,2,2 };
    vector<string> actual = o.getWordsInLongestSubsequence(3, words, groups);
    vector<string> expected = { "bab","dab" };
    check.checkStringVector(expected, actual);

    words = { "a","b","c","d" };
    groups = { 1,2,3,4 };
    actual = o.getWordsInLongestSubsequence(4, words, groups);
    expected = { "a","b","c","d" };
    check.checkStringVector(expected, actual);
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
