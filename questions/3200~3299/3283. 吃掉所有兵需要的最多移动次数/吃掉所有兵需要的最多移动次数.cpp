/* 吃掉所有兵需要的最多移动次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 50 x 50 的国际象棋棋盘，棋盘上有 一个 马和一些兵。给你两个整数 kx 和 ky ，其中 (kx, ky) 表示马所在的位置，同时还有一个二维数组 positions ，其中 positions[i] = [xi, yi] 表示第 i 个兵在棋盘上的位置。

Alice 和 Bob 玩一个回合制游戏，Alice 先手。玩家的一次操作中，可以执行以下操作：

玩家选择一个仍然在棋盘上的兵，然后移动马，通过 最少 的 步数 吃掉这个兵。注意 ，玩家可以选择 任意 一个兵，不一定 要选择从马的位置出发 最少 移动步数的兵。
在马吃兵的过程中，马 可能 会经过一些其他兵的位置，但这些兵 不会 被吃掉。只有 选中的兵在这个回合中被吃掉。
Alice 的目标是 最大化 两名玩家的 总 移动次数，直到棋盘上不再存在兵，而 Bob 的目标是 最小化 总移动次数。

假设两名玩家都采用 最优 策略，请你返回可以达到的 最大 总移动次数。

在一次 移动 中，如下图所示，马有 8 个可以移动到的位置，每个移动位置都是沿着坐标轴的一个方向前进 2 格，然后沿着垂直的方向前进 1 格。





示例 1：

输入：kx = 1, ky = 1, positions = [[0,0]]

输出：4

解释：



马需要移动 4 步吃掉 (0, 0) 处的兵。

示例 2：

输入：kx = 0, ky = 2, positions = [[1,1],[2,2],[3,3]]

输出：8

解释：



Alice 选择 (2, 2) 处的兵，移动马吃掉它需要 2 步：(0, 2) -> (1, 4) -> (2, 2) 。
Bob 选择 (3, 3) 处的兵，移动马吃掉它需要 2 步：(2, 2) -> (4, 1) -> (3, 3) 。
Alice 选择 (1, 1) 处的兵，移动马吃掉它需要 4 步：(3, 3) -> (4, 1) -> (2, 2) -> (0, 3) -> (1, 1) 。
示例 3：

输入：kx = 0, ky = 0, positions = [[1,2],[2,4]]

输出：3

解释：

Alice 选择 (2, 4) 处的兵，移动马吃掉它需要 2 步：(0, 0) -> (1, 2) -> (2, 4) 。注意，(1, 2) 处的兵不会被吃掉。
Bob 选择 (1, 2) 处的兵，移动马吃掉它需要 1 步：(2, 4) -> (1, 2) 。


提示：

0 <= kx, ky <= 49
1 <= positions.length <= 15
positions[i].length == 2
0 <= positions[i][0], positions[i][1] <= 49
positions[i] 两两互不相同。
输入保证对于所有 0 <= i < positions.length ，都有 positions[i] != [kx, ky] 。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = (int)positions.size(), maxMask = (1 << n), allMask = maxMask - 1, totalMoves = 0;
        vector<vector<int>> moves(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> minMoves(n, vector<int>(maxMask, inf)), maxMoves(n, vector<int>(maxMask, 0));

        getMoves(kx, ky, n, positions, moves);

        for (int i = 0, bit = 1; i < n; ++i, bit <<= 1) {
            totalMoves = max(totalMoves, moves[0][i + 1] + getMinMaxMoves(i, allMask ^ bit, 0, n, moves, minMoves, maxMoves));
        }

        return totalMoves;
    }

    int getMinMaxMoves(int current, int mask, int minmax, int n, vector<vector<int>>& moves, vector<vector<int>>& minMoves, vector<vector<int>>& maxMoves) {
        if (mask == 0) {
            return 0;
        }

        if (minmax == 0 && minMoves[current][mask] != inf) {
            return minMoves[current][mask];
        }

        if ((minmax == 1 && maxMoves[current][mask] != 0)) {
            return maxMoves[current][mask];
        }

        int& curMoves = (minmax == 0 ? minMoves[current][mask] : maxMoves[current][mask]);

        for (int next = 0, bit = 1; next < n; ++next, bit <<= 1) {
            if ((mask & bit) != 0) {
                if (minmax == 0) {
                    curMoves = min(curMoves, moves[current + 1][next + 1] + getMinMaxMoves(next, mask ^ bit, minmax ^ 1, n, moves, minMoves, maxMoves));
                }
                else {
                    curMoves = max(curMoves, moves[current + 1][next + 1] + getMinMaxMoves(next, mask ^ bit, minmax ^ 1, n, moves, minMoves, maxMoves));
                }
            }
        }

        return curMoves;
    }

    void getMoves(int kx, int ky, int n, vector<vector<int>>& positions, vector<vector<int>>& moves) {
        for (int i = 0; i < n; ++i) {
            moves[0][i + 1] = getMoves(kx, ky, positions[i][0], positions[i][1]);

            for (int j = i + 1; j < n; ++j) {
                moves[i + 1][j + 1] = getMoves(positions[i][0], positions[i][1], positions[j][0], positions[j][1]);
                moves[j + 1][i + 1] = moves[i + 1][j + 1];
            }
        }
    }

    int getMoves(int x0, int y0, int x1, int y1) {
        int moves = 0;
        int dx[8] = { 1,2,2,1,-1,-2,-2,-1 }, dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
        queue<pair<int, int>> nodes;
        nodes.push({ x0,y0 });
        vector<vector<bool>> visited(len, vector<bool>(len, false));
        visited[x0][y0] = true;

        while (!nodes.empty()) {
            int size = (int)nodes.size();
            ++moves;

            for (int i = 0; i < size; ++i) {
                int x = nodes.front().first, y = nodes.front().second;
                nodes.pop();

                for (int j = 0; j < 8; ++j) {
                    int nx = x + dx[j], ny = y + dy[j];
                    if (nx == x1 && ny == y1) {
                        return moves;
                    }

                    if (nx >= 0 && nx < len && ny >= 0 && ny < len && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        nodes.push({ nx,ny });
                    }
                }
            }
        }

        return moves;
    }

    int len = 50;
    int inf = INT_MAX / 2;
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> positions = { {0,0} };
    check.checkInt(4, o.maxMoves(1, 1, positions));

    positions = { {1,1},{2,2},{3,3} };
    check.checkInt(8, o.maxMoves(0, 2, positions));

    positions = { {1,2},{2,4} };
    check.checkInt(3, o.maxMoves(0, 0, positions));

    positions = { {1,1},{2,3},{4,5},{6,8},{8,11},{12,13},{15,24},{18,20},{15,17},{16,13},{19,11},{20,9},{22,7},{23,4},{24,0} };
    check.checkInt(90, o.maxMoves(13, 12, positions));
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
