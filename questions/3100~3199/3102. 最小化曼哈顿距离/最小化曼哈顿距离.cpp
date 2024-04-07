/* 最小化曼哈顿距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的数组 points ，它表示二维平面上一些点的整数坐标，其中 points[i] = [xi, yi] 。

两点之间的距离定义为它们的
曼哈顿距离
。

请你恰好移除一个点，返回移除后任意两点之间的 最大 距离可能的 最小 值。



示例 1：

输入：points = [[3,10],[5,15],[10,2],[4,4]]
输出：12
解释：移除每个点后的最大距离如下所示：
- 移除第 0 个点后，最大距离在点 (5, 15) 和 (10, 2) 之间，为 |5 - 10| + |15 - 2| = 18 。
- 移除第 1 个点后，最大距离在点 (3, 10) 和 (10, 2) 之间，为 |3 - 10| + |10 - 2| = 15 。
- 移除第 2 个点后，最大距离在点 (5, 15) 和 (4, 4) 之间，为 |5 - 4| + |15 - 4| = 12 。
- 移除第 3 个点后，最大距离在点 (5, 15) 和 (10, 2) 之间的，为 |5 - 10| + |15 - 2| = 18 。
在恰好移除一个点后，任意两点之间的最大距离可能的最小值是 12 。
示例 2：

输入：points = [[1,1],[1,1],[1,1]]
输出：0
解释：移除任一点后，任意两点之间的最大距离都是 0 。


提示：

3 <= points.length <= 105
points[i].length == 2
1 <= points[i][0], points[i][1] <= 108
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
		/* ManhattanDist = |x1 - x2| + |y1 - y2|
		   ChebyshevDist = max(|x1 - x2|, |y1 - y2|)
		   ManhattanDist((x1, y1), (x2, y2)) = ChebyshevDist((x1 + y1, x1 - y1), (x2 + y2, x2 - y2))
		   ChebyshevDist((x1, y1), (x2, y2)) = ManhattanDist(((x1 + y1) / 2, (x1 - y1) / 2), ((x2 + y2) / 2, (x2 - y2) / 2)) */
		map<int, int> xs, ys;
		int maxX = INT_MIN, minX = INT_MAX, maxY = INT_MIN, minY = INT_MAX;

		for (auto& point : points) {  // Manhattan坐标转Chebyshev坐标
			int x = point[0] + point[1], y = point[0] - point[1];
			point[0] = x;
			point[1] = y;
			maxX = max(maxX, x);
			minX = min(minX, x);
			maxY = max(maxY, y);
			minY = min(minY, y);
			++xs[x];
			++ys[y];
		}

		// Manhattan距离等于新坐标系下的Chebyshev距离
		int minDistance = max(xs.rbegin()->first - xs.begin()->first, ys.rbegin()->first - ys.begin()->first);

		for (auto& point : points) {
			int x = point[0], y = point[1];
			if (x == minX || x == maxX || y == minY || y == maxY) {  // 不在边界上的点不会影响最终结果
				if (--xs[x] == 0) {  // 先删除这个点
					xs.erase(x);
				}

				if (--ys[y] == 0) {
					ys.erase(y);
				}

				// 求新的最大距离
				int dist = max(xs.rbegin()->first - xs.begin()->first, ys.rbegin()->first - ys.begin()->first);
				minDistance = min(minDistance, dist);

				++xs[x];  // 将删除的点加回来
				++ys[y];
			}
		}

		return minDistance;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> points = { {3,10},{5,15},{10,2},{4,4} };
	check.checkInt(12, o.minimumDistance(points));

	points = { {1,1},{1,1},{1,1} };
	check.checkInt(0, o.minimumDistance(points));

	points = { {3,2},{3,9},{7,10},{4,4},{8,10},{2,7} };
	check.checkInt(10, o.minimumDistance(points));
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
