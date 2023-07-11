/* 黑格子的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 m 和 n ，表示一个下标从 0 开始的 m x n 的网格图。

给你一个下标从 0 开始的二维整数矩阵 coordinates ，其中 coordinates[i] = [x, y] 表示坐标为 [x, y] 的格子是 黑色的 ，所有没出现在 coordinates 中的格子都是 白色的。

一个块定义为网格图中 2 x 2 的一个子矩阵。更正式的，对于左上角格子为 [x, y] 的块，其中 0 <= x < m - 1 且 0 <= y < n - 1 ，包含坐标为 [x, y] ，[x + 1, y] ，[x, y + 1] 和 [x + 1, y + 1] 的格子。

请你返回一个下标从 0 开始长度为 5 的整数数组 arr ，arr[i] 表示恰好包含 i 个 黑色 格子的块的数目。



示例 1：

输入：m = 3, n = 3, coordinates = [[0,0]]
输出：[3,1,0,0,0]
解释：网格图如下：

只有 1 个块有一个黑色格子，这个块是左上角为 [0,0] 的块。
其他 3 个左上角分别为 [0,1] ，[1,0] 和 [1,1] 的块都有 0 个黑格子。
所以我们返回 [3,1,0,0,0] 。
示例 2：

输入：m = 3, n = 3, coordinates = [[0,0],[1,1],[0,2]]
输出：[0,2,2,0,0]
解释：网格图如下：

有 2 个块有 2 个黑色格子（左上角格子分别为 [0,0] 和 [0,1]）。
左上角为 [1,0] 和 [1,1] 的两个块，都有 1 个黑格子。
所以我们返回 [0,2,2,0,0] 。


提示：

2 <= m <= 105
2 <= n <= 105
0 <= coordinates.length <= 104
coordinates[i].length == 2
0 <= coordinates[i][0] < m
0 <= coordinates[i][1] < n
coordinates 中的坐标对两两互不相同。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<long long, int> blocks;
        vector<long long> ans = { ((long long)m - 1) * ((long long)n - 1),0,0,0,0 };

        for (auto& coordinate : coordinates) {
            int x = coordinate[0], y = coordinate[1];

            if (x != 0 && y != 0) {
                ++blocks[(((long long)x - 1) << 32) | ((long long)y - 1)];
            }

            if (x != 0 && y != n - 1) {
                ++blocks[(((long long)x - 1) << 32) | y];
            }

            if (x != m - 1 && y != 0) {
                ++blocks[((long long)x << 32) | ((long long)y - 1)];
            }

            if (x != m - 1 && y != n - 1) {
                ++blocks[((long long)x << 32) | y];
            }
        }

        for (auto& block : blocks) {
            ++ans[block.second];
        }

        ans[0] -= (ans[1] + ans[2] + ans[3] + ans[4]);

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> coordinates = { {0,0} };
    vector<long long> actual = o.countBlackBlocks(3, 3, coordinates);
    vector<long long> expected = { 3,1,0,0,0 };
    check.checkLongLongVector(expected, actual);

    coordinates = { {0,0},{1,1},{0,2} };
    actual = o.countBlackBlocks(3, 3, coordinates);
    expected = { 0,2,2,0,0 };
    check.checkLongLongVector(expected, actual);
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
