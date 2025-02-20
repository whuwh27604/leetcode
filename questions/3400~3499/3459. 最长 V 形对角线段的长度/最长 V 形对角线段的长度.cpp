/* 最长 V 形对角线段的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 n x m 的二维整数矩阵 grid，其中每个元素的值为 0、1 或 2。

V 形对角线段 定义如下：

线段从 1 开始。
后续元素按照以下无限序列的模式排列：2, 0, 2, 0, ...。
该线段：
起始于某个对角方向（左上到右下、右下到左上、右上到左下或左下到右上）。
沿着相同的对角方向继续，保持 序列模式 。
在保持 序列模式 的前提下，最多允许 一次顺时针 90 度转向 另一个对角方向。


返回最长的 V 形对角线段 的 长度 。如果不存在有效的线段，则返回 0。



示例 1：

输入： grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

输出： 5

解释：



最长的 V 形对角线段长度为 5，路径如下：(0,2) → (1,3) → (2,4)，在 (2,4) 处进行 顺时针 90 度转向 ，继续路径为 (3,3) → (4,2)。

示例 2：

输入： grid = [[2,2,2,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

输出： 4

解释：



最长的 V 形对角线段长度为 4，路径如下：(2,3) → (3,2)，在 (3,2) 处进行 顺时针 90 度转向 ，继续路径为 (2,1) → (1,0)。

示例 3：

输入： grid = [[1,2,2,2,2],[2,2,2,2,0],[2,0,0,0,0],[0,0,2,2,2],[2,0,0,2,0]]

输出： 5

解释：



最长的 V 形对角线段长度为 5，路径如下：(0,0) → (1,1) → (2,2) → (3,3) → (4,4)。

示例 4：

输入： grid = [[1]]

输出： 1

解释：

最长的 V 形对角线段长度为 1，路径如下：(0,0)。



提示：

n == grid.length
m == grid[i].length
1 <= n, m <= 500
grid[i][j] 的值为 0、1 或 2。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = (int)grid.size(), m = (int)grid[0].size();
        vector<vector<int>> maxLen0(n, vector<int>(m, 1)), maxLen1(n, vector<int>(m, 1)), maxLen2(n, vector<int>(m, 1)), maxLen3(n, vector<int>(m, 1));

        for (int r = 0; r < n; ++r) {
            vector<int> nums = getLine0(grid, n, m, r, 0);
            vector<int> maxLen = getMaxLen(nums, false);
            setLine0(maxLen, maxLen0, r, 0);
            maxLen = getMaxLen(nums, true);
            setLine0(maxLen, maxLen2, r, 0);
        }

        for (int c = 1; c < m; ++c) {
            vector<int> nums = getLine0(grid, n, m, n - 1, c);
            vector<int> maxLen = getMaxLen(nums, false);
            setLine0(maxLen, maxLen0, n - 1, c);
            maxLen = getMaxLen(nums, true);
            setLine0(maxLen, maxLen2, n - 1, c);
        }

        for (int c = m - 1; c >= 0; --c) {
            vector<int> nums = getLine1(grid, n, m, 0, c);
            vector<int> maxLen = getMaxLen(nums, false);
            setLine1(maxLen, maxLen1, 0, c);
            maxLen = getMaxLen(nums, true);
            setLine1(maxLen, maxLen3, 0, c);
        }

        for (int r = 1; r < n; ++r) {
            vector<int> nums = getLine1(grid, n, m, r, 0);
            vector<int> maxLen = getMaxLen(nums, false);
            setLine1(maxLen, maxLen1, r, 0);
            maxLen = getMaxLen(nums, true);
            setLine1(maxLen, maxLen3, r, 0);
        }

        return getMaxLen(grid, n, m, maxLen0, maxLen1, maxLen2, maxLen3);
    }

    vector<int> getLine0(vector<vector<int>>& grid, int row, int column, int r, int c) {
        vector<int> line;

        while (r >= 0 && c < column) {
            line.push_back(grid[r--][c++]);
        }

        return line;
    }

    void setLine0(vector<int>& line, vector<vector<int>>& grid, int r, int c) {
        for (int num : line) {
            grid[r--][c++] = num;
        }
    }

    vector<int> getLine1(vector<vector<int>>& grid, int row, int column, int r, int c) {
        vector<int> line;

        while (r < row && c < column) {
            line.push_back(grid[r++][c++]);
        }

        return line;
    }

    void setLine1(vector<int>& line, vector<vector<int>>& grid, int r, int c) {
        for (int num : line) {
            grid[r++][c++] = num;
        }
    }

    vector<int> getMaxLen(vector<int>& nums, bool rev) {  // 递推以grid[r][c]为起点，某个方向上的最长序列长度
        int size = (int)nums.size();
        vector<int> maxLen(size, 1);

        if (rev) {
            for (int i = 1; i < size; ++i) {
                if ((nums[i] == 0 && nums[i - 1] == 2) || (nums[i] == 2 && nums[i - 1] == 0)) {
                    maxLen[i] = maxLen[i - 1] + 1;
                }
            }
        }
        else {
            for (int i = size - 2; i >= 0; --i) {
                if ((nums[i] == 0 && nums[i + 1] == 2) || (nums[i] == 2 && nums[i + 1] == 0)) {
                    maxLen[i] = maxLen[i + 1] + 1;
                }
            }
        }

        return maxLen;
    }

    int getMaxLen(vector<vector<int>>& grid, int row, int column, vector<vector<int>>& maxLen0,
        vector<vector<int>>& maxLen1, vector<vector<int>>& maxLen2, vector<vector<int>>& maxLen3) {
        int maxLen = 0;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                if (grid[r][c] == 1) {  // 当前是1时，结果只能是一条直线，不能转弯
                    maxLen = max(maxLen, 1);
                    if (getPeerValue(grid, r, c, 0, 1) == 2) {  // 要保证下一个数字是2
                        maxLen = max(maxLen, 1 + maxLen0[r][c]);
                    }
                    if (getPeerValue(grid, r, c, 1, 1) == 2) {
                        maxLen = max(maxLen, 1 + maxLen1[r][c]);
                    }
                    if (getPeerValue(grid, r, c, 2, 1) == 2) {
                        maxLen = max(maxLen, 1 + maxLen2[r][c]);
                    }
                    if (getPeerValue(grid, r, c, 3, 1) == 2) {
                        maxLen = max(maxLen, 1 + maxLen3[r][c]);
                    }
                }
                else {  // 当前是0或2，两个方向最长长度相加
                    if (getPeerValue(grid, r, c, 1, maxLen1[r][c] - 1) == 2 && getPeerValue(grid, r, c, 1, maxLen1[r][c]) == 1) {  // 要保证对端是2，并且对端的下一个是1
                        maxLen = max(maxLen, maxLen0[r][c] + maxLen1[r][c]);
                    }
                    if (getPeerValue(grid, r, c, 2, maxLen2[r][c] - 1) == 2 && getPeerValue(grid, r, c, 2, maxLen2[r][c]) == 1) {
                        maxLen = max(maxLen, maxLen1[r][c] + maxLen2[r][c]);
                    }
                    if (getPeerValue(grid, r, c, 3, maxLen3[r][c] - 1) == 2 && getPeerValue(grid, r, c, 3, maxLen3[r][c]) == 1) {
                        maxLen = max(maxLen, maxLen2[r][c] + maxLen3[r][c]);
                    }
                    if (getPeerValue(grid, r, c, 0, maxLen0[r][c] - 1) == 2 && getPeerValue(grid, r, c, 0, maxLen0[r][c]) == 1) {
                        maxLen = max(maxLen, maxLen3[r][c] + maxLen0[r][c]);
                    }
                }
            }
        }

        return maxLen;
    }

    int getPeerValue(vector<vector<int>>& grid, int r, int c, int dir, int len) {
        int dr[4] = { -1,1,1,-1 }, dc[4] = { 1,1,-1,-1 };
        int nr = r + dr[dir] * len, nc = c + dc[dir] * len;

        return (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()) ? grid[nr][nc] : -1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {2,2,1,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2} };
    check.checkInt(5, o.lenOfVDiagonal(grid));

    grid = { {2,2,2,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2} };
    check.checkInt(4, o.lenOfVDiagonal(grid));

    grid = { {1,2,2,2,2},{2,2,2,2,0},{2,0,0,0,0},{0,0,2,2,2},{2,0,0,2,0} };
    check.checkInt(5, o.lenOfVDiagonal(grid));

    grid = { {1} };
    check.checkInt(1, o.lenOfVDiagonal(grid));

    grid = { {0,0},{2,2} };
    check.checkInt(0, o.lenOfVDiagonal(grid));

    grid = { {1,2,2},{1,0,2} };
    check.checkInt(2, o.lenOfVDiagonal(grid));

    grid = { {1,1,1,2,0,0},{0,0,0,0,1,2} };
    check.checkInt(2, o.lenOfVDiagonal(grid));

    grid = { {0,0,0,0,2,2,2,0,1,1,1,2,1,2,0,1,0,0},{2,1,2,2,0,2,2,0,2,2,2,2,2,0,1,0,1,2},{0,2,2,1,2,2,2,0,2,1,2,2,0,1,1,2,2,0},{0,0,2,1,0,2,1,1,2,2,1,0,2,2,0,0,1,1},{0,2,2,1,0,1,1,0,0,0,0,2,2,2,2,2,2,1},{1,2,1,0,1,0,1,1,0,1,2,2,0,2,0,2,2,0},{2,2,0,0,0,0,1,0,0,1,2,2,0,0,0,0,2,1},{1,2,2,2,2,0,1,1,1,0,1,2,2,2,2,0,0,2} };
    check.checkInt(6, o.lenOfVDiagonal(grid));
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
