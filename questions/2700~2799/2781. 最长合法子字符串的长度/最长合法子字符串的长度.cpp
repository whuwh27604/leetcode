/* 最长合法子字符串的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 word 和一个字符串数组 forbidden 。

如果一个字符串不包含 forbidden 中的任何字符串，我们称这个字符串是 合法 的。

请你返回字符串 word 的一个 最长合法子字符串 的长度。

子字符串 指的是一个字符串中一段连续的字符，它可以为空。



示例 1：

输入：word = "cbaaaabc", forbidden = ["aaa","cb"]
输出：4
解释：总共有 9 个合法子字符串："c" ，"b" ，"a" ，"ba" ，"aa" ，"bc" ，"baa" ，"aab" 和 "aabc" 。最长合法子字符串的长度为 4 。
其他子字符串都要么包含 "aaa" ，要么包含 "cb" 。
示例 2：

输入：word = "leetcode", forbidden = ["de","le","e"]
输出：4
解释：总共有 11 个合法子字符串："l" ，"t" ，"c" ，"o" ，"d" ，"tc" ，"co" ，"od" ，"tco" ，"cod" 和 "tcod" 。最长合法子字符串的长度为 4 。
所有其他子字符串都至少包含 "de" ，"le" 和 "e" 之一。


提示：

1 <= word.length <= 105
word 只包含小写英文字母。
1 <= forbidden.length <= 105
1 <= forbidden[i].length <= 10
forbidden[i] 只包含小写英文字母。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(TrieNode*) * 26);
        len = 0;
    }

    TrieNode* next[26];
    int len;
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
    }

    void buildTree(vector<string>& words) {
        for (string& word : words) {
            insert(word);
        }
    }

    void insert(string& word) {
        TrieNode* node = root;

        for (int i = (int)word.size() - 1; i >= 0; --i) {
            int index = word[i] - 'a';
            if (node->next[index] == NULL) {
                node->next[index] = new TrieNode;
            }

            node = node->next[index];
        }

        node->len = word.size();
    }

    bool search(string& word, int start, int pos, int& len) {
        TrieNode* node = root;

        for (; pos >= start; --pos) {
            int index = word[pos] - 'a';
            if (node->next[index] == NULL) {
                return false;
            }

            node = node->next[index];
            if (node->len != 0) {
                len = node->len;
                return true;
            }
        }

        return false;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int size = word.size(), i = 0, j = 0, maxLen = 0;
        Trie trie;
        trie.buildTree(forbidden);

        while (i < size) {
            int len = 0;

            while (j < size && trie.search(word, i, j, len) == false) {
                ++j;
            }

            maxLen = max(maxLen, j - i);
            i = j - (len - 1) + 1;
            j = i;
        }

        return maxLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> forbidden = { "aaa","cb" };
    check.checkInt(4, o.longestValidSubstring("cbaaaabc", forbidden));

    forbidden = { "de","le","e" };
    check.checkInt(4, o.longestValidSubstring("leetcode", forbidden));

    forbidden = { "e" };
    check.checkInt(10, o.longestValidSubstring("aaaaaaaaaa", forbidden));

    forbidden = { "a" };
    check.checkInt(0, o.longestValidSubstring("aaaaaaaaaa", forbidden));
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
