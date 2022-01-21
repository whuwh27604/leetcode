/* 粉刷房子 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个小城市里，有 m 个房子排成一排，你需要给每个房子涂上 n 种颜色之一（颜色编号为 1 到 n ）。有的房子去年夏天已经涂过颜色了，所以这些房子不需要被重新涂色。

我们将连续相同颜色尽可能多的房子称为一个街区。（比方说 houses = [1,2,2,3,3,2,1,1] ，它包含 5 个街区  [{1}, {2,2}, {3,3}, {2}, {1,1}] 。）

给你一个数组 houses ，一个 m * n 的矩阵 cost 和一个整数 target ，其中：

houses[i]：是第 i 个房子的颜色，0 表示这个房子还没有被涂色。
cost[i][j]：是将第 i 个房子涂成颜色 j+1 的花费。
请你返回房子涂色方案的最小总花费，使得每个房子都被涂色后，恰好组成 target 个街区。如果没有可用的涂色方案，请返回 -1 。

 

示例 1：

输入：houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
输出：9
解释：房子涂色方案为 [1,2,2,1,1]
此方案包含 target = 3 个街区，分别是 [{1}, {2,2}, {1,1}]。
涂色的总花费为 (1 + 1 + 1 + 1 + 5) = 9。
示例 2：

输入：houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
输出：11
解释：有的房子已经被涂色了，在此基础上涂色方案为 [2,2,1,2,2]
此方案包含 target = 3 个街区，分别是 [{2,2}, {1}, {2,2}]。
给第一个和最后一个房子涂色的花费为 (10 + 1) = 11。
示例 3：

输入：houses = [0,0,0,0,0], cost = [[1,10],[10,1],[1,10],[10,1],[1,10]], m = 5, n = 2, target = 5
输出：5
示例 4：

输入：houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
输出：-1
解释：房子已经被涂色并组成了 4 个街区，分别是 [{3},{1},{2},{3}] ，无法形成 target = 3 个街区。
 

提示：

m == houses.length == cost.length
n == cost[i].length
1 <= m <= 100
1 <= n <= 20
1 <= target <= m
0 <= houses[i] <= n
1 <= cost[i][j] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/paint-house-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int inf = 1000000000, ans = inf;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, inf)));  // 前[0,house]个房子，最后一个房子是颜色color，形成neighbor个街区的最小花费

        for (int house = 0; house < m; ++house) {
            for (int color = 0; color < n; ++color) {
                if (houses[house] != 0 && houses[house] != color + 1) {  // 期望最后一个房子是color颜色，但它已经被指定为其它颜色，那么花费是inf
                    continue;
                }

                for (int neighbor = 0; neighbor < target; ++neighbor) {
                    for (int prevColor = 0; prevColor < n; ++prevColor) {  // 枚举前一个房子的颜色
                        if (prevColor == color) {  // 和前一个房子颜色相同，那么街区数量不会增加
                            if (house == 0) {  // 第1个房子要特殊处理
                                if (neighbor == 0) {
                                    dp[house][color][neighbor] = 0;
                                }
                            }
                            else {
                                dp[house][color][neighbor] = min(dp[house][color][neighbor], dp[house - 1][color][neighbor]);
                            }
                        }
                        else {  // 和前一个房子颜色不同，街区数加1
                            if (house > 0 && neighbor > 0) {  // 不可能是第一个房子
                                dp[house][color][neighbor] = min(dp[house][color][neighbor], dp[house - 1][prevColor][neighbor - 1]);
                            }
                        }
                    }

                    if (dp[house][color][neighbor] != inf && houses[house] == 0) {  // 如果需要涂色，加上相应的花费
                        dp[house][color][neighbor] += cost[house][color];
                    }
                }
            }
        }

        for (int color = 0; color < n; ++color) {  // 检查最后一个房子涂哪种颜色花费最小
            ans = min(ans, dp[m - 1][color][target - 1]);
        }

        return ans == inf ? -1 : ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> houses = { 0,0,0,0,0 };
    vector<vector<int>> cost = { {1,10},{10,1},{10,1},{1,10},{5,1} };
    check.checkInt(9, o.minCost(houses, cost, 5, 2, 3));

    houses = { 0,2,1,2,0 };
    cost = { {1,10},{10,1},{10,1},{1,10},{5,1} };
    check.checkInt(11, o.minCost(houses, cost, 5, 2, 3));

    houses = { 0,0,0,0,0 };
    cost = { {1,10},{10,1},{1,10},{10,1},{1,10} };
    check.checkInt(5, o.minCost(houses, cost, 5, 2, 5));

    houses = { 3,1,2,3 };
    cost = { {1,1,1},{1,1,1},{1,1,1},{1,1,1} };
    check.checkInt(-1, o.minCost(houses, cost, 4, 4, 3));
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
