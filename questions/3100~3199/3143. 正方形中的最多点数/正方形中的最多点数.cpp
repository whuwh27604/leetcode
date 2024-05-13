/* 正方形中的最多点数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维数组 points 和一个字符串 s ，其中 points[i] 表示第 i 个点的坐标，s[i] 表示第 i 个点的 标签 。

如果一个正方形的中心在 (0, 0) ，所有边都平行于坐标轴，且正方形内 不 存在标签相同的两个点，那么我们称这个正方形是 合法 的。

请你返回 合法 正方形中可以包含的 最多 点数。

注意：

如果一个点位于正方形的边上或者在边以内，则认为该点位于正方形内。
正方形的边长可以为零。


示例 1：



输入：points = [[2,2],[-1,-2],[-4,4],[-3,1],[3,-3]], s = "abdca"

输出：2

解释：

边长为 4 的正方形包含两个点 points[0] 和 points[1] 。

示例 2：



输入：points = [[1,1],[-2,-2],[-2,2]], s = "abb"

输出：1

解释：

边长为 2 的正方形包含 1 个点 points[0] 。

示例 3：

输入：points = [[1,1],[-1,-1],[2,-2]], s = "ccd"

输出：0

解释：

任何正方形都无法只包含 points[0] 和 points[1] 中的一个点，所以合法正方形中都不包含任何点。



提示：

1 <= s.length, points.length <= 105
points[i].length == 2
-109 <= points[i][0], points[i][1] <= 109
s.length == points.length
points 中的点坐标互不相同。
s 只包含小写英文字母。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
		int n = (int)s.size(), count = 0, minLen = INT_MAX;
		vector<int> min1Lens(127, INT_MAX), min2Lens(127, INT_MAX);

		for (int i = 0; i < n; ++i) {
			int len = max(abs(points[i][0]), abs(points[i][1]));
			char c = s[i];

			if (len < min1Lens[c]) {
				min2Lens[c] = min1Lens[c];
				min1Lens[c] = len;
			}
			else if (len < min2Lens[c]) {
				min2Lens[c] = len;
			}
		}

		for (char c = 'a'; c <= 'z'; ++c) {
			minLen = min(minLen, min2Lens[c]);
		}

		for (int i = 0; i < n; ++i) {
			if (abs(points[i][0]) < minLen && abs(points[i][1]) < minLen) {
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

	vector<vector<int>> points = {{2,2},{-1,-2},{-4,4},{-3,1},{3,-3}};
	check.checkInt(2,o.maxPointsInsideSquare(points,"abdca"));

	points = {{1,1},{-2,-2},{-2,2}};
	check.checkInt(1,o.maxPointsInsideSquare(points,"abb"));

	points = {{1,1},{-1,-1},{2,-2}};
	check.checkInt(0, o.maxPointsInsideSquare(points, "ccd"));
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
