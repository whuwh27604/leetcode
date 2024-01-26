/* 收集所有金币可获得的最大积分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一棵由 n 个节点组成的无向树，以 0  为根节点，节点编号从 0 到 n - 1 。给你一个长度为 n - 1 的二维 整数 数组 edges ，其中 edges[i] = [ai, bi] 表示在树上的节点 ai 和 bi 之间存在一条边。另给你一个下标从 0 开始、长度为 n 的数组 coins 和一个整数 k ，其中 coins[i] 表示节点 i 处的金币数量。

从根节点开始，你必须收集所有金币。要想收集节点上的金币，必须先收集该节点的祖先节点上的金币。

节点 i 上的金币可以用下述方法之一进行收集：

收集所有金币，得到共计 coins[i] - k 点积分。如果 coins[i] - k 是负数，你将会失去 abs(coins[i] - k) 点积分。
收集所有金币，得到共计 floor(coins[i] / 2) 点积分。如果采用这种方法，节点 i 子树中所有节点 j 的金币数 coins[j] 将会减少至 floor(coins[j] / 2) 。
返回收集 所有 树节点的金币之后可以获得的最大积分。



示例 1：


输入：edges = [[0,1],[1,2],[2,3]], coins = [10,10,3,3], k = 5
输出：11
解释：
使用第一种方法收集节点 0 上的所有金币。总积分 = 10 - 5 = 5 。
使用第一种方法收集节点 1 上的所有金币。总积分 = 5 + (10 - 5) = 10 。
使用第二种方法收集节点 2 上的所有金币。所以节点 3 上的金币将会变为 floor(3 / 2) = 1 ，总积分 = 10 + floor(3 / 2) = 11 。
使用第二种方法收集节点 3 上的所有金币。总积分 =  11 + floor(1 / 2) = 11.
可以证明收集所有节点上的金币能获得的最大积分是 11 。
示例 2：


输入：edges = [[0,1],[0,2]], coins = [8,4,4], k = 0
输出：16
解释：
使用第一种方法收集所有节点上的金币，因此，总积分 = (8 - 0) + (4 - 0) + (4 - 0) = 16 。


提示：

n == coins.length
2 <= n <= 105
0 <= coins[i] <= 104
edges.length == n - 1
0 <= edges[i][0], edges[i][1] < n
0 <= k <= 104
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
		int n = coins.size();
		vector<vector<int>> adjs(n);
		vector<vector<int>> memo(maxShift + 1, vector<int>(n, -1));

		getAdjs(edges, adjs);

		return getMaxPoints(0, -1, 0, adjs, coins, memo, k);
    }

	void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
		for (auto& edge : edges) {
			int x = edge[0], y = edge[1];
			adjs[x].push_back(y);
			adjs[y].push_back(x);
		}
	}

	int getMaxPoints(int node, int parent, int shift, vector<vector<int>>& adjs, vector<int>& coins, vector<vector<int>>& memo, int k) {
		if (memo[shift][node] != -1) {
			return memo[shift][node];
		}

		int nextShift = (shift == maxShift ? maxShift : shift + 1);
		int points1 = (coins[node] >> shift) - k, points2 = (coins[node] >> nextShift);

		for (int next : adjs[node]) {
			if (next != parent) {
				points1 += getMaxPoints(next, node, shift, adjs, coins, memo, k);
				points2 += getMaxPoints(next, node, nextShift, adjs, coins, memo, k);
			}
		}

		return memo[shift][node] = max(points1, points2);
	}

	int maxShift = 14;
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> edges = { {0,1},{1,2},{2,3} };
	vector<int> coins = { 10,10,3,3 };
	check.checkInt(11, o.maximumPoints(edges, coins, 5));

	edges = { {0,1},{0,2} };
	coins = { 8,4,4 };
	check.checkInt(16, o.maximumPoints(edges, coins, 0));
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
