/* 将句子排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个 句子 指的是一个序列的单词用单个空格连接起来，且开头和结尾没有任何空格。每个单词都只包含小写或大写英文字母。

我们可以给一个句子添加 从 1 开始的单词位置索引 ，并且将句子中所有单词 打乱顺序 。

比方说，句子 "This is a sentence" 可以被打乱顺序得到 "sentence4 a3 is2 This1" 或者 "is2 sentence4 This1 a3" 。
给你一个 打乱顺序 的句子 s ，它包含的单词不超过 9 个，请你重新构造并得到原本顺序的句子。

 

示例 1：

输入：s = "is2 sentence4 This1 a3"
输出："This is a sentence"
解释：将 s 中的单词按照初始位置排序，得到 "This1 is2 a3 sentence4" ，然后删除数字。
示例 2：

输入：s = "Myself2 Me1 I4 and3"
输出："Me Myself and I"
解释：将 s 中的单词按照初始位置排序，得到 "Me1 Myself2 and3 I4" ，然后删除数字。
 

提示：

2 <= s.length <= 200
s 只包含小写和大写英文字母、空格以及从 1 到 9 的数字。
s 中单词数目为 1 到 9 个。
s 中的单词由单个空格分隔。
s 不包含任何前导或者后缀空格。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sorting-the-sentence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        string ans;
        vector<string> words(9);

        getWords(s, words);

        for (string& word : words) {
            if (word == "") {
                break;
            }

            ans += word;
            ans += " ";
        }

        ans.pop_back();
        return ans;
    }

    void getWords(string& sentence, vector<string>& words) {
        char* p = const_cast<char*>(sentence.c_str());
        char* context;

        p = strtok_s(p, " ", &context);
        while (p != NULL) {
            string word(p);
            int index = word.back() - '1';
            word.pop_back();
            words[index] = word;
            p = strtok_s(NULL, " ", &context);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("This is a sentence", o.sortSentence("is2 sentence4 This1 a3"));
    check.checkString("s", o.sortSentence("s1"));
    check.checkString("Me Myself and I", o.sortSentence("Myself2 Me1 I4 and3"));
    check.checkString("a b c d e f g h i", o.sortSentence("a1 b2 c3 d4 e5 f6 g7 h8 i9"));
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
