/* 用邮票贴满网格图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的二进制矩阵 grid ，每个格子要么为 0 （空）要么为 1 （被占据）。

给你邮票的尺寸为 stampHeight x stampWidth 。我们想将邮票贴进二进制矩阵中，且满足以下 限制 和 要求 ：

覆盖所有 空 格子。
不覆盖任何 被占据 的格子。
我们可以放入任意数目的邮票。
邮票可以相互有 重叠 部分。
邮票不允许 旋转 。
邮票必须完全在矩阵 内 。
如果在满足上述要求的前提下，可以放入邮票，请返回 true ，否则返回 false 。

 

示例 1：



输入：grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], stampHeight = 4, stampWidth = 3
输出：true
解释：我们放入两个有重叠部分的邮票（图中标号为 1 和 2），它们能覆盖所有与空格子。
示例 2：



输入：grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2, stampWidth = 2
输出：false
解释：没办法放入邮票覆盖所有的空格子，且邮票不超出网格图以外。
 

提示：

m == grid.length
n == grid[r].length
1 <= m, n <= 105
1 <= m * n <= 2 * 105
grid[r][c] 要么是 0 ，要么是 1 。
1 <= stampHeight, stampWidth <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stamping-the-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        vector<vector<int>> sums(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
        vector<vector<int>> diffs(sums.size() + 1, vector<int>(sums[0].size() + 1, 0));

        getSums(grid, sums);
        getDiffs(sums, stampHeight, stampWidth, diffs);

        return canAllStamp(grid, diffs);
    }

    void getSums(vector<vector<int>>& grid, vector<vector<int>>& sums) {
        for (int i = 0; i < (int)grid.size(); ++i) {
            for (int j = 0; j < (int)grid[0].size(); ++j) {
                sums[i + 1][j + 1] = sums[i + 1][j] + sums[i][j + 1] - sums[i][j] + grid[i][j];
            }
        }
    }

    void getDiffs(vector<vector<int>>& sums, int height, int width, vector<vector<int>>& diffs) {
        for (int i = 1; i <= (int)sums.size() - height; ++i) {
            for (int j = 1; j <= (int)sums[0].size() - width; ++j) {
                if (sums[i + height - 1][j + width - 1] - sums[i - 1][j + width - 1] - sums[i + height - 1][j - 1] + sums[i - 1][j - 1] == 0) {  // 该矩形区域内没有任何1，可以放邮票
                    ++diffs[i][j];  // 标记差分数组的四个角
                    --diffs[i + height][j];
                    --diffs[i][j + width];
                    ++diffs[i + height][j + width];
                }
            }
        }
    }

    bool canAllStamp(vector<vector<int>>& grid, vector<vector<int>>& diffs) {
        for (int i = 1; i < (int)diffs.size() - 1; ++i) {
            for (int j = 1; j < (int)diffs[0].size() - 1; ++j) {
                diffs[i][j] += (diffs[i][j - 1] + diffs[i - 1][j] - diffs[i - 1][j - 1]);  // 利用差分数组还原该位置实际覆盖的stamp个数

                if (diffs[i][j] == 0 && grid[i - 1][j - 1] == 0) {  // 没有stamp覆盖该位置，并且该位置是一个空格子，那么返回失败
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0} };
    check.checkBool(true, o.possibleToStamp(grid, 4, 3));

    grid = { {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1} };
    check.checkBool(false, o.possibleToStamp(grid, 2, 2));

    grid = { {0,0,0,0,0},{0,0,0,0,0},{0,0,1,0,0},{0,0,0,0,1},{0,0,0,1,1} };
    check.checkBool(false, o.possibleToStamp(grid, 2, 2));
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
