/* 找出有效子序列的最大长度 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums。

nums 的子序列 sub 的长度为 x ，如果其满足以下条件，则称其为 有效子序列：

(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2
返回 nums 的 最长的有效子序列 的长度。

一个 子序列 指的是从原数组中删除一些元素（也可以不删除任何元素），剩余元素保持原来顺序组成的新数组。



示例 1：

输入： nums = [1,2,3,4]

输出： 4

解释：

最长的有效子序列是 [1, 2, 3, 4]。

示例 2：

输入： nums = [1,2,1,1,2,1,2]

输出： 6

解释：

最长的有效子序列是 [1, 2, 1, 2, 1, 2]。

示例 3：

输入： nums = [1,3]

输出： 2

解释：

最长的有效子序列是 [1, 3]。



提示：

2 <= nums.length <= 2 * 105
1 <= nums[i] <= 107
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        return max(getMaxLen1(nums), getMaxLen2(nums));
    }

    int getMaxLen1(vector<int>& nums) {
        int size = (int)nums.size(), len = 1, oe = (nums[0] & 1) ^ 1;

        for (int i = 1; i < size; ++i) {
            if (((nums[i] & 1) ^ oe) == 0) {
                ++len;
                oe ^= 1;
            }
        }

        return len;
    }

    int getMaxLen2(vector<int>& nums) {
        int odd = 0, even = 0;

        for (int num : nums) {
            if ((num & 1) == 0) {
                ++even;
            }
            else {
                ++odd;
            }
        }

        return max(even, odd);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3,4 };
    check.checkInt(4, o.maximumLength(nums));

    nums = { 1,2,1,1,2,1,2 };
    check.checkInt(6, o.maximumLength(nums));

    nums = { 1,3 };
    check.checkInt(2, o.maximumLength(nums));
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
