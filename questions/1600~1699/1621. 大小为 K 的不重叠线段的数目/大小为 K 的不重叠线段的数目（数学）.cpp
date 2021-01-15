﻿/* 大小为 K 的不重叠线段的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一维空间的 n 个点，其中第 i 个点（编号从 0 到 n-1）位于 x = i 处，请你找到 恰好 k 个不重叠 线段且每个线段至少覆盖两个点的方案数。线段的两个端点必须都是 整数坐标 。这 k 个线段不需要全部覆盖全部 n 个点，且它们的端点 可以 重合。

请你返回 k 个不重叠线段的方案数。由于答案可能很大，请将结果对 109 + 7 取余 后返回。

 

示例 1：


输入：n = 4, k = 2
输出：5
解释：
如图所示，两个线段分别用红色和蓝色标出。
上图展示了 5 种不同的方案 {(0,2),(2,3)}，{(0,1),(1,3)}，{(0,1),(2,3)}，{(1,2),(2,3)}，{(0,1),(1,2)} 。
示例 2：

输入：n = 3, k = 1
输出：3
解释：总共有 3 种不同的方案 {(0,1)}, {(0,2)}, {(1,2)} 。
示例 3：

输入：n = 30, k = 7
输出：796297179
解释：画 7 条线段的总方案数为 3796297200 种。将这个数对 109 + 7 取余得到 796297179 。
示例 4：

输入：n = 5, k = 3
输出：7
示例 5：

输入：n = 3, k = 2
输出：1
 

提示：

2 <= n <= 1000
1 <= k <= n-1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-sets-of-k-non-overlapping-line-segments
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        /* 可以想象为选择了k个线段后，在每个线段中间加一个点作为这个线段的末端点（最后一个线段不用）。这样就不存在共用端点的情况了。
           所以问题的本质就是在n+k-1个点里面选择2k个点，答案是C(n+k-1, 2k)=(n+k-1)!/((2k)!*(n-k-1)!) */
        /* a/b(mod(c))=a*b'(mod(c)), b' is b's multiplicative inverse. If c is a prime, b'=pow(b,c-2)(mod(c)) */
        int mod = 1000000007;

        return (int)(factorial(n + k - 1, mod) * fastPower((factorial(2 * k, mod) * factorial(n - k - 1, mod)) % mod, mod - 2, mod) % mod);
    }

    long long factorial(int n, int mod) {
        long long x = 1;

        for (int i = 2; i <= n; ++i) {
            x = (x * i) % mod;
        }

        return x;
    }

    long long fastPower(long long x, int n, int mod) {
        long long ans = 1;
        int index = 1;

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

    check.checkInt(1, o.numberOfSets(2, 1));
    check.checkInt(3, o.numberOfSets(3, 1));
    check.checkInt(1, o.numberOfSets(3, 2));
    check.checkInt(6, o.numberOfSets(4, 1));
    check.checkInt(5, o.numberOfSets(4, 2));
    check.checkInt(1, o.numberOfSets(4, 3));
    check.checkInt(10, o.numberOfSets(5, 1));
    check.checkInt(15, o.numberOfSets(5, 2));
    check.checkInt(7, o.numberOfSets(5, 3));
    check.checkInt(1, o.numberOfSets(5, 4));
    check.checkInt(796297179, o.numberOfSets(30, 7));
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
