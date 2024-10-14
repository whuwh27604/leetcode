﻿/* 构造最小位运算数组 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的
质数
数组 nums 。你的任务是返回一个长度为 n 的数组 ans ，对于每个下标 i ，以下 条件 均成立：

ans[i] OR (ans[i] + 1) == nums[i]
除此以外，你需要 最小化 结果数组里每一个 ans[i] 。

如果没法找到符合 条件 的 ans[i] ，那么 ans[i] = -1 。

质数 指的是一个大于 1 的自然数，且它只有 1 和自己两个因数。



示例 1：

输入：nums = [2,3,5,7]

输出：[-1,1,4,3]

解释：

对于 i = 0 ，不存在 ans[0] 满足 ans[0] OR (ans[0] + 1) = 2 ，所以 ans[0] = -1 。
对于 i = 1 ，满足 ans[1] OR (ans[1] + 1) = 3 的最小 ans[1] 为 1 ，因为 1 OR (1 + 1) = 3 。
对于 i = 2 ，满足 ans[2] OR (ans[2] + 1) = 5 的最小 ans[2] 为 4 ，因为 4 OR (4 + 1) = 5 。
对于 i = 3 ，满足 ans[3] OR (ans[3] + 1) = 7 的最小 ans[3] 为 3 ，因为 3 OR (3 + 1) = 7 。
示例 2：

输入：nums = [11,13,31]

输出：[9,12,15]

解释：

对于 i = 0 ，满足 ans[0] OR (ans[0] + 1) = 11 的最小 ans[0] 为 9 ，因为 9 OR (9 + 1) = 11 。
对于 i = 1 ，满足 ans[1] OR (ans[1] + 1) = 13 的最小 ans[1] 为 12 ，因为 12 OR (12 + 1) = 13 。
对于 i = 2 ，满足 ans[2] OR (ans[2] + 1) = 31 的最小 ans[2] 为 15 ，因为 15 OR (15 + 1) = 31 。


提示：

1 <= nums.length <= 100
2 <= nums[i] <= 109
nums[i] 是一个质数。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int size = (int)nums.size();
        vector<int> ans(size, -1);

        for (int i = 0; i < size; ++i) {
            int num = nums[i];
            if (num != 2) {  // 形如100...000无解，质数里面只有2是这种情况
                int n = num + 1;  // 形如011...111，答案是将最后连续1的最左边1修改为0。num + 1使之变为100...000
                ans[i] = num ^ ((n & -n) >> 1);  // lowbit(x) = (x & -x)得到100...000，然后左移一位得到10...000，再和原数异或完成修改
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,3,5,7 };
    vector<int> actual = o.minBitwiseArray(nums);
    vector<int> expected = { -1,1,4,3 };
    check.checkIntVector(expected, actual);

    nums = { 11,13,31 };
    actual = o.minBitwiseArray(nums);
    expected = { 9,12,15 };
    check.checkIntVector(expected, actual);
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
