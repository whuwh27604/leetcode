/* 实现 Trie (前缀树).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
 

示例：

输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
 

提示：

1 <= word.length, prefix.length <= 2000
word 和 prefix 仅由小写英文字母组成
insert、search 和 startsWith 调用次数 总计 不超过 3 * 104 次

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

    /** Inserts a word into the trie. */
    void insert(string word) {
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* current = root;

        for (char c : word) {
            int index = c - 'a';
            if (current->next[index] == NULL) {
                return false;
            }

            current = current->next[index];
        }

        return current->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* current = root;

        for (char c : prefix) {
            int index = c - 'a';
            if (current->next[index] == NULL) {
                return false;
            }

            current = current->next[index];
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
