/* 划分数组得到最小的值之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个数组 nums 和 andValues，长度分别为 n 和 m。

数组的 值 等于该数组的 最后一个 元素。

你需要将 nums 划分为 m 个 不相交的连续 子数组，对于第 ith 个子数组 [li, ri]，子数组元素的按位AND运算结果等于 andValues[i]，换句话说，对所有的 1 <= i <= m，nums[li] & nums[li + 1] & ... & nums[ri] == andValues[i] ，其中 & 表示按位AND运算符。

返回将 nums 划分为 m 个子数组所能得到的可能的 最小 子数组 值 之和。如果无法完成这样的划分，则返回 -1 。



示例 1：

输入： nums = [1,4,3,3,2], andValues = [0,3,3,2]

输出： 12

解释：

唯一可能的划分方法为：

[1,4] 因为 1 & 4 == 0
[3] 因为单元素子数组的按位 AND 结果就是该元素本身
[3] 因为单元素子数组的按位 AND 结果就是该元素本身
[2] 因为单元素子数组的按位 AND 结果就是该元素本身
这些子数组的值之和为 4 + 3 + 3 + 2 = 12

示例 2：

输入： nums = [2,3,5,7,7,7,5], andValues = [0,7,5]

输出： 17

解释：

划分 nums 的三种方式为：

[[2,3,5],[7,7,7],[5]] 其中子数组的值之和为 5 + 7 + 5 = 17
[[2,3,5,7],[7,7],[5]] 其中子数组的值之和为 7 + 7 + 5 = 19
[[2,3,5,7,7],[7],[5]] 其中子数组的值之和为 7 + 7 + 5 = 19
子数组值之和的最小可能值为 17

示例 3：

输入： nums = [1,2,3,4], andValues = [2]

输出： -1

解释：

整个数组 nums 的按位 AND 结果为 0。由于无法将 nums 划分为单个子数组使得元素的按位 AND 结果为 2，因此返回 -1。



提示：

1 <= n == nums.length <= 104
1 <= m == andValues.length <= min(n, 10)
1 <= nums[i] < 105
0 <= andValues[j] < 105
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
		n = (int)nums.size();
		m = (int)andValues.size();
		numbers = nums;
		andVals = andValues;
		memo.clear();
		int ans = DFS(0, 0, init);

		return ans >= inf ? -1 : ans;
    }

	int DFS(int index, int subs, int andVal) {
		if (subs == m) {
			return index == n ? 0 : inf;  // 成功划分完成
		}

		if (n - index < m - subs) {  // 剪枝，剩下的数已经不够组数
			return inf;
		}

		andVal &= numbers[index];
		if (andVal < andVals[subs]) {  // 剪枝，已经不可能划分出第subs组了
			return inf;
		}

		long long state = (((long long)index * 100 + subs) << 32) | andVal;
		if (memo.count(state) != 0) {  // 已经计算过该状态
			return memo[state];
		}

		int ans = DFS(index + 1, subs, andVal);  // 不划分
		if (andVal == andVals[subs]) {
			ans = min(ans, DFS(index + 1, subs + 1, init) + numbers[index]);  // 划分，index是第subs组的最后一个数
		}

		return memo[state] = ans;
	}

	int n = 0;
	int m = 0;
	int init = 0x7fffffff;
	int inf = INT_MAX / 10;
	vector<int> numbers;
	vector<int> andVals;
	unordered_map<long long, int> memo;
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,4,3,3,2 };
	vector<int> andValues = { 0,3,3,2 };
	check.checkInt(12, o.minimumValueSum(nums, andValues));

	nums = { 2,3,5,7,7,7,5 };
	andValues = { 0,7,5 };
	check.checkInt(17, o.minimumValueSum(nums, andValues));

	nums = { 1,2,3,4 };
	andValues = { 2 };
	check.checkInt(-1, o.minimumValueSum(nums, andValues));

	nums = { 12,13 };
	andValues = { 12,12 };
	check.checkInt(-1, o.minimumValueSum(nums, andValues));
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
