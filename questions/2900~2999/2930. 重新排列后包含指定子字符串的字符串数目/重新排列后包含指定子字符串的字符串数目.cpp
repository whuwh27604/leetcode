/* 重新排列后包含指定子字符串的字符串数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 。

如果一个字符串 s 只包含小写英文字母，且 将 s 的字符重新排列后，新字符串包含 子字符串 "leet" ，那么我们称字符串 s 是一个 好 字符串。

比方说：

字符串 "lteer" 是好字符串，因为重新排列后可以得到 "leetr" 。
"letl" 不是好字符串，因为无法重新排列并得到子字符串 "leet" 。
请你返回长度为 n 的好字符串 总 数目。

由于答案可能很大，将答案对 109 + 7 取余 后返回。

子字符串 是一个字符串中一段连续的字符序列。


示例 1：

输入：n = 4
输出：12
解释：总共有 12 个字符串重新排列后包含子字符串 "leet" ："eelt" ，"eetl" ，"elet" ，"elte" ，"etel" ，"etle" ，"leet" ，"lete" ，"ltee" ，"teel" ，"tele" 和 "tlee" 。
示例 2：

输入：n = 10
输出：83943898
解释：长度为 10 的字符串重新排列后包含子字符串 "leet" 的方案数为 526083947580 。所以答案为 526083947580 % (109 + 7) = 83943898 。


提示：

1 <= n <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int stringCount(int n) {
        long long mod = 1000000007;
        long long count = fastPower(26, n, mod);  // 总的方案数
        count = (count + mod - fastPower(25, n, mod)) % mod;  // 不含 l 的方案数
        count = (count + mod - fastPower(25, n, mod)) % mod;  // 不含 t 的方案数
        count = (count + mod - fastPower(25, n, mod)) % mod;  // 不含 e 的方案数
        count = (count + mod - n * fastPower(25, n - 1, mod) % mod) % mod;  // 只含一个 e 的方案数
        count = (count + fastPower(24, n, mod)) % mod;  // 不含 l、t 的方案数
        count = (count + fastPower(24, n, mod)) % mod;  // 不含 l、e 的方案数
        count = (count + fastPower(24, n, mod)) % mod;  // 不含 t、e 的方案数
        count = (count + n * fastPower(24, n - 1, mod) % mod) % mod;  // 不含 l、只含一个 e 的方案数
        count = (count + n * fastPower(24, n - 1, mod) % mod) % mod;  // 不含 t、只含一个 e 的方案数
        count = (count + mod - fastPower(23, n, mod)) % mod;  // 不含 l、t、e 的方案数
        count = (count + mod - n * fastPower(23, n - 1, mod) % mod) % mod;  // 不含 l、t、只含一个 e 的方案数

        return (int)count;
    }

    long long fastPower(long long x, int n, long long mod) {
        long long ans = 1;

        while (n > 0) {
            if ((n & 1) == 1) {
                ans = ans * x % mod;
            }

            x = x * x % mod;
            n >>= 1;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(12, o.stringCount(4));
    check.checkInt(83943898, o.stringCount(10));
    check.checkInt(0, o.stringCount(1));
    check.checkInt(778066325, o.stringCount(100000));
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
