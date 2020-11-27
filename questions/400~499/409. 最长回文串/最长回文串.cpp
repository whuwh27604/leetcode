/* 最长回文串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int alphabet[52] = { 0 };
        int length = 0;

        for (unsigned int i = 0; i < s.size(); i++) {
            int index = ((s[i] >= 'a') ? (s[i] - 'a' + 26) : (s[i] - 'A'));
            if (alphabet[index] == 1) {
                alphabet[index] = 0;
                length += 2;
            }
            else {
                alphabet[index] = 1;
            }
        }

        int addOne = 0;
        for (int j = 0; j < 52; j++) {
            if (alphabet[j] == 1) {
                addOne = 1;
                break;
            }
        }

        return (length + addOne);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string s = "abccccdd";
    check.checkInt(7, o.longestPalindrome(s));

    s = "";
    check.checkInt(0, o.longestPalindrome(s));

    s = "abbcccddddA";
    check.checkInt(9, o.longestPalindrome(s));

    s = "abbcccddddABBCCCDDDD";
    check.checkInt(17, o.longestPalindrome(s));
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
