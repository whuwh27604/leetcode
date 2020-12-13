/* 反转字符串 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 

示例:

输入: s = "abcdefg", k = 2
输出: "bacdfeg"
 

提示：

该字符串只包含小写英文字母。
给定字符串的长度和 k 在 [1, 10000] 范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-string-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        bool needReverse = true;
        int leftLen = s.size();
        auto iter = s.begin();

        while (leftLen >= k) {
            if (needReverse) {
                reverse(iter, (iter + k));
            }

            needReverse = !needReverse;
            leftLen -= k;
            iter += k;
        }

        if ((leftLen != 0) && needReverse) {
            reverse(iter, s.end());
        }

        return s;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("bacdfeg", o.reverseStr("abcdefg", 2));
    check.checkString("a", o.reverseStr("a", 1));
    check.checkString("abc", o.reverseStr("abc", 1));
    check.checkString("a", o.reverseStr("a", 2));
    check.checkString("ba", o.reverseStr("ab", 2));
    check.checkString("baa", o.reverseStr("aba", 2));
    check.checkString("baab", o.reverseStr("abab", 2));
    check.checkString("baaba", o.reverseStr("ababa", 2));
    check.checkString("baabba", o.reverseStr("ababab", 2));
    check.checkString("baabbaa", o.reverseStr("abababa", 2));
    check.checkString("baabbaab", o.reverseStr("abababab", 2));
    check.checkString("cba", o.reverseStr("abc", 3));
    check.checkString("cbaabcba", o.reverseStr("abcabcab", 3));
    check.checkString("cbaabccba", o.reverseStr("abcabcabc", 3));
    check.checkString("cbaabccbad", o.reverseStr("abcabcabcd", 3));
    check.checkString("cbaabccbade", o.reverseStr("abcabcabcde", 3));
    check.checkString("cbaabccbadef", o.reverseStr("abcabcabcdef", 3));
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
