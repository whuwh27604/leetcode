/* 检测相邻递增子数组 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 n 个整数组成的数组 nums ，请你找出 k 的 最大值，使得存在 两个 相邻 且长度为 k 的 严格递增
子数组
。具体来说，需要检查是否存在从下标 a 和 b (a < b) 开始的 两个 子数组，并满足下述全部条件：

这两个子数组 nums[a..a + k - 1] 和 nums[b..b + k - 1] 都是 严格递增 的。
这两个子数组必须是 相邻的，即 b = a + k。
返回 k 的 最大可能 值。

子数组 是数组中的一个连续 非空 的元素序列。



示例 1：

输入：nums = [2,5,7,8,9,2,3,4,3,1]

输出：3

解释：

从下标 2 开始的子数组是 [7, 8, 9]，它是严格递增的。
从下标 5 开始的子数组是 [2, 3, 4]，它也是严格递增的。
这两个子数组是相邻的，因此 3 是满足题目条件的 最大 k 值。
示例 2：

输入：nums = [1,2,3,4,4,4,4,5,6,7]

输出：2

解释：

从下标 0 开始的子数组是 [1, 2]，它是严格递增的。
从下标 2 开始的子数组是 [3, 4]，它也是严格递增的。
这两个子数组是相邻的，因此 2 是满足题目条件的 最大 k 值。


提示：

2 <= nums.length <= 2 * 105
-109 <= nums[i] <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        nums.push_back(INT_MIN);
        int len1 = -1, len2 = -1, start = 0, maxSub = 0;

        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                len1 = len2;
                len2 = i - start;
                start = i;
                maxSub = max(maxSub, len2 / 2);

                if (len1 != -1) {
                    maxSub = max(maxSub, min(len1, len2));
                }
            }
        }

        return maxSub;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,5,7,8,9,2,3,4,3,1 };
    check.checkInt(3, o.maxIncreasingSubarrays(nums));

    nums = { 1,2,3,4,4,4,4,5,6,7 };
    check.checkInt(2, o.maxIncreasingSubarrays(nums));
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
