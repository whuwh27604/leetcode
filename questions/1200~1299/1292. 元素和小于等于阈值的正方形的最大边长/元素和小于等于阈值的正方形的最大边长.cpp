/* 元素和小于等于阈值的正方形的最大边长.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 m x n 的矩阵 mat 和一个整数阈值 threshold。

请你返回元素总和小于或等于阈值的正方形区域的最大边长；如果没有这样的正方形区域，则返回 0 。
 

示例 1：



输入：mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
输出：2
解释：总和小于 4 的正方形的最大边长为 2，如图所示。
示例 2：

输入：mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
输出：0
示例 3：

输入：mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
输出：3
示例 4：

输入：mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
输出：2
 

提示：

1 <= m, n <= 300
m == mat.length
n == mat[i].length
0 <= mat[i][j] <= 10000
0 <= threshold <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int i, j, row = mat.size(), column = mat[0].size(), maxEdge = 0;
        
        vector<vector<int>> preSum(row + 1, vector<int>(column + 1, 0));
        preparePreSum(mat, preSum);

        slideWindow(preSum, 0, 0, threshold, maxEdge);

        for (i = 1; i < row && row - i > maxEdge; ++i) {
            slideWindow(preSum, i, 0, threshold, maxEdge);
        }

        for (j = 1; j < column && column - j > maxEdge; ++j) {
            slideWindow(preSum, 0, j, threshold, maxEdge);
        }

        return maxEdge;
    }

    void preparePreSum(vector<vector<int>>& mat, vector<vector<int>>& preSum) {
        for (unsigned int i = 0; i < mat.size(); ++i) {
            for (unsigned int j = 0; j < mat[0].size(); ++j) {
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + mat[i][j];
            }
        }
    }

    void slideWindow(vector<vector<int>>& preSum, int r0, int c0, int threshold, int& maxEdge) {
        int row = preSum.size() - 1, column = preSum[0].size() - 1, r1 = r0 + maxEdge, c1 = c0 + maxEdge;

        while (r1 < row && c1 < column && row - r0 > maxEdge) {
            while (r0 <= r1 && c0 <= c1 && (preSum[r1 + 1][c1 + 1] - preSum[r1 + 1][c0] - preSum[r0][c1 + 1] + preSum[r0][c0]) > threshold) {
                ++r0, ++c0;
            }

            maxEdge = max(maxEdge, r1 + 1 - r0);
            ++r1, ++c1;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = { {1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2} };
    check.checkInt(2, o.maxSideLength(mat, 4));

    mat = { {2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2} };
    check.checkInt(0, o.maxSideLength(mat, 1));

    mat = { {2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2} };
    check.checkInt(5, o.maxSideLength(mat, 50));

    mat = { {1,1,1,1},{1,0,0,0},{1,0,0,0},{1,0,0,0} };
    check.checkInt(3, o.maxSideLength(mat, 6));

    mat = { {18,70},{61,1},{25,85},{14,40},{11,96},{97,96},{63,45} };
    check.checkInt(2, o.maxSideLength(mat, 40184));

    mat = { {5} };
    check.checkInt(1, o.maxSideLength(mat, 5));

    mat = { {5} };
    check.checkInt(0, o.maxSideLength(mat, 4));
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
