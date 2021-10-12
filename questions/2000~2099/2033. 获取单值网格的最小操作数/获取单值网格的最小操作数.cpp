/* 获取单值网格的最小操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 m x n 的二维整数网格 grid 和一个整数 x 。每一次操作，你可以对 grid 中的任一元素 加 x 或 减 x 。

单值网格 是全部元素都相等的网格。

返回使网格化为单值网格所需的 最小 操作数。如果不能，返回 -1 。

 

示例 1：



输入：grid = [[2,4],[6,8]], x = 2
输出：4
解释：可以执行下述操作使所有元素都等于 4 ：
- 2 加 x 一次。
- 6 减 x 一次。
- 8 减 x 两次。
共计 4 次操作。
示例 2：



输入：grid = [[1,5],[2,3]], x = 1
输出：5
解释：可以使所有元素都等于 3 。
示例 3：



输入：grid = [[1,2],[3,4]], x = 2
输出：-1
解释：无法使所有元素相等。
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 105
1 <= m * n <= 105
1 <= x, grid[i][j] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-operations-to-make-a-uni-value-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int i, j, row = grid.size(), column = grid[0].size(), size = row * column, num = grid[0][0], index = 0;
        vector<int> nums(size);

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (((grid[i][j] - num) % x) != 0) {
                    return -1;
                }

                nums[index++] = grid[i][j];
            }
        }

        sort(nums.begin(), nums.end());
        int median = nums[size / 2], opers = 0;

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                opers += abs(grid[i][j] - median) / x;
            }
        }

        return opers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {2,4},{6,8} };
    check.checkInt(4, o.minOperations(grid, 2));

    grid = { {1,5},{2,3} };
    check.checkInt(5, o.minOperations(grid, 1));

    grid = { {1,2},{3,4} };
    check.checkInt(-1, o.minOperations(grid, 2));

    grid = { {4} };
    check.checkInt(0, o.minOperations(grid, 5));
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
