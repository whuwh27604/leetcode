/* 摘樱桃.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个N x N的网格(grid) 代表了一块樱桃地，每个格子由以下三种数字的一种来表示：

0 表示这个格子是空的，所以你可以穿过它。
1 表示这个格子里装着一个樱桃，你可以摘到樱桃然后穿过它。
-1 表示这个格子里有荆棘，挡着你的路。
你的任务是在遵守下列规则的情况下，尽可能的摘到最多樱桃：

从位置 (0, 0) 出发，最后到达 (N-1, N-1) ，只能向下或向右走，并且只能穿越有效的格子（即只可以穿过值为0或者1的格子）；
当到达 (N-1, N-1) 后，你要继续走，直到返回到 (0, 0) ，只能向上或向左走，并且只能穿越有效的格子；
当你经过一个格子且这个格子包含一个樱桃时，你将摘到樱桃并且这个格子会变成空的（值变为0）；
如果在 (0, 0) 和 (N-1, N-1) 之间不存在一条可经过的路径，则没有任何一个樱桃能被摘到。
示例 1:

输入: grid =
[[0, 1, -1],
 [1, 0, -1],
 [1, 1,  1]]
输出: 5
解释：
玩家从（0,0）点出发，经过了向下走，向下走，向右走，向右走，到达了点(2, 2)。
在这趟单程中，总共摘到了4颗樱桃，矩阵变成了[[0,1,-1],[0,0,-1],[0,0,0]]。
接着，这名玩家向左走，向上走，向上走，向左走，返回了起始点，又摘到了1颗樱桃。
在旅程中，总共摘到了5颗樱桃，这是可以摘到的最大值了。
说明:

grid 是一个 N * N 的二维数组，N的取值范围是1 <= N <= 50。
每一个 grid[i][j] 都是集合 {-1, 0, 1}其中的一个数。
可以保证起点 grid[0][0] 和终点 grid[N-1][N-1] 的值都不会是 -1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cherry-pickup
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r1, r2, c1, c2, n = grid.size();
        vector<vector<vector<int>>> dp((n + n + 1), vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        dp[2][1][1] = grid[0][0];

        for (int sum = 3; sum <= (n + n); ++sum) {
            for (r1 = min(sum - 1, n), c1 = sum - r1; r1 > 0 && c1 <= n; --r1, ++c1) {
                for (r2 = min(sum - 1, n), c2 = sum - r2; r2 > 0 && c2 <= n; --r2, ++c2) {
                    if (grid[r1 - 1][c1 - 1] == -1 || grid[r2 - 1][c2 - 1] == -1) {
                        dp[sum][r1][r2] = -1;
                    }
                    else {
                        dp[sum][r1][r2] = max({ dp[sum - 1][r1][r2], dp[sum - 1][r1][r2 - 1], dp[sum - 1][r1 - 1][r2], dp[sum - 1][r1 - 1][r2 - 1] });
                        if (dp[sum][r1][r2] != -1) {
                            dp[sum][r1][r2] += (grid[r1 - 1][c1 - 1] + (r1 == r2 ? 0 : grid[r2 - 1][c2 - 1]));
                        }
                    }
                }
            }
        }

        return dp[n + n][n][n] == -1 ? 0 : dp[n + n][n][n];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {0,1,-1},{1,0,-1},{1,1,1} };
    check.checkInt(5, o.cherryPickup(grid));

    grid = { {1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{1,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1} };
    check.checkInt(15, o.cherryPickup(grid));

    grid = { {1} };
    check.checkInt(1, o.cherryPickup(grid));

    grid = { {0} };
    check.checkInt(0, o.cherryPickup(grid));

    grid = { {1,-1},{-1,1} };
    check.checkInt(0, o.cherryPickup(grid));

    grid = { {1,1,1,0,0},{0,0,1,0,1},{1,0,1,0,0},{0,0,1,0,0},{0,0,1,1,1} };
    check.checkInt(11, o.cherryPickup(grid));
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
