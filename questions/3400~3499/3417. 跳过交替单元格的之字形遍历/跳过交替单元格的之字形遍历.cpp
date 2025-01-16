/* 跳过交替单元格的之字形遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的二维数组 grid，数组由 正整数 组成。

你的任务是以 之字形 遍历 grid，同时跳过每个 交替 的单元格。

之字形遍历的定义如下：

从左上角的单元格 (0, 0) 开始。
在当前行中向 右 移动，直到到达该行的末尾。
下移到下一行，然后在该行中向 左 移动，直到到达该行的开头。
继续在行间交替向右和向左移动，直到所有行都被遍历完。
注意：在遍历过程中，必须跳过每个 交替 的单元格。

返回一个整数数组 result，其中包含按 顺序 记录的、且跳过交替单元格后的之字形遍历中访问到的单元格值。



示例 1：

输入： grid = [[1,2],[3,4]]

输出： [1,4]

解释：



示例 2：

输入： grid = [[2,1],[2,1],[2,1]]

输出： [2,1,2]

解释：



示例 3：

输入： grid = [[1,2,3],[4,5,6],[7,8,9]]

输出： [1,3,5,7,9]

解释：





提示：

2 <= n == grid.length <= 50
2 <= m == grid[i].length <= 50
1 <= grid[i][j] <= 2500
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int row = (int)grid.size(), column = (int)grid[0].size();
        int c = 0, dir = 0;
        vector<int> ans;

        for (int r = 0; r < row; ++r) {
            if (dir == 0) {
                while (c < column) {
                    ans.push_back(grid[r][c]);
                    c += 2;
                }

                c = (c == column ? column - 1 : column - 2);
            }
            else {
                while (c >= 0) {
                    ans.push_back(grid[r][c]);
                    c -= 2;
                }

                c = (c == -1 ? 0 : 1);
            }

            dir ^= 1;
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {1,2},{3,4} };
    vector<int> actual = o.zigzagTraversal(grid);
    vector<int> expected = { 1,4 };
    check.checkIntVector(expected, actual);

    grid = { {2,1},{2,1},{2,1} };
    actual = o.zigzagTraversal(grid);
    expected = { 2,1,2 };
    check.checkIntVector(expected, actual);

    grid = { {1,2,3},{4,5,6},{7,8,9} };
    actual = o.zigzagTraversal(grid);
    expected = { 1,3,5,7,9 };
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
