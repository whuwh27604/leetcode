/* 对数组执行操作使平方和最大.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个 正 整数 k 。

你可以对数组执行以下操作 任意次 ：

选择两个互不相同的下标 i 和 j ，同时 将 nums[i] 更新为 (nums[i] AND nums[j]) 且将 nums[j] 更新为 (nums[i] OR nums[j]) ，OR 表示按位 或 运算，AND 表示按位 与 运算。
你需要从最终的数组里选择 k 个元素，并计算它们的 平方 之和。

请你返回你可以得到的 最大 平方和。

由于答案可能会很大，将答案对 109 + 7 取余 后返回。



示例 1：

输入：nums = [2,6,5,8], k = 2
输出：261
解释：我们可以对数组执行以下操作：
- 选择 i = 0 和 j = 3 ，同时将 nums[0] 变为 (2 AND 8) = 0 且 nums[3] 变为 (2 OR 8) = 10 ，结果数组为 nums = [0,6,5,10] 。
- 选择 i = 2 和 j = 3 ，同时将 nums[2] 变为 (5 AND 10) = 0 且 nums[3] 变为 (5 OR 10) = 15 ，结果数组为 nums = [0,6,0,15] 。
从最终数组里选择元素 15 和 6 ，平方和为 152 + 62 = 261 。
261 是可以得到的最大结果。
示例 2：

输入：nums = [4,5,4,7], k = 3
输出：90
解释：不需要执行任何操作。
选择元素 7 ，5 和 4 ，平方和为 72 + 52 + 42 = 90 。
90 是可以得到的最大结果。


提示：

1 <= k <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long ans = 0, mod = 1000000007;
        vector<int> bitCount(31, 0);

        for (int num : nums) {
            for (int i = 0, bit = 1; i < 31; ++i, bit <<= 1) {
                if ((num & bit) != 0) {
                    ++bitCount[i];
                }
            }
        }

        for (int i = 0; i < k; ++i) {
            long long num = 0;

            for (int i = 0, bit = 1; i < 31; ++i, bit <<= 1) {
                if (bitCount[i] != 0) {
                    --bitCount[i];
                    num |= bit;
                }
            }

            ans = (ans + num * num) % mod;
        }

        return (int)ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,6,5,8 };
    check.checkInt(261, o.maxSum(nums, 2));

    nums = { 4,5,4,7 };
    check.checkInt(90, o.maxSum(nums, 3));
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
