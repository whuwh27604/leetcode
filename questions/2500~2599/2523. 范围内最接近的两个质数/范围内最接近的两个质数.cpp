/* 范围内最接近的两个质数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数 left 和 right ，请你找到两个整数 num1 和 num2 ，它们满足：

left <= nums1 < nums2 <= right  。
nums1 和 nums2 都是 质数 。
nums2 - nums1 是满足上述条件的质数对中的 最小值 。
请你返回正整数数组 ans = [nums1, nums2] 。如果有多个整数对满足上述条件，请你返回 nums1 最小的质数对。如果不存在符合题意的质数对，请你返回 [-1, -1] 。

如果一个整数大于 1 ，且只能被 1 和它自己整除，那么它是一个质数。



示例 1：

输入：left = 10, right = 19
输出：[11,13]
解释：10 到 19 之间的质数为 11 ，13 ，17 和 19 。
质数对的最小差值是 2 ，[11,13] 和 [17,19] 都可以得到最小差值。
由于 11 比 17 小，我们返回第一个质数对。
示例 2：

输入：left = 4, right = 6
输出：[-1,-1]
解释：给定范围内只有一个质数，所以题目条件无法被满足。


提示：

1 <= left <= right <= 106
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

vector<int> primes;

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        int maxNum = 1000000;
        vector<bool> isPrime(maxNum + 1, true);

        for (int i = 2; i <= maxNum; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }

            for (int j = 0; j < (int)primes.size() && i * primes[j] <= maxNum; ++j) {
                isPrime[i * primes[j]] = false;

                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
    }
}

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        init();
        int minDist = INT_MAX, size = primes.size();
        vector<int> ans = { -1,-1 };

        for (int i = 1; i < size; ++i) {
            if (primes[i - 1] >= left && primes[i] <= right) {
                int dist = primes[i] - primes[i - 1];
                if (dist < minDist) {
                    minDist = dist;
                    ans = { primes[i - 1],primes[i] };
                }
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.closestPrimes(10, 19);
    vector<int> expected = { 11,13 };
    check.checkIntVector(expected, actual);

    actual = o.closestPrimes(4, 6);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);
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
