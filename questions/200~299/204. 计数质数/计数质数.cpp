/* 计数质数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        // 埃拉托色尼筛选法
        unsigned char* primes = new unsigned char[n];
        memset(primes, 1, n);  // 全部置1
        for (int i = 2; (i * i) < n; i++) {  // 如果n=i*i，则n不是质数，所以只需要循环到(i * i) < n就可以了
            if (primes[i] == 0) {
                continue;
            }

            for (int j = (i * i); j < n; j += i) {  // i的小于i的倍数都已经排除过了，现在只需要排除更大的i的倍数
                primes[j] = 0;
            }
        }

        int count = 0;
        for (int k = 2; k < n; k++) {
            count += primes[k];
        }
        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.countPrimes(3));
    check.checkInt(2, o.countPrimes(4));
    check.checkInt(2, o.countPrimes(5));
    check.checkInt(3, o.countPrimes(6));
    check.checkInt(3, o.countPrimes(7));
    check.checkInt(4, o.countPrimes(8));
    check.checkInt(4, o.countPrimes(9));
    check.checkInt(4, o.countPrimes(10));
    check.checkInt(4, o.countPrimes(11));
    check.checkInt(5, o.countPrimes(12));
    check.checkInt(30, o.countPrimes(120));
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
