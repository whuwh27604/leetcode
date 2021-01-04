/* K 次操作转变字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 s 和 t ，你的目标是在 k 次操作以内把字符串 s 转变成 t 。

在第 i 次操作时（1 <= i <= k），你可以选择进行如下操作：

选择字符串 s 中满足 1 <= j <= s.length 且之前未被选过的任意下标 j （下标从 1 开始），并将此位置的字符切换 i 次。
不进行任何操作。
切换 1 次字符的意思是用字母表中该字母的下一个字母替换它（字母表环状接起来，所以 'z' 切换后会变成 'a'）。

请记住任意一个下标 j 最多只能被操作 1 次。

如果在不超过 k 次操作内可以把字符串 s 转变成 t ，那么请你返回 true ，否则请你返回 false 。

 

示例 1：

输入：s = "input", t = "ouput", k = 9
输出：true
解释：第 6 次操作时，我们将 'i' 切换 6 次得到 'o' 。第 7 次操作时，我们将 'n' 切换 7 次得到 'u' 。
示例 2：

输入：s = "abc", t = "bcd", k = 10
输出：false
解释：我们需要将每个字符切换 1 次才能得到 t 。我们可以在第 1 次操作时将 'a' 切换成 'b' ，但另外 2 个字母在剩余操作中无法再转变为 t 中对应字母。
示例 3：

输入：s = "aab", t = "bbb", k = 27
输出：true
解释：第 1 次操作时，我们将第一个 'a' 切换 1 次得到 'b' 。在第 27 次操作时，我们将第二个字母 'a' 切换 27 次得到 'b' 。
 

提示：

1 <= s.length, t.length <= 10^5
0 <= k <= 10^9
s 和 t 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/can-convert-string-in-k-moves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> shiftingTimesCount(26, 0);
        int i, size = s.size();

        for (i = 0; i < size; ++i) {
            ++shiftingTimesCount[(t[i] + 26 - s[i]) % 26];
        }

        for (i = 1; i < 26; ++i) {
            if ((shiftingTimesCount[i] - 1) * 26 + i > k) {
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

    check.checkBool(true, o.canConvertString("input", "ouput", 9));
    check.checkBool(false, o.canConvertString("abc", "bcd", 10));
    check.checkBool(true, o.canConvertString("aab", "bbb", 27));
    check.checkBool(false, o.canConvertString("input", "output", 900));
    check.checkBool(true, o.canConvertString("a", "a", 0));
    check.checkBool(false, o.canConvertString("a", "b", 0));
    check.checkBool(false, o.canConvertString("aaaaa", "bbbbb", 104));
    check.checkBool(true, o.canConvertString("aaaaa", "bbbbb", 105));
    check.checkBool(false, o.canConvertString("ccccc", "aaaaa", 127));
    check.checkBool(true, o.canConvertString("ccccc", "aaaaa", 128));
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
