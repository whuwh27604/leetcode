/* 丑数 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你帮忙设计一个程序，用来找出第 n 个丑数。

丑数是可以被 a 或 b 或 c 整除的 正整数。

 

示例 1：

输入：n = 3, a = 2, b = 3, c = 5
输出：4
解释：丑数序列为 2, 3, 4, 5, 6, 8, 9, 10... 其中第 3 个是 4。
示例 2：

输入：n = 4, a = 2, b = 3, c = 4
输出：6
解释：丑数序列为 2, 3, 4, 6, 8, 9, 10, 12... 其中第 4 个是 6。
示例 3：

输入：n = 5, a = 2, b = 11, c = 13
输出：10
解释：丑数序列为 2, 4, 6, 8, 10, 11, 12, 13... 其中第 5 个是 10。
示例 4：

输入：n = 1000000000, a = 2, b = 217983653, c = 336916467
输出：1999999984
 

提示：

1 <= n, a, b, c <= 10^9
1 <= a * b * c <= 10^18
本题结果在 [1, 2 * 10^9] 的范围内

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b), ac = lcm(a, c), bc = lcm(b, c), abc = lcm(ab, c);
        long long left = min({ a, b, c }), right = 2000000000;

        while (left < right) {
            long long middle = (right + left) / 2;
            long long count = middle / a + middle / b + middle / c - middle / ab - middle / ac - middle / bc + middle / abc;
            if (count >= (long long)n) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }

        return (int)left;
    }

    long long gcd(long long x, long long y) {
        return (y == 0) ? x : gcd(y, x % y);
    }

    long long lcm(long long x, long long y) {
        return x * y / gcd(x, y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.nthUglyNumber(3, 2, 3, 5));
    check.checkInt(6, o.nthUglyNumber(4, 2, 3, 4));
    check.checkInt(10, o.nthUglyNumber(5, 2, 11, 13));
    check.checkInt(1999999984, o.nthUglyNumber(1000000000, 2, 217983653, 336916467));
    check.checkInt(6, o.nthUglyNumber(6, 1, 2, 3));
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
