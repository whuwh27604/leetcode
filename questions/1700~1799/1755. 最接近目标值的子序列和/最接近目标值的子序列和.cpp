/* 最接近目标值的子序列和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个目标值 goal 。

你需要从 nums 中选出一个子序列，使子序列元素总和最接近 goal 。也就是说，如果子序列元素和为 sum ，你需要 最小化绝对差 abs(sum - goal) 。

返回 abs(sum - goal) 可能的 最小值 。

注意，数组的子序列是通过移除原始数组中的某些元素（可能全部或无）而形成的数组。

 

示例 1：

输入：nums = [5,-7,3,5], goal = 6
输出：0
解释：选择整个数组作为选出的子序列，元素和为 6 。
子序列和与目标值相等，所以绝对差为 0 。
示例 2：

输入：nums = [7,-9,15,-2], goal = -5
输出：1
解释：选出子序列 [7,-9,-2] ，元素和为 -4 。
绝对差为 abs(-4 - (-5)) = abs(1) = 1 ，是可能的最小值。
示例 3：

输入：nums = [1,2,3], goal = -7
输出：7
 

提示：

1 <= nums.length <= 40
-107 <= nums[i] <= 107
-109 <= goal <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/closest-subsequence-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int size = nums.size(), half = size / 2, minDiff = abs(goal);  // 子集为空
        vector<int> sums1(1 << half, 0), sums2(1 << (size - half), 0);

        getSums(nums, 0, sums1);  // 子集在前半部分
        sort(sums1.begin(), sums1.end());
        auto iter = lower_bound(sums1.begin(), sums1.end(), goal);
        if (iter != sums1.end()) {
            minDiff = min(minDiff, *iter - goal);
        }
        if (iter != sums1.begin()) {
            minDiff = min(minDiff, goal - *(--iter));
        }

        getSums(nums, half, sums2);  // 子集在后半部分
        sort(sums2.begin(), sums2.end());
        iter = lower_bound(sums2.begin(), sums2.end(), goal);
        if (iter != sums2.end()) {
            minDiff = min(minDiff, *iter - goal);
        }
        if (iter != sums2.begin()) {
            minDiff = min(minDiff, goal - *(--iter));
        }

        return min(minDiff, getMinDiff(sums1, sums2, goal));  // 子集在前后子集各取一部分合并
    }

    void getSums(vector<int>& nums, int start, vector<int>& sums) {
        int i, j, bit, size = sums.size();

        for (i = 1; i < size; ++i) {
            for (j = 0, bit = 1; bit < size; ++j, bit <<= 1) {
                if ((i & bit) != 0) {
                    sums[i] = sums[i ^ bit] + nums[j + start];
                    break;
                }
            }
        }
    }

    int getMinDiff(vector<int>& nums1, vector<int>& nums2, int goal) {
        int left = 0, right = nums2.size() - 1, size = nums1.size(), minDiff = INT_MAX;

        while (left < size && right >= 0) {
            int sum = nums1[left] + nums2[right];
            minDiff = min(minDiff, abs(sum - goal));

            if (sum == goal) {
                break;
            }
            else if (sum > goal) {
                --right;
            }
            else {
                ++left;
            }
        }

        return minDiff;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,-7,3,5 };
    check.checkInt(0, o.minAbsDifference(nums, 6));

    nums = { 7,-9,15,-2 };
    check.checkInt(1, o.minAbsDifference(nums, -5));

    nums = { 1,2,3 };
    check.checkInt(7, o.minAbsDifference(nums, -7));

    nums = { -2 };
    check.checkInt(0, o.minAbsDifference(nums, 0));

    nums = { 7,-9,15,-2,5,-7,3,5,1,2,3,21,-23,-25,36 };
    check.checkInt(0, o.minAbsDifference(nums, 10));

    nums = { 7,-9,15,-2,5,-7,3,5,1,2,3,21,-23,-25,36,50,-55,60,-78,99,7,-9,15,-2,5,-7,3,5,1,2,3,21,-23,-25,36,50,-55,60,-78,99 };
    check.checkInt(0, o.minAbsDifference(nums, -20));
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
