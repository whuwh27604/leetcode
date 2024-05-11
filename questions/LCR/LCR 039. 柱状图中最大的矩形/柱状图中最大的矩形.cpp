/* 柱状图中最大的矩形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定非负整数数组 heights ，数组中的数字用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。



示例 1:



输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
示例 2：



输入： heights = [2,4]
输出： 4


提示：

1 <= heights.length <=105
0 <= heights[i] <= 104


注意：本题与主站 84 题相同： https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
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

    vector<int> heights = { 2,1,5,6,2,3 };
    check.checkInt(10, o.largestRectangleArea(heights));

    heights = { 2,4 };
    check.checkInt(4, o.largestRectangleArea(heights));

    heights = { 9,8,4,9,2,6,9,0,5,4,9,5,3,8,2,9 };
    check.checkInt(18, o.largestRectangleArea(heights));
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
