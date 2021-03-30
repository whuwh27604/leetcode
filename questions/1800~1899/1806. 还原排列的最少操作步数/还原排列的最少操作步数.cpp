// 还原排列的最少操作步数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int reinitializePermutation(int n) {
        /* 记位置i在k轮之后的位置为pos(i, k)，m = n - 1，则：
           1、当 i < n/2 时，pos(i, 1) = 2i（第一条规则）
           2、当 i ≥ n/2 时，pos(i, 1) = 2i − (n − 1)（第二条规则）
           可以发现位置[0]和[n - 1]永远不变，而对其它位置(0, n - 1)，pos(i, 1) = 2i (mod = m)
           进一步，pos(i, k) = pow(2, k) * i (mod = m)
           讨论位置1，即i = 1，pos(1, k) = pow(2, k) (mod = m)，目标是要k轮之后，使pow(2, k) = 1 (mod = m)
           进一步，如果k使得pos(1, k) = pow(2, k) = 1 (mod = m)，那么必然有pos(i, k) = pow(2, k) * i = i (mod = m)
           就是说当位置[1]通过轮转回到位置[1]的时候，其它位置也会同时回到它自己的位置 */
        if (n == 2) {  // 特殊情况，只有首尾两个位置，它们不会变化，所以1步之后还是原数组
            return 1;
        }

        int steps = 1, power2 = 2, mod = n - 1;  // 先走一步，避免等于原数组直接返回了
        while (power2 != 1) {
            ++steps;
            power2 = (power2 * 2) % mod;
        }

        return steps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.reinitializePermutation(2));
    check.checkInt(2, o.reinitializePermutation(4));
    check.checkInt(4, o.reinitializePermutation(6));
    check.checkInt(3, o.reinitializePermutation(8));
    check.checkInt(6, o.reinitializePermutation(10));
    check.checkInt(10, o.reinitializePermutation(12));
    check.checkInt(12, o.reinitializePermutation(14));
    check.checkInt(4, o.reinitializePermutation(16));
    check.checkInt(8, o.reinitializePermutation(18));
    check.checkInt(18, o.reinitializePermutation(20));
    check.checkInt(36, o.reinitializePermutation(1000));
    check.checkInt(82, o.reinitializePermutation(84));
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
