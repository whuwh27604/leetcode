/* 矩阵中和能被 K 整除的路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的 m x n 整数矩阵 grid 和一个整数 k 。你从起点 (0, 0) 出发，每一步只能往 下 或者往 右 ，你想要到达终点 (m - 1, n - 1) 。

请你返回路径和能被 k 整除的路径数目，由于答案可能很大，返回答案对 109 + 7 取余 的结果。

 

示例 1：



输入：grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
输出：2
解释：有两条路径满足路径上元素的和能被 k 整除。
第一条路径为上图中用红色标注的路径，和为 5 + 2 + 4 + 5 + 2 = 18 ，能被 3 整除。
第二条路径为上图中用蓝色标注的路径，和为 5 + 3 + 0 + 5 + 2 = 15 ，能被 3 整除。
示例 2：


输入：grid = [[0,0]], k = 5
输出：1
解释：红色标注的路径和为 0 + 0 = 0 ，能被 5 整除。
示例 3：


输入：grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
输出：10
解释：每个数字都能被 1 整除，所以每一条路径的和都能被 k 整除。
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 5 * 104
1 <= m * n <= 5 * 104
0 <= grid[i][j] <= 100
1 <= k <= 50

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int row = grid.size(), column = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(column, vector<int>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                for (int i = 0; i < k; ++i) {
                    int j = (i + k - grid[r][c] % k) % k;

                    if (r != 0) {
                        dp[r][c][i] = dp[r - 1][c][j];
                    }

                    if (c != 0) {
                        dp[r][c][i] = (dp[r][c][i] + dp[r][c - 1][j]) % 1000000007;
                    }
                }
            }
        }

        return dp[row - 1][column - 1][0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {5,2,4},{3,0,5},{0,7,2} };
    check.checkInt(2, o.numberOfPaths(grid, 3));

    grid = { {0,0} };
    check.checkInt(1, o.numberOfPaths(grid, 5));

    grid = { {7,3,4,9},{2,3,6,2},{2,3,7,0} };
    check.checkInt(10, o.numberOfPaths(grid, 1));
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
