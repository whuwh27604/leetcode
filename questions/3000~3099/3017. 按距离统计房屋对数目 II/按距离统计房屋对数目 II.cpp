/* 按距离统计房屋对数目 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你三个 正整数 n 、x 和 y 。

在城市中，存在编号从 1 到 n 的房屋，由 n 条街道相连。对所有 1 <= i < n ，都存在一条街道连接编号为 i 的房屋与编号为 i + 1 的房屋。另存在一条街道连接编号为 x 的房屋与编号为 y 的房屋。

对于每个 k（1 <= k <= n），你需要找出所有满足要求的 房屋对 [house1, house2] ，即从 house1 到 house2 需要经过的 最少 街道数为 k 。

返回一个下标从 1 开始且长度为 n 的数组 result ，其中 result[k] 表示所有满足要求的房屋对的数量，即从一个房屋到另一个房屋需要经过的 最少 街道数为 k 。

注意，x 与 y 可以 相等 。



示例 1：


输入：n = 3, x = 1, y = 3
输出：[6,0,0]
解释：让我们检视每个房屋对
- 对于房屋对 (1, 2)，可以直接从房屋 1 到房屋 2。
- 对于房屋对 (2, 1)，可以直接从房屋 2 到房屋 1。
- 对于房屋对 (1, 3)，可以直接从房屋 1 到房屋 3。
- 对于房屋对 (3, 1)，可以直接从房屋 3 到房屋 1。
- 对于房屋对 (2, 3)，可以直接从房屋 2 到房屋 3。
- 对于房屋对 (3, 2)，可以直接从房屋 3 到房屋 2。
示例 2：


输入：n = 5, x = 2, y = 4
输出：[10,8,2,0,0]
解释：对于每个距离 k ，满足要求的房屋对如下：
- 对于 k == 1，满足要求的房屋对有 (1, 2), (2, 1), (2, 3), (3, 2), (2, 4), (4, 2), (3, 4), (4, 3), (4, 5), 以及 (5, 4)。
- 对于 k == 2，满足要求的房屋对有 (1, 3), (3, 1), (1, 4), (4, 1), (2, 5), (5, 2), (3, 5), 以及 (5, 3)。
- 对于 k == 3，满足要求的房屋对有 (1, 5)，以及 (5, 1) 。
- 对于 k == 4 和 k == 5，不存在满足要求的房屋对。
示例 3：


输入：n = 4, x = 1, y = 1
输出：[6,4,2,0]
解释：对于每个距离 k ，满足要求的房屋对如下：
- 对于 k == 1，满足要求的房屋对有 (1, 2), (2, 1), (2, 3), (3, 2), (3, 4), 以及 (4, 3)。
- 对于 k == 2，满足要求的房屋对有 (1, 3), (3, 1), (2, 4), 以及 (4, 2)。
- 对于 k == 3，满足要求的房屋对有 (1, 4), 以及 (4, 1)。
- 对于 k == 4，不存在满足要求的房屋对。


提示：

2 <= n <= 105
1 <= x, y <= n
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
		vector<long long> ans(n, 0);
		int z = (x + y) / 2;

		if (x > y) {
			swap(x, y);
		}

		if (x == y || x + 1 == y) {
			for (int i = 1; i < n; ++i) {
				++ans[0];
				--ans[n - i];
			}
		}
		else {
			for (int i = 1; i <= x; ++i) {
				++ans[0];  // i到[i + 1, z]的距离是[1, 2, ..., z - i]
				--ans[z - i];
				++ans[x - i];  // i到[y, z + 1]的距离是[x - i + 1, ..., x - i + 1 + y - z - 1]
				--ans[x - i + y - z];
				++ans[x - i + 1];  // i到[y + 1, n]的距离是[x - i + 2, ..., x - i + 1 + n - y]
				--ans[x - i + 1 + n - y];
			}

			for (int i = x + 1; i < y; ++i) {
				int len = (y - x + 1) / 2;  // 这是 i 到环上所有点的最大距离
				if (i + len >= y) {  // i 到[i + 1, n]所有点应该直达
					++ans[0];
					--ans[n - i];
				}
				else {  // 环上前一段直达，环上后一段和最后的一段直线绕行 i->x->y->j
					++ans[0];  // i 到[i + 1, i + len]的距离是[1, ... , len]
					--ans[len];
					++ans[i - x];  // i 到[i + len + 1, y]的距离是[i - x + 1, ..., i - x + 1 + y - (i + len + 1)]
					--ans[y - x - len];
					++ans[i - x + 1];  // i 到[y + 1, n]的距离是[i - x + 1 + 1, ..., i - x + 1 + n - y]
					--ans[i - x + 1 + n - y];
				}
			}

			for (int i = y; i < n; ++i) {  // 最后的一段直线全部直达
				++ans[0];
				--ans[n - i];
			}
		}

		ans[0] *= 2;  // 差分数组求结果，a->b 和 b->a 是不同的pair，所以所有pair * 2
		for (int i = 1; i < n; ++i) {
			ans[i] = ans[i] * 2 + ans[i - 1];
		}

		return ans;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<long long> actual = o.countOfPairs(3, 1, 3);
	vector<long long> expected = { 6,0,0 };
	check.checkLongLongVector(expected, actual);

	actual = o.countOfPairs(5, 2, 4);
	expected = { 10,8,2,0,0 };
	check.checkLongLongVector(expected, actual);

	actual = o.countOfPairs(4, 1, 1);
	expected = { 6,4,2,0 };
	check.checkLongLongVector(expected, actual);
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
