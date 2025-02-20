﻿/* 统计元素和差值为偶数的分区方案.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums 。

分区 是指将数组按照下标 i （0 <= i < n - 1）划分成两个 非空 子数组，其中：

左子数组包含区间 [0, i] 内的所有下标。
右子数组包含区间 [i + 1, n - 1] 内的所有下标。
对左子数组和右子数组先求元素 和 再做 差 ，统计并返回差值为 偶数 的 分区 方案数。



示例 1：

输入：nums = [10,10,3,7,6]

输出：4

解释：

共有 4 个满足题意的分区方案：

[10]、[10, 3, 7, 6] 元素和的差值为 10 - 26 = -16 ，是偶数。
[10, 10]、[3, 7, 6] 元素和的差值为 20 - 16 = 4，是偶数。
[10, 10, 3]、[7, 6] 元素和的差值为 23 - 13 = 10，是偶数。
[10, 10, 3, 7]、[6] 元素和的差值为 30 - 6 = 24，是偶数。
示例 2：

输入：nums = [1,2,2]

输出：0

解释：

不存在元素和的差值为偶数的分区方案。

示例 3：

输入：nums = [2,4,6,8]

输出：3

解释：

所有分区方案都满足元素和的差值为偶数。



提示：

2 <= n == nums.length <= 100
1 <= nums[i] <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int size = (int)nums.size(), cnt = 0;

        for (int i = 1; i < size; ++i) {
            nums[i] += nums[i - 1];
        }

        for (int i = 1; i < size; ++i) {
            if (((nums[i - 1] & 1) ^ ((nums[size - 1] - nums[i - 1]) & 1)) == 0) {
                ++cnt;
            }
        }

        return cnt;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 10,10,3,7,6 };
    check.checkInt(4, o.countPartitions(nums));

    nums = { 1,2,2 };
    check.checkInt(0, o.countPartitions(nums));

    nums = { 2,4,6,8 };
    check.checkInt(3, o.countPartitions(nums));
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
