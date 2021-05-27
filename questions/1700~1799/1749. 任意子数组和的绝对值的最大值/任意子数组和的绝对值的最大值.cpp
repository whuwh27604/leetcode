﻿/* 任意子数组和的绝对值的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。一个子数组 [numsl, numsl+1, ..., numsr-1, numsr] 的 和的绝对值 为 abs(numsl + numsl+1 + ... + numsr-1 + numsr) 。

请你找出 nums 中 和的绝对值 最大的任意子数组（可能为空），并返回该 最大值 。

abs(x) 定义如下：

如果 x 是负整数，那么 abs(x) = -x 。
如果 x 是非负整数，那么 abs(x) = x 。
 

示例 1：

输入：nums = [1,-3,2,3,-4]
输出：5
解释：子数组 [2,3] 和的绝对值最大，为 abs(2+3) = abs(5) = 5 。
示例 2：

输入：nums = [2,-5,1,-4,3,-2]
输出：8
解释：子数组 [-5,1,-4] 和的绝对值最大，为 abs(-5+1-4) = abs(-8) = 8 。
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-absolute-sum-of-any-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int posSum = 0, negSum = 0, maxPosSum = 0, minNegSum = 0;

        for (int num : nums) {
            posSum += num;
            maxPosSum = max(maxPosSum, posSum);
            if (posSum < 0) {
                posSum = 0;
            }

            negSum += num;
            minNegSum = min(minNegSum, negSum);
            if (negSum > 0) {
                negSum = 0;
            }
        }

        return max(maxPosSum, -minNegSum);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,-3,2,3,-4 };
    check.checkInt(5, o.maxAbsoluteSum(nums));

    nums = { 2,-5,1,-4,3,-2 };
    check.checkInt(8, o.maxAbsoluteSum(nums));

    nums = { -2 };
    check.checkInt(2, o.maxAbsoluteSum(nums));

    nums = { 1,-2,3,4,-5,6,7,8,-9,10,9,8,-7,6,5,-4,3,2,-1 };
    check.checkInt(46, o.maxAbsoluteSum(nums));

    nums = { -1,2,-3,-4,5,-6,-7,-8,9,-10,-9,-8,7,-6,-5,4,-3,-2,1 };
    check.checkInt(46, o.maxAbsoluteSum(nums));
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
