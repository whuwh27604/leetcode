/* 统计按位或能得到最大值的子集数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，请你找出 nums 子集 按位或 可能得到的 最大值 ，并返回按位或能得到最大值的 不同非空子集的数目 。

如果数组 a 可以由数组 b 删除一些元素（或不删除）得到，则认为数组 a 是数组 b 的一个 子集 。如果选中的元素下标位置不一样，则认为两个子集 不同 。

对数组 a 执行 按位或 ，结果等于 a[0] OR a[1] OR ... OR a[a.length - 1]（下标从 0 开始）。

 

示例 1：

输入：nums = [3,1]
输出：2
解释：子集按位或能得到的最大值是 3 。有 2 个子集按位或可以得到 3 ：
- [3]
- [3,1]
示例 2：

输入：nums = [2,2,2]
输出：7
解释：[2,2,2] 的所有非空子集的按位或都可以得到 2 。总共有 23 - 1 = 7 个子集。
示例 3：

输入：nums = [3,2,1,5]
输出：6
解释：子集按位或可能的最大值是 7 。有 6 个子集按位或可以得到 7 ：
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]
 

提示：

1 <= nums.length <= 16
1 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-maximum-bitwise-or-subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int i, bit, subset, size = nums.size(), maxOr = 0, count = 0;
        vector<int> dp(1 << size, 0);

        for (int num : nums) {
            maxOr |= num;
        }

        for (subset = 0; subset < (1 << size); ++subset) {
            for (i = 0, bit = 1; i < size; ++i, bit <<= 1) {
                if ((subset & bit) != 0) {
                    dp[subset] = dp[subset ^ bit] | nums[i];

                    if (dp[subset] == maxOr) {
                        ++count;
                    }

                    break;
                }
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,1 };
    check.checkInt(2, o.countMaxOrSubsets(nums));

    nums = { 2,2,2 };
    check.checkInt(7, o.countMaxOrSubsets(nums));

    nums = { 3,2,1,5 };
    check.checkInt(6, o.countMaxOrSubsets(nums));

    nums = { 2 };
    check.checkInt(1, o.countMaxOrSubsets(nums));

    nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    check.checkInt(32297, o.countMaxOrSubsets(nums));
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
