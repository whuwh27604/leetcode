/* 收集树上所有苹果的最少时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵有 n 个节点的无向树，节点编号为 0 到 n-1 ，它们中有一些节点有苹果。通过树上的一条边，需要花费 1 秒钟。你从 节点 0 出发，请你返回最少需要多少秒，可以收集到所有苹果，并回到节点 0 。

无向树的边由 edges 给出，其中 edges[i] = [fromi, toi] ，表示有一条边连接 from 和 toi 。除此以外，还有一个布尔数组 hasApple ，其中 hasApple[i] = true 代表节点 i 有一个苹果，否则，节点 i 没有苹果。

 

示例 1：



输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
输出：8
解释：上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
示例 2：



输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
输出：6
解释：上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
示例 3：

输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
输出：0
 

提示：

1 <= n <= 10^5
edges.length == n-1
edges[i].length == 2
0 <= fromi, toi <= n-1
fromi < toi
hasApple.length == n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-time-to-collect-all-apples-in-a-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjacencies(n, vector<int>{});
        getAdjacencies(edges, adjacencies);

        vector<int> visited(n, 0);
        int time = 0;

        return DFS(0, adjacencies, hasApple, visited, time) ? time - 2 : time;
    }

    void getAdjacencies(vector<vector<int>>& edges, vector<vector<int>>& adjacencies) {
        for (auto& edge : edges) {
            adjacencies[edge[0]].push_back(edge[1]);
            adjacencies[edge[1]].push_back(edge[0]);
        }
    }

    bool DFS(int root, vector<vector<int>>& adjacencies, vector<bool>& hasApple, vector<int>& visited, int& time) {
        if (visited[root] == 1) {
            return false;
        }

        bool needCount = hasApple[root];
        visited[root] = 1;

        for (int neighbour : adjacencies[root]) {
            if (DFS(neighbour, adjacencies, hasApple, visited, time)) {
                needCount = true;
            }
        }

        if (needCount) {
            time += 2;
        }

        return needCount;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1},{0,2},{1,4},{1,5},{2,3},{2,6} };
    vector<bool> hasApple = { false,false,true,false,true,true,false };
    check.checkInt(8, o.minTime(7, edges, hasApple));

    edges = { {0,1},{0,2},{1,4},{1,5},{2,3},{2,6} };
    hasApple = { false,false,true,false,false,true,false };
    check.checkInt(6, o.minTime(7, edges, hasApple));

    edges = { {0,1},{0,2},{1,4},{1,5},{2,3},{2,6} };
    hasApple = { false,false,false,false,false,false,false };
    check.checkInt(0, o.minTime(7, edges, hasApple));

    edges = { {0,2},{0,3},{1,2} };
    hasApple = { false,true,false,false };
    check.checkInt(4, o.minTime(4, edges, hasApple));

    edges = { {0,2},{1,2} };
    hasApple = { false,true,false };
    check.checkInt(4, o.minTime(3, edges, hasApple));

    edges = { {0,1},{1,2},{3,4},{0,4} };
    hasApple = { false,false,false,true,false };
    check.checkInt(4, o.minTime(5, edges, hasApple));

    edges = {  };
    hasApple = { true };
    check.checkInt(0, o.minTime(1, edges, hasApple));
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
