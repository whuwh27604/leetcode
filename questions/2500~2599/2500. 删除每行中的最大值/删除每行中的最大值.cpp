/* 删除每行中的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 大小的矩阵 grid ，由若干正整数组成。

执行下述操作，直到 grid 变为空矩阵：

从每一行删除值最大的元素。如果存在多个这样的值，删除其中任何一个。
将删除元素中的最大值与答案相加。
注意 每执行一次操作，矩阵中列的数据就会减 1 。

返回执行上述操作后的答案。



示例 1：



输入：grid = [[1,2,4],[3,3,1]]
输出：8
解释：上图展示在每一步中需要移除的值。
- 在第一步操作中，从第一行删除 4 ，从第二行删除 3（注意，有两个单元格中的值为 3 ，我们可以删除任一）。在答案上加 4 。
- 在第二步操作中，从第一行删除 2 ，从第二行删除 3 。在答案上加 3 。
- 在第三步操作中，从第一行删除 1 ，从第二行删除 1 。在答案上加 1 。
最终，答案 = 4 + 3 + 1 = 8 。
示例 2：



输入：grid = [[10]]
输出：10
解释：上图展示在每一步中需要移除的值。
- 在第一步操作中，从第一行删除 10 。在答案上加 10 。
最终，答案 = 10 。


提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 100
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), sum = 0;

        for (auto& row : grid) {
            sort(row.begin(), row.end());
        }

        for (int c = 0; c < n; ++c) {
            int num = 0;

            for (int r = 0; r < m; ++r) {
                num = max(num, grid[r][c]);
            }

            sum += num;
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,2,4},{3,3,1} };
    check.checkInt(8, o.deleteGreatestValue(grid));

    grid = { {10} };
    check.checkInt(10, o.deleteGreatestValue(grid));
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
