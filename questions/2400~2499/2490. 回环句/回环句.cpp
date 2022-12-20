/* 回环句.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
句子 是由单个空格分隔的一组单词，且不含前导或尾随空格。

例如，"Hello World"、"HELLO"、"hello world hello world" 都是符合要求的句子。
单词 仅 由大写和小写英文字母组成。且大写和小写字母会视作不同字符。

如果句子满足下述全部条件，则认为它是一个 回环句 ：

单词的最后一个字符和下一个单词的第一个字符相等。
最后一个单词的最后一个字符和第一个单词的第一个字符相等。
例如，"leetcode exercises sound delightful"、"eetcode"、"leetcode eats soul" 都是回环句。然而，"Leetcode is cool"、"happy Leetcode"、"Leetcode" 和 "I like Leetcode" 都 不 是回环句。

给你一个字符串 sentence ，请你判断它是不是一个回环句。如果是，返回 true ；否则，返回 false 。



示例 1：

输入：sentence = "leetcode exercises sound delightful"
输出：true
解释：句子中的单词是 ["leetcode", "exercises", "sound", "delightful"] 。
- leetcode 的最后一个字符和 exercises 的第一个字符相等。
- exercises 的最后一个字符和 sound 的第一个字符相等。
- sound 的最后一个字符和 delightful 的第一个字符相等。
- delightful 的最后一个字符和 leetcode 的第一个字符相等。
这个句子是回环句。
示例 2：

输入：sentence = "eetcode"
输出：true
解释：句子中的单词是 ["eetcode"] 。
- eetcode 的最后一个字符和 eetcode 的第一个字符相等。
这个句子是回环句。
示例 3：

输入：sentence = "Leetcode is cool"
输出：false
解释：句子中的单词是 ["Leetcode", "is", "cool"] 。
- Leetcode 的最后一个字符和 is 的第一个字符 不 相等。
这个句子 不 是回环句。


提示：

1 <= sentence.length <= 500
sentence 仅由大小写英文字母和空格组成
sentence 中的单词由单个空格进行分隔
不含任何前导或尾随空格
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        for (int i = 0; i < (int)sentence.size(); ++i) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }

        return sentence[0] == sentence.back();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isCircularSentence("leetcode exercises sound delightful"));
    check.checkBool(true, o.isCircularSentence("eetcode"));
    check.checkBool(true, o.isCircularSentence("leetcode eats soul"));
    check.checkBool(false, o.isCircularSentence("Leetcode is cool"));
    check.checkBool(false, o.isCircularSentence("happy Leetcode"));
    check.checkBool(false, o.isCircularSentence("Leetcode"));
    check.checkBool(false, o.isCircularSentence("I like Leetcode"));
    check.checkBool(false, o.isCircularSentence("MuFoevIXCZzrpXeRmTssj lYSW U jM"));
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
