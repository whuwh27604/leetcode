/* 网络延迟时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 N 个网络节点，标记为 1 到 N。

给定一个列表 times，表示信号经过有向边的传递时间。 times[i] = (u, v, w)，其中 u 是源节点，v 是目标节点， w 是一个信号从源节点传递到目标节点的时间。

现在，我们从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1。

 

示例：



输入：times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
输出：2
 

注意:

N 的范围在 [1, 100] 之间。
K 的范围在 [1, N] 之间。
times 的长度在 [1, 6000] 之间。
所有的边 times[i] = (u, v, w) 都有 1 <= u, v <= N 且 0 <= w <= 100。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/network-delay-time
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

struct pairCompare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<pair<int, int>>> fromTos;
        hashTimes(times, fromTos);

        vector<int> minDistances(N + 1, INT_MAX);
        minDistances[K] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, pairCompare> nodes;  // 使用优先队列，每次选出距离最小的点拓展下一个
        nodes.push({ K,0 });

        while (!nodes.empty()) {
            pair<int, int> from = nodes.top();
            nodes.pop();

            auto iter = fromTos.find(from.first);
            if (iter == fromTos.end()) {
                continue;
            }

            vector<pair<int, int>>& tos = iter->second;
            for (int i = 0; i < (int)tos.size(); i++) {
                int distance2Next = from.second + tos[i].second;
                if (distance2Next < minDistances[tos[i].first]) {  // 从K节点到to节点的距离出现了更小的值，更新并往下拓展
                    minDistances[tos[i].first] = distance2Next;
                    nodes.push({ tos[i].first, distance2Next });
                }
            }
        }

        int maxDistance = 0;
        for (int i = 1; i <= N; i++) {
            if (minDistances[i] == INT_MAX) {  // 该节点不可达
                return -1;
            }

            if (minDistances[i] > maxDistance) {
                maxDistance = minDistances[i];
            }
        }

        return maxDistance;
    }

    void hashTimes(vector<vector<int>>& times, unordered_map<int, vector<pair<int, int>>>& fromTos) {
        for (vector<int>& time : times) {
            auto iter = fromTos.find(time[0]);
            if (iter == fromTos.end()) {
                fromTos[time[0]] = { { time[1], time[2] } };
            }
            else {
                iter->second.push_back({ time[1], time[2] });
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> times = { {2,1,1},{2,3,1},{3,4,1} };
    check.checkInt(2, o.networkDelayTime(times, 4, 2));
    check.checkInt(-1, o.networkDelayTime(times, 4, 3));

    times = { {1,2,1},{2,3,7},{1,3,4},{2,1,2} };
    check.checkInt(-1, o.networkDelayTime(times, 4, 1));
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
