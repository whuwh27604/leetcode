/* 单面值组合的第 K 小金额.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 coins 表示不同面额的硬币，另给你一个整数 k 。

你有无限量的每种面额的硬币。但是，你 不能 组合使用不同面额的硬币。

返回使用这些硬币能制造的 第 kth 小 金额。



示例 1：

输入： coins = [3,6,9], k = 3

输出： 9

解释：给定的硬币可以制造以下金额：
3元硬币产生3的倍数：3, 6, 9, 12, 15等。
6元硬币产生6的倍数：6, 12, 18, 24等。
9元硬币产生9的倍数：9, 18, 27, 36等。
所有硬币合起来可以产生：3, 6, 9, 12, 15等。

示例 2：

输入：coins = [5,2], k = 7

输出：12

解释：给定的硬币可以制造以下金额：
5元硬币产生5的倍数：5, 10, 15, 20等。
2元硬币产生2的倍数：2, 4, 6, 8, 10, 12等。
所有硬币合起来可以产生：2, 4, 5, 6, 8, 10, 12, 14, 15等。



提示：

1 <= coins.length <= 15
1 <= coins[i] <= 25
1 <= k <= 2 * 109
coins 包含两两不同的整数。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
	typedef long long LL;

	long long findKthSmallest(vector<int>& coins, int k) {
		int size = (int)coins.size();
		vector<vector<LL>> lcms(size + 1);

		getLcms(size, coins, lcms);

		return getKth(size, k, coins, lcms);
    }

	LL getKth(int size, int k, vector<int>& coins, vector<vector<LL>>& lcms) {
		LL kth = 0, low = k - 1, high = (LL)(*min_element(coins.begin(), coins.end())) * k;

		while (low <= high) {
			LL mid = (low + high) / 2;
			LL cnt = count(size, mid, lcms);

			if (cnt < k) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
				kth = mid;
			}
		}

		return kth;
	}

	LL count(int size, LL num, vector<vector<LL>>& lcms) {
		LL cnt = 0, sign = 1;

		for (int i = 1; i <= size; ++i) {
			for (LL lcm : lcms[i]) {
				cnt += (num / lcm * sign);
			}

			sign *= -1;
		}

		return cnt;
	}

	void getLcms(int size, vector<int>& coins, vector<vector<LL>>& lcms) {
		int maxMask = (1 << size);

		for (int mask = 1; mask < maxMask; ++mask) {
			pair<int, LL> lcm = getLcm(size, mask, coins);
			lcms[lcm.first].push_back(lcm.second);
		}
	}

	pair<int, LL> getLcm(int size, int mask, vector<int>& coins) {
		LL lcm = 1;
		int cnt = 0;

		for (int i = 0, bit = 1; i < size; ++i, bit <<= 1) {
			if ((bit & mask) != 0) {
				++cnt;
				lcm = lcm * coins[i] / gcd(lcm, coins[i]);
			}
		}

		return { cnt, lcm };
	}

	LL gcd(LL x, LL y) {
		return (y == 0) ? x : gcd(y, x % y);
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> coins = { 3,6,9 };
	check.checkLongLong(9, o.findKthSmallest(coins, 3));

	coins = { 5,2 };
	check.checkLongLong(12, o.findKthSmallest(coins, 7));

	coins = { 5,2,3,6,9 };
	check.checkLongLong(27, o.findKthSmallest(coins, 20));

	coins = { 1,2,3,4,5,6,7,10,11,12,13,17,20,21,22 };
	check.checkLongLong(2000000000, o.findKthSmallest(coins, 2000000000));

	coins = { 6,7,10,11,12,13,17,20,21,22,23,24,25,18,19 };
	check.checkLongLong(3690356556, o.findKthSmallest(coins, 2000000000));

	coins = { 6,7,10,11,12,13,17,20,21,22,23,24,25,18,19 };
	check.checkLongLong(3667576572, o.findKthSmallest(coins, 1987654321));
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
