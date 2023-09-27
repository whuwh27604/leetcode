/* 完全子集的最大元素和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 1 开始、由 n 个整数组成的数组。

如果一组数字中每对元素的乘积都是一个完全平方数，则称这组数字是一个 完全集 。

下标集 {1, 2, ..., n} 的子集可以表示为 {i1, i2, ..., ik}，我们定义对应该子集的 元素和 为 nums[i1] + nums[i2] + ... + nums[ik] 。

返回下标集 {1, 2, ..., n} 的 完全子集 所能取到的 最大元素和 。

完全平方数是指可以表示为一个整数和其自身相乘的数。



示例 1：

输入：nums = [8,7,3,5,7,2,4,9]
输出：16
解释：除了由单个下标组成的子集之外，还有两个下标集的完全子集：{1,4} 和 {2,8} 。
与下标 1 和 4 对应的元素和等于 nums[1] + nums[4] = 8 + 5 = 13 。
与下标 2 和 8 对应的元素和等于 nums[2] + nums[8] = 7 + 9 = 16 。
因此，下标集的完全子集可以取到的最大元素和为 16 。
示例 2：

输入：nums = [5,10,3,10,1,13,7,9,4]
输出：19
解释：除了由单个下标组成的子集之外，还有四个下标集的完全子集：{1,4}、{1,9}、{2,8}、{4,9} 和 {1,4,9} 。
与下标 1 和 4 对应的元素和等于 nums[1] + nums[4] = 5 + 10 = 15 。
与下标 1 和 9 对应的元素和等于 nums[1] + nums[9] = 5 + 4 = 9 。
与下标 2 和 8 对应的元素和等于 nums[2] + nums[8] = 10 + 9 = 19 。
与下标 4 和 9 对应的元素和等于 nums[4] + nums[9] = 10 + 4 = 14 。
与下标 1、4 和 9 对应的元素和等于 nums[1] + nums[4] + nums[9] = 5 + 10 + 4 = 19 。
因此，下标集的完全子集可以取到的最大元素和为 19 。


提示：

1 <= n == nums.length <= 104
1 <= nums[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        long long maxSum = 0;

        /* 对于一个索引idx = remainder * factor * factor，如果remainder = idx / (factor * factor)相同，那么这个索引可以放在同一组
           算法复杂度是(1 + 1/4 + 1/9 + ...) * n，该极数收敛于Π^2/6 */
        for (int remainder = 1; remainder <= n; ++remainder) {  // 枚举剩余因子remainder
            long long sum = 0;

            for (int factor = 1; factor <= 100; ++factor) {  // 枚举所有可以放在这一组的索引
                int idx = remainder * factor * factor - 1;
                if (idx >= n) {
                    break;
                }

                sum += nums[idx];
            }

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 8,7,3,5,7,2,4,9 };
    check.checkLongLong(16, o.maximumSum(nums));

    nums = { 5,10,3,10,1,13,7,9,4 };
    check.checkLongLong(19, o.maximumSum(nums));

    nums = { 1,100,100,1 };
    check.checkLongLong(100, o.maximumSum(nums));
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
