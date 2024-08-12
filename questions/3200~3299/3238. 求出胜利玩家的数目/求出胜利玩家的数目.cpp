/* 求出胜利玩家的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n ，表示在一个游戏中的玩家数目。同时给你一个二维整数数组 pick ，其中 pick[i] = [xi, yi] 表示玩家 xi 获得了一个颜色为 yi 的球。

如果玩家 i 获得的球中任何一种颜色球的数目 严格大于 i 个，那么我们说玩家 i 是胜利玩家。换句话说：

如果玩家 0 获得了任何的球，那么玩家 0 是胜利玩家。
如果玩家 1 获得了至少 2 个相同颜色的球，那么玩家 1 是胜利玩家。
...
如果玩家 i 获得了至少 i + 1 个相同颜色的球，那么玩家 i 是胜利玩家。
请你返回游戏中 胜利玩家 的数目。

注意，可能有多个玩家是胜利玩家。



示例 1：

输入：n = 4, pick = [[0,0],[1,0],[1,0],[2,1],[2,1],[2,0]]

输出：2

解释：

玩家 0 和玩家 1 是胜利玩家，玩家 2 和玩家 3 不是胜利玩家。

示例 2：

输入：n = 5, pick = [[1,1],[1,2],[1,3],[1,4]]

输出：0

解释：

没有胜利玩家。

示例 3：

输入：n = 5, pick = [[1,1],[2,4],[2,4],[2,4]]

输出：1

解释：

玩家 2 是胜利玩家，因为玩家 2 获得了 3 个颜色为 4 的球。



提示：

2 <= n <= 10
1 <= pick.length <= 100
pick[i].length == 2
0 <= xi <= n - 1
0 <= yi <= 10
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> count(n, vector<int>(11, 0));
        int winner = 0;

        for (auto& pk : pick) {
            ++count[pk[0]][pk[1]];
        }

        for (int i = 0; i < n; ++i) {
            for (int cnt : count[i]) {
                if (cnt > i) {
                    ++winner;
                    break;
                }
            }
        }

        return winner;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> pick = { {0,0},{1,0},{1,0},{2,1},{2,1},{2,0} };
    check.checkInt(2, o.winningPlayerCount(4, pick));

    pick = { {1,1},{1,2},{1,3},{1,4} };
    check.checkInt(0, o.winningPlayerCount(5, pick));

    pick = { {1,1},{2,4},{2,4},{2,4} };
    check.checkInt(1, o.winningPlayerCount(5, pick));
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
