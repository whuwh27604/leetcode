/* 字符串的最大公因子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

 

示例 1：

输入：str1 = "ABCABC", str2 = "ABC"
输出："ABC"
示例 2：

输入：str1 = "ABABAB", str2 = "ABAB"
输出："AB"
示例 3：

输入：str1 = "LEET", str2 = "CODE"
输出：""
 

提示：

1 <= str1.length <= 1000
1 <= str2.length <= 1000
str1[i] 和 str2[i] 为大写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/greatest-common-divisor-of-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string s1s2 = str1 + str2;
        string s2s1 = str2 + str1;
        if (s1s2 != s2s1) {
            return "";
        }

        int len1 = str1.size(), len2 = str2.size();
        int len = gcd(len1, len2);
        string gcdString(str1, 0, len);
        return gcdString;
    }

    int gcd(int x, int y) {
        return (x == 0) ? y : gcd(y % x, x);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("ABC", o.gcdOfStrings("ABCABC", "ABC"));
    check.checkString("AB", o.gcdOfStrings("ABABAB", "ABAB"));
    check.checkString("", o.gcdOfStrings("LEET", "CODE"));
    check.checkString("A", o.gcdOfStrings("A", "A"));
    check.checkString("", o.gcdOfStrings("A", "B"));
    check.checkString("A", o.gcdOfStrings("AAA", "AA"));
    check.checkString("AA", o.gcdOfStrings("AAAAAAAA", "AAAAAA"));
    check.checkString("AAAAAAAA", o.gcdOfStrings("AAAAAAAA", "AAAAAAAA"));
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
