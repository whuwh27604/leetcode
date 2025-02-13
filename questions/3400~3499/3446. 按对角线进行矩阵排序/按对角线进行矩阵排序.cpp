/* 按对角线进行矩阵排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 n x n 的整数方阵 grid。返回一个经过如下调整的矩阵：

左下角三角形（包括中间对角线）的对角线按 非递增顺序 排序。
右上角三角形 的对角线按 非递减顺序 排序。


示例 1：

输入： grid = [[1,7,3],[9,8,2],[4,5,6]]

输出： [[8,2,3],[9,6,7],[4,5,1]]

解释：



标有黑色箭头的对角线（左下角三角形）应按非递增顺序排序：

[1, 8, 6] 变为 [8, 6, 1]。
[9, 5] 和 [4] 保持不变。
标有蓝色箭头的对角线（右上角三角形）应按非递减顺序排序：

[7, 2] 变为 [2, 7]。
[3] 保持不变。
示例 2：

输入： grid = [[0,1],[1,2]]

输出： [[2,1],[1,0]]

解释：



标有黑色箭头的对角线必须按非递增顺序排序，因此 [0, 2] 变为 [2, 0]。其他对角线已经符合要求。

示例 3：

输入： grid = [[1]]

输出： [[1]]

解释：

只有一个元素的对角线已经符合要求，因此无需修改。



提示：

grid.length == grid[i].length == n
1 <= n <= 10
-105 <= grid[i][j] <= 105
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = (int)grid.size();

        for (int R = 0, maxC = n; R < n; ++R, --maxC) {
            vector<int> tmp;

            for (int r = R, c = 0; c < maxC; ++r, ++c) {
                tmp.push_back(grid[r][c]);
            }

            sort(tmp.begin(), tmp.end(), greater<int>());

            for (int r = R, c = 0; c < maxC; ++r, ++c) {
                grid[r][c] = tmp[c];
            }
        }

        for (int C = n - 1, maxR = 1; C > 0; --C, ++maxR) {
            vector<int> tmp;

            for (int r = 0, c = C; r < maxR; ++r, ++c) {
                tmp.push_back(grid[r][c]);
            }

            sort(tmp.begin(), tmp.end());

            for (int r = 0, c = C; r < maxR; ++r, ++c) {
                grid[r][c] = tmp[r];
            }
        }

        return grid;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {1,7,3},{9,8,2},{4,5,6} };
    vector<vector<int>> actual = o.sortMatrix(grid);
    vector<vector<int>> expected = { {8,2,3},{9,6,7},{4,5,1} };
    check.checkIntVectorVector(expected, actual);

    grid = { {0,1},{1,2} };
    actual = o.sortMatrix(grid);
    expected = { {2,1},{1,0} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1} };
    actual = o.sortMatrix(grid);
    expected = { {1} };
    check.checkIntVectorVector(expected, actual);
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
