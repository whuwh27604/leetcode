/* 最大矩形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

 

示例 1：


输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。
示例 2：

输入：matrix = []
输出：0
示例 3：

输入：matrix = [["0"]]
输出：0
示例 4：

输入：matrix = [["1"]]
输出：1
示例 5：

输入：matrix = [["0","0"]]
输出：0
 

提示：

rows == matrix.length
cols == matrix[0].length
0 <= row, cols <= 200
matrix[i][j] 为 '0' 或 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int i, j, row = matrix.size(), column = matrix[0].size(), maxArea = 0;
        vector<int> heights(column, 0);

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
            }

            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        int i, size = heights.size(), largestArea = 0;
        vector<int> leftFirstLess(size), rightFirstLess(size, size);  // left一定会更新；right先全部初始化为size，部分会更新，剩下未更新的说明右边没有更小的数，所以就是size
        stack<pair<int, int>> increasingNums;
        increasingNums.push({ -1,-1 });  // 预置一个永不出栈的元素，索引置为-1

        for (i = 0; i < size; ++i) {
            // 相等的也出栈，这样rightFirstLess可能不正确，但是没关系，相等的值中最右边一个的rightFirstLess是正确的，这个值确保了最大面积不会出错。
            while (heights[i] <= increasingNums.top().first) {
                rightFirstLess[increasingNums.top().second] = i;  // 出栈的数，右边第一个小于它的索引都是i
                increasingNums.pop();
            }

            leftFirstLess[i] = increasingNums.top().second;  // 对于height[i]，左边第一个小于它的数是栈顶元素。由于上面把相等的元素也出栈了，所以这里是严格正确的
            increasingNums.push({ heights[i], i });
        }

        for (i = 0; i < size; ++i) {
            largestArea = max(largestArea, (rightFirstLess[i] - leftFirstLess[i] - 1) * heights[i]);
        }

        return largestArea;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<char>> matrix = { {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} };
    check.checkInt(6, o.maximalRectangle(matrix));

    matrix = {  };
    check.checkInt(0, o.maximalRectangle(matrix));

    matrix = { {'0'} };
    check.checkInt(0, o.maximalRectangle(matrix));

    matrix = { {'1'} };
    check.checkInt(1, o.maximalRectangle(matrix));

    matrix = { {'0'},{'0'} };
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
