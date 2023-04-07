/* 最长平衡子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个仅由 0 和 1 组成的二进制字符串 s 。

如果子字符串中 所有的 0 都在 1 之前 且其中 0 的数量等于 1 的数量，则认为 s 的这个子字符串是平衡子字符串。请注意，空子字符串也视作平衡子字符串。

返回  s 中最长的平衡子字符串长度。

子字符串是字符串中的一个连续字符序列。



示例 1：

输入：s = "01000111"
输出：6
解释：最长的平衡子字符串是 "000111" ，长度为 6 。
示例 2：

输入：s = "00111"
输出：4
解释：最长的平衡子字符串是 "0011" ，长度为  4 。
示例 3：

输入：s = "111"
输出：0
解释：除了空子字符串之外不存在其他平衡子字符串，所以答案为 0 。


提示：

1 <= s.length <= 50
'0' <= s[i] <= '1'
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int maxLen = 0, zeros = 0, ones = 0;
        char prev = 0;
        s += '2';

        for (char c : s) {
            if (c == prev) {
                c == '0' ? ++zeros : ++ones;
            }
            else {
                int len = min(zeros, ones);
                maxLen = max(maxLen, len);

                if (c == '0') {
                    zeros = 1;
                    ones = 0;
                }
                else {
                    ones = 1;
                }
            }

            prev = c;
        }

        return maxLen * 2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(6, o.findTheLongestBalancedSubstring("01000111"));
    check.checkInt(4, o.findTheLongestBalancedSubstring("00111"));
    check.checkInt(0, o.findTheLongestBalancedSubstring("11100"));
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
