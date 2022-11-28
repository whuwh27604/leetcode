/* 找出中枢整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n ，找出满足下述条件的 中枢整数 x ：

1 和 x 之间的所有元素之和等于 x 和 n 之间所有元素之和。
返回中枢整数 x 。如果不存在中枢整数，则返回 -1 。题目保证对于给定的输入，至多存在一个中枢整数。



示例 1：

输入：n = 8
输出：6
解释：6 是中枢整数，因为 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21 。
示例 2：

输入：n = 1
输出：1
解释：1 是中枢整数，因为 1 = 1 。
示例 3：

输入：n = 4
输出：-1
解释：可以证明不存在满足题目要求的整数。


提示：

1 <= n <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int x = (int)sqrt((n * n + n) / 2);

        return (1 + x) * x == (x + n) * (n - x + 1) ? x : -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(6, o.pivotInteger(8));
    check.checkInt(1, o.pivotInteger(1));
    check.checkInt(-1, o.pivotInteger(4));
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
