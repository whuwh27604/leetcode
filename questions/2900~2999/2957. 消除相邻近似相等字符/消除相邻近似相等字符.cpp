/* 消除相邻近似相等字符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 word 。

一次操作中，你可以选择 word 中任意一个下标 i ，将 word[i] 修改成任意一个小写英文字母。

请你返回消除 word 中所有相邻 近似相等 字符的 最少 操作次数。

两个字符 a 和 b 如果满足 a == b 或者 a 和 b 在字母表中是相邻的，那么我们称它们是 近似相等 字符。



示例 1：

输入：word = "aaaaa"
输出：2
解释：我们将 word 变为 "acaca" ，该字符串没有相邻近似相等字符。
消除 word 中所有相邻近似相等字符最少需要 2 次操作。
示例 2：

输入：word = "abddez"
输出：2
解释：我们将 word 变为 "ybdoez" ，该字符串没有相邻近似相等字符。
消除 word 中所有相邻近似相等字符最少需要 2 次操作。
示例 3：

输入：word = "zyxyxyz"
输出：3
解释：我们将 word 变为 "zaxaxaz" ，该字符串没有相邻近似相等字符。
消除 word 中所有相邻近似相等字符最少需要 3 次操作


提示：

1 <= word.length <= 100
word 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int size = word.size(), opers = 0;

        for (int i = 1; i < size; ++i) {
            if (word[i] == word[i - 1] || word[i] == word[i - 1] + 1 || word[i] == word[i - 1] - 1) {
                ++opers;
                ++i;
            }
        }

        return opers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.removeAlmostEqualCharacters("aaaaa"));
    check.checkInt(2, o.removeAlmostEqualCharacters("abddez"));
    check.checkInt(3, o.removeAlmostEqualCharacters("zyxyxyz"));
    check.checkInt(0, o.removeAlmostEqualCharacters("za"));
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
