/* 所有球里面不同颜色的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 limit 和一个大小为 n x 2 的二维数组 queries 。

总共有 limit + 1 个球，每个球的编号为 [0, limit] 中一个 互不相同 的数字。一开始，所有球都没有颜色。queries 中每次操作的格式为 [x, y] ，你需要将球 x 染上颜色 y 。每次操作之后，你需要求出所有球中 不同 颜色的数目。

请你返回一个长度为 n 的数组 result ，其中 result[i] 是第 i 次操作以后不同颜色的数目。

注意 ，没有染色的球不算作一种颜色。



示例 1：

输入：limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]

输出：[1,2,2,3]

解释：



操作 0 后，球 1 颜色为 4 。
操作 1 后，球 1 颜色为 4 ，球 2 颜色为 5 。
操作 2 后，球 1 颜色为 3 ，球 2 颜色为 5 。
操作 3 后，球 1 颜色为 3 ，球 2 颜色为 5 ，球 3 颜色为 4 。
示例 2：

输入：limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]]

输出：[1,2,2,3,4]

解释：



操作 0 后，球 0 颜色为 1 。
操作 1 后，球 0 颜色为 1 ，球 1 颜色为 2 。
操作 2 后，球 0 颜色为 1 ，球 1 和 2 颜色为 2 。
操作 3 后，球 0 颜色为 1 ，球 1 和 2 颜色为 2 ，球 3 颜色为 4 。
操作 4 后，球 0 颜色为 1 ，球 1 和 2 颜色为 2 ，球 3 颜色为 4 ，球 4 颜色为 5 。


提示：

1 <= limit <= 109
1 <= n == queries.length <= 105
queries[i].length == 2
0 <= queries[i][0] <= limit
1 <= queries[i][1] <= 109
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
		unordered_map<int, unordered_set<int>> colorBalls;
		unordered_map<int, int> ballColor;
		vector<int> ans(queries.size());

		for (int i = 0; i < (int)queries.size(); ++i) {
			int x = queries[i][0], y = queries[i][1];

			if (ballColor.count(x) != 0) {
				int color = ballColor[x];
				colorBalls[color].erase(x);
				if (colorBalls[color].empty()) {
					colorBalls.erase(color);
				}
			}

			ballColor[x] = y;
			colorBalls[y].insert(x);
			ans[i] = (int)colorBalls.size();
		}

		return ans;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> queries = { {1,4},{2,5},{1,3},{3,4} };
	vector<int> actual = o.queryResults(4, queries);
	vector<int> expected = { 1,2,2,3 };
	check.checkIntVector(expected, actual);

	queries = { {0,1},{1,2},{2,2},{3,4},{4,5} };
	actual = o.queryResults(4, queries);
	expected = { 1,2,2,3,4 };
	check.checkIntVector(expected, actual);
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
