/* 找出 K 秒后拿着球的孩子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 正整数 n 和 k。有 n 个编号从 0 到 n - 1 的孩子按顺序从左到右站成一队。

最初，编号为 0 的孩子拿着一个球，并且向右传球。每过一秒，拿着球的孩子就会将球传给他旁边的孩子。一旦球到达队列的 任一端 ，即编号为 0 的孩子或编号为 n - 1 的孩子处，传球方向就会 反转 。

返回 k 秒后接到球的孩子的编号。



示例 1：

输入：n = 3, k = 5

输出：1

解释：

经过的时间	孩子队列
0	[0, 1, 2]
1	[0, 1, 2]
2	[0, 1, 2]
3	[0, 1, 2]
4	[0, 1, 2]
5	[0, 1, 2]
示例 2：

输入：n = 5, k = 6

输出：2

解释：

经过的时间	孩子队列
0	[0, 1, 2, 3, 4]
1	[0, 1, 2, 3, 4]
2	[0, 1, 2, 3, 4]
3	[0, 1, 2, 3, 4]
4	[0, 1, 2, 3, 4]
5	[0, 1, 2, 3, 4]
6	[0, 1, 2, 3, 4]
示例 3：

输入：n = 4, k = 2

输出：2

解释：

经过的时间	孩子队列
0	[0, 1, 2, 3]
1	[0, 1, 2, 3]
2	[0, 1, 2, 3]


提示：

2 <= n <= 50
1 <= k <= 50
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfChild(int n, int k) {
        int a = k / (n - 1), b = k % (n - 1);

        return (a & 1) == 0 ? b : n - 1 - b;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.numberOfChild(3, 5));
    check.checkInt(2, o.numberOfChild(5, 6));
    check.checkInt(2, o.numberOfChild(4, 2));
    check.checkInt(0, o.numberOfChild(4, 6));
    check.checkInt(2, o.numberOfChild(4, 10));
    check.checkInt(1, o.numberOfChild(2, 1));
    check.checkInt(0, o.numberOfChild(2, 2));
    check.checkInt(1, o.numberOfChild(2, 3));
    check.checkInt(0, o.numberOfChild(2, 4));
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
