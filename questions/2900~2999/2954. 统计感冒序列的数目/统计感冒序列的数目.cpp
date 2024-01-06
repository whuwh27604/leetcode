/* 统计感冒序列的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 和一个下标从 0 开始的整数数组 sick ，数组按 升序 排序。

有 n 位小朋友站成一排，按顺序编号为 0 到 n - 1 。数组 sick 包含一开始得了感冒的小朋友的位置。如果位置为 i 的小朋友得了感冒，他会传染给下标为 i - 1 或者 i + 1 的小朋友，前提 是被传染的小朋友存在且还没有得感冒。每一秒中， 至多一位 还没感冒的小朋友会被传染。

经过有限的秒数后，队列中所有小朋友都会感冒。感冒序列 指的是 所有 一开始没有感冒的小朋友最后得感冒的顺序序列。请你返回所有感冒序列的数目。

由于答案可能很大，请你将答案对 109 + 7 取余后返回。

注意，感冒序列 不 包含一开始就得了感冒的小朋友的下标。



示例 1：

输入：n = 5, sick = [0,4]
输出：4
解释：一开始，下标为 1 ，2 和 3 的小朋友没有感冒。总共有 4 个可能的感冒序列：
- 一开始，下标为 1 和 3 的小朋友可以被传染，因为他们分别挨着有感冒的小朋友 0 和 4 ，令下标为 1 的小朋友先被传染。
然后，下标为 2 的小朋友挨着感冒的小朋友 1 ，下标为 3 的小朋友挨着感冒的小朋友 4 ，两位小朋友都可以被传染，令下标为 2 的小朋友被传染。
最后，下标为 3 的小朋友被传染，因为他挨着感冒的小朋友 2 和 4 ，感冒序列为 [1,2,3] 。
- 一开始，下标为 1 和 3 的小朋友可以被传染，因为他们分别挨着感冒的小朋友 0 和 4 ，令下标为 1 的小朋友先被传染。
然后，下标为 2 的小朋友挨着感冒的小朋友 1 ，下标为 3 的小朋友挨着感冒的小朋友 4 ，两位小朋友都可以被传染，令下标为 3 的小朋友被传染。
最后，下标为 2 的小朋友被传染，因为他挨着感冒的小朋友 1 和 3 ，感冒序列为  [1,3,2] 。
- 感冒序列 [3,1,2] ，被传染的顺序：[0,1,2,3,4] => [0,1,2,3,4] => [0,1,2,3,4] => [0,1,2,3,4] 。
- 感冒序列 [3,2,1] ，被传染的顺序：[0,1,2,3,4] => [0,1,2,3,4] => [0,1,2,3,4] => [0,1,2,3,4] 。
示例 2：

输入：n = 4, sick = [1]
输出：3
解释：一开始，下标为 0 ，2 和 3 的小朋友没有感冒。总共有 3 个可能的感冒序列：
- 感冒序列 [0,2,3] ，被传染的顺序：[0,1,2,3] => [0,1,2,3] => [0,1,2,3] => [0,1,2,3] 。
- 感冒序列 [2,0,3] ，被传染的顺序：[0,1,2,3] => [0,1,2,3] => [0,1,2,3] => [0,1,2,3] 。
- 感冒序列 [2,3,0] ，被传染的顺序：[0,1,2,3] => [0,1,2,3] => [0,1,2,3] => [0,1,2,3] 。


提示：

2 <= n <= 105
1 <= sick.length <= n - 1
0 <= sick[i] <= n - 1
sick 按升序排列。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

int maxLen = 100000, mod = 1000000007;
vector<long long> factorials(maxLen + 1), inverses(maxLen + 1);

long long fastPower(long long x, int n) {
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

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        factorials[0] = 1;
        inverses[0] = 1;

        for (int i = 1; i <= maxLen; ++i) {
            factorials[i] = factorials[i - 1] * i % mod;
            inverses[i] = fastPower(factorials[i], mod - 2);
        }
    }
}

class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        init();

        int size = sick.size(), m = n - size;
        int len = sick[0];
        long long sequences = combination(m, len);  // 左右两端只有一条路径，所以只需要计算m个位置分别在len个时间点的感染路径
        m -= len;
        len = n - sick[size - 1] - 1;
        sequences = (sequences * combination(m, len)) % mod;
        m -= len;

        for (int i = 1; i < size; ++i) {
            len = sick[i] - sick[i - 1] - 1;
            if (len != 0) {
                sequences = (sequences * combination(m, len)) % mod;  // 中间的位置，除了计算m个位置分别在len个时间点的感染路径
                m -= len;
                sequences = (sequences * fastPower(2, len - 1)) % mod;  // 它本身还有 2 ^ (len - 1)种感染路径
            }
        }

        return (int)sequences;
    }

    long long combination(int x, int y) {  // C(x, y) = P(x, y) / y! = x! / (x - y)! / y! = x! * inverse[(x - y)!] * inverse[y!] (mod)
        return factorials[x] * inverses[x - y] % mod * inverses[y] % mod;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> sick = { 0,4 };
    check.checkInt(4, o.numberOfSequence(5, sick));

    sick = { 1 };
    check.checkInt(3, o.numberOfSequence(4, sick));
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
