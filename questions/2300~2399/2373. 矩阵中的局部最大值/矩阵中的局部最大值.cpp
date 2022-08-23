/* 矩阵中的局部最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 n x n 的整数矩阵 grid 。

生成一个大小为 (n - 2) x (n - 2) 的整数矩阵  maxLocal ，并满足：

maxLocal[i][j] 等于 grid 中以 i + 1 行和 j + 1 列为中心的 3 x 3 矩阵中的 最大值 。
换句话说，我们希望找出 grid 中每个 3 x 3 矩阵中的最大值。

返回生成的矩阵。

 

示例 1：



输入：grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
输出：[[9,9],[8,6]]
解释：原矩阵和生成的矩阵如上图所示。
注意，生成的矩阵中，每个值都对应 grid 中一个相接的 3 x 3 矩阵的最大值。
示例 2：



输入：grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
输出：[[2,2,2],[2,2,2],[2,2,2]]
解释：注意，2 包含在 grid 中每个 3 x 3 的矩阵中。
 

提示：

n == grid.length == grid[i].length
3 <= n <= 100
1 <= grid[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/largest-local-values-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));

        for (int r = 1; r < n - 1; ++r) {
            for (int c = 1; c < n - 1; ++c) {
                ans[r - 1][c - 1] = max({ grid[r - 1][c - 1],grid[r - 1][c],grid[r - 1][c + 1],grid[r][c - 1],grid[r][c],grid[r][c + 1],grid[r + 1][c - 1],grid[r + 1][c],grid[r + 1][c + 1] });
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2} };
    vector<vector<int>> actual = o.largestLocal(grid);
    vector<vector<int>> expected = { {9,9},{8,6} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1,1,1,1,1},{1,1,1,1,1},{1,1,2,1,1},{1,1,1,1,1},{1,1,1,1,1} };
    actual = o.largestLocal(grid);
    expected = { {2,2,2},{2,2,2},{2,2,2} };
    check.checkIntVectorVector(expected, actual);
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
