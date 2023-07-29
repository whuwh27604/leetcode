/* 将字符串中的元音字母排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 s ，将 s 中的元素重新 排列 得到新的字符串 t ，它满足：

所有辅音字母都在原来的位置上。更正式的，如果满足 0 <= i < s.length 的下标 i 处的 s[i] 是个辅音字母，那么 t[i] = s[i] 。
元音字母都必须以他们的 ASCII 值按 非递减 顺序排列。更正式的，对于满足 0 <= i < j < s.length 的下标 i 和 j  ，如果 s[i] 和 s[j] 都是元音字母，那么 t[i] 的 ASCII 值不能大于 t[j] 的 ASCII 值。
请你返回结果字母串。

元音字母为 'a' ，'e' ，'i' ，'o' 和 'u' ，它们可能是小写字母也可能是大写字母，辅音字母是除了这 5 个字母以外的所有字母。



示例 1：

输入：s = "lEetcOde"
输出："lEOtcede"
解释：'E' ，'O' 和 'e' 是 s 中的元音字母，'l' ，'t' ，'c' 和 'd' 是所有的辅音。将元音字母按照 ASCII 值排序，辅音字母留在原地。
示例 2：

输入：s = "lYmpH"
输出："lYmpH"
解释：s 中没有元音字母（s 中都为辅音字母），所以我们返回 "lYmpH" 。


提示：

1 <= s.length <= 105
s 只包含英语字母表中的 大写 和 小写 字母。
*/

#include <iostream>
#include <unordered_set>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = { 'a','e','i','o','u','A','E','I','O','U' };
        map<char, int> count;
        int size = s.size();
        string ans = s;

        for (char c : s) {
            if (vowels.count(c) != 0) {
                ++count[c];
            }
        }

        for (int i = 0; i < size; ++i) {
            if (vowels.count(s[i]) != 0) {
                ans[i] = count.begin()->first;
                if (--count.begin()->second == 0) {
                    count.erase(count.begin());
                }
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("lEOtcede", o.sortVowels("lEetcOde"));
    check.checkString("lYmpH", o.sortVowels("lYmpH"));
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
