/* 节点序列的最大得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个节点的 无向图 ，节点编号为 0 到 n - 1 。

给你一个下标从 0 开始的整数数组 scores ，其中 scores[i] 是第 i 个节点的分数。同时给你一个二维整数数组 edges ，其中 edges[i] = [ai, bi] ，表示节点 ai 和 bi 之间有一条 无向 边。

一个合法的节点序列如果满足以下条件，我们称它是 合法的 ：

序列中每 相邻 节点之间有边相连。
序列中没有节点出现超过一次。
节点序列的分数定义为序列中节点分数之 和 。

请你返回一个长度为 4 的合法节点序列的最大分数。如果不存在这样的序列，请你返回 -1 。

 

示例 1：



输入：scores = [5,2,9,8,4], edges = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
输出：24
解释：上图为输入的图，节点序列为 [0,1,2,3] 。
节点序列的分数为 5 + 2 + 9 + 8 = 24 。
观察可知，没有其他节点序列得分和超过 24 。
注意节点序列 [3,1,2,0] 和 [1,0,2,3] 也是合法的，且分数为 24 。
序列 [0,3,2,4] 不是合法的，因为没有边连接节点 0 和 3 。
示例 2：



输入：scores = [9,20,6,4,11,12], edges = [[0,3],[5,3],[2,4],[1,3]]
输出：-1
解释：上图为输入的图。
没有长度为 4 的合法序列，所以我们返回 -1 。
 

提示：

n == scores.length
4 <= n <= 5 * 104
1 <= scores[i] <= 108
0 <= edges.length <= 5 * 104
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
不会有重边。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-score-of-a-node-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Peer {
public:
    int node1;
    int node2;
    int node3;
    int score1;
    int score2;
    int score3;

    Peer() : node1(-1), node2(-1), node3(-1), score1(0), score2(0), score3(0) {}

    void addPeer(int peer, int score) {  // 对于一个点，最多保留3个最大的peer就够用了
        if (score >= score1) {
            node3 = node2, score3 = score2;
            node2 = node1, score2 = score1;
            node1 = peer, score1 = score;
        }
        else if (score >= score2) {
            node3 = node2, score3 = score2;
            node2 = peer, score2 = score;
        }
        else if (score > score3) {
            node3 = peer, score3 = score;
        }
    }
};

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size(), maxScore = -1;
        vector<Peer> peers(n);

        for (auto& edge : edges) {
            peers[edge[0]].addPeer(edge[1], scores[edge[1]]);
            peers[edge[1]].addPeer(edge[0], scores[edge[0]]);
        }

        // 对于a--b--c--d，枚举所有的b--c边，找最大的a、d
        for (auto& edge : edges) {
            int b = edge[0], c = edge[1];
            int a = (peers[b].node1 == c ? peers[b].node2 : peers[b].node1), d = (peers[c].node1 == b ? peers[c].node2 : peers[c].node1);

            if (a == -1 || d == -1) {  // a或d不存在，b--c不是一个有效的边
                continue;
            }

            if (a != d) {  // 找到一个有效的a--b--c--d
                maxScore = max(maxScore, scores[a] + scores[b] + scores[c] + scores[d]);
                continue;
            }

            // a和d是同一个点，尝试将a换另一个score稍小的点。
            // 如果当前已经是peer.node2，那么只能选peer.node3；如果当前是peer.node1，那么可以选peer.node2，如果peer.node2是c，那么只能选peer.node3
            int next = (a == peers[b].node2 ? peers[b].node3 : (peers[b].node2 == c ? peers[b].node3 : peers[b].node2));
            if (next != -1) {
                maxScore = max(maxScore, scores[next] + scores[b] + scores[c] + scores[d]);
            }

            // a和d是同一个点，尝试将d换另一个score稍小的点
            next = (d == peers[c].node2 ? peers[c].node3 : (peers[c].node2 == b ? peers[c].node3 : peers[c].node2));
            if (next != -1) {
                maxScore = max(maxScore, scores[a] + scores[b] + scores[c] + scores[next]);
            }
        }

        return maxScore;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> scores = { 5,2,9,8,4 };
    vector<vector<int>> edges = { {0,1},{1,2},{2,3},{0,2},{1,3},{2,4} };
    check.checkInt(24, o.maximumScore(scores, edges));

    scores = { 9,20,6,4,11,12 };
    edges = { {0,3},{5,3},{2,4},{1,3} };
    check.checkInt(-1, o.maximumScore(scores, edges));

    scores = { 1,2,3,4 };
    edges = {  };
    check.checkInt(-1, o.maximumScore(scores, edges));
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
