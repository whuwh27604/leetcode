/* 哈沙德数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一个整数能够被其各个数位上的数字之和整除，则称之为 哈沙德数（Harshad number）。给你一个整数 x 。如果 x 是 哈沙德数 ，则返回 x 各个数位上的数字之和，否则，返回 -1 。



示例 1：

输入： x = 18

输出： 9

解释：

x 各个数位上的数字之和为 9 。18 能被 9 整除。因此 18 是哈沙德数，答案是 9 。

示例 2：

输入： x = 23

输出： -1

解释：

x 各个数位上的数字之和为 5 。23 不能被 5 整除。因此 23 不是哈沙德数，答案是 -1 。



提示：

1 <= x <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
		int num = x, sum = 0;

		while (num != 0) {
			sum += (num % 10);
			num /= 10;
		}

		return (x % sum == 0) ? sum : -1;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(9, o.sumOfTheDigitsOfHarshadNumber(18));
	check.checkInt(-1, o.sumOfTheDigitsOfHarshadNumber(23));
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
