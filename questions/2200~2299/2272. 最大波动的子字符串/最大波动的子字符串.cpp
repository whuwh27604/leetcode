/* 最大波动的子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
字符串的 波动 定义为子字符串中出现次数 最多 的字符次数与出现次数 最少 的字符次数之差。

给你一个字符串 s ，它只包含小写英文字母。请你返回 s 里所有 子字符串的 最大波动 值。

子字符串 是一个字符串的一段连续字符序列。

 

示例 1：

输入：s = "aababbb"
输出：3
解释：
所有可能的波动值和它们对应的子字符串如以下所示：
- 波动值为 0 的子字符串："a" ，"aa" ，"ab" ，"abab" ，"aababb" ，"ba" ，"b" ，"bb" 和 "bbb" 。
- 波动值为 1 的子字符串："aab" ，"aba" ，"abb" ，"aabab" ，"ababb" ，"aababbb" 和 "bab" 。
- 波动值为 2 的子字符串："aaba" ，"ababbb" ，"abbb" 和 "babb" 。
- 波动值为 3 的子字符串 "babbb" 。
所以，最大可能波动值为 3 。
示例 2：

输入：s = "abcde"
输出：0
解释：
s 中没有字母出现超过 1 次，所以 s 中每个子字符串的波动值都是 0 。
 

提示：

1 <= s.length <= 104
s  只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/substring-with-largest-variance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int maxVariance = 0;

        for (char a = 'a'; a <= 'z'; ++a) {
            for (char b = 'a'; b <= 'z'; ++b) {
                if (b != a) {
                    maxVariance = max(maxVariance, getMaxVariance(s, a, b));
                }
            }
        }

        return maxVariance;
    }

    int getMaxVariance(string& s, char a, char b) {
        int count1 = 0, count2 = 0, maxVariance = 0;  // 有两种模式：1、aaa...b或者aaa...bb...aaa...；2、baaa...
        bool valid1 = false, valid2 = false;

        for (char c : s) {
            if (c == a) {
                ++count1;

                if (valid1) {
                    maxVariance = max(maxVariance, count1);
                }

                if (valid2) {
                    maxVariance = max(maxVariance, ++count2);
                }
            }
            else if (c == b) {
                if (count1 == 0) {
                    valid1 = false;
                }
                else {
                    valid1 = true;
                    maxVariance = max(maxVariance, --count1);
                }

                count2 = -1;
                valid2 = true;
            }
        }

        return maxVariance;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.largestVariance("aababbb"));
    check.checkInt(0, o.largestVariance("abcde"));
    check.checkInt(1, o.largestVariance("lripaa"));
    check.checkInt(1, o.largestVariance("ababab"));
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
