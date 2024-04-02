/* 求交集区域内的最大正方形面积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在二维平面上存在 n 个矩形。给你两个下标从 0 开始的二维整数数组 bottomLeft 和 topRight，两个数组的大小都是 n x 2 ，其中 bottomLeft[i] 和 topRight[i] 分别代表第 i 个矩形的 左下角 和 右上角 坐标。

我们定义 向右 的方向为 x 轴正半轴（x 坐标增加），向左 的方向为 x 轴负半轴（x 坐标减少）。同样地，定义 向上 的方向为 y 轴正半轴（y 坐标增加），向下 的方向为 y 轴负半轴（y 坐标减少）。

你可以选择一个区域，该区域由两个矩形的 交集 形成。你需要找出能够放入该区域 内 的 最大 正方形面积，并选择最优解。

返回能够放入交集区域的正方形的 最大 可能面积，如果矩形之间不存在任何交集区域，则返回 0。



示例 1：


输入：bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]
输出：1
解释：边长为 1 的正方形可以放入矩形 0 和矩形 1 的交集区域，或矩形 1 和矩形 2 的交集区域。因此最大面积是边长 * 边长，即 1 * 1 = 1。
可以证明，边长更大的正方形无法放入任何交集区域。
示例 2：


输入：bottomLeft = [[1,1],[2,2],[1,2]], topRight = [[3,3],[4,4],[3,4]]
输出：1
解释：边长为 1 的正方形可以放入矩形 0 和矩形 1，矩形 1 和矩形 2，或所有三个矩形的交集区域。因此最大面积是边长 * 边长，即 1 * 1 = 1。
可以证明，边长更大的正方形无法放入任何交集区域。
请注意，区域可以由多于两个矩形的交集构成。
示例 3：


输入：bottomLeft = [[1,1],[3,3],[3,1]], topRight = [[2,2],[4,4],[4,2]]
输出：0
解释：不存在相交的矩形，因此，返回 0 。


提示：

n == bottomLeft.length == topRight.length
2 <= n <= 103
bottomLeft[i].length == topRight[i].length == 2
1 <= bottomLeft[i][0], bottomLeft[i][1] <= 107
1 <= topRight[i][0], topRight[i][1] <= 107
bottomLeft[i][0] < topRight[i][0]
bottomLeft[i][1] < topRight[i][1]
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
		int n = topRight.size(), maxLen = 0;

		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int x11 = bottomLeft[i][0], y11 = bottomLeft[i][1], x12 = topRight[i][0], y12 = topRight[i][1];
				int x21 = bottomLeft[j][0], y21 = bottomLeft[j][1], x22 = topRight[j][0], y22 = topRight[j][1];
				maxLen = max(maxLen, min(getIntersectionLen(x11, x12, x21, x22), getIntersectionLen(y11, y12, y21, y22)));
			}
		}

		return (long long)maxLen * maxLen;
    }

	int getIntersectionLen(int p11, int p12, int p21, int p22) {
		return p22 < p11 || p21 > p12 ? 0 : min(p12, p22) - max(p11, p21);
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> bottomLeft = { {1,1},{2,2},{3,1} };
	vector<vector<int>> topRight = { {3,3},{4,4},{6,6} };
	check.checkLongLong(1, o.largestSquareArea(bottomLeft, topRight));

	bottomLeft = { {1,1},{2,2},{1,2} };
	topRight = { {3,3},{4,4},{3,4} };
	check.checkLongLong(1, o.largestSquareArea(bottomLeft, topRight));

	bottomLeft = { {1,1},{3,3},{3,1} };
	topRight = { {2,2},{4,4},{4,2} };
	check.checkLongLong(0, o.largestSquareArea(bottomLeft, topRight));
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
