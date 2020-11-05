/* 实现 strStr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLen = haystack.size();
        int needleLen = needle.size();
        int current = 0;

        if (needleLen == 0) {
            return 0;
        }

        if (haystackLen < needleLen) {
            return -1;
        }

        while (current <= (haystackLen - needleLen)) {
            if (haystack[current] == needle[0]) {
                if (compare(&haystack[current], &needle[0], needleLen)) {
                    return current;
                }
            }
            current++;
        }
        return -1;
    }

    bool compare(char* s1, char* s2, int len) {
        for (int i = 0; i < len; i++) {
            if (s1[i] != s2[i]) {
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

    string haystack = "hello";
    string needle = "ll";
    check.checkInt(2, o.strStr(haystack, needle));

    haystack = "aaaaa";
    needle = "bba";
    check.checkInt(-1, o.strStr(haystack, needle));

    haystack = "aaaaa";
    needle = "";
    check.checkInt(0, o.strStr(haystack, needle));

    haystack = "aaaaa";
    needle = "bbaaa";
    check.checkInt(-1, o.strStr(haystack, needle));

    haystack = "aaaaa";
    needle = "aaaaa";
    check.checkInt(0, o.strStr(haystack, needle));

    haystack = "aaaaabcd";
    needle = "abcd";
    check.checkInt(4, o.strStr(haystack, needle));
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
