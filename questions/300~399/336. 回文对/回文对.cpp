/* 回文对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一组 互不相同 的单词， 找出所有 不同 的索引对 (i, j)，使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串。

 

示例 1：

输入：words = ["abcd","dcba","lls","s","sssll"]
输出：[[0,1],[1,0],[3,2],[2,4]]
解释：可拼接成的回文串为 ["dcbaabcd","abcddcba","slls","llssssll"]
示例 2：

输入：words = ["bat","tab","cat"]
输出：[[0,1],[1,0]]
解释：可拼接成的回文串为 ["battab","tabbat"]
示例 3：

输入：words = ["a",""]
输出：[[0,1],[1,0]]
 
提示：

1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/palindrome-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(TrieNode*) * 26);
        index = -1;
    }

    int index;
    TrieNode* next[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
    }

    void insert(string& word, int idx) {
        TrieNode* node = root;

        for (int i = 0; i < (int)word.size(); ++i) {
            int j = word[i] - 'a';
            if (node->next[j] == NULL) {
                node->next[j] = new TrieNode;
            }

            node = node->next[j];
        }

        node->index = idx;
    }

    int getMatchIndex(string& word, int start, int end) {
        TrieNode* node = root;

        for (int i = start; i >= end; --i) {
            int j = word[i] - 'a';
            if (node->next[j] == NULL) {
                return -1;
            }

            node = node->next[j];
        }

        return node->index;
    }

private:
    TrieNode* root;
};

class Manacher {
public:
    Manacher(string& s) {
        preprocess(s);
        radii.resize(ms.size());
        calculate();
    }

    void preprocess(string& s) {
        ms += "@#";  // 首尾添加字符@、$，可以简化后面算法的边界处理

        for (char c : s) {
            ms += c;
            ms += '#';  // 每个字符前后插入#，可以使奇偶回文都变为奇回文，简化算法的处理
        }

        ms += '$';
    }

    void calculate() {
        /*   symmetryMaxRight   symmetryI     center          i            maxRight
        ------------|---------------|------------|------------|---------------|-------- */
        int i, size = ms.size();
        int center, maxRight = 0;

        for (i = 1; i < size - 1; i++) {
            if (i < maxRight) {
                /* （2 * center - i）是symmetryI，分三种情况可证明下面这句话成立：
                   1、radii[symmetryI]大于(symmetryI-symmetryMaxRight)，则radii[i]=(symmetryI-symmetryMaxRight)=(maxRight-i)，不能再大
                   2、radii[symmetryI]小于(symmetryI-symmetryMaxRight)，则radii[i]=radii[symmetryI]，不能再大
                   3、radii[symmetryI]等于(symmetryI-symmetryMaxRight)，则radii[i]=radii[symmetryI]=(maxRight-i)，然后执行下面的while语句继续拓展 */
                radii[i] = min(radii[2 * center - i], maxRight - i);
            }
            else {
                radii[i] = 1;
            }

            // 中心拓展找最大的半径，预处理在首尾添加的不同字符保证不会越界
            while (ms[i - radii[i]] == ms[i + radii[i]]) {
                radii[i]++;
            }

            // 每走一步i，都要维护maxRight。我们希望maxRight尽可能往右，这样才能更有机会执行if (i < maxRight)提高效率
            if (maxRight < i + radii[i]) {
                center = i;
                maxRight = i + radii[i];
            }
        }
    }

    bool isPalindrome(int start, int end) {
        return radii[(start + 1) + (end + 1)] / 2 >= (end - start + 2) / 2;
    }

private:
    string ms;
    vector<int> radii;
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> pairs;
        Trie trie;
        int size = words.size();

        for (int i = 0; i < size; ++i) {
            trie.insert(words[i], i);
        }

        for (int i = 0; i < size; ++i) {
            string& word = words[i];
            int index = -1;

            if (!word.empty()) {
                int len = word.size();
                Manacher manacher(word);

                for (int j = 0; j < len; ++j) {
                    if (manacher.isPalindrome(0, j)) {
                        index = trie.getMatchIndex(word, len - 1, j + 1);
                        if (index != -1) {
                            pairs.push_back({ index, i });
                        }
                    }

                    if (manacher.isPalindrome(j, len - 1)) {
                        index = trie.getMatchIndex(word, j - 1, 0);
                        if (index != -1) {
                            pairs.push_back({ i, index });
                        }
                    }
                }

                index = trie.getMatchIndex(word, len - 1, 0);
                if (index != -1 && index != i) {
                    pairs.push_back({ i, index });
                }
            }
        }

        return pairs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "abcd","dcba","lls","s","sssll" };
    vector<vector<int>> actual = o.palindromePairs(words);
    vector<vector<int>> expected = { {0,1},{1,0},{3,2},{2,4} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    words = { "bat","tab","cat" };
    actual = o.palindromePairs(words);
    expected = { {0,1},{1,0} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    words = { "a","" };
    actual = o.palindromePairs(words);
    expected = { {0,1},{1,0} };
    check.checkIntVectorRandomOrderVector(expected, actual);
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
