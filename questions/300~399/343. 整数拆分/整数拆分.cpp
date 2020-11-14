/* 整数拆分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }

        int count2 = 0, count3 = n / 3, remainder = n % 3;
        if (remainder == 2) {
            count2 = 1;
        }
        else if (remainder == 1) {
            count2 = 2;
            count3 -= 1;
        }

        return (int)(pow(3, count3) * pow(2, count2));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.integerBreak(2));
    check.checkInt(2, o.integerBreak(3));
    check.checkInt(4, o.integerBreak(4));
    check.checkInt(6, o.integerBreak(5));
    check.checkInt(9, o.integerBreak(6));
    check.checkInt(12, o.integerBreak(7));
    check.checkInt(18, o.integerBreak(8));
    check.checkInt(1549681956, o.integerBreak(58));
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
