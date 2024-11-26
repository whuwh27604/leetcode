/* 重排子字符串以形成目标字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 s 和 t（它们互为字母异位词），以及一个整数 k。

你的任务是判断是否可以将字符串 s 分割成 k 个等长的子字符串，然后重新排列这些子字符串，并以任意顺序连接它们，使得最终得到的新字符串与给定的字符串 t 相匹配。

如果可以做到，返回 true；否则，返回 false。

字母异位词 是指由另一个单词或短语的所有字母重新排列形成的单词或短语，使用所有原始字母恰好一次。

子字符串 是字符串中的一个连续 非空 字符序列。



示例 1：

输入： s = "abcd", t = "cdab", k = 2

输出： true

解释：

将 s 分割成 2 个长度为 2 的子字符串：["ab", "cd"]。
重新排列这些子字符串为 ["cd", "ab"]，然后连接它们得到 "cdab"，与 t 相匹配。
示例 2：

输入： s = "aabbcc", t = "bbaacc", k = 3

输出： true

解释：

将 s 分割成 3 个长度为 2 的子字符串：["aa", "bb", "cc"]。
重新排列这些子字符串为 ["bb", "aa", "cc"]，然后连接它们得到 "bbaacc"，与 t 相匹配。
示例 3：

输入： s = "aabbcc", t = "bbaacc", k = 2

输出： false

解释：

将 s 分割成 2 个长度为 3 的子字符串：["aab", "bcc"]。
这些子字符串无法重新排列形成 t = "bbaacc"，所以输出 false。


提示：

1 <= s.length == t.length <= 2 * 105
1 <= k <= s.length
s.length 能被 k 整除。
s 和 t 仅由小写英文字母组成。
输入保证 s 和 t 互为字母异位词。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int size = (int)s.size(), len = size / k;
        unordered_map<string, int> subs;

        for (int i = 0; i < size; i += len) {
            ++subs[string(s, i, len)];
        }

        for (int i = 0; i < size; i += len) {
            string sub(t, i, len);

            if (--subs[sub] == -1) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.isPossibleToRearrange("abcd", "cdab", 2));
    check.checkBool(true, o.isPossibleToRearrange("aabbcc", "bbaacc", 3));
    check.checkBool(false, o.isPossibleToRearrange("aabbcc", "bbaacc", 2));
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
