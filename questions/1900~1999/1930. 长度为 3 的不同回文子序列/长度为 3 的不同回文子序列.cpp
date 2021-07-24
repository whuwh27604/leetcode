/* 长度为 3 的不同回文子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，返回 s 中 长度为 3 的不同回文子序列 的个数。

即便存在多种方法来构建相同的子序列，但相同的子序列只计数一次。

回文 是正着读和反着读一样的字符串。

子序列 是由原字符串删除其中部分字符（也可以不删除）且不改变剩余字符之间相对顺序形成的一个新字符串。

例如，"ace" 是 "abcde" 的一个子序列。
 

示例 1：

输入：s = "aabca"
输出：3
解释：长度为 3 的 3 个回文子序列分别是：
- "aba" ("aabca" 的子序列)
- "aaa" ("aabca" 的子序列)
- "aca" ("aabca" 的子序列)
示例 2：

输入：s = "adc"
输出：0
解释："adc" 不存在长度为 3 的回文子序列。
示例 3：

输入：s = "bbcbaba"
输出：4
解释：长度为 3 的 4 个回文子序列分别是：
- "bbb" ("bbcbaba" 的子序列)
- "bcb" ("bbcbaba" 的子序列)
- "bab" ("bbcbaba" 的子序列)
- "aba" ("bbcbaba" 的子序列)
 

提示：

3 <= s.length <= 105
s 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-length-3-palindromic-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int num = 0;

        for (char c = 'a'; c <= 'z'; ++c) {
            num += count(s, c);
        }

        return num;
    }

    int count(string& s, char c) {
        int i, j, k, size = s.size(), num = 0;
        vector<bool> exist('z' + 1, false);

        for (i = 0; i < size && s[i] != c; ++i) {}
        for (j = size - 1; j >= 0 && s[j] != c; --j) {}

        for (k = i + 1; k < j; ++k) {
            exist[s[k]] = true;
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            if (exist[c]) {
                ++num;
            }
        }

        return num;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.countPalindromicSubsequence("aabca"));
    check.checkInt(0, o.countPalindromicSubsequence("adc"));
    check.checkInt(4, o.countPalindromicSubsequence("bbcbaba"));
    check.checkInt(1, o.countPalindromicSubsequence("aaaaaaaaaaaaaa"));
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
