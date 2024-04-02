/* 子集中元素的最大数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 正整数 数组 nums 。

你需要从数组中选出一个满足下述条件的
子集
：

你可以将选中的元素放置在一个下标从 0 开始的数组中，并使其遵循以下模式：[x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x]（注意，k 可以是任何 非负 的 2 的幂）。例如，[2, 4, 16, 4, 2] 和 [3, 9, 3] 都符合这一模式，而 [2, 4, 8, 4, 2] 则不符合。
返回满足这些条件的子集中，元素数量的 最大值 。



示例 1：

输入：nums = [5,4,1,2,2]
输出：3
解释：选择子集 {4,2,2} ，将其放在数组 [2,4,2] 中，它遵循该模式，且 22 == 4 。因此答案是 3 。
示例 2：

输入：nums = [1,3,2,4]
输出：1
解释：选择子集 {1}，将其放在数组 [1] 中，它遵循该模式。因此答案是 1 。注意我们也可以选择子集 {2} 、{4} 或 {3} ，可能存在多个子集都能得到相同的答案。


提示：

2 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
		unordered_map<int, int> numsCount;
		int maxLen = 0, maxNum = 0;

		for (int num : nums) {
			if (num == 1) {
				++maxLen;
			}
			else {
				++numsCount[num];
				maxNum = max(maxNum, num);
			}
		}

		if (maxLen != 0 && maxLen % 2 == 0) {
			--maxLen;
		}

		for (auto& kv : numsCount) {
			maxLen = max(maxLen, getMaxLen(numsCount, maxNum, kv.first));
		}

		return maxLen;
    }

	int getMaxLen(unordered_map<int, int>& numsCount, int maxNum, int num) {
		int maxLen = 0;
		long long n = num;

		while (n <= maxNum) {
			if (numsCount.count((int)n) == 0) {
				break;
			}

			if (numsCount[(int)n] == 1) {
				maxLen += 1;
				break;
			}
			else {
				maxLen += 2;
				n *= n;
			}
		}

		if (maxLen % 2 == 0) {
			--maxLen;
		}

		return maxLen;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 5,4,1,2,2 };
	check.checkInt(3, o.maximumLength(nums));

	nums = { 1,3,2,4 };
	check.checkInt(1, o.maximumLength(nums));

	nums = { 1,1 };
	check.checkInt(1, o.maximumLength(nums));

	nums = { 48841,358801,28561,18974736,4356,221,358801,599,13,4356,66,48841,28561,815730721,13,815730721,18974736,66,169,599,169,221 };
	check.checkInt(7, o.maximumLength(nums));
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
