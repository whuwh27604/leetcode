/* 坏了的计算器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
显示着数字的坏计算器上，我们可以执行以下两种操作：

双倍（Double）：将显示屏上的数字乘 2；
递减（Decrement）：将显示屏上的数字减 1 。
最初，计算器显示数字 X。

返回显示数字 Y 所需的最小操作数。

 

示例 1：

输入：X = 2, Y = 3
输出：2
解释：先进行双倍运算，然后再进行递减运算 {2 -> 4 -> 3}.
示例 2：

输入：X = 5, Y = 8
输出：2
解释：先递减，再双倍 {5 -> 4 -> 8}.
示例 3：

输入：X = 3, Y = 10
输出：3
解释：先双倍，然后递减，再双倍 {3 -> 6 -> 5 -> 10}.
示例 4：

输入：X = 1024, Y = 1
输出：1023
解释：执行递减运算 1023 次
 

提示：

1 <= X <= 10^9
1 <= Y <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/broken-calculator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        // 奇数加1偶数除2能够最快的到达目标
        int operations = 0;

        while (Y > X) {
            if ((Y & 1) == 1) {
                Y += 1;
                ++operations;
            }

            Y >>= 1;
            ++operations;
        }

        return operations + (X - Y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.brokenCalc(2, 3));
    check.checkInt(2, o.brokenCalc(5, 8));
    check.checkInt(3, o.brokenCalc(3, 10));
    check.checkInt(1023, o.brokenCalc(1024, 1));
    check.checkInt(40, o.brokenCalc(3, 999999999));
    check.checkInt(39, o.brokenCalc(1, 1000000000));
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
