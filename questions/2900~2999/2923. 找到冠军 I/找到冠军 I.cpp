/* 找到冠军 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一场比赛中共有 n 支队伍，按从 0 到  n - 1 编号。

给你一个下标从 0 开始、大小为 n * n 的二维布尔矩阵 grid 。对于满足 0 <= i, j <= n - 1 且 i != j 的所有 i, j ：如果 grid[i][j] == 1，那么 i 队比 j 队 强 ；否则，j 队比 i 队 强 。

在这场比赛中，如果不存在某支强于 a 队的队伍，则认为 a 队将会是 冠军 。

返回这场比赛中将会成为冠军的队伍。



示例 1：

输入：grid = [[0,1],[0,0]]
输出：0
解释：比赛中有两支队伍。
grid[0][1] == 1 表示 0 队比 1 队强。所以 0 队是冠军。
示例 2：

输入：grid = [[0,0,1],[1,0,1],[0,0,0]]
输出：1
解释：比赛中有三支队伍。
grid[1][0] == 1 表示 1 队比 0 队强。
grid[1][2] == 1 表示 1 队比 2 队强。
所以 1 队是冠军。


提示：

n == grid.length
n == grid[i].length
2 <= n <= 100
grid[i][j] 的值为 0 或 1
对于满足 i != j 的所有 i, j ，grid[i][j] != grid[j][i] 均成立
生成的输入满足：如果 a 队比 b 队强，b 队比 c 队强，那么 a 队比 c 队强
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size(), i = 0, j = 0;

        for (; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }

                if (grid[i][j] == 0) {
                    break;
                }
            }

            if (j == n) {
                break;
            }
        }

        return i;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = {{0,1},{0,0}};
    check.checkInt(0,o.findChampion(grid));

    grid = {{0,0,1},{1,0,1},{0,0,0}};
    check.checkInt(1, o.findChampion(grid));
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
