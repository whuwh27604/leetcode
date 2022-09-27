/* 电动车游城市.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小明的电动车电量充满时可行驶距离为 cnt，每行驶 1 单位距离消耗 1 单位电量，且花费 1 单位时间。小明想选择电动车作为代步工具。地图上共有 N 个景点，景点编号为 0 ~ N-1。他将地图信息以 [城市 A 编号,城市 B 编号,两城市间距离] 格式整理在在二维数组 paths，表示城市 A、B 间存在双向通路。初始状态，电动车电量为 0。每个城市都设有充电桩，charge[i] 表示第 i 个城市每充 1 单位电量需要花费的单位时间。请返回小明最少需要花费多少单位时间从起点城市 start 抵达终点城市 end。

示例 1：

输入：paths = [[1,3,3],[3,2,1],[2,1,3],[0,1,4],[3,0,5]], cnt = 6, start = 1, end = 0, charge = [2,10,4,1]

输出：43

解释：最佳路线为：1->3->0。
在城市 1 仅充 3 单位电至城市 3，然后在城市 3 充 5 单位电，行驶至城市 5。
充电用时共 3*10 + 5*1= 35
行驶用时 3 + 5 = 8，此时总用时最短 43。


示例 2：

输入：paths = [[0,4,2],[4,3,5],[3,0,5],[0,1,5],[3,2,4],[1,2,8]], cnt = 8, start = 0, end = 2, charge = [4,1,1,3,2]

输出：38

解释：最佳路线为：0->4->3->2。
城市 0 充电 2 单位，行驶至城市 4 充电 8 单位，行驶至城市 3 充电 1 单位，最终行驶至城市 2。
充电用时 4*2+2*8+3*1 = 27
行驶用时 2+5+4 = 11，总用时最短 38。

提示：

1 <= paths.length <= 200
paths[i].length == 3
2 <= charge.length == n <= 100
0 <= path[i][0],path[i][1],start,end < n
1 <= cnt <= 100
1 <= path[i][2] <= cnt
1 <= charge[i] <= 100
题目保证所有城市相互可以到达

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/DFPeFJ
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int minCost;
    int city;
    int elect;

    Node(int cost, int c_, int e_) : minCost(cost), city(c_), elect(e_) {}

    bool operator<(const Node& node) const {
        return minCost > node.minCost;
    }
};

class Solution {
public:
    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {
        int n = charge.size();
        vector<vector<pair<int, int>>> adjs(n);

        getAdjs(n, paths, adjs);

        return dijkstra(adjs, n, cnt, start, end, charge);
    }

    void getAdjs(int n, vector<vector<int>>& paths, vector<vector<pair<int, int>>>& adjs) {
        vector<vector<int>> distances(n, vector<int>(n, INT_MAX));

        for (auto& path : paths) {
            int from = path[0], to = path[1], dist = path[2];
            if (dist < distances[from][to]) {
                distances[from][to] = dist;
                distances[to][from] = dist;
            }
        }

        for (int from = 0; from < n; ++from) {
            for (int to = 0; to < n; ++to) {
                if (distances[from][to] != INT_MAX) {
                    adjs[from].push_back({ to,distances[from][to] });
                }
            }
        }
    }

    int dijkstra(vector<vector<pair<int, int>>>& adjs, int n, int cnt, int start, int end, vector<int>& charge) {
        vector<vector<int>> minCosts(n, vector<int>(cnt + 1, INT_MAX));
        priority_queue<Node> nodes;
        nodes.push(Node(0, start, 0));

        while (!nodes.empty()) {
            Node node = nodes.top();
            nodes.pop();

            if (node.city == end) {  // end第一次出队列时，一定是电量为0，并且是到end的最小花费
                return node.minCost;
            }

            if (node.elect < cnt) {  // 如果电量不满，给自己充一个单位的电
                int minCost = node.minCost + charge[node.city];
                if (minCost < minCosts[node.city][node.elect + 1]) {
                    minCosts[node.city][node.elect + 1] = minCost;
                    nodes.push(Node(minCost, node.city, node.elect + 1));
                }
            }
            
            for (auto& next : adjs[node.city]) {
                int minCost = node.minCost + next.second;
                if (node.elect >= next.second && minCost < minCosts[next.first][node.elect - next.second]) {  // 可以到达下一站
                    minCosts[next.first][node.elect - next.second] = minCost;
                    nodes.push(Node(minCost, next.first, node.elect - next.second));
                }
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> paths = { {1,3,3},{3,2,1},{2,1,3},{0,1,4},{3,0,5} };
    vector<int> charge = { 2,10,4,1 };
    check.checkInt(43, o.electricCarPlan(paths, 6, 1, 0, charge));

    paths = { {0,4,2},{4,3,5},{3,0,5},{0,1,5},{3,2,4},{1,2,8} };
    charge = { 4,1,1,3,2 };
    check.checkInt(38, o.electricCarPlan(paths, 8, 0, 2, charge));

    paths = { {3,6,9},{0,7,24},{5,3,27},{7,6,1},{1,2,41},{3,6,28},{2,3,30},{5,0,41},{0,3,13},{6,4,4},{3,5,20},{0,5,22},{0,1,6},{7,5,11},{5,6,17},{0,6,22},{1,6,32},{2,4,25},{0,7,34},{0,4,36},{3,0,25} };
    charge = { 34,15,30,64,67,11,33,98 };
    check.checkInt(578, o.electricCarPlan(paths, 43, 4, 3, charge));
    
    paths = { {3,7,32},{0,6,46},{1,0,47},{0,6,8},{0,3,30},{1,5,34},{1,2,9},{1,4,29},{0,1,6} };
    charge = { 90,57,24,52,75,61,39,20 };
    check.checkInt(3801, o.electricCarPlan(paths, 52, 4, 5, charge));
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
