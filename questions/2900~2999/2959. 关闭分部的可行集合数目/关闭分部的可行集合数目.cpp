/* 关闭分部的可行集合数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个公司在全国有 n 个分部，它们之间有的有道路连接。一开始，所有分部通过这些道路两两之间互相可以到达。

公司意识到在分部之间旅行花费了太多时间，所以它们决定关闭一些分部（也可能不关闭任何分部），同时保证剩下的分部之间两两互相可以到达且最远距离不超过 maxDistance 。

两个分部之间的 距离 是通过道路长度之和的 最小值 。

给你整数 n ，maxDistance 和下标从 0 开始的二维整数数组 roads ，其中 roads[i] = [ui, vi, wi] 表示一条从 ui 到 vi 长度为 wi的 无向 道路。

请你返回关闭分部的可行方案数目，满足每个方案里剩余分部之间的最远距离不超过 maxDistance。

注意，关闭一个分部后，与之相连的所有道路不可通行。

注意，两个分部之间可能会有多条道路。



示例 1：



输入：n = 3, maxDistance = 5, roads = [[0,1,2],[1,2,10],[0,2,10]]
输出：5
解释：可行的关闭分部方案有：
- 关闭分部集合 [2] ，剩余分部为 [0,1] ，它们之间的距离为 2 。
- 关闭分部集合 [0,1] ，剩余分部为 [2] 。
- 关闭分部集合 [1,2] ，剩余分部为 [0] 。
- 关闭分部集合 [0,2] ，剩余分部为 [1] 。
- 关闭分部集合 [0,1,2] ，关闭后没有剩余分部。
总共有 5 种可行的关闭方案。
示例 2：



输入：n = 3, maxDistance = 5, roads = [[0,1,20],[0,1,10],[1,2,2],[0,2,2]]
输出：7
解释：可行的关闭分部方案有：
- 关闭分部集合 [] ，剩余分部为 [0,1,2] ，它们之间的最远距离为 4 。
- 关闭分部集合 [0] ，剩余分部为 [1,2] ，它们之间的距离为 2 。
- 关闭分部集合 [1] ，剩余分部为 [0,2] ，它们之间的距离为 2 。
- 关闭分部集合 [0,1] ，剩余分部为 [2] 。
- 关闭分部集合 [1,2] ，剩余分部为 [0] 。
- 关闭分部集合 [0,2] ，剩余分部为 [1] 。
- 关闭分部集合 [0,1,2] ，关闭后没有剩余分部。
总共有 7 种可行的关闭方案。
示例 3：

输入：n = 1, maxDistance = 10, roads = []
输出：2
解释：可行的关闭分部方案有：
- 关闭分部集合 [] ，剩余分部为 [0] 。
- 关闭分部集合 [0] ，关闭后没有剩余分部。
总共有 2 种可行的关闭方案。


提示：

1 <= n <= 10
1 <= maxDistance <= 105
0 <= roads.length <= 1000
roads[i].length == 3
0 <= ui, vi <= n - 1
ui != vi
1 <= wi <= 1000
一开始所有分部之间通过道路互相可以到达。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>> distances(n, vector<int>(n, INT_MAX / 2));
        int maxMask = (1 << n), sets = 0;

        getDistances(roads, distances);

        for (int mask = 0; mask < maxMask; ++mask) {
            if (check(n, mask, maxDistance, distances)) {
                ++sets;
            }
        }

        return sets;
    }

    void getDistances(vector<vector<int>>& roads, vector<vector<int>>& distances) {
        for (auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            distances[u][v] = min(distances[u][v], w);
            distances[v][u] = min(distances[v][u], w);
        }
    }

    bool check(int n, int mask, int maxDistance, vector<vector<int>> distances) {
        floyd(n, mask, maxDistance, distances);

        return checkMaxDistance(n, mask, maxDistance, distances);
    }

    void floyd(int n, int mask, int maxDistance, vector<vector<int>>& distances) {
        for (int k = 0, bit0 = 1; k < n; ++k, bit0 <<= 1) {
            if ((mask & bit0) != 0) {
                for (int i = 0, bit1 = 1; i < n; ++i, bit1 <<= 1) {
                    if ((mask & bit1) != 0) {
                        for (int j = 0, bit2 = 1; j < n; ++j, bit2 <<= 1) {
                            if ((mask & bit2) != 0) {
                                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                            }
                        }
                    }
                }
            }
        }
    }

    bool checkMaxDistance(int n, int mask, int maxDistance, vector<vector<int>>& distances) {
        for (int i = 0, bit0 = 1; i < n; ++i, bit0 <<= 1) {
            if ((mask & bit0) != 0) {
                for (int j = 0, bit1 = 1; j < n; ++j, bit1 <<= 1) {
                    if ((mask & bit1) != 0 && i != j && distances[i][j] > maxDistance) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> roads = { {0,1,2},{1,2,10},{0,2,10} };
    check.checkInt(5, o.numberOfSets(3, 5, roads));

    roads = { {0,1,20},{0,1,10},{1,2,2},{0,2,2} };
    check.checkInt(7, o.numberOfSets(3, 5, roads));

    roads = {};
    check.checkInt(2, o.numberOfSets(1, 10, roads));
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
