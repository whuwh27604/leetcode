/* 可以输入的最大单词数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
键盘出现了一些故障，有些字母键无法正常工作。而键盘上所有其他键都能够正常工作。

给你一个由若干单词组成的字符串 text ，单词间由单个空格组成（不含前导和尾随空格）；另有一个字符串 brokenLetters ，由所有已损坏的不同字母键组成，返回你可以使用此键盘完全输入的 text 中单词的数目。

 

示例 1：

输入：text = "hello world", brokenLetters = "ad"
输出：1
解释：无法输入 "world" ，因为字母键 'd' 已损坏。
示例 2：

输入：text = "leet code", brokenLetters = "lt"
输出：1
解释：无法输入 "leet" ，因为字母键 'l' 和 't' 已损坏。
示例 3：

输入：text = "leet code", brokenLetters = "e"
输出：0
解释：无法输入任何单词，因为字母键 'e' 已损坏。
 

提示：

1 <= text.length <= 104
0 <= brokenLetters.length <= 26
text 由若干用单个空格分隔的单词组成，且不含任何前导和尾随空格
每个单词仅由小写英文字母组成
brokenLetters 由 互不相同 的小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-words-you-can-type
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int words = 0, count = 1;
        vector<bool> isBroken('z' + 1, false);

        for (char c : brokenLetters) {
            isBroken[c] = true;
        }

        for (char c : text) {
            if (c == ' ') {
                words += count;
                count = 1;
            }
            else if (isBroken[c]) {
                count = 0;
            }
        }

        return words + count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.canBeTypedWords("hello world", "ad"));
    check.checkInt(2, o.canBeTypedWords("hello world", ""));
    check.checkInt(1, o.canBeTypedWords("leet code", "lt"));
    check.checkInt(0, o.canBeTypedWords("leet code", "e"));
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
