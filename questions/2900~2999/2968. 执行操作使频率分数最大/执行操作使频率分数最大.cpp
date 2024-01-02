/* 执行操作使频率分数最大.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

你可以对数组执行 至多 k 次操作：

从数组中选择一个下标 i ，将 nums[i] 增加 或者 减少 1 。
最终数组的频率分数定义为数组中众数的 频率 。

请你返回你可以得到的 最大 频率分数。

众数指的是数组中出现次数最多的数。一个元素的频率指的是数组中这个元素的出现次数。



示例 1：

输入：nums = [1,2,6,4], k = 3
输出：3
解释：我们可以对数组执行以下操作：
- 选择 i = 0 ，将 nums[0] 增加 1 。得到数组 [2,2,6,4] 。
- 选择 i = 3 ，将 nums[3] 减少 1 ，得到数组 [2,2,6,3] 。
- 选择 i = 3 ，将 nums[3] 减少 1 ，得到数组 [2,2,6,2] 。
元素 2 是最终数组中的众数，出现了 3 次，所以频率分数为 3 。
3 是所有可行方案里的最大频率分数。
示例 2：

输入：nums = [1,4,4,2,4], k = 0
输出：3
解释：我们无法执行任何操作，所以得到的频率分数是原数组中众数的频率 3 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= k <= 1014
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int size = nums.size(), right = 0, maxFreq = 0;
        vector<long long> presum(size + 1, 0);

        sort(nums.begin(), nums.end());
        getPresum(size, nums, presum);

        for (int left = 0; left < size; ++left) {
            while (right < size && getCost(nums, presum, left, right) <= k) {
                ++right;
            }

            maxFreq = max(maxFreq, right - left);
        }

        return maxFreq;
    }

    void getPresum(int size, vector<int>& nums, vector<long long>& presum) {
        for (int i = 0; i < size; ++i) {
            presum[i + 1] = presum[i] + nums[i];
        }
    }

    long long getCost(vector<int>& nums, vector<long long>& presum, int left, int right) {
        int mid = (left + right) / 2;
        long long cost = nums[mid] * ((long long)mid - left + 1) - (presum[mid + 1] - presum[left]);
        cost += presum[right + 1] - presum[mid] - nums[mid] * ((long long)right - mid + 1);

        return cost;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,6,4 };
    check.checkInt(3, o.maxFrequencyScore(nums, 3));

    nums = { 1,4,4,2,4 };
    check.checkInt(3, o.maxFrequencyScore(nums, 0));
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
