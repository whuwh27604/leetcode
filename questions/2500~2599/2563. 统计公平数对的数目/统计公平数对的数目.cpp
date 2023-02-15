/* 统计公平数对的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、长度为 n 的整数数组 nums ，和两个整数 lower 和 upper ，返回 公平数对的数目 。

如果 (i, j) 数对满足以下情况，则认为它是一个 公平数对 ：

0 <= i < j < n，且
lower <= nums[i] + nums[j] <= upper


示例 1：

输入：nums = [0,1,7,4,4,5], lower = 3, upper = 6
输出：6
解释：共计 6 个公平数对：(0,3)、(0,4)、(0,5)、(1,3)、(1,4) 和 (1,5) 。
示例 2：

输入：nums = [1,7,9,2,5], lower = 11, upper = 11
输出：1
解释：只有单个公平数对：(2,3) 。


提示：

1 <= nums.length <= 105
nums.length == n
-109 <= nums[i] <= 109
-109 <= lower <= upper <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        long long pairs = 0;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < size; ++i) {
            int low = lower - nums[i], high = upper - nums[i];
            int left = distance(nums.begin(), lower_bound(nums.begin(), nums.begin() + i, low));
            if (left < i) {
                int right = min(i, (int)distance(nums.begin(), upper_bound(nums.begin(), nums.begin() + i, high)));
                pairs += ((long long)right - left);
            }
        }

        return pairs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 0,1,7,4,4,5 };
    check.checkLongLong(6, o.countFairPairs(nums, 3, 6));

    nums = { 1,7,9,2,5 };
    check.checkLongLong(1, o.countFairPairs(nums, 11, 11));

    nums = { 0,0,0,0,0,0 };
    check.checkLongLong(15, o.countFairPairs(nums, 0, 0));
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
