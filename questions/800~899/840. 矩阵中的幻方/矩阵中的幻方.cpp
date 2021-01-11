/* 矩阵中的幻方.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
3 x 3 的幻方是一个填充有从 1 到 9 的不同数字的 3 x 3 矩阵，其中每行，每列以及两条对角线上的各数之和都相等。

给定一个由整数组成的 grid，其中有多少个 3 × 3 的 “幻方” 子矩阵？（每个子矩阵都是连续的）。

 

示例：

输入: [[4,3,8,4],
      [9,5,1,9],
      [2,7,6,2]]
输出: 1
解释:
下面的子矩阵是一个 3 x 3 的幻方：
438
951
276

而这一个不是：
384
519
762

总的来说，在本示例所给定的矩阵中只有一个 3 x 3 的幻方子矩阵。
提示:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/magic-squares-in-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        if ((row < 3) || (column < 3)) {
            return 0;
        }

        unordered_set<int> magicSquares = { 81637492, 83419672, 61873294, 67219834, 49237816, 43891276, 29473618, 27691438 };
        int magicSquareNums = 0;

        for (int i = 0; i < (row - 2); i++) {
            for (int j = 0; j < (column - 2); j++) {
                int number = encodeSquare(i, j, grid);
                if (magicSquares.find(number) != magicSquares.end()) {
                    magicSquareNums++;
                }
            }
        }

        return magicSquareNums;
    }

    int encodeSquare(int r, int c, vector<vector<int>>& grid) {
        if (grid[r + 1][c + 1] != 5) {
            return -1;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((grid[r + i][c + j] < 1) || (grid[r + i][c + j] > 9)) {
                    return -1;
                }
            }
        }

        return (grid[r][c] * 10000000 + grid[r][c + 1] * 1000000 + grid[r][c + 2] * 100000 + grid[r + 1][c] * 10000
            + grid[r + 1][c + 2] * 1000 + grid[r + 2][c] * 100 + grid[r + 2][c + 1] * 10 + grid[r + 2][c + 2]);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {4,3,8,4},{9,5,1,9},{2,7,6,2} };
    check.checkInt(1, o.numMagicSquaresInside(grid));

    grid = { {4,3,8,3,4},{9,5,1,5,9},{2,7,6,7,2} };
    check.checkInt(2, o.numMagicSquaresInside(grid));

    grid = { {4} };
    check.checkInt(0, o.numMagicSquaresInside(grid));

    grid = { {4,3},{9,5} };
    check.checkInt(0, o.numMagicSquaresInside(grid));
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
