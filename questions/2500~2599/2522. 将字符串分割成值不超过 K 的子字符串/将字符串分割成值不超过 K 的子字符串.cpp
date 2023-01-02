/* 将字符串分割成值不超过 K 的子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，它每一位都是 1 到 9 之间的数字组成，同时给你一个整数 k 。

如果一个字符串 s 的分割满足以下条件，我们称它是一个 好 分割：

s 中每个数位 恰好 属于一个子字符串。
每个子字符串的值都小于等于 k 。
请你返回 s 所有的 好 分割中，子字符串的 最少 数目。如果不存在 s 的 好 分割，返回 -1 。

注意：

一个字符串的 值 是这个字符串对应的整数。比方说，"123" 的值为 123 ，"1" 的值是 1 。
子字符串 是字符串中一段连续的字符序列。


示例 1：

输入：s = "165462", k = 60
输出：4
解释：我们将字符串分割成子字符串 "16" ，"54" ，"6" 和 "2" 。每个子字符串的值都小于等于 k = 60 。
不存在小于 4 个子字符串的好分割。
示例 2：

输入：s = "238182", k = 5
输出：-1
解释：这个字符串不存在好分割。


提示：

1 <= s.length <= 105
s[i] 是 '1' 到 '9' 之间的数字。
1 <= k <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumPartition(string s, int k) {
        int size = s.size(), inf = INT_MAX / 2;
        vector<int> dp(size + 1, inf);
        dp[0] = 0;

        for (int i = 0; i < size; ++i) {
            long long num = 0, pow = 1;

            for (int j = i; j >= 0; --j) {
                num += ((long long)s[j] - '0') * pow;
                pow *= 10;
                if (num <= k) {
                    dp[i + 1] = min(dp[i + 1], 1 + dp[j]);
                }
                else {
                    break;
                }
            }
        }

        return dp[size] == inf ? -1 : dp[size];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.minimumPartition("165462", 60));
    check.checkInt(-1, o.minimumPartition("238182", 5));
    check.checkInt(42, o.minimumPartition("165462238182165462238182165462238182165462238182165462238182165462238182", 53));
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
