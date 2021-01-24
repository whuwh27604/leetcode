/* 球会落何处.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
用一个大小为 m x n 的二维网格 grid 表示一个箱子。你有 n 颗球。箱子的顶部和底部都是开着的。

箱子中的每个单元格都有一个对角线挡板，跨过单元格的两个角，可以将球导向左侧或者右侧。

将球导向右侧的挡板跨过左上角和右下角，在网格中用 1 表示。
将球导向左侧的挡板跨过右上角和左下角，在网格中用 -1 表示。
在箱子每一列的顶端各放一颗球。每颗球都可能卡在箱子里或从底部掉出来。如果球恰好卡在两块挡板之间的 "V" 形图案，或者被一块挡导向到箱子的任意一侧边上，就会卡住。

返回一个大小为 n 的数组 answer ，其中 answer[i] 是球放在顶部的第 i 列后从底部掉出来的那一列对应的下标，如果球卡在盒子里，则返回 -1 。

 

示例 1：



输入：grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
输出：[1,-1,-1,-1,-1]
解释：示例如图：
b0 球开始放在第 0 列上，最终从箱子底部第 1 列掉出。
b1 球开始放在第 1 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
b2 球开始放在第 2 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b3 球开始放在第 3 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b4 球开始放在第 4 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
示例 2：

输入：grid = [[-1]]
输出：[-1]
解释：球被卡在箱子左侧边上。
示例 3：

输入：grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
输出：[0,1,2,3,4,-1]
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] 为 1 或 -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/where-will-the-ball-fall
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int i, column = grid[0].size();
        vector<int> ballPositions(column);

        for (i = 0; i < column; ++i) {
            ballPositions[i] = findEachBall(grid, i);
        }

        return ballPositions;
    }

    int findEachBall(vector<vector<int>>& grid, int c) {
        int row = grid.size(), column = grid[0].size(), r = 0, dir = 0;

        while (r < row) {
            if (c < 0 || c >= column) {
                return -1;
            }

            if (dir == 0) {  // down
                if (grid[r][c] == 1) {
                    ++c;
                    dir = 1;
                }
                else {
                    --c;
                    dir = 2;
                }
            }
            else if (dir == 1) {  // right
                if (grid[r][c] == 1) {
                    ++r;
                    dir = 0;
                }
                else {
                    return -1;
                }
            }
            else {  // left
                if (grid[r][c] == 1) {
                    return -1;
                }
                else {
                    ++r;
                    dir = 0;
                }
            }
        }

        return c;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,-1,-1,-1},{1,-1,-1,1},{-1,1,1,1},{1,1,-1,1},{1,1,1,1} };
    vector<int> actual = o.findBall(grid);
    vector<int> expected = { -1,-1,-1,-1 };
    check.checkIntVector(expected, actual);

    grid = { {1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1} };
    actual = o.findBall(grid);
    expected = { 1,-1,-1,-1,-1 };
    check.checkIntVector(expected, actual);

    grid = { {-1} };
    actual = o.findBall(grid);
    expected = { -1 };
    check.checkIntVector(expected, actual);

    grid = { {1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1} };
    actual = o.findBall(grid);
    expected = { 0,1,2,3,4,-1 };
    check.checkIntVector(expected, actual);
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
