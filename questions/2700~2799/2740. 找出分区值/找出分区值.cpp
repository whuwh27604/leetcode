/* 找出分区值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 正 整数数组 nums 。

将 nums 分成两个数组：nums1 和 nums2 ，并满足下述条件：

数组 nums 中的每个元素都属于数组 nums1 或数组 nums2 。
两个数组都 非空 。
分区值 最小 。
分区值的计算方法是 |max(nums1) - min(nums2)| 。

其中，max(nums1) 表示数组 nums1 中的最大元素，min(nums2) 表示数组 nums2 中的最小元素。

返回表示分区值的整数。



示例 1：

输入：nums = [1,3,2,4]
输出：1
解释：可以将数组 nums 分成 nums1 = [1,2] 和 nums2 = [3,4] 。
- 数组 nums1 的最大值等于 2 。
- 数组 nums2 的最小值等于 3 。
分区值等于 |2 - 3| = 1 。
可以证明 1 是所有分区方案的最小值。
示例 2：

输入：nums = [100,1,10]
输出：9
解释：可以将数组 nums 分成 nums1 = [10] 和 nums2 = [100,1] 。
- 数组 nums1 的最大值等于 10 。
- 数组 nums2 的最小值等于 1 。
分区值等于 |10 - 1| = 9 。
可以证明 9 是所有分区方案的最小值。


提示：

2 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int size = nums.size(), value = INT_MAX;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < size; ++i) {
            value = min(value, nums[i] - nums[i - 1]);
        }

        return value;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,2,4 };
    check.checkInt(1, o.findValueOfPartition(nums));

    nums = { 100,1,10 };
    check.checkInt(9, o.findValueOfPartition(nums));
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
