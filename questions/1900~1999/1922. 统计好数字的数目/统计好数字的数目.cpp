/* 统计好数字的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们称一个数字字符串是 好数字 当它满足（下标从 0 开始）偶数 下标处的数字为 偶数 且 奇数 下标处的数字为 质数 （2，3，5 或 7）。

比方说，"2582" 是好数字，因为偶数下标处的数字（2 和 8）是偶数且奇数下标处的数字（5 和 2）为质数。但 "3245" 不是 好数字，因为 3 在偶数下标处但不是偶数。
给你一个整数 n ，请你返回长度为 n 且为好数字的数字字符串 总数 。由于答案可能会很大，请你将它对 109 + 7 取余后返回 。

一个 数字字符串 是每一位都由 0 到 9 组成的字符串，且可能包含前导 0 。

 

示例 1：

输入：n = 1
输出：5
解释：长度为 1 的好数字包括 "0"，"2"，"4"，"6"，"8" 。
示例 2：

输入：n = 4
输出：400
示例 3：

输入：n = 50
输出：564908303
 

提示：

1 <= n <= 1015

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-good-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long x = (n + 1) / 2, y = n / 2;  // 很显然答案是pow(5, x) * pow(4, y)

        return (int)(fastPower(5, x) * fastPower(4, y) % mod);
    }

    long long fastPower(int x, long long n) {
        long long ans = 1, bit = 1;

        while (n != 0) {
            if ((n & bit) != 0) {
                ans = (ans * x) % mod;
            }

            n &= ~bit;
            bit <<= 1;
            x = ((long long)x * x) % mod;
        }

        return ans;
    }

private:
    int mod = 1000000007;
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.countGoodNumbers(1));
    check.checkInt(400, o.countGoodNumbers(4));
    check.checkInt(564908303, o.countGoodNumbers(50));
    check.checkInt(643535977, o.countGoodNumbers(806166225460393));
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
