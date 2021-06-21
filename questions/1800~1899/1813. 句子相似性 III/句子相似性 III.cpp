/* 句子相似性 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个句子是由一些单词与它们之间的单个空格组成，且句子的开头和结尾没有多余空格。比方说，"Hello World" ，"HELLO" ，"hello world hello world" 都是句子。每个单词都 只 包含大写和小写英文字母。

如果两个句子 sentence1 和 sentence2 ，可以通过往其中一个句子插入一个任意的句子（可以是空句子）而得到另一个句子，那么我们称这两个句子是 相似的 。比方说，sentence1 = "Hello my name is Jane" 且 sentence2 = "Hello Jane" ，我们可以往 sentence2 中 "Hello" 和 "Jane" 之间插入 "my name is" 得到 sentence1 。

给你两个句子 sentence1 和 sentence2 ，如果 sentence1 和 sentence2 是相似的，请你返回 true ，否则返回 false 。

 

示例 1：

输入：sentence1 = "My name is Haley", sentence2 = "My Haley"
输出：true
解释：可以往 sentence2 中 "My" 和 "Haley" 之间插入 "name is" ，得到 sentence1 。
示例 2：

输入：sentence1 = "of", sentence2 = "A lot of words"
输出：false
解释：没法往这两个句子中的一个句子只插入一个句子就得到另一个句子。
示例 3：

输入：sentence1 = "Eating right now", sentence2 = "Eating"
输出：true
解释：可以往 sentence2 的结尾插入 "right now" 得到 sentence1 。
示例 4：

输入：sentence1 = "Luky", sentence2 = "Lucccky"
输出：false
 

提示：

1 <= sentence1.length, sentence2.length <= 100
sentence1 和 sentence2 都只包含大小写英文字母和空格。
sentence1 和 sentence2 中的单词都只由单个空格隔开。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sentence-similarity-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        deque<string> words1, words2;

        getWords(sentence1, words1);
        getWords(sentence2, words2);

        while (!words1.empty() && !words2.empty() && words1.front() == words2.front()) {
            words1.pop_front();
            words2.pop_front();
        }

        while (!words1.empty() && !words2.empty() && words1.back() == words2.back()) {
            words1.pop_back();
            words2.pop_back();
        }

        return words1.empty() || words2.empty();
    }

    void getWords(string& sentence, deque<string>& words) {
        char* p = const_cast<char*>(sentence.c_str());
        char* context;

        p = strtok_s(p, " ", &context);
        while (p != NULL) {
            words.push_back(string(p));
            p = strtok_s(NULL, " ", &context);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.areSentencesSimilar("My name is Haley", "My Haley"));
    check.checkBool(true, o.areSentencesSimilar("Eating right now", "Eating"));
    check.checkBool(true, o.areSentencesSimilar("a b c d", "a x b c b c b c d"));
    check.checkBool(true, o.areSentencesSimilar("A", "a A b A"));
    check.checkBool(true, o.areSentencesSimilar("A", "A b A"));
    check.checkBool(true, o.areSentencesSimilar("A b A", "A b A"));
    check.checkBool(true, o.areSentencesSimilar("TjZ ScAi m m xz PNWaKigqqY p IyJ B rok", "TjZ ScAi m LlbJhCf gL u m R pZpiH mSk a og m xz PNWaKigqqY p IyJ B rok"));
    check.checkBool(false, o.areSentencesSimilar("of", "A lot of words"));
    check.checkBool(false, o.areSentencesSimilar("Luky", "Lucccky"));
    check.checkBool(false, o.areSentencesSimilar("lucccky", "Lucccky"));
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
