/* 不同路径 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？



网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }

        // 由于只能向下或向右移动，dp[i][j]=dp[i-1][j]+dp[i][j-1]
        int i, j, m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dpPrevRow(n, 0);
        dpPrevRow[0] = (obstacleGrid[0][0] == 1) ? 0 : 1;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dpPrevRow[j] = 0;
                }
                else {
                    if (j != 0) {
                        dpPrevRow[j] += dpPrevRow[j - 1];
                    }
                }
            }
        }

        return dpPrevRow[n - 1];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> obstacleGrid = {};
    check.checkInt(0, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {} };
    check.checkInt(0, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0} };
    check.checkInt(1, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0,0,0} };
    check.checkInt(1, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0},{0},{0} };
    check.checkInt(1, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0,0},{0,0} };
    check.checkInt(2, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0,0,0},{0,0,0},{0,0,0} };
    check.checkInt(6, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0,0,0},{0,1,0},{0,0,0} };
    check.checkInt(2, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {1,0,0},{0,0,0},{0,0,0} };
    check.checkInt(0, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0,0,0},{0,0,0},{0,0,1} };
    check.checkInt(0, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0,1,0},{1,0,0},{0,0,0} };
    check.checkInt(0, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0,1,0},{0,0,0},{0,0,0} };
    check.checkInt(3, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0,0,1},{0,0,0},{0,0,0} };
    check.checkInt(5, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0,0,0,0},{0,0,0,0},{0,0,0,0} };
    check.checkInt(10, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0,0,0,1},{0,0,0,0},{0,0,0,0} };
    check.checkInt(9, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0,0,0,0},{0,0,1,0},{0,0,0,0} };
    check.checkInt(4, o.uniquePathsWithObstacles(obstacleGrid));

    obstacleGrid = { {0,0,0,0},{0,0,0,0},{0,1,0,0} };
    check.checkInt(7, o.uniquePathsWithObstacles(obstacleGrid));
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
