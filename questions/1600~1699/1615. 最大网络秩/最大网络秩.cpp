/* 最大网络秩.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
n 座城市和一些连接这些城市的道路 roads 共同组成一个基础设施网络。每个 roads[i] = [ai, bi] 都表示在城市 ai 和 bi 之间有一条双向道路。

两座不同城市构成的 城市对 的 网络秩 定义为：与这两座城市 直接 相连的道路总数。如果存在一条道路直接连接这两座城市，则这条道路只计算 一次 。

整个基础设施网络的 最大网络秩 是所有不同城市对中的 最大网络秩 。

给你整数 n 和数组 roads，返回整个基础设施网络的 最大网络秩 。

 

示例 1：



输入：n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
输出：4
解释：城市 0 和 1 的网络秩是 4，因为共有 4 条道路与城市 0 或 1 相连。位于 0 和 1 之间的道路只计算一次。
示例 2：



输入：n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
输出：5
解释：共有 5 条道路与城市 1 或 2 相连。
示例 3：

输入：n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
输出：5
解释：2 和 5 的网络秩为 5，注意并非所有的城市都需要连接起来。
 

提示：

2 <= n <= 100
0 <= roads.length <= n * (n - 1) / 2
roads[i].length == 2
0 <= ai, bi <= n-1
ai != bi
每对城市之间 最多只有一条 道路相连

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-network-rank
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if (roads.empty()) {
            return 0;
        }

        vector<int> indegrees(n, 0);
        unordered_set<int> hashRoads;
        getIndegrees(roads, indegrees, hashRoads);

        vector<int> Indegree1stCities, Indegree2ndCities;
        pair<int, int> max2Indegrees = get1st2ndIndegrees(n, indegrees, Indegree1stCities, Indegree2ndCities);

        int maxNetworkRank = Indegree1stCities.size() == 1 ? max2Indegrees.first + max2Indegrees.second : max2Indegrees.first * 2;

        return checkIfTwoCitiesNoRoad(Indegree1stCities, Indegree2ndCities, hashRoads) ? maxNetworkRank : maxNetworkRank - 1;
    }

    void getIndegrees(vector<vector<int>>& roads, vector<int>& indegrees, unordered_set<int>& hashRoads) {
        for (auto& road : roads) {
            ++indegrees[road[0]];
            ++indegrees[road[1]];
            hashRoads.insert(road[0] * 1000 + road[1]);
            hashRoads.insert(road[1] * 1000 + road[0]);
        }
    }

    pair<int, int> get1st2ndIndegrees(int n, vector<int>& indegrees, vector<int>& Indegree1stCities, vector<int>& Indegree2ndCities) {
        int  i, first = 1, second = 1;

        for (i = 0; i < n; ++i) {
            if (indegrees[i] > first) {
                Indegree2ndCities = Indegree1stCities;
                Indegree1stCities = { i };
                second = first;
                first = indegrees[i];
            }
            else if (indegrees[i] == first) {
                Indegree1stCities.push_back(i);
            }
            else if (indegrees[i] > second) {
                Indegree2ndCities = { i };
                second = indegrees[i];
            }
            else if (indegrees[i] == second) {
                Indegree2ndCities.push_back(i);
            }
        }

        return { first, second };
    }

    bool checkIfTwoCitiesNoRoad(vector<int>& Indegree1stCities, vector<int>& Indegree2ndCities, unordered_set<int>& hashRoads) {
        int i, j, size1 = Indegree1stCities.size(), size2 = Indegree2ndCities.size();

        if (size1 == 1) {
            for (i = 0; i < size2; ++i) {
                if (hashRoads.count(Indegree1stCities[0] * 1000 + Indegree2ndCities[i]) == 0) {
                    return true;
                }
            }
        }
        else {
            for (i = 0; i < size1 - 1; ++i) {
                for (j = i + 1; j < size1; ++j) {
                    if (hashRoads.count(Indegree1stCities[i] * 1000 + Indegree1stCities[j]) == 0) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> roads = { {0,1},{0,3},{1,2},{1,3} };
    check.checkInt(4, o.maximalNetworkRank(4, roads));

    roads = { {0,1},{0,3},{1,2},{1,3},{2,3},{2,4} };
    check.checkInt(5, o.maximalNetworkRank(5, roads));

    roads = { {0,1},{1,2},{2,3},{2,4},{5,6},{5,7} };
    check.checkInt(5, o.maximalNetworkRank(8, roads));

    roads = {  };
    check.checkInt(0, o.maximalNetworkRank(2, roads));

    roads = { {0,1} };
    check.checkInt(1, o.maximalNetworkRank(2, roads));

    roads = { {0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4} };
    check.checkInt(7, o.maximalNetworkRank(5, roads));
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
