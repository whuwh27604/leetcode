/* 舒适的湿度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
力扣嘉年华为了确保更舒适的游览环境条件，在会场的各处设置了湿度调节装置，这些调节装置受控于总控室中的一台控制器。 控制器中已经预设了一些调节指令，整数数组operate[i] 表示第 i 条指令增加空气湿度的大小。现在你可以将任意数量的指令修改为降低湿度（变化的数值不变），以确保湿度尽可能的适宜：

控制器会选择 一段连续的指令 ，从而进行湿度调节的操作；
这段指令最终对湿度影响的绝对值，即为当前操作的「不适宜度」
在控制器所有可能的操作中，最大 的「不适宜度」即为「整体不适宜度」
请返回在所有修改指令的方案中，可以得到的 最小 「整体不适宜度」。

示例 1：

输入：operate = [5,3,7]

输出：8

解释：对于方案 2 的 [5,3,-7] 操作指令 [5],[3],[-7] 的「不适宜度」分别为 5,3,7 操作指令 [5,3],[3,-7] 的「不适宜度」分别为 8,4 操作指令 [5,3,-7] 的「不适宜度」为 1， 因此对于方案 [5,3,-7]的「整体不适宜度」为 8，其余方案的「整体不适宜度」均不小于 8，如下表所示：image.png

示例 2：

输入：operate = [20,10]

输出：20

提示：

1 <= operate.length <= 1000
1 <= operate[i] <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
	int unSuitability(vector<int>& operate) {
		int inf = INT_MAX / 2, ans = inf;
		int maxNum = *max_element(operate.begin(), operate.end()), maxDiff = maxNum * 2;
		vector<int> dp(maxDiff + 1, inf);
		dp[0] = 0;  // 预置一个presum = maxPresum = minPresum = 0

		// 对nums[0,n)，整体不适宜度 = max(abs(sum[i,j])) = maxPresum - minPresum, ans = min(整体不适宜度) ∈（对每个nums[i]变换符号）
		// 答案最大到不了 2 * maxNum，因为当presum大于maxNum时，下一个数就选择变为负数
		// 令dp[i][diff]表示对于nums[0, i]，maxPresum - presum = diff 时，maxPresum - minPresum的最小值

		for (int num : operate) {
			vector<int> tmp(maxDiff + 1, inf);

			for (int diff = 0; diff <= maxDiff; ++diff) {
				if (diff + num <= maxDiff) {
					tmp[diff + num] = min(tmp[diff + num], max(dp[diff], diff + num));
				}

				if (num <= diff) {
					tmp[diff - num] = min(tmp[diff - num], dp[diff]);
				}
				else {
					tmp[0] = min(tmp[0], dp[diff] + num - diff);
				}
			}

			dp = tmp;
		}

		for (int v : dp) {
			ans = min(ans, v);
		}

		return ans;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> operate = { 5,3,7 };
	check.checkInt(8, o.unSuitability(operate));

	operate = { 20,10 };
	check.checkInt(20, o.unSuitability(operate));

	operate = { 10,10,8,10,6,10,8,10 };
	check.checkInt(18, o.unSuitability(operate));

	operate = { 1,3 };
	check.checkInt(3, o.unSuitability(operate));

	operate = { 1,2,3 };
	check.checkInt(3, o.unSuitability(operate));

	operate = { 6,2,3,9 };
	check.checkInt(9, o.unSuitability(operate));

	operate = { 6,8,4,5 };
	check.checkInt(9, o.unSuitability(operate));

	operate = { 1,2,4,6,7,7,3 };
	check.checkInt(7, o.unSuitability(operate));

	operate = { 8,6,5,1,2,2,3,6 };
	check.checkInt(8, o.unSuitability(operate));
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
