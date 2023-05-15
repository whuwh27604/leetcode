/* 最大或值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 k 。每一次操作中，你可以选择一个数并将它乘 2 。

你最多可以进行 k 次操作，请你返回 nums[0] | nums[1] | ... | nums[n - 1] 的最大值。

a | b 表示两个整数 a 和 b 的 按位或 运算。



示例 1：

输入：nums = [12,9], k = 1
输出：30
解释：如果我们对下标为 1 的元素进行操作，新的数组为 [12,18] 。此时得到最优答案为 12 和 18 的按位或运算的结果，也就是 30 。
示例 2：

输入：nums = [8,1,2], k = 2
输出：35
解释：如果我们对下标 0 处的元素进行操作，得到新数组 [32,1,2] 。此时得到最优答案为 32|1|2 = 35 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 15
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int size = nums.size(), sum = 0;
        long long maxSum = 0;
        vector<int> orSums(size + 1, 0);

        for (int i = size - 1; i >= 0; --i) {
            orSums[i] = orSums[i + 1] | nums[i];
        }

        for (int i = 0; i < size; ++i) {
            maxSum = max(maxSum, ((long long)nums[i] << k) | sum | orSums[i + 1]);
            sum |= nums[i];
        }

        return maxSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 12,9 };
    check.checkLongLong(30, o.maximumOr(nums, 1));

    nums = { 8,1,2 };
    check.checkLongLong(35, o.maximumOr(nums, 2));
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
