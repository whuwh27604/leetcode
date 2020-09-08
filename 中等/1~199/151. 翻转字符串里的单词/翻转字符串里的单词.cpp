/* 翻转字符串里的单词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串，逐个翻转字符串中的每个单词。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

进阶：

请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int position = 0, start = 0;
        s.push_back(' ');

        while ((position = s.find(' ', position)) != s.npos) {
            if ((position - start) == 0) {
                start = ++position;
                continue;
            }

            string word(s, start, (position - start));
            ans = word + " " + ans;
            start = ++position;
        }

        if (!ans.empty()) {
            ans.pop_back();
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("", o.reverseWords(""));
    check.checkString("", o.reverseWords(" "));
    check.checkString("", o.reverseWords("  "));
    check.checkString("a", o.reverseWords("a"));
    check.checkString("a", o.reverseWords("  a   "));
    check.checkString("abc", o.reverseWords("abc"));
    check.checkString("abc", o.reverseWords(" abc "));
    check.checkString("example good a", o.reverseWords("a good   example"));
    check.checkString("world! hello", o.reverseWords("  hello world!  "));
    check.checkString("blue is sky the", o.reverseWords("the sky is blue"));
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
