/* 网格游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维数组 grid ，数组大小为 2 x n ，其中 grid[r][c] 表示矩阵中 (r, c) 位置上的点数。现在有两个机器人正在矩阵上参与一场游戏。

两个机器人初始位置都是 (0, 0) ，目标位置是 (1, n-1) 。每个机器人只会 向右 ((r, c) 到 (r, c + 1)) 或 向下 ((r, c) 到 (r + 1, c)) 。

游戏开始，第一个 机器人从 (0, 0) 移动到 (1, n-1) ，并收集路径上单元格的全部点数。对于路径上所有单元格 (r, c) ，途经后 grid[r][c] 会重置为 0 。然后，第二个 机器人从 (0, 0) 移动到 (1, n-1) ，同样收集路径上单元的全部点数。注意，它们的路径可能会存在相交的部分。

第一个 机器人想要打击竞争对手，使 第二个 机器人收集到的点数 最小化 。与此相对，第二个 机器人想要 最大化 自己收集到的点数。两个机器人都发挥出自己的 最佳水平 的前提下，返回 第二个 机器人收集到的 点数 。

 

示例 1：



输入：grid = [[2,5,4],[1,5,1]]
输出：4
解释：第一个机器人的最佳路径如红色所示，第二个机器人的最佳路径如蓝色所示。
第一个机器人访问过的单元格将会重置为 0 。
第二个机器人将会收集到 0 + 0 + 4 + 0 = 4 个点。
示例 2：


输入：grid = [[3,3,1],[8,5,2]]
输出：4
解释：第一个机器人的最佳路径如红色所示，第二个机器人的最佳路径如蓝色所示。
第一个机器人访问过的单元格将会重置为 0 。
第二个机器人将会收集到 0 + 3 + 1 + 0 = 4 个点。
示例 3：


输入：grid = [[1,3,1,15],[1,3,3,1]]
输出：7
解释：第一个机器人的最佳路径如红色所示，第二个机器人的最佳路径如蓝色所示。
第一个机器人访问过的单元格将会重置为 0 。
第二个机器人将会收集到 0 + 1 + 3 + 3 + 0 = 7 个点。
 

提示：

grid.length == 2
n == grid[r].length
1 <= n <= 5 * 104
1 <= grid[r][c] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/grid-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        /* 1、此题的目标是让乙的分数最小，所以甲的最优策略并不是自己先获取一个最大分数。
           2、从乙的角度考虑，我们发现其实甲拿完以后，乙只有两个选择：要么横向走到底，再往下走；要么第一步往下走，再横向走到底
           3、发现这个结论就好办了，遍历甲每一个向下的位置，同时求乙的分数，取最小值即可 */
        int i, size = grid[0].size();
        vector<long long> presum0(size, 0), presum1(size, 0);

        getPresum(grid, presum0, presum1);
        long long minSum = presum0[size - 1] - grid[0][0];

        for (i = 1; i < size; ++i) {
            minSum = min(minSum, max(presum0[size - 1] - presum0[i], presum1[i - 1]));
        }

        return minSum;
    }

    void getPresum(vector<vector<int>>& grid, vector<long long>& presum0, vector<long long>& presum1) {
        int i, size = grid[0].size();

        presum0[0] = grid[0][0];
        presum1[0] = grid[1][0];

        for (i = 1; i < size; ++i) {
            presum0[i] = presum0[i - 1] + grid[0][i];
            presum1[i] = presum1[i - 1] + grid[1][i];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {2,5,4},{1,5,1} };
    check.checkLongLong(4, o.gridGame(grid));

    grid = { {3,3,1},{8,5,2} };
    check.checkLongLong(4, o.gridGame(grid));

    grid = { {1,3,1,15},{1,3,3,1} };
    check.checkLongLong(7, o.gridGame(grid));

    grid = { {1},{1} };
    check.checkLongLong(0, o.gridGame(grid));

    grid = { {20,3,20,17,2,12,15,17,4,15},{20,10,13,14,15,5,2,3,14,3} };
    check.checkLongLong(63, o.gridGame(grid));
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
