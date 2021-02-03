/* 接雨水.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
 

提示：

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int i, size = height.size(), units = 0;
        vector<int> leftMax(size), rightMax(size);

        int maximum = 0;
        for (i = 0; i < size; ++i) {
            maximum = max(maximum, height[i]);
            leftMax[i] = maximum;
        }

        maximum = 0;
        for (i = size - 1; i >= 0; --i) {
            maximum = max(maximum, height[i]);
            rightMax[i] = maximum;
        }

        for (i = 0; i < size; ++i) {
            units += (min(leftMax[i], rightMax[i]) - height[i]);
        }

        return units;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    check.checkInt(6, o.trap(height));

    height = { 4,2,0,3,2,5 };
    check.checkInt(9, o.trap(height));

    height = { 4 };
    check.checkInt(0, o.trap(height));
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
