/* 树中可以形成回文的路径数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 树（即，一个连通、无向且无环的图），根 节点为 0 ，由编号从 0 到 n - 1 的 n 个节点组成。这棵树用一个长度为 n 、下标从 0 开始的数组 parent 表示，其中 parent[i] 为节点 i 的父节点，由于节点 0 为根节点，所以 parent[0] == -1 。

另给你一个长度为 n 的字符串 s ，其中 s[i] 是分配给 i 和 parent[i] 之间的边的字符。s[0] 可以忽略。

找出满足 u < v ，且从 u 到 v 的路径上分配的字符可以 重新排列 形成 回文 的所有节点对 (u, v) ，并返回节点对的数目。

如果一个字符串正着读和反着读都相同，那么这个字符串就是一个 回文 。



示例 1：



输入：parent = [-1,0,0,1,1,2], s = "acaabc"
输出：8
解释：符合题目要求的节点对分别是：
- (0,1)、(0,2)、(1,3)、(1,4) 和 (2,5) ，路径上只有一个字符，满足回文定义。
- (2,3)，路径上字符形成的字符串是 "aca" ，满足回文定义。
- (1,5)，路径上字符形成的字符串是 "cac" ，满足回文定义。
- (3,5)，路径上字符形成的字符串是 "acac" ，可以重排形成回文 "acca" 。
示例 2：

输入：parent = [-1,0,0,0,0], s = "aaaaa"
输出：10
解释：任何满足 u < v 的节点对 (u,v) 都符合题目要求。


提示：

n == parent.length == s.length
1 <= n <= 105
对于所有 i >= 1 ，0 <= parent[i] <= n - 1 均成立
parent[0] == -1
parent 表示一棵有效的树
s 仅由小写英文字母组成
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> tree(n);
        unordered_map<int, int> pathCount;
        pathCount[0] = 1;  // 预置一个空路径的数量

        // 关键算法：[u, v]路径的回文性和[u, root] + [root, v]的回文性是一样的，所以预处理所有点的path值，对每一个path值，寻找可以和它配对的path值
        // path值用一个整数表示，其中每一个bit位表示字符[a~z]出现的奇偶性
        buildTree(n, parent, tree);
        DFS(0, 0, tree, s, pathCount);

        return count(pathCount);
    }

    void buildTree(int n, vector<int>& parent, vector<vector<int>>& tree) {
        for (int i = 1; i < n; ++i) {
            tree[parent[i]].push_back(i);
        }
    }

    void DFS(int node, int path, vector<vector<int>>& tree, string& s, unordered_map<int, int>& pathCount) {
        if (node != 0) {
            int bit = (1 << (s[node] - 'a'));
            path ^= bit;
            ++pathCount[path];
        }

        for (int next : tree[node]) {
            DFS(next, path, tree, s, pathCount);
        }
    }

    long long count(unordered_map<int, int>& pathCount) {
        long long palindromePaths = 0;

        for (auto& kv : pathCount) {
            int path = kv.first, cnt = kv.second;
            palindromePaths += cnt * ((long long)cnt - 1);  // path完全相同的两点，都可以形成palindrome

            for (int bit = 1; bit < (1 << 26); bit <<= 1) {
                int pldrPath = path ^ bit;  // 只有一个位置奇偶性不同，也可以形成palindrome
                if (pathCount.count(pldrPath) != 0) {
                    palindromePaths += ((long long)cnt * pathCount[pldrPath]);
                }
            }
        }

        return palindromePaths / 2;  // 只统计u < v的path
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> parent = { -1,0,0,1,1,2 };
    check.checkLongLong(8, o.countPalindromePaths(parent, "acaabc"));

    parent = { -1,0,0,0,0 };
    check.checkLongLong(10, o.countPalindromePaths(parent, "aaaaa"));

    parent = { -1,0,0 };
    check.checkLongLong(3, o.countPalindromePaths(parent, "zzz"));
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
