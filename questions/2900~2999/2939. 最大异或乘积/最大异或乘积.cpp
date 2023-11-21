/* 最大异或乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你三个整数 a ，b 和 n ，请你返回 (a XOR x) * (b XOR x) 的 最大值 且 x 需要满足 0 <= x < 2n。

由于答案可能会很大，返回它对 109 + 7 取余 后的结果。

注意，XOR 是按位异或操作。



示例 1：

输入：a = 12, b = 5, n = 4
输出：98
解释：当 x = 2 时，(a XOR x) = 14 且 (b XOR x) = 7 。所以，(a XOR x) * (b XOR x) = 98 。
98 是所有满足 0 <= x < 2n 中 (a XOR x) * (b XOR x) 的最大值。
示例 2：

输入：a = 6, b = 7 , n = 5
输出：930
解释：当 x = 25 时，(a XOR x) = 31 且 (b XOR x) = 30 。所以，(a XOR x) * (b XOR x) = 930 。
930 是所有满足 0 <= x < 2n 中 (a XOR x) * (b XOR x) 的最大值。
示例 3：

输入：a = 1, b = 6, n = 3
输出：12
解释： 当 x = 5 时，(a XOR x) = 4 且 (b XOR x) = 3 。所以，(a XOR x) * (b XOR x) = 12 。
12 是所有满足 0 <= x < 2n 中 (a XOR x) * (b XOR x) 的最大值。


提示：

0 <= a, b < 250
0 <= n <= 50
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long p = (a >> n) << n, q = (b >> n) << n;  // p = a ^ x, q = b ^ x，先把超出 2 ^ n的部分保留下来，这部分不受异或操作影响

        for (int i = (n - 1); i >= 0; --i) {
            long long bit = ((long long)1 << i);
            if (((a & bit) ^ (b & bit)) == 0) {  // a、b的这一位相同，那么x的这一位选择相反的数，可以使异或的结果p、q这一位都是1
                p |= bit;
                q |= bit;
            }
            else {  // a、b的这一位不同，那么异或的结果只有一个1，p、q谁小就把这个1给谁
                if (p < q) {
                    p |= bit;
                }
                else {
                    q |= bit;
                }
            }
        }

        int mod = 1000000007;
        p %= mod;
        q %= mod;

        return (int)(p * q % mod);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(98, o.maximumXorProduct(12, 5, 4));
    check.checkInt(930, o.maximumXorProduct(6, 7, 5));
    check.checkInt(12, o.maximumXorProduct(1, 6, 3));
    check.checkInt(0, o.maximumXorProduct(0, 4, 0));
    check.checkInt(683615772, o.maximumXorProduct(1125899906842624, 123, 50));
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
