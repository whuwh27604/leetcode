/* 单词拆分 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]
示例 2：

输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。
示例 3：

输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break-ii
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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (string& word : wordDict) {
            trie.insert(word);
        }

        unordered_set<int> failedPosition;
        string sentence;
        vector<string> sentences;
        (void)DFS(s, 0, trie, failedPosition, sentence, sentences);

        return sentences;
    }

    bool DFS(string& s, int start, Trie& trie, unordered_set<int>& failedPosition, string& sentence, vector<string>& sentences) {
        if (failedPosition.count(start) != 0) {  // 前面已经计算过，以该位置为开始会分割失败
            return false;
        }

        if (start == s.size()) {  // 整个s都已经匹配上了，说明找到一个分割方法
            sentences.push_back(sentence);  // 为简化后面回溯的处理，这里不要直接修改sentence，先把sentence拷贝到sentences里面，再去掉最后的空格
            sentences.back().pop_back();
            return true;
        }

        TrieNode* startNode = NULL;
        TrieNode* endNode = NULL;
        int end, searchFrom = start;
        bool success = false;

        while ((end = trie.search(s, searchFrom, startNode, &endNode)) != -1) {  // 利用字典树快速匹配
            sentence.append(s, start, end - start + 1);  // 当前位置匹配上一个单词，保存到sentence
            sentence += ' ';

            if (DFS(s, end + 1, trie, failedPosition, sentence, sentences)) {  // DFS进入下一跳继续匹配
                success = true;  // 如果最终DFS成功了，说明start位置有解
            }

            int len = end - start + 1 + 1;
            sentence.erase(sentence.size() - len, len);  // 回溯，当前的word删除，尝试有没有更长的匹配项
            searchFrom = end + 1;  // 从当前word结尾的下一个字符继续匹配
            startNode = endNode;
        }

        if (!success) {
            failedPosition.insert(start);  // 如果所有的DFS都没有成功过，记录该位置不可行
        }

        return success;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> wordDict = { "cat","cats","and","sand","dog" };
    vector<string> actual = o.wordBreak("catsanddog", wordDict);
    vector<string> expected = { "cats and dog","cat sand dog" };
    check.checkStringVectorRandomOrder(expected, actual);

    wordDict = { "apple","pen","applepen","pine","pineapple" };
    actual = o.wordBreak("pineapplepenapple", wordDict);
    expected = { "pine apple pen apple","pineapple pen apple","pine applepen apple" };
    check.checkStringVectorRandomOrder(expected, actual);

    wordDict = { "cats","dog","sand","and","cat" };
    actual = o.wordBreak("catsandog", wordDict);
    expected = {  };
    check.checkStringVectorRandomOrder(expected, actual);

    wordDict = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    actual = o.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", wordDict);
    expected = {  };
    check.checkStringVectorRandomOrder(expected, actual);
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
