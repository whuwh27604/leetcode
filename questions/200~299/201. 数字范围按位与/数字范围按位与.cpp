/* 数字范围按位与.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

示例 1: 

输入: [5,7]
输出: 4
示例 2:

输入: [0,1]
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bitwise-and-of-numbers-range
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // 求m、n二进制中1的最大前缀
        while (m < n) {
            n &= (n - 1);  // 二进制中最后的1清零
        }

        return m & n;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(4, o.rangeBitwiseAnd(5, 7));
    check.checkInt(0, o.rangeBitwiseAnd(0, 1));
    check.checkInt(7, o.rangeBitwiseAnd(7, 7));
    check.checkInt(INT_MAX - 1, o.rangeBitwiseAnd(INT_MAX - 1, INT_MAX));
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
