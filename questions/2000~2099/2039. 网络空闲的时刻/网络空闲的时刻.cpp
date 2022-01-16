/* 网络空闲的时刻.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个有 n 个服务器的计算机网络，服务器编号为 0 到 n - 1 。同时给你一个二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示服务器 ui 和 vi 之间有一条信息线路，在 一秒 内它们之间可以传输 任意 数目的信息。再给你一个长度为 n 且下标从 0 开始的整数数组 patience 。

题目保证所有服务器都是 相通 的，也就是说一个信息从任意服务器出发，都可以通过这些信息线路直接或间接地到达任何其他服务器。

编号为 0 的服务器是 主 服务器，其他服务器为 数据 服务器。每个数据服务器都要向主服务器发送信息，并等待回复。信息在服务器之间按 最优 线路传输，也就是说每个信息都会以 最少时间 到达主服务器。主服务器会处理 所有 新到达的信息并 立即 按照每条信息来时的路线 反方向 发送回复信息。

在 0 秒的开始，所有数据服务器都会发送各自需要处理的信息。从第 1 秒开始，每 一秒最 开始 时，每个数据服务器都会检查它是否收到了主服务器的回复信息（包括新发出信息的回复信息）：

如果还没收到任何回复信息，那么该服务器会周期性 重发 信息。数据服务器 i 每 patience[i] 秒都会重发一条信息，也就是说，数据服务器 i 在上一次发送信息给主服务器后的 patience[i] 秒 后 会重发一条信息给主服务器。
否则，该数据服务器 不会重发 信息。
当没有任何信息在线路上传输或者到达某服务器时，该计算机网络变为 空闲 状态。

请返回计算机网络变为 空闲 状态的 最早秒数 。

 

示例 1：



输入：edges = [[0,1],[1,2]], patience = [0,2,1]
输出：8
解释：
0 秒最开始时，
- 数据服务器 1 给主服务器发出信息（用 1A 表示）。
- 数据服务器 2 给主服务器发出信息（用 2A 表示）。

1 秒时，
- 信息 1A 到达主服务器，主服务器立刻处理信息 1A 并发出 1A 的回复信息。
- 数据服务器 1 还没收到任何回复。距离上次发出信息过去了 1 秒（1 < patience[1] = 2），所以不会重发信息。
- 数据服务器 2 还没收到任何回复。距离上次发出信息过去了 1 秒（1 == patience[2] = 1），所以它重发一条信息（用 2B 表示）。

2 秒时，
- 回复信息 1A 到达服务器 1 ，服务器 1 不会再重发信息。
- 信息 2A 到达主服务器，主服务器立刻处理信息 2A 并发出 2A 的回复信息。
- 服务器 2 重发一条信息（用 2C 表示）。
...
4 秒时，
- 回复信息 2A 到达服务器 2 ，服务器 2 不会再重发信息。
...
7 秒时，回复信息 2D 到达服务器 2 。

从第 8 秒开始，不再有任何信息在服务器之间传输，也不再有信息到达服务器。
所以第 8 秒是网络变空闲的最早时刻。
示例 2：



输入：edges = [[0,1],[0,2],[1,2]], patience = [0,10,10]
输出：3
解释：数据服务器 1 和 2 第 2 秒初收到回复信息。
从第 3 秒开始，网络变空闲。
 

提示：

n == patience.length
2 <= n <= 105
patience[0] == 0
对于 1 <= i < n ，满足 1 <= patience[i] <= 105
1 <= edges.length <= min(105, n * (n - 1) / 2)
edges[i].length == 2
0 <= ui, vi < n
ui != vi
不会有重边。
每个服务器都直接或间接与别的服务器相连。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-time-when-the-network-becomes-idle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size(), idleTime = 0;
        vector<vector<int>> adjs(n);
        vector<int> distances(n, -1);

        getAdjs(edges, adjs);
        getDistances(adjs, distances);

        for (int i = 1; i < n; ++i) {
            idleTime = max(idleTime, (distances[i] * 2 - 1) / patience[i] * patience[i] + 2 * distances[i] + 1);
        }

        return idleTime;
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    void getDistances(vector<vector<int>>& adjs, vector<int>& distances) {
        int distance = 0;
        queue<int> bfs;

        bfs.push(0);
        distances[0] = 0;

        while (!bfs.empty()) {
            int i, size = bfs.size();
            ++distance;

            for (i = 0; i < size; ++i) {
                int node = bfs.front();
                bfs.pop();

                for (int next : adjs[node]) {
                    if (distances[next] == -1) {
                        distances[next] = distance;
                        bfs.push(next);
                    }
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = {{0,1},{1,2}};
    vector<int> patience = {0,2,1};
    check.checkInt(8,o.networkBecomesIdle(edges,patience));

    edges = {{0,1},{0,2},{1,2}};
    patience = {0,10,10};
    check.checkInt(3,o.networkBecomesIdle(edges,patience));

    edges = {{9,10},{0,4},{10,11},{8,3},{0,9},{6,8},{0,1},{8,2},{11,3},{8,11},{7,6},{1,5},{4,2},{5,3},{0,7},{3,2},{11,2}};
    patience = {0,1,1,9,3,1,1,1,5,3,1,5};
    check.checkInt(12, o.networkBecomesIdle(edges, patience));
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
