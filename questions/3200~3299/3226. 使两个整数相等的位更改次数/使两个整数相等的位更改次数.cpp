/* 使两个整数相等的位更改次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数 n 和 k。

你可以选择 n 的 二进制表示 中任意一个值为 1 的位，并将其改为 0。

返回使得 n 等于 k 所需要的更改次数。如果无法实现，返回 -1。



示例 1：

输入： n = 13, k = 4

输出： 2

解释：
最初，n 和 k 的二进制表示分别为 n = (1101)2 和 k = (0100)2，

我们可以改变 n 的第一位和第四位。结果整数为 n = (0100)2 = k。

示例 2：

输入： n = 21, k = 21

输出： 0

解释：
n 和 k 已经相等，因此不需要更改。

示例 3：

输入： n = 14, k = 13

输出： -1

解释：
无法使 n 等于 k。



提示：

1 <= n, k <= 106
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        int cnt = 0;

        for (int bit = 1; bit <= n || bit <= k; bit <<= 1) {
            if ((bit & n) == 0 && (bit & k) != 0) {
                return -1;
            }

            if ((bit & n) != 0 && (bit & k) == 0) {
                ++cnt;
            }
        }

        return cnt;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(2, o.minChanges(13, 4));
    check.checkInt(0, o.minChanges(21, 21));
    check.checkInt(-1, o.minChanges(14, 13));
    check.checkInt(-1, o.minChanges(11, 56));
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
