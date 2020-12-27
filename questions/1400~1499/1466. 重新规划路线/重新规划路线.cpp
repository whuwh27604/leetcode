/* 重新规划路线.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
n 座城市，从 0 到 n-1 编号，其间共有 n-1 条路线。因此，要想在两座不同城市之间旅行只有唯一一条路线可供选择（路线网形成一颗树）。去年，交通运输部决定重新规划路线，以改变交通拥堵的状况。

路线用 connections 表示，其中 connections[i] = [a, b] 表示从城市 a 到 b 的一条有向路线。

今年，城市 0 将会举办一场大型比赛，很多游客都想前往城市 0 。

请你帮助重新规划路线方向，使每个城市都可以访问城市 0 。返回需要变更方向的最小路线数。

题目数据 保证 每个城市在重新规划路线方向后都能到达城市 0 。

 

示例 1：



输入：n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
输出：3
解释：更改以红色显示的路线的方向，使每个城市都可以到达城市 0 。
示例 2：



输入：n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
输出：2
解释：更改以红色显示的路线的方向，使每个城市都可以到达城市 0 。
示例 3：

输入：n = 3, connections = [[1,0],[2,0]]
输出：0
 

提示：

2 <= n <= 5 * 10^4
connections.length == n-1
connections[i].length == 2
0 <= connections[i][0], connections[i][1] <= n-1
connections[i][0] != connections[i][1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjacencies(n);
        vector<unordered_set<int>> fromTos(n);
        fromTos[0].insert(n);
        int redirections = 0;

        getAdjacency(connections, adjacencies, fromTos);
        DFS(0, n, adjacencies, fromTos, redirections);

        return redirections;
    }

    void getAdjacency(vector<vector<int>>& connections, vector<vector<int>>& adjacencies, vector<unordered_set<int>>& fromTos) {
        for (auto& connection : connections) {
            fromTos[connection[0]].insert(connection[1]);
            adjacencies[connection[0]].push_back(connection[1]);
            adjacencies[connection[1]].push_back(connection[0]);
        }
    }

    void DFS(int root, int from, vector<vector<int>>& adjacencies, vector<unordered_set<int>>& fromTos, int& redirections) {
        if (fromTos[root].count(from) == 0) {
            ++redirections;
        }

        for (int to : adjacencies[root]) {
            if (to != from) {
                DFS(to, root, adjacencies, fromTos, redirections);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> connections = { {0,1},{1,3},{2,3},{4,0},{4,5} };
    check.checkInt(3, o.minReorder(6, connections));

    connections = { {1,0},{1,2},{3,2},{3,4} };
    check.checkInt(2, o.minReorder(5, connections));

    connections = { {1,0},{2,0} };
    check.checkInt(0, o.minReorder(3, connections));

    connections = { {0,1},{2,0},{3,0},{4,1},{0,5},{1,6},{0,7} };
    check.checkInt(4, o.minReorder(8, connections));
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
