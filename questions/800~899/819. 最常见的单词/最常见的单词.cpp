/* 最常见的单词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个段落 (paragraph) 和一个禁用单词列表 (banned)。返回出现次数最多，同时不在禁用列表中的单词。

题目保证至少有一个词不在禁用列表中，而且答案唯一。

禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母。

 

示例：

输入:
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
输出: "ball"
解释:
"hit" 出现了3次，但它是一个禁用的单词。
"ball" 出现了2次 (同时没有其他单词出现2次)，所以它是段落里出现次数最多的，且不在禁用列表中的单词。
注意，所有这些单词在段落里不区分大小写，标点符号需要忽略（即使是紧挨着单词也忽略， 比如 "ball,"），
"hit"不是最终的答案，虽然它出现次数更多，但它在禁用单词列表中。
 

提示：

1 <= 段落长度 <= 1000
0 <= 禁用单词个数 <= 100
1 <= 禁用单词长度 <= 10
答案是唯一的, 且都是小写字母 (即使在 paragraph 里是大写的，即使是一些特定的名词，答案都是小写的。)
paragraph 只包含字母、空格和下列标点符号!?',;.
不存在没有连字符或者带有连字符的单词。
单词里只包含字母，不会出现省略号或者其他标点符号。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/most-common-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedTable;
        for (unsigned int i = 0; i < banned.size(); i++) {
            bannedTable.insert(banned[i]);
        }

        int maxCount = 0;
        string maxCountWord;
        unordered_map<string, int> wordsCount;
        char* p = const_cast<char*>(paragraph.c_str());
        const char* delim = " !?',;.";
        char* context;
        p = strtok_s(p, delim, &context);
        while (p != NULL) {
            string word(p);
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (bannedTable.find(word) == bannedTable.end()) {
                auto iter = wordsCount.find(word);
                if (iter == wordsCount.end()) {
                    wordsCount[word] = 1;
                }
                else {
                    iter->second += 1;
                }

                if (wordsCount[word] > maxCount) {
                    maxCount = wordsCount[word];
                    maxCountWord = word;
                }
            }

            p = strtok_s(NULL, delim, &context);
        }

        return maxCountWord;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = { "hit" };
    check.checkString("ball", o.mostCommonWord(paragraph, banned));

    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    banned = {  };
    check.checkString("hit", o.mostCommonWord(paragraph, banned));

    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit it it it it.";
    banned = {  "hit" };
    check.checkString("it", o.mostCommonWord(paragraph, banned));

    paragraph = "B";
    banned = {  };
    check.checkString("b", o.mostCommonWord(paragraph, banned));

    paragraph = "B";
    banned = { "hit" };
    check.checkString("b", o.mostCommonWord(paragraph, banned));
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
