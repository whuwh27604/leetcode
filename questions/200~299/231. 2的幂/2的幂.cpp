/* 2的幂.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1
示例 2:

输入: 16
输出: true
解释: 24 = 16
示例 3:

输入: 218
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-two
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.isPowerOfTwo(1));
    check.checkBool(true, o.isPowerOfTwo(2));
    check.checkBool(true, o.isPowerOfTwo(4));
    check.checkBool(true, o.isPowerOfTwo(8));
    check.checkBool(true, o.isPowerOfTwo(16));
    check.checkBool(true, o.isPowerOfTwo(32));
    check.checkBool(false, o.isPowerOfTwo(3));
    check.checkBool(false, o.isPowerOfTwo(5));
    check.checkBool(false, o.isPowerOfTwo(6));
    check.checkBool(false, o.isPowerOfTwo(7));
    check.checkBool(false, o.isPowerOfTwo(9));
    check.checkBool(false, o.isPowerOfTwo(10));
    check.checkBool(false, o.isPowerOfTwo(14));
    check.checkBool(false, o.isPowerOfTwo(15));
    check.checkBool(false, o.isPowerOfTwo(0));
    check.checkBool(false, o.isPowerOfTwo(-1));
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
