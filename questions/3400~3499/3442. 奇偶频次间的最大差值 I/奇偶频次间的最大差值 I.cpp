/* 奇偶频次间的最大差值 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由小写英文字母组成的字符串 s 。请你找出字符串中两个字符的出现频次之间的 最大 差值，这两个字符需要满足：

一个字符在字符串中出现 偶数次 。
另一个字符在字符串中出现 奇数次 。
返回 最大 差值，计算方法是出现 奇数次 字符的次数 减去 出现 偶数次 字符的次数。



示例 1：

输入：s = "aaaaabbc"

输出：3

解释：

字符 'a' 出现 奇数次 ，次数为 5 ；字符 'b' 出现 偶数次 ，次数为 2 。
最大差值为 5 - 2 = 3 。
示例 2：

输入：s = "abcabcab"

输出：1

解释：

字符 'a' 出现 奇数次 ，次数为 3 ；字符 'c' 出现 偶数次 ，次数为 2 。
最大差值为 3 - 2 = 1 。


提示：

3 <= s.length <= 100
s 仅由小写英文字母组成。
s 至少由一个出现奇数次的字符和一个出现偶数次的字符组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnt(127, 0);
        int maxOdd = 0, minEven = INT_MAX;

        for (char c : s) {
            ++cnt[c];
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt[c] != 0) {
                if ((cnt[c] & 1) == 0) {
                    minEven = min(minEven, cnt[c]);
                }
                else {
                    maxOdd = max(maxOdd, cnt[c]);
                }
            }            
        }

        return maxOdd - minEven;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(3, o.maxDifference("aaaaabbc"));
    check.checkInt(1, o.maxDifference("abcabcab"));
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
