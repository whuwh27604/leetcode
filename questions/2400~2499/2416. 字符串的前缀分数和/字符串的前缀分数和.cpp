/* 字符串的前缀分数和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的数组 words ，该数组由 非空 字符串组成。

定义字符串 word 的 分数 等于以 word 作为 前缀 的 words[i] 的数目。

例如，如果 words = ["a", "ab", "abc", "cab"] ，那么 "ab" 的分数是 2 ，因为 "ab" 是 "ab" 和 "abc" 的一个前缀。
返回一个长度为 n 的数组 answer ，其中 answer[i] 是 words[i] 的每个非空前缀的分数 总和 。

注意：字符串视作它自身的一个前缀。

 

示例 1：

输入：words = ["abc","ab","bc","b"]
输出：[5,4,3,2]
解释：对应每个字符串的答案如下：
- "abc" 有 3 个前缀："a"、"ab" 和 "abc" 。
- 2 个字符串的前缀为 "a" ，2 个字符串的前缀为 "ab" ，1 个字符串的前缀为 "abc" 。
总计 answer[0] = 2 + 2 + 1 = 5 。
- "ab" 有 2 个前缀："a" 和 "ab" 。
- 2 个字符串的前缀为 "a" ，2 个字符串的前缀为 "ab" 。
总计 answer[1] = 2 + 2 = 4 。
- "bc" 有 2 个前缀："b" 和 "bc" 。
- 2 个字符串的前缀为 "b" ，1 个字符串的前缀为 "bc" 。
总计 answer[2] = 2 + 1 = 3 。
- "b" 有 1 个前缀："b"。
- 2 个字符串的前缀为 "b" 。
总计 answer[3] = 2 。
示例 2：

输入：words = ["abcd"]
输出：[4]
解释：
"abcd" 有 4 个前缀 "a"、"ab"、"abc" 和 "abcd"。
每个前缀的分数都是 1 ，总计 answer[0] = 1 + 1 + 1 + 1 = 4 。
 

提示：

1 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sum-of-prefix-scores-of-strings
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
    }

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
            ++node->count;
        }
    }

    int search(string& word) {
        TrieNode* node = root;
        int cnt = 0;

        for (char c : word) {
            node = node->next[c - 'a'];
            cnt += node->count;
        }

        return cnt;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int index = 0, size = words.size();
        vector<int> ans(size);
        Trie trie;

        for (string& word : words) {
            trie.insert(word);
        }

        for (string& word : words) {
            ans[index++] = trie.search(word);
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "abc","ab","bc","b" };
    vector<int> actual = o.sumPrefixScores(words);
    vector<int> expected = { 5,4,3,2 };
    check.checkIntVector(expected, actual);

    words = { "abcd" };
    actual = o.sumPrefixScores(words);
    expected = { 4 };
    check.checkIntVector(expected, actual);
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
