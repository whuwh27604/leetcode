/* 长度最小的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

示例: 

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right, size = nums.size();
        long long minLen = LLONG_MAX, sum = 0;

        for (right = 0; right < size; right++) {
            sum += nums[right];
            if (sum < s) {
                continue;
            }

            while ((sum - nums[left]) >= s) {
                sum -= nums[left];
                left++;
            }

            int len = right - left;
            minLen = (minLen < len) ? minLen : len;
        }

        return (minLen == LLONG_MAX) ? 0 : (int)(minLen + 1);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = {};
    check.checkInt(0, o.minSubArrayLen(0, nums));

    nums = { 1 };
    check.checkInt(0, o.minSubArrayLen(2, nums));

    nums = { 1 };
    check.checkInt(1, o.minSubArrayLen(1, nums));

    nums = { 1,2,3 };
    check.checkInt(3, o.minSubArrayLen(6, nums));

    nums = { 1,2,3,4 };
    check.checkInt(2, o.minSubArrayLen(6, nums));

    nums = { 1,2,3,4,5,6 };
    check.checkInt(1, o.minSubArrayLen(6, nums));

    nums = { 2,3,1,2,4,3 };
    check.checkInt(2, o.minSubArrayLen(7, nums));

    nums = { 1,2,3,4,5 };
    check.checkInt(3, o.minSubArrayLen(11, nums));
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
