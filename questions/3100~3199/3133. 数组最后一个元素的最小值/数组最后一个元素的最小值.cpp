/* 数组最后一个元素的最小值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 n 和 x 。你需要构造一个长度为 n 的 正整数 数组 nums ，对于所有 0 <= i < n - 1 ，满足 nums[i + 1] 大于 nums[i] ，并且数组 nums 中所有元素的按位 AND 运算结果为 x 。

返回 nums[n - 1] 可能的 最小 值。



示例 1：

输入：n = 3, x = 4

输出：6

解释：

数组 nums 可以是 [4,5,6] ，最后一个元素为 6 。

示例 2：

输入：n = 2, x = 7

输出：15

解释：

数组 nums 可以是 [7,15] ，最后一个元素为 15 。



提示：

1 <= n, x <= 108
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
		n -= 1;  // 将n - 1的bit位，依次插入x的bit==0的位置
		long long bit = 1, ans = x;

		while (n != 0) {
			while ((ans & bit) != 0) {
				bit <<= 1;
			}

			if ((n & 1) == 1) {
				ans ^= bit;
			}

			n >>= 1;
			bit <<= 1;
		}

		return ans;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkLongLong(6, o.minEnd(3, 4));
	check.checkLongLong(15, o.minEnd(2, 7));
	check.checkLongLong(55012476815, o.minEnd(6715154, 7193485));
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
