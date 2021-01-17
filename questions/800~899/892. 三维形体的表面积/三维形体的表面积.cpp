/* 三维形体的表面积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。

每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。

请你返回最终形体的表面积。

 

示例 1：

输入：[[2]]
输出：10
示例 2：

输入：[[1,2],[3,4]]
输出：34
示例 3：

输入：[[1,0],[0,2]]
输出：16
示例 4：

输入：[[1,1,1],[1,0,1],[1,1,1]]
输出：32
示例 5：

输入：[[2,2,2],[2,1,2],[2,2,2]]
输出：46
 

提示：

1 <= N <= 50
0 <= grid[i][j] <= 50

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surface-area-of-3d-shapes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int i, j, N = grid.size(), area = 0;

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                int height = grid[i][j];
                if (height == 0) {
                    continue;
                }

                int left = (j == 0) ? 0 : grid[i][j - 1];
                left = (left >= height) ? 0 : (height - left);
                int right = (j == N - 1) ? 0 : grid[i][j + 1];
                right = (right >= height) ? 0 : (height - right);
                int front = (i == 0) ? 0 : grid[i - 1][j];
                front = (front >= height) ? 0 : (height - front);
                int back = (i == N - 1) ? 0 : grid[i + 1][j];
                back = (back >= height) ? 0 : (height - back);
                area += (left + right + front + back + 2);
            }
        }

        return area;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {2} };
    check.checkInt(10, o.surfaceArea(grid));

    grid = { {1,2},{3,4} };
    check.checkInt(34, o.surfaceArea(grid));

    grid = { {1,0},{0,2} };
    check.checkInt(16, o.surfaceArea(grid));

    grid = { {1,1,1},{1,0,1},{1,1,1} };
    check.checkInt(32, o.surfaceArea(grid));

    grid = { {2,2,2},{2,1,2},{2,2,2} };
    check.checkInt(46, o.surfaceArea(grid));
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
