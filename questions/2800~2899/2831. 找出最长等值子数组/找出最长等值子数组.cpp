/* 找出最长等值子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

如果子数组中所有元素都相等，则认为子数组是一个 等值子数组 。注意，空数组是 等值子数组 。

从 nums 中删除最多 k 个元素后，返回可能的最长等值子数组的长度。

子数组 是数组中一个连续且可能为空的元素序列。



示例 1：

输入：nums = [1,3,2,3,1,3], k = 3
输出：3
解释：最优的方案是删除下标 2 和下标 4 的元素。
删除后，nums 等于 [1, 3, 3, 3] 。
最长等值子数组从 i = 1 开始到 j = 3 结束，长度等于 3 。
可以证明无法创建更长的等值子数组。
示例 2：

输入：nums = [1,1,2,2,1,1], k = 2
输出：4
解释：最优的方案是删除下标 2 和下标 3 的元素。
删除后，nums 等于 [1, 1, 1, 1] 。
数组自身就是等值子数组，长度等于 4 。
可以证明无法创建更长的等值子数组。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= nums.length
0 <= k <= nums.length
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int size = nums.size(), maxLen = 0;
        unordered_map<int, vector<int>> indices;

        for (int i = 0; i < size; ++i) {
            indices[nums[i]].push_back(i);
        }

        for (auto& kv : indices) {
            maxLen = max(maxLen, getMaxLen(kv.second, k));
        }

        return maxLen;
    }

    int getMaxLen(vector<int>& indices, int k) {
        int size = indices.size(), left = 0, right = 0, maxLen = 0;

        for (; left < size; ++left) {
            while (right < size && (indices[right] - indices[left]) - (right - left) <= k) {
                ++right;
            }

            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,2,3,1,3 };
    check.checkInt(3, o.longestEqualSubarray(nums, 3));

    nums = { 1,1,2,2,1,1 };
    check.checkInt(4, o.longestEqualSubarray(nums, 2));
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
