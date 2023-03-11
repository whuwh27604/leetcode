/* 递枕头.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
最初，排在队首的第一个人拿着一个枕头。每秒钟，拿着枕头的人会将枕头传递给队伍中的下一个人。一旦枕头到达队首或队尾，传递方向就会改变，队伍会继续沿相反方向传递枕头。

例如，当枕头到达第 n 个人时，TA 会将枕头传递给第 n - 1 个人，然后传递给第 n - 2 个人，依此类推。
给你两个正整数 n 和 time ，返回 time 秒后拿着枕头的人的编号。



示例 1：

输入：n = 4, time = 5
输出：2
解释：队伍中枕头的传递情况为：1 -> 2 -> 3 -> 4 -> 3 -> 2 。
5 秒后，枕头传递到第 2 个人手中。
示例 2：

输入：n = 3, time = 2
输出：3
解释：队伍中枕头的传递情况为：1 -> 2 -> 3 。
2 秒后，枕头传递到第 3 个人手中。


提示：

2 <= n <= 1000
1 <= time <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        return ((time / (n - 1)) & 1) == 0 ? 1 + time % (n - 1) : n - time % (n - 1);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.passThePillow(4, 5));
    check.checkInt(3, o.passThePillow(3, 2));
    check.checkInt(1, o.passThePillow(4, 6));
    check.checkInt(2, o.passThePillow(2, 3));
    check.checkInt(1, o.passThePillow(2, 4));
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
