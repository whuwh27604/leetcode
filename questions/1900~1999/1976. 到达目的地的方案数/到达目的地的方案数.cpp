/* 到达目的地的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你在一个城市里，城市由 n 个路口组成，路口编号为 0 到 n - 1 ，某些路口之间有 双向 道路。输入保证你可以从任意路口出发到达其他任意路口，且任意两个路口之间最多有一条路。

给你一个整数 n 和二维整数数组 roads ，其中 roads[i] = [ui, vi, timei] 表示在路口 ui 和 vi 之间有一条需要花费 timei 时间才能通过的道路。你想知道花费 最少时间 从路口 0 出发到达路口 n - 1 的方案数。

请返回花费 最少时间 到达目的地的 路径数目 。由于答案可能很大，将结果对 109 + 7 取余 后返回。

 

示例 1：


输入：n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
输出：4
解释：从路口 0 出发到路口 6 花费的最少时间是 7 分钟。
四条花费 7 分钟的路径分别为：
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
示例 2：

输入：n = 2, roads = [[1,0,10]]
输出：1
解释：只有一条从路口 0 到路口 1 的路，花费 10 分钟。
 

提示：

1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 109
ui != vi
任意两个路口之间至多有一条路。
从任意路口出发，你能够到达其他任意路口。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-arrive-at-destination
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../tools/TestData.h"
#include "../check/CheckResult.h"

using namespace std;

struct pairCompare {
    bool operator()(const pair<int, long long>& p1, const pair<int, long long>& p2) const {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> minCosts(n, LLONG_MAX);
        minCosts[0] = 0;

        vector<int> dp(n, 0);
        dp[0] = 1;

        vector<vector<pair<int, long long>>> adjs(n);
        getAdjs(roads, adjs);

        priority_queue<pair<int, long long>, vector<pair<int, long long>>, pairCompare> dijkstra;  // {node,cost}
        dijkstra.push({ 0,0 });

        while (!dijkstra.empty()) {
            int node = dijkstra.top().first;
            long long cost = dijkstra.top().second;
            dijkstra.pop();

            for (auto& next : adjs[node]) {
                long long nextCost = cost + next.second;
                if (nextCost < minCosts[next.first]) {
                    minCosts[next.first] = nextCost;
                    dijkstra.push({ next.first, nextCost });
                    dp[next.first] = dp[node];
                }
                else if (nextCost == minCosts[next.first]) {
                    dp[next.first] = (dp[next.first] + dp[node]) % 1000000007;
                }
            }
        }

        return dp[n - 1];
    }

    void getAdjs(vector<vector<int>>& roads, vector<vector<pair<int, long long>>>& adjs) {
        for (auto& road : roads) {
            adjs[road[0]].push_back({ road[1],road[2] });
            adjs[road[1]].push_back({ road[0],road[2] });
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> roads = { {0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2} };
    check.checkInt(4, o.countPaths(7, roads));

    roads = { {1,0,10} };
    check.checkInt(1, o.countPaths(2, roads));

    roads = {};
    check.checkInt(1, o.countPaths(1, roads));

    roads = getIntVectorVector("./testcase1.txt");
    check.checkInt(1, o.countPaths(200, roads));
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
