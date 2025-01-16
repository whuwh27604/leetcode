/* 机器人可以获得的最大金币数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的网格。一个机器人从网格的左上角 (0, 0) 出发，目标是到达网格的右下角 (m - 1, n - 1)。在任意时刻，机器人只能向右或向下移动。

网格中的每个单元格包含一个值 coins[i][j]：

如果 coins[i][j] >= 0，机器人可以获得该单元格的金币。
如果 coins[i][j] < 0，机器人会遇到一个强盗，强盗会抢走该单元格数值的 绝对值 的金币。
机器人有一项特殊能力，可以在行程中 最多感化 2个单元格的强盗，从而防止这些单元格的金币被抢走。

注意：机器人的总金币数可以是负数。

返回机器人在路径上可以获得的 最大金币数 。



示例 1：

输入： coins = [[0,1,-1],[1,-2,3],[2,-3,4]]

输出： 8

解释：

一个获得最多金币的最优路径如下：

从 (0, 0) 出发，初始金币为 0（总金币 = 0）。
移动到 (0, 1)，获得 1 枚金币（总金币 = 0 + 1 = 1）。
移动到 (1, 1)，遇到强盗抢走 2 枚金币。机器人在此处使用一次感化能力，避免被抢（总金币 = 1）。
移动到 (1, 2)，获得 3 枚金币（总金币 = 1 + 3 = 4）。
移动到 (2, 2)，获得 4 枚金币（总金币 = 4 + 4 = 8）。
示例 2：

输入： coins = [[10,10,10],[10,10,10]]

输出： 40

解释：

一个获得最多金币的最优路径如下：

从 (0, 0) 出发，初始金币为 10（总金币 = 10）。
移动到 (0, 1)，获得 10 枚金币（总金币 = 10 + 10 = 20）。
移动到 (0, 2)，再获得 10 枚金币（总金币 = 20 + 10 = 30）。
移动到 (1, 2)，获得 10 枚金币（总金币 = 30 + 10 = 40）。


提示：

m == coins.length
n == coins[i].length
1 <= m, n <= 500
-1000 <= coins[i][j] <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int row = (int)coins.size(), column = (int)coins[0].size(), inf = INT_MIN / 2;
        vector<vector<int>> maxAmount0(row + 1, vector<int>(column + 1, inf)), maxAmount1(row + 1, vector<int>(column + 1, inf)), maxAmount2(row + 1, vector<int>(column + 1, inf));
        maxAmount0[row - 1][column] = maxAmount1[row - 1][column] = maxAmount2[row - 1][column] = 0;
        maxAmount0[row][column - 1] = maxAmount1[row][column - 1] = maxAmount2[row][column - 1] = 0;

        for (int r = row - 1; r >= 0; --r) {
            for (int c = column - 1; c >= 0; --c) {
                maxAmount0[r][c] = max(maxAmount0[r][c + 1], maxAmount0[r + 1][c]) + coins[r][c];
                maxAmount1[r][c] = max(maxAmount1[r][c + 1], maxAmount1[r + 1][c]) + coins[r][c];
                maxAmount2[r][c] = max(maxAmount2[r][c + 1], maxAmount2[r + 1][c]) + coins[r][c];

                if (coins[r][c] < 0) {
                    maxAmount1[r][c] = max(maxAmount1[r][c], maxAmount0[r + 1][c]);
                    maxAmount1[r][c] = max(maxAmount1[r][c], maxAmount0[r][c + 1]);
                    maxAmount2[r][c] = max(maxAmount2[r][c], maxAmount1[r + 1][c]);
                    maxAmount2[r][c] = max(maxAmount2[r][c], maxAmount1[r][c + 1]);
                }
            }
        }

        return maxAmount2[0][0];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> coins = { {0,1,-1},{1,-2,3},{2,-3,4} };
    check.checkInt(8, o.maximumAmount(coins));

    coins = { {10,10,10},{10,10,10} };
    check.checkInt(40, o.maximumAmount(coins));

    coins = { {-7,12,12,13},{-6,19,19,-6},{9,-2,-10,16},{-4,14,-10,-9} };
    check.checkInt(60, o.maximumAmount(coins));
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
