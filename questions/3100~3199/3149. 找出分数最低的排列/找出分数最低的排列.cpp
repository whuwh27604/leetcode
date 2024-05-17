/* 找出分数最低的排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 nums ，它是 [0, 1, 2, ..., n - 1] 的一个
排列
 。对于任意一个 [0, 1, 2, ..., n - 1] 的排列 perm ，其 分数 定义为：

score(perm) = |perm[0] - nums[perm[1]]| + |perm[1] - nums[perm[2]]| + ... + |perm[n - 1] - nums[perm[0]]|

返回具有 最低 分数的排列 perm 。如果存在多个满足题意且分数相等的排列，则返回其中
字典序最小
的一个。



示例 1：

输入：nums = [1,0,2]

输出：[0,1,2]

解释：



字典序最小且分数最低的排列是 [0,1,2]。这个排列的分数是 |0 - 0| + |1 - 2| + |2 - 1| = 2 。

示例 2：

输入：nums = [0,2,1]

输出：[0,2,1]

解释：



字典序最小且分数最低的排列是 [0,2,1]。这个排列的分数是 |0 - 1| + |2 - 2| + |1 - 0| = 2 。



提示：

2 <= n == nums.length <= 14
nums 是 [0, 1, 2, ..., n - 1] 的一个排列。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findPermutation(vector<int>& nums_) {
		init(nums_);
		(void)DFS(1, 0);  // 旋转一个perm，score不变，所以perm[0]一定是0

		return getPermutation();
    }

	int DFS(int mask, int last) {  // DFS返回上一个数是last，可选数是mask的状态下，可以取得的最小score
		if (mask == target) {  // 找到一个perm，计算最后一个score
			return abs(last - nums[0]);
		}

		int state = ((last << n) | mask);
		int& ans = memo[state];
		if (ans != inf) {  // 已经计算过该状态，直接返回答案
			return ans;
		}

		int minScore = inf;
		for (int i = 0, bit = 1; i < n; ++i, bit <<= 1) {  // 从小到大遍历，得到的字典序最小
			if ((mask & bit) == 0) {
				int score = abs(last - nums[i]) + DFS(mask | bit, i);  // 注意abs(last - nums[i])要算在这个状态的score里面
				if (score < minScore) {
					minScore = score;
					next[state] = ((i << n) | (mask | bit));  // 记录状态迁移表，用来恢复答案
				}
			}
		}

		return ans = minScore;  // 记忆化避免重复计算
	}

	vector<int> getPermutation() {
		vector<int> permutation(n);

		for (int i = 0, mask = 1; i < n; ++i, mask = next[mask]) {
			permutation[i] = (mask >> n);
		}

		return permutation;
	}

	Solution() : n(0), target(0), inf(INT_MAX / 2) {}

	void init(vector<int>& nums_) {
		nums = nums_;
		n = (int)nums.size();
		target = (1 << n) - 1;
		memo.clear();
		memo.resize((size_t)1 << (n + 4), inf);  // (num << n) | mask构成一个状态
		next.clear();
		next.resize((size_t)1 << (n + 4));
	}

	int n;
	int target;
	int inf;
	vector<int> nums;
	vector<int> memo;
	vector<int> next;
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,0,2 };
	vector<int> actual = o.findPermutation(nums);
	vector<int> expected = { 0,1,2 };
	check.checkIntVector(expected, actual);

	nums = { 0,2,1 };
	actual = o.findPermutation(nums);
	expected = { 0,2,1 };
	check.checkIntVector(expected, actual);

	nums = { 2,1,0 };
	actual = o.findPermutation(nums);
	expected = { 0,1,2 };
	check.checkIntVector(expected, actual);

	nums = { 0,2,1,3,4 };
	actual = o.findPermutation(nums);
	expected = { 0,2,3,4,1 };
	check.checkIntVector(expected, actual);

	nums = { 0,3,4,1,2 };
	actual = o.findPermutation(nums);
	expected = { 0,3,1,4,2 };
	check.checkIntVector(expected, actual);

	nums = { 0,1,2,3,4 };
	actual = o.findPermutation(nums);
	expected = { 0,1,2,3,4 };
	check.checkIntVector(expected, actual);

	nums = { 0,1,2,3,4,5 };
	actual = o.findPermutation(nums);
	expected = { 0,1,2,3,4,5 };
	check.checkIntVector(expected, actual);

	nums = { 1,4,3,2,0,5 };
	actual = o.findPermutation(nums);
	expected = { 0,4,2,3,5,1 };
	check.checkIntVector(expected, actual);

	nums = { 1,3,2,4,5,0 };
	actual = o.findPermutation(nums);
	expected = { 0,5,4,3,1,2 };
	check.checkIntVector(expected, actual);
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
