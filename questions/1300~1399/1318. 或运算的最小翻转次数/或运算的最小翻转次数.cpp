/* 或运算的最小翻转次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你三个正整数 a、b 和 c。

你可以对 a 和 b 的二进制表示进行位翻转操作，返回能够使按位或运算   a OR b == c  成立的最小翻转次数。

「位翻转操作」是指将一个数的二进制表示任何单个位上的 1 变成 0 或者 0 变成 1 。

 

示例 1：



输入：a = 2, b = 6, c = 5
输出：3
解释：翻转后 a = 1 , b = 4 , c = 5 使得 a OR b == c
示例 2：

输入：a = 4, b = 2, c = 7
输出：1
示例 3：

输入：a = 1, b = 2, c = 3
输出：0
 

提示：

1 <= a <= 10^9
1 <= b <= 10^9
1 <= c <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-flips-to-make-a-or-b-equal-to-c
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int i, mask = 1, count = 0, ab = (a | b);

        for (i = 0; i < 31; ++i, mask <<= 1) {
            if ((mask & c) == 0) {
                count += (((mask & a) != 0 ? 1 : 0) + ((mask & b) != 0 ? 1 : 0));
            }
            else {
                count += ((mask & ab) == 0 ? 1 : 0);
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.minFlips(2, 6, 5));
    check.checkInt(1, o.minFlips(4, 2, 7));
    check.checkInt(0, o.minFlips(1, 2, 3));
    check.checkInt(62, o.minFlips(INT_MAX, INT_MAX, 0));
    check.checkInt(3, o.minFlips(8, 3, 5));
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
