/* 统计前后缀下标对 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串数组 words 。

定义一个 布尔 函数 isPrefixAndSuffix ，它接受两个字符串参数 str1 和 str2 ：

当 str1 同时是 str2 的前缀（
prefix
）和后缀（
suffix
）时，isPrefixAndSuffix(str1, str2) 返回 true，否则返回 false。
例如，isPrefixAndSuffix("aba", "ababa") 返回 true，因为 "aba" 既是 "ababa" 的前缀，也是 "ababa" 的后缀，但是 isPrefixAndSuffix("abc", "abcd") 返回 false。

以整数形式，返回满足 i < j 且 isPrefixAndSuffix(words[i], words[j]) 为 true 的下标对 (i, j) 的 数量 。



示例 1：

输入：words = ["a","aba","ababa","aa"]
输出：4
解释：在本示例中，计数的下标对包括：
i = 0 且 j = 1 ，因为 isPrefixAndSuffix("a", "aba") 为 true 。
i = 0 且 j = 2 ，因为 isPrefixAndSuffix("a", "ababa") 为 true 。
i = 0 且 j = 3 ，因为 isPrefixAndSuffix("a", "aa") 为 true 。
i = 1 且 j = 2 ，因为 isPrefixAndSuffix("aba", "ababa") 为 true 。
因此，答案是 4 。
示例 2：

输入：words = ["pa","papa","ma","mama"]
输出：2
解释：在本示例中，计数的下标对包括：
i = 0 且 j = 1 ，因为 isPrefixAndSuffix("pa", "papa") 为 true 。
i = 2 且 j = 3 ，因为 isPrefixAndSuffix("ma", "mama") 为 true 。
因此，答案是 2 。
示例 3：

输入：words = ["abab","ab"]
输出：0
解释：在本示例中，唯一有效的下标对是 i = 0 且 j = 1 ，但是 isPrefixAndSuffix("abab", "ab") 为 false 。
因此，答案是 0 。


提示：

1 <= words.length <= 105
1 <= words[i].length <= 105
words[i] 仅由小写英文字母组成。
所有 words[i] 的长度之和不超过 5 * 105 。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode() {
        count = 0;
    }

    unordered_map<int, TrieNode*> next;
    int count;
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
    }

    void insert(string& word) {
        TrieNode* node = root;
        int size = word.size();

        for (int i = 0; i < size; ++i) {
            int key = ((word[i] << 8) | word[size - 1 - i]);

            if (node->next.count(key) == 0) {
                node->next[key] = new TrieNode;
            }

            node = node->next[key];
            ++node->count;
        }
    }

    int search(string& word) {
        TrieNode* node = root;
        int size = word.size();

        for (int i = 0; i < size; ++i) {
            int key = ((word[i] << 8) | word[size - 1 - i]);

            if (node->next.count(key) == 0) {
                return 0;
            }

            node = node->next[key];
        }

        return node->count;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long pairs = 0;
        Trie trie;

        for (int i = words.size() - 1; i >= 0; --i) {
            pairs += trie.search(words[i]);
            trie.insert(words[i]);
        }

        return pairs;
    }
};

int main()
{
	Solution o;
	CheckResult check;

    vector<string> words = { "a","aba","ababa","aa" };
    check.checkLongLong(4, o.countPrefixSuffixPairs(words));

    words = { "pa","papa","ma","mama" };
    check.checkLongLong(2, o.countPrefixSuffixPairs(words));

    words = { "abab","ab" };
    check.checkLongLong(0, o.countPrefixSuffixPairs(words));

    words = { "a","a" };
    check.checkLongLong(1, o.countPrefixSuffixPairs(words));

    words = { "a","aa","aa","b","ab" };
    check.checkLongLong(3, o.countPrefixSuffixPairs(words));

    words = { "b","a","b","a","b" };
    check.checkLongLong(4, o.countPrefixSuffixPairs(words));
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
