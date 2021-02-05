/* 最小覆盖子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"
 

提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成
 

进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> lettersT('z' + 1, 0), lettersS('z' + 1, 0);
        countT(t, lettersT);

        int left = 0, right, size = s.size(), targetLeft = -1, minimumWindow = INT_MAX;
        int typesT = countTypes(lettersT), nolessTypes = 0;

        for (right = 0; right < size; ++right) {
            if (++lettersS[s[right]] == lettersT[s[right]]) {
                ++nolessTypes;
            }

            if (nolessTypes < typesT) {
                continue;
            }

            while (lettersS[s[left]] > lettersT[s[left]]) {
                --lettersS[s[left++]];
            }

            if (right - left + 1 < minimumWindow) {
                minimumWindow = right - left + 1;
                targetLeft = left;
            }
        }

        if (targetLeft == -1) {
            return "";
        }

        return string(s, targetLeft, minimumWindow);
    }

    void countT(string& t, vector<int>& lettersT) {
        for (char c : t) {
            ++lettersT[c];
        }
    }

    int countTypes(vector<int>& letters) {
        int types = 0;

        for (int i = 'A'; i <= 'z'; ++i) {
            if (letters[i] != 0) {
                ++types;
            }
        }

        return types;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("", o.minWindow("AAA", "a"));
    check.checkString("", o.minWindow("a", "b"));
    check.checkString("a", o.minWindow("a", "a"));
    check.checkString("aa", o.minWindow("aa", "aa"));
    check.checkString("a", o.minWindow("ab", "a"));
    check.checkString("BANC", o.minWindow("ADOBECODEBANC", "ABC"));
    check.checkString("cdcdza", o.minWindow("cdcdza", "cdcdza"));
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
