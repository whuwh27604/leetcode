/* 搜索推荐系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个产品数组 products 和一个字符串 searchWord ，products  数组中每个产品都是一个字符串。

请你设计一个推荐系统，在依次输入单词 searchWord 的每一个字母后，推荐 products 数组中前缀与 searchWord 相同的最多三个产品。如果前缀相同的可推荐产品超过三个，请按字典序返回最小的三个。

请你以二维列表的形式，返回在输入 searchWord 每个字母后相应的推荐产品的列表。

 

示例 1：

输入：products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
输出：[
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
解释：按字典序排序后的产品列表是 ["mobile","moneypot","monitor","mouse","mousepad"]
输入 m 和 mo，由于所有产品的前缀都相同，所以系统返回字典序最小的三个产品 ["mobile","moneypot","monitor"]
输入 mou， mous 和 mouse 后系统都返回 ["mouse","mousepad"]
示例 2：

输入：products = ["havana"], searchWord = "havana"
输出：[["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
示例 3：

输入：products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
输出：[["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
示例 4：

输入：products = ["havana"], searchWord = "tatiana"
输出：[[],[],[],[],[],[],[]]
 

提示：

1 <= products.length <= 1000
1 <= Σ products[i].length <= 2 * 10^4
products[i] 中所有的字符都是小写英文字母。
1 <= searchWord.length <= 1000
searchWord 中所有字符都是小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-suggestions-system
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(TrieNode*) * 26);
        count = 0;
        isEnd = false;
    }

    void addCount() {
        ++count;
    }

    int getCount() {
        return count;
    }

    bool isEnd;
    int count;
    TrieNode* next[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
    }

    void insert(string& word) {
        TrieNode* node = root;

        for (char c : word) {
            int index = c - 'a';
            if (node->next[index] == NULL) {
                node->next[index] = new TrieNode;
            }

            node = node->next[index];
        }

        node->isEnd = true;
        node->addCount();
    }

    void search(string& searchWord, vector<vector<string>>& words) {
        TrieNode* node = root;
        string word;
        int idx = 0;

        for (char c : searchWord) {
            int index = c - 'a';
            if (node->next[index] == NULL) {
                return;
            }

            node = node->next[index];
            word += c;
            DFS(node, word, words[idx++]);
        }
    }

    void DFS(TrieNode* node, string& word, vector<string>& words) {
        if (node->isEnd) {
            for (int i = 0; i < node->getCount(); ++i) {
                words.push_back(word);
                if (words.size() == 3) {
                    return;
                }
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (node->next[i] != NULL) {
                word += ('a' + i);
                DFS(node->next[i], word, words);
                word.pop_back();
            }

            if (words.size() == 3) {
                break;
            }
        }
    }

private:
    TrieNode* root;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for (string& product : products) {
            trie.insert(product);
        }

        vector<vector<string>> suggested(searchWord.size(), vector<string>{});
        trie.search(searchWord, suggested);

        return suggested;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> products = { "mobile","mouse","moneypot","monitor","mousepad" };
    vector<vector<string>> actual = o.suggestedProducts(products, "mouse");
    vector<vector<string>> expected = { {"mobile","moneypot","monitor"},{"mobile","moneypot","monitor"},{"mouse","mousepad"},{"mouse","mousepad"},{"mouse","mousepad"} };
    check.checkStringVectorVector(expected, actual);

    products = { "havana" };
    actual = o.suggestedProducts(products, "havana");
    expected = { {"havana"},{"havana"},{"havana"},{"havana"},{"havana"},{"havana"} };
    check.checkStringVectorVector(expected, actual);

    products = { "bags","baggage","banner","box","cloths" };
    actual = o.suggestedProducts(products, "bags");
    expected = { {"baggage","bags","banner"},{"baggage","bags","banner"},{"baggage","bags"},{"bags"} };
    check.checkStringVectorVector(expected, actual);

    products = { "havana" };
    actual = o.suggestedProducts(products, "tatiana");
    expected = { {},{},{},{},{},{},{} };
    check.checkStringVectorVector(expected, actual);

    products = { "a","a","a","a","ab","abc" };
    actual = o.suggestedProducts(products, "abcd");
    expected = { {"a","a","a"},{"ab","abc"},{"abc"},{} };
    check.checkStringVectorVector(expected, actual);
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
