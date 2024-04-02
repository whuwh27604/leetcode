/* K 个不相交子数组的最大能量值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 下标从 0 开始的整数数组 nums 和一个 正奇数 整数 k 。

x 个子数组的能量值定义为 strength = sum[1] * x - sum[2] * (x - 1) + sum[3] * (x - 2) - sum[4] * (x - 3) + ... + sum[x] * 1 ，其中 sum[i] 是第 i 个子数组的和。更正式的，能量值是满足 1 <= i <= x 的所有 i 对应的 (-1)i+1 * sum[i] * (x - i + 1) 之和。

你需要在 nums 中选择 k 个 不相交子数组 ，使得 能量值最大 。

请你返回可以得到的 最大能量值 。

注意，选出来的所有子数组 不 需要覆盖整个数组。



示例 1：

输入：nums = [1,2,3,-1,2], k = 3
输出：22
解释：选择 3 个子数组的最好方式是选择：nums[0..2] ，nums[3..3] 和 nums[4..4] 。能量值为 (1 + 2 + 3) * 3 - (-1) * 2 + 2 * 1 = 22 。
示例 2：

输入：nums = [12,-2,-2,-2,-2], k = 5
输出：64
解释：唯一一种选 5 个不相交子数组的方案是：nums[0..0] ，nums[1..1] ，nums[2..2] ，nums[3..3] 和 nums[4..4] 。能量值为 12 * 5 - (-2) * 4 + (-2) * 3 - (-2) * 2 + (-2) * 1 = 64 。
示例 3：

输入：nums = [-1,-2,-3], k = 1
输出：-1
解释：选择 1 个子数组的最优方案是：nums[0..0] 。能量值为 -1 。


提示：

1 <= n <= 104
-109 <= nums[i] <= 109
1 <= k <= n
1 <= n * k <= 106
k 是奇数。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
		int n = nums.size(), sign = 1;
		vector<long long> presum(n + 1, 0);
		vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, LLONG_MIN));  // 初始化为最小值
		dp[0] = vector<long long>(n + 1, 0);  // 不选数组的strength是0

		for (int i = 1; i <= n; ++i) {
			presum[i] = presum[i - 1] + nums[i - 1];
		}

		/* 题目要求表达式sum[1] * k - sum[2] * (k - 1) + sum[3] * (k - 2) - sum[4] * (k - 3) + ... + sum[k] * 1的最大值
		   数组下标从1开始，dp[c][i]表示从nums[1, i]取c个子数组，构成表达式前c项的最大值
		   对于nums[i]，1、如果不选择这个数，那么dp[c][i] = dp[c][i - 1]，即从nums[1, i - 1]选择c个子数组构成最大值；
		   2、如果选择这个数，那么枚举最后一个子数组nums[j, i]，dp[c][i] = max(dp[c - 1][j - 1] + sum[j, i] * coef)
		   即最后一个数组是nums[j, i]，它的和sum[j, i] = presum[i] - presum[j - 1]
		   系数coef = (k - c + 1) * ((-1) ^ (c + 1))
		   然后还需要从数组nums[1, j - 1]选择c - 1个数组，构成最大值。
		   直接枚举j的复杂度是O(n * k * n)，需要优化这一过程：
		   dp[c][i] = max(dp[c - 1][j - 1] + sum[j, i] * coef)
		            = max(dp[c - 1][j - 1] + (presum[i] - presum[j - 1]) * coef)
					= max(dp[c - 1][j - 1] - presum[j - 1] * coef + presum[i] * coef)
		   对于位置i来说，presum[i] * coef是固定值，所以只需要求得max(dp[c - 1][j - 1] - presum[j - 1] * coef)的最大值
		   该值可以在遍历i的过程中进行维护，从而避免对每个i都再枚举一次所有j。 */

		for (int c = 1; c <= k; ++c) {
			int coef = (k - c + 1) * sign;
			long long mx = LLONG_MIN;

			for (int i = c; i <= n - (k - c); ++i) {  // 要取c个数组，那么至少要有c个数字；后端要留下(k - c)个数字才能构成完整的原始表达式
				mx = max(mx, dp[c - 1][i - 1] - coef * presum[i - 1]);
				dp[c][i] = max(dp[c][i - 1], coef * presum[i] + mx);
			}

			sign *= -1;
		}

		return dp[k][n];
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,3,-1,2 };
	check.checkLongLong(22, o.maximumStrength(nums, 3));

	nums = { 12,-2,-2,-2,-2 };
	check.checkLongLong(64, o.maximumStrength(nums, 5));

	nums = { -1,-2,-3 };
	check.checkLongLong(-1, o.maximumStrength(nums, 1));
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
