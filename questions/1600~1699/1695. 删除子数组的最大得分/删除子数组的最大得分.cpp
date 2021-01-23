/* 删除子数组的最大得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。删除子数组的 得分 就是子数组各元素之 和 。

返回 只删除一个 子数组可获得的 最大得分 。

如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r] ，那么它就是 a 的一个子数组。

 

示例 1：

输入：nums = [4,2,4,5,6]
输出：17
解释：最优子数组是 [2,4,5,6]
示例 2：

输入：nums = [5,2,1,2,5,2,1,2,5]
输出：8
解释：最优子数组是 [5,2,1] 或 [1,2,5]
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-erasure-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> numsInWindow(10001, 0);
        int left = 0, right, size = nums.size(), sum = 0, maxSum = 0;

        for (right = 0; right < size; ++right) {
            int num = nums[right];

            while (numsInWindow[num] == 1) {
                sum -= nums[left];
                numsInWindow[nums[left++]] = 0;
            }

            numsInWindow[num] = 1;
            sum += num;
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,2,4,5,6 };
    check.checkInt(17, o.maximumUniqueSubarray(nums));

    nums = { 5,2,1,2,5,2,1,2,5 };
    check.checkInt(8, o.maximumUniqueSubarray(nums));

    nums = { 5 };
    check.checkInt(5, o.maximumUniqueSubarray(nums));
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
