/* 覆盖所有点的最少矩形数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维整数数组 point ，其中 points[i] = [xi, yi] 表示二维平面内的一个点。同时给你一个整数 w 。你需要用矩形 覆盖所有 点。

每个矩形的左下角在某个点 (x1, 0) 处，且右上角在某个点 (x2, y2) 处，其中 x1 <= x2 且 y2 >= 0 ，同时对于每个矩形都 必须 满足 x2 - x1 <= w 。

如果一个点在矩形内或者在边上，我们说这个点被矩形覆盖了。

请你在确保每个点都 至少 被一个矩形覆盖的前提下，最少 需要多少个矩形。

注意：一个点可以被多个矩形覆盖。



示例 1：



输入：points = [[2,1],[1,0],[1,4],[1,8],[3,5],[4,6]], w = 1

输出：2

解释：

上图展示了一种可行的矩形放置方案：

一个矩形的左下角在 (1, 0) ，右上角在 (2, 8) 。
一个矩形的左下角在 (3, 0) ，右上角在 (4, 8) 。
示例 2：



输入：points = [[0,0],[1,1],[2,2],[3,3],[4,4],[5,5],[6,6]], w = 2

输出：3

解释：

上图展示了一种可行的矩形放置方案：

一个矩形的左下角在 (0, 0) ，右上角在 (2, 2) 。
一个矩形的左下角在 (3, 0) ，右上角在 (5, 5) 。
一个矩形的左下角在 (6, 0) ，右上角在 (6, 6) 。
示例 3：



输入：points = [[2,3],[1,2]], w = 0

输出：2

解释：

上图展示了一种可行的矩形放置方案：

一个矩形的左下角在 (1, 0) ，右上角在 (1, 2) 。
一个矩形的左下角在 (2, 0) ，右上角在 (2, 3) 。


提示：

1 <= points.length <= 105
points[i].length == 2
0 <= xi == points[i][0] <= 109
0 <= yi == points[i][1] <= 109
0 <= w <= 109
所有点坐标 (xi, yi) 互不相同。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
		int size = (int)points.size();
		vector<int> xs(size);

		for (int i = 0; i < size; ++i) {
			xs[i] = points[i][0];
		}

		sort(xs.begin(), xs.end());
		int start = 0, count = 1;

		for (int end = 0; end < size; ++end) {
			if (xs[end] - xs[start] > w) {
				start = end;
				++count;
			}
		}

		return count;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> points = { {2,1},{1,0},{1,4},{1,8},{3,5},{4,6} };
	check.checkInt(2, o.minRectanglesToCoverPoints(points, 1));

	points = { {0,0},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6} };
	check.checkInt(3, o.minRectanglesToCoverPoints(points, 2));

	points = { {2,3},{1,2} };
	check.checkInt(2, o.minRectanglesToCoverPoints(points, 0));
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
