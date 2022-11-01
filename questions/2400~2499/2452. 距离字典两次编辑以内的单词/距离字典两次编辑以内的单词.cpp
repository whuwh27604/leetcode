/* 距离字典两次编辑以内的单词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串数组 queries 和 dictionary 。数组中所有单词都只包含小写英文字母，且长度都相同。

一次 编辑 中，你可以从 queries 中选择一个单词，将任意一个字母修改成任何其他字母。从 queries 中找到所有满足以下条件的字符串：不超过 两次编辑内，字符串与 dictionary 中某个字符串相同。

请你返回 queries 中的单词列表，这些单词距离 dictionary 中的单词 编辑次数 不超过 两次 。单词返回的顺序需要与 queries 中原本顺序相同。

 

示例 1：

输入：queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
输出：["word","note","wood"]
解释：
- 将 "word" 中的 'r' 换成 'o' ，得到 dictionary 中的单词 "wood" 。
- 将 "note" 中的 'n' 换成 'j' 且将 't' 换成 'k' ，得到 "joke" 。
- "ants" 需要超过 2 次编辑才能得到 dictionary 中的单词。
- "wood" 不需要修改（0 次编辑），就得到 dictionary 中相同的单词。
所以我们返回 ["word","note","wood"] 。
示例 2：

输入：queries = ["yes"], dictionary = ["not"]
输出：[]
解释：
"yes" 需要超过 2 次编辑才能得到 "not" 。
所以我们返回空数组。
 

提示：

1 <= queries.length, dictionary.length <= 100
n == queries[i].length == dictionary[j].length
1 <= n <= 100
所有 queries[i] 和 dictionary[j] 都只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/words-within-two-edits-of-dictionary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for (string& query : queries) {
            if (editable(query, dictionary)) {
                ans.push_back(query);
            }
        }

        return ans;
    }

    bool editable(string& word, vector<string>& dictionary) {
        for (string& dict : dictionary) {
            if (editable(word, dict)) {
                return true;
            }
        }

        return false;
    }

    bool editable(string& word, string& dict) {
        int diff = 0;

        for (int i = 0; i < (int)word.size() && diff < 3; ++i) {
            if (word[i] != dict[i]) {
                ++diff;
            }
        }

        return diff < 3;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> queries = { "word","note","ants","wood" };
    vector<string> dictionary = { "wood","joke","moat" };
    vector<string> actual = o.twoEditWords(queries, dictionary);
    vector<string> expected = { "word","note","wood" };
    check.checkStringVector(expected, actual);

    queries = { "yes" };
    dictionary = { "not" };
    actual = o.twoEditWords(queries, dictionary);
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
