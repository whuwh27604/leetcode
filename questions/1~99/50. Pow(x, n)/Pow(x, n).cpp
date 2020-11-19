/* Pow(x, n).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powx-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long num = n, index = 1;
        num = abs(num);
        double ans = 1;

        while (num != 0) {
            if ((num & index) != 0) {
                ans *= x;
            }
            num &= ~index;
            index <<= 1;
            x = x * x;
        }

        return n >= 0 ? ans : 1 / ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkDouble(1, o.myPow(2, 0));
    check.checkDouble(2, o.myPow(2, 1));
    check.checkDouble(1024, o.myPow(2, 10));
    check.checkDouble(9.261, o.myPow(2.1, 3));
    check.checkDouble(0.25, o.myPow(2, -2));
    check.checkDouble(1, o.myPow(1, INT_MAX));
    check.checkDouble(0, o.myPow(0.00001, INT_MAX));
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
