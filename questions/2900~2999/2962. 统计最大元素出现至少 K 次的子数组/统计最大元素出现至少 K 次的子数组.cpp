/* 统计最大元素出现至少 K 次的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个 正整数 k 。

请你统计有多少满足 「 nums 中的 最大 元素」至少出现 k 次的子数组，并返回满足这一条件的子数组的数目。

子数组是数组中的一个连续元素序列。



示例 1：

输入：nums = [1,3,2,3,3], k = 2
输出：6
解释：包含元素 3 至少 2 次的子数组为：[1,3,2,3]、[1,3,2,3,3]、[3,2,3]、[3,2,3,3]、[2,3,3] 和 [3,3] 。
示例 2：

输入：nums = [1,4,2,1], k = 3
输出：0
解释：没有子数组包含元素 4 至少 3 次。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int size = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> indices;

        for (int i = 0; i < size; ++i) {
            if (nums[i] == maxNum) {
                indices.push_back(i);
            }
        }

        int len = indices.size();
        if (len < k) {
            return 0;
        }

        int i = 0, j = k - 1, prev = -1;
        long long subarrays = 0;

        while (j < len) {
            subarrays += ((long long)indices[i] - prev) * ((long long)size - indices[j]);
            prev = indices[i];
            ++i, ++j;
        }

        return subarrays;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,2,3,3 };
    check.checkLongLong(6, o.countSubarrays(nums, 2));

    nums = { 1,4,2,1 };
    check.checkLongLong(0, o.countSubarrays(nums, 3));

    nums = { 37,20,38,66,34,38,9,41,1,14,25,63,8,12,66,66,60,12,35,27,16,38,12,66,38,36,59,54,66,54,66,48,59,66,34,11,50,66,42,51,53,66,31,24,66,44,66,1,66,66,29,54 };
    check.checkLongLong(594, o.countSubarrays(nums, 5));
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
