/* 矩阵中的最长递增路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数矩阵，找出最长递增路径的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:

输入: nums =
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
输出: 4
解释: 最长递增路径为 [1, 2, 6, 9]。
示例 2:

输入: nums =
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
输出: 4
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int row = matrix.size(), column = matrix[0].size(), maxLongestPath = 0;
        vector<vector<int>> longestPaths(row, vector<int>(column, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                int pathLen = DFS(matrix, longestPaths, i, j);
                maxLongestPath = max(maxLongestPath, pathLen);
            }
        }

        return maxLongestPath;
    }

    int DFS(vector<vector<int>>& matrix, vector<vector<int>>& longestPaths, int pR, int pC) {
        if (longestPaths[pR][pC] != 0) {
            return longestPaths[pR][pC];
        }

        int dc[4] = { 1,0,-1,0 }, dr[4] = { 0,1,0,-1 };
        int row = matrix.size(), column = matrix[0].size(), pathLen, longestPathLen = 1;

        for (int direction = 0; direction < 4; direction++) {
            int nextR = pR + dr[direction];
            int nextC = pC + dc[direction];
            if ((nextR < 0) || (nextR >= row) || (nextC < 0) || (nextC >= column) || (matrix[nextR][nextC] <= matrix[pR][pC])) {
                continue;
            }

            pathLen = DFS(matrix, longestPaths, nextR, nextC) + 1;
            longestPathLen = max(pathLen, longestPathLen);
        }

        longestPaths[pR][pC] = longestPathLen;
        return longestPathLen;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> matrix = { {9,9,4},{6,6,8},{2,1,1} };
    check.checkInt(4, o.longestIncreasingPath(matrix));

    matrix = { {3,4,5},{3,2,6},{2,2,1} };
    check.checkInt(4, o.longestIncreasingPath(matrix));

    matrix = {  };
    check.checkInt(0, o.longestIncreasingPath(matrix));

    matrix = { {} };
    check.checkInt(0, o.longestIncreasingPath(matrix));

    matrix = { {1,2,3,4,5},{16,17,18,19,6},{15,24,25,20,7},{14,23,22,21,8},{13,12,11,10,9} };
    check.checkInt(25, o.longestIncreasingPath(matrix));

    matrix = { {7,7,5},{2,4,6},{8,2,0} };
    check.checkInt(4, o.longestIncreasingPath(matrix));

    matrix = { {0,1,2,3,4,5,6,7,8,9},{19,18,17,16,15,14,13,12,11,10},{20,21,22,23,24,25,26,27,28,29},{39,38,37,36,35,34,33,32,31,30},
        {40,41,42,43,44,45,46,47,48,49},{59,58,57,56,55,54,53,52,51,50},{60,61,62,63,64,65,66,67,68,69},{79,78,77,76,75,74,73,72,71,70},
        {80,81,82,83,84,85,86,87,88,89},{99,98,97,96,95,94,93,92,91,90},{100,101,102,103,104,105,106,107,108,109},{119,118,117,116,115,114,113,112,111,110},
        {120,121,122,123,124,125,126,127,128,129},{139,138,137,136,135,134,133,132,131,130},{0,0,0,0,0,0,0,0,0,0} };
    check.checkInt(140, o.longestIncreasingPath(matrix));
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
