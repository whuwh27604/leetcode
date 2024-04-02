/* 最高频率的 ID.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你需要在一个集合里动态记录 ID 的出现频率。给你两个长度都为 n 的整数数组 nums 和 freq ，nums 中每一个元素表示一个 ID ，对应的 freq 中的元素表示这个 ID 在集合中此次操作后需要增加或者减少的数目。

增加 ID 的数目：如果 freq[i] 是正数，那么 freq[i] 个 ID 为 nums[i] 的元素在第 i 步操作后会添加到集合中。
减少 ID 的数目：如果 freq[i] 是负数，那么 -freq[i] 个 ID 为 nums[i] 的元素在第 i 步操作后会从集合中删除。
请你返回一个长度为 n 的数组 ans ，其中 ans[i] 表示第 i 步操作后出现频率最高的 ID 数目 ，如果在某次操作后集合为空，那么 ans[i] 为 0 。



示例 1：

输入：nums = [2,3,2,1], freq = [3,2,-3,1]

输出：[3,3,2,2]

解释：

第 0 步操作后，有 3 个 ID 为 2 的元素，所以 ans[0] = 3 。
第 1 步操作后，有 3 个 ID 为 2 的元素和 2 个 ID 为 3 的元素，所以 ans[1] = 3 。
第 2 步操作后，有 2 个 ID 为 3 的元素，所以 ans[2] = 2 。
第 3 步操作后，有 2 个 ID 为 3 的元素和 1 个 ID 为 1 的元素，所以 ans[3] = 2 。

示例 2：

输入：nums = [5,5,3], freq = [2,-2,1]

输出：[2,0,1]

解释：

第 0 步操作后，有 2 个 ID 为 5 的元素，所以 ans[0] = 2 。
第 1 步操作后，集合中没有任何元素，所以 ans[1] = 0 。
第 2 步操作后，有 1 个 ID 为 3 的元素，所以 ans[2] = 1 。



提示：

1 <= nums.length == freq.length <= 105
1 <= nums[i] <= 105
-105 <= freq[i] <= 105
freq[i] != 0
输入保证任何操作后，集合中的元素出现次数不会为负数。
*/

#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
		int size = nums.size(), idx = 0;
		map<long long, unordered_set<int>> freqNums;
		unordered_map<int, long long> numFreqs;
		vector<long long> maxFreqs(size, 0);

		for (int i = 0; i < size; ++i) {
			int num = nums[i], delta = freq[i];
			long long frq = numFreqs[num];
			freqNums[frq].erase(num);
			if (freqNums[frq].empty()) {
				freqNums.erase(frq);
			}
			frq += delta;
			numFreqs[num] = frq;
			freqNums[frq].insert(num);
			maxFreqs[idx++] = freqNums.rbegin()->first;
		}

		return maxFreqs;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 2,3,2,1 };
	vector<int> freq = { 3,2,-3,1 };
	vector<long long> actual = o.mostFrequentIDs(nums, freq);
	vector<long long> expected = { 3,3,2,2 };
	check.checkLongLongVector(expected, actual);

	nums = { 5,5,3 };
	freq = { 2,-2,1 };
	actual = o.mostFrequentIDs(nums, freq);
	expected = { 2,0,1 };
	check.checkLongLongVector(expected, actual);
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
