/* 找出最大的可达成数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 num 和 t 。

如果整数 x 可以在执行下述操作不超过 t 次的情况下变为与 num 相等，则称其为 可达成数字 ：

每次操作将 x 的值增加或减少 1 ，同时可以选择将 num 的值增加或减少 1 。
返回所有可达成数字中的最大值。可以证明至少存在一个可达成数字。



示例 1：

输入：num = 4, t = 1
输出：6
解释：最大可达成数字是 x = 6 ，执行下述操作可以使其等于 num ：
- x 减少 1 ，同时 num 增加 1 。此时，x = 5 且 num = 5 。
可以证明不存在大于 6 的可达成数字。
示例 2：

输入：num = 3, t = 2
输出：7
解释：最大的可达成数字是 x = 7 ，执行下述操作可以使其等于 num ：
- x 减少 1 ，同时 num 增加 1 。此时，x = 6 且 num = 4 。
- x 减少 1 ，同时 num 增加 1 。此时，x = 5 且 num = 5 。
可以证明不存在大于 7 的可达成数字。


提示：

1 <= num, t <= 50
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2 * t;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(6, o.theMaximumAchievableX(4, 1));
    check.checkInt(7, o.theMaximumAchievableX(3, 2));
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
