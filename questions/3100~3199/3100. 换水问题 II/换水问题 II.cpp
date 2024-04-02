/* 换水问题 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 numBottles 和 numExchange 。

numBottles 代表你最初拥有的满水瓶数量。在一次操作中，你可以执行以下操作之一：

喝掉任意数量的满水瓶，使它们变成空水瓶。
用 numExchange 个空水瓶交换一个满水瓶。然后，将 numExchange 的值增加 1 。
注意，你不能使用相同的 numExchange 值交换多批空水瓶。例如，如果 numBottles == 3 并且 numExchange == 1 ，则不能用 3 个空水瓶交换成 3 个满水瓶。

返回你 最多 可以喝到多少瓶水。



示例 1：


输入：numBottles = 13, numExchange = 6
输出：15
解释：上表显示了满水瓶的数量、空水瓶的数量、numExchange 的值，以及累计喝掉的水瓶数量。
示例 2：


输入：numBottles = 10, numExchange = 3
输出：13
解释：上表显示了满水瓶的数量、空水瓶的数量、numExchange 的值，以及累计喝掉的水瓶数量。


提示：

1 <= numBottles <= 100
1 <= numExchange <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
		int empty = 0, drunk = 0;

		while (numBottles != 0) {
			drunk += numBottles;
			empty += numBottles;
			numBottles = 0;

			while (empty >= numExchange) {
				empty -= numExchange++;
				++numBottles;
			}
		}

		return drunk;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(15, o.maxBottlesDrunk(13, 6));
	check.checkInt(13, o.maxBottlesDrunk(10, 3));
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
