/* 丑数 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编写一个程序，找出第 n 个丑数。

丑数就是质因数只包含 2, 3, 5 的正整数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Solution() {
        /* 考虑三个序列：2*1,2*2,2*3,2*4,2*5,2*6,2*8,2*9,2*10,2*12...
                         3*1,3*2,3*3,3*4,3*5,3*6,3*8,3*9,3*10,3*12...
                         5*1,5*2,5*3,5*4,5*5,5*6,5*8,5*9,5*10,5*12...
           丑数序列由上面三个序列归并排序得到。 */
        int i, index2 = 0, index3 = 0, index5 = 0;

        uglyNumber[0] = 1;
        for (i = 1; i < 1690; i++) {
            int next2 = uglyNumber[index2] * 2;
            int next3 = uglyNumber[index3] * 3;
            int next5 = uglyNumber[index5] * 5;
            int minimum = (next2 < next3) ? next2 : next3;
            minimum = (minimum < next5) ? minimum : next5;
            uglyNumber[i] = minimum;

            if (minimum == next2) {
                index2++;
            }
            if (minimum == next3) {
                index3++;
            }
            if (minimum == next5) {
                index5++;
            }
        }
    }

    int nthUglyNumber(int n) {
        return uglyNumber[n - 1];
    }

    int uglyNumber[1690];
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.nthUglyNumber(1));
    check.checkInt(2, o.nthUglyNumber(2));
    check.checkInt(3, o.nthUglyNumber(3));
    check.checkInt(4, o.nthUglyNumber(4));
    check.checkInt(5, o.nthUglyNumber(5));
    check.checkInt(6, o.nthUglyNumber(6));
    check.checkInt(8, o.nthUglyNumber(7));
    check.checkInt(9, o.nthUglyNumber(8));
    check.checkInt(10, o.nthUglyNumber(9));
    check.checkInt(12, o.nthUglyNumber(10));
    check.checkInt(15, o.nthUglyNumber(11));
    check.checkInt(16, o.nthUglyNumber(12));
    check.checkInt(18, o.nthUglyNumber(13));
    check.checkInt(20, o.nthUglyNumber(14));
    check.checkInt(24, o.nthUglyNumber(15));
    check.checkInt(25, o.nthUglyNumber(16));
    check.checkInt(27, o.nthUglyNumber(17));
    check.checkInt(30, o.nthUglyNumber(18));
    check.checkInt(32, o.nthUglyNumber(19));
    check.checkInt(36, o.nthUglyNumber(20));
    check.checkInt(2123366400, o.nthUglyNumber(1690));
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
