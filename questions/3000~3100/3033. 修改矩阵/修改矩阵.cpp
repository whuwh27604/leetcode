/* 修改矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、大小为 m x n 的整数矩阵 matrix ，新建一个下标从 0 开始、名为 answer 的矩阵。使 answer 与 matrix 相等，接着将其中每个值为 -1 的元素替换为所在列的 最大 元素。

返回矩阵 answer 。



示例 1：


输入：matrix = [[1,2,-1],[4,-1,6],[7,8,9]]
输出：[[1,2,9],[4,8,6],[7,8,9]]
解释：上图显示了发生替换的元素（蓝色区域）。
- 将单元格 [1][1] 中的值替换为列 1 中的最大值 8 。
- 将单元格 [0][2] 中的值替换为列 2 中的最大值 9 。
示例 2：


输入：matrix = [[3,-1],[5,2]]
输出：[[3,2],[5,2]]
解释：上图显示了发生替换的元素（蓝色区域）。


提示：

m == matrix.length
n == matrix[i].length
2 <= m, n <= 50
-1 <= matrix[i][j] <= 100
测试用例中生成的输入满足每列至少包含一个非负整数。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();

		for (int c = 0; c < n; ++c) {
			int maxC = 0;

			for (int r = 0; r < m; ++r) {
				maxC = max(maxC, matrix[r][c]);
			}

			for (int r = 0; r < m; ++r) {
				if (matrix[r][c] == -1) {
					matrix[r][c] = maxC;
				}
			}
		}

		return matrix;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> matrix = { {1,2,-1},{4,-1,6},{7,8,9} };
	vector<vector<int>> actual = o.modifiedMatrix(matrix);
	vector<vector<int>> expected = { {1,2,9},{4,8,6},{7,8,9} };
	check.checkIntVectorVector(expected, actual);

	matrix = { {3,-1},{5,2} };
	actual = o.modifiedMatrix(matrix);
	expected = { {3,2},{5,2} };
	check.checkIntVectorVector(expected, actual);
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
