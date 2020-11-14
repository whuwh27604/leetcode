/* 添加与搜索单词 - 数据结构设计.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个支持以下两种操作的数据结构：

void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
说明:

你可以假设所有单词都是由小写字母 a-z 组成的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-and-search-word-data-structure-design
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
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

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode;
    }

    ~WordDictionary() {
        list<TrieNode*> nodes;
        nodes.push_back(root);

        while (!nodes.empty()) {
            int i, j, size = nodes.size();
            for (i = 0; i < size; i++) {
                TrieNode* node = nodes.front();
                nodes.pop_front();
                for (j = 0; j < 26; j++) {
                    if (node->next[j] != NULL) {
                        nodes.push_back(node->next[j]);
                    }
                }

                delete node;
            }
        }
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* nextNode = root;

        for (char c : word) {
            int index = c - 'a';
            if (nextNode->next[index] == NULL) {
                nextNode->next[index] = new TrieNode;
            }

            nextNode = nextNode->next[index];
        }

        nextNode->isEnd = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        list<TrieNode*> nextNodes;
        nextNodes.push_back(root);

        for (char c : word) {
            int i, j, size = nextNodes.size();
            if (c == '.') {
                for (i = 0; i < size; i++) {
                    TrieNode* node = nextNodes.front();
                    nextNodes.pop_front();
                    for (j = 0; j < 26; j++) {
                        if (node->next[j] != NULL) {
                            nextNodes.push_back(node->next[j]);
                        }
                    }
                }
            }
            else {
                for (i = 0; i < size; i++) {
                    TrieNode* node = nextNodes.front();
                    nextNodes.pop_front();
                    if (node->next[c - 'a'] != NULL) {
                        nextNodes.push_back(node->next[c - 'a']);
                    }
                }
            }
        }

        for (TrieNode* node : nextNodes) {
            if (node->isEnd) {
                return true;
            }
        }
        return false;
    }

    TrieNode* root;
};

int main()
{
    WordDictionary o;
    CheckResult check;

    check.checkBool(false, o.search(""));
    check.checkBool(false, o.search("a"));
    check.checkBool(false, o.search("b"));
    o.addWord("bad");
    o.addWord("dad");
    o.addWord("mad");
    check.checkBool(false, o.search("pad"));
    check.checkBool(true, o.search("bad"));
    check.checkBool(true, o.search(".ad"));
    check.checkBool(true, o.search("b.."));
    check.checkBool(true, o.search("..."));
    check.checkBool(false, o.search("b..."));
    check.checkBool(false, o.search("...."));
    check.checkBool(false, o.search(".ad."));
    o.addWord("x");
    check.checkBool(true, o.search("x"));
    check.checkBool(true, o.search("."));
    check.checkBool(false, o.search("x."));
    check.checkBool(false, o.search(".x"));
    check.checkBool(false, o.search(".."));
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
