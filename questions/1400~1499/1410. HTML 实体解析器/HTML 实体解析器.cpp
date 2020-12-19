/* HTML 实体解析器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「HTML 实体解析器」 是一种特殊的解析器，它将 HTML 代码作为输入，并用字符本身替换掉所有这些特殊的字符实体。

HTML 里这些特殊字符和它们对应的字符实体包括：

双引号：字符实体为 &quot; ，对应的字符是 " 。
单引号：字符实体为 &apos; ，对应的字符是 ' 。
与符号：字符实体为 &amp; ，对应对的字符是 & 。
大于号：字符实体为 &gt; ，对应的字符是 > 。
小于号：字符实体为 &lt; ，对应的字符是 < 。
斜线号：字符实体为 &frasl; ，对应的字符是 / 。
给你输入字符串 text ，请你实现一个 HTML 实体解析器，返回解析器解析后的结果。

 

示例 1：

输入：text = "&amp; is an HTML entity but &ambassador; is not."
输出："& is an HTML entity but &ambassador; is not."
解释：解析器把字符实体 &amp; 用 & 替换
示例 2：

输入：text = "and I quote: &quot;...&quot;"
输出："and I quote: \"...\""
示例 3：

输入：text = "Stay home! Practice on Leetcode :)"
输出："Stay home! Practice on Leetcode :)"
示例 4：

输入：text = "x &gt; y &amp;&amp; x &lt; y is always false"
输出："x > y && x < y is always false"
示例 5：

输入：text = "leetcode.com&frasl;problemset&frasl;all"
输出："leetcode.com/problemset/all"
 

提示：

1 <= text.length <= 10^5
字符串可能包含 256 个ASCII 字符中的任意字符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/html-entity-parser
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string entityParser(string text) {
        string ans;
        int i, size = text.size();
        text += '.';

        for (i = 0; i < size; ++i) {
            if (text[i] != '&') {
                ans += text[i];
                continue;
            }

            if (text[i + 1] == 'q' && text[i + 2] == 'u' && text[i + 3] == 'o' && text[i + 4] == 't' && text[i + 5] == ';') {
                ans += '\"';
                i += 5;
            }
            else if (text[i + 1] == 'a' && text[i + 2] == 'p' && text[i + 3] == 'o' && text[i + 4] == 's' && text[i + 5] == ';') {
                ans += '\'';
                i += 5;
            }
            else if (text[i + 1] == 'a' && text[i + 2] == 'm' && text[i + 3] == 'p' && text[i + 4] == ';') {
                ans += '&';
                i += 4;
            }
            else if (text[i + 1] == 'g' && text[i + 2] == 't' && text[i + 3] == ';') {
                ans += '>';
                i += 3;
            }
            else if (text[i + 1] == 'l' && text[i + 2] == 't' && text[i + 3] == ';') {
                ans += '<';
                i += 3;
            }
            else if (text[i + 1] == 'f' && text[i + 2] == 'r' && text[i + 3] == 'a' && text[i + 4] == 's' && text[i + 5] == 'l' && text[i + 6] == ';') {
                ans += '/';
                i += 6;
            }
            else {
                ans += '&';
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("& is an HTML entity but &ambassador; is not.", o.entityParser("&amp; is an HTML entity but &ambassador; is not."));
    check.checkString("and I quote: \"...\"", o.entityParser("and I quote: &quot;...&quot;"));
    check.checkString("Stay home! Practice on Leetcode :)", o.entityParser("Stay home! Practice on Leetcode :)"));
    check.checkString("x > y && x < y is always false", o.entityParser("x &gt; y &amp;&amp; x &lt; y is always false"));
    check.checkString("leetcode.com/problemset/all", o.entityParser("leetcode.com&frasl;problemset&frasl;all"));
    check.checkString("and I quote: '...'", o.entityParser("and I quote: &apos;...&apos;"));
    check.checkString("&", o.entityParser("&"));
    check.checkString("a", o.entityParser("a"));
    check.checkString("&gt;", o.entityParser("&amp;gt;"));
    check.checkString("<''&", o.entityParser("&lt;&apos;&apos;&amp;"));
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
