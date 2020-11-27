/* 找不同.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。

 

示例:

输入：
s = "abcd"
t = "abcde"

输出：
e

解释：
'e' 是那个被添加的字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int charCount[(int)'z' + 1] = { 0 };

        for (unsigned int i = 0; i < s.size(); i++) {
            charCount[(int)(s[i])]++;
        }

        for (unsigned int i = 0; i < t.size(); i++) {
            if (charCount[(int)(t[i])] == 0) {
                return t[i];
            }
            charCount[(int)(t[i])]--;
        }

        return 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string s = "abcd";
    string t = "abcde";
    check.checkChar('e', o.findTheDifference(s, t));

    s = "";
    t = "z";
    check.checkChar('z', o.findTheDifference(s, t));

    s = "aaabbbccc";
    t = "aaabbbbccc";
    check.checkChar('b', o.findTheDifference(s, t));

    s = "aaabbbccc";
    t = "cababcbabc";
    check.checkChar('b', o.findTheDifference(s, t));
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
