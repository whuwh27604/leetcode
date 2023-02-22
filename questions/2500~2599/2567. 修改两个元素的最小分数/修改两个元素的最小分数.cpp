/* 修改两个元素的最小分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。

nums 的 最小 得分是满足 0 <= i < j < nums.length 的 |nums[i] - nums[j]| 的最小值。
nums的 最大 得分是满足 0 <= i < j < nums.length 的 |nums[i] - nums[j]| 的最大值。
nums 的分数是 最大 得分与 最小 得分的和。
我们的目标是最小化 nums 的分数。你 最多 可以修改 nums 中 2 个元素的值。

请你返回修改 nums 中 至多两个 元素的值后，可以得到的 最小分数 。

|x| 表示 x 的绝对值。



示例 1：

输入：nums = [1,4,3]
输出：0
解释：将 nums[1] 和 nums[2] 的值改为 1 ，nums 变为 [1,1,1] 。|nums[i] - nums[j]| 的值永远为 0 ，所以我们返回 0 + 0 = 0 。
示例 2：

输入：nums = [1,4,7,8,5]
输出：3
解释：
将 nums[0] 和 nums[1] 的值变为 6 ，nums 变为 [6,6,7,8,5] 。
最小得分是 i = 0 且 j = 1 时得到的 |nums[i] - nums[j]| = |6 - 6| = 0 。
最大得分是 i = 3 且 j = 4 时得到的 |nums[i] - nums[j]| = |8 - 5| = 3 。
最大得分与最小得分之和为 3 。这是最优答案。


提示：

3 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int size = nums.size();

        sort(nums.begin(), nums.end());

        return min({ nums[size - 1] - nums[2], nums[size - 2] - nums[1], nums[size - 3] - nums[0] });
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,4,3 };
    check.checkInt(0, o.minimizeSum(nums));

    nums = { 1,4,7,8,5 };
    check.checkInt(3, o.minimizeSum(nums));

    nums = { 31,25,72,79,74,65 };
    check.checkInt(14, o.minimizeSum(nums));
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
