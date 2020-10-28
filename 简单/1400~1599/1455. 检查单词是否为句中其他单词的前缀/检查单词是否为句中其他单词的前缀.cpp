/* 检查单词是否为句中其他单词的前缀.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 sentence 作为句子并指定检索词为 searchWord ，其中句子由若干用 单个空格 分隔的单词组成。

请你检查检索词 searchWord 是否为句子 sentence 中任意单词的前缀。

如果 searchWord 是某一个单词的前缀，则返回句子 sentence 中该单词所对应的下标（下标从 1 开始）。
如果 searchWord 是多个单词的前缀，则返回匹配的第一个单词的下标（最小下标）。
如果 searchWord 不是任何单词的前缀，则返回 -1 。
字符串 S 的 「前缀」是 S 的任何前导连续子字符串。

 

示例 1：

输入：sentence = "i love eating burger", searchWord = "burg"
输出：4
解释："burg" 是 "burger" 的前缀，而 "burger" 是句子中第 4 个单词。
示例 2：

输入：sentence = "this problem is an easy problem", searchWord = "pro"
输出：2
解释："pro" 是 "problem" 的前缀，而 "problem" 是句子中第 2 个也是第 6 个单词，但是应该返回最小下标 2 。
示例 3：

输入：sentence = "i am tired", searchWord = "you"
输出：-1
解释："you" 不是句子中任何单词的前缀。
示例 4：

输入：sentence = "i use triple pillow", searchWord = "pill"
输出：4
示例 5：

输入：sentence = "hello from the other side", searchWord = "they"
输出：-1
 

提示：

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence 由小写英文字母和空格组成。
searchWord 由小写英文字母组成。
前缀就是紧密附着于词根的语素，中间不能插入其它成分，并且它的位置是固定的——-位于词根之前。（引用自 前缀_百度百科 ）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string::size_type i, j, start, end, position = 0, prefixLen = searchWord.size();
        int wordIndex = 1;

        while (sentence[position] == ' ') {
            position++;
        }
        start = position;
        sentence += ' ';

        while ((position = sentence.find(' ', position)) != string::npos) {
            if ((position - start) >= prefixLen) {
                end = start + prefixLen;
                j = 0;
                for (i = start; i < end; i++) {
                    if (sentence[i] != searchWord[j++]) {
                        break;
                    }
                }

                if (i == end) {
                    return wordIndex;
                }
            }

            wordIndex++;
            position++;
            start = position;
        }

        return -1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(4, o.isPrefixOfWord("i love eating burger", "burg"));
    check.checkInt(2, o.isPrefixOfWord("this problem is an easy problem", "pro"));
    check.checkInt(-1, o.isPrefixOfWord("i am tired", "you"));
    check.checkInt(4, o.isPrefixOfWord("i use triple pillow", "pill"));
    check.checkInt(-1, o.isPrefixOfWord("hello from the other side", "they"));
    check.checkInt(1, o.isPrefixOfWord("hello from the other side", "hello"));
    check.checkInt(-1, o.isPrefixOfWord("hello from the other side", "ello"));
    check.checkInt(1, o.isPrefixOfWord("a", "a"));
    check.checkInt(-1, o.isPrefixOfWord("a", "b"));
    check.checkInt(1, o.isPrefixOfWord("  a   ", "a"));
    check.checkInt(2, o.isPrefixOfWord("a b", "b"));
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
