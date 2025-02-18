/* 找出长度为 K 的特殊子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个整数 k。

判断是否存在一个长度 恰好 为 k 的子字符串，该子字符串需要满足以下条件：

该子字符串 只包含一个唯一字符（例如，"aaa" 或 "bbb"）。
如果该子字符串的 前面 有字符，则该字符必须与子字符串中的字符不同。
如果该子字符串的 后面 有字符，则该字符也必须与子字符串中的字符不同。
如果存在这样的子串，返回 true；否则，返回 false。

子字符串 是字符串中的连续、非空字符序列。



示例 1：

输入： s = "aaabaaa", k = 3

输出： true

解释：

子字符串 s[4..6] == "aaa" 满足条件：

长度为 3。
所有字符相同。
子串 "aaa" 前的字符是 'b'，与 'a' 不同。
子串 "aaa" 后没有字符。
示例 2：

输入： s = "abc", k = 2

输出： false

解释：

不存在长度为 2 、仅由一个唯一字符组成且满足所有条件的子字符串。



提示：

1 <= k <= s.length <= 100
s 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        vector<int> cnt(127, 0);
        int size = (int)s.size();

        for (int i = 0; i < size; ++i) {
            char c = s[i];
            ++cnt[c];
            if (i >= k) {
                --cnt[s[i - k]];
            }

            if ((cnt[c] == k)
                && (i == k - 1 || c != s[i - k])
                && (i == size - 1 || c != s[i + 1])) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.hasSpecialSubstring("aaabaaa", 3));
    check.checkBool(false, o.hasSpecialSubstring("abc", 2));
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
