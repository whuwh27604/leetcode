/* 第 N 个神奇数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个正整数如果能被 a 或 b 整除，那么它是神奇的。

给定三个整数 n , a , b ，返回第 n 个神奇的数字。因为答案可能很大，所以返回答案 对 109 + 7 取模 后的值。



示例 1：

输入：n = 1, a = 2, b = 3
输出：2
示例 2：

输入：n = 4, a = 2, b = 3
输出：6


提示：

1 <= n <= 109
2 <= a, b <= 4 * 104
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long low = min(a, b), high = low * n, ans = 0, mod = 1000000007;
        long long lcm = (long long)a * b / gcd(a, b);

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long count = mid / a + mid / b - mid / lcm;
            if (count > n) {
                high = mid - 1;
            }
            else if (count < n) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
                ans = mid;
            }
        }

        return (int)(ans % mod);
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.nthMagicalNumber(1, 2, 3));
    check.checkInt(6, o.nthMagicalNumber(4, 2, 3));
    check.checkInt(997250612, o.nthMagicalNumber(1000000000, 11, 40000));
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
