/* 最小正和子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和 两个 整数 l 和 r。你的任务是找到一个长度在 l 和 r 之间（包含）且和大于 0 的 子数组 的 最小 和。

返回满足条件的子数组的 最小 和。如果不存在这样的子数组，则返回 -1。

子数组 是数组中的一个连续 非空 元素序列。



示例 1：

输入： nums = [3, -2, 1, 4], l = 2, r = 3

输出： 1

解释：

长度在 l = 2 和 r = 3 之间且和大于 0 的子数组有：

[3, -2] 和为 1
[1, 4] 和为 5
[3, -2, 1] 和为 2
[-2, 1, 4] 和为 3
其中，子数组 [3, -2] 的和为 1，是所有正和中最小的。因此，答案为 1。

示例 2：

输入： nums = [-2, 2, -3, 1], l = 2, r = 3

输出： -1

解释：

不存在长度在 l 和 r 之间且和大于 0 的子数组。因此，答案为 -1。

示例 3：

输入： nums = [1, 2, 3, 4], l = 2, r = 4

输出： 3

解释：

子数组 [1, 2] 的长度为 2，和为 3，是所有正和中最小的。因此，答案为 3。



提示：

1 <= nums.length <= 100
1 <= l <= r <= nums.length
-1000 <= nums[i] <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int size = (int)nums.size(), minSum = INT_MAX;

        for (int i = 0; i < size; ++i) {
            int sum = 0;

            for (int j = i; j < size; ++j) {
                int len = j - i + 1;
                sum += nums[j];

                if (len >= l && len <= r && sum > 0) {
                    minSum = min(minSum, sum);
                }
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,-2,1,4 };
    check.checkInt(1, o.minimumSumSubarray(nums, 2, 3));

    nums = { -2,2,-3,1 };
    check.checkInt(-1, o.minimumSumSubarray(nums, 2, 3));

    nums = { 1,2,3,4 };
    check.checkInt(3, o.minimumSumSubarray(nums, 2, 4));
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
