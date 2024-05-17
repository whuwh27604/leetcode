/* 大数组元素的乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个整数 x 的 强数组 指的是满足和为 x 的二的幂的最短有序数组。比方说，11 的强数组为 [1, 2, 8] 。

我们将每一个正整数 i （即1，2，3等等）的 强数组 连接得到数组 big_nums ，big_nums 开始部分为 [1, 2, 1, 2, 4, 1, 4, 2, 4, 1, 2, 4, 8, ...] 。

给你一个二维整数数组 queries ，其中 queries[i] = [fromi, toi, modi] ，你需要计算 (big_nums[fromi] * big_nums[fromi + 1] * ... * big_nums[toi]) % modi 。

请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。



示例 1：

输入：queries = [[1,3,7]]

输出：[4]

解释：

只有一个查询。

big_nums[1..3] = [2,1,2] 。它们的乘积为 4 ，4 对 7 取余数得到 4 。

示例 2：

输入：queries = [[2,5,3],[7,7,4]]

输出：[2,2]

解释：

有两个查询。

第一个查询：big_nums[2..5] = [1,2,4,1] 。它们的乘积为 8 ，8 对 3 取余数得到 2 。

第二个查询：big_nums[7] = 2 ，2 对 4 取余数得到 2 。



提示：

1 <= queries.length <= 500
queries[i].length == 3
0 <= queries[i][0] <= queries[i][1] <= 1015
1 <= queries[i][2] <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

typedef long long LL;

class Solution {
public:
	vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
		int size = (int)queries.size();
		vector<int> ans(size);

		for (int i = 0; i < size; ++i) {
			LL from = queries[i][0], to = queries[i][1], mod = queries[i][2];
			LL last = findLastNum(to);
			LL count = countEachBit(last - 1) + countLastNum(last, to + 1 - countBits(last - 1));
			if (from != 0) {
				last = findLastNum(--from);
				count -= (countEachBit(last - 1) + countLastNum(last, from + 1 - countBits(last - 1)));
			}
			ans[i] = (int)fastPower(2, count, mod);  // 统计出幂次后，最后计算结果
		}

		return ans;
	}

	LL countBits(LL num) {  // 统计[1, ... , num]一共有多少个bit1
		LL count = 0;

		for (LL bit = 1, left = num; bit <= num; bit <<= 1) {
			left >>= 1;
			LL right = (num & (bit - 1)) + 1;
			count += left * bit;  // 左边取[0, left)，右边可以取[0, bit - 1]
			if ((num & bit) != 0) {
				count += right;  // 如果num的bit位是1，那么左边可以取left，右边可以取[0, num & (bit - 1)]
			}
		}

		return count;
	}

	LL countEachBit(LL num) {
		LL count = 0;

		// 将乘法转为加法，最后再计算2的幂：
		// bit0 = 1, bit1 = 2, ...biti = 2 ^ i ,
		// bit0 ^ cnt0 * bit1 ^ cnt1 ... * biti ^ cnti = 2 ^ (0 * cnt0 + 1 * cnt1 + ... + i * cnti)
		for (LL i = 0, bit = 1, left = num; bit <= num; ++i, bit <<= 1) {
			left >>= 1;
			LL right = (num & (bit - 1)) + 1;
			LL cnt = left * bit;
			if ((num & bit) != 0) {
				cnt += right;
			}
			count += cnt * i;
		}

		return count;
	}

	LL countLastNum(LL num, LL bits) {  // 最后一个数可能不完全，只计算前bits个
		LL count = 0;

		for (LL i = 0, bit = 1; bits != 0; ++i, bit <<= 1) {
			if ((num & bit) != 0) {
				count += i;
				--bits;
			}
		}

		return count;
	}

	LL findLastNum(LL index) {
		LL count = index + 1, low = 1, high = count, last = 0;

		while (low <= high) {
			LL mid = (low + high) / 2;
			if (countBits(mid) >= count) {
				last = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}

		return last;
	}

	LL fastPower(LL x, LL n, LL mod) {
		LL ans = 1;

		while (n > 0) {
			if ((n & 1) == 1) {
				ans = ans * x % mod;
			}

			x = x * x % mod;
			n >>= 1;
		}

		return ans % mod;  // mod可能为1
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<long long>> queries = { {1,3,7} };
	vector<int> actual = o.findProductsOfElements(queries);
	vector<int> expected = { 4 };
	check.checkIntVector(expected, actual);

	queries = { {2,5,3},{7,7,4} };
	actual = o.findProductsOfElements(queries);
	expected = { 2,2 };
	check.checkIntVector(expected, actual);

	queries = { {9,9,1} };
	actual = o.findProductsOfElements(queries);
	expected = { 0 };
	check.checkIntVector(expected, actual);

	queries = { {7,1000000000000000,19191} };
	actual = o.findProductsOfElements(queries);
	expected = { 18484 };
	check.checkIntVector(expected, actual);

	queries = getLongLongVectorVector("./testcase1.txt");
	actual = o.findProductsOfElements(queries);
	expected = getIntVector("./expected1.txt");
	check.checkIntVector(expected, actual);
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
