/* 特殊数组 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果数组的每一对相邻元素都是两个奇偶性不同的数字，则该数组被认为是一个 特殊数组 。

Aging 有一个整数数组 nums。如果 nums 是一个 特殊数组 ，返回 true，否则返回 false。



示例 1：

输入：nums = [1]

输出：true

解释：

只有一个元素，所以答案为 true。

示例 2：

输入：nums = [2,1,4]

输出：true

解释：

只有两对相邻元素： (2,1) 和 (1,4)，它们都包含了奇偶性不同的数字，因此答案为 true。

示例 3：

输入：nums = [4,3,1,6]

输出：false

解释：

nums[1] 和 nums[2] 都是奇数。因此答案为 false。



提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
		for (int i = 1; i < (int)nums.size(); ++i) {
			if (((nums[i] ^ nums[i - 1]) & 1) == 0) {
				return false;
			}
		}

		return true;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1 };
	check.checkBool(true, o.isArraySpecial(nums));

	nums = { 2,1,4 };
	check.checkBool(true, o.isArraySpecial(nums));

	nums = { 4,3,1,6 };
	check.checkBool(false, o.isArraySpecial(nums));
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
