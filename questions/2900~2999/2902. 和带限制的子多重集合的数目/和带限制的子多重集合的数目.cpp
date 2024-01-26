/* 和带限制的子多重集合的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的非负整数数组 nums 和两个整数 l 和 r 。

请你返回 nums 中子多重集合的和在闭区间 [l, r] 之间的 子多重集合的数目 。

由于答案可能很大，请你将答案对 109 + 7 取余后返回。

子多重集合 指的是从数组中选出一些元素构成的 无序 集合，每个元素 x 出现的次数可以是 0, 1, ..., occ[x] 次，其中 occ[x] 是元素 x 在数组中的出现次数。

注意：

如果两个子多重集合中的元素排序后一模一样，那么它们两个是相同的 子多重集合 。
空 集合的和是 0 。


示例 1：

输入：nums = [1,2,2,3], l = 6, r = 6
输出：1
解释：唯一和为 6 的子集合是 {1, 2, 3} 。
示例 2：

输入：nums = [2,1,4,2,7], l = 1, r = 5
输出：7
解释：和在闭区间 [1, 5] 之间的子多重集合为 {1} ，{2} ，{4} ，{2, 2} ，{1, 2} ，{1, 4} 和 {1, 2, 2} 。
示例 3：

输入：nums = [1,2,1,3,5,2], l = 3, r = 5
输出：9
解释：和在闭区间 [3, 5] 之间的子多重集合为 {3} ，{5} ，{1, 2} ，{1, 3} ，{2, 2} ，{2, 3} ，{1, 1, 2} ，{1, 1, 3} 和 {1, 2, 2} 。


提示：

1 <= nums.length <= 2 * 104
0 <= nums[i] <= 2 * 104
nums 的和不超过 2 * 104 。
0 <= l <= r <= 2 * 104
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
		int ans = 0, mod = 1000000007;
		unordered_map<int, int> numsCount;
		vector<int> dp(r + 1, 0);  // dp[i][target]表示使用numsCount中的前i个数，构成和为target的子集数
		dp[0] = 1;  // 空数组得到target==0的方案数

		for (int num : nums) {
			if (num == 0) {
				++dp[0];  // 有数字0时，target==0的方案数加1
			}
			else {
				++numsCount[num];
			}
		}

		for (auto& kv : numsCount) {
			int num = kv.first, count = kv.second;

			for (int target = r; target > 0 && target > r - num; --target) {  // dp使用滚动数组，从大到小遍历区间(r - num, r]之间的数
				int sum = 0, tar = target;

				// 先计算dp[tar]，枚举num的个数[0,1,..,count]
				// 接下来把dp[tar - num, tar - 2 * num, ... tar - count * num]都计算出来，每一次计算可以利用上一个的结果O(1)完成
				for (int i = 0; i < count; ++i) {
					if (tar >= i * num) {
						sum = (sum + dp[tar - i * num]) % mod;
					}
				}

				do {
					if (tar >= num * count) {
						sum = (sum + dp[tar - num * count]) % mod;
					}
					int tmp = dp[tar];
					dp[tar] = sum;
					sum = (sum + mod - tmp) % mod;
					tar -= num;
				} while (tar > 0);
			}
		}

		for (int i = l; i <= r; ++i) {
			ans = (ans + dp[i]) % mod;
		}

		return ans;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,2,3 };
	check.checkInt(1, o.countSubMultisets(nums, 6, 6));

	nums = { 2,1,4,2,7 };
	check.checkInt(7, o.countSubMultisets(nums, 1, 5));

	nums = { 1,2,1,3,5,2 };
	check.checkInt(9, o.countSubMultisets(nums, 3, 5));

	nums = { 1,2,1,3,5,2,0,2,1,4,2,7,0,1,2,2,3,0 };
	check.checkInt(3360, o.countSubMultisets(nums, 0, 100));
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
