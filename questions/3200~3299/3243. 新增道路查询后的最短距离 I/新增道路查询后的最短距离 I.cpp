/* 新增道路查询后的最短距离 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 和一个二维整数数组 queries。

有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。

queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1 的最短路径的长度。

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



提示：

3 <= n <= 500
1 <= queries.length <= 500
queries[i].length == 2
0 <= queries[i][0] < queries[i][1] < n
1 < queries[i][1] - queries[i][0]
查询中没有重复的道路。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int size = (int)queries.size();
        vector<int> ans(size);
        vector<vector<int>> adjs(n);

        for (int i = 0; i < n - 1; ++i) {
            adjs[i].push_back(i + 1);
        }

        for (int i = 0; i < size; ++i) {
            adjs[queries[i][0]].push_back(queries[i][1]);
            ans[i] = getDist(adjs, n);
        }

        return ans;
    }

    int getDist(vector<vector<int>>& adjs, int n) {
        int dist = 0;
        queue<int> nodes;
        nodes.push(0);
        vector<int> visited(n, false);
        visited[0] = true;

        while (!nodes.empty()) {
            int size = (int)nodes.size();
            ++dist;

            for (int i = 0; i < size; ++i) {
                int node = nodes.front();
                nodes.pop();

                for (int next : adjs[node]) {
                    if (next == n - 1) {
                        return dist;
                    }

                    if (!visited[next]) {
                        visited[next] = true;
                        nodes.push(next);
                    }
                }
            }
        }

        return dist;
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
