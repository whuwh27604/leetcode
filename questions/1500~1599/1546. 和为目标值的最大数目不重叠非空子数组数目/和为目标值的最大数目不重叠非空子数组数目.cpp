/* 和为目标值的最大数目不重叠非空子数组数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 nums 和一个整数 target 。

请你返回 非空不重叠 子数组的最大数目，且每个子数组中数字和都为 target 。

 

示例 1：

输入：nums = [1,1,1,1,1], target = 2
输出：2
解释：总共有 2 个不重叠子数组（加粗数字表示） [1,1,1,1,1] ，它们的和为目标值 2 。
示例 2：

输入：nums = [-1,3,5,1,4,2,-9], target = 6
输出：2
解释：总共有 3 个子数组和为 6 。
([5,1], [4,2], [3,5,1,4,2,-9]) 但只有前 2 个是不重叠的。
示例 3：

输入：nums = [-2,6,6,3,5,4,1,2,8], target = 10
输出：3
示例 4：

输入：nums = [0,0,0], target = 0
输出：3
 

提示：

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
0 <= target <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> presums = { 0 };
        int sum = 0, subarrs = 0;

        for (int num : nums) {
            sum += num;

            if (presums.count(sum - target) == 0) {
                presums.insert(sum);
            }
            else {
                ++subarrs;  // 贪心算法，右端点先结束的子数组优先选择
                sum = 0;
                presums = { 0 };
            }
        }

        return subarrs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,1,1,1,1 };
    check.checkInt(2, o.maxNonOverlapping(nums, 2));

    nums = { -1,3,5,1,4,2,-9 };
    check.checkInt(2, o.maxNonOverlapping(nums, 6));

    nums = { -2,6,6,3,5,4,1,2,8 };
    check.checkInt(3, o.maxNonOverlapping(nums, 10));

    nums = { 0,0,0 };
    check.checkInt(3, o.maxNonOverlapping(nums, 0));

    nums = { -5,5,-4,5,4 };
    check.checkInt(2, o.maxNonOverlapping(nums, 5));

    nums = { 3,0,2,0,2,3,3,0,0,2,1,1,1,0,-1,-1,1,-1,1,0,2,0,0,3,0,0,3,1,0,2,0,-1,2,-1,1,1,3,0,2,3,3,0,0,2,-1,1 };
    check.checkInt(12, o.maxNonOverlapping(nums, 3));

    nums = { 5 };
    check.checkInt(0, o.maxNonOverlapping(nums, 0));

    nums = { 5 };
    check.checkInt(1, o.maxNonOverlapping(nums, 5));
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
