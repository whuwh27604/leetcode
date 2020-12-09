/* 制造字母异位词的最小步骤数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度相等的字符串 s 和 t。每一个步骤中，你可以选择将 t 中的 任一字符 替换为 另一个字符。

返回使 t 成为 s 的字母异位词的最小步骤数。

字母异位词 指字母相同，但排列不同（也可能相同）的字符串。

 

示例 1：

输出：s = "bab", t = "aba"
输出：1
提示：用 'b' 替换 t 中的第一个 'a'，t = "bba" 是 s 的一个字母异位词。
示例 2：

输出：s = "leetcode", t = "practice"
输出：5
提示：用合适的字符替换 t 中的 'p', 'r', 'a', 'i' 和 'c'，使 t 变成 s 的字母异位词。
示例 3：

输出：s = "anagram", t = "mangaar"
输出：0
提示："anagram" 和 "mangaar" 本身就是一组字母异位词。
示例 4：

输出：s = "xxyyzz", t = "xxyyzz"
输出：0
示例 5：

输出：s = "friend", t = "family"
输出：4
 

提示：

1 <= s.length <= 50000
s.length == t.length
s 和 t 只包含小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-steps-to-make-two-strings-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sCount('z' + 1, 0), tCount('z' + 1, 0);
        int steps = 0;

        for (char c : s) {
            ++sCount[c];
        }

        for (char c : t) {
            ++tCount[c];
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            if (tCount[c] > sCount[c]) {
                steps += (tCount[c] - sCount[c]);
            }
        }

        return steps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.minSteps("bab", "aba"));
    check.checkInt(5, o.minSteps("leetcode", "practice"));
    check.checkInt(0, o.minSteps("anagram", "mangaar"));
    check.checkInt(0, o.minSteps("xxyyzz", "xxyyzz"));
    check.checkInt(4, o.minSteps("friend", "family"));
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
