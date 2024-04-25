/* 快速公交.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小扣打算去秋日市集，由于游客较多，小扣的移动速度受到了人流影响：

小扣从 x 号站点移动至 x + 1 号站点需要花费的时间为 inc；
小扣从 x 号站点移动至 x - 1 号站点需要花费的时间为 dec。
现有 m 辆公交车，编号为 0 到 m-1。小扣也可以通过搭乘编号为 i 的公交车，从 x 号站点移动至 jump[i]*x 号站点，耗时仅为 cost[i]。小扣可以搭乘任意编号的公交车且搭乘公交次数不限。

假定小扣起始站点记作 0，秋日市集站点记作 target，请返回小扣抵达秋日市集最少需要花费多少时间。由于数字较大，最终答案需要对 1000000007 (1e9 + 7) 取模。

注意：小扣可在移动过程中到达编号大于 target 的站点。

示例 1：

输入：target = 31, inc = 5, dec = 3, jump = [6], cost = [10]

输出：33

解释： 小扣步行至 1 号站点，花费时间为 5； 小扣从 1 号站台搭乘 0 号公交至 6 * 1 = 6 站台，花费时间为 10； 小扣从 6 号站台步行至 5 号站台，花费时间为 3； 小扣从 5 号站台搭乘 0 号公交至 6 * 5 = 30 站台，花费时间为 10； 小扣从 30 号站台步行至 31 号站台，花费时间为 5； 最终小扣花费总时间为 33。

示例 2：

输入：target = 612, inc = 4, dec = 5, jump = [3,6,8,11,5,10,4], cost = [4,7,6,3,7,6,4]

输出：26

解释： 小扣步行至 1 号站点，花费时间为 4； 小扣从 1 号站台搭乘 0 号公交至 3 * 1 = 3 站台，花费时间为 4； 小扣从 3 号站台搭乘 3 号公交至 11 * 3 = 33 站台，花费时间为 3； 小扣从 33 号站台步行至 34 站台，花费时间为 4； 小扣从 34 号站台搭乘 0 号公交至 3 * 34 = 102 站台，花费时间为 4； 小扣从 102 号站台搭乘 1 号公交至 6 * 102 = 612 站台，花费时间为 7； 最终小扣花费总时间为 26。

提示：

1 <= target <= 10^9
1 <= jump.length, cost.length <= 10
2 <= jump[i] <= 10^6
1 <= inc, dec, cost[i] <= 10^6
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
	int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
		int size = (int)jump.size();
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> nodes;
		nodes.push({ 0,target });
		unordered_map<int, long long> minDist;
		minDist[target] = 0;
		minDist[0] = LLONG_MAX / 2;

		while (!nodes.empty()) {
			int node = nodes.top().second;
			long long dist = nodes.top().first;
			nodes.pop();

			if (minDist.count(node) != 0 && dist > minDist[node]) {
				continue;
			}

			if (dist >= minDist[0]) {
				continue;
			}

			minDist[0] = min(minDist[0], (long long)node * inc + dist);

			for (int i = 0; i < size; ++i) {
				int jmp = jump[i], dis = cost[i];

				if (node % jmp == 0) {
					int next = node / jmp;
					long long nextDist = dist + dis;
					if (minDist.count(next) == 0 || nextDist < minDist[next]) {
						minDist[next] = nextDist;
						nodes.push({ nextDist, next });
					}
				}
				else {
					int remainder = node % jmp;
					int next = node - remainder;
					long long nextDist = dist + inc * (long long)remainder;
					if (minDist.count(next) == 0 || nextDist < minDist[next]) {
						minDist[next] = nextDist;
						nodes.push({ nextDist, next });
					}

					next += jmp;
					nextDist = dist + dec * ((long long)jmp - remainder);
					if (minDist.count(next) == 0 || nextDist < minDist[next]) {
						minDist[next] = nextDist;
						nodes.push({ nextDist, next });
					}
				}
			}
		}

		return minDist[0] % 1000000007;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> jump = { 6 };
	vector<int> cost = { 10 };
	check.checkInt(33, o.busRapidTransit(31, 5, 3, jump, cost));

	jump = { 3,6,8,11,5,10,4 };
	cost = { 4,7,6,3,7,6,4 };
	check.checkInt(26, o.busRapidTransit(612, 4, 5, jump, cost));

	jump = { 2,2,2,2,2,2,2,2,2,2 };
	cost = { 1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000 };
	check.checkInt(10953125, o.busRapidTransit(1000000000, 1, 1, jump, cost));

	jump = { 5,4,3,2 };
	cost = { 1000000,861353,682606,430676 };
	check.checkInt(5209058, o.busRapidTransit(999999991, 1, 1, jump, cost));

	jump = { 80,44,73,69,98 };
	cost = { 72,82,77,3,31 };
	check.checkInt(1293, o.busRapidTransit(868, 60, 62, jump, cost));

	jump = { 6061,5876,6528,6680,5580,2772,6619,7365,9474,2136 };
	cost = { 1792,6103,9708,6519,2305,8327,7393,9533,269,7938 };
	check.checkInt(1293, o.busRapidTransit(980632, 2933, 5626, jump, cost));
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
