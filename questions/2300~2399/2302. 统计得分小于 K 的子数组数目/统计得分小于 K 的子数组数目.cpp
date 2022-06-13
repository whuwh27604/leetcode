/* 统计得分小于 K 的子数组数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个数字的 分数 定义为数组之和 乘以 数组的长度。

比方说，[1, 2, 3, 4, 5] 的分数为 (1 + 2 + 3 + 4 + 5) * 5 = 75 。
给你一个正整数数组 nums 和一个整数 k ，请你返回 nums 中分数 严格小于 k 的 非空整数子数组数目。

子数组 是数组中的一个连续元素序列。

 

示例 1：

输入：nums = [2,1,4,3,5], k = 10
输出：6
解释：
有 6 个子数组的分数小于 10 ：
- [2] 分数为 2 * 1 = 2 。
- [1] 分数为 1 * 1 = 1 。
- [4] 分数为 4 * 1 = 4 。
- [3] 分数为 3 * 1 = 3 。
- [5] 分数为 5 * 1 = 5 。
- [2,1] 分数为 (2 + 1) * 2 = 6 。
注意，子数组 [1,4] 和 [4,3,5] 不符合要求，因为它们的分数分别为 10 和 36，但我们要求子数组的分数严格小于 10 。
示例 2：

输入：nums = [1,1,1], k = 5
输出：5
解释：
除了 [1,1,1] 以外每个子数组分数都小于 5 。
[1,1,1] 分数为 (1 + 1 + 1) * 3 = 9 ，大于 5 。
所以总共有 5 个子数组得分小于 5 。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= k <= 1015

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-subarrays-with-score-less-than-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int left, right = 0, size = nums.size();
        long long sum = 0, count = 0;

        for (left = 0; left < size; ++left) {
            while (right < size && (sum + nums[right]) * ((long long)right - left + 1) < k) {
                sum += nums[right++];
            }

            count += ((long long)right - left);
            sum -= nums[left];
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,1,4,3,5 };
    check.checkLongLong(6, o.countSubarrays(nums, 10));

    nums = { 1,1,1 };
    check.checkLongLong(5, o.countSubarrays(nums, 5));

    nums = { 1,2,3,4,5,4,3,2,1,1,2,3,4,5,4,3,2,1,1,2,3,4,5,4,3,2,1,1,2,3,4,5,4,3,2,1,1,2,3,4,5,4,3,2,1,1,2,3,4,5,4,3,2,1 };
    check.checkLongLong(156, o.countSubarrays(nums, 30));

    nums = { 3 };
    check.checkLongLong(0, o.countSubarrays(nums, 3));

    nums = { 3 };
    check.checkLongLong(1, o.countSubarrays(nums, 4));
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
