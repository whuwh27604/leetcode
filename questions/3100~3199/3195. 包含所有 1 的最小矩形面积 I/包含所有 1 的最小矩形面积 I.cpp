/* 包含所有 1 的最小矩形面积 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维 二进制 数组 grid。请你找出一个边在水平方向和竖直方向上、面积 最小 的矩形，并且满足 grid 中所有的 1 都在矩形的内部。

返回这个矩形可能的 最小 面积。



示例 1：

输入： grid = [[0,1,0],[1,0,1]]

输出： 6

解释：



这个最小矩形的高度为 2，宽度为 3，因此面积为 2 * 3 = 6。

示例 2：

输入： grid = [[0,0],[1,0]]

输出： 1

解释：



这个最小矩形的高度和宽度都是 1，因此面积为 1 * 1 = 1。



提示：

1 <= grid.length, grid[i].length <= 1000
grid[i][j] 是 0 或 1。
输入保证 grid 中至少有一个 1 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row = (int)grid.size(), column = (int)grid[0].size();
        int maxR = 0, maxC = 0, minR = INT_MAX, minC = INT_MAX;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                if (grid[r][c] == 1) {
                    maxR = max(maxR, r);
                    maxC = max(maxC, c);
                    minR = min(minR, r);
                    minC = min(minC, c);
                }
            }
        }

        return (maxR - minR + 1) * (maxC - minC + 1);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {0,1,0},{1,0,1} };
    check.checkInt(6, o.minimumArea(grid));

    grid = { {0,0},{1,0} };
    check.checkInt(1, o.minimumArea(grid));
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
