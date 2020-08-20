/* 第N个数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。

注意:
n 是正数且在32位整数范围内 ( n < 231)。

示例 1:

输入:
3

输出:
3
示例 2:

输入:
11

输出:
0

说明:
第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/nth-digit
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int digitCount[10] = { 0,9,180,2700,36000,450000,5400000,63000000,720000000,INT_MAX };
        int i = 1, left = n;

        while (left > digitCount[i]) {
            left -= digitCount[i++];
        }

        int number = left / i;
        int digit = left % i;
        if (digit == 0) {
            digit = i;
        }
        else {
            number++;
        }

        number = (int)pow(10, i - 1) + number - 1;
        return to_string(number)[digit - 1] - '0';
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.findNthDigit(1));
    check.checkInt(9, o.findNthDigit(9));
    check.checkInt(1, o.findNthDigit(10));
    check.checkInt(0, o.findNthDigit(11));
    check.checkInt(9, o.findNthDigit(189));
    check.checkInt(1, o.findNthDigit(190));
    check.checkInt(3, o.findNthDigit(1000));
    check.checkInt(7, o.findNthDigit(10000));
    check.checkInt(2, o.findNthDigit(100000));
    check.checkInt(1, o.findNthDigit(1000000));
    check.checkInt(7, o.findNthDigit(10000000));
    check.checkInt(8, o.findNthDigit(100000000));
    check.checkInt(1, o.findNthDigit(1000000000));
    check.checkInt(2, o.findNthDigit(INT_MAX));
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
