/* 二维网格迁移.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m 行 n 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。

每次「迁移」操作将会引发下述活动：

位于 grid[i][j] 的元素将会移动到 grid[i][j + 1]。
位于 grid[i][n - 1] 的元素将会移动到 grid[i + 1][0]。
位于 grid[m - 1][n - 1] 的元素将会移动到 grid[0][0]。
请你返回 k 次迁移操作后最终得到的 二维网格。

 

示例 1：



输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
输出：[[9,1,2],[3,4,5],[6,7,8]]
示例 2：



输入：grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
输出：[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
示例 3：

输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
输出：[[1,2,3],[4,5,6],[7,8,9]]
 

提示：

1 <= grid.length <= 50
1 <= grid[i].length <= 50
-1000 <= grid[i][j] <= 1000
0 <= k <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shift-2d-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        /* 移动k次，水平方向第c列移动到c --> (c + k % n) % n
           移动k次，垂直方向移动的次数x = (k / n)，如果(k % n) + c >= n 则 x+1
           所以垂直方向第r列移动到r --> (r + x % m) % m */
        int r, c, x, m = grid.size(), n = grid[0].size();
        vector<vector<int>> shifted(m, vector<int>(n, 0));

        for (r = 0; r < m; r++) {
            for (c = 0; c < n; c++) {
                x = k / n;
                if ((k % n) + c >= n) {
                    x++;
                }
                shifted[(r + x % m) % m][(c + k % n) % n] = grid[r][c];
            }
        }

        return shifted;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {1,2,3},{4,5,6},{7,8,9} };
    vector<vector<int>> actual = o.shiftGrid(grid, 1);
    vector<vector<int>> expected = { {9,1,2},{3,4,5},{6,7,8} };
    check.checkIntDoubleVector(expected, actual);

    grid = { {3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13} };
    actual = o.shiftGrid(grid, 4);
    expected = { {12,0,21,13},{3,8,1,9},{19,7,2,5},{4,6,11,10} };
    check.checkIntDoubleVector(expected, actual);

    grid = { {1,2,3},{4,5,6},{7,8,9} };
    actual = o.shiftGrid(grid, 9);
    expected = { {1,2,3},{4,5,6},{7,8,9} };
    check.checkIntDoubleVector(expected, actual);

    grid = { {12} };
    actual = o.shiftGrid(grid, 9);
    expected = { {12} };
    check.checkIntDoubleVector(expected, actual);

    grid = { {1,2,3} };
    actual = o.shiftGrid(grid, 5);
    expected = { {2,3,1} };
    check.checkIntDoubleVector(expected, actual);

    grid = { {1},{2},{3} };
    actual = o.shiftGrid(grid, 5);
    expected = { {2},{3},{1} };
    check.checkIntDoubleVector(expected, actual);
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
