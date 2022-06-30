/* 质数排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你帮忙给从 1 到 n 的数设计排列方案，使得所有的「质数」都应该被放在「质数索引」（索引从 1 开始）上；你需要返回可能的方案总数。

让我们一起来回顾一下「质数」：质数一定是大于 1 的，并且不能用两个小于它的正整数的乘积来表示。

由于答案可能会很大，所以请你返回答案 模 mod 10^9 + 7 之后的结果即可。

 

示例 1：

输入：n = 5
输出：12
解释：举个例子，[1,2,5,4,3] 是一个有效的排列，但 [5,2,3,4,1] 不是，因为在第二种情况里质数 5 被错误地放在索引为 1 的位置上。
示例 2：

输入：n = 100
输出：682289015
 

提示：

1 <= n <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/prime-arrangements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numPrimeArrangements(int n) {
        int primes = countPrimes(n);

        return (int)(permutation(primes) * permutation(n - primes) % 1000000007);
    }
    
    int countPrimes(int n) {  // 埃拉托色尼筛选法
        vector<int> primes(n + 1, 1);
        int count = 0;

        for (int i = 2; (i * i) <= n; ++i) {
            if (primes[i] != 0) {
                for (int j = (i * i); j <= n; j += i) {
                    primes[j] = 0;
                }
            }
        }

        for (int k = 2; k <= n; ++k) {
            count += primes[k];
        }

        return count;
    }

    long long permutation(int n) {
        long long ans = 1;

        for (int i = 2; i <= n; ++i) {
            ans = (ans * i % 1000000007);
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(12, o.numPrimeArrangements(5));
    check.checkInt(1, o.numPrimeArrangements(2));
    check.checkInt(1, o.numPrimeArrangements(1));
    check.checkInt(682289015, o.numPrimeArrangements(100));
    check.checkInt(289151874, o.numPrimeArrangements(17));
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
