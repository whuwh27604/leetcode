/* 使数组和小于等于 x 的最少时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度相等下标从 0 开始的整数数组 nums1 和 nums2 。每一秒，对于所有下标 0 <= i < nums1.length ，nums1[i] 的值都增加 nums2[i] 。操作 完成后 ，你可以进行如下操作：

选择任一满足 0 <= i < nums1.length 的下标 i ，并使 nums1[i] = 0 。
同时给你一个整数 x 。

请你返回使 nums1 中所有元素之和 小于等于 x 所需要的 最少 时间，如果无法实现，那么返回 -1 。



示例 1：

输入：nums1 = [1,2,3], nums2 = [1,2,3], x = 4
输出：3
解释：
第 1 秒，我们对 i = 0 进行操作，得到 nums1 = [0,2+2,3+3] = [0,4,6] 。
第 2 秒，我们对 i = 1 进行操作，得到 nums1 = [0+1,0,6+3] = [1,0,9] 。
第 3 秒，我们对 i = 2 进行操作，得到 nums1 = [1+1,0+2,0] = [2,2,0] 。
现在 nums1 的和为 4 。不存在更少次数的操作，所以我们返回 3 。
示例 2：

输入：nums1 = [1,2,3], nums2 = [3,3,3], x = 4
输出：-1
解释：不管如何操作，nums1 的和总是会超过 x 。


提示：

1 <= nums1.length <= 103
1 <= nums1[i] <= 103
0 <= nums2[i] <= 103
nums1.length == nums2.length
0 <= x <= 106
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        int sum1 = 0, sum2 = 0;
        vector<pair<int, int>> numbers(n);
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int i = 0; i < n; ++i) {
            sum1 += nums1[i];
            sum2 += nums2[i];
            numbers[i] = { nums2[i],nums1[i] };
        }

        sort(numbers.begin(), numbers.end());

        /* 1、对numbers[i]，多次操作和最后一次操作的效果是一样的，所以一个number最多操作一次，总共最多操作n次
           2、假设操作t次，被操作的数是[i1,i2...it]，那么最多可以减少多少呢？
              nums1[i1] + nums1[i2] + ... + nums1[it]是固定要减少的
              x1 * nums2[i1] + x2 * nums2[i2] + ... + xt * nums2[it]是变动部分，[x1,x2...xt]是[1,2...t]的一个排列，即操作这t个数的顺序，显然要将较大的x对应到较大的nums2才能够取到最大值
           3、至此，问题转变为假设操作t次，应该操作哪t个数呢？使用动态规划求解，令dp[i][t]表示前i个数操作t次可以取得的最大值，递推求解 */
        dp[0][1] = numbers[0].first + numbers[0].second;

        for (int i = 1; i < n; ++i) {
            for (int t = 1; t <= i + 1; ++t) {
                dp[i][t] = dp[i - 1][t];  // 不选第i个数
                dp[i][t] = max(dp[i][t], dp[i - 1][t - 1] + t * numbers[i].first + numbers[i].second);  // 选择第i个数
            }
        }

        for (int t = 0; t <= n; ++t) {
            if (sum1 + t * sum2 - dp[n - 1][t] <= x) {
                return t;
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 1,2,3 };
    vector<int> nums2 = { 1,2,3 };
    check.checkInt(3, o.minimumTime(nums1, nums2, 4));

    nums1 = { 1,2,3 };
    nums2 = { 3,3,3 };
    check.checkInt(-1, o.minimumTime(nums1, nums2, 4));

    nums1 = { 8,2,3 };
    nums2 = { 1,4,2 };
    check.checkInt(0, o.minimumTime(nums1, nums2, 13));
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
