/* 不间断子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。nums 的一个子数组如果满足以下条件，那么它是 不间断 的：

i，i + 1 ，...，j  表示子数组中的下标。对于所有满足 i <= i1, i2 <= j 的下标对，都有 0 <= |nums[i1] - nums[i2]| <= 2 。
请你返回 不间断 子数组的总数目。

子数组是一个数组中一段连续 非空 的元素序列。



示例 1：

输入：nums = [5,4,2,4]
输出：8
解释：
大小为 1 的不间断子数组：[5], [4], [2], [4] 。
大小为 2 的不间断子数组：[5,4], [4,2], [2,4] 。
大小为 3 的不间断子数组：[4,2,4] 。
没有大小为 4 的不间断子数组。
不间断子数组的总数目为 4 + 3 + 1 = 8 。
除了这些以外，没有别的不间断子数组。
示例 2：

输入：nums = [1,2,3]
输出：6
解释：
大小为 1 的不间断子数组：[1], [2], [3] 。
大小为 2 的不间断子数组：[1,2], [2,3] 。
大小为 3 的不间断子数组：[1,2,3] 。
不间断子数组的总数目为 3 + 2 + 1 = 6 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include <map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long subs = 0;
        int size = nums.size(), left = 0, right = 0;
        map<int, int> count;

        for (; left < size; ++left) {
            while (right < size && (count.empty() || max(nums[right], count.rbegin()->first) - min(nums[right], count.begin()->first) <= 2)) {
                ++count[nums[right++]];
            }

            int len = right - left;
            subs += len;

            if (--count[nums[left]] == 0) {
                count.erase(nums[left]);
            }
        }

        return subs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,4,2,4 };
    check.checkLongLong(8, o.continuousSubarrays(nums));

    nums = { 1,2,3 };
    check.checkLongLong(6, o.continuousSubarrays(nums));

    nums = { 3 };
    check.checkLongLong(1, o.continuousSubarrays(nums));

    nums = { 5,4,2,4,1,2,3 };
    check.checkLongLong(14, o.continuousSubarrays(nums));

    nums = { 5,4,2,4,1,2,3,5,4,2,4,1,2,3,5,4,2,4,1,2,3,5,4,2,4,1,2,3,5,4,2,4,1,2,3 };
    check.checkLongLong(78, o.continuousSubarrays(nums));
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
