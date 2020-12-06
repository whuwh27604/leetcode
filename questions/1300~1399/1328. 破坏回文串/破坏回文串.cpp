/* 破坏回文串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个回文字符串 palindrome ，请你将其中 一个 字符用任意小写英文字母替换，使得结果字符串的字典序最小，且 不是 回文串。

请你返回结果字符串。如果无法做到，则返回一个空串。

 

示例 1：

输入：palindrome = "abccba"
输出："aaccba"
示例 2：

输入：palindrome = "a"
输出：""
 

提示：

1 <= palindrome.length <= 1000
palindrome 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/break-a-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        /* 1、a --> ""
           2、aaabbaaa --> aaaabaaa
           3、aaabaaa --> aaabaab 
           4、aaaaaa --> aaaaab
           5、baaab --> aaaab */
        int firstNonA, size = palindrome.size() / 2;

        if (size == 0) {
            return "";
        }

        for (firstNonA = 0; firstNonA < size && palindrome[firstNonA] == 'a'; ++firstNonA) {}

        if (firstNonA == size) {
            palindrome.back() = 'b';
        }
        else {
            palindrome[firstNonA] = 'a';
        }

        return palindrome;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("", o.breakPalindrome("a"));
    check.checkString("", o.breakPalindrome("z"));
    check.checkString("aaaabaaa", o.breakPalindrome("aaabbaaa"));
    check.checkString("aaabaab", o.breakPalindrome("aaabaaa"));
    check.checkString("aaaaab", o.breakPalindrome("aaaaaa"));
    check.checkString("aaaab", o.breakPalindrome("baaab"));
    check.checkString("aaccba", o.breakPalindrome("abccba"));
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
