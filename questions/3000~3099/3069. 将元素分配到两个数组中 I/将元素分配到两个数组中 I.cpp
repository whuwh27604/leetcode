/* 将元素分配到两个数组中 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 1 开始、包含 不同 整数的数组 nums ，数组长度为 n 。

你需要通过 n 次操作，将 nums 中的所有元素分配到两个数组 arr1 和 arr2 中。在第一次操作中，将 nums[1] 追加到 arr1 。在第二次操作中，将 nums[2] 追加到 arr2 。之后，在第 i 次操作中：

如果 arr1 的最后一个元素 大于 arr2 的最后一个元素，就将 nums[i] 追加到 arr1 。否则，将 nums[i] 追加到 arr2 。
通过连接数组 arr1 和 arr2 形成数组 result 。例如，如果 arr1 == [1,2,3] 且 arr2 == [4,5,6] ，那么 result = [1,2,3,4,5,6] 。

返回数组 result 。



示例 1：

输入：nums = [2,1,3]
输出：[2,3,1]
解释：在前两次操作后，arr1 = [2] ，arr2 = [1] 。
在第 3 次操作中，由于 arr1 的最后一个元素大于 arr2 的最后一个元素（2 > 1），将 nums[3] 追加到 arr1 。
3 次操作后，arr1 = [2,3] ，arr2 = [1] 。
因此，连接形成的数组 result 是 [2,3,1] 。
示例 2：

输入：nums = [5,4,3,8]
输出：[5,3,4,8]
解释：在前两次操作后，arr1 = [5] ，arr2 = [4] 。
在第 3 次操作中，由于 arr1 的最后一个元素大于 arr2 的最后一个元素（5 > 4），将 nums[3] 追加到 arr1 ，因此 arr1 变为 [5,3] 。
在第 4 次操作中，由于 arr2 的最后一个元素大于 arr1 的最后一个元素（4 > 3），将 nums[4] 追加到 arr2 ，因此 arr2 变为 [4,8] 。
4 次操作后，arr1 = [5,3] ，arr2 = [4,8] 。
因此，连接形成的数组 result 是 [5,3,4,8] 。


提示：

3 <= n <= 50
1 <= nums[i] <= 100
nums中的所有元素都互不相同。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> arr1 = { nums[0] };
		vector<int> arr2 = { nums[1] };

		for (int i = 2; i < n; ++i) {
			if (arr1.back() > arr2.back()) {
				arr1.push_back(nums[i]);
			}
			else {
				arr2.push_back(nums[i]);
			}
		}

		arr1.insert(arr1.end(), arr2.begin(), arr2.end());

		return arr1;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 2,1,3 };
	vector<int> actual = o.resultArray(nums);
	vector<int> expected = { 2,3,1 };
	check.checkIntVector(expected, actual);

	nums = { 5,4,3,8 };
	actual = o.resultArray(nums);
	expected = { 5,3,4,8 };
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
