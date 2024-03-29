/* 求出所有子序列的能量和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums 和一个 正 整数 k 。

一个整数数组的 能量 定义为和 等于 k 的子序列的数目。

请你返回 nums 中所有子序列的 能量和 。

由于答案可能很大，请你将它对 109 + 7 取余 后返回。



示例 1：

输入： nums = [1,2,3], k = 3

输出： 6

解释：

总共有 5 个能量不为 0 的子序列：

子序列 [1,2,3] 有 2 个和为 3 的子序列：[1,2,3] 和 [1,2,3] 。
子序列 [1,2,3] 有 1 个和为 3 的子序列：[1,2,3] 。
子序列 [1,2,3] 有 1 个和为 3 的子序列：[1,2,3] 。
子序列 [1,2,3] 有 1 个和为 3 的子序列：[1,2,3] 。
子序列 [1,2,3] 有 1 个和为 3 的子序列：[1,2,3] 。
所以答案为 2 + 1 + 1 + 1 + 1 = 6 。

示例 2：

输入： nums = [2,3,3], k = 5

输出： 4

解释：

总共有 3 个能量不为 0 的子序列：

子序列 [2,3,3] 有 2 个子序列和为 5 ：[2,3,3] 和 [2,3,3] 。
子序列 [2,3,3] 有 1 个子序列和为 5 ：[2,3,3] 。
子序列 [2,3,3] 有 1 个子序列和为 5 ：[2,3,3] 。
所以答案为 2 + 1 + 1 = 4 。

示例 3：

输入： nums = [1,2,3], k = 7

输出： 0

解释：不存在和为 7 的子序列，所以 nums 的能量和为 0 。



提示：

1 <= n <= 100
1 <= nums[i] <= 104
1 <= k <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
		int n = nums.size(), mod = 1000000007;
		long long ans = 0;
		// dp[i][c][s]表示nums的前i个数中取c个数，构成和为s的子序列数
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, 0)));
		dp[0][0][0] = 1;

		for (int i = 1; i <= n; ++i) {
			int num = nums[i - 1];
			dp[i][0][0] = 1;

			for (int c = 1; c <= i; ++c) {
				for (int s = 1; s <= k; ++s) {
					dp[i][c][s] = dp[i - 1][c][s];  // 不选择第i个数
					if (num <= s) {
						dp[i][c][s] = (dp[i][c][s] + dp[i - 1][c - 1][s - num]) % mod;  // 选择第i个数
					}
				}
			}
		}

		for (int c = 1; c <= n; ++c) {
			ans = (ans + dp[n][c][k] * fastPower(2, n - c, mod)) % mod;
		}

		return (int)ans;
    }

	long long fastPower(long long x, int n, long long mod) {
		long long ans = 1;

		while (n > 0) {
			if ((n & 1) == 1) {
				ans = ans * x % mod;
			}

			x = x * x % mod;
			n >>= 1;
		}

		return ans;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,3 };
	check.checkInt(6, o.sumOfPower(nums, 3));

	nums = { 2,3,3 };
	check.checkInt(4, o.sumOfPower(nums, 5));

	nums = { 1,2,3 };
	check.checkInt(0, o.sumOfPower(nums, 7));

	nums = { 1,2,3,2,3,3,1,2,3,2,3,3,1,2,3,2,3,3,1,2,3,2,3,3,1,2,3,2,3,3,1,2,3,2,3,3,1,2,3,2,3,3,1,2,3,2,3,3,1,2,3,2,3,3,1,2,3,2,3,3,1,2,3,2,3,3,1,2,3,2,3,3,1,2,3,2,3,3,1,2,3,2,3,3,1,2,3,2,3,3 };
	check.checkInt(336898689, o.sumOfPower(nums, 5));

	nums = { 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3 };
	check.checkInt(882517099, o.sumOfPower(nums, 3));
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
