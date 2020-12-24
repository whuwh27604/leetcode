/* 重新排列句子中的单词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「句子」是一个用空格分隔单词的字符串。给你一个满足下述格式的句子 text :

句子的首字母大写
text 中的每个单词都用单个空格分隔。
请你重新排列 text 中的单词，使所有单词按其长度的升序排列。如果两个单词的长度相同，则保留其在原句子中的相对顺序。

请同样按上述格式返回新的句子。

 

示例 1：

输入：text = "Leetcode is cool"
输出："Is cool leetcode"
解释：句子中共有 3 个单词，长度为 8 的 "Leetcode" ，长度为 2 的 "is" 以及长度为 4 的 "cool" 。
输出需要按单词的长度升序排列，新句子中的第一个单词首字母需要大写。
示例 2：

输入：text = "Keep calm and code on"
输出："On and keep calm code"
解释：输出的排序情况如下：
"On" 2 个字母。
"and" 3 个字母。
"keep" 4 个字母，因为存在长度相同的其他单词，所以它们之间需要保留在原句子中的相对顺序。
"calm" 4 个字母。
"code" 4 个字母。
示例 3：

输入：text = "To be or not to be"
输出："To be or to be not"
 

提示：

text 以大写字母开头，然后包含若干小写字母以及单词间的单个空格。
1 <= text.length <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rearrange-words-in-a-sentence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string arrangeWords(string text) {
        text[0] += ('a' - 'A');
        text += ' ';

        map<int, vector<string>> words;
        classify(text, words);

        string arrangedText;
        arrange(words, arrangedText);

        arrangedText[0] -= ('a' - 'A');
        return arrangedText;
    }

    void classify(string& text, map<int, vector<string>>& words) {
        int position, start = 0;

        while ((position = text.find(' ', start)) != text.npos) {
            int len = position - start;
            string word(text, start, len);
            words[len].push_back(word);
            start = position + 1;
        }
    }

    void arrange(map<int, vector<string>>& words, string& arrangedText) {
        for (auto iter = words.begin(); iter != words.end(); ++iter) {
            for (auto& word : iter->second) {
                arrangedText += word;
                arrangedText += ' ';
            }
        }

        arrangedText.pop_back();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("Is cool leetcode", o.arrangeWords("Leetcode is cool"));
    check.checkString("On and keep calm code", o.arrangeWords("Keep calm and code on"));
    check.checkString("To be or to be not", o.arrangeWords("To be or not to be"));
    check.checkString("A", o.arrangeWords("A"));
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
