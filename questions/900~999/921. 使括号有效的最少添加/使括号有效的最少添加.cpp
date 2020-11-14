/* 使括号有效的最少添加.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个由 '(' 和 ')' 括号组成的字符串 S，我们需要添加最少的括号（ '(' 或是 ')'，可以在任何位置），以使得到的括号字符串有效。

从形式上讲，只有满足下面几点之一，括号字符串才是有效的：

它是一个空字符串，或者
它可以被写成 AB （A 与 B 连接）, 其中 A 和 B 都是有效字符串，或者
它可以被写作 (A)，其中 A 是有效字符串。
给定一个括号字符串，返回为使结果字符串有效而必须添加的最少括号数。

 

示例 1：

输入："())"
输出：1
示例 2：

输入："((("
输出：3
示例 3：

输入："()"
输出：0
示例 4：

输入："()))(("
输出：4
 

提示：

S.length <= 1000
S 只包含 '(' 和 ')' 字符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0, adding = 0;

        for (char c : S) {
            if (c == '(') {
                ++left;
            }
            else {
                if (left > 0) {
                    --left;
                }
                else {
                    ++adding;
                }
            }
        }

        return adding + left;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.minAddToMakeValid("())"));
    check.checkInt(3, o.minAddToMakeValid("((("));
    check.checkInt(0, o.minAddToMakeValid("()"));
    check.checkInt(4, o.minAddToMakeValid("()))(("));
    check.checkInt(0, o.minAddToMakeValid(""));
    check.checkInt(1, o.minAddToMakeValid("("));
    check.checkInt(1, o.minAddToMakeValid(")"));
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
