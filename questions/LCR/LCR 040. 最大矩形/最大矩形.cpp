/* 最大矩形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个由 0 和 1 组成的矩阵 matrix ，找出只包含 1 的最大矩形，并返回其面积。

注意：此题 matrix 输入格式为一维 01 字符串数组。



示例 1：



输入：matrix = ["10100","10111","11111","10010"]
输出：6
解释：最大矩形如上图所示。
示例 2：

输入：matrix = []
输出：0
示例 3：

输入：matrix = ["0"]
输出：0
示例 4：

输入：matrix = ["1"]
输出：1
示例 5：

输入：matrix = ["00"]
输出：0


提示：

rows == matrix.length
cols == matrix[0].length
0 <= row, cols <= 200
matrix[i][j] 为 '0' 或 '1'


注意：本题与主站 85 题相同（输入参数格式不同）： https://leetcode-cn.com/problems/maximal-rectangle/
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }

        int column = matrix[0].size();
        if (column == 0) {
            return 0;
        }

        vector<int> heights(column, 0);
        int maxRectangle = 0;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                if (matrix[r][c] == '0') {
                    heights[c] = 0;
                }
                else {
                    ++heights[c];
                }
            }

            maxRectangle = max(maxRectangle, largestRectangleArea(heights));
        }

        return maxRectangle;
    }

    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size(), maxArea = 0;
        vector<int> leftLess(size, -1), rightLess(size, size);
        stack<int> increasing;

        for (int i = size - 1; i >= 0; --i) {
            while (!increasing.empty() && heights[increasing.top()] >= heights[i]) {
                leftLess[increasing.top()] = i;
                increasing.pop();
            }

            if (!increasing.empty()) {
                rightLess[i] = increasing.top();
            }

            increasing.push(i);
        }

        for (int i = 0; i < size; ++i) {
            maxArea = max(maxArea, heights[i] * (rightLess[i] - leftLess[i] - 1));
        }

        return maxArea;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> matrix = { "10100","10111","11111","10010" };
    check.checkInt(6, o.maximalRectangle(matrix));

    matrix = {  };
    check.checkInt(0, o.maximalRectangle(matrix));

    matrix = { "0" };
    check.checkInt(0, o.maximalRectangle(matrix));

    matrix = { "1" };
    check.checkInt(1, o.maximalRectangle(matrix));

    matrix = { "00" };
    check.checkInt(0, o.maximalRectangle(matrix));
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
