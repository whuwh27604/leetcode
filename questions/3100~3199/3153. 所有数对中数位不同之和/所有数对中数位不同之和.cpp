/* 所有数对中数位不同之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
车尔尼有一个数组 nums ，它只包含 正 整数，所有正整数的数位长度都 相同 。

两个整数的 数位不同 指的是两个整数 相同 位置上不同数字的数目。

请车尔尼返回 nums 中 所有 整数对里，数位不同之和。



示例 1：

输入：nums = [13,23,12]

输出：4

解释：
计算过程如下：
- 13 和 23 的数位不同为 1 。
- 13 和 12 的数位不同为 1 。
- 23 和 12 的数位不同为 2 。
所以所有整数数对的数位不同之和为 1 + 1 + 2 = 4 。

示例 2：

输入：nums = [10,10,10,10]

输出：0

解释：
数组中所有整数都相同，所以所有整数数对的数位不同之和为 0 。



提示：

2 <= nums.length <= 105
1 <= nums[i] < 109
nums 中的整数都有相同的数位长度。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
		long long diffs = 0;

		while (nums[0] != 0) {
			vector<int> count(10, 0);
			long long sum = 0;

			for (int& num : nums) {
				++count[num % 10];
				num /= 10;
			}

			for (int cnt : count) {
				diffs += (cnt * sum);
				sum += cnt;
			}
		}

		return diffs;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 13,23,12 };
	check.checkLongLong(4, o.sumDigitDifferences(nums));

	nums = { 10,10,10,10 };
	check.checkLongLong(0, o.sumDigitDifferences(nums));

	nums = { 50,28,48 };
	check.checkLongLong(5, o.sumDigitDifferences(nums));
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
