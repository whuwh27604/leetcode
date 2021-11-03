/* 接雨水 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。

 

示例：

给出如下 3x6 的高度图:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

返回 4 。


如上图所示，这是下雨前的高度图[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] 的状态。

 



下雨后，雨水将会被存储在这些方块中。总的接雨水量是4。

 

提示：

1 <= m, n <= 110
0 <= heightMap[i][j] <= 20000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int r;
    int c;
    int height;

    Node() : r(0), c(0), height(0) {}
    Node(int _r, int _c, int _height) : r(_r), c(_c), height(_height) {}

    bool operator<(const Node& node) const {
        return height > node.height;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int i, j, row = heightMap.size(), column = heightMap[0].size(), rainWater = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        priority_queue<Node> dijkstra;

        for (i = 0; i < row; ++i) {
            dijkstra.push(Node(i, 0, heightMap[i][0]));
            dijkstra.push(Node(i, column - 1, heightMap[i][column - 1]));
            visited[i][0] = visited[i][column - 1] = true;
        }

        for (j = 0; j < column; ++j) {
            dijkstra.push(Node(0, j, heightMap[0][j]));
            dijkstra.push(Node(row - 1, j, heightMap[row - 1][j]));
            visited[0][j] = visited[row - 1][j] = true;
        }

        while (!dijkstra.empty()) {
            int r = dijkstra.top().r, c = dijkstra.top().c, height = dijkstra.top().height;
            dijkstra.pop();

            for (i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < column && !visited[nr][nc]) {
                    if (height > heightMap[nr][nc]) {
                        rainWater += (height - heightMap[nr][nc]);
                    }

                    dijkstra.push(Node(nr, nc, max(height, heightMap[nr][nc])));
                    visited[nr][nc] = true;
                }
            }
        }

        return rainWater;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> heightMap = { {0,1,0},{1,0,1},{0,1,0} };
    check.checkInt(1, o.trapRainWater(heightMap));

    heightMap = { {1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1} };
    check.checkInt(4, o.trapRainWater(heightMap));

    heightMap = { {12,13,1,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13} };
    check.checkInt(14, o.trapRainWater(heightMap));

    heightMap = { {5,8,7,7},{5,2,1,5},{7,1,7,1},{8,9,6,9},{9,8,9,9} };
    check.checkInt(12, o.trapRainWater(heightMap));

    heightMap = { {5} };
    check.checkInt(0, o.trapRainWater(heightMap));

    heightMap = { {3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3} };
    check.checkInt(10, o.trapRainWater(heightMap));

    heightMap = { {1,0,0},{2,0,5},{1,0,3},{2,2,3},{2,2,0},{1,2,5},{3,2,2},{3,2,1},{3,0,4},{3,2,4},{3,0,2},{4,0,1},{3,1,0},{4,1,5} };
    check.checkInt(4, o.trapRainWater(heightMap));
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
