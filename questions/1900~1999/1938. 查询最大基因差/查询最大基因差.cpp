/* 查询最大基因差.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 n 个节点的有根树，节点编号从 0 到 n - 1 。每个节点的编号表示这个节点的 独一无二的基因值 （也就是说节点 x 的基因值为 x）。两个基因值的 基因差 是两者的 异或和 。给你整数数组 parents ，其中 parents[i] 是节点 i 的父节点。如果节点 x 是树的 根 ，那么 parents[x] == -1 。

给你查询数组 queries ，其中 queries[i] = [nodei, vali] 。对于查询 i ，请你找到 vali 和 pi 的 最大基因差 ，其中 pi 是节点 nodei 到根之间的任意节点（包含 nodei 和根节点）。更正式的，你想要最大化 vali XOR pi 。

请你返回数组 ans ，其中 ans[i] 是第 i 个查询的答案。

 

示例 1：


输入：parents = [-1,0,1,1], queries = [[0,2],[3,2],[2,5]]
输出：[2,3,7]
解释：查询数组处理如下：
- [0,2]：最大基因差的对应节点为 0 ，基因差为 2 XOR 0 = 2 。
- [3,2]：最大基因差的对应节点为 1 ，基因差为 2 XOR 1 = 3 。
- [2,5]：最大基因差的对应节点为 2 ，基因差为 5 XOR 2 = 7 。
示例 2：


输入：parents = [3,7,-1,2,0,7,0,2], queries = [[4,6],[1,15],[0,5]]
输出：[6,14,7]
解释：查询数组处理如下：
- [4,6]：最大基因差的对应节点为 0 ，基因差为 6 XOR 0 = 6 。
- [1,15]：最大基因差的对应节点为 1 ，基因差为 15 XOR 1 = 14 。
- [0,5]：最大基因差的对应节点为 2 ，基因差为 5 XOR 2 = 7 。
 

提示：

2 <= parents.length <= 105
对于每个 不是 根节点的 i ，有 0 <= parents[i] <= parents.length - 1 。
parents[root] == -1
1 <= queries.length <= 3 * 104
0 <= nodei <= parents.length - 1
0 <= vali <= 2 * 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-genetic-difference-query
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode() : left(NULL), right(NULL), count(0) {}

    TrieNode* left;
    TrieNode* right;
    int count;
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
        maxBits = 0x20000;  // 2^17 < 2 * 10^5 < 2^18
    }

    void insert(int num) {
        TrieNode* current = root;

        for (int bit = maxBits; bit != 0; bit >>= 1) {
            if ((num & bit) == 0) {
                if (current->left == NULL) {
                    current->left = new TrieNode;
                }
                current = current->left;
            }
            else {
                if (current->right == NULL) {
                    current->right = new TrieNode;
                }
                current = current->right;
            }

            ++current->count;
        }
    }

    void remove(int num) {
        TrieNode* current = root;

        for (int bit = maxBits; bit != 0; bit >>= 1) {
            current = ((num & bit) == 0 ? current->left : current->right);
            --current->count;
        }
    }

    int getMaxXor(int num) {
        TrieNode* another = root;
        int maxXor = 0;

        for (int bit = maxBits; bit != 0; bit >>= 1) {
            maxXor <<= 1;

            if ((num & bit) == 0) {  // num当前位为0，那么目标数的当前位尽可能选1，这样异或的结果为1才能最大
                if (another->right != NULL && another->right->count != 0) {  // 可以选到1，那么选它
                    maxXor |= 1;
                    another = another->right;
                }
                else {  // 没有1可选，只能被迫选0
                    another = another->left;
                }
            }
            else {  // num当前位为1，那么目标数的当前位尽可能选0，这样异或的结果为1才能最大
                if (another->left != NULL && another->left->count != 0) {  // 可以选到0，那么选它
                    maxXor |= 1;
                    another = another->left;
                }
                else {  // 没有0可选，只能被迫选1
                    another = another->right;
                }
            }
        }

        return maxXor;
    }

private:
    TrieNode* root;
    int maxBits;
};

class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        Trie trie;
        vector<vector<int>> children(n);
        vector<vector<pair<int, int>>> hashQueries(n);  // { val, index }
        vector<int> responses(queries.size());

        getHashQueries(queries, hashQueries);  // 离线查询，按照DFS的顺序返回答案
        DFS(getChildren(n, parents, children), children, trie, hashQueries, responses);

        return responses;
    }

    int getChildren(int n, vector<int>& parents, vector<vector<int>>& children) {
        int root = 0;

        for (int node = 0; node < n; ++node) {
            if (parents[node] != -1) {
                children[parents[node]].push_back(node);
            }
            else {
                root = node;
            }
        }

        return root;
    }

    void getHashQueries(vector<vector<int>>& queries, vector<vector<pair<int, int>>>& hashQueries) {
        for (int i = 0; i < (int)queries.size(); ++i) {
            hashQueries[queries[i][0]].push_back({ queries[i][1], i });
        }
    }

    void DFS(int root, vector<vector<int>>& children, Trie& trie, vector<vector<pair<int, int>>>& hashQueries, vector<int>& responses) {
        trie.insert(root);

        if (!hashQueries[root].empty()) {
            for (auto& query : hashQueries[root]) {
                responses[query.second] = trie.getMaxXor(query.first);
            }
        }

        for (int child : children[root]) {
            DFS(child, children, trie, hashQueries, responses);
        }

        trie.remove(root);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> parents = { -1,0,1,1 };
    vector<vector<int>> queries = { {0,2},{3,2},{2,5} };
    vector<int> actual = o.maxGeneticDifference(parents, queries);
    vector<int> expected = { 2,3,7 };
    check.checkIntVector(expected, actual);

    parents = { 3,7,-1,2,0,7,0,2 };
    queries = { {4,6},{1,15},{0,5} };
    actual = o.maxGeneticDifference(parents, queries);
    expected = { 6,14,7 };
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
