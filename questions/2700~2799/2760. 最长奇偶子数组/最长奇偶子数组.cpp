/* 最长奇偶子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个整数 threshold 。

请你从 nums 的子数组中找出以下标 l 开头、下标 r 结尾 (0 <= l <= r < nums.length) 且满足以下条件的 最长子数组 ：

nums[l] % 2 == 0
对于范围 [l, r - 1] 内的所有下标 i ，nums[i] % 2 != nums[i + 1] % 2
对于范围 [l, r] 内的所有下标 i ，nums[i] <= threshold
以整数形式返回满足题目要求的最长子数组的长度。

注意：子数组 是数组中的一个连续非空元素序列。



示例 1：

输入：nums = [3,2,5,4], threshold = 5
输出：3
解释：在这个示例中，我们选择从 l = 1 开始、到 r = 3 结束的子数组 => [2,5,4] ，满足上述条件。
因此，答案就是这个子数组的长度 3 。可以证明 3 是满足题目要求的最大长度。
示例 2：

输入：nums = [1,2], threshold = 2
输出：1
解释：
在这个示例中，我们选择从 l = 1 开始、到 r = 1 结束的子数组 => [2] 。
该子数组满足上述全部条件。可以证明 1 是满足题目要求的最大长度。
示例 3：

输入：nums = [2,3,4,5], threshold = 4
输出：3
解释：
在这个示例中，我们选择从 l = 0 开始、到 r = 2 结束的子数组 => [2,3,4] 。
该子数组满足上述全部条件。
因此，答案就是这个子数组的长度 3 。可以证明 3 是满足题目要求的最大长度。


提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= threshold <= 100
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int len = 0, maxLen = 0, oddEven = 0;

        for (int num : nums) {
            if (num <= threshold && ((num & 1) ^ oddEven) == 0) {
                ++len;
                oddEven ^= 1;
            }
            else {
                maxLen = max(maxLen, len);

                if (num <= threshold && num % 2 == 0) {
                    len = 1;
                    oddEven = 1;
                }
                else {
                    len = 0;
                    oddEven = 0;
                }
            }
        }

        return max(maxLen, len);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,2,5,4 };
    check.checkInt(3, o.longestAlternatingSubarray(nums, 5));

    nums = { 1,2 };
    check.checkInt(1, o.longestAlternatingSubarray(nums, 2));

    nums = { 2,3,4,5 };
    check.checkInt(3, o.longestAlternatingSubarray(nums, 4));

    nums = { 4,10,3 };
    check.checkInt(2, o.longestAlternatingSubarray(nums, 10));
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
