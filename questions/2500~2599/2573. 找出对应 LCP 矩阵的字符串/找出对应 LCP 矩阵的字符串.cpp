﻿/* 找出对应 LCP 矩阵的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
对任一由 n 个小写英文字母组成的字符串 word ，我们可以定义一个 n x n 的矩阵，并满足：

lcp[i][j] 等于子字符串 word[i,...,n-1] 和 word[j,...,n-1] 之间的最长公共前缀的长度。
给你一个 n x n 的矩阵 lcp 。返回与 lcp 对应的、按字典序最小的字符串 word 。如果不存在这样的字符串，则返回空字符串。

对于长度相同的两个字符串 a 和 b ，如果在 a 和 b 不同的第一个位置，字符串 a 的字母在字母表中出现的顺序先于 b 中的对应字母，则认为字符串 a 按字典序比字符串 b 小。例如，"aabd" 在字典上小于 "aaca" ，因为二者不同的第一位置是第三个字母，而 'b' 先于 'c' 出现。



示例 1：

输入：lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
输出："abab"
解释：lcp 对应由两个交替字母组成的任意 4 字母字符串，字典序最小的是 "abab" 。
示例 2：

输入：lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]
输出："aaaa"
解释：lcp 对应只有一个不同字母的任意 4 字母字符串，字典序最小的是 "aaaa" 。
示例 3：

输入：lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]
输出：""
解释：lcp[3][3] 无法等于 3 ，因为 word[3,...,3] 仅由单个字母组成；因此，不存在答案。


提示：

1 <= n == lcp.length == lcp[i].length <= 1000
0 <= lcp[i][j] <= n
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int size = lcp.size();
        string s(size, 'A');
        char current = 'a';  // 字典序最小，第一个字符必然是a

        for (int i = 0; i < size; ++i) {
            if (s[i] == 'A') {
                if (current > 'z') {  // 已经没有小写字母可用了，返回失败
                    return "";
                }

                s[i] = current;  // 如果当前位还未定，选择最小的可选字符

                for (int j = i + 1; j < size; ++j) {  // 将后续所有相同字符确定下来
                    if (lcp[i][j] != 0) {  // lcp[i][j]不为0，说明i位和j位的字符肯定是相同的
                        s[j] = current;
                    }
                }

                ++current;
            }
        }

        return check(s, lcp) ? s : "";
    }

    bool check(string& s, vector<vector<int>>& lcp) {
        int size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));  // 根据s求真实的lcp，和给定的lcp比较是否一致
        dp[size - 1][size - 1] = 1;

        for (int i = size - 2; i >= 0; --i) {
            if (s[i] == s[size - 1]) {
                dp[i][size - 1] = 1;
            }
        }

        for (int j = size - 2; j >= 0; --j) {
            if (s[j] == s[size - 1]) {
                dp[size - 1][j] = 1;
            }
        }

        for (int i = size - 2; i >= 0; --i) {
            for (int j = size - 2; j >= 0; --j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
            }
        }

        return dp == lcp;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> lcp = { {4,0,2,0},{0,3,0,1},{2,0,2,0},{0,1,0,1} };
    check.checkString("abab", o.findTheString(lcp));

    lcp = { {4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1} };
    check.checkString("aaaa", o.findTheString(lcp));

    lcp = { {4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,3} };
    check.checkString("", o.findTheString(lcp));

    lcp = { {1} };
    check.checkString("a", o.findTheString(lcp));

    lcp = { {27,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1} };
    check.checkString("", o.findTheString(lcp));
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
