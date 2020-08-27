/* 最小路径和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int i, j, row = grid.size(), column = grid[0].size();
        vector<int> dp(column, INT_MAX);
        dp[0] = 0;

        for (i = 0; i < row; i++) {
            dp[0] += grid[i][0];

            for (j = 1; j < column; j++) {
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }

        return dp[column - 1];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = {};
    check.checkInt(0, o.minPathSum(grid));

    grid = { {} };
    check.checkInt(0, o.minPathSum(grid));

    grid = { {3} };
    check.checkInt(3, o.minPathSum(grid));

    grid = { {1,3,5} };
    check.checkInt(9, o.minPathSum(grid));

    grid = { {1},{3},{5} };
    check.checkInt(9, o.minPathSum(grid));

    grid = { {1,3,1},{1,5,1},{4,2,1} };
    check.checkInt(7, o.minPathSum(grid));
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
