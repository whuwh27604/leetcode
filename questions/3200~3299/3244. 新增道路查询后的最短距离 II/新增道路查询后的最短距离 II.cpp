/* 新增道路查询后的最短距离 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 和一个二维整数数组 queries。

有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。

queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1 的最短路径的长度。

所有查询中不会存在两个查询都满足 queries[i][0] < queries[j][0] < queries[i][1] < queries[j][1]。

返回一个数组 answer，对于范围 [0, queries.length - 1] 中的每个 i，answer[i] 是处理完前 i + 1 个查询后，从城市 0 到城市 n - 1 的最短路径的长度。



示例 1：

输入： n = 5, queries = [[2, 4], [0, 2], [0, 4]]

输出： [3, 2, 1]

解释：



新增一条从 2 到 4 的道路后，从 0 到 4 的最短路径长度为 3。



新增一条从 0 到 2 的道路后，从 0 到 4 的最短路径长度为 2。



新增一条从 0 到 4 的道路后，从 0 到 4 的最短路径长度为 1。

示例 2：

输入： n = 4, queries = [[0, 3], [0, 2]]

输出： [1, 1]

解释：



新增一条从 0 到 3 的道路后，从 0 到 3 的最短路径长度为 1。



新增一条从 0 到 2 的道路后，从 0 到 3 的最短路径长度仍为 1。



提示:

3 <= n <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= queries[i][0] < queries[i][1] < n
1 < queries[i][1] - queries[i][0]
查询中不存在重复的道路。
不存在两个查询都满足 i != j 且 queries[i][0] < queries[j][0] < queries[i][1] < queries[j][1]。
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int start;
    int end;

    Node() : start(0), end(0) {}
    Node(int s, int e) : start(s), end(e) {}

    bool operator<(const Node& o) const {
        return start < o.start;
    }
};

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int size = (int)queries.size();
        vector<int> ans(size);
        set<Node> nodes;

        for (int i = 0; i < n; ++i) {
            nodes.insert(Node(i, i + 1));
        }

        for (int i = 0; i < size; ++i) {
            int x = queries[i][0], y = queries[i][1];
            auto iter = nodes.upper_bound(Node(x, 0));
            --iter;

            if (iter->start == x && iter->end < y) {
                while (iter->start != y) {
                    iter = nodes.erase(iter);
                }

                nodes.insert(Node(x, y));
            }

            ans[i] = (int)nodes.size() - 1;
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> queries = { {2,4},{0,2},{0,4} };
    vector<int> actual = o.shortestDistanceAfterQueries(5, queries);
    vector<int> expected = { 3,2,1 };
    check.checkIntVector(expected, actual);

    queries = { {0,3},{0,2} };
    actual = o.shortestDistanceAfterQueries(4, queries);
    expected = { 1,1 };
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
