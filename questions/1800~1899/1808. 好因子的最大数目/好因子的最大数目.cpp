/* 好因子的最大数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 primeFactors 。你需要构造一个正整数 n ，它满足以下条件：

n 质因数（质因数需要考虑重复的情况）的数目 不超过 primeFactors 个。
n 好因子的数目最大化。如果 n 的一个因子可以被 n 的每一个质因数整除，我们称这个因子是 好因子 。比方说，如果 n = 12 ，那么它的质因数为 [2,2,3] ，那么 6 和 12 是好因子，但 3 和 4 不是。
请你返回 n 的好因子的数目。由于答案可能会很大，请返回答案对 109 + 7 取余 的结果。

请注意，一个质数的定义是大于 1 ，且不能被分解为两个小于该数的自然数相乘。一个数 n 的质因子是将 n 分解为若干个质因子，且它们的乘积为 n 。

 

示例 1：

输入：primeFactors = 5
输出：6
解释：200 是一个可行的 n 。
它有 5 个质因子：[2,2,2,5,5] ，且有 6 个好因子：[10,20,40,50,100,200] 。
不存在别的 n 有至多 5 个质因子，且同时有更多的好因子。
示例 2：

输入：primeFactors = 8
输出：18
 

提示：

1 <= primeFactors <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximize-number-of-nice-divisors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        /* 题目的意思是把primeFactors分解为几个数的和，而这些数的乘积要最大，即primeFactors=A+B+...X，求max(A*B*...*X)
           通过数学方法可以证明，需要分解为最多个3，然后有余数的话再分解为2 */
        if (primeFactors <= 3) {
            return primeFactors;
        }

        long long ans;
        if (primeFactors % 3 == 0) {
            ans = fastPower(3, primeFactors / 3);
        }
        else if (primeFactors % 3 == 1) {
            ans = fastPower(3, primeFactors / 3 - 1) * 4;
        }
        else {
            ans = fastPower(3, primeFactors / 3) * 2;
        }

        return (int)(ans % 1000000007);
    }

    long long fastPower(long long x, int n) {
        long long ans = 1, index = 1;
        int mod = 1000000007;

        while (n != 0) {
            if ((n & index) != 0) {
                ans = (ans * x) % mod;
            }
            n &= ~index;
            index <<= 1;
            x = (x * x) % mod;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.maxNiceDivisors(1));
    check.checkInt(3, o.maxNiceDivisors(3));
    check.checkInt(4, o.maxNiceDivisors(4));
    check.checkInt(6, o.maxNiceDivisors(5));
    check.checkInt(18, o.maxNiceDivisors(8));
    check.checkInt(703522804, o.maxNiceDivisors(100));
    check.checkInt(897135186, o.maxNiceDivisors(1000000000));
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
