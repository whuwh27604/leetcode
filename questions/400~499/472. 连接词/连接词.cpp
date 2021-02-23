/* 连接词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个 不含重复 单词的字符串数组 words ，编写一个程序，返回 words 中的所有 连接词 。

连接词 的定义为：一个字符串完全是由至少两个给定数组中的单词组成的。

 

示例 1：

输入：words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
输出：["catsdogcats","dogcatsdog","ratcatdogcat"]
解释："catsdogcats"由"cats", "dog" 和 "cats"组成;
     "dogcatsdog"由"dog", "cats"和"dog"组成;
     "ratcatdogcat"由"rat", "cat", "dog"和"cat"组成。
示例 2：

输入：words = ["cat","dog","catdog"]
输出：["catdog"]
 

提示：

1 <= words.length <= 104
0 <= words[i].length <= 1000
words[i] 仅由小写字母组成
0 <= sum(words[i].length) <= 6 * 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/concatenated-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

bool stringCompare(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

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

    bool isConcatenatedWord(string& word) {
        vector<bool> visited(word.size(), false);

        return DFS(word, 0, visited);
    }

    bool DFS(string& word, int start, vector<bool>& visited) {
        int i, size = word.size();
        TrieNode* current = root;

        if (start == size) {
            return true;
        }

        if (visited[start]) {
            return false;
        }

        for (i = start; i < size; ++i) {
            int index = word[i] - 'a';
            if (current->next[index] == NULL) {
                break;
            }

            current = current->next[index];
            if (current->isEnd) {
                if (DFS(word, i + 1, visited)) {
                    return true;
                }
            }
        }

        visited[start] = true;
        return false;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> concatenatedWords;
        Trie trie;

        sort(words.begin(), words.end(), stringCompare);

        auto iter = words.begin();
        if (*iter == "") {
            ++iter;
        }

        for (; iter != words.end(); ++iter) {
            if (trie.isConcatenatedWord(*iter)) {
                concatenatedWords.push_back(*iter);
            }

            trie.insert(*iter);
        }

        return concatenatedWords;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "cat","dog","catdog" };
    vector<string> actual = o.findAllConcatenatedWordsInADict(words);
    vector<string> expected = { "catdog" };
    check.checkStringVectorRandomOrder(expected, actual);

    words = { "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat" };
    actual = o.findAllConcatenatedWordsInADict(words);
    expected = { "catsdogcats","dogcatsdog","ratcatdogcat" };
    check.checkStringVectorRandomOrder(expected, actual);

    words = { "" };
    actual = o.findAllConcatenatedWordsInADict(words);
    expected = {  };
    check.checkStringVectorRandomOrder(expected, actual);

    words = { "","a" };
    actual = o.findAllConcatenatedWordsInADict(words);
    expected = {  };
    check.checkStringVectorRandomOrder(expected, actual);

    words = { "a","aa" };
    actual = o.findAllConcatenatedWordsInADict(words);
    expected = { "aa" };
    check.checkStringVectorRandomOrder(expected, actual);

    words = { "cat","catcat" };
    actual = o.findAllConcatenatedWordsInADict(words);
    expected = { "catcat" };
    check.checkStringVectorRandomOrder(expected, actual);

    words = getStringVector("./testcase1.txt");
    actual = o.findAllConcatenatedWordsInADict(words);
    expected = getStringVector("./testcase1Expected.txt");
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
