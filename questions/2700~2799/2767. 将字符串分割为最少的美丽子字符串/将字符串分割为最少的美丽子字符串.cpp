/* 将字符串分割为最少的美丽子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串 s ，你需要将字符串分割成一个或者多个 子字符串  ，使每个子字符串都是 美丽 的。

如果一个字符串满足以下条件，我们称它是 美丽 的：

它不包含前导 0 。
它是 5 的幂的 二进制 表示。
请你返回分割后的子字符串的 最少 数目。如果无法将字符串 s 分割成美丽子字符串，请你返回 -1 。

子字符串是一个字符串中一段连续的字符序列。



示例 1：

输入：s = "1011"
输出：2
解释：我们可以将输入字符串分成 ["101", "1"] 。
- 字符串 "101" 不包含前导 0 ，且它是整数 51 = 5 的二进制表示。
- 字符串 "1" 不包含前导 0 ，且它是整数 50 = 1 的二进制表示。
最少可以将 s 分成 2 个美丽子字符串。
示例 2：

输入：s = "111"
输出：3
解释：我们可以将输入字符串分成 ["1", "1", "1"] 。
- 字符串 "1" 不包含前导 0 ，且它是整数 50 = 1 的二进制表示。
最少可以将 s 分成 3 个美丽子字符串。
示例 3：

输入：s = "0"
输出：-1
解释：无法将给定字符串分成任何美丽子字符串。


提示：

1 <= s.length <= 15
s[i] 要么是 '0' 要么是 '1' 。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int size = s.size(), inf = INT_MAX / 2;
        vector<int> dp(size + 1, inf);
        dp[size] = 0;

        for (int i = size - 1; i >= 0; --i) {
            for (int j = i; j < size; ++j) {
                if (dp[j + 1] != inf && check(s, i, j)) {
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
        }

        return dp[0] == inf ? -1 : dp[0];
    }

    bool check(string& s, int start, int end) {
        if (s[start] == '0') {
            return false;
        }

        int num = 0, bit = 1;
        for (int i = end; i >= start; --i, bit <<= 1) {
            if (s[i] == '1') {
                num += bit;
            }
        }

        if (num == 0) {
            return false;
        }

        while (num != 1) {
            if (num % 5 != 0) {
                return false;
            }

            num /= 5;
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.minimumBeautifulSubstrings("1011"));
    check.checkInt(3, o.minimumBeautifulSubstrings("111"));
    check.checkInt(-1, o.minimumBeautifulSubstrings("0"));
    check.checkInt(4, o.minimumBeautifulSubstrings("10110111111011"));
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
