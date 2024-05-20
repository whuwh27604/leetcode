/* 特殊数组 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果数组的每一对相邻元素都是两个奇偶性不同的数字，则该数组被认为是一个 特殊数组 。

周洋哥有一个整数数组 nums 和一个二维整数矩阵 queries，对于 queries[i] = [fromi, toi]，请你帮助周洋哥检查子数组 nums[fromi..toi] 是不是一个 特殊数组 。

返回布尔数组 answer，如果 nums[fromi..toi] 是特殊数组，则 answer[i] 为 true ，否则，answer[i] 为 false 。



示例 1：

输入：nums = [3,4,1,2,6], queries = [[0,4]]

输出：[false]

解释：

子数组是 [3,4,1,2,6]。2 和 6 都是偶数。

示例 2：

输入：nums = [4,3,1,6], queries = [[0,2],[2,3]]

输出：[false,true]

解释：

子数组是 [4,3,1]。3 和 1 都是奇数。因此这个查询的答案是 false。
子数组是 [1,6]。只有一对：(1,6)，且包含了奇偶性不同的数字。因此这个查询的答案是 true。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] <= nums.length - 1
*/

#include <iostream>

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
		int size = (int)nums.size();
		vector<int> presum(size, 0);
		vector<bool> ans;

		for (int i = 1; i < size; ++i) {
			presum[i] = ((nums[i] ^ nums[i - 1]) & 1) + presum[i - 1];
		}

		for (auto& query : queries) {
			ans.push_back(presum[query[1]] - presum[query[0]] == query[1] - query[0]);
		}

		return ans;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 3,4,1,2,6 };
	vector<vector<int>> queries = { {0,4} };
	vector<bool> actual = o.isArraySpecial(nums, queries);
	vector<bool> expected = { false };
	check.checkBoolVector(expected, actual);

	nums = { 4,3,1,6 };
	queries = { {0,2},{2,3} };
	actual = o.isArraySpecial(nums, queries);
	expected = { false,true };
	check.checkBoolVector(expected, actual);
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
