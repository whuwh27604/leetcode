/* 重排字符形成目标字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的字符串 s 和 target 。你可以从 s 取出一些字符并将其重排，得到若干新的字符串。

从 s 中取出字符并重新排列，返回可以形成 target 的 最大 副本数。

 

示例 1：

输入：s = "ilovecodingonleetcode", target = "code"
输出：2
解释：
对于 "code" 的第 1 个副本，选取下标为 4 、5 、6 和 7 的字符。
对于 "code" 的第 2 个副本，选取下标为 17 、18 、19 和 20 的字符。
形成的字符串分别是 "ecod" 和 "code" ，都可以重排为 "code" 。
可以形成最多 2 个 "code" 的副本，所以返回 2 。
示例 2：

输入：s = "abcba", target = "abc"
输出：1
解释：
选取下标为 0 、1 和 2 的字符，可以形成 "abc" 的 1 个副本。
可以形成最多 1 个 "abc" 的副本，所以返回 1 。
注意，尽管下标 3 和 4 分别有额外的 'a' 和 'b' ，但不能重用下标 2 处的 'c' ，所以无法形成 "abc" 的第 2 个副本。
示例 3：

输入：s = "abbaccaddaeea", target = "aaaaa"
输出：1
解释：
选取下标为 0 、3 、6 、9 和 12 的字符，可以形成 "aaaaa" 的 1 个副本。
可以形成最多 1 个 "aaaaa" 的副本，所以返回 1 。
 

提示：

1 <= s.length <= 100
1 <= target.length <= 10
s 和 target 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/rearrange-characters-to-make-target-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int countS[26] = { 0 }, countT[26] = { 0 };
        int copies = INT_MAX;

        for (char c : s) {
            ++countS[c - 'a'];
        }

        for (char c : target) {
            ++countT[c - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (countT[i] != 0) {
                copies = min(copies, countS[i] / countT[i]);
            }
        }

        return copies;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.rearrangeCharacters("ilovecodingonleetcode", "code"));
    check.checkInt(1, o.rearrangeCharacters("abcba", "abc"));
    check.checkInt(1, o.rearrangeCharacters("abbaccaddaeea", "aaaaa"));
    check.checkInt(0, o.rearrangeCharacters("a", "b"));
    check.checkInt(5, o.rearrangeCharacters("aaaaa", "a"));
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
