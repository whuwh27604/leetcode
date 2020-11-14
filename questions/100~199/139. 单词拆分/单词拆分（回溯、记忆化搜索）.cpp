/* 单词拆分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(TrieNode*) * 26);
        isEnd = false;
    }

    bool isEnd;
    TrieNode* next[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
    }

    void insert(string& word) {
        TrieNode* current = root;

        for (char c : word) {
            int index = c - 'a';
            if (current->next[index] == NULL) {
                current->next[index] = new TrieNode;
            }

            current = current->next[index];
        }

        current->isEnd = true;
    }

    int search(string& s, int start, TrieNode* startNode, TrieNode** endNode) {
        TrieNode* current = (startNode == NULL ? root : startNode);

        for (int i = start; i < (int)s.size(); ++i) {
            int index = s[i] - 'a';
            if (current->next[index] == NULL) {
                return -1;
            }

            current = current->next[index];
            if (current->isEnd) {
                *endNode = current;
                return i;
            }
        }

        return -1;
    }

    TrieNode* root;
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        unordered_set<int> failedPosition;

        for (string& word : wordDict) {
            trie.insert(word);
        }

        return DFS(s, 0, trie, failedPosition);
    }

    bool DFS(string& s, int start, Trie& trie, unordered_set<int>& failedPosition) {
        if (failedPosition.count(start) != 0) {
            return false;
        }

        TrieNode* startNode = NULL;
        TrieNode* endNode = NULL;
        int end;

        while ((end = trie.search(s, start, startNode , &endNode)) != -1) {
            if (end == s.size() - 1) {
                return true;
            }

            if (DFS(s, end + 1, trie, failedPosition)) {
                return true;
            }

            start = end + 1;
            startNode = endNode;
        }

        failedPosition.insert(start);
        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> wordDict = { "cats","dog","sand","and","cat","og" };
    check.checkBool(true, o.wordBreak("catsandog", wordDict));

    wordDict = { "cats","dog","sand","an","cat" };
    check.checkBool(true, o.wordBreak("catsandog", wordDict));

    wordDict = { "cats","dog","sand","and","cat" };
    check.checkBool(false, o.wordBreak("catsandog", wordDict));

    wordDict = { "leet","code" };
    check.checkBool(true, o.wordBreak("leetcode", wordDict));

    wordDict = { "apple","pen" };
    check.checkBool(true, o.wordBreak("applepenapple", wordDict));

    wordDict = {  };
    check.checkBool(false, o.wordBreak("a", wordDict));

    wordDict = { "car","ca","rs" };
    check.checkBool(true, o.wordBreak("cars", wordDict));

    wordDict = { "a","b","bbb","bbbb" };
    check.checkBool(true, o.wordBreak("bb", wordDict));

    wordDict = { "dd","ad","da","b" };
    check.checkBool(true, o.wordBreak("ddadddbdddadd", wordDict));

    wordDict = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    check.checkBool(false, o.wordBreak("aaaaaaaaaaaaaaab", wordDict));

    wordDict = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    check.checkBool(false, o.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict));

    wordDict = { "aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba" };
    check.checkBool(false, o.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", wordDict));
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
