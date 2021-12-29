/* 句子中的最多单词数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个 句子 由一些 单词 以及它们之间的单个空格组成，句子的开头和结尾不会有多余空格。

给你一个字符串数组 sentences ，其中 sentences[i] 表示单个 句子 。

请你返回单个句子里 单词的最多数目 。

 

示例 1：

输入：sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
输出：6
解释：
- 第一个句子 "alice and bob love leetcode" 总共有 5 个单词。
- 第二个句子 "i think so too" 总共有 4 个单词。
- 第三个句子 "this is great thanks very much" 总共有 6 个单词。
所以，单个句子中有最多单词数的是第三个句子，总共有 6 个单词。
示例 2：

输入：sentences = ["please wait", "continue to fight", "continue to win"]
输出：3
解释：可能有多个句子有相同单词数。
这个例子中，第二个句子和第三个句子（加粗斜体）有相同数目的单词数。
 

提示：

1 <= sentences.length <= 100
1 <= sentences[i].length <= 100
sentences[i] 只包含小写英文字母和 ' ' 。
sentences[i] 的开头和结尾都没有空格。
sentences[i] 中所有单词由单个空格隔开。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-words-found-in-sentences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mostWords = 0;

        for (string& sentence : sentences) {
            int words = 1;

            for (char c : sentence) {
                if (c == ' ') {
                    ++words;
                }
            }

            mostWords = max(mostWords, words);
        }

        return mostWords;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> sentences = { "alice and bob love leetcode", "i think so too", "this is great thanks very much" };
    check.checkInt(6, o.mostWordsFound(sentences));

    sentences = { "please wait", "continue to fight", "continue to win" };
    check.checkInt(3, o.mostWordsFound(sentences));
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
