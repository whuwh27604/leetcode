/* 统计理想数组的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 n 和 maxValue ，用于描述一个 理想数组 。

对于下标从 0 开始、长度为 n 的整数数组 arr ，如果满足以下条件，则认为该数组是一个 理想数组 ：

每个 arr[i] 都是从 1 到 maxValue 范围内的一个值，其中 0 <= i < n 。
每个 arr[i] 都可以被 arr[i - 1] 整除，其中 0 < i < n 。
返回长度为 n 的 不同 理想数组的数目。由于答案可能很大，返回对 109 + 7 取余的结果。

 

示例 1：

输入：n = 2, maxValue = 5
输出：10
解释：存在以下理想数组：
- 以 1 开头的数组（5 个）：[1,1]、[1,2]、[1,3]、[1,4]、[1,5]
- 以 2 开头的数组（2 个）：[2,2]、[2,4]
- 以 3 开头的数组（1 个）：[3,3]
- 以 4 开头的数组（1 个）：[4,4]
- 以 5 开头的数组（1 个）：[5,5]
共计 5 + 2 + 1 + 1 + 1 = 10 个不同理想数组。
示例 2：

输入：n = 5, maxValue = 3
输出：11
解释：存在以下理想数组：
- 以 1 开头的数组（9 个）：
   - 不含其他不同值（1 个）：[1,1,1,1,1]
   - 含一个不同值 2（4 个）：[1,1,1,1,2], [1,1,1,2,2], [1,1,2,2,2], [1,2,2,2,2]
   - 含一个不同值 3（4 个）：[1,1,1,1,3], [1,1,1,3,3], [1,1,3,3,3], [1,3,3,3,3]
- 以 2 开头的数组（1 个）：[2,2,2,2,2]
- 以 3 开头的数组（1 个）：[3,3,3,3,3]
共计 9 + 1 + 1 = 11 个不同理想数组。
 

提示：

2 <= n <= 104
1 <= maxValue <= 104

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-the-number-of-ideal-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Combination {
public:
    Combination(int n) {
        maxN = n;
        mod = 1000000007;
        factorial.resize(n + 1);
        inverse.resize(n + 1);
        calc();
    }

    void calc() {
        long long num = 1;
        factorial[0] = inverse[0] = 1;

        for (int i = 1; i <= maxN; ++i) {
            num = (num * i) % mod;
            factorial[i] = (int)num;
            inverse[i] = fastPower(factorial[i], mod - 2);
        }
    }

    int fastPower(int x, int n) {
        long long ans = 1;
        int bit = 1;

        while (n != 0) {
            if ((n & bit) != 0) {
                ans = (ans * x) % mod;
            }

            n &= ~bit;
            bit <<= 1;
            x = ((long long)x * x) % mod;
        }

        return (int)ans;
    }

    int comb(int n, int m) {  // comb(n, m) = n! / m!(n - m)! = n! * inverse(m!) * inverse((n - m)!)
        return (int)((long long)factorial[n] * inverse[m] % mod * inverse[n - m] % mod);
    }

private:
    int maxN;
    int mod;
    vector<int> factorial;
    vector<int> inverse;
};

Combination combination(13 + 10000 - 1);  // 根据数据范围，Ai最大为13

class PrimeFactor {
public:
    vector<vector<pair<int, int>>> factorCounts;

    PrimeFactor(int n) {
        factorCounts.resize(n + 1);

        for (int i = 2; i <= n; ++i) {
            if (factorCounts[i].empty()) {  // i是一个质数
                for (int j = i; j <= n; j += i) {  // i的所有倍数
                    int num = j, count = 0;

                    while (num % i == 0) {  // 计算这个倍数包含的质因子i的个数
                        ++count;
                        num /= i;
                    }

                    factorCounts[j].push_back({ i, count });
                }
            }
        }
    }
};

PrimeFactor primeFactor(10000);

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        /*
        * ways(n, k, empty = false) = comb(n - 1, k - 1)  将n个球放入k个篮子，不能为空
        * ways(n, k, empty = true) = comb(n + k - 1, k - 1)  将n个球放入k个篮子，可以为空
        * 假设maxValue = P0^A0 * P1^A1 * ... * Pn^An，题目等价于求ways(A0, n, empty = true) * ways(A1, n, empty = true) * ... * ways(An, n, empty = true)
        */
        int mod = 1000000007;
        long long total = 1;  // [1,1...1]

        for (int num = 2; num <= maxValue; ++num) {  // 以num为结尾的array
            long long arrays = 1;

            for (auto& factorCount : primeFactor.factorCounts[num]) {  // 将count个球放入n个篮子，可以为空
                arrays = arrays * combination.comb(factorCount.second + n - 1, n - 1) % mod;
            }

            total = (total + arrays) % mod;
        }

        return (int)total;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(10, o.idealArrays(2, 5));
    check.checkInt(11, o.idealArrays(5, 3));
    check.checkInt(10, o.idealArrays(2, 5));
    check.checkInt(22940607, o.idealArrays(10000, 10000));
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
