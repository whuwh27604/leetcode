/* 最短且字典序最小的美丽子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串 s 和一个正整数 k 。

如果 s 的某个子字符串中 1 的个数恰好等于 k ，则称这个子字符串是一个 美丽子字符串 。

令 len 等于 最短 美丽子字符串的长度。

返回长度等于 len 且字典序 最小 的美丽子字符串。如果 s 中不含美丽子字符串，则返回一个 空 字符串。

对于相同长度的两个字符串 a 和 b ，如果在 a 和 b 出现不同的第一个位置上，a 中该位置上的字符严格大于 b 中的对应字符，则认为字符串 a 字典序 大于 字符串 b 。

例如，"abcd" 的字典序大于 "abcc" ，因为两个字符串出现不同的第一个位置对应第四个字符，而 d 大于 c 。


示例 1：

输入：s = "100011001", k = 3
输出："11001"
解释：示例中共有 7 个美丽子字符串：
1. 子字符串 "100011001" 。
2. 子字符串 "100011001" 。
3. 子字符串 "100011001" 。
4. 子字符串 "100011001" 。
5. 子字符串 "100011001" 。
6. 子字符串 "100011001" 。
7. 子字符串 "100011001" 。
最短美丽子字符串的长度是 5 。
长度为 5 且字典序最小的美丽子字符串是子字符串 "11001" 。
示例 2：

输入：s = "1011", k = 2
输出："11"
解释：示例中共有 3 个美丽子字符串：
1. 子字符串 "1011" 。
2. 子字符串 "1011" 。
3. 子字符串 "1011" 。
最短美丽子字符串的长度是 2 。
长度为 2 且字典序最小的美丽子字符串是子字符串 "11" 。
示例 3：

输入：s = "000", k = 1
输出：""
解释：示例中不存在美丽子字符串。


提示：

1 <= s.length <= 100
1 <= k <= s.length
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int minLen = getMinLen(s, k);
        if (minLen == -1) {
            return "";
        }

        return getMinSubstr(s, k, minLen);
    }

    int getMinLen(string& s, int k) {
        int size = s.size(), right = 0, count = 0, minLen = INT_MAX;

        for (int left = 0; left < size; ++left) {
            while (count < k && right < size) {
                if (s[right] == '1') {
                    ++count;
                }

                ++right;
            }

            if (count == k) {
                minLen = min(minLen, right - left);
            }

            if (s[left] == '1') {
                --count;
            }
        }

        return minLen == INT_MAX ? -1 : minLen;
    }

    string getMinSubstr(string& s, int k, int minLen) {
        int size = s.size(), left = 0, right = 0, count = 0;
        string minSubstr(minLen, '2');

        for (; right < minLen - 1; ++right) {
            if (s[right] == '1') {
                ++count;
            }
        }

        for (; right < size; ++left, ++right) {
            if (s[right] == '1') {
                ++count;
            }

            if (count == k) {
                minSubstr = min(minSubstr, string(s, left, minLen));
            }

            if (s[left] == '1') {
                --count;
            }
        }

        return minSubstr;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("11001", o.shortestBeautifulSubstring("100011001", 3));
    check.checkString("11", o.shortestBeautifulSubstring("1011", 2));
    check.checkString("", o.shortestBeautifulSubstring("000", 1));
    check.checkString("1", o.shortestBeautifulSubstring("1", 1));
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
