/* 沙漏的最大总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 m x n 的整数矩阵 grid 。

按以下形式将矩阵的一部分定义为一个 沙漏 ：


返回沙漏中元素的 最大 总和。

注意：沙漏无法旋转且必须整个包含在矩阵中。

 

示例 1：


输入：grid = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
输出：30
解释：上图中的单元格表示元素总和最大的沙漏：6 + 2 + 1 + 2 + 9 + 2 + 8 = 30 。
示例 2：


输入：grid = [[1,2,3],[4,5,6],[7,8,9]]
输出：35
解释：上图中的单元格表示元素总和最大的沙漏：1 + 2 + 3 + 5 + 7 + 8 + 9 = 35 。
 

提示：

m == grid.length
n == grid[i].length
3 <= m, n <= 150
0 <= grid[i][j] <= 106

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-sum-of-an-hourglass
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size(), mSum = 0;

        for (int r = 1; r < row - 1; ++r) {
            for (int c = 1; c < column - 1; ++c) {
                mSum = max(mSum, grid[r - 1][c - 1] + grid[r - 1][c] + grid[r - 1][c + 1] + grid[r][c] + grid[r + 1][c - 1] + grid[r + 1][c] + grid[r + 1][c + 1]);
            }
        }

        return mSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {6,2,1,3},{4,2,1,5},{9,2,8,7},{4,1,2,9} };
    check.checkInt(30, o.maxSum(grid));

    grid = { {1,2,3},{4,5,6},{7,8,9} };
    check.checkInt(35, o.maxSum(grid));
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
