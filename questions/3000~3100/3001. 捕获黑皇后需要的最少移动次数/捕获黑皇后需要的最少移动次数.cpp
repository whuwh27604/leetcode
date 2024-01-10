/* 捕获黑皇后需要的最少移动次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现有一个下标从 0 开始的 8 x 8 棋盘，上面有 3 枚棋子。

给你 6 个整数 a 、b 、c 、d 、e 和 f ，其中：

(a, b) 表示白色车的位置。
(c, d) 表示白色象的位置。
(e, f) 表示黑皇后的位置。
假定你只能移动白色棋子，返回捕获黑皇后所需的最少移动次数。

请注意：

车可以向垂直或水平方向移动任意数量的格子，但不能跳过其他棋子。
象可以沿对角线方向移动任意数量的格子，但不能跳过其他棋子。
如果车或象能移向皇后所在的格子，则认为它们可以捕获皇后。
皇后不能移动。


示例 1：


输入：a = 1, b = 1, c = 8, d = 8, e = 2, f = 3
输出：2
解释：将白色车先移动到 (1, 3) ，然后移动到 (2, 3) 来捕获黑皇后，共需移动 2 次。
由于起始时没有任何棋子正在攻击黑皇后，要想捕获黑皇后，移动次数不可能少于 2 次。
示例 2：


输入：a = 5, b = 3, c = 3, d = 4, e = 5, f = 2
输出：1
解释：可以通过以下任一方式移动 1 次捕获黑皇后：
- 将白色车移动到 (5, 2) 。
- 将白色象移动到 (5, 2) 。


提示：

1 <= a, b, c, d, e, f <= 8
两枚棋子不会同时出现在同一个格子上。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
		if (a == e && (c != e || (c == e && (d < min(b, f) || d > max(b, f))))) {
			return 1;  // 车后同行，象不在中间，直接捕获
		}

		if (b == f && (d != f || (d == f && (c < min(a, e) || c > max(a, e))))) {
			return 1;  // 车后同列，象不在中间，直接捕获
		}

		if (c + d == e + f && (a + b != e + f || (a + b == e + f && (a < min(c, e) || a > max(c, e))))) {
			return 1;  // 象后同对角线，车不在中间，直接捕获
		}

		if (c - d == e - f && (a - b != e - f || (a - b == e - f && (a < min(c, e) || a > max(c, e))))) {
			return 1;  // 象后同反对角线，车不在中间，直接捕获
		}

		return 2;  // 其它情况都可以通过最多2步移动，捕获皇后
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(2, o.minMovesToCaptureTheQueen(1, 1, 8, 8, 2, 3));
	check.checkInt(1, o.minMovesToCaptureTheQueen(5, 3, 3, 4, 5, 2));
	check.checkInt(1, o.minMovesToCaptureTheQueen(1, 1, 8, 8, 4, 4));
	check.checkInt(1, o.minMovesToCaptureTheQueen(1, 2, 1, 1, 1, 4));
	check.checkInt(1, o.minMovesToCaptureTheQueen(1, 2, 1, 5, 1, 4));
	check.checkInt(1, o.minMovesToCaptureTheQueen(2, 1, 1, 1, 4, 1));
	check.checkInt(1, o.minMovesToCaptureTheQueen(2, 1, 5, 1, 4, 1));
	check.checkInt(1, o.minMovesToCaptureTheQueen(1, 1, 2, 2, 4, 4));
	check.checkInt(1, o.minMovesToCaptureTheQueen(5, 5, 2, 2, 4, 4));
	check.checkInt(1, o.minMovesToCaptureTheQueen(6, 1, 5, 2, 3, 4));
	check.checkInt(1, o.minMovesToCaptureTheQueen(2, 5, 5, 2, 3, 4));
	check.checkInt(2, o.minMovesToCaptureTheQueen(1, 2, 1, 3, 1, 4));
	check.checkInt(2, o.minMovesToCaptureTheQueen(2, 1, 3, 1, 4, 1));
	check.checkInt(2, o.minMovesToCaptureTheQueen(3, 3, 2, 2, 4, 4));
	check.checkInt(2, o.minMovesToCaptureTheQueen(4, 3, 5, 2, 3, 4));
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
