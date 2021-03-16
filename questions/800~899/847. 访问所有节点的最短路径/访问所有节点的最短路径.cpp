/* ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出 graph 为有 N 个节点（编号为 0, 1, 2, ..., N-1）的无向连通图。 

graph.length = N，且只有节点 i 和 j 连通时，j != i 在列表 graph[i] 中恰好出现一次。

返回能够访问所有节点的最短路径的长度。你可以在任一节点开始和停止，也可以多次重访节点，并且可以重用边。

 

示例 1：

输入：[[1,2,3],[0],[0],[0]]
输出：4
解释：一个可能的路径为 [1,0,2,0,3]
示例 2：

输入：[[1],[0,2,4],[1,3,4],[2],[1,2]]
输出：4
解释：一个可能的路径为 [0,1,4,2,3]
 

提示：

1 <= graph.length <= 12
0 <= graph[i].length < graph.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-path-visiting-all-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) {
            return 0;
        }

        queue<pair<int, int>> nodeStates;
        vector<vector<int>> distance(n, vector<int>((1 << n), INT_MAX));

        init(n, nodeStates, distance);

        return bfs(graph, (1 << n) - 1, nodeStates, distance);
    }

    void init(int n, queue<pair<int, int>>& nodeStates, vector<vector<int>>& distance) {
        for (int node = 0; node < n; ++node) {
            int state = 1 << node;
            nodeStates.push({ node, state });
            distance[node][state] = 0;
        }
    }

    int bfs(vector<vector<int>>& graph, int target, queue<pair<int, int>>& nodeStates, vector<vector<int>>& distance) {
        int steps = 0;

        while (!nodeStates.empty()) {
            int i, size = nodeStates.size();
            ++steps;

            for (i = 0; i < size; ++i) {
                int node = nodeStates.front().first;
                int state = nodeStates.front().second;
                nodeStates.pop();

                for (int nextNode : graph[node]) {
                    int nextState = (state | (1 << nextNode));
                    if (nextState == target) {
                        return steps;  // 本题的关键是要意识到，bfs遍历到一条路径访问了所有节点的那一刻，花费的步骤就是最短路径。
                    }

                    if (steps < distance[nextNode][nextState]) {  // 以更大的步骤到达相同的状态是没有必要的
                        nodeStates.push({ nextNode, nextState });
                        distance[nextNode][nextState] = steps;
                    }
                }
            }
        }

        return steps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> graph = { {1,2,3},{0},{0},{0} };
    check.checkInt(4, o.shortestPathLength(graph));

    graph = { {1},{0,2,4},{1,3,4},{2},{1,2} };
    check.checkInt(4, o.shortestPathLength(graph));

    graph = { {} };
    check.checkInt(0, o.shortestPathLength(graph));

    graph = { {1,2,3,4,5,6,7,8,9,10,11},{0,2,3,4,5,6,7,8,9,10,11},{0,1,3,4,5,6,7,8,9,10,11},{0,1,2,4,5,6,7,8,9,10,11},{0,1,2,3,5,6,7,8,9,10,11},{0,1,2,3,4,6,7,8,9,10,11},{0,1,2,3,4,5,7,8,9,10,11},{0,1,2,3,4,5,6,8,9,10,11},{0,1,2,3,4,5,6,7,9,10,11},{0,1,2,3,4,5,6,7,8,10,11},{0,1,2,3,4,5,6,7,8,9,11},{0,1,2,3,4,5,6,7,8,9,10} };
    check.checkInt(11, o.shortestPathLength(graph));
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
