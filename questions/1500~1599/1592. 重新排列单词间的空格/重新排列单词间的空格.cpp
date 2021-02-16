/* 重新排列单词间的空格.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 text ，该字符串由若干被空格包围的单词组成。每个单词由一个或者多个小写英文字母组成，并且两个单词之间至少存在一个空格。题目测试用例保证 text 至少包含一个单词 。

请你重新排列空格，使每对相邻单词之间的空格数目都 相等 ，并尽可能 最大化 该数目。如果不能重新平均分配所有空格，请 将多余的空格放置在字符串末尾 ，这也意味着返回的字符串应当与原 text 字符串的长度相等。

返回 重新排列空格后的字符串 。

 

示例 1：

输入：text = "  this   is  a sentence "
输出："this   is   a   sentence"
解释：总共有 9 个空格和 4 个单词。可以将 9 个空格平均分配到相邻单词之间，相邻单词间空格数为：9 / (4-1) = 3 个。
示例 2：

输入：text = " practice   makes   perfect"
输出："practice   makes   perfect "
解释：总共有 7 个空格和 3 个单词。7 / (3-1) = 3 个空格加上 1 个多余的空格。多余的空格需要放在字符串的末尾。
示例 3：

输入：text = "hello   world"
输出："hello   world"
示例 4：

输入：text = "  walks  udp package   into  bar a"
输出："walks  udp  package  into  bar  a "
示例 5：

输入：text = "a"
输出："a"
 

提示：

1 <= text.length <= 100
text 由小写英文字母和 ' ' 组成
text 中至少包含一个单词

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rearrange-spaces-between-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int words = 0, spaces = 0;
        count(text, words, spaces);

        int average = words == 1 ? 0 : spaces / (words - 1), last = words == 1 ? spaces : spaces % (words - 1), index = 1;
        string reordered;
        char prev = ' ';

        for (char c : text) {
            if (c == ' ') {
                if (prev != ' ' && index != words) {
                    reordered += string(average, ' ');
                    ++index;
                }
            }
            else {
                reordered += c;
            }

            prev = c;
        }

        reordered += string(last, ' ');
        return reordered;
    }

    void count(string& text, int& words, int& spaces) {
        char prev = ' ';

        for (char c : text) {
            if (c == ' ') {
                ++spaces;
            }
            else {
                if (prev == ' ') {
                    ++words;
                }
            }

            prev = c;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("this   is   a   sentence", o.reorderSpaces("  this   is  a sentence "));
    check.checkString("practice   makes   perfect ", o.reorderSpaces(" practice   makes   perfect"));
    check.checkString("hello   world", o.reorderSpaces("hello   world"));
    check.checkString("hello      world", o.reorderSpaces(" hello   world  "));
    check.checkString("walks  udp  package  into  bar  a ", o.reorderSpaces("  walks  udp package   into  bar a"));
    check.checkString("a", o.reorderSpaces("a"));
    check.checkString("a  ", o.reorderSpaces(" a "));
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
