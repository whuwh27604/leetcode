/* 两句话中的不常见单词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）

如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。

返回所有不常用单词的列表。

您可以按任何顺序返回列表。

 

示例 1：

输入：A = "this apple is sweet", B = "this apple is sour"
输出：["sweet","sour"]
示例 2：

输入：A = "apple apple", B = "banana"
输出：["banana"]
 

提示：

0 <= A.length <= 200
0 <= B.length <= 200
A 和 B 都只包含空格和小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/uncommon-words-from-two-sentences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> wordsCount;
        wordsString2Map(A, wordsCount);
        wordsString2Map(B, wordsCount);

        vector<string> uncommonWords;
        for (auto iter = wordsCount.begin(); iter != wordsCount.end(); iter++) {
            if (iter->second == 1) {
                uncommonWords.push_back(iter->first);
            }
        }

        return uncommonWords;
    }

    void wordsString2Map(string& s, unordered_map<string, int>& wordsCount) {
        char* p = const_cast<char*>(s.c_str());
        char* context;
        p = strtok_s(p, " ", &context);
        while (p != NULL) {
            string word(p);
            auto iter = wordsCount.find(word);
            if (iter == wordsCount.end()) {
                wordsCount[word] = 1;
            }
            else {
                iter->second++;
            }

            p = strtok_s(NULL, " ", &context);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string A = "this apple is sweet";
    string B = "this apple is sour";
    vector<string> actual = o.uncommonFromSentences(A, B);
    vector<string> expected = { "sweet","sour" };
    check.checkStringVector(expected, actual);

    A = " this apple is sweet ";
    B = "  this apple is sour  ";
    actual = o.uncommonFromSentences(A, B);
    expected = { "sweet","sour" };
    check.checkStringVector(expected, actual);

    A = "apple apple";
    B = "banana";
    actual = o.uncommonFromSentences(A, B);
    expected = { "banana" };
    check.checkStringVector(expected, actual);

    A = "";
    B = "";
    actual = o.uncommonFromSentences(A, B);
    expected = {  };
    check.checkStringVector(expected, actual);

    A = "";
    B = "aaa";
    actual = o.uncommonFromSentences(A, B);
    expected = { "aaa" };
    check.checkStringVector(expected, actual);

    A = "";
    B = "aaa aaa";
    actual = o.uncommonFromSentences(A, B);
    expected = {  };
    check.checkStringVector(expected, actual);
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
