/* 统计点对的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个无向图，无向图由整数 n  ，表示图中节点的数目，和 edges 组成，其中 edges[i] = [ui, vi] 表示 ui 和 vi 之间有一条无向边。同时给你一个代表查询的整数数组 queries 。

第 j 个查询的答案是满足如下条件的点对 (a, b) 的数目：

a < b
cnt 是与 a 或者 b 相连的边的数目，且 cnt 严格大于 queries[j] 。
请你返回一个数组 answers ，其中 answers.length == queries.length 且 answers[j] 是第 j 个查询的答案。

请注意，图中可能会有 重复边 。

 

示例 1：


输入：n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
输出：[6,5]
解释：每个点对中，与至少一个点相连的边的数目如上图所示。
示例 2：

输入：n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]], queries = [1,2,3,4,5]
输出：[10,10,9,8,6]
 

提示：

2 <= n <= 2 * 104
1 <= edges.length <= 105
1 <= ui, vi <= n
ui != vi
1 <= queries.length <= 20
0 <= queries[j] < edges.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-pairs-of-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        int i, size = queries.size();
        vector<int> responses(size);
        vector<int> nodeEdges(n, 0);  // 记录和每个node相连的edge有多少个
        unordered_map<int, int> overlaps;  // 记录每个edge重复了多少次

        getNodeEdges(edges, nodeEdges, overlaps);

        vector<int> sortedNodeEdges = nodeEdges;
        sort(sortedNodeEdges.begin(), sortedNodeEdges.end());  // 排序，便于后序双指针统计点对个数

        for (i = 0; i < size; ++i) {  // 先统计两个点连接的edge之和大于query的点对个数，然后减去这两个点形成的edge重复过多的情况
            responses[i] = getNodePairs(n, sortedNodeEdges, queries[i]) - getFake(overlaps, nodeEdges, queries[i]);
        }

        return responses;
    }

    void getNodeEdges(vector<vector<int>>& edges, vector<int>& nodeEdges, unordered_map<int, int>& overlaps) {
        for (auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];

            if (node1 > node2) {
                swap(node1, node2);
            }

            ++nodeEdges[node1 - 1];
            ++nodeEdges[node2 - 1];
            ++overlaps[(node1 << 16) | node2];
        }
    }

    int getNodePairs(int n, vector<int>& sortedNodeEdges, int query) {
        int i, j = n - 1, pairs = 0;

        for (i = 0; i < n - 1; ++i) {  // 双指针统计点对连接的edge之和大于query的个数
            while (j >= 0 && sortedNodeEdges[i] + sortedNodeEdges[j] > query) {
                --j;
            }

            pairs += (n - 1 - max(i, j));  // 题目要求 a < b
        }

        return pairs;
    }

    int getFake(unordered_map<int, int>& overlaps, vector<int>& nodeEdges, int query) {
        int fakePairs = 0;

        for (auto& overlap : overlaps) {
            int node1 = overlap.first >> 16, node2 = overlap.first & 0xffff, count = overlap.second;

            if ((nodeEdges[node1 - 1] + nodeEdges[node2 - 1] > query) && (nodeEdges[node1 - 1] + nodeEdges[node2 - 1] - count <= query)) {
                ++fakePairs;  // 本来是大于query的，减去重复edge个数之后不大于query了，那么这个点对不应该统计进去
            }
        }

        return fakePairs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {1,2},{2,4},{1,3},{2,3},{2,1} };
    vector<int> queries = { 2,3 };
    vector<int> actual = o.countPairs(4, edges, queries);
    vector<int> expected = { 6,5 };
    check.checkIntVector(expected, actual);
    
    edges = { {1,2},{2,4},{1,3},{2,3},{2,1} };
    queries = { 0,1,2,3,4 };
    actual = o.countPairs(4, edges, queries);
    expected = { 6,6,6,5,2 };
    check.checkIntVector(expected, actual);

    edges = { {1,5},{1,5},{3,4},{2,5},{1,3},{5,1},{2,3},{2,5} };
    queries = { 1,2,3,4,5 };
    actual = o.countPairs(5, edges, queries);
    expected = { 10,10,9,8,6 };
    check.checkIntVector(expected, actual);

    edges = { {16,42} };
    queries = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    actual = o.countPairs(48, edges, queries);
    expected = { 93,93,93,93,93,93,93,93,93,93,93,93,93,93,93,93,93,93 };
    check.checkIntVector(expected, actual);

    edges = { {1,2} };
    queries = { 0 };
    actual = o.countPairs(2, edges, queries);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    edges = { {1,2} };
    queries = { 1 };
    actual = o.countPairs(2, edges, queries);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    edges = getIntVectorVector("./testcase1.txt");
    queries = { 11,8,1,35,11,23,44,1,17,10,37,37,5,15,27,6,1473,40,3223 };
    actual = o.countPairs(3527, edges, queries);
    expected = { 5252,148847,5742588,0,5252,0,0,5742588,0,18222,0,0,1458546,3,0,763006,0,0,0 };
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
