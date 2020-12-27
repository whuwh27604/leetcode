/* 柱状图中最大的矩形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 



以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

 



图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

 

示例:

输入: [2,1,5,6,2,3]
输出: 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
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

    vector<int> heights = { 2,1,5,6,2,3 };
    check.checkInt(10, o.largestRectangleArea(heights));

    heights = { 3,6,5,7,4,8,1,0 };
    check.checkInt(20, o.largestRectangleArea(heights));

    heights = { 2,2,1,2 };
    check.checkInt(4, o.largestRectangleArea(heights));

    heights = { 2147483647,0,2147483647,0,2147483647,0,2147483647,0,2147483647,0 };
    check.checkInt(2147483647, o.largestRectangleArea(heights));

    heights = { 2,1,5,6,2,3,4,5,6,7,8 };
    check.checkInt(20, o.largestRectangleArea(heights));
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
