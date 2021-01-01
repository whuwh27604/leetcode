/* 词典中最长的单词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。

若无答案，则返回空字符串。

示例 1:

输入:
words = ["w","wo","wor","worl", "world"]
输出: "world"
解释:
单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。
示例 2:

输入:
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
输出: "apple"
解释:
"apply"和"apple"都能由词典中的单词组成。但是"apple"得字典序小于"apply"。
注意:

所有输入的字符串都只包含小写字母。
words数组长度范围为[1,1000]。
words[i]的长度范围为[1,30]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-word-in-dictionary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode(bool _isEnd) {
        memset(next, 0, sizeof(TrieNode*) * 26);
        isEnd = _isEnd;
    }

    bool isEnd;
    TrieNode* next[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode(false);
    }

    bool CheckIfAddingOneWord(string& word) {
        TrieNode* current = root;
        int i, index, size = word.size();

        for (i = 0; i < size - 1; ++i) {
            index = word[i] - 'a';

            if (current->next[index] == NULL || !current->next[index]->isEnd) {
                return false;
            }

            current = current->next[index];
        }

        index = word[i] - 'a';
        current->next[index] = new TrieNode(true);

        return true;
    }

private:
    TrieNode* root;
};

bool stringCompare(const string& s1, const string& s2) {
    return s1.size() == s2.size() ? s1 < s2 : s1.size() < s2.size();
}

class Solution {
public:
    string longestWord(vector<string>& words) {
        string maxLenWord;
        Trie trie;

        sort(words.begin(), words.end(), stringCompare);

        for (string& word : words) {
            if (trie.CheckIfAddingOneWord(word) && word.size() > maxLenWord.size()) {
                maxLenWord = word;
            }
        }

        return maxLenWord;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> words = { "w","wo","wor","worl", "world" };
    check.checkString("world", o.longestWord(words));

    words = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
    check.checkString("apple", o.longestWord(words));

    words = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaab", "aaaaabb", "aaaaabbb", "aaaaabbbb", "aaaaabbbbb", "aaaaabbbbbc", "aaaaabbbbbcc", \
        "aaaaabbbbbccc", "aaaaabbbbbcccc", "aaaaabbbbbccccc", "aaaaabbbbbcccccd", "aaaaabbbbbcccccdd", "aaaaabbbbbcccccddd", "aaaaabbbbbcccccdddd",
        "aaaaabbbbbcccccddddd", "aaaaabbbbbcccccddddde", "aaaaabbbbbcccccdddddee", "aaaaabbbbbcccccdddddeee", "aaaaabbbbbcccccdddddeeee", "aaaaabbbbbcccccdddddeeeee", \
        "aaaaabbbbbcccccdddddeeeee", "aaaaabbbbbcccccdddddeeeeef", "aaaaabbbbbcccccdddddeeeeeff", "aaaaabbbbbcccccdddddeeeeefff", "aaaaabbbbbcccccdddddeeeeeffff", "aaaaabbbbbcccccdddddeeeeefffff" };
    check.checkString("aaaaabbbbbcccccdddddeeeeefffff", o.longestWord(words));

    words = { "a", "ab", "abc", "abcde" };
    check.checkString("abc", o.longestWord(words));

    words = { "a", "b", "c", "abcde" };
    check.checkString("a", o.longestWord(words));

    words = { "ab" };
    check.checkString("", o.longestWord(words));

    words = { "azx", "abc", "az", "ab", "a" };
    check.checkString("abc", o.longestWord(words));

    words = { "abcde", "azxdy", "abcd", "azxd", "azx", "abc", "az", "ab", "a" };
    check.checkString("abcde", o.longestWord(words));

    words = { "m","mo","moc","moch","mocha","l","la","lat","latt","latte","c","ca","cat" };
    check.checkString("latte", o.longestWord(words));
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
