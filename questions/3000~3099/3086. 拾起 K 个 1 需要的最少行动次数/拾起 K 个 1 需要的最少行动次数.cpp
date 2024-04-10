/* 拾起 K 个 1 需要的最少行动次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二进制数组 nums，其长度为 n ；另给你一个 正整数 k 以及一个 非负整数 maxChanges 。

Alice 在玩一个游戏，游戏的目标是让 Alice 使用 最少 数量的 行动 次数从 nums 中拾起 k 个 1 。游戏开始时，Alice 可以选择数组 [0, n - 1] 范围内的任何索引 aliceIndex 站立。如果 nums[aliceIndex] == 1 ，Alice 会拾起一个 1 ，并且 nums[aliceIndex] 变成0（这 不算 作一次行动）。之后，Alice 可以执行 任意数量 的 行动（包括零次），在每次行动中 Alice 必须 恰好 执行以下动作之一：

选择任意一个下标 j != aliceIndex 且满足 nums[j] == 0 ，然后将 nums[j] 设置为 1 。这个动作最多可以执行 maxChanges 次。
选择任意两个相邻的下标 x 和 y（|x - y| == 1）且满足 nums[x] == 1, nums[y] == 0 ，然后交换它们的值（将 nums[y] = 1 和 nums[x] = 0）。如果 y == aliceIndex，在这次行动后 Alice 拾起一个 1 ，并且 nums[y] 变成 0 。
返回 Alice 拾起 恰好 k 个 1 所需的 最少 行动次数。



示例 1：

输入：nums = [1,1,0,0,0,1,1,0,0,1], k = 3, maxChanges = 1

输出：3

解释：如果游戏开始时 Alice 在 aliceIndex == 1 的位置上，按照以下步骤执行每个动作，他可以利用 3 次行动拾取 3 个 1 ：

游戏开始时 Alice 拾取了一个 1 ，nums[1] 变成了 0。此时 nums 变为 [1,1,1,0,0,1,1,0,0,1] 。
选择 j == 2 并执行第一种类型的动作。nums 变为 [1,0,1,0,0,1,1,0,0,1]
选择 x == 2 和 y == 1 ，并执行第二种类型的动作。nums 变为 [1,1,0,0,0,1,1,0,0,1] 。由于 y == aliceIndex，Alice 拾取了一个 1 ，nums 变为  [1,0,0,0,0,1,1,0,0,1] 。
选择 x == 0 和 y == 1 ，并执行第二种类型的动作。nums 变为 [0,1,0,0,0,1,1,0,0,1] 。由于 y == aliceIndex，Alice 拾取了一个 1 ，nums 变为  [0,0,0,0,0,1,1,0,0,1] 。
请注意，Alice 也可能执行其他的 3 次行动序列达成拾取 3 个 1 。

示例 2：

输入：nums = [0,0,0,0], k = 2, maxChanges = 3

输出：4

解释：如果游戏开始时 Alice 在 aliceIndex == 0 的位置上，按照以下步骤执行每个动作，他可以利用 4 次行动拾取 2 个 1 ：

选择 j == 1 并执行第一种类型的动作。nums 变为 [0,1,0,0] 。
选择 x == 1 和 y == 0 ，并执行第二种类型的动作。nums 变为 [1,0,0,0] 。由于 y == aliceIndex，Alice 拾起了一个 1 ，nums 变为 [0,0,0,0] 。
再次选择 j == 1 并执行第一种类型的动作。nums 变为 [0,1,0,0] 。
再次选择 x == 1 和 y == 0 ，并执行第二种类型的动作。nums 变为 [1,0,0,0] 。由于y == aliceIndex，Alice 拾起了一个 1 ，nums 变为 [0,0,0,0] 。


提示：

2 <= n <= 105
0 <= nums[i] <= 1
1 <= k <= 105
0 <= maxChanges <= 105
maxChanges + sum(nums) >= k
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
	long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
		long long minMoves = LLONG_MAX;
		int n = (int)nums.size();
		vector<int> indices;
		int ones = getMaxConsectiveOnes(n, nums, indices);

		if (ones + maxChanges >= k) {
			return k > ones ? (k - ones) * 2 + (ones == 0 ? 0 : ones - 1) : k - 1;
		}

		k -= maxChanges;
		int half1 = k / 2, half2 = (k - 1) / 2;
		int size = (int)indices.size();
		vector<long long> presum(size + 1, 0);
		for (int i = 0; i < size; ++i) {
			presum[i + 1] = presum[i] + indices[i];
		}

		for (int right = k - 1; right < size; ++right) {
			int left = right - k + 1, median = right - half2;
			long long moves = (long long)indices[median] * half1 - (presum[median] - presum[left]);
			moves += presum[right + 1] - presum[median + 1] - (long long)indices[median] * half2;
			minMoves = min(minMoves, moves);
		}

		return minMoves + 2 * maxChanges;
    }

	int getMaxConsectiveOnes(int n, vector<int>& nums, vector<int>& indices) {
		int len = 0, maxLen = 0;

		for (int i = 0; i < n; ++i) {
			if (nums[i] == 0) {
				len = 0;
			}
			else {
				maxLen = max(maxLen, ++len);
				indices.push_back(i);
			}
		}

		return maxLen > 3 ? 3 : maxLen;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,1,0,0,0,1,1,0,0,1 };
	check.checkLongLong(3, o.minimumMoves(nums, 3, 1));

	nums = { 0,0,0,0 };
	check.checkLongLong(4, o.minimumMoves(nums, 2, 3));

	nums = { 1,1 };
	check.checkLongLong(0, o.minimumMoves(nums, 1, 2));
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
