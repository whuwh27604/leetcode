/* 将数组划分成若干好子数组的方式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二元数组 nums 。

如果数组中的某个子数组 恰好 只存在 一 个值为 1 的元素，则认为该子数组是一个 好子数组 。

请你统计将数组 nums 划分成若干 好子数组 的方法数，并以整数形式返回。由于数字可能很大，返回其对 109 + 7 取余 之后的结果。

子数组是数组中的一个连续 非空 元素序列。



示例 1：

输入：nums = [0,1,0,0,1]
输出：3
解释：存在 3 种可以将 nums 划分成若干好子数组的方式：
- [0,1] [0,0,1]
- [0,1,0] [0,1]
- [0,1,0,0] [1]
示例 2：

输入：nums = [0,1,0]
输出：1
解释：存在 1 种可以将 nums 划分成若干好子数组的方式：
- [0,1,0]


提示：

1 <= nums.length <= 105
0 <= nums[i] <= 1
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int size = nums.size(), index1 = -1;
        long long goodSubs = 1, mod = 1000000007;

        for (int i = 0; i < size; ++i) {
            if (nums[i] == 1) {
                if (index1 != -1) {
                    goodSubs = goodSubs * (i - index1) % mod;
                }

                index1 = i;
            }
        }

        return index1 == -1 ? 0 : (int)goodSubs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 0,1,0,0,1 };
    check.checkInt(3, o.numberOfGoodSubarraySplits(nums));

    nums = { 0,1,0 };
    check.checkInt(1, o.numberOfGoodSubarraySplits(nums));

    nums = { 0 };
    check.checkInt(0, o.numberOfGoodSubarraySplits(nums));

    nums = { 1 };
    check.checkInt(1, o.numberOfGoodSubarraySplits(nums));

    nums = { 1,1,1 };
    check.checkInt(1, o.numberOfGoodSubarraySplits(nums));

    nums = { 1,0,1,0,0,1,0,0,0,1 };
    check.checkInt(24, o.numberOfGoodSubarraySplits(nums));
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
