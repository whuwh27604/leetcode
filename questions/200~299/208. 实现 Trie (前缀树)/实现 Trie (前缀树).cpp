/* 实现 Trie (前缀树).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");
trie.search("app");     // 返回 true
说明:

你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree
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

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }

    ~Trie() {
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

    /** Inserts a word into the trie. */
    void insert(string word) {
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* nextNode = root;

        for (char c : word) {
            int index = c - 'a';
            if (nextNode->next[index] == NULL) {
                return false;
            }

            nextNode = nextNode->next[index];
        }

        return nextNode->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* nextNode = root;

        for (char c : prefix) {
            int index = c - 'a';
            if (nextNode->next[index] == NULL) {
                return false;
            }

            nextNode = nextNode->next[index];
        }

        return true;
    }

    TrieNode* root;
};

int main()
{
    CheckResult check;

    Trie trie;
    check.checkBool(false, trie.search("a"));
    check.checkBool(false, trie.startsWith("a"));
    trie.insert("apple");
    check.checkBool(true, trie.search("apple"));
    check.checkBool(false, trie.search("app"));
    check.checkBool(true, trie.startsWith("app"));
    trie.insert("app");
    check.checkBool(true, trie.search("app"));
    trie.insert("box");
    check.checkBool(true, trie.search("box"));
    check.checkBool(true, trie.startsWith("box"));
    check.checkBool(true, trie.startsWith("b"));
    check.checkBool(false, trie.startsWith("boxe"));
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
