/* 到达第 K 级台阶的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你有一个 非负 整数 k 。有一个无限长度的台阶，最低 一层编号为 0 。

虎老师有一个整数 jump ，一开始值为 0 。虎老师从台阶 1 开始，虎老师可以使用 任意 次操作，目标是到达第 k 级台阶。假设虎老师位于台阶 i ，一次 操作 中，虎老师可以：

向下走一级到 i - 1 ，但该操作 不能 连续使用，如果在台阶第 0 级也不能使用。
向上走到台阶 i + 2jump 处，然后 jump 变为 jump + 1 。
请你返回虎老师到达台阶 k 处的总方案数。

注意 ，虎老师可能到达台阶 k 处后，通过一些操作重新回到台阶 k 处，这视为不同的方案。



示例 1：

输入：k = 0

输出：2

解释：

2 种到达台阶 0 的方案为：

虎老师从台阶 1 开始。
执行第一种操作，从台阶 1 向下走到台阶 0 。
虎老师从台阶 1 开始。
执行第一种操作，从台阶 1 向下走到台阶 0 。
执行第二种操作，向上走 20 级台阶到台阶 1 。
执行第一种操作，从台阶 1 向下走到台阶 0 。
示例 2：

输入：k = 1

输出：4

解释：

4 种到达台阶 1 的方案为：

虎老师从台阶 1 开始，已经到达台阶 1 。
虎老师从台阶 1 开始。
执行第一种操作，从台阶 1 向下走到台阶 0 。
执行第二种操作，向上走 20 级台阶到台阶 1 。
虎老师从台阶 1 开始。
执行第二种操作，向上走 20 级台阶到台阶 2 。
执行第一种操作，向下走 1 级台阶到台阶 1 。
虎老师从台阶 1 开始。
执行第一种操作，从台阶 1 向下走到台阶 0 。
执行第二种操作，向上走 20 级台阶到台阶 1 。
执行第一种操作，向下走 1 级台阶到台阶 0 。
执行第二种操作，向上走 21 级台阶到台阶 2 。
执行第一种操作，向下走 1 级台阶到台阶 1 。


提示：

0 <= k <= 109
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int waysToReachStair(int k) {
		unordered_map<long long, int> memo;

		return DFS(1, 1, 0, k, memo);
    }

	int DFS(long long num, long long jump, int flag, int k, unordered_map<long long, int>& memo) {
		long long key = ((jump << 32) | (num << 31) | flag);
		if (memo.count(key) != 0) {
			return memo[key];
		}

		int ways = (num == k ? 1 : 0);
		if (num != 0 && flag != 1 && num - 1 <= k) {
			ways += DFS(num - 1, jump, 1, k, memo);
		}
		if (num + jump <= k + 1) {
			ways += DFS(num + jump, jump << 1, 0, k, memo);
		}

		return memo[key] = ways;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(2, o.waysToReachStair(0));
	check.checkInt(4, o.waysToReachStair(1));
	check.checkInt(0, o.waysToReachStair(100000000));
	check.checkInt(0, o.waysToReachStair(1000000000));
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
