/* 判断通过操作能否让字符串相等 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 s1 和 s2 ，两个字符串的长度都为 4 ，且只包含 小写 英文字母。

你可以对两个字符串中的 任意一个 执行以下操作 任意 次：

选择两个下标 i 和 j 且满足 j - i = 2 ，然后 交换 这个字符串中两个下标对应的字符。
如果你可以让字符串 s1 和 s2 相等，那么返回 true ，否则返回 false 。



示例 1：

输入：s1 = "abcd", s2 = "cdab"
输出：true
解释： 我们可以对 s1 执行以下操作：
- 选择下标 i = 0 ，j = 2 ，得到字符串 s1 = "cbad" 。
- 选择下标 i = 1 ，j = 3 ，得到字符串 s1 = "cdab" = s2 。
示例 2：

输入：s1 = "abcd", s2 = "dacb"
输出：false
解释：无法让两个字符串相等。


提示：

s1.length == s2.length == 4
s1 和 s2 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string t1 = s1;
        swap(t1[0], t1[2]);
        string t2 = s1;
        swap(t2[1], t2[3]);
        string t3 = s1;
        swap(t3[0], t3[2]);
        swap(t3[1], t3[3]);

        return s1 == s2 || t1 == s2 || t2 == s2 || t3 == s2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.canBeEqual("abcd", "cdab"));
    check.checkBool(false, o.canBeEqual("abcd", "dacb"));
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
