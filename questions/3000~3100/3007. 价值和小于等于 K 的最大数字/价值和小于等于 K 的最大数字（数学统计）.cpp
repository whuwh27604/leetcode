/* 价值和小于等于 K 的最大数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 k 和一个整数 x 。

令 s 为整数 num 的下标从 1 开始的二进制表示。我们说一个整数 num 的 价值 是满足 i % x == 0 且 s[i] 是 设置位 的 i 的数目。

请你返回 最大 整数 num ，满足从 1 到 num 的所有整数的 价值 和小于等于 k 。

注意：

一个整数二进制表示下 设置位 是值为 1 的数位。
一个整数的二进制表示下标从右到左编号，比方说如果 s == 11100 ，那么 s[4] == 1 且 s[2] == 0 。


示例 1：

输入：k = 9, x = 1
输出：6
解释：数字 1 ，2 ，3 ，4 ，5 和 6 二进制表示分别为 "1" ，"10" ，"11" ，"100" ，"101" 和 "110" 。
由于 x 等于 1 ，每个数字的价值分别为所有设置位的数目。
这些数字的所有设置位数目总数是 9 ，所以前 6 个数字的价值和为 9 。
所以答案为 6 。
示例 2：

输入：k = 7, x = 2
输出：9
解释：由于 x 等于 2 ，我们检查每个数字的偶数位。
2 和 3 在二进制表示下的第二个数位为设置位，所以它们的价值和为 2 。
6 和 7 在二进制表示下的第二个数位为设置位，所以它们的价值和为 2 。
8 和 9 在二进制表示下的第四个数位为设置位但第二个数位不是设置位，所以它们的价值和为 2 。
数字 1 ，4 和 5 在二进制下偶数位都不是设置位，所以它们的价值和为 0 。
10 在二进制表示下的第二个数位和第四个数位都是设置位，所以它的价值为 2 。
前 9 个数字的价值和为 6 。
前 10 个数字的价值和为 8，超过了 k = 7 ，所以答案为 9 。


提示：

1 <= k <= 1015
1 <= x <= 8
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;
typedef long long LL;

class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
		LL low = 1, high = (k + 1) * ((LL)1 << x), maxNum = 0;  // high不可过大，否则countValue的时候会LL型溢出

		while (low <= high) {
			LL mid = (high - low) / 2 + low;
			LL cnt = countValue(mid, x);
			if (cnt > k) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
				maxNum = mid;
			}
		}

		return maxNum;
    }

	LL countValue(LL num, int x) {
		LL value = 0;

		for (LL bit = 1, index = 1; bit <= num; bit <<= 1, ++index) {  // 枚举中间位置的bit位
			if (index % x == 0) {
				LL right = num / (bit << 1);  // 在bit右边，有right + 1个数，左边的全集有bit个数
				value += (right * bit);  // 其中right个数可以匹配左边的全集

				if ((num & bit) != 0) {  // 如果num的bit位是1，那么right还可以取到最大的一个
					value += ((num & (bit - 1)) + 1);  // 此时左边只能匹配到num对应位置的最大值，加上一个0
				}
			}
		}

		return value;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkLongLong(6, o.findMaximumNumber(9, 1));
	check.checkLongLong(9, o.findMaximumNumber(7, 2));
	check.checkLongLong(343778878348159, o.findMaximumNumber(1000000000000000, 8));
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
