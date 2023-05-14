/* 字典序最小的美丽字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一个字符串满足以下条件，则称其为 美丽字符串 ：

它由英语小写字母表的前 k 个字母组成。
它不包含任何长度为 2 或更长的回文子字符串。
给你一个长度为 n 的美丽字符串 s 和一个正整数 k 。

请你找出并返回一个长度为 n 的美丽字符串，该字符串还满足：在字典序大于 s 的所有美丽字符串中字典序最小。如果不存在这样的字符串，则返回一个空字符串。

对于长度相同的两个字符串 a 和 b ，如果字符串 a 在与字符串 b 不同的第一个位置上的字符字典序更大，则字符串 a 的字典序大于字符串 b 。

例如，"abcd" 的字典序比 "abcc" 更大，因为在不同的第一个位置（第四个字符）上 d 的字典序大于 c 。


示例 1：

输入：s = "abcz", k = 26
输出："abda"
解释：字符串 "abda" 既是美丽字符串，又满足字典序大于 "abcz" 。
可以证明不存在字符串同时满足字典序大于 "abcz"、美丽字符串、字典序小于 "abda" 这三个条件。
示例 2：

输入：s = "dc", k = 4
输出：""
解释：可以证明，不存在既是美丽字符串，又字典序大于 "dc" 的字符串。


提示：

1 <= n == s.length <= 105
4 <= k <= 26
s 是一个美丽字符串
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int size = s.size(), i = size;
        bool find = false;
        char maxC = 'a' + k - 1;

        while (!find && i != 0) {  // 先找第一个可以修改的位置
            --i;

            while (s[i] != maxC) {
                ++s[i];
                if ((i == 0) || (i == 1 && s[i] != s[i - 1]) || (i > 1 && s[i] != s[i - 1] && s[i] != s[i - 2])) {  // 修改后和前两个位置都不同，那么该位置可修改
                    find = true;
                    break;
                }
            }
        }

        if (!find) {
            return "";
        }

        for (++i; i < size; ++i) {  // 填充后面的位置
            if (s[i - 1] == 'a' || (i > 1 && s[i - 2] == 'a')) {  // 如果前两个位置有a
                s[i] = ((s[i - 1] == 'b' || (i > 1 && s[i - 2] == 'b')) ? 'c' : 'b');  // 如果前两个位置没有b，那么可以是b；否则只能是c
            }
            else {  // 前两个位置没有a，那么这里可以是a
                s[i] = 'a';
            }
        }

        return s;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("abda", o.smallestBeautifulString("abcz", 26));
    check.checkString("", o.smallestBeautifulString("dc", 4));
    check.checkString("b", o.smallestBeautifulString("a", 26));
    check.checkString("", o.smallestBeautifulString("d", 4));
    check.checkString("ba", o.smallestBeautifulString("ad", 4));
    check.checkString("acb", o.smallestBeautifulString("abd", 4));
    check.checkString("cef", o.smallestBeautifulString("ced", 6));
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
