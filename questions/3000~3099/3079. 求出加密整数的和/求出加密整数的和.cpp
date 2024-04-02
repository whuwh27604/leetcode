/* 求出加密整数的和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，数组中的元素都是 正 整数。定义一个加密函数 encrypt ，encrypt(x) 将一个整数 x 中 每一个 数位都用 x 中的 最大 数位替换。比方说 encrypt(523) = 555 且 encrypt(213) = 333 。

请你返回数组中所有元素加密后的 和 。



示例 1：

输入：nums = [1,2,3]

输出：6

解释：加密后的元素位 [1,2,3] 。加密元素的和为 1 + 2 + 3 == 6 。

示例 2：

输入：nums = [10,21,31]

输出：66

解释：加密后的元素为 [11,22,33] 。加密元素的和为 11 + 22 + 33 == 66 。



提示：

1 <= nums.length <= 50
1 <= nums[i] <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
		int sum = 0;

		for (int num : nums) {
			sum += encrypt(num);
		}

		return sum;
    }

	int encrypt(int num) {
		int d = 0, m = 0;

		while (num != 0) {
			m = max(m, num % 10);
			d = d * 10 + 1;
			num /= 10;
		}

		return d * m;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,3 };
	check.checkInt(6, o.sumOfEncryptedInt(nums));

	nums = { 10,21,31 };
	check.checkInt(66, o.sumOfEncryptedInt(nums));
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
