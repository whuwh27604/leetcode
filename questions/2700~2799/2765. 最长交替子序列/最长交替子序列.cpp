/* 最长交替子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。如果 nums 中长度为 m 的子数组 s 满足以下条件，我们称它是一个 交替子序列 ：

m 大于 1 。
s1 = s0 + 1 。
下标从 0 开始的子数组 s 与数组 [s0, s1, s0, s1,...,s(m-1) % 2] 一样。也就是说，s1 - s0 = 1 ，s2 - s1 = -1 ，s3 - s2 = 1 ，s4 - s3 = -1 ，以此类推，直到 s[m - 1] - s[m - 2] = (-1)m 。
请你返回 nums 中所有 交替 子数组中，最长的长度，如果不存在交替子数组，请你返回 -1 。

子数组是一个数组中一段连续 非空 的元素序列。



示例 1：

输入：nums = [2,3,4,3,4]
输出：4
解释：交替子数组有 [3,4] ，[3,4,3] 和 [3,4,3,4] 。最长的子数组为 [3,4,3,4] ，长度为4 。
示例 2：

输入：nums = [4,5,6]
输出：2
解释：[4,5] 和 [5,6] 是仅有的两个交替子数组。它们长度都为 2 。


提示：

2 <= nums.length <= 100
1 <= nums[i] <= 104
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int size = nums.size(), len = 1, maxLen = 0, delta = 1;

        for (int i = 1; i < size; ++i) {
            if (nums[i - 1] + delta == nums[i]) {
                ++len;
                delta *= -1;
            }
            else {
                maxLen = max(maxLen, len);
                if (nums[i - 1] + 1 == nums[i]) {
                    len = 2;
                    delta = -1;
                }
                else {
                    len = 1;
                    delta = 1;
                }
            }
        }

        maxLen = max(maxLen, len);

        return maxLen == 1 ? -1 : maxLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,4,3,4 };
    check.checkInt(4, o.alternatingSubarray(nums));

    nums = { 4,5,6 };
    check.checkInt(2, o.alternatingSubarray(nums));

    nums = { 1,2 };
    check.checkInt(2, o.alternatingSubarray(nums));

    nums = { 2,1 };
    check.checkInt(-1, o.alternatingSubarray(nums));
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
