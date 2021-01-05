/* 二进制表示中质数个计算置位.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个整数 L 和 R ，找到闭区间 [L, R] 范围内，计算置位位数为质数的整数个数。

（注意，计算置位代表二进制表示中1的个数。例如 21 的二进制表示 10101 有 3 个计算置位。还有，1 不是质数。）

示例 1:

输入: L = 6, R = 10
输出: 4
解释:
6 -> 110 (2 个计算置位，2 是质数)
7 -> 111 (3 个计算置位，3 是质数)
9 -> 1001 (2 个计算置位，2 是质数)
10-> 1010 (2 个计算置位，2 是质数)
示例 2:

输入: L = 10, R = 15
输出: 5
解释:
10 -> 1010 (2 个计算置位, 2 是质数)
11 -> 1011 (3 个计算置位, 3 是质数)
12 -> 1100 (2 个计算置位, 2 是质数)
13 -> 1101 (3 个计算置位, 3 是质数)
14 -> 1110 (3 个计算置位, 3 是质数)
15 -> 1111 (4 个计算置位, 4 不是质数)
注意:

L, R 是 L <= R 且在 [1, 10^6] 中的整数。
R - L 的最大值为 10000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int sum = 0;

        for (int i = L; i <= R; i++) {
            int countOnes = hammingWeight(i);
            if (isPrime(countOnes)) {
                sum++;
            }
        }

        return sum;
    }

    int hammingWeight(int n) {
        int sum = 0;
        while (n != 0) {
            sum++;
            n &= (n - 1);
        }
        return sum;
    }

    bool isPrime(int n) {
        // 10^6二进制最多20位数
        bool prime[21] = { false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, true, false };
        return prime[n];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(4, o.countPrimeSetBits(6, 10));
    check.checkInt(5, o.countPrimeSetBits(10, 15));
    check.checkInt(1, o.countPrimeSetBits(6, 6));
    check.checkInt(0, o.countPrimeSetBits(1, 1));
    check.checkInt(0, o.countPrimeSetBits(1, 2));
    check.checkInt(1, o.countPrimeSetBits(1, 3));
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
