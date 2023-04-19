/* 查询网格图中每一列的宽度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的 m x n 整数矩阵 grid 。矩阵中某一列的宽度是这一列数字的最大 字符串长度 。

比方说，如果 grid = [[-10], [3], [12]] ，那么唯一一列的宽度是 3 ，因为 -10 的字符串长度为 3 。
请你返回一个大小为 n 的整数数组 ans ，其中 ans[i] 是第 i 列的宽度。

一个有 len 个数位的整数 x ，如果是非负数，那么 字符串长度 为 len ，否则为 len + 1 。



示例 1：

输入：grid = [[1],[22],[333]]
输出：[3]
解释：第 0 列中，333 字符串长度为 3 。
示例 2：

输入：grid = [[-15,1,3],[15,7,12],[5,6,-2]]
输出：[3,1,2]
解释：
第 0 列中，只有 -15 字符串长度为 3 。
第 1 列中，所有整数的字符串长度都是 1 。
第 2 列中，12 和 -2 的字符串长度都为 2 。


提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-109 <= grid[r][c] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        vector<int> widths(column, 0);

        for (int c = 0; c < column; ++c) {
            for (int r = 0; r < row; ++r) {
                widths[c] = max(widths[c], (int)to_string(grid[r][c]).size());
            }
        }

        return widths;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1},{22},{333} };
    vector<int> actual = o.findColumnWidth(grid);
    vector<int> expected = { 3 };
    check.checkIntVector(expected, actual);

    grid = { {-15,1,3},{15,7,12},{5,6,-2} };
    actual = o.findColumnWidth(grid);
    expected = { 3,1,2 };
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
