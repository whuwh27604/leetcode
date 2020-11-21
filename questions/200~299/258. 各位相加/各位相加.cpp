/* 各位相加.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。

示例:

输入: 38
输出: 2
解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
进阶:
你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        /* num = A1*10^n1+A2*10^n2+...An-2*10^2+An-1*10+An = A1*(10^n1-1)+A2*(10^n2-1)+...+An-2*99+An-1*9+A1+A2+...An-2+An-1+An
           num%9 = (A1+A2+...An-2+An-1+An)%9 
           (A1+A2+...An-2+An-1+An) = (num - 1)%9+1 */
        return (num - 1) % 9 + 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(2, o.addDigits(38));
    check.checkInt(5, o.addDigits(59));
    check.checkInt(6, o.addDigits(123));
    check.checkInt(7, o.addDigits(889));
    check.checkInt(9, o.addDigits(9999));
    check.checkInt(0, o.addDigits(0));
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
