/* 最小跳跃次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
为了给刷题的同学一些奖励，力扣团队引入了一个弹簧游戏机。游戏机由 N 个特殊弹簧排成一排，编号为 0 到 N-1。初始有一个小球在编号 0 的弹簧处。若小球在编号为 i 的弹簧处，通过按动弹簧，可以选择把小球向右弹射 jump[i] 的距离，或者向左弹射到任意左侧弹簧的位置。也就是说，在编号为 i 弹簧处按动弹簧，小球可以弹向 0 到 i-1 中任意弹簧或者 i+jump[i] 的弹簧（若 i+jump[i]>=N ，则表示小球弹出了机器）。小球位于编号 0 处的弹簧时不能再向左弹。

为了获得奖励，你需要将小球弹出机器。请求出最少需要按动多少次弹簧，可以将小球从编号 0 弹簧弹出整个机器，即向右越过编号 N-1 的弹簧。

示例 1：

输入：jump = [2, 5, 1, 1, 1, 1]

输出：3

解释：小 Z 最少需要按动 3 次弹簧，小球依次到达的顺序为 0 -> 2 -> 1 -> 6，最终小球弹出了机器。

限制：

1 <= jump.length <= 10^6
1 <= jump[i] <= 10000
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
	int minJump(vector<int>& jump) {
		int size = (int)jump.size(), jumps = 0, firstNotVisited = 1;
		vector<bool> visited(size, false);
		visited[0] = true;
		queue<int> nodes;
		nodes.push(0);

		while (!nodes.empty()) {
			int cnt = (int)nodes.size();
			++jumps;

			for (int i = 0; i < cnt; ++i) {
				int node = nodes.front();
				nodes.pop();

				int next = node + jump[node];  // 往右边跳
				if (next >= size) {
					return jumps;
				}

				if (!visited[next]) {
					visited[next] = true;
					nodes.push(next);
				}

				for (int prev = firstNotVisited; prev < node; ++prev) {  // 左边所有还未访问的点都可以访问了
					if (!visited[prev]) {
						visited[prev] = true;
						nodes.push(prev);
					}
				}

				firstNotVisited = max(firstNotVisited, node + 1);  // firstNotVisited 至少会到 node + 1
			}
		}

		return -1;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> jump = { 2,5,1,1,1,1 };
	check.checkInt(3, o.minJump(jump));

	jump = { 4,6,10,8,3,5,3,5,7,8,6,10,3,7,3,10,7,10,10,9,1,4,7,4,8,6,9,8,8,2,7,2,4,5,4,3,3,2,2,2,3,4,4,1,1,5,6,8,1,2 };
	check.checkInt(11, o.minJump(jump));

	jump = { 3,7,6,1,4,3,7,8,1,2,8,5,9,8,3,2,7,5,1,1 };
	check.checkInt(6, o.minJump(jump));
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
