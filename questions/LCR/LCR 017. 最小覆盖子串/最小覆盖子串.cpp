/* 最小覆盖子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。如果 s 中不存在符合条件的子字符串，则返回空字符串 "" 。

如果 s 中存在多个符合条件的子字符串，返回任意一个。



注意： 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。



示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最短子字符串 "BANC" 包含了字符串 t 的所有字符 'A'、'B'、'C'
示例 2：

输入：s = "a", t = "a"
输出："a"
示例 3：

输入：s = "a", t = "aa"
输出：""
解释：t 中两个字符 'a' 均应包含在 s 的子串中，因此没有符合条件的子字符串，返回空字符串。


提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成


进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？



注意：本题与主站 76 题相似（本题答案不唯一）：https://leetcode-cn.com/problems/minimum-window-substring/
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, size = s.size(), minLen = INT_MAX;
        string ans;
        bool valid = false;
        vector<int> countS(127, 0), countT(127, 0);

        for (char c : t) {
            ++countT[c];
        }

        for (; left < size; ++left) {
            while (!(valid = check(countS, countT))) {
                if (right < size) {
                    ++countS[s[right++]];
                }
                else {
                    break;
                }
            }

            if (valid && right - left < minLen) {
                minLen = right - left;
                ans = string(s, left, minLen);
            }

            --countS[s[left]];
        }

        return ans;
    }

    bool check(vector<int>& countS, vector<int>& countT) {
        for (char c = 'a'; c <= 'z'; ++c) {
            if (countS[c] < countT[c]) {
                return false;
            }
        }

        for (char c = 'A'; c <= 'Z'; ++c) {
            if (countS[c] < countT[c]) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("BANC", o.minWindow("ADOBECODEBANC", "ABC"));
    check.checkString("a", o.minWindow("a", "a"));
    check.checkString("", o.minWindow("a", "aa"));
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
