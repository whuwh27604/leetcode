/* 统计可能的树根数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 有一棵 n 个节点的树，节点编号为 0 到 n - 1 。树用一个长度为 n - 1 的二维整数数组 edges 表示，其中 edges[i] = [ai, bi] ，表示树中节点 ai 和 bi 之间有一条边。

Alice 想要 Bob 找到这棵树的根。她允许 Bob 对这棵树进行若干次 猜测 。每一次猜测，Bob 做如下事情：

选择两个 不相等 的整数 u 和 v ，且树中必须存在边 [u, v] 。
Bob 猜测树中 u 是 v 的 父节点 。
Bob 的猜测用二维整数数组 guesses 表示，其中 guesses[j] = [uj, vj] 表示 Bob 猜 uj 是 vj 的父节点。

Alice 非常懒，她不想逐个回答 Bob 的猜测，只告诉 Bob 这些猜测里面 至少 有 k 个猜测的结果为 true 。

给你二维整数数组 edges ，Bob 的所有猜测和整数 k ，请你返回可能成为树根的 节点数目 。如果没有这样的树，则返回 0。



示例 1：



输入：edges = [[0,1],[1,2],[1,3],[4,2]], guesses = [[1,3],[0,1],[1,0],[2,4]], k = 3
输出：3
解释：
根为节点 0 ，正确的猜测为 [1,3], [0,1], [2,4]
根为节点 1 ，正确的猜测为 [1,3], [1,0], [2,4]
根为节点 2 ，正确的猜测为 [1,3], [1,0], [2,4]
根为节点 3 ，正确的猜测为 [1,0], [2,4]
根为节点 4 ，正确的猜测为 [1,3], [1,0]
节点 0 ，1 或 2 为根时，可以得到 3 个正确的猜测。
示例 2：



输入：edges = [[0,1],[1,2],[2,3],[3,4]], guesses = [[1,0],[3,4],[2,1],[3,2]], k = 1
输出：5
解释：
根为节点 0 ，正确的猜测为 [3,4]
根为节点 1 ，正确的猜测为 [1,0], [3,4]
根为节点 2 ，正确的猜测为 [1,0], [2,1], [3,4]
根为节点 3 ，正确的猜测为 [1,0], [2,1], [3,2], [3,4]
根为节点 4 ，正确的猜测为 [1,0], [2,1], [3,2]
任何节点为根，都至少有 1 个正确的猜测。


提示：

edges.length == n - 1
2 <= n <= 105
1 <= guesses.length <= 105
0 <= ai, bi, uj, vj <= n - 1
ai != bi
uj != vj
edges 表示一棵有效的树。
guesses[j] 是树中的一条边。
0 <= k <= guesses.length
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> adjs(n);
        unordered_set<long long> guessSet;

        getAdjs(edges, adjs);
        getGuessSet(guesses, guessSet);
        int rightGuess = DFS4RightGuess(0, -1, adjs, guessSet);

        return DFS4PossibleRoot(0, -1, rightGuess, k, adjs, guessSet);
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    void getGuessSet(vector<vector<int>>& guesses, unordered_set<long long>& guessSet) {
        for (auto& guess : guesses) {
            guessSet.insert(((long long)guess[0] << 32) | guess[1]);
        }
    }

    int DFS4RightGuess(int node, int parent, vector<vector<int>>& adjs, unordered_set<long long>& guessSet) {
        int rightGuess = 0;

        for (int next : adjs[node]) {
            if (next != parent) {
                if (guessSet.count(((long long)node << 32) | next) != 0) {
                    ++rightGuess;
                }

                rightGuess += DFS4RightGuess(next, node, adjs, guessSet);
            }
        }

        return rightGuess;
    }

    int DFS4PossibleRoot(int node, int parent, int rightGuess, int k, vector<vector<int>>& adjs, unordered_set<long long>& guessSet) {
        int possibleRoot = (rightGuess >= k ? 1 : 0);

        for (int next : adjs[node]) {
            if (next != parent) {
                int newRightGuess = rightGuess;
                if (guessSet.count(((long long)node << 32) | next) != 0) {
                    --newRightGuess;
                }

                if (guessSet.count(((long long)next << 32) | node) != 0) {
                    ++newRightGuess;
                }

                possibleRoot += DFS4PossibleRoot(next, node, newRightGuess, k, adjs, guessSet);
            }
        }

        return possibleRoot;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1},{1,2},{1,3},{4,2} };
    vector<vector<int>> guesses = { {1,3},{0,1},{1,0},{2,4} };
    check.checkInt(3, o.rootCount(edges, guesses, 3));

    edges = { {0,1},{1,2},{2,3},{3,4} };
    guesses = { {1,0},{3,4},{2,1},{3,2} };
    check.checkInt(5, o.rootCount(edges, guesses, 1));

    edges = { {0,1},{2,0},{0,3},{4,2},{3,5},{6,0},{1,7},{2,8},{2,9},{4,10},{9,11},{3,12},{13,8},{14,9},{15,9},{10,16} };
    guesses = { {8,2},{12,3},{0,1},{16,10} };
    check.checkInt(4, o.rootCount(edges, guesses, 2));
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
