/* 找出网格的区域平均强度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、大小为 m x n 的网格 image ，表示一个灰度图像，其中 image[i][j] 表示在范围 [0..255] 内的某个像素强度。另给你一个 非负 整数 threshold 。

如果 image[a][b] 和 image[c][d] 满足 |a - c| + |b - d| == 1 ，则称这两个像素是 相邻像素 。

区域 是一个 3 x 3 的子网格，且满足区域中任意两个 相邻 像素之间，像素强度的 绝对差 小于或等于 threshold 。

区域 内的所有像素都认为属于该区域，而一个像素 可以 属于 多个 区域。

你需要计算一个下标从 0 开始、大小为 m x n 的网格 result ，其中 result[i][j] 是 image[i][j] 所属区域的 平均 强度，向下取整 到最接近的整数。如果 image[i][j] 属于多个区域，result[i][j] 是这些区域的 “取整后的平均强度” 的 平均值，也 向下取整 到最接近的整数。如果 image[i][j] 不属于任何区域，则 result[i][j] 等于 image[i][j] 。

返回网格 result 。



示例 1：


输入：image = [[5,6,7,10],[8,9,10,10],[11,12,13,10]], threshold = 3
输出：[[9,9,9,9],[9,9,9,9],[9,9,9,9]]
解释：图像中存在两个区域，如图片中的阴影区域所示。第一个区域的平均强度为 9 ，而第二个区域的平均强度为 9.67 ，向下取整为 9 。两个区域的平均强度为 (9 + 9) / 2 = 9 。由于所有像素都属于区域 1 、区域 2 或两者，因此 result 中每个像素的强度都为 9 。
注意，在计算多个区域的平均值时使用了向下取整的值，因此使用区域 2 的平均强度 9 来进行计算，而不是 9.67 。
示例 2：


输入：image = [[10,20,30],[15,25,35],[20,30,40],[25,35,45]], threshold = 12
输出：[[25,25,25],[27,27,27],[27,27,27],[30,30,30]]
解释：图像中存在两个区域，如图片中的阴影区域所示。第一个区域的平均强度为 25 ，而第二个区域的平均强度为 30 。两个区域的平均强度为 (25 + 30) / 2 = 27.5 ，向下取整为 27 。图像中第 0 行的所有像素属于区域 1 ，因此 result 中第 0 行的所有像素为 25 。同理，result 中第 3 行的所有像素为 30 。图像中第 1 行和第 2 行的像素属于区域 1 和区域 2 ，因此它们在 result 中的值为 27 。
示例 3：

输入：image = [[5,6,7],[8,9,10],[11,12,13]], threshold = 1
输出：[[5,6,7],[8,9,10],[11,12,13]]
解释：图像中不存在任何区域，因此对于所有像素，result[i][j] == image[i][j] 。


提示：

3 <= n, m <= 500
0 <= image[i][j] <= 255
0 <= threshold <= 255
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
		int m = image.size(), n = image[0].size();
		vector<vector<int>> intensities(m + 2, vector<int>(n + 2, -1));
		vector<vector<int>> averageIntensities = image;

		getIntensities(m, n, image, threshold, intensities);
		getAverageIntensities(m, n, intensities, averageIntensities);

		return averageIntensities;
    }

	void getIntensities(int m, int n, vector<vector<int>>& image, int threshold, vector<vector<int>>& intensities) {
		for (int r = 0; r < m - 2; ++r) {
			for (int c = 0; c < n - 2; ++c) {
				if (isRegion(image, threshold, r, c)) {
					intensities[r + 2][c + 2] = calcIntensity(image, r, c);
				}
			}
		}
	}

	bool isRegion(vector<vector<int>>& image, int threshold, int r, int c) {
		return abs(image[r][c] - image[r][c + 1]) <= threshold
			&& abs(image[r][c + 1] - image[r][c + 2]) <= threshold
			&& abs(image[r + 1][c] - image[r + 1][c + 1]) <= threshold
			&& abs(image[r + 1][c + 1] - image[r + 1][c + 2]) <= threshold
			&& abs(image[r + 2][c] - image[r + 2][c + 1]) <= threshold
			&& abs(image[r + 2][c + 1] - image[r + 2][c + 2]) <= threshold
			&& abs(image[r][c] - image[r + 1][c]) <= threshold
			&& abs(image[r + 1][c] - image[r + 2][c]) <= threshold
			&& abs(image[r][c + 1] - image[r + 1][c + 1]) <= threshold
			&& abs(image[r + 1][c + 1] - image[r + 2][c + 1]) <= threshold
			&& abs(image[r][c + 2] - image[r + 1][c + 2]) <= threshold
			&& abs(image[r + 1][c + 2] - image[r + 2][c + 2]) <= threshold;
	}

	int calcIntensity(vector<vector<int>>& image, int r, int c) {
		int intensity = 0;

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				intensity += image[r + i][c + j];
			}
		}

		return intensity / 9;
	}

	void getAverageIntensities(int m, int n, vector<vector<int>>& intensities, vector<vector<int>>& averageIntensities) {
		for (int r = 2; r < m + 2; ++r) {
			for (int c = 2; c < n + 2; ++c) {
				int sum = 0, count = 0;

				for (int i = r - 2; i <= r; ++i) {
					for (int j = c - 2; j <= c; ++j) {
						if (intensities[i][j] != -1) {
							sum += intensities[i][j];
							++count;
						}
					}
				}

				if (count != 0) {
					averageIntensities[r - 2][c - 2] = sum / count;
				}
			}
		}
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> image = { {5,6,7,10},{8,9,10,10},{11,12,13,10} };
	vector<vector<int>> actual = o.resultGrid(image, 3);
	vector<vector<int>> expected = { {9,9,9,9},{9,9,9,9},{9,9,9,9} };
	check.checkIntVectorVector(expected, actual);

	image = { {10,20,30},{15,25,35},{20,30,40},{25,35,45} };
	actual = o.resultGrid(image, 12);
	expected = { {25,25,25},{27,27,27},{27,27,27},{30,30,30} };
	check.checkIntVectorVector(expected, actual);

	image = { {5,6,7},{8,9,10},{11,12,13} };
	actual = o.resultGrid(image, 1);
	expected = { {5,6,7},{8,9,10},{11,12,13} };
	check.checkIntVectorVector(expected, actual);

	image = { {4,8,5},{5,7,7},{9,4,2} };
	actual = o.resultGrid(image, 4);
	expected = { {4,8,5},{5,7,7},{9,4,2} };
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
