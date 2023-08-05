/* 包含三个字符串的最短字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你三个字符串 a ，b 和 c ， 你的任务是找到长度 最短 的字符串，且这三个字符串都是它的 子字符串 。
如果有多个这样的字符串，请你返回 字典序最小 的一个。

请你返回满足题目要求的字符串。

注意：

两个长度相同的字符串 a 和 b ，如果在第一个不相同的字符处，a 的字母在字母表中比 b 的字母 靠前 ，那么字符串 a 比字符串 b 字典序小 。
子字符串 是一个字符串中一段连续的字符序列。


示例 1：

输入：a = "abc", b = "bca", c = "aaa"
输出："aaabca"
解释：字符串 "aaabca" 包含所有三个字符串：a = ans[2...4] ，b = ans[3..5] ，c = ans[0..2] 。结果字符串的长度至少为 6 ，且"aaabca" 是字典序最小的一个。
示例 2：

输入：a = "ab", b = "ba", c = "aba"
输出："aba"
解释：字符串 "aba" 包含所有三个字符串：a = ans[0..1] ，b = ans[1..2] ，c = ans[0..2] 。由于 c 的长度为 3 ，结果字符串的长度至少为 3 。"aba" 是字典序最小的一个。


提示：

1 <= a.length, b.length, c.length <= 100
a ，b ，c 只包含小写英文字母。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string minimumString(string a, string b, string c) {
        string ans = build3(a, b, c);
        ans = getLess(ans, build3(a, c, b));
        ans = getLess(ans, build3(b, a, c));
        ans = getLess(ans, build3(b, c, a));
        ans = getLess(ans, build3(c, a, b));
        ans = getLess(ans, build3(c, b, a));

        return ans;
    }

    string build3(string a, string b, string c) {
        return build2(build2(a, b), c);
    }

    string build2(string a, string b) {
        if (a.find(b) != a.npos) {
            return a;
        }

        int size1 = a.size(), size2 = b.size(), len = min(size1, size2 - 1);

        while (len > 0 && a.compare(size1 - len, len, b, 0, len) != 0) {
            --len;
        }

        for (int i = len; i < size2; ++i) {
            a += b[i];
        }

        return a;
    }

    string getLess(string a, string b) {
        if (a.size() != b.size()) {
            return a.size() < b.size() ? a : b;
        }
        else {
            return a < b ? a : b;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("aaabca", o.minimumString("abc", "bca", "aaa"));
    check.checkString("aba", o.minimumString("ab", "ba", "aba"));
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
