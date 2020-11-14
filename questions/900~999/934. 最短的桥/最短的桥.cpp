/* 最短的桥.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）

现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。

返回必须翻转的 0 的最小数目。（可以保证答案至少是 1。）

 

示例 1：

输入：[[0,1],[1,0]]
输出：1
示例 2：

输入：[[0,1,0],[0,0,0],[0,0,1]]
输出：2
示例 3：

输入：[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
输出：1
 

提示：

1 <= A.length = A[0].length <= 100
A[i][j] == 0 或 A[i][j] == 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-bridge
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        pair<int, int> land = findIsland(A);

        queue<pair<int, int>> allLands;
        DFS4AllLands(A, land, allLands);

        return BFS4AnotherIsland(A, allLands);
    }

    pair<int, int> findIsland(vector<vector<int>>& A) {
        int i, j, size = A.size();

        for (i = 0; i < size; ++i) {
            for (j = 0; j < size; ++j) {
                if (A[i][j] == 1) {
                    return { i, j };
                }
            }
        }

        return { 0, 0 };
    }

    void DFS4AllLands(vector<vector<int>>& A, pair<int, int>& land, queue<pair<int, int>>& allLands) {
        allLands.push(land);
        A[land.first][land.second] = -1;

        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        int size = A.size();

        for (int i = 0; i < 4; ++i) {
            int r = land.first + dr[i];
            int c = land.second + dc[i];

            if ((r >= 0) && (r < size) && (c >= 0) && (c < size) && (A[r][c] == 1)) {
                pair<int, int> nextLand = { r, c };
                DFS4AllLands(A, nextLand, allLands);
            }
        }
    }

    int BFS4AnotherIsland(vector<vector<int>>& A, queue<pair<int, int>>& bfs) {
        int bridgeLen = 0, size = A.size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        while (!bfs.empty()) {
            int len = bfs.size();

            for (int i = 0; i < len; ++i) {
                pair<int, int> land = bfs.front();
                bfs.pop();

                for (int j = 0; j < 4; ++j) {
                    int r = land.first + dr[j];
                    int c = land.second + dc[j];

                    if ((r < 0) || (r >= size) || (c < 0) || (c >= size)) {
                        continue;
                    }

                    if (A[r][c] == 1) {
                        return bridgeLen;
                    }

                    if (A[r][c] == 0) {
                        A[r][c] = -1;
                        bfs.push({ r,c });
                    }
                }
            }

            ++bridgeLen;
        }

        return bridgeLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> A = { {0,1},{1,0} };
    check.checkInt(1, o.shortestBridge(A));

    A = { {0,1,0},{0,0,0},{0,0,1} };
    check.checkInt(2, o.shortestBridge(A));

    A = { {1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1} };
    check.checkInt(1, o.shortestBridge(A));

    A = { {0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0}, };
    check.checkInt(17, o.shortestBridge(A));
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
