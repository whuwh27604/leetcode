/* 幸福值最大化的选择方案.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的数组 happiness ，以及一个 正整数 k 。

n 个孩子站成一队，其中第 i 个孩子的 幸福值 是 happiness[i] 。你计划组织 k 轮筛选从这 n 个孩子中选出 k 个孩子。

在每一轮选择一个孩子时，所有 尚未 被选中的孩子的 幸福值 将减少 1 。注意，幸福值 不能 变成负数，且只有在它是正数的情况下才会减少。

选择 k 个孩子，并使你选中的孩子幸福值之和最大，返回你能够得到的 最大值 。



示例 1：

输入：happiness = [1,2,3], k = 2
输出：4
解释：按以下方式选择 2 个孩子：
- 选择幸福值为 3 的孩子。剩余孩子的幸福值变为 [0,1] 。
- 选择幸福值为 1 的孩子。剩余孩子的幸福值变为 [0] 。注意幸福值不能小于 0 。
所选孩子的幸福值之和为 3 + 1 = 4 。
示例 2：

输入：happiness = [1,1,1,1], k = 2
输出：1
解释：按以下方式选择 2 个孩子：
- 选择幸福值为 1 的任意一个孩子。剩余孩子的幸福值变为 [0,0,0] 。
- 选择幸福值为 0 的孩子。剩余孩子的幸福值变为 [0,0] 。
所选孩子的幸福值之和为 1 + 0 = 1 。
示例 3：

输入：happiness = [2,3,4,5], k = 1
输出：5
解释：按以下方式选择 1 个孩子：
- 选择幸福值为 5 的孩子。剩余孩子的幸福值变为 [1,2,3] 。
所选孩子的幸福值之和为 5 。


提示：

1 <= n == happiness.length <= 2 * 105
1 <= happiness[i] <= 108
1 <= k <= n
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
		int n = happiness.size(), decrease = 0;
		long long sum = 0;

		sort(happiness.begin(), happiness.end(), greater<int>());

		for (int i = 0; i < k; ++i) {
			if (happiness[i] > decrease) {
				sum += (happiness[i] - decrease++);
			}
			else {
				break;
			}
		}

		return sum;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> happiness = { 1,2,3 };
	check.checkLongLong(4, o.maximumHappinessSum(happiness, 2));

	happiness = { 1,1,1,1 };
	check.checkLongLong(1, o.maximumHappinessSum(happiness, 2));

	happiness = { 2,3,4,5 };
	check.checkLongLong(5, o.maximumHappinessSum(happiness, 1));
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
