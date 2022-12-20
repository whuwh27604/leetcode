/* 两个城市间路径的最小分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n ，表示总共有 n 个城市，城市从 1 到 n 编号。给你一个二维数组 roads ，其中 roads[i] = [ai, bi, distancei] 表示城市 ai 和 bi 之间有一条 双向 道路，道路距离为 distancei 。城市构成的图不一定是连通的。

两个城市之间一条路径的 分数 定义为这条路径中道路的 最小 距离。

城市 1 和城市 n 之间的所有路径的 最小 分数。

注意：

一条路径指的是两个城市之间的道路序列。
一条路径可以 多次 包含同一条道路，你也可以沿着路径多次到达城市 1 和城市 n 。
测试数据保证城市 1 和城市n 之间 至少 有一条路径。


示例 1：



输入：n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
输出：5
解释：城市 1 到城市 4 的路径中，分数最小的一条为：1 -> 2 -> 4 。这条路径的分数是 min(9,5) = 5 。
不存在分数更小的路径。
示例 2：



输入：n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
输出：2
解释：城市 1 到城市 4 分数最小的路径是：1 -> 2 -> 1 -> 3 -> 4 。这条路径的分数是 min(2,2,4,7) = 2 。


提示：

2 <= n <= 105
1 <= roads.length <= 105
roads[i].length == 3
1 <= ai, bi <= n
ai != bi
1 <= distancei <= 104
不会有重复的边。
城市 1 和城市 n 之间至少有一条路径。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int maxN = getMaxN(roads), leastScore = INT_MAX;
        vector<vector<pair<int, int>>> adjs(maxN + 1);
        vector<bool> visited(maxN + 1, false);
        visited[1] = true;

        getAdjs(roads, adjs);
        DFS(1, adjs, visited, leastScore);

        return leastScore;
    }

    int getMaxN(vector<vector<int>>& roads) {
        int maxN = 0;

        for (auto& road : roads) {
            maxN = max(maxN, max(road[0], road[1]));
        }

        return maxN;
    }

    void getAdjs(vector<vector<int>>& roads, vector<vector<pair<int, int>>>& adjs) {
        for (auto& road : roads) {
            adjs[road[0]].push_back({ road[1],road[2] });
            adjs[road[1]].push_back({ road[0],road[2] });
        }
    }

    void DFS(int city, vector<vector<pair<int, int>>>& adjs, vector<bool>& visited, int& leastScore) {
        for (auto& next : adjs[city]) {
            leastScore = min(leastScore, next.second);
            if (!visited[next.first]) {
                visited[next.first] = true;
                DFS(next.first, adjs, visited, leastScore);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> roads = { {1,2,9},{2,3,6},{2,4,5},{1,4,7} };
    check.checkInt(5, o.minScore(4, roads));

    roads = { {1,2,2},{1,3,4},{3,4,7} };
    check.checkInt(2, o.minScore(4, roads));

    roads = getIntVectorVector("./testcase1.txt");
    check.checkInt(1, o.minScore(73022, roads));
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
