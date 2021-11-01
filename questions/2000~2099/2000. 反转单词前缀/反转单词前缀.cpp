/* 反转单词前缀.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 word 和一个字符 ch 。找出 ch 第一次出现的下标 i ，反转 word 中从下标 0 开始、直到下标 i 结束（含下标 i ）的那段字符。如果 word 中不存在字符 ch ，则无需进行任何操作。

例如，如果 word = "abcdefd" 且 ch = "d" ，那么你应该 反转 从下标 0 开始、直到下标 3 结束（含下标 3 ）。结果字符串将会是 "dcbaefd" 。
返回 结果字符串 。

 

示例 1：

输入：word = "abcdefd", ch = "d"
输出："dcbaefd"
解释："d" 第一次出现在下标 3 。
反转从下标 0 到下标 3（含下标 3）的这段字符，结果字符串是 "dcbaefd" 。
示例 2：

输入：word = "xyxzxe", ch = "z"
输出："zxyxxe"
解释："z" 第一次也是唯一一次出现是在下标 3 。
反转从下标 0 到下标 3（含下标 3）的这段字符，结果字符串是 "zxyxxe" 。
示例 3：

输入：word = "abcd", ch = "z"
输出："abcd"
解释："z" 不存在于 word 中。
无需执行反转操作，结果字符串是 "abcd" 。
 

提示：

1 <= word.length <= 250
word 由小写英文字母组成
ch 是一个小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-prefix-of-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = find(word, ch);
        if (index != word.size()) {
            reverse(word, index);
        }

        return word;
    }

    int find(string& word, char ch) {
        int i, size = word.size();

        for (i = 0; i < size && word[i] != ch; ++i) {}

        return i;
    }

    void reverse(string& word, int index) {
        for (int i = 0, j = index; i <= j; ++i, --j) {
            swap(word[i], word[j]);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("dcbaefd", o.reversePrefix("abcdefd", 'd'));
    check.checkString("zxyxxe", o.reversePrefix("xyxzxe", 'z'));
    check.checkString("abcd", o.reversePrefix("abcd", 'z'));
    check.checkString("abcd", o.reversePrefix("abcd", 'a'));
    check.checkString("dcba", o.reversePrefix("abcd", 'd'));
    check.checkString("d", o.reversePrefix("d", 'd'));
    check.checkString("a", o.reversePrefix("a", 'd'));
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
