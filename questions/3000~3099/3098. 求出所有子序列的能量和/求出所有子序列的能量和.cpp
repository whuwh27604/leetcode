/* 求出所有子序列的能量和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums 和一个 正 整数 k 。

一个子序列的 能量 定义为子序列中 任意 两个元素的差值绝对值的 最小值 。

请你返回 nums 中长度 等于 k 的 所有 子序列的 能量和 。

由于答案可能会很大，将答案对 109 + 7 取余 后返回。



示例 1：

输入：nums = [1,2,3,4], k = 3

输出：4

解释：

nums 中总共有 4 个长度为 3 的子序列：[1,2,3] ，[1,3,4] ，[1,2,4] 和 [2,3,4] 。能量和为 |2 - 3| + |3 - 4| + |2 - 1| + |3 - 4| = 4 。

示例 2：

输入：nums = [2,2], k = 2

输出：0

解释：

nums 中唯一一个长度为 2 的子序列是 [2,2] 。能量和为 |2 - 2| = 0 。

示例 3：

输入：nums = [4,3,-1], k = 2

输出：10

解释：

nums 总共有 3 个长度为 2 的子序列：[4,3] ，[4,-1] 和 [3,-1] 。能量和为 |4 - 3| + |4 - (-1)| + |3 - (-1)| = 10 。



提示：

2 <= n == nums.length <= 50
-108 <= nums[i] <= 108
2 <= k <= n
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
		int n = nums.size(), powerSum = 0;
		vector<vector<int>> dp(n + 2, vector<int>(k - 1, 0));
		vector<vector<int>> sum(n + 2, vector<int>(k - 1, 0));

		sort(nums.begin(), nums.end());

		// 枚举nums[i]和nums[j]，下标从1开始，假设他们俩是子序列中差值绝对值最小的，构成一个power
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				int power = nums[j - 1] - nums[i - 1];
				dpLeft(i, k, power, nums, dp, sum);  // 看看左右两边有哪些数可以加入到这个子序列
				dpRight(j, k, power, nums, dp, sum);
				powerSum = (powerSum + getPowerSum(k, i, j, power, sum)) % mod;
			}
		}

		return powerSum;
    }

	void dpLeft(int left, int k, int power, vector<int>& nums, vector<vector<int>>& dp, vector<vector<int>>& sum) {
		int prev = 0;
		dp[0][0] = 1, sum[0][0] = 1;  // 选择0个数的子序列个数是1

		// dp[last][len]表示子序列最后一个数是last，长度为len，可以加入nums[i]，nums[j]构成一个合法子序列的个数
		// sum[last][len]表示nums[0, last]中，长度为len，可以加入nums[i]，nums[j]构成一个合法子序列的总个数
		for (int last = 1; last < left; ++last) {
			dp[last][0] = 1, sum[last][0] = 1;  // 选择0个数的子序列个数是1

			for (int len = 1; len <= k - 2; ++len) {
				while (prev + 1 < last && nums[last - 1] - nums[prev] > power) {
					++prev;  // 将prev移动到最后一个last、prev差值大于power的位置
				}

				if (nums[left - 1] - nums[last - 1] > power) {  // 如果last和left差值大于power，那么last可以被选择
					dp[last][len] = sum[prev][len - 1];  // 选上它，然后还要从nums[0, prev]选择len - 1个数
				}
				else {
					dp[last][len] = 0;  // 否则last不可选，dp值为0
				}

				sum[last][len] = (sum[last - 1][len] + dp[last][len]) % mod;  // sum[last][len]实质上是dp[last][len]的前缀和
			}
		}
	}

	void dpRight(int right, int k, int power, vector<int>& nums, vector<vector<int>>& dp, vector<vector<int>>& sum) {
		int n = nums.size();
		int prev = n + 1;
		dp[n + 1][0] = 1, sum[n + 1][0] = 1;

		for (int last = n; last > right; --last) {
			dp[last][0] = 1, sum[last][0] = 1;

			for (int len = 1; len <= k - 2; ++len) {
				while (prev - 1 > last && nums[prev - 2] - nums[last - 1] >= power) {
					--prev;  // 右端在nums[j]后面，可以等于power
				}

				if (nums[last - 1] - nums[right - 1] >= power) {
					dp[last][len] = sum[prev][len - 1];
				}
				else {
					dp[last][len] = 0;
				}

				sum[last][len] = (sum[last + 1][len] + dp[last][len]) % mod;
			}
		}
	}

	int getPowerSum(int k, int left, int right, int power, vector<vector<int>>& sum) {
		int powerSum = 0;

		// 枚举左右两边的子序列长度，左边len，右边k - 2 - len，再加上left和right，正好构成一个k长度的子序列
		for (int len = 0; len <= k - 2; ++len) {
			powerSum = (powerSum + (long long)sum[left - 1][len] * sum[right + 1][k - 2 - len] % mod * power % mod) % mod;
		}

		return powerSum;
	}

	int mod = 1000000007;
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,3,4 };
	check.checkInt(4, o.sumOfPowers(nums, 3));

	nums = { 2,2 };
	check.checkInt(0, o.sumOfPowers(nums, 2));

	nums = { 4,3,-1 };
	check.checkInt(10, o.sumOfPowers(nums, 2));

	nums = { 4,3,-1,1,2,3,4,2,2 };
	check.checkInt(61, o.sumOfPowers(nums, 3));

	nums = { 1,1,1 };
	check.checkInt(0, o.sumOfPowers(nums, 3));

	nums = { 16461744,48674538,99629027,57381059,52261311,88796826,48963946,88349752,30978348,979976,67206553,92468646,38938991,3592455,77742032,27587216,41871286 };
	check.checkInt(735615748, o.sumOfPowers(nums, 12));

	nums = { -24,-921,119,-291,-65,-628,372,274,962,-592,-10,67,-977,85,-294,349,-119,-846,-959,-79,-877,833,857,44,826,-295,-855,554,-999,759,-653,-423,-599,-928 };
	check.checkInt(990202285, o.sumOfPowers(nums, 19));
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
