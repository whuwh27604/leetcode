/* 到达首都的最少油耗.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 n 个节点的树（一个无向、连通、无环图），每个节点表示一个城市，编号从 0 到 n - 1 ，且恰好有 n - 1 条路。0 是首都。给你一个二维整数数组 roads ，其中 roads[i] = [ai, bi] ，表示城市 ai 和 bi 之间有一条 双向路 。

每个城市里有一个代表，他们都要去首都参加一个会议。

每座城市里有一辆车。给你一个整数 seats 表示每辆车里面座位的数目。

城市里的代表可以选择乘坐所在城市的车，或者乘坐其他城市的车。相邻城市之间一辆车的油耗是一升汽油。

请你返回到达首都最少需要多少升汽油。



示例 1：



输入：roads = [[0,1],[0,2],[0,3]], seats = 5
输出：3
解释：
- 代表 1 直接到达首都，消耗 1 升汽油。
- 代表 2 直接到达首都，消耗 1 升汽油。
- 代表 3 直接到达首都，消耗 1 升汽油。
最少消耗 3 升汽油。
示例 2：



输入：roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
输出：7
解释：
- 代表 2 到达城市 3 ，消耗 1 升汽油。
- 代表 2 和代表 3 一起到达城市 1 ，消耗 1 升汽油。
- 代表 2 和代表 3 一起到达首都，消耗 1 升汽油。
- 代表 1 直接到达首都，消耗 1 升汽油。
- 代表 5 直接到达首都，消耗 1 升汽油。
- 代表 6 到达城市 4 ，消耗 1 升汽油。
- 代表 4 和代表 6 一起到达首都，消耗 1 升汽油。
最少消耗 7 升汽油。
示例 3：



输入：roads = [], seats = 1
输出：0
解释：没有代表需要从别的城市到达首都。


提示：

1 <= n <= 105
roads.length == n - 1
roads[i].length == 2
0 <= ai, bi < n
ai != bi
roads 表示一棵合法的树。
1 <= seats <= 105
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = getN(roads);
        vector<vector<int>> adjs(n);
        pair<long long, int> ret = { 0,0 };

        getAdjs(roads, adjs);

        for (int city : adjs[0]) {
            pair<long long, int> sub = DFS(city, 0, adjs, seats);
            ret.first += sub.first;
        }

        return ret.first;
    }

    int getN(vector<vector<int>>& roads) {
        int n = 0;

        for (auto& road : roads) {
            n = max(n, *max_element(road.begin(), road.end()));
        }

        return n + 1;
    }

    void getAdjs(vector<vector<int>>& roads, vector<vector<int>>& adjs) {
        for (auto& road : roads) {
            adjs[road[0]].push_back(road[1]);
            adjs[road[1]].push_back(road[0]);
        }
    }

    pair<long long, int> DFS(int city, int parent, vector<vector<int>>& adjs, int seats) {
        pair<long long, int> ret = { 0,1 };

        for (int next : adjs[city]) {
            if (next != parent) {
                pair<long long, int> sub = DFS(next, city, adjs, seats);
                ret.first += sub.first;
                ret.second += sub.second;
            }
        }

        ret.first += (ret.second + seats - 1) / seats;

        return ret;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> roads = { {0,1},{0,2},{0,3} };
    check.checkLongLong(3, o.minimumFuelCost(roads, 5));

    roads = { {3,1},{3,2},{1,0},{0,4},{0,5},{4,6} };
    check.checkLongLong(7, o.minimumFuelCost(roads, 2));

    roads = {};
    check.checkLongLong(0, o.minimumFuelCost(roads, 1));
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
