/* 绝对差不超过限制的最长连续子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，和一个表示限制的整数 limit，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit 。

如果不存在满足条件的子数组，则返回 0 。

 

示例 1：

输入：nums = [8,2,4,7], limit = 4
输出：2
解释：所有子数组如下：
[8] 最大绝对差 |8-8| = 0 <= 4.
[8,2] 最大绝对差 |8-2| = 6 > 4.
[8,2,4] 最大绝对差 |8-2| = 6 > 4.
[8,2,4,7] 最大绝对差 |8-2| = 6 > 4.
[2] 最大绝对差 |2-2| = 0 <= 4.
[2,4] 最大绝对差 |2-4| = 2 <= 4.
[2,4,7] 最大绝对差 |2-7| = 5 > 4.
[4] 最大绝对差 |4-4| = 0 <= 4.
[4,7] 最大绝对差 |4-7| = 3 <= 4.
[7] 最大绝对差 |7-7| = 0 <= 4.
因此，满足题意的最长子数组的长度为 2 。
示例 2：

输入：nums = [10,1,2,4,7,2], limit = 5
输出：4
解释：满足题意的最长子数组是 [2,4,7,2]，其最大绝对差 |2-7| = 5 <= 5 。
示例 3：

输入：nums = [4,2,2,2,4,4,2,2], limit = 0
输出：3
 

提示：

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multimap<int, int> numsInWindow;
        int i, size = nums.size(), minIndex = 0, maxLen = 0;

        for (i = 0; i < size; ++i) {
            while (!numsInWindow.empty() && nums[i] < numsInWindow.rbegin()->first - limit) {
                minIndex = max(minIndex, numsInWindow.rbegin()->second + 1);
                numsInWindow.erase(--numsInWindow.end());
            }

            while (!numsInWindow.empty() && nums[i] > numsInWindow.begin()->first + limit) {
                minIndex = max(minIndex, numsInWindow.begin()->second + 1);
                numsInWindow.erase(numsInWindow.begin());
            }

            numsInWindow.insert({ nums[i], i });
            maxLen = max(maxLen, i - minIndex + 1);
        }

        return maxLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 8,2,4,7 };
    check.checkInt(2, o.longestSubarray(nums, 4));

    nums = { 10,1,2,4,7,2 };
    check.checkInt(4, o.longestSubarray(nums, 5));

    nums = { 4,2,2,2,4,4,2,2 };
    check.checkInt(3, o.longestSubarray(nums, 0));

    nums = { 4 };
    check.checkInt(1, o.longestSubarray(nums, 1));

    nums = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,11,12,12 };
    check.checkInt(25, o.longestSubarray(nums, 10));
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
