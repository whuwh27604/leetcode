/* 4的幂.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。

示例 1:

输入: 16
输出: true
示例 2:

输入: 5
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-four
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return ((num > 0) && ((num & (num - 1)) == 0) && ((num & 0xaaaaaaaa) == 0));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.isPowerOfFour(1));
    check.checkBool(true, o.isPowerOfFour(4));
    check.checkBool(true, o.isPowerOfFour(16));
    check.checkBool(true, o.isPowerOfFour(64));
    check.checkBool(true, o.isPowerOfFour(1073741824));
    check.checkBool(false, o.isPowerOfFour(0));
    check.checkBool(false, o.isPowerOfFour(-4));
    check.checkBool(false, o.isPowerOfFour(3));
    check.checkBool(false, o.isPowerOfFour(1073741825));
    check.checkBool(false, o.isPowerOfFour(INT_MAX));
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
