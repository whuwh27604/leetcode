/* 统计回文子序列数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你数字字符串 s ，请你返回 s 中长度为 5 的 回文子序列 数目。由于答案可能很大，请你将答案对 109 + 7 取余 后返回。

提示：

如果一个字符串从前往后和从后往前读相同，那么它是 回文字符串 。
子序列是一个字符串中删除若干个字符后，不改变字符顺序，剩余字符构成的字符串。


示例 1：

输入：s = "103301"
输出：2
解释：
总共有 6 长度为 5 的子序列："10330" ，"10331" ，"10301" ，"10301" ，"13301" ，"03301" 。
它们中有两个（都是 "10301"）是回文的。
示例 2：

输入：s = "0000000"
输出：21
解释：所有 21 个长度为 5 的子序列都是 "00000" ，都是回文的。
示例 3：

输入：s = "9999900000"
输出：2
解释：仅有的两个回文子序列是 "99999" 和 "00000" 。


提示：

1 <= s.length <= 104
s 只包含数字字符。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPalindromes(string s) {
        vector<int> dp1(10, 0), dp2(100, 0), dp3(1000, 0), dp4(10000, 0), dp5(100000, 0);

        for (char c : s) {
            int digit = c - '0';
            count5(dp5, dp4, digit);
            count4(dp4, dp3, digit);
            count3(dp3, dp2, digit);
            count2(dp2, dp1, digit);
            count1(dp1, digit);
        }

        return count(dp5);
    }

    void count1(vector<int>& dp1, int digit) {
        ++dp1[digit];
    }

    void count2(vector<int>& dp2, vector<int>& dp1, int digit) {
        for (int d = 0; d < 10; ++d) {
            int num = d * 10 + digit;
            dp2[num] = (dp2[num] + dp1[d]) % mod;
        }
    }

    void count3(vector<int>& dp3, vector<int>& dp2, int digit) {
        for (int d = 0; d < 100; ++d) {
            int num = d * 10 + digit;
            dp3[num] = (dp3[num] + dp2[d]) % mod;
        }
    }

    void count4(vector<int>& dp4, vector<int>& dp3, int digit) {
        for (int d1 = 0; d1 < 10; ++d1) {
            for (int d3 = 0; d3 < 10; ++d3) {
                int num = d1 * 1000 + digit * 100 + d3 * 10 + digit;
                dp4[num] = (dp4[num] + dp3[d1 * 100 + digit * 10 + d3]) % mod;
            }
        }
    }

    void count5(vector<int>& dp5, vector<int>& dp4, int digit) {
        for (int d2 = 0; d2 < 10; ++d2) {
            for (int d3 = 0; d3 < 10; ++d3) {
                int num = digit * 10000 + d2 * 1000 + d3 * 100 + d2 * 10 + digit;
                dp5[num] = (dp5[num] + dp4[digit * 1000 + d2 * 100 + d3 * 10 + d2]) % mod;
            }
        }
    }

    int count(vector<int>& dp5) {
        int cnt = 0;

        for (int num : dp5) {
            cnt = (cnt + num) % mod;
        }

        return cnt;
    }

private:
    int mod = 1000000007;
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.countPalindromes("103301"));
    check.checkInt(21, o.countPalindromes("0000000"));
    check.checkInt(2, o.countPalindromes("9999900000"));
    check.checkInt(0, o.countPalindromes("1"));
    check.checkInt(71234974, o.countPalindromes("103301000000099999000001033010000000999990000010330100000009999900000103301000000099999000001033010000000999990000010330100000009999900000"));
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
