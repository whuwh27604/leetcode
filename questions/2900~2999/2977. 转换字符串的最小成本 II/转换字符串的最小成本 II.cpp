/* 转换字符串的最小成本 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的字符串 source 和 target ，它们的长度均为 n 并且由 小写 英文字母组成。

另给你两个下标从 0 开始的字符串数组 original 和 changed ，以及一个整数数组 cost ，其中 cost[i] 代表将字符串 original[i] 更改为字符串 changed[i] 的成本。

你从字符串 source 开始。在一次操作中，如果 存在 任意 下标 j 满足 cost[j] == z  、original[j] == x 以及 changed[j] == y ，你就可以选择字符串中的 子串 x 并以 z 的成本将其更改为 y 。 你可以执行 任意数量 的操作，但是任两次操作必须满足 以下两个 条件 之一 ：

在两次操作中选择的子串分别是 source[a..b] 和 source[c..d] ，满足 b < c  或 d < a 。换句话说，两次操作中选择的下标 不相交 。
在两次操作中选择的子串分别是 source[a..b] 和 source[c..d] ，满足 a == c 且 b == d 。换句话说，两次操作中选择的下标 相同 。
返回将字符串 source 转换为字符串 target 所需的 最小 成本。如果不可能完成转换，则返回 -1 。

注意，可能存在下标 i 、j 使得 original[j] == original[i] 且 changed[j] == changed[i] 。



示例 1：

输入：source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
输出：28
解释：将 "abcd" 转换为 "acbe"，执行以下操作：
- 将子串 source[1..1] 从 "b" 改为 "c" ，成本为 5 。
- 将子串 source[2..2] 从 "c" 改为 "e" ，成本为 1 。
- 将子串 source[2..2] 从 "e" 改为 "b" ，成本为 2 。
- 将子串 source[3..3] 从 "d" 改为 "e" ，成本为 20 。
产生的总成本是 5 + 1 + 2 + 20 = 28 。
可以证明这是可能的最小成本。
示例 2：

输入：source = "abcdefgh", target = "acdeeghh", original = ["bcd","fgh","thh"], changed = ["cde","thh","ghh"], cost = [1,3,5]
输出：9
解释：将 "abcdefgh" 转换为 "acdeeghh"，执行以下操作：
- 将子串 source[1..3] 从 "bcd" 改为 "cde" ，成本为 1 。
- 将子串 source[5..7] 从 "fgh" 改为 "thh" ，成本为 3 。可以执行此操作，因为下标 [5,7] 与第一次操作选中的下标不相交。
- 将子串 source[5..7] 从 "thh" 改为 "ghh" ，成本为 5 。可以执行此操作，因为下标 [5,7] 与第一次操作选中的下标不相交，且与第二次操作选中的下标相同。
产生的总成本是 1 + 3 + 5 = 9 。
可以证明这是可能的最小成本。
示例 3：

输入：source = "abcdefgh", target = "addddddd", original = ["bcd","defgh"], changed = ["ddd","ddddd"], cost = [100,1578]
输出：-1
解释：无法将 "abcdefgh" 转换为 "addddddd" 。
如果选择子串 source[1..3] 执行第一次操作，以将 "abcdefgh" 改为 "adddefgh" ，你无法选择子串 source[3..7] 执行第二次操作，因为两次操作有一个共用下标 3 。
如果选择子串 source[3..7] 执行第一次操作，以将 "abcdefgh" 改为 "abcddddd" ，你无法选择子串 source[1..3] 执行第二次操作，因为两次操作有一个共用下标 3 。


提示：

1 <= source.length == target.length <= 1000
source、target 均由小写英文字母组成
1 <= cost.length == original.length == changed.length <= 100
1 <= original[i].length == changed[i].length <= source.length
original[i]、changed[i] 均由小写英文字母组成
original[i] != changed[i]
1 <= cost[i] <= 106
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    int index;
    TrieNode* next[26];

    TrieNode() {
        index = -1;
        memset(next, 0, sizeof(TrieNode*) * 26);
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode;
    }

    bool insert(string& word, int index) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';
            if (node->next[idx] == NULL) {
                node->next[idx] = new TrieNode;
            }

            node = node->next[idx];
        }

        if (node->index != -1) {
            return false;
        }

        node->index = index;
        return true;
    }

    int getIndex(string& word) {
        TrieNode* node = root;

        for (char c : word) {
            node = node->next[c - 'a'];
        }

        return node->index;
    }

    vector<int> search(string& s1, string& s2, int start) {
        vector<int> indices;
        int size = s1.size();
        TrieNode* node1 = root;
        TrieNode* node2 = root;

        for (int i = start; i < size; ++i) {
            node1 = node1->next[s1[i] - 'a'];
            node2 = node2->next[s2[i] - 'a'];

            if (node1 == NULL || node2 == NULL) {
                break;
            }

            if (node1->index != -1 && node2->index != -1) {
                indices.push_back((node1->index << 8) | node2->index);
            }
        }

        return indices;
    }
};

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        Trie trie;
        int maxIndex = buildTrie(original, changed, trie);

        vector<vector<long long>> distance(maxIndex, vector<long long>(maxIndex, inf));
        vector<int> lens(maxIndex);

        init(original, changed, cost, trie, maxIndex, distance, lens);
        floyd(distance, maxIndex);

        return getMinCost(source, target, trie, distance, lens);
    }

    int buildTrie(vector<string>& original, vector<string>& changed, Trie& trie) {
        int index = 0;

        for (string& word : original) {
            if (trie.insert(word, index)) {
                ++index;
            }
        }

        for (string& word : changed) {
            if (trie.insert(word, index)) {
                ++index;
            }
        }

        return index;
    }

    void init(vector<string>& original, vector<string>& changed, vector<int>& cost, Trie& trie, int maxIndex, vector<vector<long long>>& distance, vector<int>& lens) {
        int size = cost.size();

        for (int i = 0; i < maxIndex; ++i) {
            distance[i][i] = 0;
        }

        for (int i = 0; i < (int)cost.size(); ++i) {
            int x = trie.getIndex(original[i]);
            int y = trie.getIndex(changed[i]);
            distance[x][y] = min(distance[x][y], (long long)cost[i]);
            lens[x] = original[i].size();
        }
    }

    void floyd(vector<vector<long long>>& distance, int maxIndex) {
        for (int k = 0; k < maxIndex; ++k) {
            for (int i = 0; i < maxIndex; ++i) {
                if (distance[i][k] != inf) {
                    for (int j = 0; j < maxIndex; ++j) {
                        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                    }
                }
            }
        }
    }

    long long getMinCost(string& source, string& target, Trie& trie, vector<vector<long long>>& distance, vector<int>& lens) {
        int size = source.size();
        vector<long long> dp(size + 1, inf);
        dp[size] = 0;

        for (int i = size - 1; i >= 0; --i) {
            if (source[i] == target[i]) {
                dp[i] = dp[i + 1];
            }

            vector<int> indices = trie.search(source, target, i);
            for (auto& index : indices) {
                int x = index >> 8, y = index & 0xff, len = lens[x];
                dp[i] = min(dp[i], distance[x][y] + dp[i + len]);
            }
        }

        return dp[0] == inf ? -1 : dp[0];
    }

    long long inf = LLONG_MAX / 2;
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> original = { "a","b","c","c","e","d" };
    vector<string> changed = { "b","c","b","e","b","e" };
    vector<int> cost = { 2,5,5,1,2,20 };
    check.checkLongLong(28, o.minimumCost("abcd", "acbe", original, changed, cost));

    original = { "bcd","fgh","thh" };
    changed = { "cde","thh","ghh" };
    cost = { 1,3,5 };
    check.checkLongLong(9, o.minimumCost("abcdefgh", "acdeeghh", original, changed, cost));

    original = { "bcd","defgh" };
    changed = { "ddd","ddddd" };
    cost = { 100,1578 };
    check.checkLongLong(-1, o.minimumCost("abcdefgh", "addddddd", original, changed, cost));

    original = { "b","b","h","b","a","a" };
    changed = { "a","h","e","e","b","h" };
    cost = { 3,5,9,9,5,10 };
    check.checkLongLong(-1, o.minimumCost("bbhbahbbbabhbbbbbhaa", "aheebebehaeheehhbahh", original, changed, cost));
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
