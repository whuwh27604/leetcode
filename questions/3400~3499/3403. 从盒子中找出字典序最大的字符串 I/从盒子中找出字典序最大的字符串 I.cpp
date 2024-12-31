﻿/* 从盒子中找出字典序最大的字符串 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 word 和一个整数 numFriends。

Alice 正在为她的 numFriends 位朋友组织一个游戏。游戏分为多个回合，在每一回合中：

word 被分割成 numFriends 个 非空 字符串，且该分割方式与之前的任意回合所采用的都 不完全相同 。
所有分割出的字符串都会被放入一个盒子中。
在所有回合结束后，找出盒子中 字典序最大的 字符串。

字符串 a 的字典序 小于 字符串 b 的前提是：在两个字符串上第一处不同的位置上，a 的字母在字母表中的顺序早于 b 中对应的字母。
如果前 min(a.length, b.length) 个字符都相同，那么较短的字符串字典序更小。



示例 1：

输入: word = "dbca", numFriends = 2

输出: "dbc"

解释:

所有可能的分割方式为：

"d" 和 "bca"。
"db" 和 "ca"。
"dbc" 和 "a"。
示例 2：

输入: word = "gggg", numFriends = 4

输出: "g"

解释:

唯一可能的分割方式为："g", "g", "g", 和 "g"。



提示:

1 <= word.length <= 5 * 103
word 仅由小写英文字母组成。
1 <= numFriends <= word.length
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }

        int size = (int)word.size(), maxLen = size - (numFriends - 1);
        string ans(word, 0, maxLen);

        for (int i = 1; i < size; ++i) {
            ans = max(ans, string(word, i, min(maxLen, size - i)));
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("dbc", o.answerString("dbca", 2));
    check.checkString("g", o.answerString("gggg", 4));
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
