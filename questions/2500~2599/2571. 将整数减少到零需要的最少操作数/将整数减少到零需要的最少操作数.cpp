/* 将整数减少到零需要的最少操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n ，你可以执行下述操作 任意 次：

n 加上或减去 2 的某个 幂
返回使 n 等于 0 需要执行的 最少 操作数。

如果 x == 2i 且其中 i >= 0 ，则数字 x 是 2 的幂。



示例 1：

输入：n = 39
输出：3
解释：我们可以执行下述操作：
- n 加上 20 = 1 ，得到 n = 40 。
- n 减去 23 = 8 ，得到 n = 32 。
- n 减去 25 = 32 ，得到 n = 0 。
可以证明使 n 等于 0 需要执行的最少操作数是 3 。
示例 2：

输入：n = 54
输出：3
解释：我们可以执行下述操作：
- n 加上 21 = 2 ，得到 n = 56 。
- n 加上 23 = 8 ，得到 n = 64 。
- n 减去 26 = 64 ，得到 n = 0 。
使 n 等于 0 需要执行的最少操作数是 3 。


提示：

1 <= n <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(int n) {
        int opers = 0, bit = 1;

        while (n != 0) {
            while ((n & bit) == 0) {
                bit <<= 1;
            }

            if ((n & (bit << 1)) == 0) {
                n -= bit;
            }
            else {
                n += bit;
            }
            ++opers;
        }

        return opers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.minOperations(39));
    check.checkInt(3, o.minOperations(54));
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
