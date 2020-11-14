/* 元音拼写检查器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在给定单词列表 wordlist 的情况下，我们希望实现一个拼写检查器，将查询单词转换为正确的单词。

对于给定的查询单词 query，拼写检查器将会处理两类拼写错误：

大小写：如果查询匹配单词列表中的某个单词（不区分大小写），则返回的正确单词与单词列表中的大小写相同。
例如：wordlist = ["yellow"], query = "YellOw": correct = "yellow"
例如：wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
例如：wordlist = ["yellow"], query = "yellow": correct = "yellow"
元音错误：如果在将查询单词中的元音（‘a’、‘e’、‘i’、‘o’、‘u’）分别替换为任何元音后，能与单词列表中的单词匹配（不区分大小写），则返回的正确单词与单词列表中的匹配项大小写相同。
例如：wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
例如：wordlist = ["YellOw"], query = "yeellow": correct = "" （无匹配项）
例如：wordlist = ["YellOw"], query = "yllw": correct = "" （无匹配项）
此外，拼写检查器还按照以下优先级规则操作：

当查询完全匹配单词列表中的某个单词（区分大小写）时，应返回相同的单词。
当查询匹配到大小写问题的单词时，您应该返回单词列表中的第一个这样的匹配项。
当查询匹配到元音错误的单词时，您应该返回单词列表中的第一个这样的匹配项。
如果该查询在单词列表中没有匹配项，则应返回空字符串。
给出一些查询 queries，返回一个单词列表 answer，其中 answer[i] 是由查询 query = queries[i] 得到的正确单词。

 

示例：

输入：wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
输出：["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
 

提示：

1 <= wordlist.length <= 5000
1 <= queries.length <= 5000
1 <= wordlist[i].length <= 7
1 <= queries[i].length <= 7
wordlist 和 queries 中的所有字符串仅由英文字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/vowel-spellchecker
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> answers;
        unordered_set<string> exactlyMatches;
        unordered_map<string, string> capitlizations, vowelErrors;

        preprocess(wordlist, exactlyMatches, capitlizations, vowelErrors);

        for (string& query : queries) {
            if (exactlyMatches.count(query) == 1) {
                answers.push_back(query);
                continue;
            }

            string lowercase = query;
            transform(query.begin(), query.end(), lowercase.begin(), ::tolower);
            if (capitlizations.count(lowercase) == 1) {
                answers.push_back(capitlizations[lowercase]);
                continue;
            }

            ignoreVowel(lowercase);
            if (vowelErrors.count(lowercase) == 1) {
                answers.push_back(vowelErrors[lowercase]);
            }
            else {
                answers.push_back("");
            }
        }

        return answers;
    }

    void preprocess(vector<string>& wordlist, unordered_set<string>& exactlyMatches,
        unordered_map<string, string>& capitlizations, unordered_map<string, string>& vowelErrors) {
        for (string& word : wordlist) {
            exactlyMatches.insert(word);

            string lowercase = word;
            transform(word.begin(), word.end(), lowercase.begin(), ::tolower);
            if (capitlizations.count(lowercase) == 0) {
                capitlizations[lowercase] = word;
            }

            ignoreVowel(lowercase);
            if (vowelErrors.count(lowercase) == 0) {
                vowelErrors[lowercase] = word;
            }
        }
    }

    void ignoreVowel(string& word) {
        for (char& c : word) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = 'a';
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> wordlist = { "KiTe","kite","hare","Hare" };
    vector<string> queries = { "kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto" };
    vector<string> actual = o.spellchecker(wordlist, queries);
    vector<string> expected = { "kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe" };
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
