/* 重新排列后的最大子矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制矩阵 matrix ，它的大小为 m x n ，你可以将 matrix 中的 列 按任意顺序重新排列。

请你返回最优方案下将 matrix 重新排列后，全是 1 的子矩阵面积。

 

示例 1：



输入：matrix = [[0,0,1],[1,1,1],[1,0,1]]
输出：4
解释：你可以按照上图方式重新排列矩阵的每一列。
最大的全 1 子矩阵是上图中加粗的部分，面积为 4 。
示例 2：



输入：matrix = [[1,0,1,0,1]]
输出：3
解释：你可以按照上图方式重新排列矩阵的每一列。
最大的全 1 子矩阵是上图中加粗的部分，面积为 3 。
示例 3：

输入：matrix = [[1,1,0],[1,0,1]]
输出：2
解释：由于你只能整列整列重新排布，所以没有比面积为 2 更大的全 1 子矩形。
示例 4：

输入：matrix = [[0,0],[0,0]]
输出：0
解释：由于矩阵中没有 1 ，没有任何全 1 的子矩阵，所以面积为 0 。
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m * n <= 105
matrix[i][j] 要么是 0 ，要么是 1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int i, row = matrix.size(), column = matrix[0].size(), maxArea = 0;

        vector<vector<int>> allHeights(row, vector<int>(column));
        getAllHeights(matrix, allHeights);

        for (i = 0; i < row; ++i) {
            vector<int> heights(column);
            getHeights(allHeights, i, column, heights);
            sort(heights.begin(), heights.end());
            maxArea = max(maxArea, getMaxArea(heights));
        }

        return maxArea;
    }

    void getAllHeights(vector<vector<int>>& matrix, vector<vector<int>>& allHeights) {
        for (unsigned int j = 0; j < matrix[0].size(); ++j) {
            int ones = 0;

            for (unsigned int i = 0; i < matrix.size(); ++i) {
                if (matrix[i][j] == 0) {
                    allHeights[i][j] = 0;
                    ones = 0;
                }
                else {
                    allHeights[i][j] = ++ones;
                }
            }
        }
    }

    void getHeights(vector<vector<int>>& allHeights, int row, int column, vector<int>& heights) {
        for (int j = 0; j < column; ++j) {
            heights[j] = allHeights[row][j];
        }
    }

    int getMaxArea(vector<int>& heights) {
        int i, size = heights.size(), maxArea = 0;

        for (i = size - 1; i >= 0 && heights[i] != 0; --i) {
            maxArea = max(maxArea, heights[i] * (size - i));
        }

        return maxArea;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> matrix = { {0,0,1},{1,1,1},{1,0,1} };
    check.checkInt(4, o.largestSubmatrix(matrix));

    matrix = { {1,0,1,0,1} };
    check.checkInt(3, o.largestSubmatrix(matrix));

    matrix = { {1,1,0},{1,0,1} };
    check.checkInt(2, o.largestSubmatrix(matrix));

    matrix = { {0,0},{0,0} };
    check.checkInt(0, o.largestSubmatrix(matrix));
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
