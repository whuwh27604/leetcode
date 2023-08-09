/* 判断是否能拆分数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的数组 nums 和一个整数 m 。请你判断能否执行一系列操作，将数组拆分成 n 个 非空 数组。

在每一步操作中，你可以选择一个 长度至少为 2 的现有数组（之前步骤的结果） 并将其拆分成 2 个子数组，而得到的 每个 子数组，至少 需要满足以下条件之一：

子数组的长度为 1 ，或者
子数组元素之和 大于或等于  m 。
如果你可以将给定数组拆分成 n 个满足要求的数组，返回 true ；否则，返回 false 。

注意：子数组是数组中的一个连续非空元素序列。



示例 1：

输入：nums = [2, 2, 1], m = 4
输出：true
解释：
第 1 步，将数组 nums 拆分成 [2, 2] 和 [1] 。
第 2 步，将数组 [2, 2] 拆分成 [2] 和 [2] 。
因此，答案为 true 。
示例 2：

输入：nums = [2, 1, 3], m = 5
输出：false
解释：
存在两种不同的拆分方法：
第 1 种，将数组 nums 拆分成 [2, 1] 和 [3] 。
第 2 种，将数组 nums 拆分成 [2] 和 [1, 3] 。
然而，这两种方法都不满足题意。因此，答案为 false 。
示例 3：

输入：nums = [2, 3, 3, 2, 3], m = 6
输出：true
解释：
第 1 步，将数组 nums 拆分成 [2, 3, 3, 2] 和 [3] 。
第 2 步，将数组 [2, 3, 3, 2] 拆分成 [2, 3, 3] 和 [2] 。
第 3 步，将数组 [2, 3, 3] 拆分成 [2] 和 [3, 3] 。
第 4 步，将数组 [3, 3] 拆分成 [3] 和 [3] 。
因此，答案为 true 。


提示：

1 <= n == nums.length <= 100
1 <= nums[i] <= 100
1 <= m <= 200
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();

        if (n <= 2) {
            return true;
        }

        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] + nums[i] >= m) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,2,1 };
    check.checkBool(true, o.canSplitArray(nums, 4));

    nums = { 2,3,3,2,3 };
    check.checkBool(true, o.canSplitArray(nums, 6));

    nums = { 2,1,3 };
    check.checkBool(false, o.canSplitArray(nums, 5));
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
