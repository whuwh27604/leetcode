/* 和至少为 K 的最短子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k ，找出 nums 中和至少为 k 的 最短非空子数组 ，并返回该子数组的长度。如果不存在这样的 子数组 ，返回 -1 。

子数组 是数组中 连续 的一部分。

 

示例 1：

输入：nums = [1], k = 1
输出：1
示例 2：

输入：nums = [1,2], k = 4
输出：-1
示例 3：

输入：nums = [2,-1,2], k = 3
输出：3
 

提示：

1 <= nums.length <= 105
-105 <= nums[i] <= 105
1 <= k <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int size = nums.size(), minLen = INT_MAX;
        vector<long long> presums(size + 1, 0);
        deque<int> indices;

        for (int i = 0; i < size; ++i) {
            presums[i + 1] = presums[i] + nums[i];
        }

        for (int i = 0; i <= size; ++i) {
            while (!indices.empty() && presums[i] - presums[indices.front()] >= k) {
                minLen = min(minLen, i - indices.front());
                indices.pop_front();
            }

            while (!indices.empty() && presums[i] <= presums[indices.back()]) {
                indices.pop_back();
            }

            indices.push_back(i);
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1 };
    check.checkInt(1, o.shortestSubarray(nums, 1));

    nums = { 1,2 };
    check.checkInt(-1, o.shortestSubarray(nums, 4));

    nums = { 2,-1,2 };
    check.checkInt(3, o.shortestSubarray(nums, 3));

    nums = { 48,99,37,4,-31 };
    check.checkInt(2, o.shortestSubarray(nums, 140));

    nums = { 1,2,-4,5 };
    check.checkInt(-1, o.shortestSubarray(nums, 6));

    nums = { 84,-37,32,40,95 };
    check.checkInt(3, o.shortestSubarray(nums, 167));
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
