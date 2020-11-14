/* 颜色交替的最短路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个有向图中，节点分别标记为 0, 1, ..., n-1。这个图中的每条边不是红色就是蓝色，且存在自环或平行边。

red_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的红色有向边。类似地，blue_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的蓝色有向边。

返回长度为 n 的数组 answer，其中 answer[X] 是从节点 0 到节点 X 的红色边和蓝色边交替出现的最短路径的长度。如果不存在这样的路径，那么 answer[x] = -1。

 

示例 1：

输入：n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
输出：[0,1,-1]
示例 2：

输入：n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
输出：[0,1,-1]
示例 3：

输入：n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
输出：[0,-1,-1]
示例 4：

输入：n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
输出：[0,1,2]
示例 5：

输入：n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
输出：[0,1,1]
 

提示：

1 <= n <= 100
red_edges.length <= 400
blue_edges.length <= 400
red_edges[i].length == blue_edges[i].length == 2
0 <= red_edges[i][j], blue_edges[i][j] < n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-path-with-alternating-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> redEdges(n, vector<int>{}), blueEdges(n, vector<int>{});
        catalog(red_edges, redEdges);
        catalog(blue_edges, blueEdges);

        vector<int> redFirstPathLen(n, 0), blueFirstPathLen(n, 0), pathLen(n, 0);
        bfsPath(redEdges, blueEdges, false, redFirstPathLen);
        bfsPath(redEdges, blueEdges, true, blueFirstPathLen);

        getShortestPath(redFirstPathLen, blueFirstPathLen, pathLen);
        return pathLen;
    }

    void catalog(vector<vector<int>>& edges, vector<vector<int>>& fromTos) {
        for (vector<int>& edge : edges) {
            fromTos[edge[0]].push_back(edge[1]);
        }
    }

    void bfsPath(vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges, bool cameFromRed, vector<int>& pathLen) {
        int length = 0;
        queue<int> bfs;
        bfs.push(0);
        pathLen[0] |= 0x60000000;

        while (!bfs.empty()) {
            int i, size = bfs.size();
            for (i = 0; i < size; ++i) {
                int node = bfs.front();
                bfs.pop();

                if ((pathLen[node] & 0xffffff) == 0) {
                    pathLen[node] += length;
                }

                if (cameFromRed) {
                    for (int next : blueEdges[node]) {
                        if ((pathLen[next] & 0x40000000) == 0) {
                            pathLen[next] |= 0x40000000;
                            bfs.push(next);
                        }
                    }
                }
                else {
                    for (int next : redEdges[node]) {
                        if ((pathLen[next] & 0x20000000) == 0) {
                            pathLen[next] |= 0x20000000;
                            bfs.push(next);
                        }
                    }
                }
            }

            cameFromRed = !cameFromRed;
            ++length;
        }
    }

    void getShortestPath(vector<int>& redFirstPathLen, vector<int>& blueFirstPathLen, vector<int>& pathLen) {
        for (unsigned int i = 1; i < pathLen.size(); ++i) {
            redFirstPathLen[i] &= 0xffffff;
            blueFirstPathLen[i] &= 0xffffff;

            if (redFirstPathLen[i] != 0 && blueFirstPathLen[i] != 0) {
                pathLen[i] = min(redFirstPathLen[i], blueFirstPathLen[i]);
            }
            else if (redFirstPathLen[i] == 0 && blueFirstPathLen[i] != 0) {
                pathLen[i] = blueFirstPathLen[i];
            }
            else if (redFirstPathLen[i] != 0 && blueFirstPathLen[i] == 0) {
                pathLen[i] = redFirstPathLen[i];
            }
            else {
                pathLen[i] = -1;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> red_edges = { {0,1},{1,2} };
    vector<vector<int>> blue_edges = {};
    vector<int> actual = o.shortestAlternatingPaths(3, red_edges, blue_edges);
    vector<int> expected = { 0,1,-1 };
    check.checkIntVector(expected, actual);

    red_edges = { {0,1} };
    blue_edges = { {2,1} };
    actual = o.shortestAlternatingPaths(3, red_edges, blue_edges);
    expected = { 0,1,-1 };
    check.checkIntVector(expected, actual);

    red_edges = { {1,0} };
    blue_edges = { {2,1} };
    actual = o.shortestAlternatingPaths(3, red_edges, blue_edges);
    expected = { 0,-1,-1 };
    check.checkIntVector(expected, actual);

    red_edges = { {0,1} };
    blue_edges = { {1,2} };
    actual = o.shortestAlternatingPaths(3, red_edges, blue_edges);
    expected = { 0,1,2 };
    check.checkIntVector(expected, actual);

    red_edges = { {0,1},{0,2} };
    blue_edges = { {1,0} };
    actual = o.shortestAlternatingPaths(3, red_edges, blue_edges);
    expected = { 0,1,1 };
    check.checkIntVector(expected, actual);

    red_edges = { {{2,2},{0,4},{4,2},{4,3},{2,4},{0,0},{0,1},{2,3},{1,3}} };
    blue_edges = { {{0,4},{1,0},{1,4},{0,0},{4,0}} };
    actual = o.shortestAlternatingPaths(5, red_edges, blue_edges);
    expected = { 0,1,2,2,1 };
    check.checkIntVector(expected, actual);

    red_edges = { {0,1},{1,2},{2,3},{3,4} };
    blue_edges = { {1,2},{2,3},{3,1} };
    actual = o.shortestAlternatingPaths(5, red_edges, blue_edges);
    expected = { 0,1,2,3,7 };
    check.checkIntVector(expected, actual);

    red_edges = {  };
    blue_edges = {  };
    actual = o.shortestAlternatingPaths(1, red_edges, blue_edges);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    red_edges = {  };
    blue_edges = {  };
    actual = o.shortestAlternatingPaths(3, red_edges, blue_edges);
    expected = { 0,-1,-1 };
    check.checkIntVector(expected, actual);
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
