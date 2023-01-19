/* 统计好子数组的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k ，请你返回 nums 中 好 子数组的数目。

一个子数组 arr 如果有 至少 k 对下标 (i, j) 满足 i < j 且 arr[i] == arr[j] ，那么称它是一个 好 子数组。

子数组 是原数组中一段连续 非空 的元素序列。



示例 1：

输入：nums = [1,1,1,1,1], k = 10
输出：1
解释：唯一的好子数组是这个数组本身。
示例 2：

输入：nums = [3,1,4,3,2,2,4], k = 2
输出：4
解释：总共有 4 个不同的好子数组：
- [3,1,4,3,2,2] 有 2 对。
- [3,1,4,3,2,2,4] 有 3 对。
- [1,4,3,2,2,4] 有 2 对。
- [4,3,2,2,4] 有 2 对。


提示：

1 <= nums.length <= 105
1 <= nums[i], k <= 109
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, long long> count;
        int size = nums.size(), left = 0, right = 0;
        long long goods = 0, subarrs = 0;

        for (int right = 0; right < size; ++right) {
            int num = nums[right];
            long long cnt = ++count[num];
            goods += (cnt * (cnt - 1) / 2 - (cnt > 2 ? (cnt - 1) * (cnt - 2) / 2 : 0));

            while (goods >= k) {
                num = nums[left++];
                cnt = count[num]--;
                goods -= (cnt * (cnt - 1) / 2 - (cnt > 2 ? (cnt - 1) * (cnt - 2) / 2 : 0));
            }

            subarrs += left;
        }

        return subarrs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,1,1,1,1 };
    check.checkLongLong(1, o.countGood(nums, 10));

    nums = { 3,1,4,3,2,2,4 };
    check.checkLongLong(4, o.countGood(nums, 2));
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
