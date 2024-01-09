/* 使 X 和 Y 相等的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数 x 和 y 。

一次操作中，你可以执行以下四种操作之一：

如果 x 是 11 的倍数，将 x 除以 11 。
如果 x 是 5 的倍数，将 x 除以 5 。
将 x 减 1 。
将 x 加 1 。
请你返回让 x 和 y 相等的 最少 操作次数。



示例 1：

输入：x = 26, y = 1
输出：3
解释：我们可以通过以下操作将 26 变为 1 ：
1. 将 x 减 1
2. 将 x 除以 5
3. 将 x 除以 5
将 26 变为 1 最少需要 3 次操作。
示例 2：

输入：x = 54, y = 2
输出：4
解释：我们可以通过以下操作将 54 变为 2 ：
1. 将 x 加 1
2. 将 x 除以 11
3. 将 x 除以 5
4. 将 x 加 1
将 54 变为 2 最少需要 4 次操作。
示例 3：

输入：x = 25, y = 30
输出：5
解释：我们可以通过以下操作将 25 变为 30 ：
1. 将 x 加 1
2. 将 x 加 1
3. 将 x 加 1
4. 将 x 加 1
5. 将 x 加 1
将 25 变为 30 最少需要 5 次操作。


提示：

1 <= x, y <= 104
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
		int maxNum = 10000, minOpers = INT_MAX;
		vector<bool> visited(maxNum + 1, false);
		queue<pair<int, int>> nodes;
		nodes.push({ x,0 });
		visited[x] = true;

		while (!nodes.empty()) {
			int n = nodes.front().first, opers = nodes.front().second;
			nodes.pop();

			if (n <= y) {
				minOpers = min(minOpers, opers + (y - n));
			}
			else {
				++opers;

				if (n % 11 == 0 && !visited[n / 11]) {
					visited[n / 11] = true;
					nodes.push({ n / 11, opers });
				}

				if (n % 5 == 0 && !visited[n / 5]) {
					visited[n / 5] = true;
					nodes.push({ n / 5, opers });
				}

				if (n != 0 && !visited[n - 1]) {
					visited[n - 1] = true;
					nodes.push({ n - 1, opers });
				}
				
				if (n != maxNum && !visited[n + 1]) {
					visited[n + 1] = true;
					nodes.push({ n + 1, opers });
				}
			}
		}

		return minOpers;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(3, o.minimumOperationsToMakeEqual(26, 1));
	check.checkInt(4, o.minimumOperationsToMakeEqual(54, 2));
	check.checkInt(5, o.minimumOperationsToMakeEqual(25, 30));
	check.checkInt(5, o.minimumOperationsToMakeEqual(18, 1));
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
