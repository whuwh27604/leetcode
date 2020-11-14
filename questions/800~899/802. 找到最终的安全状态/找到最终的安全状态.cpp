/* 找到最终的安全状态.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在有向图中, 我们从某个节点和每个转向处开始, 沿着图的有向边走。 如果我们到达的节点是终点 (即它没有连出的有向边), 我们停止。

现在, 如果我们最后能走到终点，那么我们的起始节点是最终安全的。 更具体地说, 存在一个自然数 K,  无论选择从哪里开始行走, 我们走了不到 K 步后必能停止在一个终点。

哪些节点最终是安全的？ 结果返回一个有序的数组。

该有向图有 N 个节点，标签为 0, 1, ..., N-1, 其中 N 是 graph 的节点数.  图以以下的形式给出: graph[i] 是节点 j 的一个列表，满足 (i, j) 是图的一条有向边。

示例：
输入：graph = [[1,2],[2,3],[5],[0],[5],[],[]]
输出：[2,4,5,6]
这里是上图的示意图。



提示：

graph 节点数不超过 10000.
图的边数不会超过 32000.
每个 graph[i] 被排序为不同的整数列表， 在区间 [0, graph.length - 1] 中选取。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-eventual-safe-states
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // 反转graph，拓扑排序，入度为0的点就是安全的
        vector<vector<int>> fromTos(graph.size(), vector<int>{});
        vector<int> indegrees(graph.size(), 0);
        queue<int> zeroIndegreeNodes;
        reverseGraph(graph, fromTos, indegrees, zeroIndegreeNodes);

        vector<int> safeNodes;
        while (!zeroIndegreeNodes.empty()) {
            int from = zeroIndegreeNodes.front();
            zeroIndegreeNodes.pop();

            safeNodes.push_back(from);
            
            vector<int>& tos = fromTos[from];
            for (int to : tos) {
                if (--indegrees[to] == 0) {
                    zeroIndegreeNodes.push(to);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }

    void reverseGraph(vector<vector<int>>& graph, vector<vector<int>>& fromTos, vector<int>& indegrees, queue<int>& zeroIndegreeNodes) {
        for (int i = 0; i < (int)graph.size(); i++) {
            indegrees[i] = graph[i].size();

            if (graph[i].empty()) {
                zeroIndegreeNodes.push(i);
                continue;
            }

            for (int to : graph[i]) {
                fromTos[to].push_back(i);
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> graph = { {1,2},{2,3},{5},{0},{5},{},{} };
    vector<int> actual = o.eventualSafeNodes(graph);
    vector<int> expected = { 2,4,5,6 };
    check.checkIntVector(expected, actual);

    graph = { {1},{0} };
    actual = o.eventualSafeNodes(graph);
    expected = {  };
    check.checkIntVector(expected, actual);

    graph = { {} };
    actual = o.eventualSafeNodes(graph);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    graph = { {},{},{} };
    actual = o.eventualSafeNodes(graph);
    expected = { 0,1,2 };
    check.checkIntVector(expected, actual);

    graph = { {1},{0,2},{} };
    actual = o.eventualSafeNodes(graph);
    expected = { 2 };
    check.checkIntVector(expected, actual);

    graph = {  };
    actual = o.eventualSafeNodes(graph);
    expected = {  };
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
