/* 执行操作后元素的最高频率 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和两个整数 k 和 numOperations 。

你必须对 nums 执行 操作  numOperations 次。每次操作中，你可以：

选择一个下标 i ，它在之前的操作中 没有 被选择过。
将 nums[i] 增加范围 [-k, k] 中的一个整数。
在执行完所有操作以后，请你返回 nums 中出现 频率最高 元素的出现次数。

一个元素 x 的 频率 指的是它在数组中出现的次数。



示例 1：

输入：nums = [1,4,5], k = 1, numOperations = 2

输出：2

解释：

通过以下操作得到最高频率 2 ：

将 nums[1] 增加 0 ，nums 变为 [1, 4, 5] 。
将 nums[2] 增加 -1 ，nums 变为 [1, 4, 4] 。
示例 2：

输入：nums = [5,11,20,20], k = 5, numOperations = 1

输出：2

解释：

通过以下操作得到最高频率 2 ：

将 nums[1] 增加 0 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= k <= 109
0 <= numOperations <= nums.length
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<pair<int, int>> numsCount;

        count(nums, numsCount);

        return max(getMaxFreqWithTarget(numsCount, k, numOperations), getMaxFreqWithoutTarget(numsCount, k, numOperations));
    }

    void count(vector<int>& nums, vector<pair<int, int>>& numsCount) {
        map<int, int> mp;

        for (int num : nums) {
            ++mp[num];
        }

        for (auto& kv : mp) {
            numsCount.push_back({ kv.first,kv.second });
        }
    }

    int getMaxFreqWithTarget(vector<pair<int, int>>& numsCount, int k, int numOperations) {  // 目标众数在nums中
        int size = (int)numsCount.size(), L = 0, R = 0, cnt = 0, maxFreq = 0;

        for (int i = 0; i < size; ++i) {  // 枚举目标众数，滑动左右窗口包含所有符合条件的数
            while (L < i && numsCount[i].first - numsCount[L].first > k) {
                cnt -= numsCount[L++].second;
            }

            while (R < size && numsCount[R].first - numsCount[i].first <= k) {
                cnt += numsCount[R++].second;
            }

            int freq = min(cnt, numsCount[i].second + numOperations);
            maxFreq = max(maxFreq, freq);
        }

        return maxFreq;
    }

    int getMaxFreqWithoutTarget(vector<pair<int, int>>& numsCount, int k, int numOperations) {  // 目标众数不在nums中
        int size = (int)numsCount.size(), R = 0, cnt = 0, maxFreq = 0;

        for (int L = 0; L < size; ++L) {  // 枚举左侧第一个需要改变的数
            int target = numsCount[L].first + k;  // 确定左侧第一个修改的数后，目标众数应该贪心选择尽可能靠右的数。不用担心target出现在nums中，因为这样getMaxFreqWithTarget会得到正确结果

            while (R < size && numsCount[R].first - numsCount[L].first <= k * 2) {  // 滑动窗口到最右侧
                cnt += numsCount[R++].second;
            }

            int freq = min(cnt, numOperations);
            maxFreq = max(maxFreq, freq);

            cnt -= numsCount[L].second;
        }

        return maxFreq;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,4,5 };
    check.checkInt(2, o.maxFrequency(nums, 1, 2));

    nums = { 5,11,20,20 };
    check.checkInt(2, o.maxFrequency(nums, 5, 1));

    nums = { 1,10 };
    check.checkInt(2, o.maxFrequency(nums, 5, 2));

    nums = { 1,2,8,9 };
    check.checkInt(4, o.maxFrequency(nums, 4, 4));
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
