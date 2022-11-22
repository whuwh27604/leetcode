/* 完美分割的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，每个字符是数字 '1' 到 '9' ，再给你两个整数 k 和 minLength 。

如果对 s 的分割满足以下条件，那么我们认为它是一个 完美 分割：

s 被分成 k 段互不相交的子字符串。
每个子字符串长度都 至少 为 minLength 。
每个子字符串的第一个字符都是一个 质数 数字，最后一个字符都是一个 非质数 数字。质数数字为 '2' ，'3' ，'5' 和 '7' ，剩下的都是非质数数字。
请你返回 s 的 完美 分割数目。由于答案可能很大，请返回答案对 109 + 7 取余 后的结果。

一个 子字符串 是字符串中一段连续字符串序列。



示例 1：

输入：s = "23542185131", k = 3, minLength = 2
输出：3
解释：存在 3 种完美分割方案：
"2354 | 218 | 5131"
"2354 | 21851 | 31"
"2354218 | 51 | 31"
示例 2：

输入：s = "23542185131", k = 3, minLength = 3
输出：1
解释：存在一种完美分割方案："2354 | 218 | 5131" 。
示例 3：

输入：s = "3312958", k = 3, minLength = 1
输出：1
解释：存在一种完美分割方案："331 | 29 | 58" 。


提示：

1 <= k, minLength <= s.length <= 1000
s 每个字符都为数字 '1' 到 '9' 之一。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        int size = s.size(), start = 0, next = 0;
        vector<int> lens;

        do {
            next = getOnePart(s, start, minLength);
            if (next == -1) {
                return 0;
            }
            
            lens.push_back(next - start);
            start = next;
        } while (start != size);

        return getWays(lens, k, minLength);
    }

    int getOnePart(string& s, int start, int minLength) {
        int size = s.size(), next = start;

        for (; next < size && isPrime(s[next]); ++next) {}
        if (next == start || next == size) {
            return -1;
        }

        for (; next < size && !isPrime(s[next]); ++next) {}

        return next;
    }

    bool isPrime(char c) {
        return c == '2' || c == '3' || c == '5' || c == '7';
    }

    int getWays(vector<int>& lens, int k, int minLength) {
        int size = lens.size(), len = 0, mod = 1000000007;
        vector<vector<int>> dp(k + 1, vector<int>(size, 0));
        vector<int> prevPresums(size + 1, 0), curPresums(size + 1, 0);

        for (int j = 0; j < size; ++j) {
            len += lens[j];
            if (len >= minLength) {
                dp[1][j] = 1;
            }
            prevPresums[j + 1] = prevPresums[j] + dp[1][j];
        }

        for (int i = 2; i <= k; ++i) {
            int p = 0, lastLen = 0;

            for (int j = 0; j < size; ++j) {
                lastLen += lens[j];
                while (lastLen - lens[p] >= minLength) {
                    lastLen -= lens[p++];
                }

                dp[i][j] = prevPresums[p];
                curPresums[j + 1] = (curPresums[j] + dp[i][j]) % mod;
            }

            prevPresums = curPresums;
        }

        return dp[k][size - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.beautifulPartitions("23542185131", 3, 2));
    check.checkInt(1, o.beautifulPartitions("23542185131", 3, 3));
    check.checkInt(1, o.beautifulPartitions("3312958", 3, 1));
    check.checkInt(4, o.beautifulPartitions("783938233588472343879134266968", 4, 6));
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
