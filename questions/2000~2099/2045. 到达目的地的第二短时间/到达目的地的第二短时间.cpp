/* 到达目的地的第二短时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
城市用一个 双向连通 图表示，图中有 n 个节点，从 1 到 n 编号（包含 1 和 n）。图中的边用一个二维整数数组 edges 表示，其中每个 edges[i] = [ui, vi] 表示一条节点 ui 和节点 vi 之间的双向连通边。每组节点对由 最多一条 边连通，顶点不存在连接到自身的边。穿过任意一条边的时间是 time 分钟。

每个节点都有一个交通信号灯，每 change 分钟改变一次，从绿色变成红色，再由红色变成绿色，循环往复。所有信号灯都 同时 改变。你可以在 任何时候 进入某个节点，但是 只能 在节点 信号灯是绿色时 才能离开。如果信号灯是  绿色 ，你 不能 在节点等待，必须离开。

第二小的值 是 严格大于 最小值的所有值中最小的值。

例如，[2, 3, 4] 中第二小的值是 3 ，而 [2, 2, 4] 中第二小的值是 4 。
给你 n、edges、time 和 change ，返回从节点 1 到节点 n 需要的 第二短时间 。

注意：

你可以 任意次 穿过任意顶点，包括 1 和 n 。
你可以假设在 启程时 ，所有信号灯刚刚变成 绿色 。
 

示例 1：

        

输入：n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
输出：13
解释：
上面的左图展现了给出的城市交通图。
右图中的蓝色路径是最短时间路径。
花费的时间是：
- 从节点 1 开始，总花费时间=0
- 1 -> 4：3 分钟，总花费时间=3
- 4 -> 5：3 分钟，总花费时间=6
因此需要的最小时间是 6 分钟。

右图中的红色路径是第二短时间路径。
- 从节点 1 开始，总花费时间=0
- 1 -> 3：3 分钟，总花费时间=3
- 3 -> 4：3 分钟，总花费时间=6
- 在节点 4 等待 4 分钟，总花费时间=10
- 4 -> 5：3 分钟，总花费时间=13
因此第二短时间是 13 分钟。
示例 2：



输入：n = 2, edges = [[1,2]], time = 3, change = 2
输出：11
解释：
最短时间路径是 1 -> 2 ，总花费时间 = 3 分钟
最短时间路径是 1 -> 2 -> 1 -> 2 ，总花费时间 = 11 分钟
 

提示：

2 <= n <= 104
n - 1 <= edges.length <= min(2 * 104, n * (n - 1) / 2)
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
不含重复边
每个节点都可以从其他节点直接或者间接到达
1 <= time, change <= 103

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/second-minimum-time-to-reach-destination
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../tools/TestData.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adjs(n + 1);
        getAdjs(edges, adjs);

        vector<int> minimum(n + 1, INT_MAX), secondMin(n + 1, INT_MAX);
        minimum[1] = 0;

        queue<pair<int, int>> bfs;
        bfs.push({ 1,0 });

        while (!bfs.empty()) {
            int node = bfs.front().first, minute = bfs.front().second;
            bfs.pop();

            for (int next : adjs[node]) {
                int arrival = getDepartureTime(minute, change) + time;
                if (arrival < secondMin[next]) {
                    maintenceMin(next, arrival, minimum, secondMin);
                    bfs.push({ next, arrival });
                }
            }
        }

        return secondMin[n];
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    int getDepartureTime(int arrival, int change) {
        int interval = arrival / change;
        return (interval & 1) == 0 ? arrival : (interval + 1) * change;
    }

    void maintenceMin(int node, int minute, vector<int>& minimum, vector<int>& secondMin) {
        if (minute < minimum[node]) {
            secondMin[node] = minimum[node];
            minimum[node] = minute;
        }
        else if (minute > minimum[node] && minute < secondMin[node]) {
            secondMin[node] = minute;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {1,2},{1,3},{1,4},{3,4},{4,5} };
    check.checkInt(13, o.secondMinimum(5, edges, 3, 5));

    edges = { {1,2},{1,3},{1,4},{3,4},{4,5} };
    check.checkInt(5, o.secondMinimum(5, edges, 1, 1));

    edges = { {1,2} };
    check.checkInt(11, o.secondMinimum(2, edges, 3, 2));

    edges = { {1,2},{1,3},{2,3} };
    check.checkInt(7, o.secondMinimum(3, edges, 3, 2));

    edges = getIntVectorVector("./testcase1.txt");
    check.checkInt(12829, o.secondMinimum(8541, edges, 861, 272));

    edges = getIntVectorVector("./testcase2.txt");
    check.checkInt(120, o.secondMinimum(10000, edges, 23, 37));
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
