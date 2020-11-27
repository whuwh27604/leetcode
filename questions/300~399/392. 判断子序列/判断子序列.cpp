/* 判断子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

示例 1:
s = "abc", t = "ahbgdc"

返回 true.

示例 2:
s = "axc", t = "ahbgdc"

返回 false.

后续挑战 :

如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/is-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }

        unsigned int j = 0;
        for (unsigned int i = 0; i < t.size(); i++) {
            if (t[i] == s[j]) {
                j++;
                if (j == s.size()) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string s = "abc";
    string t = "ahbgdc";
    check.checkBool(true, o.isSubsequence(s, t));

    s = "axc";
    t = "ahbgdc";
    check.checkBool(false, o.isSubsequence(s, t));

    s = "xac";
    t = "ahbgdc";
    check.checkBool(false, o.isSubsequence(s, t));

    s = "acx";
    t = "ahbgdc";
    check.checkBool(false, o.isSubsequence(s, t));

    s = "";
    t = "ahbgdc";
    check.checkBool(true, o.isSubsequence(s, t));

    s = "";
    t = "";
    check.checkBool(true, o.isSubsequence(s, t));

    s = "a";
    t = "abc";
    check.checkBool(true, o.isSubsequence(s, t));

    s = "c";
    t = "abc";
    check.checkBool(true, o.isSubsequence(s, t));

    s = "abcde";
    t = "abcde";
    check.checkBool(true, o.isSubsequence(s, t));
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
