/* 两整数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:

输入: a = 1, b = 2
输出: 3
示例 2:

输入: a = -2, b = 3
输出: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

class Solution {
public:
    int getSum(int a, int b) {
        // a^b得到低位，a&b得到进位，重复计算直到没有进位
        int lower = (a ^ b);
        int carrier = (a & b);
        if (carrier == 0) {
            return lower;
        }
        return getSum(lower, (((unsigned int)carrier) << 1));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(3, o.getSum(1, 2));
    check.checkInt(1, o.getSum(-2, 3));
    check.checkInt(-1, o.getSum(-3, 2));
    check.checkInt(0, o.getSum(-3, 3));
    check.checkInt(-3, o.getSum(-3, 0));
    check.checkInt(2, o.getSum(0, 2));
    check.checkInt(123, o.getSum(100, 23));
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
