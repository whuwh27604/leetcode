/* 最大化一张图中的路径价值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一张 无向 图，图中有 n 个节点，节点编号从 0 到 n - 1 （都包括）。同时给你一个下标从 0 开始的整数数组 values ，其中 values[i] 是第 i 个节点的 价值 。同时给你一个下标从 0 开始的二维整数数组 edges ，其中 edges[j] = [uj, vj, timej] 表示节点 uj 和 vj 之间有一条需要 timej 秒才能通过的无向边。最后，给你一个整数 maxTime 。

合法路径 指的是图中任意一条从节点 0 开始，最终回到节点 0 ，且花费的总时间 不超过 maxTime 秒的一条路径。你可以访问一个节点任意次。一条合法路径的 价值 定义为路径中 不同节点 的价值 之和 （每个节点的价值 至多 算入价值总和中一次）。

请你返回一条合法路径的 最大 价值。

注意：每个节点 至多 有 四条 边与之相连。

 

示例 1：



输入：values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
输出：75
解释：
一条可能的路径为：0 -> 1 -> 0 -> 3 -> 0 。总花费时间为 10 + 10 + 10 + 10 = 40 <= 49 。
访问过的节点为 0 ，1 和 3 ，最大路径价值为 0 + 32 + 43 = 75 。
示例 2：



输入：values = [5,10,15,20], edges = [[0,1,10],[1,2,10],[0,3,10]], maxTime = 30
输出：25
解释：
一条可能的路径为：0 -> 3 -> 0 。总花费时间为 10 + 10 = 20 <= 30 。
访问过的节点为 0 和 3 ，最大路径价值为 5 + 20 = 25 。
示例 3：



输入：values = [1,2,3,4], edges = [[0,1,10],[1,2,11],[2,3,12],[1,3,13]], maxTime = 50
输出：7
解释：
一条可能的路径为：0 -> 1 -> 3 -> 1 -> 0 。总花费时间为 10 + 13 + 13 + 10 = 46 <= 50 。
访问过的节点为 0 ，1 和 3 ，最大路径价值为 1 + 2 + 4 = 7 。
示例 4：



输入：values = [0,1,2], edges = [[1,2,10]], maxTime = 10
输出：0
解释：
唯一一条路径为 0 。总花费时间为 0 。
唯一访问过的节点为 0 ，最大路径价值为 0 。
 

提示：

n == values.length
1 <= n <= 1000
0 <= values[i] <= 108
0 <= edges.length <= 2000
edges[j].length == 3
0 <= uj < vj <= n - 1
10 <= timej, maxTime <= 100
[uj, vj] 所有节点对 互不相同 。
每个节点 至多有四条 边。
图可能不连通。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-path-quality-of-a-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <unordered_set>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

struct pairCompare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size(), maxPathQuality = 0;
        vector<int> currentValues = values;

        vector<vector<pair<int, int>>> adjs(n);
        getAdjs(edges, adjs);

        vector<int> minTimes(n, INT_MAX);
        dijkstra(adjs, minTimes);

        DFS(0, adjs, minTimes, 0, maxTime, values, currentValues, 0, maxPathQuality);

        return maxPathQuality;
    }

    void DFS(int node, vector<vector<pair<int, int>>>& adjs, vector<int>& minTimes, int time, int maxTime,
        vector<int>& values, vector<int>& currentValues, int value, int& maxPathQuality) {
        if (currentValues[node] >= 0) {
            value += currentValues[node];
            currentValues[node] = -1;
        }
        else {
            --currentValues[node];
        }

        if (node == 0) {
            maxPathQuality = max(maxPathQuality, value);
        }

        for (auto& next : adjs[node]) {
            if (time + next.second + minTimes[next.first] <= maxTime) {
                DFS(next.first, adjs, minTimes, time + next.second, maxTime, values, currentValues, value, maxPathQuality);
            }
        }

        if (++currentValues[node] == 0) {
            currentValues[node] = values[node];
        }
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<pair<int, int>>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back({ edge[1],edge[2] });
            adjs[edge[1]].push_back({ edge[0],edge[2] });
        }
    }

    void dijkstra(vector<vector<pair<int, int>>>& adjs, vector<int>& minTimes) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, pairCompare> nodes;  // {node, time}
        nodes.push({ 0,0 });

        while (!nodes.empty()) {
            int node = nodes.top().first, time = nodes.top().second;
            nodes.pop();

            if (time < minTimes[node]) {
                minTimes[node] = time;

                for (auto& next : adjs[node]) {
                    nodes.push({ next.first, time + next.second });
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 0,32,10,43 };
    vector<vector<int>> edges = { {0,1,10},{1,2,15},{0,3,10} };
    check.checkInt(75, o.maximalPathQuality(values, edges, 49));

    values = { 5,10,15,20 };
    edges = { {0,1,10},{1,2,10},{0,3,10} };
    check.checkInt(25, o.maximalPathQuality(values, edges, 30));

    values = { 1,2,3,4 };
    edges = { {0,1,10},{1,2,11},{2,3,12},{1,3,13} };
    check.checkInt(7, o.maximalPathQuality(values, edges, 50));

    values = { 0,1,2 };
    edges = { {1,2,10} };
    check.checkInt(0, o.maximalPathQuality(values, edges, 10));

    values = { 95 };
    edges = {  };
    check.checkInt(95, o.maximalPathQuality(values, edges, 83));

    values = getIntVector("./testcase1_values.txt");
    edges = getIntVectorVector("./testcase1_edges.txt");
    check.checkInt(498794167, o.maximalPathQuality(values, edges, 100));
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
