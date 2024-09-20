/* 形成目标字符串需要的最少字符串数 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串数组 words 和一个字符串 target。

如果字符串 x 是 words 中 任意 字符串的
前缀
，则认为 x 是一个 有效 字符串。

现计划通过 连接 有效字符串形成 target ，请你计算并返回需要连接的 最少 字符串数量。如果无法通过这种方式形成 target，则返回 -1。



示例 1：

输入： words = ["abc","aaaaa","bcdef"], target = "aabcdabc"

输出： 3

解释：

target 字符串可以通过连接以下有效字符串形成：

words[1] 的长度为 2 的前缀，即 "aa"。
words[2] 的长度为 3 的前缀，即 "bcd"。
words[0] 的长度为 3 的前缀，即 "abc"。
示例 2：

输入： words = ["abababab","ab"], target = "ababaababa"

输出： 2

解释：

target 字符串可以通过连接以下有效字符串形成：

words[0] 的长度为 5 的前缀，即 "ababa"。
words[0] 的长度为 5 的前缀，即 "ababa"。
示例 3：

输入： words = ["abcdef"], target = "xyz"

输出： -1



提示：

1 <= words.length <= 100
1 <= words[i].length <= 5 * 103
输入确保 sum(words[i].length) <= 105。
words[i] 只包含小写英文字母。
1 <= target.length <= 5 * 103
target 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(TrieNode*) * 26);
    }

    TrieNode* next[26];
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int size = (int)target.size(), inf = INT_MAX / 2;
        vector<int> dp(size + 1, inf);
        dp[size] = 0;
        TrieNode* root = new TrieNode;

        for (string& word : words) {
            insert(root, word);
        }

        for (int i = size - 1; i >= 0; --i) {
            TrieNode* current = root;

            for (int j = i; j < size; ++j) {
                int idx = target[j] - 'a';
                if (current->next[idx] == NULL) {
                    break;
                }

                current = current->next[idx];
                dp[i] = min(dp[i], 1 + dp[j + 1]);
            }
        }

        return dp[0] == inf ? -1 : dp[0];
    }

    void insert(TrieNode* root, string& word) {
        TrieNode* current = root;

        for (char c : word) {
            int idx = c - 'a';
            if (current->next[idx] == NULL) {
                current->next[idx] = new TrieNode;
            }

            current = current->next[idx];
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> words = { "abc","aaaaa","bcdef" };
    check.checkInt(3, o.minValidStrings(words, "aabcdabc"));

    words = { "abababab","ab" };
    check.checkInt(2, o.minValidStrings(words, "ababaababa"));

    words = { "abcdef" };
    check.checkInt(-1, o.minValidStrings(words, "xyz"));
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
