/* Alice 和 Bob 玩鲜花游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 和 Bob 在一个长满鲜花的环形草地玩一个回合制游戏。环形的草地上有一些鲜花，Alice 到 Bob 之间顺时针有 x 朵鲜花，逆时针有 y 朵鲜花。

游戏过程如下：

Alice 先行动。
每一次行动中，当前玩家必须选择顺时针或者逆时针，然后在这个方向上摘一朵鲜花。
一次行动结束后，如果所有鲜花都被摘完了，那么 当前 玩家抓住对手并赢得游戏的胜利。
给你两个整数 n 和 m ，你的任务是求出满足以下条件的所有 (x, y) 对：

按照上述规则，Alice 必须赢得游戏。
Alice 顺时针方向上的鲜花数目 x 必须在区间 [1,n] 之间。
Alice 逆时针方向上的鲜花数目 y 必须在区间 [1,m] 之间。
请你返回满足题目描述的数对 (x, y) 的数目。



示例 1：

输入：n = 3, m = 2
输出：3
解释：以下数对满足题目要求：(1,2) ，(3,2) ，(2,1) 。
示例 2：

输入：n = 1, m = 1
输出：0
解释：没有数对满足题目要求。


提示：

1 <= n, m <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
		return ((long long)n + 1) / 2 * (m / 2) + ((long long)m + 1) / 2 * (n / 2);
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkLongLong(3, o.flowerGame(3, 2));
	check.checkLongLong(0, o.flowerGame(1, 1));
	check.checkLongLong(8, o.flowerGame(4, 4));
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
