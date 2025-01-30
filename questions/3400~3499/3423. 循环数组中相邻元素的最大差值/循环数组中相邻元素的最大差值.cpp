/* 循环数组中相邻元素的最大差值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 循环 数组 nums ，请你找出相邻元素之间的 最大 绝对差值。

注意：一个循环数组中，第一个元素和最后一个元素是相邻的。



示例 1：

输入：nums = [1,2,4]

输出：3

解释：

由于 nums 是循环的，nums[0] 和 nums[2] 是相邻的，它们之间的绝对差值是最大值 |4 - 1| = 3 。

示例 2：

输入：nums = [-5,-10,-5]

输出：5

解释：

相邻元素 nums[0] 和 nums[1] 之间的绝对差值为最大值 |-5 - (-10)| = 5 。



提示：

2 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int size = (int)nums.size(), maxDist = abs(nums[0] - nums[size - 1]);

        for (int i = 1; i < size; ++i) {
            maxDist = max(maxDist, abs(nums[i] - nums[i - 1]));
        }

        return maxDist;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,4 };
    check.checkInt(3, o.maxAdjacentDistance(nums));

    nums = { -5,-10,-5 };
    check.checkInt(5, o.maxAdjacentDistance(nums));
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
