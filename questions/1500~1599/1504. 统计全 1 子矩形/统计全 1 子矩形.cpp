/* 统计全 1 子矩形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个只包含 0 和 1 的 rows * columns 矩阵 mat ，请你返回有多少个 子矩形 的元素全部都是 1 。

 

示例 1：

输入：mat = [[1,0,1],
            [1,1,0],
            [1,1,0]]
输出：13
解释：
有 6 个 1x1 的矩形。
有 2 个 1x2 的矩形。
有 3 个 2x1 的矩形。
有 1 个 2x2 的矩形。
有 1 个 3x1 的矩形。
矩形数目总共 = 6 + 2 + 3 + 1 + 1 = 13 。
示例 2：

输入：mat = [[0,1,1,0],
            [0,1,1,1],
            [1,1,1,0]]
输出：24
解释：
有 8 个 1x1 的子矩形。
有 5 个 1x2 的子矩形。
有 2 个 1x3 的子矩形。
有 4 个 2x1 的子矩形。
有 2 个 2x2 的子矩形。
有 2 个 3x1 的子矩形。
有 1 个 3x2 的子矩形。
矩形数目总共 = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24 。
示例 3：

输入：mat = [[1,1,1,1,1,1]]
输出：21
示例 4：

输入：mat = [[1,0,1],[0,1,0],[1,0,1]]
输出：5
 

提示：

1 <= rows <= 150
1 <= columns <= 150
0 <= mat[i][j] <= 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-submatrices-with-all-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int i, j, row = mat.size(), column = mat[0].size(), allones = 0;
        vector<vector<int>> heights(row, vector<int>(column));  // 记录每个位置的高度
        vector<vector<int>> allOneSubMats(row, vector<int>(column));  // 记录每个位置全1矩阵的数量

        getHeights(mat, heights);

        for (i = 0; i < row; ++i) {
            stack<pair<int, int>> increasing;
            increasing.push({ -1, -1 });  // 单调递增栈，前置一个高度为-1的节点，保证不为空

            for (j = 0; j < column; ++j) {
                while (heights[i][j] < increasing.top().first) {
                    increasing.pop();  // 左边比自己高，不影响计算全1矩阵，直接pop掉
                }

                int col = increasing.top().second;  // 左边第一个比自己矮的坐标
                /* 1、mat[i][col]形成的所有全1子矩阵，都能够延长到mat[i][j]
                   2、mat[i][col+1]到mat[i][j]之间，是高度为heights[i][j]的全1矩阵 */
                allOneSubMats[i][j] = (col == -1 ? 0 : allOneSubMats[i][col]) + heights[i][j] * (j - col);
                allones += allOneSubMats[i][j];
                increasing.push({ heights[i][j], j });
            }
        }

        return allones;
    }

    void getHeights(vector<vector<int>>& mat, vector<vector<int>>& heights) {
        for (int i = 0; i < (int)mat.size(); ++i) {
            for (int j = 0; j < (int)mat[0].size(); ++j) {
                if (mat[i][j] == 0) {
                    heights[i][j] = 0;
                }
                else {
                    heights[i][j] = (i == 0 ? 1 : heights[i - 1][j] + 1);
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = { {1,1,1},{1,1,1},{1,1,1} };
    check.checkInt(36, o.numSubmat(mat));

    mat = { {1,0,1},{1,1,0},{1,1,0} };
    check.checkInt(13, o.numSubmat(mat));

    mat = { {0,1,1,0},{0,1,1,1},{1,1,1,0} };
    check.checkInt(24, o.numSubmat(mat));

    mat = { {1,1,1,1,1,1} };
    check.checkInt(21, o.numSubmat(mat));

    mat = { {1,0,1},{0,1,0},{1,0,1} };
    check.checkInt(5, o.numSubmat(mat));

    mat = { {1} };
    check.checkInt(1, o.numSubmat(mat));

    mat = { {0} };
    check.checkInt(0, o.numSubmat(mat));
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
