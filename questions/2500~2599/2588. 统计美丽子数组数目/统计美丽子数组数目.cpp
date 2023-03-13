/* 统计美丽子数组数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组nums 。每次操作中，你可以：

选择两个满足 0 <= i, j < nums.length 的不同下标 i 和 j 。
选择一个非负整数 k ，满足 nums[i] 和 nums[j] 在二进制下的第 k 位（下标编号从 0 开始）是 1 。
将 nums[i] 和 nums[j] 都减去 2k 。
如果一个子数组内执行上述操作若干次后，该子数组可以变成一个全为 0 的数组，那么我们称它是一个 美丽 的子数组。

请你返回数组 nums 中 美丽子数组 的数目。

子数组是一个数组中一段连续 非空 的元素序列。



示例 1：

输入：nums = [4,3,1,2,4]
输出：2
解释：nums 中有 2 个美丽子数组：[4,3,1,2,4] 和 [4,3,1,2,4] 。
- 按照下述步骤，我们可以将子数组 [3,1,2] 中所有元素变成 0 ：
  - 选择 [3, 1, 2] 和 k = 1 。将 2 个数字都减去 21 ，子数组变成 [1, 1, 0] 。
  - 选择 [1, 1, 0] 和 k = 0 。将 2 个数字都减去 20 ，子数组变成 [0, 0, 0] 。
- 按照下述步骤，我们可以将子数组 [4,3,1,2,4] 中所有元素变成 0 ：
  - 选择 [4, 3, 1, 2, 4] 和 k = 2 。将 2 个数字都减去 22 ，子数组变成 [0, 3, 1, 2, 0] 。
  - 选择 [0, 3, 1, 2, 0] 和 k = 0 。将 2 个数字都减去 20 ，子数组变成 [0, 2, 0, 2, 0] 。
  - 选择 [0, 2, 0, 2, 0] 和 k = 1 。将 2 个数字都减去 21 ，子数组变成 [0, 0, 0, 0, 0] 。
示例 2：

输入：nums = [1,10,4]
输出：0
解释：nums 中没有任何美丽子数组。


提示：

1 <= nums.length <= 105
0 <= nums[i] <= 106
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long beauties = 0;
        int sum = 0;
        unordered_map<int, int> count;
        count[0] = 1;

        for (int num : nums) {
            sum ^= num;
            beauties += count[sum];
            ++count[sum];
        }

        return beauties;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,1,2,4,4 };
    check.checkLongLong(3, o.beautifulSubarrays(nums));

    nums = { 4,3,1,2,4 };
    check.checkLongLong(2, o.beautifulSubarrays(nums));

    nums = { 1,10,4 };
    check.checkLongLong(0, o.beautifulSubarrays(nums));

    nums = { 5,20,1,5,18,8,15,5,17,4,15,2,5,5,19,8,14,14,6,13 };
    check.checkLongLong(7, o.beautifulSubarrays(nums));
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
