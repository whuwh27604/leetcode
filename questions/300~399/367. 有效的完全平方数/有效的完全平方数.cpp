/* 有效的完全平方数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：

输入：16
输出：True
示例 2：

输入：14
输出：False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-perfect-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }

        int maxIntSqrt = 46340;
        int middle = (num / 2);
        if (middle > maxIntSqrt) {
            middle = maxIntSqrt;
        }

        return isSquare(num, 1, middle);
    }

    bool isSquare(int num, int left, int right) {
        if ((num < (left * left)) || (num > (right * right))) {
            return false;
        }

        if ((num == (left * left)) || (num == (right * right))) {
            return true;
        }

        int middle = ((left + right) / 2);
        if (num == (middle * middle)) {
            return true;
        }
        else if (num < (middle * middle)) {
            return isSquare(num, (left + 1), (middle - 1));
        }
        else {
            return isSquare(num, (middle + 1), (right - 1));
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.isPerfectSquare(1));
    check.checkBool(false, o.isPerfectSquare(2));
    check.checkBool(false, o.isPerfectSquare(3));
    check.checkBool(true, o.isPerfectSquare(4));
    check.checkBool(false, o.isPerfectSquare(5));
    check.checkBool(true, o.isPerfectSquare(16));
    check.checkBool(false, o.isPerfectSquare(14));
    check.checkBool(true, o.isPerfectSquare(2147395600));
    check.checkBool(false, o.isPerfectSquare(2147395601));
    check.checkBool(false, o.isPerfectSquare(INT_MAX));
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
