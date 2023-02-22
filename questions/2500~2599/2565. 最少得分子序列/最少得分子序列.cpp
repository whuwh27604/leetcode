/* 最少得分子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 s 和 t 。

你可以从字符串 t 中删除任意数目的字符。

如果没有从字符串 t 中删除字符，那么得分为 0 ，否则：

令 left 为删除字符中的最小下标。
令 right 为删除字符中的最大下标。
字符串的得分为 right - left + 1 。

请你返回使 t 成为 s 子序列的最小得分。

一个字符串的 子序列 是从原字符串中删除一些字符后（也可以一个也不删除），剩余字符不改变顺序得到的字符串。（比方说 "ace" 是 "abcde" 的子序列，但是 "aec" 不是）。



示例 1：

输入：s = "abacaba", t = "bzaa"
输出：1
解释：这个例子中，我们删除下标 1 处的字符 "z" （下标从 0 开始）。
字符串 t 变为 "baa" ，它是字符串 "abacaba" 的子序列，得分为 1 - 1 + 1 = 1 。
1 是能得到的最小得分。
示例 2：

输入：s = "cde", t = "xyz"
输出：3
解释：这个例子中，我们将下标为 0， 1 和 2 处的字符 "x" ，"y" 和 "z" 删除（下标从 0 开始）。
字符串变成 "" ，它是字符串 "cde" 的子序列，得分为 2 - 0 + 1 = 3 。
3 是能得到的最小得分。


提示：

1 <= s.length, t.length <= 105
s 和 t 都只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumScore(string s, string t) {
        int sizeS = s.size(), sizeT = t.size(), low = 0, high = sizeT, minScore = sizeT;
        vector<int> lefts(sizeT, sizeS), rights(sizeT, -1);

        getLefts(s, t, lefts);
        getRights(s, t, rights);

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(lefts, rights, sizeS, sizeT, mid)) {
                high = mid - 1;
                minScore = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return minScore;
    }

    void getLefts(string& s, string& t, vector<int>& lefts) {
        int sizeS = s.size(), sizeT = t.size(), i = 0;

        for (int j = 0; j < sizeT; ++j) {
            for (; i < sizeS; ++i) {
                if (s[i] == t[j]) {
                    lefts[j] = i++;
                    break;
                }
            }
        }
    }

    void getRights(string& s, string& t, vector<int>& rights) {
        int sizeS = s.size(), sizeT = t.size(), i = sizeS - 1;

        for (int j = sizeT - 1; j >= 0; --j) {
            for (; i >= 0; --i) {
                if (s[i] == t[j]) {
                    rights[j] = i--;
                    break;
                }
            }
        }
    }

    bool check(vector<int>& lefts, vector<int>& rights, int sizeS, int sizeT, int score) {
        if (score == 0) {
            return rights[0] != -1;
        }

        if (score == sizeT || lefts[sizeT - score - 1] != sizeS || rights[score] != -1) {
            return true;
        }

        for (int i = 1; i < sizeT - score; ++i) {
            if (lefts[i - 1] < rights[i + score]) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.minimumScore("abacaba", "bzaa"));
    check.checkInt(3, o.minimumScore("cde", "xyz"));
    check.checkInt(1, o.minimumScore("a", "b"));
    check.checkInt(0, o.minimumScore("aaaa", "aaa"));
    check.checkInt(2, o.minimumScore("eeecaeecdeeadcdbcaa", "edecabe"));
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
