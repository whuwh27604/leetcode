/* 重新分装苹果.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的数组 apple 和另一个长度为 m 的数组 capacity 。

一共有 n 个包裹，其中第 i 个包裹中装着 apple[i] 个苹果。同时，还有 m 个箱子，第 i 个箱子的容量为 capacity[i] 个苹果。

请你选择一些箱子来将这 n 个包裹中的苹果重新分装到箱子中，返回你需要选择的箱子的 最小 数量。

注意，同一个包裹中的苹果可以分装到不同的箱子中。



示例 1：

输入：apple = [1,3,2], capacity = [4,3,1,5,2]
输出：2
解释：使用容量为 4 和 5 的箱子。
总容量大于或等于苹果的总数，所以可以完成重新分装。
示例 2：

输入：apple = [5,5,5], capacity = [2,4,2,7]
输出：4
解释：需要使用所有箱子。


提示：

1 <= n == apple.length <= 50
1 <= m == capacity.length <= 50
1 <= apple[i], capacity[i] <= 50
输入数据保证可以将包裹中的苹果重新分装到箱子中。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
		int sum = 0, boxes = 0;

		sort(capacity.begin(), capacity.end(), greater<int>());

		for (int app : apple) {
			sum += app;
		}

		for (int cap : capacity) {
			++boxes;
			sum -= cap;

			if (sum <= 0) {
				break;
			}
		}

		return boxes;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> apple = { 1,3,2 };
	vector<int> capacity = { 4,3,1,5,2 };
	check.checkInt(2, o.minimumBoxes(apple, capacity));

	apple = { 5,5,5 };
	capacity = { 2,4,2,7 };
	check.checkInt(4, o.minimumBoxes(apple, capacity));
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
