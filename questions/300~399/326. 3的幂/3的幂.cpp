/* 3的幂.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:

输入: 27
输出: true
示例 2:

输入: 0
输出: false
示例 3:

输入: 9
输出: true
示例 4:

输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-three
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        int max3PowerInInt = 1162261467;
        return ((n > 0) && ((max3PowerInInt % n) == 0));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.isPowerOfThree(1));
    check.checkBool(true, o.isPowerOfThree(3));
    check.checkBool(true, o.isPowerOfThree(9));
    check.checkBool(true, o.isPowerOfThree(27));
    check.checkBool(true, o.isPowerOfThree(1162261467));
    check.checkBool(false, o.isPowerOfThree(0));
    check.checkBool(false, o.isPowerOfThree(2));
    check.checkBool(false, o.isPowerOfThree(-3));
    check.checkBool(false, o.isPowerOfThree(INT_MAX));
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
