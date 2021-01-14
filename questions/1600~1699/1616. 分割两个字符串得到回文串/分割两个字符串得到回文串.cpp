/* 分割两个字符串得到回文串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 a 和 b ，它们长度相同。请你选择一个下标，将两个字符串都在 相同的下标 分割开。由 a 可以得到两个字符串： aprefix 和 asuffix ，满足 a = aprefix + asuffix ，同理，由 b 可以得到两个字符串 bprefix 和 bsuffix ，满足 b = bprefix + bsuffix 。请你判断 aprefix + bsuffix 或者 bprefix + asuffix 能否构成回文串。

当你将一个字符串 s 分割成 sprefix 和 ssuffix 时， ssuffix 或者 sprefix 可以为空。比方说， s = "abc" 那么 "" + "abc" ， "a" + "bc" ， "ab" + "c" 和 "abc" + "" 都是合法分割。

如果 能构成回文字符串 ，那么请返回 true，否则返回 false 。

注意， x + y 表示连接字符串 x 和 y 。

 

示例 1：

输入：a = "x", b = "y"
输出：true
解释：如果 a 或者 b 是回文串，那么答案一定为 true ，因为你可以如下分割：
aprefix = "", asuffix = "x"
bprefix = "", bsuffix = "y"
那么 aprefix + bsuffix = "" + "y" = "y" 是回文串。
示例 2：

输入：a = "abdef", b = "fecab"
输出：true
示例 3：

输入：a = "ulacfd", b = "jizalu"
输出：true
解释：在下标为 3 处分割：
aprefix = "ula", asuffix = "cfd"
bprefix = "jiz", bsuffix = "alu"
那么 aprefix + bsuffix = "ula" + "alu" = "ulaalu" 是回文串。
示例 4：

输入：a = "xbdef", b = "xecab"
输出：false
 

提示：

1 <= a.length, b.length <= 105
a.length == b.length
a 和 b 都只包含小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-two-strings-to-make-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return checkPalindrome(a, b) || checkPalindrome(b, a);
    }

    bool checkPalindrome(string& a, string& b) {
        int i, j, tmpi, tmpj, size = a.size();

        for (i = 0, j = size - 1; i < j && a[i] == b[j]; ++i, --j) {}
        tmpi = i, tmpj = j;

        for (; i < j && a[i] == a[j]; ++i, --j) {}
        if (i >= j) {
            return true;
        }

        for (; tmpi < tmpj && b[tmpi] == b[tmpj]; ++tmpi, --tmpj) {}        
        return tmpi >= tmpj;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.checkPalindromeFormation("a", "b"));
    check.checkBool(true, o.checkPalindromeFormation("abdef", "fecab"));
    check.checkBool(true, o.checkPalindromeFormation("ulacfd", "jizalu"));
    check.checkBool(false, o.checkPalindromeFormation("xbdef", "xecab"));
    check.checkBool(true, o.checkPalindromeFormation("aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd", "uvebspqckawkhbrtlqwblfwzfptanhiglaabjea"));
    check.checkBool(true, o.checkPalindromeFormation("uvebspqckawkhbrtlqwblfwzfptanhiglaabjea", "aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd"));
    check.checkBool(true, o.checkPalindromeFormation("pvhmupgqeltozftlmfjjde", "yjgpzbezspnnpszebzmhvp"));
    check.checkBool(true, o.checkPalindromeFormation("askxrrnhyddrlmcgymtichivmwyjfpyqqxmiimxqqypfjywmvihcitmygcmlryczoygimgii", "iigmigyozcyfxgfzkwpvjuxbjphbbmwlhdcavhtjhbpccsxaaiyitfbzljvhjoytfqlqrohv"));
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
