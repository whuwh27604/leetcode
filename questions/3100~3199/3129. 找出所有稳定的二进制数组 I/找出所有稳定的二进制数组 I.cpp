/* 找出所有稳定的二进制数组 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你 3 个正整数 zero ，one 和 limit 。

一个
二进制数组
 arr 如果满足以下条件，那么我们称它是 稳定的 ：

0 在 arr 中出现次数 恰好 为 zero 。
1 在 arr 中出现次数 恰好 为 one 。
arr 中每个长度超过 limit 的
子数组
 都 同时 包含 0 和 1 。
请你返回 稳定 二进制数组的 总 数目。

由于答案可能很大，将它对 109 + 7 取余 后返回。



示例 1：

输入：zero = 1, one = 1, limit = 2

输出：2

解释：

两个稳定的二进制数组为 [1,0] 和 [0,1] ，两个数组都有一个 0 和一个 1 ，且没有子数组长度大于 2 。

示例 2：

输入：zero = 1, one = 2, limit = 1

输出：1

解释：

唯一稳定的二进制数组是 [1,0,1] 。

二进制数组 [1,1,0] 和 [0,1,1] 都有长度为 2 且元素全都相同的子数组，所以它们不稳定。

示例 3：

输入：zero = 3, one = 3, limit = 2

输出：14

解释：

所有稳定的二进制数组包括 [0,0,1,0,1,1] ，[0,0,1,1,0,1] ，[0,1,0,0,1,1] ，[0,1,0,1,0,1] ，[0,1,0,1,1,0] ，[0,1,1,0,0,1] ，[0,1,1,0,1,0] ，[1,0,0,1,0,1] ，[1,0,0,1,1,0] ，[1,0,1,0,0,1] ，[1,0,1,0,1,0] ，[1,0,1,1,0,0] ，[1,1,0,0,1,0] 和 [1,1,0,1,0,0] 。



提示：

1 <= zero, one, limit <= 200
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
		vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));  // dp0[i][j]表示i个0，j个1，以0结尾的数组个数
		vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));  // dp1[i][j]表示i个0，j个1，以1结尾的数组个数
		vector<int> dp0Sum(zero + 1, 0), dp1Sum(one + 1, 0);  // dp0Sum[i]表示i个0时，最后limit个dp0[i][j]之和
		int mod = 1000000007;

		for (int j = 1; j <= one; ++j) {
			if (j <= limit) {
				dp1[0][j] = 1;
			}
			dp1Sum[j] = dp1[0][j];
		}

		for (int i = 1; i <= zero; ++i) {
			if (i <= limit) {
				dp0[i][0] = 1;
			}
			dp0Sum[i] = dp0[i][0];

			for (int j = 1; j <= one; ++j) {
				dp0[i][j] = dp1Sum[j];  // dp0[i][j] = dp1[i - 1][j] + dp1[i - 2][j] + ... + dp1[i - limit][j]
				dp1[i][j] = dp0Sum[i];  // dp1[i][j] = dp0[i][j - 1] + dp0[i][j - 2] + ... + dp0[i][j - limit]
				dp0Sum[i] = (dp0Sum[i] + dp0[i][j]) % mod;
				if (j >= limit) {
					dp0Sum[i] = (dp0Sum[i] + mod - dp0[i][j - limit]) % mod;
				}
				dp1Sum[j] = (dp1Sum[j] + dp1[i][j]) % mod;
				if (i >= limit) {
					dp1Sum[j] = (dp1Sum[j] + mod - dp1[i - limit][j]) % mod;
				}
			}
		}

		return (dp0[zero][one] + dp1[zero][one]) % mod;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(2, o.numberOfStableArrays(1, 1, 2));
	check.checkInt(1, o.numberOfStableArrays(1, 2, 1));
	check.checkInt(14, o.numberOfStableArrays(3, 3, 2));
	check.checkInt(591164091, o.numberOfStableArrays(1000, 1000, 500));
	check.checkInt(72475738, o.numberOfStableArrays(1000, 1000, 1000));
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
