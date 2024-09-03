/* 选择矩阵中单元格的最大得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由正整数构成的二维矩阵 grid。

你需要从矩阵中选择 一个或多个 单元格，选中的单元格应满足以下条件：

所选单元格中的任意两个单元格都不会处于矩阵的 同一行。
所选单元格的值 互不相同。
你的得分为所选单元格值的总和。

返回你能获得的 最大 得分。



示例 1：

输入： grid = [[1,2,3],[4,3,2],[1,1,1]]

输出： 8

解释：



选择上图中用彩色标记的单元格，对应的值分别为 1、3 和 4 。

示例 2：

输入： grid = [[8,7,6],[8,3,2]]

输出： 15

解释：



选择上图中用彩色标记的单元格，对应的值分别为 7 和 8 。



提示：

1 <= grid.length, grid[i].length <= 10
1 <= grid[i][j] <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int row = (int)grid.size(), column = (int)grid[0].size(), maxNum = 100;
        vector<int> indices(maxNum + 1, 0);
        vector<pair<int, int>> nums;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                indices[grid[r][c]] |= (1 << r);  // 记录每个数字在哪些行出现过
            }
        }

        for (int n = 1; n <= maxNum; ++n) {
            if (indices[n] != 0) {
                nums.push_back({ n,indices[n] });
            }
        }

        int size = (int)nums.size(), maxMask = (1 << row);
        vector<vector<int>> dp(size + 1, vector<int>(maxMask, 0));  // dp[i][chosen]表示已经选择的行为chosen，从nums[i, size)可选出的最大得分

        for (int i = size - 1; i >= 0; --i) {
            for (int chosen = 0; chosen < maxMask; ++chosen) {  // 枚举已经选择的行
                dp[i][chosen] = dp[i + 1][chosen];  // 不选当前num，那么得分等于数组下一个位置的得分

                for (int chosable = nums[i].second; chosable != 0; chosable &= (chosable - 1)) {  // 枚举当前数字选择哪一行
                    int lowbit = (chosable & -chosable);
                    if ((lowbit & chosen) == 0) {  // 这一行还没有被选过，选上它
                        dp[i][chosen] = max(dp[i][chosen], nums[i].first + dp[i + 1][chosen | lowbit]);
                    }
                }
            }
        }

        return dp[0][0];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {1,2,3},{4,3,2},{1,1,1} };
    check.checkInt(8, o.maxScore(grid));

    grid = { {8,7,6},{8,3,2} };
    check.checkInt(15, o.maxScore(grid));

    grid = { {1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10} };
    check.checkInt(55, o.maxScore(grid));
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
