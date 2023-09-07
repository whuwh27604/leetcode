/* 几乎唯一子数组的最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和两个正整数 m 和 k 。

请你返回 nums 中长度为 k 的 几乎唯一 子数组的 最大和 ，如果不存在几乎唯一子数组，请你返回 0 。

如果 nums 的一个子数组有至少 m 个互不相同的元素，我们称它是 几乎唯一 子数组。

子数组指的是一个数组中一段连续 非空 的元素序列。



示例 1：

输入：nums = [2,6,7,3,1,7], m = 3, k = 4
输出：18
解释：总共有 3 个长度为 k = 4 的几乎唯一子数组。分别为 [2, 6, 7, 3] ，[6, 7, 3, 1] 和 [7, 3, 1, 7] 。这些子数组中，和最大的是 [2, 6, 7, 3] ，和为 18 。
示例 2：

输入：nums = [5,9,9,2,4,5,4], m = 1, k = 3
输出：23
解释：总共有 5 个长度为 k = 3 的几乎唯一子数组。分别为 [5, 9, 9] ，[9, 9, 2] ，[9, 2, 4] ，[2, 4, 5] 和 [4, 5, 4] 。这些子数组中，和最大的是 [5, 9, 9] ，和为 23 。
示例 3：

输入：nums = [1,2,1,2,1,2,1], m = 3, k = 3
输出：0
解释：输入数组中不存在长度为 k = 3 的子数组含有至少  m = 3 个互不相同元素的子数组。所以不存在几乎唯一子数组，最大和为 0 。


提示：

1 <= nums.length <= 2 * 104
1 <= m <= k <= nums.length
1 <= nums[i] <= 109
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int size = nums.size(), left = 0, right = 0;
        long long sum = 0, ans = 0;
        unordered_map<int, int> count;

        for (; right < size; ++right) {
            int num = nums[right];
            ++count[num];
            sum += num;

            if (right - left + 1 < k) {
                continue;
            }
            else if (right - left + 1 > k) {
                num = nums[left++];
                sum -= num;
                if (--count[num] == 0) {
                    count.erase(num);
                }
            }

            if ((int)count.size() >= m) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,6,7,3,1,7 };
    check.checkLongLong(18, o.maxSum(nums, 3, 4));

    nums = { 5,9,9,2,4,5,4 };
    check.checkLongLong(23, o.maxSum(nums, 1, 3));

    nums = { 1,2,1,2,1,2,1 };
    check.checkLongLong(0, o.maxSum(nums, 3, 3));
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
