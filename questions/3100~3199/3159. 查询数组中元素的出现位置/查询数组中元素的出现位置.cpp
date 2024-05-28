/* 查询数组中元素的出现位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
* 给你一个整数数组 nums ，一个整数数组 queries 和一个整数 x 。

对于每个查询 queries[i] ，你需要找到 nums 中第 queries[i] 个 x 的位置，并返回它的下标。如果数组中 x 的出现次数少于 queries[i] ，该查询的答案为 -1 。

请你返回一个整数数组 answer ，包含所有查询的答案。

 

示例 1：

输入：nums = [1,3,1,7], queries = [1,3,2,4], x = 1

输出：[0,-1,2,-1]

解释：

第 1 个查询，第一个 1 出现在下标 0 处。
第 2 个查询，nums 中只有两个 1 ，所以答案为 -1 。
第 3 个查询，第二个 1 出现在下标 2 处。
第 4 个查询，nums 中只有两个 1 ，所以答案为 -1 。
示例 2：

输入：nums = [1,2,3], queries = [10], x = 5

输出：[-1]

解释：

第 1 个查询，nums 中没有 5 ，所以答案为 -1 。
 

提示：

1 <= nums.length, queries.length <= 105
1 <= queries[i] <= 105
1 <= nums[i], x <= 104
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
		vector<int> indices, res(queries.size(), -1);

		for (int i = 0; i < (int)nums.size(); ++i) {
			if (nums[i] == x) {
				indices.push_back(i);
			}
		}

		for (int i = 0; i < (int)queries.size(); ++i) {
			if (queries[i] <= indices.size()) {
				res[i] = indices[queries[i] - 1];
			}
		}

		return res;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,3,1,7 };
	vector<int> queries = { 1,3,2,4 };
	vector<int> actual = o.occurrencesOfElement(nums, queries, 1);
	vector<int> expected = { 0,-1,2,-1 };
	check.checkIntVector(expected, actual);

	nums = { 1,2,3 };
	queries = { 10 };
	actual = o.occurrencesOfElement(nums, queries, 5);
	expected = { -1 };
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
