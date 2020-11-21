/* 丑数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编写一个程序判断给定的数是否为丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

示例 1:

输入: 6
输出: true
解释: 6 = 2 × 3
示例 2:

输入: 8
输出: true
解释: 8 = 2 × 2 × 2
示例 3:

输入: 14
输出: false
解释: 14 不是丑数，因为它包含了另外一个质因数 7。
说明：

1 是丑数。
输入不会超过 32 位有符号整数的范围: [−231,  231 − 1]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) {
            return false;
        }

        if ((num == 1) || (num == 2) || (num == 3) || (num == 5)) {
            return true;
        }

        int quotient = (num / 2);
        if ((quotient * 2) == num) {
            return isUgly(quotient);
        }

        quotient = (num / 3);
        if ((quotient * 3) == num) {
            return isUgly(quotient);
        }

        quotient = (num / 5);
        if ((quotient * 5) == num) {
            return isUgly(quotient);
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.isUgly(6));
    check.checkBool(true, o.isUgly(8));
    check.checkBool(false, o.isUgly(14));
    check.checkBool(true, o.isUgly(1));
    check.checkBool(false, o.isUgly(0));
    check.checkBool(false, o.isUgly(-1118));
    check.checkBool(true, o.isUgly(2000000000));
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
