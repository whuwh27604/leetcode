/* 前缀和后缀搜索.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个包含一些单词的特殊词典，并能够通过前缀和后缀来检索单词。

实现 WordFilter 类：

WordFilter(string[] words) 使用词典中的单词 words 初始化对象。
f(string prefix, string suffix) 返回词典中具有前缀 prefix 和后缀suffix 的单词的下标。如果存在不止一个满足要求的下标，返回其中 最大的下标 。如果不存在这样的单词，返回 -1 。


示例

输入：
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
输出：
[null, 0]

解释：
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // 返回 0 ，因为下标为 0 的单词的 prefix = "a" 且 suffix = 'e" 。

提示：

1 <= words.length <= 15000
1 <= words[i].length <= 10
1 <= prefix.length, suffix.length <= 10
words[i]、prefix 和 suffix 仅由小写英文字母组成
最多对函数 f 进行 15000 次调用

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/prefix-and-suffix-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class SuffTrieNode {
public:
    SuffTrieNode() {
        memset(next, 0, sizeof(SuffTrieNode*) * 26);
        maxIndex = -1;
    }

    SuffTrieNode* next[26];
    int maxIndex;
};

class SuffTrie {
public:
    SuffTrieNode* root;

    SuffTrie() {
        root = new SuffTrieNode();
    }

    void insert(string& word, int index) {
        SuffTrieNode* node = root;

        for (int i = word.size() - 1; i >= 0; --i) {
            int idx = word[i] - 'a';

            if (node->next[idx] == NULL) {
                node->next[idx] = new SuffTrieNode();
            }

            node = node->next[idx];
            node->maxIndex = index;
        }
    }

    int search(string& word) {
        SuffTrieNode* node = root;

        for (int i = word.size() - 1; i >= 0; --i) {
            int idx = word[i] - 'a';

            if (node->next[idx] == NULL) {
                return -1;
            }

            node = node->next[idx];
        }

        return node->maxIndex;
    }
};

class PrefTrieNode {
public:
    PrefTrieNode() {
        memset(next, 0, sizeof(PrefTrieNode*) * 26);
    }

    PrefTrieNode* next[26];
    SuffTrie trie;
};

class PrefTrie {
public:
    PrefTrieNode* root;

    PrefTrie() {
        root = new PrefTrieNode();
    }

    void insert(string& word, int index) {
        PrefTrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (node->next[idx] == NULL) {
                node->next[idx] = new PrefTrieNode();
            }

            node = node->next[idx];
            node->trie.insert(word, index);
        }
    }

    int search(string& pref, string& suff) {
        PrefTrieNode* node = root;

        for (char c : pref) {
            int idx = c - 'a';

            if (node->next[idx] == NULL) {
                return -1;
            }

            node = node->next[idx];
        }

        return node->trie.search(suff);
    }
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < (int)words.size(); ++i) {
            trie.insert(words[i], i);
        }
    }

    int f(string pref, string suff) {
        return trie.search(pref, suff);
    }

private:
    PrefTrie trie;
};

int main()
{
    CheckResult check;

    vector<string> words = { "apple" };
    WordFilter o1(words);
    check.checkInt(0, o1.f("a", "e"));
    check.checkInt(-1, o1.f("a", "f"));
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
