﻿/* 使二进制数组全部等于 1 的最少操作次数 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制数组 nums 。

你可以对数组执行以下操作 任意 次（也可以 0 次）：

选择数组中 任意连续 3 个元素，并将它们 全部反转 。
反转 一个元素指的是将它的值从 0 变 1 ，或者从 1 变 0 。

请你返回将 nums 中所有元素变为 1 的 最少 操作次数。如果无法全部变成 1 ，返回 -1 。



示例 1：

输入：nums = [0,1,1,1,0,0]

输出：3

解释：
我们可以执行以下操作：

选择下标为 0 ，1 和 2 的元素并反转，得到 nums = [1,0,0,1,0,0] 。
选择下标为 1 ，2 和 3 的元素并反转，得到 nums = [1,1,1,0,0,0] 。
选择下标为 3 ，4 和 5 的元素并反转，得到 nums = [1,1,1,1,1,1] 。
示例 2：

输入：nums = [0,1,1,1]

输出：-1

解释：
无法将所有元素都变为 1 。



提示：

3 <= nums.length <= 105
0 <= nums[i] <= 1
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = (int)nums.size(), opers = 0;

        for (int i = 0; i < size; ++i) {
            if (nums[i] == 0) {
                if (i + 2 >= size) {
                    return -1;
                }

                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++opers;
            }
        }

        return opers;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 0,1,1,1,0,0 };
    check.checkInt(3, o.minOperations(nums));

    nums = { 0,1,1,1 };
    check.checkInt(-1, o.minOperations(nums));
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
