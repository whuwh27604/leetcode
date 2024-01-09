/* 统计强大整数的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你三个整数 start ，finish 和 limit 。同时给你一个下标从 0 开始的字符串 s ，表示一个 正 整数。

如果一个 正 整数 x 末尾部分是 s （换句话说，s 是 x 的 后缀），且 x 中的每个数位至多是 limit ，那么我们称 x 是 强大的 。

请你返回区间 [start..finish] 内强大整数的 总数目 。

如果一个字符串 x 是 y 中某个下标开始（包括 0 ），到下标为 y.length - 1 结束的子字符串，那么我们称 x 是 y 的一个后缀。比方说，25 是 5125 的一个后缀，但不是 512 的后缀。



示例 1：

输入：start = 1, finish = 6000, limit = 4, s = "124"
输出：5
解释：区间 [1..6000] 内的强大数字为 124 ，1124 ，2124 ，3124 和 4124 。这些整数的各个数位都 <= 4 且 "124" 是它们的后缀。注意 5124 不是强大整数，因为第一个数位 5 大于 4 。
这个区间内总共只有这 5 个强大整数。
示例 2：

输入：start = 15, finish = 215, limit = 6, s = "10"
输出：2
解释：区间 [15..215] 内的强大整数为 110 和 210 。这些整数的各个数位都 <= 6 且 "10" 是它们的后缀。
这个区间总共只有这 2 个强大整数。
示例 3：

输入：start = 1000, finish = 2000, limit = 4, s = "3000"
输出：0
解释：区间 [1000..2000] 内的整数都小于 3000 ，所以 "3000" 不可能是这个区间内任何整数的后缀。


提示：

1 <= start <= finish <= 1015
1 <= limit <= 9
1 <= s.length <= floor(log10(finish)) + 1
s 数位中每个数字都小于等于 limit 。
s 不包含任何前导 0 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long numberOfPowerfulInt(long long start_, long long finish_, int limit_, string s) {
		finish = to_string(finish_);
		start = to_string(start_);
		start.insert(start.begin(), finish.size() - start.size(), '0');
		size = finish.size();
		end = size - s.size();
		suffix = stoll(s);
		limit = limit_;
		sufLower = stoll(string(start, end, s.size()));
		sufUpper = stoll(string(finish, end, s.size()));
		memo.clear();
		memo.resize(size * 2 * 2, -1);

		return DFS(0, true, true);
    }

	long long DFS(int current, bool isLower, bool isUpper) {
		if (current == end) {
			if ((isLower && suffix < sufLower) || (isUpper && suffix > sufUpper)) {
				return 0;
			}

			return 1;
		}

		int mask = current * 4 + (isLower ? 1 : 0) * 2 + (isUpper ? 1 : 0);
		if (memo[mask] != -1) {
			return memo[mask];
		}

		long long count = 0;
		int low = isLower ? start[current] - '0' : 0;
		int high = isUpper ? min(finish[current] - '0', limit) : limit;

		for (int d = low; d <= high; ++d) {
			count += DFS(current + 1, isLower && d == start[current] - '0', isUpper && d == finish[current] - '0');
		}

		return memo[mask] = count;
	}

	Solution() : suffix(0), sufLower(0), sufUpper(0), size(0), end(0), limit(0) {}

	string start;
	string finish;
	long long suffix;
	long long sufLower;
	long long sufUpper;
	int size;
	int end;
	int limit;
	vector<long long> memo;
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkLongLong(5, o.numberOfPowerfulInt(1, 6000, 4, "124"));
	check.checkLongLong(2, o.numberOfPowerfulInt(15, 215, 6, "10"));
	check.checkLongLong(0, o.numberOfPowerfulInt(1000, 2000, 4, "3000"));
	check.checkLongLong(8, o.numberOfPowerfulInt(20, 1159, 5, "20"));
	check.checkLongLong(10, o.numberOfPowerfulInt(1, 10000, 9, "987"));
	check.checkLongLong(1000000000000, o.numberOfPowerfulInt(1, 1000000000000000, 9, "987"));
	check.checkLongLong(4096, o.numberOfPowerfulInt(1, 1000000000000000, 1, "101"));
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
