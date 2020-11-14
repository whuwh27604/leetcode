/* x的平方根.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
     由于返回类型是整数，小数部分将被舍去。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if ((x == 0) || (x == 1)) {
            return x;
        }

        long long left = 1;
        long long right = x - 1;
        long long middle = (left + right) / 2;
        long long lastMiddle = 0;
        long long square;

        while (middle != lastMiddle) {
            lastMiddle = middle;
            square = middle * middle;
            if (square > x) {
                right = middle - 1;
            }
            else if (square == x) {
                return (int)middle;
            }
            else {
                left = middle;
            }
            middle = (left + right) / 2;
        }

        square = (middle + 1) * (middle + 1);
        return (int)((square <= x) ? (middle + 1) : middle);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.mySqrt(0)); 
    check.checkInt(1, o.mySqrt(1)); 
    check.checkInt(1, o.mySqrt(2));
    check.checkInt(1, o.mySqrt(3));
    check.checkInt(2, o.mySqrt(4));
    check.checkInt(2, o.mySqrt(8));
    check.checkInt(10, o.mySqrt(100));
    check.checkInt(31, o.mySqrt(1000));
    check.checkInt(100, o.mySqrt(10000));
    check.checkInt(316, o.mySqrt(100000));
    check.checkInt(1000, o.mySqrt(1000000));
    check.checkInt(3162, o.mySqrt(10000000));
    check.checkInt(10000, o.mySqrt(100000000));
    check.checkInt(31622, o.mySqrt(1000000000));
    check.checkInt(46340, o.mySqrt(2147483647));
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
