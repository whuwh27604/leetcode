/* 对角线最长的矩形的面积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维整数数组 dimensions。

对于所有下标 i（0 <= i < dimensions.length），dimensions[i][0] 表示矩形 i 的长度，而 dimensions[i][1] 表示矩形 i 的宽度。

返回对角线最 长 的矩形的 面积 。如果存在多个对角线长度相同的矩形，返回面积最 大 的矩形的面积。



示例 1：

输入：dimensions = [[9,3],[8,6]]
输出：48
解释：
下标 = 0，长度 = 9，宽度 = 3。对角线长度 = sqrt(9 * 9 + 3 * 3) = sqrt(90) ≈ 9.487。
下标 = 1，长度 = 8，宽度 = 6。对角线长度 = sqrt(8 * 8 + 6 * 6) = sqrt(100) = 10。
因此，下标为 1 的矩形对角线更长，所以返回面积 = 8 * 6 = 48。
示例 2：

输入：dimensions = [[3,4],[4,3]]
输出：12
解释：两个矩形的对角线长度相同，为 5，所以最大面积 = 12。


提示：

1 <= dimensions.length <= 100
dimensions[i].length == 2
1 <= dimensions[i][0], dimensions[i][1] <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
		int maxArea = 0, maxLen = 0;

		for (auto& dimension : dimensions) {
			int x = dimension[0], y = dimension[1], len = x * x + y * y;
			if (len > maxLen) {
				maxLen = len;
				maxArea = x * y;
			}
			else if (len == maxLen) {
				maxArea = max(maxArea, x * y);
			}
		}

		return maxArea;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> dimensions = { {9,3},{8,6} };
	check.checkInt(48, o.areaOfMaxDiagonal(dimensions));

	dimensions = { {3,4},{4,3} };
	check.checkInt(12, o.areaOfMaxDiagonal(dimensions));
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
