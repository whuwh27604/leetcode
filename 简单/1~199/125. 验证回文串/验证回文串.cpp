/* 验证回文串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (auto iter = s.begin(); iter < s.end();) {
            if (!isValidChar(*iter)) {
                iter = s.erase(iter);
            }
            else {
                *iter = tolower(*iter);
                iter++;
            }
        }

        int len = s.size();
        for (int i = 0; i < (len / 2); i++) {
            if (s[i] != s[len - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    bool isValidChar(char c) {
        return (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string s = "A man, a plan, a canal: Panama";
    check.checkBool(true, o.isPalindrome(s));

    s = "race a car";
    check.checkBool(false, o.isPalindrome(s));

    s = "";
    check.checkBool(true, o.isPalindrome(s));

    s = "a";
    check.checkBool(true, o.isPalindrome(s));

    s = "]]]a]]]]";
    check.checkBool(true, o.isPalindrome(s));

    s = "aba";
    check.checkBool(true, o.isPalindrome(s));

    s = "]a]]B]]]c]]]]d]]]]]C]]]]]b]]]]]A]]]]]]]]";
    check.checkBool(true, o.isPalindrome(s));
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
