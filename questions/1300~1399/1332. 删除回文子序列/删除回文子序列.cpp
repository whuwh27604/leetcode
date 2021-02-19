/* 删除回文子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s，它仅由字母 'a' 和 'b' 组成。每一次删除操作都可以从 s 中删除一个回文 子序列。

返回删除给定字符串中所有字符（字符串为空）的最小删除次数。

「子序列」定义：如果一个字符串可以通过删除原字符串某些字符而不改变原字符顺序得到，那么这个字符串就是原字符串的一个子序列。

「回文」定义：如果一个字符串向后和向前读是一致的，那么这个字符串就是一个回文。

 

示例 1：

输入：s = "ababa"
输出：1
解释：字符串本身就是回文序列，只需要删除一次。
示例 2：

输入：s = "abb"
输出：2
解释："abb" -> "bb" -> "".
先删除回文子序列 "a"，然后再删除 "bb"。
示例 3：

输入：s = "baabb"
输出：2
解释："baabb" -> "b" -> "".
先删除回文子序列 "baab"，然后再删除 "b"。
示例 4：

输入：s = ""
输出：0
 

提示：

0 <= s.length <= 1000
s 仅包含字母 'a'  和 'b'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-palindromic-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        int i, len = s.size();
        if (len == 0) {
            return 0;
        }

        for (i = 0; i < len / 2; i++) {
            if (s[i] != s[len - 1 - i]) {
                return 2;
            }
        }

        return 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.removePalindromeSub(""));
    check.checkInt(1, o.removePalindromeSub("ababa"));
    check.checkInt(2, o.removePalindromeSub("abb"));
    check.checkInt(2, o.removePalindromeSub("baabb"));
    check.checkInt(1, o.removePalindromeSub("a"));
    check.checkInt(2, o.removePalindromeSub("ab"));
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
