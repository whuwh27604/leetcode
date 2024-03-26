﻿/* 最长公共后缀查询.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串数组 wordsContainer 和 wordsQuery 。

对于每个 wordsQuery[i] ，你需要从 wordsContainer 中找到一个与 wordsQuery[i] 有 最长公共后缀 的字符串。如果 wordsContainer 中有两个或者更多字符串有最长公共后缀，那么答案为长度 最短 的。如果有超过两个字符串有 相同 最短长度，那么答案为它们在 wordsContainer 中出现 更早 的一个。

请你返回一个整数数组 ans ，其中 ans[i]是 wordsContainer中与 wordsQuery[i] 有 最长公共后缀 字符串的下标。



示例 1：

输入：wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]

输出：[1,1,1]

解释：

我们分别来看每一个 wordsQuery[i] ：

对于 wordsQuery[0] = "cd" ，wordsContainer 中有最长公共后缀 "cd" 的字符串下标分别为 0 ，1 和 2 。这些字符串中，答案是下标为 1 的字符串，因为它的长度为 3 ，是最短的字符串。
对于 wordsQuery[1] = "bcd" ，wordsContainer 中有最长公共后缀 "bcd" 的字符串下标分别为 0 ，1 和 2 。这些字符串中，答案是下标为 1 的字符串，因为它的长度为 3 ，是最短的字符串。
对于 wordsQuery[2] = "xyz" ，wordsContainer 中没有字符串跟它有公共后缀，所以最长公共后缀为 "" ，下标为 0 ，1 和 2 的字符串都得到这一公共后缀。这些字符串中， 答案是下标为 1 的字符串，因为它的长度为 3 ，是最短的字符串。
示例 2：

输入：wordsContainer = ["abcdefgh","poiuygh","ghghgh"], wordsQuery = ["gh","acbfgh","acbfegh"]

输出：[2,0,2]

解释：

我们分别来看每一个 wordsQuery[i] ：

对于 wordsQuery[0] = "gh" ，wordsContainer 中有最长公共后缀 "gh" 的字符串下标分别为 0 ，1 和 2 。这些字符串中，答案是下标为 2 的字符串，因为它的长度为 6 ，是最短的字符串。
对于 wordsQuery[1] = "acbfgh" ，只有下标为 0 的字符串有最长公共后缀 "fgh" 。所以尽管下标为 2 的字符串是最短的字符串，但答案是 0 。
对于 wordsQuery[2] = "acbfegh" ，wordsContainer 中有最长公共后缀 "gh" 的字符串下标分别为 0 ，1 和 2 。这些字符串中，答案是下标为 2 的字符串，因为它的长度为 6 ，是最短的字符串。


提示：

1 <= wordsContainer.length, wordsQuery.length <= 104
1 <= wordsContainer[i].length <= 5 * 103
1 <= wordsQuery[i].length <= 5 * 103
wordsContainer[i] 只包含小写英文字母。
wordsQuery[i] 只包含小写英文字母。
wordsContainer[i].length 的和至多为 5 * 105 。
wordsQuery[i].length 的和至多为 5 * 105 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(TrieNode*) * 26);
        len = INT_MAX;
        index = 0;
    }

    TrieNode(int len_, int index_) {
        memset(next, 0, sizeof(TrieNode*) * 26);
        len = len_;
        index = index_;
    }

    TrieNode* next[26];
    int len;
    int index;
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
    }

    void insert(string& word, int index) {
        TrieNode* node = root;

        int len = word.size();
        if (len < node->len) {
            node->len = len;
            node->index = index;
        }

        for (int i = (int)word.size() - 1; i >= 0; --i) {
            int idx = word[i] - 'a';
            if (node->next[idx] == NULL) {
                node->next[idx] = new TrieNode(len, index);
            }

            node = node->next[idx];
            if (len < node->len) {
                node->len = len;
                node->index = index;
            }
        }
    }

    int search(string& word) {
        TrieNode* node = root;

        for (int i = (int)word.size() - 1; i >= 0; --i) {
            int idx = word[i] - 'a';
            if (node->next[idx] == NULL) {
                break;
            }

            node = node->next[idx];
        }

        return node->index;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int size1 = wordsContainer.size(), size2 = wordsQuery.size();
        Trie trie;
        vector<int> ans(size2);

        for (int i = 0; i < size1; ++i) {
            trie.insert(wordsContainer[i], i);
        }

        for (int i = 0; i < size2; ++i) {
            ans[i] = trie.search(wordsQuery[i]);
        }

        return ans;
    }
};

int main()
{
	Solution o;
	CheckResult check;

    vector<string> wordsContainer = { "abcd","bcd","xbcd" };
    vector<string> wordsQuery = { "cd","bcd","xyz" };
    vector<int> actual = o.stringIndices(wordsContainer, wordsQuery);
    vector<int> expected = { 1,1,1 };
    check.checkIntVector(expected, actual);

    wordsContainer = { "abcdefgh","poiuygh","ghghgh" };
    wordsQuery = { "gh","acbfgh","acbfegh" };
    actual = o.stringIndices(wordsContainer, wordsQuery);
    expected = { 2,0,2 };
    check.checkIntVector(expected, actual);
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
