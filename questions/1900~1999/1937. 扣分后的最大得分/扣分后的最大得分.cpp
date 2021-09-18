/* 扣分后的最大得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的整数矩阵 points （下标从 0 开始）。一开始你的得分为 0 ，你想最大化从矩阵中得到的分数。

你的得分方式为：每一行 中选取一个格子，选中坐标为 (r, c) 的格子会给你的总得分 增加 points[r][c] 。

然而，相邻行之间被选中的格子如果隔得太远，你会失去一些得分。对于相邻行 r 和 r + 1 （其中 0 <= r < m - 1），选中坐标为 (r, c1) 和 (r + 1, c2) 的格子，你的总得分 减少 abs(c1 - c2) 。

请你返回你能得到的 最大 得分。

abs(x) 定义为：

如果 x >= 0 ，那么值为 x 。
如果 x < 0 ，那么值为 -x 。
 

示例 1：


输入：points = [[1,2,3],[1,5,1],[3,1,1]]
输出：9
解释：
蓝色格子是最优方案选中的格子，坐标分别为 (0, 2)，(1, 1) 和 (2, 0) 。
你的总得分增加 3 + 5 + 3 = 11 。
但是你的总得分需要扣除 abs(2 - 1) + abs(1 - 0) = 2 。
你的最终得分为 11 - 2 = 9 。
示例 2：


输入：points = [[1,5],[2,3],[4,2]]
输出：11
解释：
蓝色格子是最优方案选中的格子，坐标分别为 (0, 1)，(1, 1) 和 (2, 0) 。
你的总得分增加 5 + 3 + 4 = 12 。
但是你的总得分需要扣除 abs(1 - 1) + abs(1 - 0) = 1 。
你的最终得分为 12 - 1 = 11 。
 

提示：

m == points.length
n == points[r].length
1 <= m, n <= 105
1 <= m * n <= 105
0 <= points[r][c] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-points-with-cost
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        /* 令dp[i][j]表示第i行选中数字points[i][j]可以获得的最大值，那么：
           dp[i+1][j] = max(points[i+1][j] + dp[i][j'] - |j - j'|), j'[0~column)
           dp[i+1][j] = max(points[i+1][j] - j + dp[i][j'] + j'), when j > j'
           dp[i+1][j] = max(points[i+1][j] + j + dp[i][j'] - j'), when j < j'
           所以，我们需要维护(dp[i][j'] + j')(j'[0,j])和(dp[i][j'] - j')(j'[j,column))的最大值 */
        int i, j, row = points.size(), column = points[0].size();
        vector<long long> dp(column), forward(column, 0), backword(column, 0);

        for (j = 0; j < column; ++j) {
            dp[j] = points[0][j];
        }

        for (i = 1; i < row; ++i) {
            forward[0] = dp[0];
            for (j = 1; j < column; ++j) {
                forward[j] = max(forward[j - 1], dp[j] + j);
            }

            backword[column - 1] = dp[column - 1] - column + 1;
            for (j = column - 2; j >= 0; --j) {
                backword[j] = max(backword[j + 1], dp[j] - j);
            }

            vector<long long> tmp(column);

            for (j = 0; j < column; ++j) {
                tmp[j] = max(forward[j] + points[i][j] - j, backword[j] + points[i][j] + j);
            }

            dp = tmp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> points = { {1,2,3},{1,5,1},{3,1,1} };
    check.checkLongLong(9, o.maxPoints(points));

    points = { {1,5},{2,3},{4,2} };
    check.checkLongLong(11, o.maxPoints(points));

    points = { {5} };
    check.checkLongLong(5, o.maxPoints(points));

    points = { {1,5,7} };
    check.checkLongLong(7, o.maxPoints(points));

    points = { {5},{3},{4} };
    check.checkLongLong(12, o.maxPoints(points));

    points = { {1,2,3,4,5,6,7,8,9},{9,8,7,6,5,4,3,2,1},{5,4,3,2,1,9,8,7,6},{5,6,7,8,9,4,3,2,1},{3,5,7,9,8,6,4,2,1} };
    check.checkLongLong(35, o.maxPoints(points));
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
