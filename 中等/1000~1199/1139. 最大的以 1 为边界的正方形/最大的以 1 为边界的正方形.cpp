/* 最大的以 1 为边界的正方形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边界全部由 1 组成的最大 正方形 子网格，并返回该子网格中的元素数量。如果不存在，则返回 0。

 

示例 1：

输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
输出：9
示例 2：

输入：grid = [[1,1,0,0]]
输出：1
 

提示：

1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-1-bordered-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();

        vector<vector<int>> rightConsecutiveOnes(row, vector<int>(column, 0)), downConsecutiveOnes(row, vector<int>(column, 0));
        if (getRightConsecutiveOnes(grid, rightConsecutiveOnes)) {
            return 0;
        }
        getDownConsecutiveOnes(grid, downConsecutiveOnes);

        int maxSideLen = getMaxSideLen(rightConsecutiveOnes, downConsecutiveOnes);
        return maxSideLen * maxSideLen;
    }

    bool getRightConsecutiveOnes(vector<vector<int>>& grid, vector<vector<int>>& rightConsecutiveOnes) {
        int i, j, row = grid.size(), column = grid[0].size(), consecutiveOnes;
        bool allZeros = true;

        for (i = 0; i < row; ++i) {
            consecutiveOnes = 0;

            for (j = column - 1; j >= 0; --j) {
                if (grid[i][j] == 0) {
                    consecutiveOnes = 0;
                }
                else {
                    rightConsecutiveOnes[i][j] = ++consecutiveOnes;
                    allZeros = false;
                }
            }
        }

        return allZeros;
    }

    void getDownConsecutiveOnes(vector<vector<int>>& grid, vector<vector<int>>& downConsecutiveOnes) {
        int i, j, row = grid.size(), column = grid[0].size(), consecutiveOnes;

        for (j = 0; j < column; ++j) {
            consecutiveOnes = 0;

            for (i = row - 1; i >= 0; --i) {
                if (grid[i][j] == 0) {
                    consecutiveOnes = 0;
                }
                else {
                    downConsecutiveOnes[i][j] = ++consecutiveOnes;
                }
            }
        }
    }

    int getMaxSideLen(vector<vector<int>>& rightConsecutiveOnes, vector<vector<int>>& downConsecutiveOnes) {
        int i, j, row = rightConsecutiveOnes.size(), column = rightConsecutiveOnes[0].size(), maxSideLen = 1;

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                for (int sideLen = min(rightConsecutiveOnes[i][j], downConsecutiveOnes[i][j]); sideLen > 1; --sideLen) {
                    if (downConsecutiveOnes[i][j + sideLen - 1] >= sideLen && rightConsecutiveOnes[i + sideLen - 1][j] >= sideLen) {
                        maxSideLen = max(maxSideLen, sideLen);
                        break;
                    }
                }
            }
        }

        return maxSideLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,1,1},{1,0,1},{1,1,1} };
    check.checkInt(9, o.largest1BorderedSquare(grid));

    grid = { {1,1,0,0} };
    check.checkInt(1, o.largest1BorderedSquare(grid));

    grid = { {0,0},{0,0} };
    check.checkInt(0, o.largest1BorderedSquare(grid));

    grid = { {0,0},{0,0} };
    check.checkInt(0, o.largest1BorderedSquare(grid));

    grid = { {1,1,1,0,0,0},{1,1,1,1,1,1},{1,1,1,1,1,1},{0,0,1,1,1,1},{0,0,1,1,1,1} };
    check.checkInt(16, o.largest1BorderedSquare(grid));
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
