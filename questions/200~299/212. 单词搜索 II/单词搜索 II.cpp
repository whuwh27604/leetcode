/* 单词搜索 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

 

示例 1：


输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
输出：["eat","oath"]
示例 2：


输入：board = [["a","b"],["c","d"]], words = ["abcb"]
输出：[]
 

提示：

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] 是一个小写英文字母
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] 由小写英文字母组成
words 中的所有字符串互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    string word;
    unordered_map<char, TrieNode*> next;
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
    }

    void insert(string& word) {
        TrieNode* node = root;

        for (char c : word) {
            if (node->next.count(c) == 0) {
                node->next[c] = new TrieNode;
            }

            node = node->next[c];
        }

        node->word = word;
    }

    void remove(string& word) {
        int i, size = word.size();
        TrieNode* node = root;
        stack<TrieNode*> nodes;
        nodes.push(root);

        for (i = 0; i < size; ++i) {
            nodes.push(node->next[word[i]]);
            node = node->next[word[i]];
        }

        for (i = size - 1; i >= 0 && node->word.empty() && node->next.empty(); --i) {
            nodes.pop();
            node = nodes.top();
            node->next.erase(word[i]);
        }
    }

    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int i, j, row = board.size(), column = board[0].size();
        vector<string> matchWords;
        Trie trie;

        buildTrie(trie, words);

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (trie.root->next.count(board[i][j]) != 0) {
                    DFS(board, trie, trie.root->next[board[i][j]], i, j, matchWords);
                }
            }
        }

        return matchWords;
    }

    void buildTrie(Trie& trie, vector<string>& words) {
        for (string& word : words) {
            trie.insert(word);
        }
    }

    void DFS(vector<vector<char>>& board, Trie& trie, TrieNode* node, int r, int c, vector<string>& matchWords) {
        if (!node->word.empty()) {
            matchWords.push_back(node->word);
            string saveWord = node->word;
            node->word.clear();
            trie.remove(saveWord);
        }

        int row = board.size(), column = board[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        board[r][c] = -board[r][c];

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];

            if (nr >= 0 && nr < row && nc >= 0 && nc < column && node->next.count(board[nr][nc]) != 0) {
                DFS(board, trie, node->next[board[nr][nc]], nr, nc, matchWords);
            }
        }

        board[r][c] = -board[r][c];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<char>> board = { {'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'} };
    vector<string> words = { "oath","pea","eat","rain" };
    vector<string> actual = o.findWords(board, words);
    vector<string> expected = { "eat","oath" };
    check.checkStringVectorRandomOrder(expected, actual);

    board = { {'a','b'},{'c','d'} };
    words = { "abcb" };
    actual = o.findWords(board, words);
    expected = {};
    check.checkStringVectorRandomOrder(expected, actual);

    board = { {'a','b'},{'b','c'},{'e','d'} };
    words = { "abcdeb" };
    actual = o.findWords(board, words);
    expected = { "abcdeb" };
    check.checkStringVectorRandomOrder(expected, actual);

    board = { {'b','c','d'},{'a','b','e'} };
    words = { "abcdeb" };
    actual = o.findWords(board, words);
    expected = { "abcdeb" };
    check.checkStringVectorRandomOrder(expected, actual);

    board = { {'w','v','n'},{'t','a','e'},{'h','k','r'} };
    words = { "a","av","ae","ak","at" };
    actual = o.findWords(board, words);
    expected = { "a","av","ae","ak","at" };
    check.checkStringVectorRandomOrder(expected, actual);

    board = { {'a','a'} };
    words = { "aaa" };
    actual = o.findWords(board, words);
    expected = {};
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
