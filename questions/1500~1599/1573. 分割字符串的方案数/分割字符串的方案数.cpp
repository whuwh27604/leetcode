/* 分割字符串的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制串 s  （一个只包含 0 和 1 的字符串），我们可以将 s 分割成 3 个 非空 字符串 s1, s2, s3 （s1 + s2 + s3 = s）。

请你返回分割 s 的方案数，满足 s1，s2 和 s3 中字符 '1' 的数目相同。

由于答案可能很大，请将它对 10^9 + 7 取余后返回。

 

示例 1：

输入：s = "10101"
输出：4
解释：总共有 4 种方法将 s 分割成含有 '1' 数目相同的三个子字符串。
"1|010|1"
"1|01|01"
"10|10|1"
"10|1|01"
示例 2：

输入：s = "1001"
输出：0
示例 3：

输入：s = "0000"
输出：3
解释：总共有 3 种分割 s 的方法。
"0|0|00"
"0|00|0"
"00|0|0"
示例 4：

输入：s = "100100010100110"
输出：12
 

提示：

s[i] == '0' 或者 s[i] == '1'
3 <= s.length <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-split-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numWays(string s) {
        int ones = countOnes(s);

        if ((ones % 3) != 0) {
            return 0;
        }

        if (ones == 0) {
            return (int)((long long)(s.size() - 1) * (s.size() - 2) / 2 % 1000000007);
        }

        ones /= 3;
        return (int)(((long long)countZerosAfterKOnes(s, ones) + 1) * ((long long)countZerosBeforeLastKOnes(s, ones) + 1) % 1000000007);
    }

    int countOnes(string& s) {
        int count = 0;

        for (char c : s) {
            if (c == '1') {
                ++count;
            }
        }

        return count;
    }

    int countZerosAfterKOnes(string& s, int k) {
        int ones = 0, zeros = 0;

        for (char c : s) {
            if (c == '1') {
                if (++ones > k) {
                    break;
                }
            }
            else {
                if (ones == k) {
                    ++zeros;
                }
            }
        }

        return zeros;
    }

    int countZerosBeforeLastKOnes(string& s, int k) {
        int ones = 0, zeros = 0, i, size = s.size();

        for (i = size - 1; i >= 0; --i) {
            if (s[i] == '1') {
                if (++ones > k) {
                    break;
                }
            }
            else {
                if (ones == k) {
                    ++zeros;
                }
            }
        }

        return zeros;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.numWays("10101"));
    check.checkInt(0, o.numWays("1001"));
    check.checkInt(3, o.numWays("0000"));
    check.checkInt(12, o.numWays("100100010100110"));
    check.checkInt(1, o.numWays("111"));
    check.checkInt(703, o.numWays("000000000000000000000000000000000000000"));
    check.checkInt(648, o.numWays("1000000000000000001000000000000000000000000000000000001"));
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
