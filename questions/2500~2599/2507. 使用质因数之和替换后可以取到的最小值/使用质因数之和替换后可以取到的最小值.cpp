/* 使用质因数之和替换后可以取到的最小值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n 。

请你将 n 的值替换为 n 的 质因数 之和，重复这一过程。

注意，如果 n 能够被某个质因数多次整除，则在求和时，应当包含这个质因数同样次数。
返回 n 可以取到的最小值。



示例 1：

输入：n = 15
输出：5
解释：最开始，n = 15 。
15 = 3 * 5 ，所以 n 替换为 3 + 5 = 8 。
8 = 2 * 2 * 2 ，所以 n 替换为 2 + 2 + 2 = 6 。
6 = 2 * 3 ，所以 n 替换为 2 + 3 = 5 。
5 是 n 可以取到的最小值。
示例 2：

输入：n = 3
输出：3
解释：最开始，n = 3 。
3 是 n 可以取到的最小值。


提示：

2 <= n <= 105
*/

#include <iostream>
#include <set>
#include <numeric>
#include "../check/CheckResult.h"

using namespace std;

set<int> primes;

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        int n = 100001;
        vector<int> nums(n, 1);

        for (int i = 2; i * i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }

            for (int j = (i * i); j < n; j += i) {  // i的小于i的倍数都已经排除过了，现在只需要排除更大的i的倍数
                nums[j] = 0;
            }
        }

        for (int k = 2; k < n; ++k) {
            if (nums[k] == 1) {
                primes.insert(k);
            }
        }
    }
}

class Solution {
public:
    int smallestValue(int n) {
        init();

        if (n == 4 || primes.count(n) != 0) {
            return n;
        }

        vector<int> factors;
        factorize(n, factors);

        return smallestValue(accumulate(factors.begin(), factors.end(), 0));
    }

    void factorize(int n, vector<int>& factors) {
        if (n == 1) {
            return;
        }

        for (int prime : primes) {
            if (prime > n) {
                break;
            }

            if (n % prime == 0) {
                factors.push_back(prime);
                return factorize(n / prime, factors);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.smallestValue(15));
    check.checkInt(3, o.smallestValue(3));
    check.checkInt(4, o.smallestValue(4));
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
